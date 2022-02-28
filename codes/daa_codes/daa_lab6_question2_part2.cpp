#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>


bool compare(pair<int , int> &p1 , pair<int , int> &p2){
    if(p1.second == p2.second) return(p1.first<p2.first);
    return(p1.second > p2.second);
}

int sum(vi freq , int start , int end){
    int sum = 0;
    for(int i = start; i<=end; i++){
        sum = sum + freq[i];
    }
    return(sum);
}

int optimal_cost(vi freq , int begin , int end){
    if(end < begin) return(0);
    if(end == begin) return(freq[begin]);

    int freq_sum = sum(freq , begin , end);

    int min = INT_MAX;

    for(int i=begin;i<=end;i++){
        int cost = optimal_cost(freq ,begin , i-1) + optimal_cost(freq , i + 1 , end);
        if(cost < min) min = cost;
    }
    return(min + freq_sum);
}

int optimal_binary_search_tree(vi val , vi freq , int n){
    return(optimal_cost(freq , 0 , n-1));
}



void sort_array_according_to_frequency(vi a , int n){
    int i ,j;
    
    map<int , int> m;
    for(i=0;i<n;i++){
        m[a[i]]++;
    }
    vi val(m.size());
    vi freq(m.size());
    pair<int , int> p[m.size()];
    i=0;
    for(auto it = m.begin(); it!=m.end(); ++it){
        p[i++] = make_pair(it->first , it->second);
    }

    sort(p , p+m.size() , compare);
  j = 0;
    for(i=0;i<m.size();i++){
        val[i] = p[i].first;
        freq[i] = p[i].second;
    }


  for(i = 0;i<m.size();i++){
      cout<<val[i]<<" , "<<freq[i]<<endl;
  }

  cout<<"\n cost of tree is : "<<optimal_binary_search_tree(val , freq , m.size())<<endl;
}

int main(){
    int n,i; 
    cout<<"enter the size of an array : "; cin>>n;
    vi a(n);
    cout<<"enter the values : ";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort_array_according_to_frequency(a , n);
}