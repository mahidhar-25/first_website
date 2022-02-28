/*
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s,temp = "";
	vector<string> s1;
	int n,flag = 0;// cin>>n;
	getline(cin , s);
	for(int i=0;i<s.size() ;i++){
		if(s[i]!= 32){
			temp += s[i];
		}else{
			s1.push_back(temp);
			temp = "";
		}
	}
	s1.push_back(temp);
	sort( s1.begin(), s1.end() );
s1.erase( unique( s1.begin(), s1.end() ), s1.end() );
	cout<<s1.size();
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
	string name , phone_no , roll_no;
	double percentage;
	Node *next;
};

bool duplicate_check(Node *temp , string no){
	if(temp == NULL) return false;
	while(temp!=NULL){
		if(temp->roll_no == no) return true;
		temp = temp->next;
	}
	return false;
}
void insert(Node **head_ref , Node *temp){
	bool x = true;
	Node *new_node = new Node();
	cout<<"enter name : "; cin.ignore(); getline(cin , new_node->name);
	cout<<"enter phone no :"; cin>>new_node->phone_no;
	cout<<"enter roll no : "; cin>>new_node->roll_no;
	while(x){
		x = duplicate_check(temp , new_node->roll_no);
		if(x == true){
            cout<<"enter a new unique roll no previous one already exist : "; cin>>new_node->roll_no;
		}
	}
	cout<<"enter percentage : "; cin>>new_node->percentage;
	new_node->next = NULL;
	if(*head_ref == NULL){
		*head_ref = new_node; return;
	}
	(*head_ref)->next = new_node; *head_ref = (*head_ref)->next;
	return;
}

void search(Node *head_ref , string no){
	int flag = 0;
	while(head_ref!=NULL){
		if(head_ref->roll_no == no){
			flag = 1;
			cout<<"name : " <<head_ref->name<<endl;       cout<<"phone no :"<<head_ref->phone_no<<endl; 
	        cout<<"roll no : "<<head_ref->roll_no<<endl;  cout<<"percentage : "<<head_ref->percentage<<endl; 
		}
		head_ref = head_ref->next;
	}
	if(flag==0)
	cout<<"no such student exist \n";
	
	return;
}

Node* delete_details(Node **head_ref , string no){
	Node *n = new Node(); n = *head_ref;
	if((*head_ref)->roll_no == no){
		*head_ref = (*head_ref)->next; return(*head_ref);
	}
	while(*head_ref!=NULL){
		if((*head_ref)->next->roll_no == no && (*head_ref)->next->next !=NULL){
			(*head_ref)->next = (*head_ref)->next->next; return(n);
		}else if((*head_ref)->next->roll_no == no && (*head_ref)->next->next ==NULL){
			(*head_ref)->next = NULL; return n;
		}

		*head_ref = (*head_ref)->next;
	}
	return(n);
}

void update(Node *head_ref , string no){
	Node *temp = new Node(); temp = head_ref;
	bool x =true;
	int flag = 0;
	while(head_ref!=NULL){
		if(head_ref->roll_no == no){
			flag = 1;
		cout<<"enter name : "; cin.ignore(); getline(cin , head_ref->name);
    	cout<<"enter phone no :"; cin>>head_ref->phone_no;
	    cout<<"enter roll no : "; cin>>head_ref->roll_no;
		while(x){
		x = duplicate_check(temp , head_ref->roll_no);
		if(x == true){
            cout<<"enter a new unique roll no previous one already exist : "; cin>>head_ref->roll_no;
		}
	}
	    cout<<"enter percentage : "; cin>>head_ref->percentage; 
	    return;
		}
	}
	if(flag==0)
	cout<<"no such student exist \n";
	
	return;
}

void print(Node *head_ref){
	setiosflags(ios::left);
	cout<<setw(20)<<"student_name"<<setw(20)<<"roll no"<<setw(20)<<"phone no"<<setw(10)<<"percentage"<<endl;
	while(head_ref!=NULL){
		cout<<setw(20)<<head_ref->name<<setw(20)<<head_ref->roll_no<<setw(20)<<head_ref->phone_no<<setw(10)<<head_ref->percentage<<endl;
		head_ref = head_ref->next;
	}
}
int main(){
	Node *head;  head = NULL; Node *temp; temp = NULL;
	string no;
	int choice,count =0;
	cout<<"enter 1. insert student details \nenter 2. search for details \nenter 3. delete \nenter 4. update \nenter 5. display \n6.exit\n"; 
	cout<<"enter choice : " ; cin>>choice;
	while(1){
		switch(choice){
			case 1:  insert(&head , temp);count++; if(count==1){temp = head ;}break;
			case 2:  cout<<"enter roll no : "; cin>>no; search(temp , no); break;
			case 3:  cout<<"enter roll no : "; cin>>no; temp = delete_details(&temp , no); break;
			case 4:  cout<<"enter roll no : "; cin>>no; update(temp , no); break;
			case 5:  print(temp); break;
			case 6:  exit(0) ; break;
			default : cout<<"enter a valid choice \n"; break;
				
		}
	cout<<"enter 1. insert student details \nenter 2. search for details \nenter 3. delete \nenter 4. update \nenter 5. display \n6.exit\n"; 
	cout<<"enter choice : " ; cin>>choice;
	}
}
