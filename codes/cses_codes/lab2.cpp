/*
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class student_report_card{
    private:
    string name;
    string roll_no;
    int marks_sub1,marks_sub2,marks_sub3,marks_sub4,marks_sub5;
    public:
    student_report_card(){
        name = "";
        roll_no = "";
        marks_sub1 = marks_sub2 = marks_sub3 = marks_sub4 = marks_sub5 = 0;
    }
    student_report_card(string Name, string Roll_no){
        name = Name;
        roll_no = Roll_no;
        marks_sub1 = marks_sub2 = marks_sub3 = marks_sub4 = marks_sub5 = 0;
    }
      void Create_student_report_card_record(int i);
      void Display_all_students_report_card_records(student_report_card student4, student_report_card student5);
};

 student_report_card student1,student2,student3;

void student_report_card::Create_student_report_card_record(int i){
    //string name,roll_no;
    if(i<4){
    cout<<"enter the name of student"<<i<<": ";
    cin>>name;
    cout<<"enter the roll no"<<i<<": ";
    cin>>roll_no;
    }
    cout<<"enter 5 subjects marks each : ";
   cin>>marks_sub1;
   cin>>marks_sub2;
   cin>>marks_sub3;
   cin>>marks_sub4;
   cin>>marks_sub5;
}

void student_report_card::Display_all_students_report_card_records(student_report_card student4, student_report_card student5){
    cout<<setiosflags(ios::left);
    cout<<setw(15)<<"NAME"<<setw(15)<<"ROLL_NO"<<setw(8)<<"SUB_1"<<setw(8)<<"SUB_2"<<setw(8)<<"SUB_3"<<setw(8)<<"SUB_4"<<setw(8)<<"SUB_5"<<endl;
    cout<<setw(15)<<student1.name<<setw(15)<<student1.roll_no<<setw(8)<<student1.marks_sub1<<setw(8)<<student1.marks_sub2<<setw(8)<<student1.marks_sub3<<setw(8)<<student1.marks_sub4<<setw(8)<<student1.marks_sub5<<endl;
    cout<<setw(15)<<student2.name<<setw(15)<<student2.roll_no<<setw(8)<<student2.marks_sub1<<setw(8)<<student2.marks_sub2<<setw(8)<<student2.marks_sub3<<setw(8)<<student2.marks_sub4<<setw(8)<<student2.marks_sub5<<endl;
    cout<<setw(15)<<student3.name<<setw(15)<<student3.roll_no<<setw(8)<<student3.marks_sub1<<setw(8)<<student3.marks_sub2<<setw(8)<<student3.marks_sub3<<setw(8)<<student3.marks_sub4<<setw(8)<<student3.marks_sub5<<endl;
    cout<<setw(15)<<student4.name<<setw(15)<<student4.roll_no<<setw(8)<<student4.marks_sub1<<setw(8)<<student4.marks_sub2<<setw(8)<<student4.marks_sub3<<setw(8)<<student4.marks_sub4<<setw(8)<<student4.marks_sub5<<endl;
    cout<<setw(15)<<student5.name<<setw(15)<<student5.roll_no<<setw(8)<<student5.marks_sub1<<setw(8)<<student5.marks_sub2<<setw(8)<<student5.marks_sub3<<setw(8)<<student5.marks_sub4<<setw(8)<<student5.marks_sub5<<endl;
  
}

int main(){
  // student_report_card student1,student2,student3;
   string NAME,ROLL_NO;
   cout<<"enter name and roll no of student 4 : ";
   cin>>NAME>>ROLL_NO;
   student_report_card student4(NAME,ROLL_NO);
  cout<<"enter name and roll no of student 5 : ";
   cin>>NAME>>ROLL_NO;
   student_report_card student5(NAME,ROLL_NO);
   student1.Create_student_report_card_record(1);
   student2.Create_student_report_card_record(2);
   student3.Create_student_report_card_record(3);
   student1.Display_all_students_report_card_records(student4,student5);
   student4.Create_student_report_card_record(4);
   student5.Create_student_report_card_record(5);
   student1.Display_all_students_report_card_records(student4,student5);
}

*/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class student_report_card{
    private:
    string name;
    string roll_no;
    int marks_sub1,marks_sub2,marks_sub3,marks_sub4,marks_sub5;
    public:
    student_report_card(){
        name = "";
        roll_no = "";
        marks_sub1 = marks_sub2 = marks_sub3 = marks_sub4 = marks_sub5 = 0;
    }
    student_report_card(string Name, string Roll_no){
        name = Name;
        roll_no = Roll_no;
        marks_sub1 = marks_sub2 = marks_sub3 = marks_sub4 = marks_sub5 = 0;
    }
      void Create_student_report_card_record(int i);
      void Display_all_students_report_card_records(student_report_card student4, student_report_card student5);
};

 student_report_card student1,student2,student3;

