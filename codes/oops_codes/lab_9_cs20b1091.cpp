//NAME : B.MAHIDHAR REDDY
//ROLL NO: CS20B1091
//TEMPLATES IN MULTIPLE INHERITENCE

#include<iostream>
#include<string>
using namespace std;

template<typename T> //template

class person{
    protected : 
    T roll_no;
    string name;
    public :
    person(){};
    //creating parametirized constructor for person class
    person(string NAME , T roll){
        this->name = NAME;
        this->roll_no = roll;
    }

    //display function

    display(){
        cout<<"  name          :  "<<name<<endl;
        cout<<"  roll no       : "<<roll_no<<endl;
        return(0);
    }
};

class student : virtual protected person<string>{
    protected : 
    string course_1 , course_2, course_3;
    public : 
    student(){};
    student *next;  //creating for checking
    student(string name , string roll , string course1 , string course2 , string course3) : person(name , roll) //initaiting parametrized for deruved and base class
    {
        this->course_1 = course1;
        this->course_2 = course2;
        this->course_3 = course3;
    }
    string compare_roll(student *head_ref) 
    {
        return(head_ref->roll_no);         //return the roll no used in checking of duplicates
    }

void display(){
   person<string>::display();  //displays name and roll no
   cout<<" course 1       : "<<course_1<<endl;
   cout<<" course 2       : "<<course_2<<endl;
   cout<<" course 3       : "<<course_3<<endl;
}
};

//research student class inherited from person class
class research_student : virtual protected person<int>{
    protected :
    string research_area , course_1;
    public:
    research_student(){}; //constructor
    research_student *next;
    research_student(string name , int roll , string course1 , string re_search_area) : person(name , roll) //parametarized constructor
    {
        this->course_1 = course1;
        this->research_area = re_search_area;
    }
    int compare_roll(research_student *head_ref) 
    {
        return(head_ref->roll_no); //used in removing of duplicates
    }
    void display(){
        person<int> :: display();
        cout<<"research area   : "<<research_area<<endl;
        cout<<"course          : "<<course_1<<endl;
    }
};

//ta class inherited from student , rresearch student classes
class TA : protected research_student , protected student{
    protected :
    string course_assigned , role;
    public :
    TA(){};
    TA *stu_next;
    TA *re_stu_next;
    //*parametarized constructor
    TA(string name, string roll, string course1, string course2, string course3,string course_assign,string role) : student(name , roll , course1, course2, course3) , person<string>(name , roll), research_student()
    {
         this->course_assigned = course_assign;
         this->role = role;
    }

    TA(string name, int roll, string course1, string research_area ,string course_assign,string role) : research_student(name , roll , course1 ,research_area) , person<int>(name , roll),student()
    {
         this->course_assigned = course_assign;
         this->role = role;
    }

    //inserting a new student role in TA in a linklist

     TA *insert_student(TA *head_ref,string name,string roll,string course1,string course2,string course3,string course_assign,string Role )
    {
        if(head_ref == NULL) //boundary condition
        {
            TA *head_ref= new TA(name,roll,course1,course2,course3,course_assign,Role); //creating head by passing parameters

            head_ref->stu_next = NULL;
            return head_ref;
        }
        else if(head_ref->stu_next == NULL)
        {
            TA *new_node = new TA(name,roll,course1,course2,course3,course_assign,Role);
            new_node->stu_next = NULL;
            head_ref->stu_next = new_node;
            return head_ref;
        }
        else
        {
            TA *new_node = new TA(name,roll,course1,course2,course3,course_assign,Role) , *temp;
            new_node->stu_next = NULL;
            temp = head_ref;

            while(temp->stu_next == NULL)
            {
                temp = temp->stu_next;     //iterating upto last
            }

            temp->stu_next = new_node;
            return head_ref;
        }
    }
  //inserting a new research student role in TA in a linklist
    TA *insert_re_search_student(TA *head_ref,string name,int roll,string course1,string research_area,string course_assign,string Role )
    {
        if(head_ref == NULL)
        {
            TA *head_ref= new TA(name,roll,course1,research_area,course_assign,Role); //creating head by passing values

            head_ref->re_stu_next = NULL;
            return head_ref;
        }
        else if(head_ref->stu_next == NULL)
        {
            TA *new_node = new TA(name,roll,course1,research_area,course_assign,Role);
            new_node->re_stu_next = NULL;
            head_ref->re_stu_next = new_node;
            return head_ref;
        }
        else
        {
            TA *new_node = new TA(name,roll,course1,research_area,course_assign,Role) , *temp;
            new_node->re_stu_next = NULL;
            temp = head_ref;

            while(temp->re_stu_next == NULL)
            {
                temp = temp->re_stu_next;
            }

            temp->re_stu_next = new_node;
            return head_ref;
        }
    }
    
