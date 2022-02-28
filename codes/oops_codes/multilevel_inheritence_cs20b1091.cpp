//NAME    : B.MAHIDHAR REDDY
//ROLL NO : CS20B1091
//MULTILEVEL INHERITENCE


#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
//base class employee
class employee{
    protected :
    string employee_id , employee_name;
};

// derived class from employee class in protected 
class contract : protected employee
{
  protected :
  double pay_per_hour;
  public :
   double set_pay(){  ///is used to set salary
      cout<<"enter updated salary per month : ";
        cin>>pay_per_hour; 
        return(pay_per_hour);
  }
  void get_pay(double time , double salary){  //get pay is used to get total salary amount
      cout<<"total salaray : "<<(time)*salary;
  }
};

// derived class from employee class in protected 
class salaried : protected employee
{
protected :
double monthly_pay;
public :
  double set_pay(){  ///is used to set salary
      cout<<"enter updated salary per month : ";
        cin>>monthly_pay; 
        return(monthly_pay);
  }
  void get_pay(double time , double salary){   //get pay is used to get total salary amount
      cout<<"total salaray : "<<(time)*salary;
  }
};

//derived class  fm another derived class salaried in private mode
class manager : private salaried
{
    private :
    manager* next;
  public :
  void update_details(manager* head_ref , string s){   //updating details of manager by taking input name/id
      int choice,flag =0;
      if(head_ref == NULL){
      cout<<"there are no managers appointed"<<endl; return;
  }
      while((head_ref)!=NULL){ //updating details by asking user to change name / id / both
          if((head_ref)->employee_name == s || (head_ref)->employee_id == s){
              flag =1;
             cout<<"if u want to channge id enter 1 \nif u wanr to change name enter 2 \nif u want to change both enter any no otheer than 1,2 \nenter your choice : "; cin>>choice;
               if(choice == 1){
      cout<<"enter employee id : "; cin.ignore(); getline(cin , (head_ref)->employee_id); //getline is used to taking input
              }else if(choice == 2){
      cout<<"enter employee name : "; cin.ignore(); getline(cin , (head_ref)->employee_name);
          }else{
      cout<<"enter employee id : "; cin.ignore();  getline(cin , (head_ref)->employee_id);
      cout<<"enter employee name : "; cin.ignore();  getline(cin , (head_ref)->employee_name);
          }
          }
          head_ref = (head_ref)->next;
  }
  if(flag == 0){
      cout<<"there is no manager with these details \n";
  }
  }

  manager* set_details(manager** head_ref){   //set details is used to set details of a manager
      manager* new_node = new manager(); //cin.ignore();
       manager *temp =  *head_ref;
       cout<<"enter employee id : "; cin>>new_node->employee_id; //getline(cin , id); cin.ignore();
       cout<<"enter employee name : "; cin.ignore(); getline(cin , new_node->employee_name); 
        cout<<"enter monthly pay :"; cin>>new_node->monthly_pay;
      new_node->next = NULL;
      if(*head_ref == NULL){
          *head_ref = new_node;
          return(*head_ref);
      }else{
      while((*head_ref)->next!=NULL){
          *head_ref = (*head_ref)->next;
      }
      (*head_ref)->next = new_node;
  }
  return(temp);
  }
  manager* get_details(manager** head_ref , string s){ 
      int flag =0;                                          //it is used to get details of a manger
      manager* temp = *head_ref;
       if(*head_ref == NULL){
      cout<<"there are no managers appointed"<<endl; return(*head_ref);
  }    //get details of a specific manager
      while((*head_ref)!=NULL){
          if((*head_ref)->employee_name == s || (*head_ref)->employee_id == s){
              flag = 1;
      cout<<"employee id : "<<(*head_ref)->employee_id<<endl;
      cout<<"employee name : "<<(*head_ref)->employee_name<<endl;
      cout<<"monthly pay : "<<(*head_ref)->monthly_pay<<endl;
          }
          *head_ref = (*head_ref)->next;
  }
   if(flag == 0){
      cout<<"there is no manager with these details \n";
  }
  return(temp);
  }
  void calculate_salary(manager* head_ref , string s){  //calculating slary of manager
      double time;
      bool flag = false;
        if(head_ref == NULL){
      cout<<"there are no managers appointed"<<endl;
      return;
  }
      cout<<"enter no of working months :"; cin>>time;
       while((head_ref)!=NULL){
          if((head_ref)->employee_name == s || (head_ref)->employee_id == s){
              flag = true; salaried::get_pay( time , head_ref->monthly_pay);
          }
          head_ref = (head_ref)->next;
  }
    if(flag == false){
      cout<<"there are no manager with these details "<<endl;
  }
  }
 
