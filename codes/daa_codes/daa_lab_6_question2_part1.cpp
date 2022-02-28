#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

class greedy_matrix{
vi a;
public :
void getdata();
int matrix_chain_multiplication(vi , int , int);
}s;
// 
// a b c d
// a(b c d)
// a(b(c d))

// a = 3*2
//b = 2*3
// c = 3*4
// 18 + 3*3*4 = 54
// 24 + 3*2*4 = 48



int greedy_matrix::matrix_chain_multiplication(vi a , int start , int end){
    cout<<" start = "<<start<<"  end = "<<end<<endl<<endl;
    int i , no_of_multiplications;
    for(i=start ; i<end ; i++){
        cout<<" matrix : "<<a[i-1]<<" x "<<a[i]<<endl;
    }
    cout<<endl<<endl;
   
    if(start == end){
        cout<<" start = "<<start<<"  end = "<<end<<" returning =  0"<<endl<<endl;
        return(0);
    }
     
    int min = INT_MAX;

    for(i=start ; i<end ; i++){
        no_of_multiplications = matrix_chain_multiplication(a , start , i) + matrix_chain_multiplication(a , i + 1, end) + a[start-1]*a[i]*a[end];
        cout<<" start * i * end  =  "<<a[start]<<" * "<<a[i]<<" * "<<a[end]<<"  =  "<<a[start-1]*a[i]*a[end]<<endl<<endl;
        cout<<"count = "<<no_of_multiplications<<" min = "<<min<<endl<<endl;
        if(no_of_multiplications < min){
            min = no_of_multiplications;
        }
    }
    cout<<endl<<endl;
      for(i=start ; i<end ; i++){
        cout<<" matrix : "<<a[i-1]<<" x "<<a[i]<<endl;
    }
    cout<<" start = "<<start<<"  end = "<<end<<" returning =  "<<min<<endl<<endl;
    return(min);
}





void greedy_matrix::getdata(){
    int n,i;
    cout<<"enter how many matrix are going to multiply : "; cin>>n;
    vi a(n);
    cout<<"enter no of rows of each matrix in order you are going to multiply :  ";
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<s.matrix_chain_multiplication(a , 1 , n-1);
}

void solve(){
    s.getdata();
}

int main(){
    solve();
    return(0);
}