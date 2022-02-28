//NAME : B.MAHIDHAR REDDY
//ROLL NO : CS20B1091
//TOPIC : function template and exceptional handling(try , catch)
#include<iostream>
#include<string>
using namespace std;

template<typename T>


void selection_sort(T s[], int n){  //selection sort alogarithm
    
    try{
        if(n <= 0){  //exceptional handling case
            throw(n);
        }
    for(int i=0 ; i< n-1 ; i++){
        int min = i;
        for(int j = i+1 ;j<n ; j++){
             if(s[min] > s[j]){
                 min = j;
             }
        }
        if(min!=i){
           T temp = s[i];
            s[i] = s[min];
            s[min] = temp;
           //swap(s[i] ,s[min]);      //swaping inbuilt
        }
        
    }
    }
    catch(int size){
        cout<<"size is zero or less than zero there are no elements to sort "<<endl;
        }
        
        cout<<"array is sorted \n";
   
}

template<typename T>

void display(T s[] , int n){ //function to display array
try{
    if(n<=0){
        throw(n);
    }
    cout<<"array after sorted : ";
    for(int i=0;i<n;i++){
        cout<<s[i]<<"  ";
    }
    cout<<endl<<endl;
}
catch(int x){
 cout<<"the array size is : "<<x<<" there are no elements to be sorted \n";
}
}

int main(){
 int choice,choice_1,n1=0,n2=0,n3=0,n4=0,i;
 string a[10000];
 int b[10000];
 char c [10000];
 float d[10000];
 cout<<"1. get values \n2. sort \n3. display \n4. exit \n";
 cout<<"enter your choice : "; cin>>choice;
 //menu driven program
 while(1){
     switch(choice){
         case 1: 
                cout<<"\nIF WE ENTER ANY DATA TYPE FOR MULTIPLE TIMES PREVIOUS ARRAY WILL WE VANISHED : \n";
                cout<<"choose the datatype of array : \n";
                cout<<"1. string \n2. char \n3. int \n4. float \n";
                cout<<"enter your choice : "; cin>>choice_1;
                if(choice_1 == 1){
                    cout<<"enter the size of an array : "; cin>>n1;  //taking the size of array
                    cout<<"enter the strings : ";
                    for(i=0;i<n1;i++){
                        cin>>a[i];       //taking inputs of array
                    }
                    cout<<"\nthe input taken : ";
                    for(i=0;i<n1;i++){
                        cout<<a[i]<<"  ";     //printing the input function
                    }cout<<endl<<endl;
                }else  if(choice_1 == 2){
                    cout<<"enter the size of an array : "; cin>>n2;
                    cout<<"enter the chars : ";
                    for(i=0;i<n2;i++){
                        cin>>c[i];
                    }
                    cout<<"\nthe input taken : ";
                    for(i=0;i<n2;i++){
                        cout<<c[i]<<"  ";
                    }cout<<endl<<endl;
                }else if(choice_1 == 3){
                    cout<<"enter the size of an array : "; cin>>n3;
                    cout<<"enter the integers : ";
                    for(i=0;i<n3;i++){
                        cin>>b[i];
                    }
                    cout<<"\nthe input taken : ";
                    for(i=0;i<n3;i++){
                        cout<<b[i]<<"  ";
                    }cout<<endl<<endl;
                }else if(choice_1 == 4){
                    cout<<"enter the size of an array : "; cin>>n4;
                    cout<<"enter the float values : ";
                    for(i=0;i<n4;i++){
                        cin>>d[i];
                    }
                    cout<<"\nthe input taken : ";
                    for(i=0;i<n4;i++){
                        cout<<d[i]<<"  ";
                    }cout<<endl<<endl;
                }else{
                    cout<<"enter a valid choice\n\n";
                }
            break;
            case 2:
                  cout<<"choose the datatype of array to be sorted as u entered earlier: \n";
                  cout<<"1. string \n2. char \n3. int \n4. float \n";
                  cout<<"enter your choice : "; cin>>choice_1;
                  if(choice_1 == 1){
                      cout<<"the array passing to sort is : ";
                       for(i=0;i<n1;i++){
                       cout<<a[i]<<"  ";            //printing the array before sorted
                    }cout<<endl<<endl;
                   selection_sort<string>(a , n1);  //passing the array
                }else  if(choice_1 == 2){
                    cout<<"the array passing to sort is : ";
                     for(i=0;i<n2;i++){
                       cout<<c[i]<<"  ";    //all choice 1,2,3,4 are similar except data type
                    }cout<<endl<<endl;
                   selection_sort<char>(c , n2);
                }else if(choice_1 == 3){
                     cout<<"the array passing to sort is : ";
                    for(i=0;i<n3;i++){
                        cout<<b[i]<<"  ";
                    } cout<<endl<<endl;
                   selection_sort<int>(b , n3);
                }else if(choice_1 == 4){
                    cout<<"the array passing to sort is : ";
                     for(i=0;i<n4;i++){
                       cout<<d[i]<<"  ";
                    }cout<<endl<<endl;
                   selection_sort<float>(d , n4);
                }else{
                    cout<<"enter a valid choice\n";
                }
            break;
            case 3:
                cout<<"1. string \n2. char \n3. int \n4. float \n";
                  cout<<"enter your choice : "; cin>>choice_1;
                  if(choice_1 == 1){
                    display<string>(a , n1);  //displaying the already sorted array;
                }else  if(choice_1 == 2){
                     display<char>(c , n2);
                }else if(choice_1 == 3){
                     display<int>(b , n3);
                }else if(choice_1 == 4){
                     display<float>(d , n4);
                }else{
                    cout<<"enter a valid choice\n";
                }
             break;
             case 4: exit(0); break;
             default : cout<<"enter a valid choice "; break;
     }
     cout<<"\n1. get values \n2. sort \n3. display \n4. exit \n";
     cout<<"enter your choice : "; cin>>choice;
 }
}
