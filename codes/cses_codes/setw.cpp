#include<iostream>
#include<iomanip>
using namespace std;

struct employ_details{
    float empl_id,age,basic_salary,DA,PF,net_salary;
    char name[10];
}employ[10];

int main(){
    int i,n;
    cout<<"no of employees : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<endl<<"enter employ id : ";
        cin>>employ[i].empl_id;
        cout<<endl<<"enter age : ";
        cin>>employ[i].age;
        cout<<endl<<"basic_salary : ";
        cin>>employ[i].basic_salary;
        employ[i].DA         = employ[i].basic_salary/5;
        employ[i].PF         = employ[i].basic_salary/10;
        employ[i].net_salary = employ[i].basic_salary + employ[i].DA - employ[i].PF;
    }
    cout<<setiosflags(ios::left);
    cout<<setw(15)<<"EMPLOY_ID"<<setw(15)<<"AGE"<<setw(15)<<"BASIC_SALARY"<<setw(8)<<"DA"<<setw(8)<<"PF"<<setw(15)<<"NET_SALARY"<<endl;
    for(i=0;i<n;i++)
    {
       cout<<setw(15)<<employ[i].empl_id<<setw(15)<<employ[i].age<<setw(15)<<employ[i].basic_salary<<setw(8)<<employ[i].DA<<setw(8)<<employ[i].PF<<setw(15)<<employ[i].net_salary<<endl;
    }
}