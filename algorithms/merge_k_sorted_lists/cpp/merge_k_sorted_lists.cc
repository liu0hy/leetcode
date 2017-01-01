// https://leetcode.com/problems/merge-k-sorted-lists/
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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto comp = [](ListNode* lhs, ListNode* rhs) {
      return lhs->val > rhs->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> buffer{comp};
    for (ListNode* node : lists) {
      if (node) buffer.push(node);
    }
    ListNode head{0};
    ListNode* cur{&head};
    while (!buffer.empty()) {
      cur->next = buffer.top();
      cur = cur->next;
      buffer.pop();
      if (cur->next) buffer.push(cur->next);
    }
    return head.next;
  }
};
