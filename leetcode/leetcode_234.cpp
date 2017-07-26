/**
 * time : O(n)
 * space : O(1)
 */
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
    bool isPalindrome(ListNode* head) {
        if(!head || !(head->next))	return true;
        
		int len = 0;
        ListNode* p = head;
        while(p){
        	len ++;
        	p = p -> next; 
		}
		
		//reverse the front part of linked list
		ListNode* q = NULL;
		for(int i = 0; i < len/2; i++){
			ListNode* cur = head;
			head = head->next;
			cur->next = q;
			q = cur;
		} 
        
		if(len%2)	head = head->next;
		
		while(head && q){
			if(head->val != q->val)
				return false;
			head = head->next;
			q = q->next;
		}
		return true;
    }
};
