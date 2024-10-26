//Oops are programmed data structure that are used to store data in form of object instead of function and logic.
//Why we use oops?
//it  is difficult for user to take data many times for objects from data members
//eg:int main(){
//    int class;
//    int roll_no;
//    string grade;
//string name;
//
//    int class1;
//    int roll_no1;
//    string grade1;
//string name1;}
// calling function for all these objects are more difficult that why we create oops to store data members at one place only
#include <iostream>
using namespace std;
class Student{
    public:              //by default all the data members of a class are private thats why we declare public.
                         //public: assessible
                         //private: can be assessible by function
    string name;
    int age;
    int account_number;
    bool gender;                     
};   
int main(){
 Student s1;
 s1.name=("avaneet");         //cin>>s1.name;
 s1.age=21;
 cout<<s1.age<<endl;
 cout<<s1.name;
}