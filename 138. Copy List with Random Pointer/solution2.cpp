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
    
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        RandomListNode *head_copy = (head) ? new RandomListNode(head->label) : nullptr;
        hash[head] = head_copy;
        RandomListNode *point = head, *copy_point = head_copy;
        
        while(point){
            if (point->next){
                // 出现过
                if (hash.find(point->next) != hash.end()){
                    copy_point->next = hash[point->next];
                }
                // 未出现
                else{
                    copy_point->next = new RandomListNode(point->next->label);
                    hash[point->next] = copy_point->next;
                }
            }
            if (point->random){
                // 出现过
                if (hash.find(point->random) != hash.end()){
                    copy_point->random = hash[point->random];
                }
                // 未出现
                else{
                    copy_point->random = new RandomListNode(point->random->label);
                    hash[point->random] = copy_point->random;
                }
            }
            point = point->next;
            copy_point = copy_point->next;
        }
        return head_copy;
    }
};