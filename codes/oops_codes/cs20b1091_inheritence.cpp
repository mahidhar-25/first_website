//NAME    : B.MAHIDHAR REDDY
//ROLL NO : CS20B1091
//TOPIC   : INHERITENCE

#include<iostream>
using namespace std;

//BASE CLASS account for savings , checkingderived classes
class account{
public:
long long int account_no;
double account_balence,intrest_rate,fee_charged;
account *next;
public :
 account(double d=0){  //parameterized constructor to entered minimum balence to open a acoount
     if(d<0){
         cout<<"you entered account balence less than zero("<<d<<")"<<" its automatically set to 0"<<endl;
         account_balence = 0;
     }else{
     account_balence = d;
     }
 }

 int search_account_no(account *head_ref , long long int no){  //find if any duplicate account no exist
     while(head_ref!=NULL){
         if(head_ref->account_no == no){
             cout<<"this account no already registered so plz enter another one "<<endl;
             return(1);
         }
         head_ref = head_ref->next;
     }
     return(0);
 }

 account* create_account(account *head_ref){  //creating account
 
 int i=1;
 account* new_node = new account();
  new_node->account_balence = account_balence;
  new_node->intrest_rate = 0;
  while(i){
  cout<<"enter your account no : "; cin>>new_node->account_no;
  i = search_account_no(head_ref , new_node->account_no );
  }
  new_node->next = NULL;
  if(head_ref == NULL){
      head_ref = new_node;
  }else{
      (head_ref)->next = new_node;  head_ref = (head_ref)->next;
  }
  return(head_ref);
 }

 double print(account* head_ref , long long int no){ //printing accouont balence
     while(head_ref!=NULL){
         if(head_ref->account_no == no){
         return((head_ref)->account_balence);
         }
         head_ref = (head_ref)->next;
     }
     cout<<"there is no account with these details "<<endl; return(0);
 }

 bool credit(account* head_ref , long long int no , double amount){  //depositing amount into account
     while(head_ref!=NULL){
         if(head_ref->account_no == no){
             head_ref->account_balence = head_ref->account_balence + amount;
             return(1);
         }
         head_ref = head_ref->next;
     }
     cout<<"there is no account with these details "<<endl; return(0);
 }

 bool debit(account* head_ref , long long int no , double amount){  //removing amount from account
      while(head_ref!=NULL){
         if(head_ref->account_no == no){
             if(head_ref->account_balence >= amount){
             head_ref->account_balence = head_ref->account_balence - amount;
             return(1);
             }else{
                 cout<<"your account balence is less than u entered"<<endl;
                 return(0);
             }
         }
         head_ref = head_ref->next;
     }
     cout<<"there is no account with these details "<<endl; return(0);    
 }
  

};

//base class savings account
class savings_account : public account{
    public :
    double intrest_rate;
    public :
    savings_account(double balence , double intrest = 0.05)

                             : account(balence){

                        this->intrest_rate = intrest;

    }

    account *create_account(account *head_ref){ //creating account including intrest rate
        account *temp = NULL;
        temp = account:: create_account(head_ref);
        temp->intrest_rate = intrest_rate;
        return(temp);
    }

   double calculate_intrest(account *head_ref , long long int no ){  //calculation intrest amount
       if(head_ref == NULL){
            cout<<"list is empty , there are no savings accounts registered ";
            return(0);
        }
     double rate;
     while(head_ref!=NULL){
         if(head_ref->account_no == no ){
            return((head_ref->account_balence)*(head_ref->intrest_rate));
         }
         head_ref = head_ref->next;
     }
       cout<<"there is no account with these details"<<endl;
       return(0.00);
   }

   double total_amount(account *head_ref , long long int no ){ //calculating total amount inclluding intrest
       if(head_ref == NULL){
            cout<<"list is empty , there are no savings accounts registered ";
            return(0);
        }
    while(head_ref!=NULL){
         if(head_ref->account_no == no ){
            return((head_ref->account_balence)*(head_ref->intrest_rate) + (head_ref->account_balence));
         }
         head_ref = head_ref->next;
     }
       cout<<"there is no account with these details"<<endl;
       return(0.00);
   }