  void set_pay(manager* head_ref , string s){
      bool flag;                                     //set salary is used to set salary of specified manager
        if(head_ref == NULL){
      cout<<"there are no managers appointed"<<endl;  return;
        }
      while((head_ref)!=NULL){
          if((head_ref)->employee_name == s || (head_ref)->employee_id == s){
              head_ref->monthly_pay = salaried::set_pay(); flag = true;
          }
          head_ref = (head_ref)->next;
  }
  if(flag == false){
      cout<<"there are no manager with these details "<<endl;
  }
  
  }

  void print_employees(manager* head_ref){ //printing all the manager details
        if(head_ref == NULL){
      cout<<"there are no managers appointed"<<endl;  return;
  }
      cout<<setiosflags(ios::left);
      cout<<setw(20)<<"employee_id"<<setw(30)<<"employee_name"<<setw(20)<<"monthly pay"<<setw(20)<<"position"<<endl;
      while(head_ref!=NULL){
          cout<<setw(20)<<head_ref->employee_id<<setw(30)<<head_ref->employee_name<<setw(20)<<head_ref->monthly_pay<<setw(20)<<"manager"<<endl;
          head_ref = head_ref->next;
      }
  }
}s;

class intern : private contract
{
    intern* next;
    public :
    void update_details(intern* head_ref , string s){  //updating details of intern by taking input name/id
      int choice , flag = 0;
      if(head_ref == NULL){
      cout<<"\nthere are no intern appointed"<<endl; return;
  }
      while((head_ref)!=NULL){
          if((head_ref)->employee_name == s || (head_ref)->employee_id == s){
              flag = 1;
              cout<<"if u want to channge id enter 1 \nif u wanr to change name enter 2 \nif u want to change both enter any no otheer than 1,2 \nenter your choice : "; cin>>choice;
              if(choice == 1){
      cout<<"enter employee id : ";  cin.ignore(); getline(cin , (head_ref)->employee_id);
              }else if(choice == 2){
      cout<<"enter employee name : ";  cin.ignore(); getline(cin , (head_ref)->employee_name);
          }else{
      cout<<"enter employee id : ";  cin.ignore(); getline(cin , (head_ref)->employee_id);
      cout<<"enter employee name : "; cin.ignore();  getline(cin ,(head_ref)->employee_name);
          }
          
  }
  head_ref = (head_ref)->next;
  }
   if(flag == 0){
      cout<<"there is no intern with these details \n";
  }
    }
 intern* set_details(intern** head_ref){  //set details is used to set details of a intern
      intern* new_node = new intern();
      intern *temp =  *head_ref;
       cout<<"enter employee id : "; cin>>new_node->employee_id; //getline(cin , id); cin.ignore();
       cout<<"enter employee name : "; cin.ignore(); getline(cin , new_node->employee_name); 
        cout<<"enter pay per hour :"; cin>>new_node->pay_per_hour;
      new_node->next = NULL;
        if(*head_ref == NULL){
          *head_ref = new_node;
          return(*head_ref);
      }else{
      while((*head_ref)->next!=NULL){
          *head_ref = (*head_ref)->next;
      }
      (*head_ref)->next = new_node;
  }
  return(temp);
  }
  intern* get_details(intern** head_ref , string s){ 
      int flag = 0; //get details of a specific intern
  intern *temp =  *head_ref;
       if(*head_ref == NULL){
      cout<<"there are no interns appointed"<<endl; return(*head_ref);
  }
      while((*head_ref)!=NULL){
          if((*head_ref)->employee_name == s || (*head_ref)->employee_id == s){
              flag = 1;
      cout<<"employee id : "<<(*head_ref)->employee_id<<endl;
      cout<<"employee name : "<<(*head_ref)->employee_name<<endl;
      cout<<"pay per hour : "<<(*head_ref)->pay_per_hour<<endl;
          }
          *head_ref = (*head_ref)->next;
  }
  if(flag == 0){
      cout<<"there is no intern with these details \n";
  }
  return(temp);
 
  }
  void calculate_salary(intern* head_ref , string s){   //calculating slary of intern
      double time;
      int flag =0;
       if(head_ref == NULL){
      cout<<"there are no interns appointed"<<endl; return;
  }
      cout<<"enter no of working hours :"; cin>>time;
       while((head_ref)!=NULL){
          if((head_ref)->employee_name == s || (head_ref)->employee_id == s){
              flag = 1;  contract::get_pay(time , head_ref->pay_per_hour );
          }
          head_ref = (head_ref)->next;
  }
  if(flag == 0){
      cout<<"there is no intern with these details \n";
  }
  }
  
