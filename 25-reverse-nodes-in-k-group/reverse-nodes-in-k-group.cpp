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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head || !head->next) return head;

        ListNode* x = new ListNode(-1, head);
        ListNode* prev_end = x;

        while(true) {
            ListNode* start = prev_end->next;
            ListNode* end = start;
            for(int i = 0; i < k; i++) {
                if(!end) return x->next;
                end = end->next;
            }

            ListNode* next_start = end;
            auto [starts, ends] = reverse(start, end);

            ends->next = next_start;
            prev_end->next = starts;
            prev_end = ends;
        }

        return x->next;
    }
private:
    pair<ListNode*, ListNode*> reverse(ListNode* start, ListNode* end) {
        ListNode* new_end = start;
        ListNode* prev = nullptr, *next = nullptr, *cur = start;
        
        while(cur != end) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return {prev, new_end};
    }
};