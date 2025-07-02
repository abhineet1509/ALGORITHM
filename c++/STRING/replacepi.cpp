#include <iostream>
using namespace std;

string replacePi(string s) {
    if (s.length() < 2) return s;

    if (s[0] == 'p' && s[1] == 'i')
        return "3.14" + replacePi(s.substr(2));
    else
        return s[0] + replacePi(s.substr(1));
}

int main (){
    string str;
    getline(cin,str);
    replacePi(str);

    return 0;
}