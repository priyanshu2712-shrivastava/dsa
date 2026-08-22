class Solution {
public:
    bool checkDivisibility(int n) {
        int number=n;
        int sum=0;
        int product=1;
        while(n>0){
            int temp=n%10;
            sum+=temp;
            product*=temp;
            n/=10;
        }
        return number%(sum+product)==0;
    }
};