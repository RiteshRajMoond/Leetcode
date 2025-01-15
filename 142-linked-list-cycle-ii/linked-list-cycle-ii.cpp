/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool cycle = false;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) cycle = true;
            if(cycle) break;
        }

        if(!cycle) return NULL;

        fast = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};