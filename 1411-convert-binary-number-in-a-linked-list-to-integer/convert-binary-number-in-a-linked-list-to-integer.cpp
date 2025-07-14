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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL, *cur = head, *next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        return head;
    }
public:
    int getDecimalValue(ListNode* head) {
        head = reverseLL(head);
        int multiply_factor = 1;
        int decimal_num = 0;

        while(head) {
            decimal_num += (head->val * multiply_factor);
            head = head->next;
            multiply_factor *= 2;
        }

        return decimal_num;
    }
};