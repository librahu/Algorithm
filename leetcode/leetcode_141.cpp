/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /**
  * fast and slow point
  * time : O(n)
  * space : O(1)
  */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && slow && fast->next){
            slow = slow -> next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};
