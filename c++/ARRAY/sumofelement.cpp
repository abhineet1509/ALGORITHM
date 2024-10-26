#include<iostream>
using namespace std;
int main (){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int count=0;
    for(int i=0;i<10;i++){
        count=count+arr[i];
    }
    cout<<count;
    return 0;
}