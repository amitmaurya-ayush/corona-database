#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class patient
{
    char name[50];
    int age;
    char symptom[5];

public:
    void enter(){
    cout<<"\n what is your name";
    cin>>name[50];
    cout<<"\n what is your age";
    cin>>age;
    cout<<"\n choose symptom a, b or c";
    gets(symptom);
    }
    char* retsymptom(){
    return symptom;
    }
};
class doctor
{
    char med_name[100];
    char dsymptom[5];

public:
    void getdata(){
    cout<<"\n enter the symptom type";
    gets(dsymptom);
    cout<<"\n enter the name of the medicine";
    cin>>med_name;
    }
    char* retsymptom(){
    return dsymptom;
    }
    char* retmed(){
    return med_name;
    }
};

void create_file(){
 doctor a;
 ofstream data;
 data.open("doctor.dat",ios::binary|ios::out);
 a.getdata();
 data.write((char*)&a,sizeof(a));
 data.close();
}
void append_file(){
doctor b;
ofstream data;
data.open("doctor.dat", ios::binary|ios::app);
b.getdata();
data.write((char*)&b,sizeof(b));
data.close();
}
void search_disease(){
char med[100];
char a[5],b[5];
int n=0;
patient y;
doctor x;
y.enter();
ifstream data;
data.open("doctor.dat",ios::binary);
while(data.read((char*)&x,sizeof(x))){
    if(strcmp(x.retsymptom(),y.retsymptom())==0){
        n=n+1;
        strcpy(med,x.retmed());
    }

    }
    data.close();
}
int main()
{
    int n,temp=0;
    float option;
  while(temp==0){
    cout<<"\n\n\n \t\t\t\tWelcome to corona data base \n\n\n";
    cout<<"\n Are you a doctor or a patient for doctor";
    cout<<"\n Enter 1 if you are a patient";
    cout<<"\n Enter 2 if you are a doctor \n  ";
    cin>>n;
    if(n==1)
        search_disease();
    else if(n==2)
        append_file();
    else
        cout<<"\n error";
    cout<<"do you have more data. \n\n enter '1' for yes and '0' for no. \n";
    cin>>option;
    if(option==0)
        temp=temp+1;
  }
    getch();
    return 0;
}
