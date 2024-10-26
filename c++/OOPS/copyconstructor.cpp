#include<iostream>
using namespace std;
class student{
    public:
    string name;
    int roll_number;
    string grade;
    int section;
    student(){
        name=("avaneet");
        roll_number=56;
    }
    student(student &a){
    cout<<"this is a copy constructor";
    name=a.name;
    roll_number=a.roll_number;
    }
    void display(){
        cout<<name<<roll_number;
    }
};
int main(){
    student a;
student c(a);
a.display();
}