// https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode{0};
        if (!l1 && !l2) return head;
        int sum = 0;
        int carry = 0;
        int lval = 0;
        int rval = 0;
        ListNode* temp = head;
        while (l1 || l2 || carry) {
            lval = l1 ? l1->val : 0;
            rval = l2 ? l2->val : 0;
            sum = lval+rval+carry;
            head->next = new ListNode{sum%10};
            carry = sum/10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            head = head->next;
        }
        head = temp->next;
        delete temp;
        return head;
    }
};
