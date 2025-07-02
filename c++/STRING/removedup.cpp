#include<iostream>
using namespace std;


string removeDuplicates(string s) {
    if (s.length() <= 1) return s;

    if (s[0] == s[1])
        return removeDuplicates(s.substr(1));  // skip duplicate
    else
        return s[0] + removeDuplicates(s.substr(1));
}
int main(){
    string str;
    getline(cin,str);
    
    cout<<removeDuplicates(str);
    return 0;
}