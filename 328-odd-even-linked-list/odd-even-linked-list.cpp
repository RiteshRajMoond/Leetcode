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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* odd = head, *even = head->next, *evenHead = head->next;

        bool flag = true;
        while(even && even->next) {
            if(flag) {
                flag = !flag;
                odd->next = odd->next->next;
                odd = odd->next;
            } else {
                flag = !flag;
                even->next = even->next->next;
                even = even->next;
            }
        }

        odd->next = evenHead;
        return head;
    }
};