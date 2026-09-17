class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> diff(n,vector<int>(m,INT_MAX));
        diff[0][0]=0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        int delR[]={-1,0,+1,0};
        int delC[]={0,-1,0,+1};
        while(!pq.empty()){
            pair<int,pair<int,int>> temp=pq.top();
            pq.pop();
            int steps=temp.first;
            int row=temp.second.first;
            int col=temp.second.second;
            for(int i=0;i<4;i++){
                int newr=row+delR[i];
                int newc=col+delC[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int mini=abs(heights[row][col]-heights[newr][newc]);
                    int effort=max(mini, steps);
                    if(effort<diff[newr][newc]){
                        diff[newr][newc]=effort;
                        pq.push({effort, {newr,newc}});
                    }
                }
            }
        }
        return diff[n-1][m-1];
    }
};