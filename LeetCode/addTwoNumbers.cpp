/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { //l1 = 9999999, l2 = 9999
        int carry = 0;
        ListNode* cur = new ListNode();
        ListNode* out = cur;
        while (l1 || l2) {
            cur->next = new ListNode();
            cur = cur->next;
            int a = 0;
            int b = 0;
            if (l1) { 
                a = l1->val; // 9, 9, 9, 9, 9, 9, 9
                l1 = l1->next; // 2, 3, 4, 5, 6, 7, 8
            }
            if (l2) { 
                b = l2->val; // 9, 9, 9, 9, 0, 0, 0
                l2 = l2->next; // 2, 3, 4, 5, 5, 5, 5
            }
            
            cur->val = (a + b + carry) % 10; // 8, 9, 9, 9, 0, 0, 0
            carry = (a + b + carry) / 10; // 1, 1, 1, 1, 1, 1, 1
        }
        if (carry) {
            ListNode* temp = new ListNode(carry);
            cur->next = temp;
        }
        
        return out->next;// 8, 9, 9, 9, 0, 0, 0, 1
    }
};