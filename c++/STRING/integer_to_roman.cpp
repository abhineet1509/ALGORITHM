#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
// int n;                             //{1000,M},{500,D},{100,C},{50,L},{10,C},{5,V},{1,I}
// cout<<"enter the number:";
// cin>>n;
// string res="";
// while(n!=0){
//     if(n>=1000){
//         res+="M";
//         n-=1000;
//     }
//      else if(n>=500){
//         res+="D";
//         n-=500;
//     }
//    else if(n>=100){
//         res+="C";
//         n-=100;
//     }
//    else if(n>=50){
//         res+="L";
//         n-=50;
//     }
//   else  if(n>=10){
//         res+="X";
//         n-=10;
//     }
//    else if(n>=5){
//         res+="V";
//         n-=5;
//     }
//    else if(n>=1){                   //vector<string> notation; {M,D,C,L,X,I}
//         res+="I";                   //vector<int> value;
//         n-=1;                       //
//     }
// }
// cout<<res;
int n;
cout<<"Enter the number:";
cin>>n;
string res="";
vector<pair<int,string>> ans={{1000,"M"},{500,"D"},{100,"C"},{50,"L"},{10,"X"},{5,"V"},{1,"I"}};
for(int i=0;n>0;i++){
    while(n>=ans[i].first){
        res+=ans[i].second;
        n-=ans[i].first;
    }
}
cout<<res;
}