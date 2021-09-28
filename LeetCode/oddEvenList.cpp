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
    ListNode* oddEvenList(ListNode* head) { //1, 2, 3, 4, 5, 6, 7
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        
        ListNode* odd = head; //1
        ListNode* odd_start = odd; //1
        ListNode* even = head->next; //2
        ListNode* even_start = even; //2
        
        bool parity = true; // attach next to odd
        head = head->next; //2
        while (head->next) {
            head = head->next; //3, 4, 5, 6, 7, '8'
            if (parity) {
                odd->next = head; //1->3->5->7
                odd = odd->next; //3, 5, 7
            }
            else {
                even->next = head; //2->4->6->'8'
                even = even->next; //4, 6, '8'
            }
            
            parity = !parity;
        }
        
        odd->next = even_start;
        even->next = NULL;
        
        return odd_start;
    }
};