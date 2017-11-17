//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

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
        ListNode *head = new ListNode(0);
        ListNode *curr = new ListNode(0);
        curr = head;
        int carry = 0;
        while((l1 != NULL) || (l2 != NULL)){
            int x = (l1 != NULL) ? l1 -> val : 0;
            int y = (l2 != NULL) ? l2 -> val : 0;
            int sum = carry + x + y;
            carry = sum / 10; 
            curr -> next = new ListNode(0);
            curr = curr -> next;
            curr -> val = sum % 10;
            if (l1 != NULL) l1 = l1 -> next;
            if (l2 != NULL) l2 = l2 -> next;   
        }
        if (carry > 0) {
            curr -> next = new ListNode(0);
            curr = curr -> next;
            curr -> val = carry;
        }  
        return head -> next;
    }
};
