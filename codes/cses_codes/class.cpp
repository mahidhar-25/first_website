#include<iostream>
#include<iomanip>
using namespace std;
 1st one
class student{

    private:
    char roll_no[10];
    char name[10];
    float M1,M2,M3;
    float total,avg;

    public:
    void get_data();
    void calculate_data();
    void head_data();
    void display_data();
};

void student::get_data(){
    cout<<"\nenter name : ";
    cin>>name;
    cout<<"\nroll no : ";
    cin>>roll_no;
    cout<<"\nenter M1,M2,M3 marks : ";
    cin>>M1>>M2>>M3;
}

void student::calculate_data(){
    avg = (M1+M2+M3)/3;
    total = avg*3;
}

void student::head_data(){
    cout<<setiosflags(ios::left);
  cout<<setw(15)<<"name"<<setw(15)<<"roll_no"<<setw(8)<<"M1"<<setw(8)<<"M2"<<setw(8)<<"M3"<<setw(15)<<"total"<<setw(10)<<"avg"<<endl;   
}

void student::display_data(){
    cout<<setiosflags(ios::left);
    cout<<setw(15)<<name<<setw(15)<<roll_no<<setw(8)<<M1<<setw(8)<<M2<<setw(8)<<M3<<setw(15)<<total<<setw(10)<<avg<<endl;
}

int main(){
    int i;
    student s[10];
    for(i=0;i<5;i++){
        s[i].get_data();
        s[i].calculate_data();
    }
    s[1].head_data();
    for(i=0;i<5;i++){
        s[i].display_data();
    }
}


/* 2nd one 
class electric_bill{
    private:
    char name[10];
    char id[10];
    float CMT,PMT;
    float reading;
    float cost;

    public:
    void get_data();
    void calculate_cost();
    void heading();
    void display();
};

void electric_bill :: get_data(){
    cout<<"enter your name : ";
    cin>>name;
    cout<<"enter id : ";
    cin>>id;
    cout<<"enter cuurent and previous readings : ";
    cin>>CMT>>PMT;
}

void electric_bill :: calculate_cost(){
    reading = CMT - PMT;
    if(reading<=100){
        cost = reading + 50;
    }else if(reading>100 && reading<=200){
        cost = reading * 2 + 50;
    }else{
        cost = reading * 3 + 50;
    }
    //cost += 50; //min charge
    if(cost >300){
        float extra_gst;
        extra_gst = 0.15 * cost;
        cost = cost + extra_gst; 
    }
}

void electric_bill :: heading(){
      cout<<setiosflags(ios::left);
    cout<<setw(10)<<"name"<<setw(15)<<"id"<<setw(15)<<"reading"<<setw(15)<<"cost"<<endl;  
}

void electric_bill:: display(){
    cout<<setiosflags(ios::left);
    cout<<setw(10)<<name<<setw(15)<<id<<setw(15)<<reading<<setw(15)<<cost<<endl;
}


int main(){
    int n,i;
    cout<<"enter no of houses in a colony : ";
    cin>>n;
    electric_bill E[n];
    for(i=0;i<n;i++){
        E[i].get_data();
        E[i].calculate_cost();
    }
      E[i].heading();

      for(i=0;i<n;i++){
          E[i].display();
      }

}
*/





