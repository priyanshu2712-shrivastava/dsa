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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(INT_MIN);

        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;

            // Find position where curr should be inserted
            ListNode* prev = dummy;

            while (prev->next != nullptr &&
                   prev->next->val <= curr->val) {
                prev = prev->next;
            }

            // Insert curr
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};