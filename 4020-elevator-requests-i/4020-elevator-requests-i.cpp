class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int current=0;
        int time=0;
        for(int floor:requests){
            if(floor==current) continue;
            else{
                int temp=abs(floor-current) ;
                time+=temp;
                current=floor;
            }
        }
        return time;
    }
};