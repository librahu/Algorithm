/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * not modify the input list
 * time : O(n)
 * space : O(n)
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int len1 = 0;
        int len2 = 0;
        while(head1){
        	head1 = head1->next;
        	len1 ++;
		}
		while(head2){
			head2 = head2->next;
			len2 ++;
		}
		int add = 0;
		while(len1>0 && len2>0){
			if(len1 == len2){
				add = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
				len1 --;
				len2 --;
			}
			else if(len1 > len2){
				add = l1->val;
                l1 = l1->next;
				len1 --;
			}
			else{
				add = l2->val;
                l2 = l2->next;
				len2 --;
			}

			res = addFront(add, res);
		}
		return reverse(res);
    }
    //insert node in the front
    ListNode* addFront(int add, ListNode* res){
    	ListNode* cur = new ListNode(add);
    	cur->next = res;
    	return cur;
	}
	//reverse list and  complete carry

	ListNode* reverse(ListNode* head){
		int carry = 0;
		ListNode* res = NULL;
		while(head){
			ListNode* cur = head;
			head = head->next;

			int sum = cur->val + carry;
			cur->val = sum % 10;
			carry = sum / 10;

			cur->next = res;
            res = cur;
		}
		if(carry){
			head = new ListNode(1);
			head->next = res;
			res = head;
		}
		return res;
	}
};
