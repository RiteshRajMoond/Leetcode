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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 1 && !head->next) return nullptr;

        ListNode* temp = head;
        int tot = 0;
        while(temp) {
            tot++;
            temp = temp->next;
        }

        if(n == tot) {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int x = tot - n;
        temp = head;
        for(int i = 1; i < x; i++) temp = temp->next;

        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head;
    }
};