// https://leetcode.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        ListNode** prev{&head};
        ListNode* cur;
        ListNode* next;
        while ((cur=*prev) && (next=cur->next)) {
            cur->next = next->next;
            next->next = cur;
            *prev = next;
            prev = &(cur->next);
        }
        return head;
    }
};
