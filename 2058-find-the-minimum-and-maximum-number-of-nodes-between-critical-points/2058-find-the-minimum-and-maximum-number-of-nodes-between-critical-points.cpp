/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> points;
        if(head==NULL) return {-1,-1};
        if(head->next==NULL) return {-1,-1};
        if(head->next->next==NULL) return {-1,-1};
        ListNode* curr=head->next;
        ListNode* prev=head;
        ListNode* forw=head->next->next;
        int pointer=1;
        while(forw!=NULL){
            if(curr->val>prev->val && curr->val>forw->val){
                points.push_back(pointer);
            }
            if(curr->val<prev->val && curr->val<forw->val){
                points.push_back(pointer);
            }
            forw=forw->next;
            curr=curr->next;
            prev=prev->next;
            pointer++;
        }
        int n=points.size();
        if(n<2) return {-1,-1};
        int mini=INT_MAX;
        int maxi=points[n-1]-points[0];
        for(int i=0;i<n-1;i++){
            int temp=points[i+1]-points[i];
            mini=min(mini, temp);
        }
        return {mini, maxi};
    }
};