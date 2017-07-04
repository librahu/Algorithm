/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * iteratively
 * time : O(n)
 * space : O(1)
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* res = NULL;  //result node point
        ListNode* tmp = NULL; //tmporary node point
        while(head){
            tmp = head -> next;
            head->next = res;
            res = head;
            head = tmp;
        }
        return res;
    }
};

/**
 * recursively
 * time : O(n)
 * space : O(n)
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* cur = head->next;
        head->next = NULL;
        ListNode* res = reverseList(cur);
        cur -> next = head;
        return res;

    }
};
