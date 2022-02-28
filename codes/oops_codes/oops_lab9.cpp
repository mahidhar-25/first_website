/*
#include<iostream>
#include<string>
#include<vector>
*/
#include<bits/stdc++.h>
using namespace std;

template < typename T>

class person{
protected :
string name;
T roll_no;
public:
person(){}
person(string N , T NO){
    name = N; 
    roll_no = NO;
}

void display(){
    cout<<"person display : "<<endl<<endl;;
    cout<<"person class details : \n";
    cout<<"name : "<<name<<endl;
    cout<<"roll no : "<<roll_no<<endl;
}


};




class student : virtual protected person<string>{
  protected :
  string course_1,course_2,course_3;
  string roll_number;
  public :
  student(){}
  student(string sub1 , string sub2 , string sub3 , string roll , string N): person<string>( N , roll)
  {
      course_1 = sub1;
      course_2 = sub2;
      course_3 = sub3;
      
  }
  display(){
     // cout<<"student display : "<<endl<<endl;
      person<string>::display();
      cout<<"course 1: "<<course_1<<endl;
      cout<<"course 2: "<<course_2<<endl;
      cout<<"course 3: "<<course_3<<endl;
      
  }
};




class research_student : virtual protected person<int>{
protected:
int roll_no;
string research_area;
string course1;
public:
research_student(){}
research_student(string course , string area , int roll , string N) : person<int>( N ,roll){
    roll_no = roll;
    research_area = area;
    course1 = course;
}
display(){
   // cout<<"research student dispklay : "<<endl<<endl;
    person<int>::display();
    cout<<endl;
    cout<<"roll no : "<<roll_no<<endl;
    cout<<"research area : "<<research_area<<endl;
}
};

template<typename T>

class TA : protected student , protected research_student{
protected :
string course_assigned;
string role;
T rollno;
TA *next;
public :
TA(string name ,string roll_no , string course_1 , string course_2 , string course_3 , string course_assign, string role_given) : student( course_1, course_2, course_3,roll_no,name ) ,research_student() ,person<string>(name , roll_no)
{
course_assigned = course_assign;
role = role_given;
}
TA(string name ,int roll_no , string course_1  ,string research_area , string course_assign, string role_given) :  research_student(course_1,research_area ,roll_no , name ) ,student() , person<int>(name , roll_no)
{
course_assigned = course_assign;
role = role_given;
}
void display(){
    int choice_1;
cout<<"1. for person details \n2. for student details \n3. for research student \n4. for TA details \n";
cout<<"enter your choice : "; cin>>choice_1;

    cout<<"TA display : "<<endl<<endl;
cout<<"course assign : "<<course_assigned<<endl;
cout<<"role : "<<role<<endl;






}

bool getdata(string roll){
    if(roll == rollno ){
        return(true);
    }
    return(false);
}
};


int main(){
    list<TA<string>> list_of_people;
    int choice,choice_1,roll,i,count=0;
    char roll_no;
    bool check = false;
    string roll_num,name,course1,course2,course3,course_assign,role,research_area;
    cout<<"1. to enter TA details \n2. to display \n3. to exit \n";
    cout<<"enter your choice : "; cin>>choice;
    while(1){
        switch (choice)
        {
        case 1: 
                cout<<"which type of roll no u want to enter : ";
                cout<<"1. string \n2. int \n3. char"; cout<<"\nenter your choice : "; cin>>choice_1;
                if(choice_1==1){
                  cout<<"enter name of TA : ";
                  cin.ignore(); getline(cin , name);
                  cout<<"enter roll no<string> : "; cin>>roll_num;
                  cout<<"choose role of a TA : ";
                  cout<<"1. student \n2. research_student \n"; cout<<"enter your choice : "; cin>>choice_1;
                  if(choice_1 == 1){
                  cout<<"enter course 1 : "; cin>>course1;
                  cout<<"enter course 2 : "; cin>>course2;
                  cout<<"enter course 3 : "; cin>>course3;
                TA<string> a(name , roll_num , course1 , course2 , course3 ,"","student");
                //list_of_people.push_back(a); count++;
                  }else if(choice_1 == 2){
                    cout<<"enter course 1 : "; cin>>course1;
                    cout<<"enter course assign : ";cin>>course_assign;
                    cout<<"research area : "; cin>>research_area;
                TA<string> a(name , roll_num , course1 ,research_area, course_assign, "research student");
                //list_of_people.push_back(a);count++;
                  }else{
                      cout<<"enter a valid choice \n";
                  }
                }else if(choice_1 == 2){
                  cout<<"enter name of TA : ";
                  cin.ignore(); getline(cin , name);
                  cout<<"enter roll no<string> : "; cin>>roll;
                  cout<<"choose role of a TA : ";
                  cout<<"1. student \n2. research_student \n"; cout<<"enter your choice : "; cin>>choice_1;
                  if(choice_1 == 1){
                  cout<<"enter course 1 : "; cin>>course1;
                  cout<<"enter course 2 : "; cin>>course2;
                  cout<<"enter course 3 : "; cin>>course3;
                TA<int> a(name , roll_num , course1 , course2 , course3 ,"", "student");
               // list_of_people.push_back(a); count++;
                  }else if(choice_1 == 2){
                    cout<<"enter course 1 : "; cin>>course1;
                    cout<<"enter course assign : ";cin>>course_assign;
                    cout<<"research area : "; cin>>research_area;
                TA<int> a(name , roll_num , course1 ,research_area, course_assign, "research student");
               // list_of_people.push_back(a); count++;
                  }else{
                      cout<<"enter a valid choice \n";
                  }
                }else{
                    cout<<"enter a valid choice \n";
                }
            break;
            case 2:
                  
            break;
           case 3: exit(0); break;
        default:
              cout<<"enter a valid choice\n";
            break;
        }
    }
   
    
}