  void set_pay(intern* head_ref , string s){    //set salary is used to set salary of specified intern
       int flag = 0;
       if(head_ref == NULL){
      cout<<"there are no interns appointed"<<endl;
  }
      while((head_ref)!=NULL){
          if((head_ref)->employee_name == s || (head_ref)->employee_id == s){
              flag = 1; head_ref->pay_per_hour = contract::set_pay();
          }
          head_ref = (head_ref)->next;
  }
   if(flag == 0){
      cout<<"there is no intern with these details \n";
  }
 
  }
  void print_employees(intern* head_ref){  //printing all the intern details
        if(head_ref == NULL){
      cout<<"there are no intern appointed"<<endl;  return;
  }
      cout<<setiosflags(ios::left);
      cout<<setw(20)<<"\nemployee_id"<<setw(30)<<"employee_name"<<setw(20)<<"pay per hour"<<setw(20)<<"position"<<endl;
      while(head_ref!=NULL){
          cout<<setw(20)<<head_ref->employee_id<<setw(30)<<head_ref->employee_name<<setw(20)<<head_ref->pay_per_hour<<setw(20)<<"intern"<<endl;
          head_ref = head_ref->next;
      }
  }
}s1;

int main(){
        int choice,choice_1;
        string id,name;
        string s_id_name;
        double pay;
        manager *head1; head1 = NULL;
        intern *head2;  head2 = NULL;
        cout<<"1. create employee(manager/intern) \n2. update employee_id \n3. print_employee details \n4. update pay(manager/intern)";
        cout<<"\n5. calculate salary(manager/intern) \n6. exit"<<endl;
        cout<<"enter your choice : "; cin>>choice;
        while(1){
            switch(choice){
             case 1:
                cout<<"enter 1. for manager \nenter 2. for intern \n"; cout<<"enter your choice : ";
                cin>>choice_1;
                if(choice_1 == 1){
                    head1 = s.set_details(&head1);
                }else if(choice_1 == 2){
                   head2 = s1.set_details(&head2);
                }else{
                    cout<<"enter valid choice"<<endl;
                }
            break;
            case 2:
                cout<<"enter 1. for manager \nenter 2. for intern \n"; cout<<"enter your choice : ";
                cin>>choice_1;
                if(choice_1 == 1){
                     cout<<"enter employee id / name :"; cin.ignore(); getline(cin , s_id_name); 
                    s.update_details(head1,s_id_name);
                }else if(choice_1 == 2){
                     cout<<"enter employee id / name :"; cin.ignore(); getline(cin , s_id_name); 
                    s1.update_details(head2,s_id_name);
                }else{
                    cout<<"enter valid choice"<<endl;
                }
            break;
            case 3:
               cout<<"enter 1. for manager \nenter 2. for intern \nenter 3. for all managers and interns details\n"; cout<<"enter your choice : ";
                cin>>choice_1;
                   if(choice_1 == 1){
                     cout<<"enter employee id / name :"; cin.ignore(); getline(cin , s_id_name); 
                    head1 = s.get_details(&head1,s_id_name);
                }else if(choice_1 == 2){
                     cout<<"enter employee id / name :"; cin.ignore(); getline(cin , s_id_name); 
                    head2 = s1.get_details(&head2,s_id_name);
                }else if(choice_1 == 3){
                    cout<<"manger details "<<endl; s.print_employees(head1);
                    cout<<"\nintern details "; s1.print_employees(head2);
                }else{
                  cout<<"enter valid choice"<<endl;
                }
                 
            break;
            case 4:
                cout<<"enter 1. for manager \nenter 2. for intern"; cout<<"\nenter your choice : ";
                cin>>choice_1;
                if(choice_1 == 1){
                    cout<<"enter employee id / name :"; cin.ignore(); getline(cin , s_id_name); 
                    s.set_pay(head1 , s_id_name);
                }else if(choice_1 == 2){
                     cout<<"enter employee id / name :";cin.ignore(); getline(cin , s_id_name); 
                    s1.set_pay(head2 , s_id_name);
                }else{
                    cout<<"enter valid choice"<<endl;
                }
            break;
            case 5:
                cout<<"enter 1. for manager \nenter 2. for intern";cout<<"\nenter your choice :";
                cin>>choice_1;
                if(choice_1 == 1){
                    cout<<"enter employee id / name :"; cin.ignore(); getline(cin , s_id_name); 
                    s.calculate_salary(head1 , s_id_name);
                }else if(choice_1 == 2){
                     cout<<"enter employee id / name :"; cin.ignore(); getline(cin , s_id_name); 
                    s1.calculate_salary(head2 , s_id_name);
                }else{
                    cout<<"enter valid choice"<<endl;
                }
            break;
            case 6:
               exit(0); break;
            default : cout<<"enter a valid choice"<<endl;
               
            }
        cout<<"\n\n1. create employee(manager/intern) \n2. update employee_id \n3. print_employee details \n4. update pay(manager/intern)";
        cout<<"\n5. calculate salary(manager/intern) \n6. exit"<<endl;
        cout<<"enter your choice : "; cin>>choice;
        }
}
