//finding maximum , second maximum , minimum ,second minimum from an array
#include<iostream>
#include<iomanip>
#include<vector>
#include<limits.h>
using namespace std;

//first method

/*

//class includes member functions in public and memeber variables as private
class max_min{
    private:
    int n,max,min;
    vector<int> a;
    public:
    void getdata();
    int find_max(int &n , vector<int> &a );
    int find_min(int &n , vector<int> &a );
};
  max_min s; //object for class to use in code

int max_min::find_max(int &n , vector<int> &a ){   //finding max element and deleting the max element and decreasing the size of an array
    int max = INT_MIN,i,index;
    for(i=0;i<n;i++){
        if(a[i]>max){
            max = a[i]; index = i;
        }
    }
    
    for(int j = index;j<n-1 ;j++){  // after deleting adjusting index elements in array by shifting
        a[j] = a[j+1];
    }
    --n;
    return max;
}


int max_min::find_min(int &n , vector<int> &a ){    // finding min element and decreasing the size by deleting the min element
    int min=INT_MAX,i,index;
    for(i = 0;i<n;i++){
        if(a[i]<min){
            min = a[i];  index = i;
        }
    }
     for(int j = index;j<n-1 ;j++){     // after deleting adjusting index elements in array by shifting
        a[j] = a[j+1];
    }
     --n;
   return min;
}


void max_min::getdata(){
    int x,n,i,j,k; 
    cout<<"enter the size of array : "; cin>>n;
    cout<<"enter the values : ";
   for(i=0;i<n;i++){
       cin>>x; a.push_back(x);     //takes the input values of an array
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;){
            if(a[i]==a[j]){          // check the array if any duplicates it deletes the elements and decrease size of an array
                for(k=j;k<n;k++){
                    a[k] = a[k+1];
                }
                j--;
                --n;
            }
            j++; } }

    if(n==1){
        cout<< " MAX = MIN =" <<a[0]<<endl<<"SMAX , SMIN doesnt exist"<<endl;
        exit(0);
    }else if(n==2){
        if(a[0]>a[1]){
            cout<<"MAX = SMIN ="<<a[0]<<endl<<"MIN = SMAX ="<<a[1]<<endl;
            exit(0);
        }else{
            cout<<"MAX = SMIN ="<<a[1]<<endl<<"MIN = SMAX ="<<a[0]<<endl;
            exit(0);
        }
    }
     for(i=0;i<2;i++){
        if(i%2==0){
            cout<<"MAX = "<<s.find_max(n,a)<<endl;   //finding maximum element
            static int smax = s.find_max(n,a);
            cout<<"SMAX = "<<smax<<endl;             //finding the second max element
            if(n==1)
            cout<<"SMIN = "<<smax<<endl;           //after SMAX if size == 1 then printing second minimum
        }else{
            cout<<"MIN = "<<s.find_min(n,a)<<endl;   // finding min element
            if(n>0)
            cout<<"SMIN = "<<s.find_min(n,a)<<endl;  //finding second min element
        }
    }
}



void solve(){
    s.getdata();  // getting data from user
}

int main() {
        solve();
}

*/
//2nd method


//class for finding max min uses member functions and variables
class max_min{
    int n;
    vector<int> a;
    public:
    void getdata();
    void find_2_smallest(vector<int> a, int n, int o_size);
    void find_2_largest(vector<int> a, int n, int o_size);
};

max_min s;  //object for class to use to find max min

void max_min::find_2_smallest(vector<int> a, int n, int o_size){   
    int min ,smin,i;
    min = smin = INT_MAX;
    for(i=0;i<n;i++){                   //finding min ele and storing in smin if an element exist lesser  than min until end of an array
        if(a[i]<min){
            smin = min;
            min = a[i];
        }else if(a[i]<smin && a[i]!=min){
            smin = a[i];
        }
    }
    if(smin == INT_MAX){
        cout<<"min = "<<min<<endl;
        cout<<"there is no second min element"<<endl;
    }else{
        cout<<"min = "<<min<<endl;            //printing the min and second min if exist
        cout<<"smin = "<<smin<<endl;
    }
}

void max_min::find_2_largest(vector<int> a, int n, int o_size){
    int max, smax,i;
    max = smax = INT_MIN;
   for(i=0;i<n;i++){
       if(a[i]>max){                   //finding max ele and storing in smax if an element exist greater  than max until end of an array
           smax = max;
           max = a[i];
       }else if(a[i]>smax && a[i]!=max){
           smax = a[i];
       }
   }

   if(smax == INT_MIN){
       cout<<"max = "<<max<<endl;
       cout<<"ther is no second max"<<endl;
   }else{
        cout<<"max = "<<max<<endl;
        cout<<"smax = "<<smax<<endl;        //printing the max and second max if exist
   }
}


