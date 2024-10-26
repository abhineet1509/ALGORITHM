
                        //***constructor***//
//constructor are those function which get called automatically whenever an object is made.
// name of constructor should be same as class name
//it does not have rerturn type
//it is used to initialize the value
#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    int roll_number;
    //string grade;
    //int section;
     Student(string s,int a){           //only student not class student
        name=s;
        roll_number=a;
    }
    void getname(){               //get name function use to print the output
        cout<<name<<endl;
        cout<<roll_number;
    }
};
int main(){
  Student a1("avaneet",56);
  a1.getname();
}