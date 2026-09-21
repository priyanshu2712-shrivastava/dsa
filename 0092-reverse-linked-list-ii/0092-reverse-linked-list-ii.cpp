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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode* leftNode = head;
        ListNode* pl = NULL;

        int pos = 1;

        while (pos < left) {
            pl = leftNode;
            leftNode = leftNode->next;
            pos++;
        }

        int step = right - left;

        ListNode* curr = leftNode->next;
        ListNode* prev = leftNode;
        ListNode* temp = NULL;

        while (step > 0) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            step--;
        }

        if (pl != NULL)
            pl->next = prev;
        else
            head = prev;

        leftNode->next = curr;

        return head;
    }
};