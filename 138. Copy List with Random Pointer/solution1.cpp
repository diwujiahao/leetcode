/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    unordered_map<RandomListNode*, RandomListNode*> hash;
    RandomListNode *head_copy = nullptr;
    void build(RandomListNode *node, RandomListNode *node_copy){
        if (!node){
            return;
        }
        // 下一个节点不存在
        if (node->next){
            if (hash.find(node->next) == hash.end()){
                node_copy->next = new RandomListNode(node->next->label);
                hash[node->next] = node_copy->next;
            }
            // 下一个节点已经存在
            else{
                node_copy->next = hash[node->next];
            }
        }
        
        if (node->random){
            // 随机节点不存在
            if (hash.find(node->random) == hash.end()){
                node_copy->random = new RandomListNode(node->random->label);
                hash[node->random] = node_copy->random;
            }
            // 随机节点存在
            else{
                node_copy->random = hash[node->random];
            }
        }
        
        build(node->next, node_copy->next);
        
    }
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head){
            return head_copy;
        }
        head_copy = new RandomListNode(head->label);
        hash[head] = head_copy;
        build(head, head_copy);
        return head_copy;
    }
};
