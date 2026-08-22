class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int green=*max_element(lights.begin(),lights.end());
        int n=arrivalTime.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int r=arrivalTime[i]%period;
            if(r<green) continue;
            else{
                int waitingPeriod=period-r;
                maxi=max(maxi,waitingPeriod);
            }
        }
        return maxi;
    }
};