    //displaying the teaching assistant details first role is stu
   TA *display(TA *head_ref,string roll)
    {
      TA *temp_head = head_ref;
        while(temp_head != NULL && student::compare_roll(temp_head) != roll) //compare such that roll no exist or not
        {
           temp_head = temp_head->stu_next;  //Traversing the list
        }

        if(temp_head == NULL)
        {
            cout<<"\nInvalid roll no enter correctyly \n";//Error handling case

        }
        else
        {
            cout<<temp_head->person<string>::display();
            cout<<"Course Assigned : " <<temp_head->course_assigned<<endl;
            cout <<"Role : "<< temp_head->role<<endl;
        }
        return head_ref;  //returning original head

    }

     //displaying the teaching assistant details first role is research stu
   TA *display(TA *head_ref,int roll)//TA STU
    {
      TA *temp_head = head_ref;
        while(temp_head != NULL && research_student::compare_roll(temp_head) != roll) //compare such that roll no exist or not
        {
           temp_head = temp_head->stu_next;  //Traversing the list
        }

        if(temp_head == NULL)
        {
            cout<<"\nInvalid roll no enter correctyly \n";//Error handling case

        }
        else
        {
           cout<<temp_head->person<int>::display();
            cout<<"Course Assigned : " <<temp_head->course_assigned<<endl;
            cout <<"Role : "<< temp_head->role<<endl;
        }
        return head_ref;

    }

    void display1(TA *head_ref,string roll)//Student diplay details
    {
        TA *temp_head = head_ref;
        while(temp_head != NULL && student::compare_roll(temp_head) != roll) //comparing roll
        {
           temp_head = temp_head->stu_next;  //Traversing the list
        }
   
       if(temp_head!=NULL){
        temp_head->student::display();
    }else{
        cout<<"there is no such emtry in student \n";
    }
    return;
    }
    //similar to student research student
    void display2(TA *head_ref,int roll)
    {
        TA *temp_head = head_ref;
        while(temp_head != NULL && research_student::compare_roll(temp_head) != roll) //comparing roll
        {
            temp_head = temp_head->re_stu_next;  //Traversing the list
        }
        if(temp_head!=NULL){
        temp_head->research_student::display();
    }else{
        cout<<"there is no such emtry in research student \n";
    }
    return;
    }

    void display3(TA *head_ref,string roll)//Person student details
    {
        TA *temp_head = head_ref;
        while(temp_head != NULL && student::compare_roll(temp_head) != roll)
        {
            temp_head =temp_head->stu_next;  //Traversing the list
        }
         if(temp_head!=NULL){
        temp_head->person<string>::display();
         }else{
        cout<<"there is no such emtry in person student \n";
    }
    return;
    }

    void display4(TA *head_ref,int roll)//person research student details
    {
        TA *temp_head = head_ref;
        while(temp_head != NULL && research_student::compare_roll(temp_head) != roll) //comparing roll
        {
            temp_head = temp_head->re_stu_next;  //Traversing the list
        }
          if(temp_head!=NULL){
        temp_head->person<int>::display();
        }else{
        cout<<"there is no such emtry in person research student \n";
    }
    return;
    }
    //checking is any duplication possible or not for dtudent by comparing roll no
    bool check_rollno(TA *head_ref , string roll){
    while (head_ref!=NULL && student::compare_roll(head_ref) != roll)
    {
        head_ref = head_ref->stu_next;
    }
    if(head_ref!=NULL){
    return(false);
    }
    return(true);
    
}

//checking is any duplication possible or not for research student by comparing roll no

 bool check_rollno(TA *head_ref , int roll){
    while (head_ref!=NULL && research_student::compare_roll(head_ref) != roll)
    {
        head_ref = head_ref->re_stu_next;
    }
    if(head_ref!=NULL){
    return(false);
    }
    return(true);
    
}

}s;



