#include<iostream>
#include<string>
using namespace std;

template<typename T>

class bubble_sort{
    T *arr;
    int size;
    public :
    void getdata(){
    cout<<"enter the size of array : "; cin>>size;
    arr = new T[size];
    cout<<"enter elements : ";
    for(int i=0;i<size;i++)
             cin>>arr[i];
    
    sorting(arr , size);
    }
    void sorting(T arr[] , int n);
};

template<typename T>
void bubble_sort<T>::sorting(T arr[] , int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i] , arr[j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int choice = 1;
    cout<<"enter 1. if you datatype in int \nenter 2. if you datatype in char \nenter 3. if you datatype in float \nenter 4. if you datatype in string \n";
    cout<<"enter 5. if you datatype in double \nenter 6. to exit\n";
    cout<<"enter your choice : "; cin>>choice;
    while(1){
        switch(choice){
            case 1: bubble_sort <int> a; a.getdata(); break;
            case 2: bubble_sort <char> b; b.getdata(); break;
            case 3: bubble_sort <float> c; c.getdata(); break; 
            case 4: bubble_sort <string> d; d.getdata(); break;
            case 5: bubble_sort <double> e; e.getdata(); break;
            case 6: exit(0); break;
            default : cout<<"enter a valid choice : "; break;
        }
     cout<<"enter 1. if you datatype in int \nenter 2. if you datatype in char \nenter 3. if you datatype in float \nenter 4. if you datatype in string \n";
    cout<<"enter 5. if you datatype in double \nenter 6. to exit\n";
    cout<<"enter your choice : "; cin>>choice;
    }
    return(0);
    
}