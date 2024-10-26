   //limitations in array                            //properties of linked list
   //fixed size                                        size can be modified
   //contigious block of memory                        non contigious
   //insertion and deletion is not easy                   insertion and deletion is easy
#include<iostream>
using namespace std;
class NODE{
    public:
    int data;
    NODE *next;
    void display(){                //with the help of constructor
        cout<<next<<" "<<data;      //NODE(int value){
                                    //  data=value;
                                    //  next=NULL;}      (4)
    }
};
int main(){            //we have to create node in dynamic way
        NODE *head;
        head=new NODE();                                                              // NODE a;
        head->data=8;
        head->next=NULL;                                                              // a.data=4;
           cout<<head->data<<endl;
           cout<<head->next;                                                        // a.data=6;
                                                                                    // a.display();
}