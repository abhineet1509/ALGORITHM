#include<iostream>
using namespace std;
               //**constructor overloading **//
class customer{
    public:
    string name;
    int roll;
 // customer(string name,int a){
 //   this->name=name;                  //can be solved by this->
 //   roll=a;
//}  //customer( string s,int a,int b){
   // name=s;
   // roll=a;
//}
//inline construtor
inline customer(string a,int b): name(a),roll(b){

}
void display(){
    cout<<name<<roll;
}
};
int main(){
    customer a("avaneet",56);
    a.display();
}