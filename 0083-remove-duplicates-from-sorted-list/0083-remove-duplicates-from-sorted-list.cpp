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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL && temp->val==temp->next->val){
                ListNode* curr=temp;
                while(curr!=NULL && curr->val==temp->val){
                    curr=curr->next;
                }
                temp->next=curr;
            }
            if(temp!=NULL){
                temp=temp->next;
            }
        }
        return head;
    }
};