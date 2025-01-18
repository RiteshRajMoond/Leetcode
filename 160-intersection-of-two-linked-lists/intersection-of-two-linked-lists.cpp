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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> mp;
        ListNode* temp = headA;
        while(temp) {
            mp[temp]++;
            temp = temp->next;
        }

        temp = headB;
        while(temp) {
            mp[temp]++;
            temp = temp->next;
        }

        for(auto& [node, freq]: mp) {
            if(freq == 2) return node;
        }

        return nullptr;
    }
};