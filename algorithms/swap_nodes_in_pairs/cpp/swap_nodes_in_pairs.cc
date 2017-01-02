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
    ListNode* cur;
    ListNode* next;
    ListNode flag{0};
    flag.next = head;
    ListNode* newCur{head};
    ListNode* oldNext{&flag};

    while (newCur && newCur->next) {
      cur = newCur;
      next = cur->next;
      newCur = next->next;
      next->next = cur;
      cur->next = newCur;
      oldNext->next = next;
      oldNext = cur;
    }
    return flag.next;
  }
};
