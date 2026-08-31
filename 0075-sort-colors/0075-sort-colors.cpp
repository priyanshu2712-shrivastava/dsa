class Solution {
public:
    void sortColors(vector<int>& nums) {
       int zero=0;
       int one=0;
       int two=0;
       for(int num:nums){
        if(num==0) zero++;
        else if(num==1) one++;
        else two++;
       } 
       int pointer=0;
       while(zero!=0){
        nums[pointer]=0;
        pointer++;
        zero--;
       }
       while(one!=0){
        nums[pointer]=1;
        pointer++;
        one--;
       }
       while(two!=0){
        nums[pointer]=2;
        pointer++;
        two--;
       }
       return;
    }
};