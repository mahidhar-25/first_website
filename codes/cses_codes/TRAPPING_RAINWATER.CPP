#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define all(x) x.begin(),x.end()

class water{
    private:
    int n;
    vi steps,a;
    public:
    void getdata();
    void find_storage(vi steps, int n);
}s;

bool check(int x,int y, vi a,int size){
    int O_y = y;
for(i=0;i<size;i = i+2){
    if(x>=a[i] && x<=a[i+1]){
        if(y>=a[i+1]){y = a[i+1]- y}
        else if(y<=a[i]){y = y - a[i]}
    }
}
int area;
for(k=a[O_y];k<=a[x];k++){
        area = area - steps[k];
    }
return y*a[O_y];
}

int water::find_area(int x, int y , vi steps, int n){
    static int size =0;
    for(i=0;i<n;i++){
        if(steps[i]==x || steps[i]==y ){
            a.push_back(i);
            size++;
        }
    }
    int area;
    if(size>2){
   area = (check(a[size-1],a[size-2], a,size))
    }else{
    area = y*(a[1]-a[0]);
    for(k=a[0];k<=a[1];k++){
        area = area - steps[k];
    }
    }
    
    return area;


}


void water::find_storage(vi steps, int n){
    int new_steps[n];
    copy(steps.begin(), steps.end(), new_steps.begin());
    sort(all(new_steps));
    for(i=n-1;i>=0;i--){
    sum = sum + find_area(new_steps[n-1],new_steps[n-2] ,steps,n);
    }
}


void water::getdata(){
    int n,x,count_inc=1,count_dec=1; cin>>n;
    for(i=0;i<n;i++){ cin>>x; steps.push_back(x); }

    for(i=0;i<n-1;i++){
        if(a[i]<a[i+1]){count_inc++;}
        if(a[i]>a[i+1]){count_dec++;}
        if(a[i]==a[i+1]){count_equal++}
    }
    if(count_inc==n || count_dec==n){cout<<"no water can be stored"<<endl; exit(0);}
    s.find_storage(steps,n);
}


void solve(){
    s.getdata();
}

int main() {
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    time(&end);
     double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return(0);
}