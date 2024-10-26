#include<algorithm>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
           for(int j=0;j<nums.size();j++){
               if(nums[i]==nums[j]){
                nums[j]=nums[j+1];
               }
           }
        }
     return nums.size();
        }
};
