#include<iostream>
using namespace std;
int inc(int n){
    if(n==0) return 1;
    inc(n-1);
    cout<<n<<endl;
    
}
int dec( int n){
    if(n==0){ return 1;}
    cout<<n<<endl;
    dec(n-1);
}

int main(){
    int n;
    cin>>n;
    dec(n);
    inc(n);
  
     return 0;
}