void max_min::getdata(){
    int x,n,i,j,k; 
    cout<<"enter the size of an array : " ; cin>>n;
    int o_size = n;
    cout<<"enter the values of an array : "<<endl;       //taking the input values from user
   for(i=0;i<n;i++){
       cin>>x; a.push_back(x);
    }
        for(i=0;i<n;i++){
        for(j=i+1;j<n;){                       // check the array if any duplicates it deletes the elements and decrease size of an array
            if(a[i]==a[j]){
                for(k=j;k<n;k++){
                    a[k] = a[k+1];
                } j--; --n;
            }
            j++; } }
    s.find_2_smallest(a , n , o_size);
    s.find_2_largest(a , n ,o_size);
}


void solve(){
    s.getdata();   //gettin data from user
}

int main() {
        solve();
    return(0);
}





//3rd method

/*
//class includes member functions in public and memeber variables as private
class max_min{
int n;
vector<int> a;
public:
void getdata();
void find_2_max(vector<int> a, int n);
void find_2_min(vector<int> a, int n);
};

max_min s;     //object for class to use in code

void max_min::find_2_max(vector<int> a, int n){
    int max1,max2,smax1,smax2,i;
    max1 = max2 = smax1 = smax2 =INT_MIN;
    for(i=0;i<n/2;i++){
        if(a[i]>max1){
          smax1 = max1; max1 = a[i];              //finding maximun for half of the array
        }else if(a[i]<max1 && a[i]>smax1){
            smax1 = a[i];
        }
    }
    for(i=n/2;i<n;i++){
        if(a[i]>max2){                        //finding max in second half of the array and comparing with first half
            smax2 = max2; max2 = a[i];
        }else if(a[i]<max2 && a[i]>smax2){
            smax2 = a[i];
        }
    }
    if(max1>max2 && smax1 > max2){
        cout<<"MAX = "<<max1<<endl<<"SMAX = "<<smax1<<endl;
    }else if(max1>max2 && smax1 < max2){
        cout<<"MAX = "<<max1<<endl<<"SMAX = "<<max2<<endl;
    }else if(max2>max1 && smax2 > max1){
        cout<<"MAX = "<<max2<<endl<<"SMAX = "<<smax2<<endl;
    }else{
        cout<<"MAX = "<<max2<<endl<<"SMAX = "<<max1<<endl;
    }
}

void max_min::find_2_min(vector<int> a, int n){
     int min1,min2,smin1,smin2,i;
    min1 = min2 = smin1 = smin2 =INT_MAX;
    for(i=0;i<n/2;i++){
        if(a[i]<min1){
          smin1 = min1; min1 = a[i];                   //finding minimun for half of the array
        }else if(a[i]>min1 && a[i]<smin1){
            smin1 = a[i];
        }
    }
    for(i=n/2;i<n;i++){
        if(a[i]<min2){
            smin2 = min2; min2 = a[i];               //finding min in second half of the array and comparing with first half
        }else if(a[i]>min2 && a[i]<smin2){
            smin2 = a[i];
        }
    }
    if(min1<min2 && smin1 < min2){
        cout<<"MIN = "<<min1<<endl<<"SMIN = "<<smin1<<endl;
    }else if(min1<min2 && smin1 > min2){
        cout<<"MIN = "<<min1<<endl<<"SMIN = "<<min2<<endl;
    }else if(min2<min1 && smin2 < min1){
        cout<<"MIN = "<<min2<<endl<<"SMIN = "<<smin2<<endl;
    }else{
        cout<<"MIN = "<<min2<<endl<<"SMin = "<<min1<<endl;
    }
}


void max_min::getdata(){
    int x,n,i,j,k;
    cout<<"enter size of an array : " ; cin>>n;
    cout<<"enter values of an array : "<<endl;
   for(i=0;i<n;i++){
       cin>>x; a.push_back(x);               //take the inputs from the user
    }
     for(i=0;i<n;i++){
        for(j=i+1;j<n;){
            if(a[i]==a[j]){                          // check the array if any duplicates it deletes the elements and decrease size of an array
                for(k=j;k<n-1;k++){
                    a[k] = a[k+1];
                } j--; --n;
            }
            j++; } }
            

    if(n==1){
        cout<< " MAX = MIN =" <<a[0]<<endl<<"smax , smin doesnt exist"<<endl;
        exit(0);
    }else if(n==2){
        if(a[0]>a[1]){
            cout<<"MAX = SMIN ="<<a[0]<<endl<<"MIN = SMAX ="<<a[1]<<endl;
            exit(0);
        }else{
            cout<<"MAX = SMIN ="<<a[1]<<endl<<"MIN = SMAX ="<<a[0]<<endl;
            exit(0);
        }
    }
  s.find_2_max(a , n);
  s.find_2_min(a , n);
}

void solve(){
    s.getdata(); 
}

int main() {
        solve();
    return(0);
}

*/

