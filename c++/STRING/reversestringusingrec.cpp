#include<iostream>
using namespace std;
void reversestr( string s){
    if(s.length()==0){
        return;
    }
   string ros=s.substr(1);
   reversestr(ros);
   cout<<s[0];

}
int main(){
    string str;
    getline(cin,str);
    reversestr(str);
    return 0;
}