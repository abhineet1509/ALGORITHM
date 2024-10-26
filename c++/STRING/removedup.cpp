#include<iostream>
using namespace std;
string removedup( string s){
    if(s.length()==0){
        return" ";
    }
    char ch=s[0];
   string ros=removedup(s.substr(1));
   if(ch==ros[0]){
    return ros;
   }
   return ch+ros;
    
}
int main(){
    string str;
    getline(cin,str);
    
    cout<<removedup(str);
    return 0;
}