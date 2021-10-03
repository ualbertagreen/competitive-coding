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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, vector<ListNode*>> head;
        
        for (ListNode* l : lists) {
            if (l) head[l->val].push_back(l);
        }
                
        ListNode* anchor = new ListNode();
        ListNode* cur = anchor;
        while (!head.empty()) {            
            for (ListNode* l : head.begin()->second) {
                cur->next = l;
                
                while (l->next && l->next->val == l->val) {
                    l = l->next;
                    cur = cur->next;
                }
                if (l->next) head[l->next->val].push_back(l->next);
                
                cur = cur->next;
            }
            
            head.erase(head.begin()->first);
        }
        
        return anchor->next;
    }
};