void student_report_card::Create_student_report_card_record(int i){
    //string name,roll_no;
    if(i<4){
    cout<<"enter the name of student"<<i<<": ";
    cin.ignore();
    getline(cin,name);
  //cin>>name;
    cout<<"enter the roll no"<<i<<": ";
    getline(cin,roll_no);
    }
    cout<<"enter 5 subjects marks each"<<i<<": ";
  cin>>marks_sub1; 
   if(marks_sub1<0||marks_sub1>100){cout<<"marks or invalid for sub1 \n enter again between 0 to 100 : " ; cin>>marks_sub1;}
   cin>>marks_sub2;
   if(marks_sub2<0||marks_sub2>100){cout<<"marks or invalid for sub2 \n enter again between 0 to 100 : " ; cin>>marks_sub2;}
   cin>>marks_sub3;
   if(marks_sub3<0||marks_sub3>100){cout<<"marks or invalid for sub3 \n enter again between 0 to 100 : " ; cin>>marks_sub3;}
   cin>>marks_sub4;
   if(marks_sub4<0||marks_sub4>100){cout<<"marks or invalid for sub4 \n enter again between 0 to 100 : " ; cin>>marks_sub4;}
   cin>>marks_sub5;
   if(marks_sub5<0||marks_sub5>100){cout<<"marks or invalid for sub5 \n enter again between 0 to 100 : " ; cin>>marks_sub5;}
}

void student_report_card::Display_all_students_report_card_records(student_report_card student4, student_report_card student5){
    cout<<setiosflags(ios::left);
    cout<<setw(25)<<"NAME"<<setw(15)<<"ROLL_NO"<<setw(8)<<"SUB_1"<<setw(8)<<"SUB_2"<<setw(8)<<"SUB_3"<<setw(8)<<"SUB_4"<<setw(8)<<"SUB_5"<<endl;
    cout<<setw(25)<<student1.name<<setw(15)<<student1.roll_no<<setw(8)<<student1.marks_sub1<<setw(8)<<student1.marks_sub2<<setw(8)<<student1.marks_sub3<<setw(8)<<student1.marks_sub4<<setw(8)<<student1.marks_sub5<<endl;
    cout<<setw(25)<<student2.name<<setw(15)<<student2.roll_no<<setw(8)<<student2.marks_sub1<<setw(8)<<student2.marks_sub2<<setw(8)<<student2.marks_sub3<<setw(8)<<student2.marks_sub4<<setw(8)<<student2.marks_sub5<<endl;
    cout<<setw(25)<<student3.name<<setw(15)<<student3.roll_no<<setw(8)<<student3.marks_sub1<<setw(8)<<student3.marks_sub2<<setw(8)<<student3.marks_sub3<<setw(8)<<student3.marks_sub4<<setw(8)<<student3.marks_sub5<<endl;
    cout<<setw(25)<<student4.name<<setw(15)<<student4.roll_no<<setw(8)<<student4.marks_sub1<<setw(8)<<student4.marks_sub2<<setw(8)<<student4.marks_sub3<<setw(8)<<student4.marks_sub4<<setw(8)<<student4.marks_sub5<<endl;
    cout<<setw(25)<<student5.name<<setw(15)<<student5.roll_no<<setw(8)<<student5.marks_sub1<<setw(8)<<student5.marks_sub2<<setw(8)<<student5.marks_sub3<<setw(8)<<student5.marks_sub4<<setw(8)<<student5.marks_sub5<<endl;
  
}


int main(){
   string NAME,ROLL_NO;
   cout<<"enter name  of student 4 : ";
             getline(cin,NAME);
  cout<<"enter roll no of student 4 : ";
             getline(cin,ROLL_NO);
 student_report_card student4(NAME,ROLL_NO);
 cout<<"enter name  of student 5 : ";
               getline(cin,NAME);
 cout<<"enter roll no of student 5 : ";
             getline(cin,ROLL_NO);
 student_report_card student5(NAME,ROLL_NO);
   int choice;
   cout<<"enter choice : ";
   cin>>choice;
   while(1){
   switch(choice){
       case 1:
            cout<<"enter which student to create : ";
           int n; cin>>n;
           switch(n){
               case 1:
                student1.Create_student_report_card_record(1);
                break;
               case 2:
                student2.Create_student_report_card_record(2);
                break;
                case 3:
                student3.Create_student_report_card_record(3);
                break;
                case 4:
                student4.Create_student_report_card_record(4);
                break;
                case 5:
                student5.Create_student_report_card_record(5);
                break;
           }
           break;
         case 2:
         student1.Display_all_students_report_card_records(student4,student5);
         break;
         case 3:
         exit(0);
         break;
   }
    cout<<"enter choice : ";
   cin>>choice;
}
}