   void update_intrest(account *head_ref , long long int no , double rate){  //updating intresting rate
       if(head_ref == NULL){
            cout<<"list is empty , there are no savings accounts registered ";
            return;
        }
       while(head_ref!=NULL){
           if(head_ref->account_no == no){
               cout<<"intrest rate is updated from "<<head_ref->intrest_rate;
               head_ref->intrest_rate = rate;
               cout<<" to  "<<rate<<endl;
               return;
           }
           head_ref = head_ref->next;
       }
       cout<<"there is no account with these details "<<endl;
   }
}s(0,0);

//derived class for checking
class checking_account : public account{
    public : 
    double fee_charged;

    public :
     checking_account(double balence , double charge = 0.01)

                             : account(balence){
       this->fee_charged = charge;
    }

      account *create_account(account *head_ref){
        account *temp = NULL;
        temp = account:: create_account(head_ref);
        temp->fee_charged = fee_charged;
        return(temp);
    }

    void credit(account* head_ref , long long int no , double amount){  //crediting into account
        if(head_ref == NULL){
            cout<<"list is empty , there are no checking accounts registered ";
            return;
        }
       bool tax =  account :: credit(head_ref ,no ,amount);
       if(tax == true){
            while(head_ref!=NULL){
         if(head_ref->account_no == no){
             head_ref->account_balence = head_ref->account_balence - head_ref->fee_charged;
             cout<<"charge  = "<<head_ref->fee_charged<<endl;
             cout<<"total amount = "<<head_ref->account_balence<<endl;
         }
         head_ref = head_ref->next;
     }
       }
    }

    void debit(account* head_ref , long long int no , double amount){  //debiting from account
        if(head_ref == NULL){
            cout<<"list is empty , there are no checking accounts registered ";
            return;
        }
        double amount_original = account :: print(head_ref ,no);
        bool tax = account :: debit(head_ref ,no ,amount);
        if(tax == true){
              while(head_ref!=NULL){
         if(head_ref->account_no == no){
             if(head_ref->account_balence >= head_ref->fee_charged){
                head_ref->account_balence = head_ref->account_balence - head_ref->fee_charged ;
                cout<<"charge  = "<<head_ref->fee_charged<<endl;
                cout<<"total amount = "<<head_ref->account_balence<<endl;
             }else{
                 head_ref->account_balence = 0.00;
                 account :: credit(head_ref ,no ,amount_original);
                 cout<<"not sufficient money"<<endl;
                 cout<<"total amount in account is  = "<<head_ref->account_balence<<endl;
             }
         }
         head_ref = head_ref->next;
     }
        }
    }

    void update_fee_charge(account *head_ref , long long int no , double fee){  //updating fee charge
        if(head_ref == NULL){
            cout<<"list is empty , there are no checking accounts registered ";
            return;
        }
         while(head_ref!=NULL){
           if(head_ref->account_no == no){
               cout<<"fee charged is updated from "<<head_ref->fee_charged;
               head_ref->fee_charged = fee;
               cout<<"  to "<<fee<<endl;
           }
           head_ref = head_ref->next;
       }
       cout<<"there is no account with these details "<<endl;
    }

    void print_fee(account *head_ref , long long int no){
        if(head_ref == NULL){
            cout<<"list is empty , there are no checking accounts registered ";
            return;
        }
        while(head_ref!=NULL){
           if(head_ref->account_no == no){
               cout<<"fee charge : "<<head_ref->fee_charged<<endl;
               return;
           }
           head_ref = head_ref->next;
       }
       cout<<"there is no account with these details "<<endl;
    }

}s1(0,0);

