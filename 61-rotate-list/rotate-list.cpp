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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k) return head;

        int len = get_length(head);
        k %= len;
        if(k == 0) return head;

        ListNode* new_end = head;

        for(int i = 0; i < len-k-1; i++) {
            new_end = new_end->next;
        }
        ListNode* new_start = new_end->next;
        new_end->next = nullptr;
        ListNode* temp = new_start;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = head;
        return new_start;
    }
private:
    int get_length(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};