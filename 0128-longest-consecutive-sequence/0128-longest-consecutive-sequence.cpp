class Solution {
public:
    int longestConsecutive(vector<int>& nums) {// TC : O(N) Average & SC : O(N)

        //N = nums.size()

        unordered_set<int> st(nums.begin(),nums.end());// TC : O(N) & SC : O(N)
        int longest = 0;

        for(int num : st){// TC : O(N)

            if(st.find(num-1) == st.end()){

                int current = num;
                int count = 1;

                while(st.find(current+1) != st.end()){// TC : O(N)

                    current++;
                    count++;
                }

                longest = max(longest,count);
            }
        }

        return longest;
    }
};