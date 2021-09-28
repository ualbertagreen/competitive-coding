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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { //listA = [4,1,8,4,5], listB = [5,6,1,8,4,5]
        ListNode* countA = headA; //4
        ListNode* countB = headB; //5
        
        int lengthA = 0;
        int lengthB = 0;
        while (countA) { //4, 1
            lengthA++; //1, 2
            countA = countA->next;
        } //5
        while (countB) {
            lengthB++;
            countB = countB->next;
        } //6
                
        while (lengthA != lengthB) {
            if (lengthA > lengthB) {
                lengthA--;
                headA = headA->next;
            }
            if (lengthB > lengthA) {
                lengthB--; //5
                headB = headB->next; //6
            }
        }
        
        while (headA != headB) {
            headA = headA->next; //1, 8, 4, 5, null
            headB = headB->next; //1, 8, 4, 5, null
        }
        
        return headA;
    }
};