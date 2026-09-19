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
        if (head == NULL) return NULL;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {

            // Duplicate found
            if (temp->next != NULL && temp->val == temp->next->val) {

                int value = temp->val;

                // Skip all nodes having this value
                while (temp != NULL && temp->val == value) {
                    temp = temp->next;
                }

                // Duplicate was at the beginning
                if (prev == NULL) {
                    head = temp;
                }
                else {
                    prev->next = temp;
                }
            }
            else {
                // Current node is unique
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};