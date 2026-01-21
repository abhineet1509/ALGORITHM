#include<bits/stdc++.h>
using namespace std;
 // Boyer's Moore(n/3) solution
vector<int> majorityElement(vector<int>& nums) {
    int c1 = 0, c2 = 0;
    int e1 = 0, e2 = 1;

    for (int x : nums) {
        if (x == e1) c1++;
        else if (x == e2) c2++;
        else if (c1 == 0) {
            e1 = x;
            c1 = 1;
        } else if (c2 == 0) {
            e2 = x;
            c2 = 1;
        } else {
            c1--;
            c2--;
        }
    }

    c1 = c2 = 0;
    for (int x : nums) {
        if (x == e1) c1++;
        else if (x == e2) c2++;
    }

    vector<int> ans;
    int n = nums.size();
    if (c1 > n / 3) ans.push_back(e1);
    if (c2 > n / 3) ans.push_back(e2);

    return ans;
}

int main (){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxcount=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if (arr[i]==arr[j])
            count++;
        }
    
    if(count>maxcount){
        maxcount=count;
        index=i;

    }
    
    }if(maxcount>n/2){
        cout<<arr[index]<<endl;
    }
    else{ cout<<"no element found";
    }
}