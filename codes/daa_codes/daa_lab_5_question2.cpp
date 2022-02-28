/*
steps :
  step 1 :
   take the array from user pass into quick sort function
  step 2:
    make partion similat to binary search 
    take two int leftpart, right part, make partion using function

    takinf 
    first pivot as starting eklement second pivot as last element 
    make sure first element is lesser if not swap them with address so that it will be easy for us teracking the position after iteration

    three parts :
    part 1 = <firt pivot
    part 2 = >= first pivot and <second pivot
    part 3 = >=second pivot

    we will check from starting with condition so in which case it falls we will swap respective end element after iteration

    we will make sure the pivots are at therepositions by swapping

    in this way we can be done with two pivots


    worst case ;
    ex : 8 7 6 5 4 3 2 1
         1 7 6 5 4 3 2 8
         1 2 6 5 4 3 7 8
         it just swapping from both sides

         every iteration we will fix two pivots
         t(n) = t(n/3) + t(n/3-1) + t(n/3-2)+ n-2  similarly equal to 3t(n/3) + n-2
         by master theorem : 
         a = 3, b = 3 n log a base b = n
         for dividing the array we take log n base 3

         so worst case time complexity : nlog(n base 3)
*/

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

class dual_pivot_sort{
 int a;
 public :
 void getdata(); //ggetting data from user
 void quick_sort(int * , int , int );//function for quick sort
}s;

int n;
void swap(int* a, int* b)  //swapping with address
{ 
    int temp = *a;  *a = *b;   *b = temp; 
} 


int partition(int* arr, int  begin, int end, int* left_part)  //making partition
  {  
       int rand_index1 , rand_index2;
    rand_index1 = begin + rand()%(end - begin + 1);
    rand_index2 = begin + rand()%(end - begin + 1);
    if(rand_index1 == rand_index2 ){
        if(rand_index1 != end){
            rand_index2 = rand_index1 + 1;
        }else{
            rand_index2 = rand_index1 - 1;
        }
    }
    if(arr[rand_index1] > arr[rand_index2]){
        swap(&arr[rand_index1] , &arr[rand_index2]);
    }
   cout<<"swaping elements left pivot and placing at begin :"<<arr[rand_index1]<<" , "<<arr[begin]<<endl;
   swap(&arr[rand_index1] , &arr[begin]);
   cout<<"swaping elements right pivot and placing at end  :"<<arr[rand_index2]<<" , "<<arr[end]<<endl;
    swap(&arr[rand_index2] , &arr[end]);
    cout<<"first pivot : "<<arr[begin]<<" second pivot : "<<arr[end]<<endl<<endl;
    if (arr[ begin] > arr[end])  swap(&arr[ begin], &arr[end]); //check first , last elemnt
    int j =  begin + 1; 
    int g = end - 1, k =  begin + 1, left_pivot = arr[ begin], right_pivot = arr[end];  //making left , right pivot

    while (k <= g) {   //initial k =  begin+1 and g = end - 1 as we made begin , end pivots
        if (arr[k] < left_pivot) {
            cout<<"for index = "<<k<<" left pivot : "<<left_pivot<<endl;
            cout<<"swaping elements left part :"<<arr[k]<<" , "<<arr[j]<<endl; swap(&arr[k], &arr[j]); j++; 
            for(int c=0;c<n;c++ ){
        cout<<arr[c]<<" ";
    }cout<<endl<<endl;//swappinf if any element is less than left pivot with begin
        } else if (arr[k] >= right_pivot){   //if for third part
            while (arr[g] > right_pivot && k < g)  g--;
             //make sure of ondition
            cout<<"swaping elements right pivot :"<<arr[k]<<" , "<<arr[g]<<endl;
            swap(&arr[k], &arr[g]);  g--; 
            for(int c=0;c<n;c++ ){
        cout<<arr[c]<<" ";
    }cout<<endl<<endl;

            if (arr[k] < left_pivot) { 
               cout<<"swaping elements"<<arr[k]<<" , "<<arr[j]<<endl; swap(&arr[k], &arr[j]);  j++; 
               for(int c=0;c<n;c++ ){
        cout<<arr[c]<<" ";
    }cout<<endl<<endl;
            } 

        } 
        k++; 
    } 
    j--; 
    g++; 
    cout<<"swaping elements and placing first pivot in its place : "<<arr[begin]<<" , "<<arr[j]<<endl;
    swap(&arr[ begin], &arr[j]); // making that pivots are at appropriate psoitions
    cout<<"swaping elements and placing second pivot in its place : "<<arr[end]<<" , "<<arr[g]<<endl;
    swap(&arr[end], &arr[g]); 

    *left_part= j; //we cannot pass two ele so we pass this with address
    // from a function. 
    cout<<"end of partition : ";
    for(int c=0;c<n;c++ ){
        cout<<arr[c]<<" ";
    }cout<<endl<<endl;
    return g; // returning right part
} 
//10 2 8 4 7 5 1 11 6 3 

void dual_pivot_sort :: quick_sort(int* arr, int begin, int end) 
{ 
   
    if (begin < end) { 
        int right_part,left_part;
        right_part = partition(arr, begin, end, &left_part); 
        quick_sort(arr, begin, left_part - 1);  //first part
        quick_sort(arr, left_part + 1,right_part - 1); //seond part
        quick_sort(arr, right_part + 1, end); //third part
    } 
} 

  

void dual_pivot_sort::getdata(){ //taking details
    
    cout<<"enter the size of an array : "; cin>>n;
    int a[n];
    cout<<"enter the elements of an array : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
   quick_sort(a , 0 , n-1);
    cout<<"final sorted array is : ";
    for(auto c : a){
        cout<<c<<" ";
    }
}

void solve(){
 s.getdata();
}

int main(){
    solve();
    return(0);
}

