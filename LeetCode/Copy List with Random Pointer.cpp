/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copies;
        
        Node* cur = head;
        while (cur) {
            Node* tmp = new Node(cur->val);
            copies[cur] = tmp;
            cur = cur->next;
        }
        
        cur = head;
        while (cur) {
            Node* tmp = copies[cur];
            tmp->next = copies[cur->next];
            tmp->random = copies[cur->random];
            cur = cur->next;
        }
        
        return copies[head];
    }
};