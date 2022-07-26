class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode* p = &dummy;
    int carry = 0, sum;
    while(l1 || l2) {
      sum = carry;
      if(l1) sum += l1->val;
      if(l2) sum += l2->val;
      if(sum >= 10) {
        carry = sum / 10;
        sum %= 10;
      } else carry = 0;
      p->next = new ListNode(sum);
      p = p->next;
      if(l1) l1 = l1->next;
      if(l2) l2 = l2->next;
    }
    if(carry)
      p->next = new ListNode(carry);
    return dummy.next;
  }
};