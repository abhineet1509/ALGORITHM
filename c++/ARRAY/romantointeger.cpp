#include<bits/stdc++.h>
using namespace std;
  int num(char c){
    
    
    if(c=='I') return 1;
    else if(c=='V') return 5;
    else if(c=='X') return 10;
    else if(c=='L') return 50; 
    else if(c=='C') return 100;
    else if(c=='D') return 500;
    else if(c=='M') return 1000;
    

}
int rtoi( string s){
    int sum=0,i=0;
    while( i<s.size()-1){
        if(num(s[i])<num(s[i+1])) {
            sum-=num(s[i]);
        }
        else {
            sum+=num(s[i]);
        }
        i++;
    }  
    sum+=num(s[i]);
     return sum;
}
int main(){
    string s;
    cin>>s;
    int n=s.size();
   int m=rtoi(s);
  cout<<m;
}