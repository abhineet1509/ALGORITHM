#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    string name;
    int roll_number;
    string grade;
    int section;
    student()
    {  
        name="avaneet";             //this is a default constructor with parameter
        roll_number=56;             
        grade="a";
        cout<<"this is a default constructor";
    }
    void display(){
        cout<<name<<roll_number<<grade;        //output:this is a default constructoravaneet56a
    }
};
int main(){
 student a;
 a.display();       //number of times an object will form number of times the output will increase
}                 //student a,b;
                 //b.display();
                 //a.display();     output:this is a default constructoravaneet56a
                 //                        this is a default constructoravaneet56a
