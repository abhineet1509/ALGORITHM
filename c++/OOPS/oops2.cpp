#include<iostream>
using namespace std;
class student{
    string name;
      public:
    int age;
    bool gender;
    string grade;
   //to make string name accessible
   void setName(string a){
    name= a;
   }
    void printinfo(){
        cout<<grade<<endl;
    }
};
int main(){
   student s[3];
   // for intput of three student
   for(int i=0;i<3;i++){
    cout<<"age";
      cin>>s[i].age;   //error because age is inaccessible it is private
     cout<<"grade";
      cin>>s[i].grade;}
     //for output of three student
     for(int i=0;i<3;i++){
                s[i].printinfo();
     }

}