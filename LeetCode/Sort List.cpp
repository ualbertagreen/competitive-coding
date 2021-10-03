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
class Solution { //[4,2,1,3]
public:
    ListNode* mergeSort(ListNode* a) {
        if (a == NULL) return a;
        if (a->next == NULL) return a;
        
        ListNode* anchor = new ListNode();
        ListNode* cur = anchor;
        
        ListNode* b = a;
        ListNode* tmp = a;
        
        while (tmp) {
            if (tmp) tmp = tmp->next; //2, 3;    2
            if (tmp) tmp = tmp->next; //1, NULL; NULL;
            
            if (tmp) b = b->next; //2
        }
        
        tmp = b;
        b = b->next; //1; 2
        tmp->next = NULL;
        
        a = mergeSort(a);
        b = mergeSort(b);
        
        while (a && b) {
            if (a->val < b->val) {
                cur->next = a;
                a = a->next;
                cur = cur->next;
            }
            else {
                cur->next = b;
                b = b->next;
                cur = cur->next;
            }
        }
        
        if (a) cur->next = a;
        else if (b) cur->next = b;
        
        return anchor->next;
    }
    
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};