int main(){
    int choice,choice_1,roll_no,i;
    bool check = true;
    string roll_num,name,course1,course2,course3,course_assign,role,research_area;
    TA *head1 , *head2 , *temp;
    head1 = NULL; head2 = NULL;
    cout<<"1. to enter TA details \n2. to display \n3. to exit \n";
    cout<<"enter your choice : "; cin>>choice;
    while(1){
        switch(choice){
            case 1:
              cout<<"\nchoose the role of TA : \n";
              cout<<"  1. student \n  2. research student\n";
              cout<<"enter your choice : "; cin>>choice_1;
              if(choice_1 == 1){ 
                  role = "student";
                  cout<<"  enter TA name             : ";
                  cin.ignore(); getline(cin , name);
                  cout<<"  enter roll no <string>    : "; cin>>roll_num;
                  temp = head1; check = false;
                  while(!check){
                  check = s.check_rollno(temp, roll_num);
                  if(check == false){
                  cout<<"  enter new roll no<string> : "; cin>>roll_num;
                  }
                  }
                  cout<<"  enter course 1            : "; cin>>course1;
                  cout<<"  entetr course 2           : "; cin>>course2;
                  cout<<"  enter course 3            : "; cin>>course3;
                  check = true;
                  while(check){
                     cout<<"  enter course assign       : "; cin>>course_assign;
                      if(course_assign == course1 || course_assign == course2 || course_assign == course3  ){
                          check = true;
                          cout<<"   course assign should be other than selected course\n";
                      }else{
                          check = false;
                      }
                  }
                  TA a(name , roll_num , course1 , course2 , course3 , course_assign , role);
                  head1 = a.insert_student(head1 ,name , roll_num , course1 , course2 , course3 , course_assign , role);
              } else if(choice_1 == 2){
                  role = "research student";
                  cout<<"  enter TA name             : ";
                  cin.ignore(); getline(cin , name);
                  cout<<"  enter roll no <int>       : "; cin>>roll_no;
                    temp = head2; check = false;
                  while(!check){
                  check = s.check_rollno(temp, roll_no);
                  if(check == false){
                 cout<<"  enter new roll no<int>     : "; cin>>roll_no;
                  }
                  }
                  cout<<"  enter course 1            : "; cin>>course1; check = true;
                  while(check){
                      cout<<"  enter course assign       : "; cin>>course_assign;
                      if(course_assign == course1 ){
                          check = true;
                          cout<<"  course assign should be other than selected course\n";
                      }else{
                          check = false;
                      }
                  }
                  cout<<"  enter research area      : "; cin>>research_area;
                  TA b(name , roll_no , course1 ,research_area ,  course_assign , role);
                  head2 = b.insert_re_search_student(head2 ,name , roll_no , course1 , research_area , course_assign , role);
              }else{
                  cout<<"  enter a valid choice \n";
              }
               break;
               case 2:
               cout<<endl;
                  cout<<"  1. person \n  2. student \n  3. research student \n  4. teaching assistant\n";
                  cout<<"  enter your choice : "; cin>>choice_1;
                  if(choice_1 == 1){
                     cout<<"  1. string \n  2. int\n"; cout<<" enter your choice : "; cin>>choice_1;
                     if(choice_1 == 1){
                         cout<<"enter roll no<string>   : "; cin>>roll_num;  cout<<endl;
                         s.display3(head1 , roll_num);
                     }else if(choice_1 == 2){
                         cout<<" enter roll no<int>     : "; cin>>roll_no;
                         cout<<endl;
                         s.display4(head2 , roll_no); choice_1 = 1;
                     }else{
                         cout<<" choose a valid choice \n"; choice_1 = 1;
                     }
                  }else if(choice_1 == 2){
                      cout<<"  enter roll no <string>   : "; cin>>roll_num; cout<<endl;
                         s.display1(head1 , roll_num);
                  }else if(choice_1 == 3){
                      cout<<"  enter roll no <int>      : "; cin>>roll_no; cout<<endl;
                         s.display2(head2 , roll_no);
                  }else if(choice_1 == 4){
                      cout<<endl;
                      cout<<"  1. student \n  2. research student\n"; cout<<"  enter your choice : "; cin>>choice_1;
                      if(choice_1 == 1){
                            cout<<"  enter roll no         : "; cin>>roll_num; cout<<endl;
                         s.display(head1 , roll_num);
                      }else if(choice_1 == 2){
                           cout<<"enter roll no            : "; cin>>roll_no; cout<<endl;
                         s.display(head2 , roll_no);
                      }else{
                          cout<<"  enter a valid choice\n";
                      }  
                  }else{
                      cout<<"  enter a valid choice\n";
                  }
                  break;
                  case 3: exit(0); break;
                  default : cout<<"  enter a valid choice \n";
        }
        cout<<endl<<endl;
    cout<<"1. to enter TA details \n2. to display \n3. to exit \n";
    cout<<"enter your choice : "; cin>>choice;
    }
}
