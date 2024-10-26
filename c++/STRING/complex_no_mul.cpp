#include<iostream>
#include<string>
using namespace std;
int main(){
    string num1,num2;
    cin>>num1>>num2;
    int p1,p2;
    for(int i=0;i<num1.length();i++){
        if(num1[i]=='+'){
            p1=i;
            break;
    }
    }
    for(int i=0;i<num2.length();i++){
          if(num2[i]=='+'){
            p2=i;
            break;
          }
    }
    int a=stoi(num1.substr(0,p1));
    int b=stoi(num1.substr(p1+1));
    int c=stoi(num1.substr(0,p2));
    int d=stoi(num1.substr(p2+1));
    int real=(a*c)+(b*d);
    int img=(a*d)+(b*c);
    string res = to_string(real) + "+" + to_string(img) + "i";
    cout<<res<<endl;
}