int main(){
    long long int no;
    int choice , choice_opt ,count = 0, count1 = 0;
    double fee,rate,amount;
    account* head = NULL; account* head1 = NULL; account* temp = NULL; account* temp1 = NULL;
     
   cout<<"\n1. open account(savings/checking)        6. calculate and update intrest \n2. credit(savings/checking)              7. change/update fee amount  ";
   cout<<"\n3. debit(savings/checkings)              8. print checking fee           \n4. change/update intrset rate            9. transact and update ";
   cout<<"\n5. calculate intrest                    10. exit"<<endl;
   cout<<"\n enter your choice : "; cin>>choice;
  while(1){
       switch(choice){
           case 1 : cout<<"enter 1 fo savings account        enter 2 for checking account"<<endl; 
                    cout<<"\n enter your choice : ";  cin>>choice_opt;
                    if(choice_opt == 1){
                      cout<<"enter balence  and  savings intrest between 0 to 1"<<endl; cin>>amount>>rate;
                      savings_account a1(amount , rate);
                      head = a1.create_account(head); count++;
                    if(count == 1){temp = head;}
                }else if(choice_opt == 2){
                     cout<<"enter balence  and  fee charge"<<endl; cin>>amount>>fee;
                     checking_account a1(amount , fee);
                     head1 = a1.create_account(head1); count1++;
                    if(count1 == 1){temp1 = head1;}
                }else{cout<<"enter a valid choice"<<endl;}
           break;
           case 2 : cout<<"enter 1 fo savings account        enter 2 for checking account"<<endl;
                    cout<<"\n enter your choice : ";  cin>>choice_opt;
                    if(choice_opt == 1){
                     cout<<"enter account no and amount to be credit : "; cin>>no>>amount;
                     s.credit(temp , no , amount);
                }else if(choice_opt == 2){
                     cout<<"enter account no and amount to be credit : "; cin>>no>>amount;
                     s1.credit(temp1 , no , amount);
                }else{cout<<"enter a valid choice"<<endl;}
           break;
           case 3 : cout<<"enter 1 fo savings account        enter 2 for checking account"<<endl; 
                    cout<<"\n enter your choice : ";  cin>>choice_opt;
                    if(choice_opt == 1){
                     cout<<"enter account no and amount to be debit : "; cin>>no>>amount;
                     s.debit(temp , no , amount);
                }else if(choice_opt == 2){
                     cout<<"enter account no and amount to be debit : "; cin>>no>>amount;
                     s1.debit(temp1 , no , amount);
                }else{cout<<"enter a valid choice"<<endl;}
           break;
           case 4 : cout<<"enter account no and new intrest rate : "; cin>>no>>rate;
                    s.update_intrest(temp , no , rate);
           break;
           case 5 : cout<<"enter account no : "; cin>>no;
                    cout<<"intrest amount = "<<s.calculate_intrest(temp , no);
           break;
           case 6 : cout<<"enter account no and new intrest rate : "; cin>>no>>rate;
                    if(temp!=NULL){
                    cout<<"intrest amount = "<<s.calculate_intrest(temp , no)<<endl;
                    cout<<"total amount = "<<s.total_amount(temp , no)<<endl;
                    s.update_intrest(temp , no , rate);
                    }else{cout<<"there are no registered accounts";}
           break;
           case 7 : cout<<"enter account no anf new fee charge : "; cin>>no>>fee;
                    s1.update_fee_charge(temp1 , no , fee);
           break;
           case 8 : cout<<"enter account no : "; cin>>no;
                    s1.print_fee(temp1 , no);
           break;
           case 9 : cout<<"enter account no and  amount to pay: "; cin>>no>>amount;
                   s1.debit(temp1 , no , amount);
           break;
           case 10 : exit(0);
           default : cout<<"enter a valid choice";
       }
       cout<<"\n1. open account(savings/checking)        6. calculate and update intrest \n2. credit(savings/checking)              7. change/update fee amount  ";
       cout<<"\n3. debit(savings/checkings)              8. print checking fee           \n4. change/update intrset rate            9. transact and update ";
       cout<<"\n5. calculate intrest                    10. exit"<<endl;
       cout<<"\n enter your choice : "; cin>>choice;
   }

    return(0);
}