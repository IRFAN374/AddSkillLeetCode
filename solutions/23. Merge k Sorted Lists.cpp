/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   struct comp
     {
        bool operator()(const ListNode *lhs, const ListNode *rhs) const {
            return lhs->val > rhs->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        int listSize = lists.size();
        if(listSize==0) return head;
        
        priority_queue<ListNode*, vector<ListNode*>,comp >pq;
        for(int i=0;i<listSize;i++){
            if(lists[i]!=NULL) pq.push(lists[i]);
        }
        
        ListNode *temp=NULL,*last=NULL;
        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            if(head==NULL){
                head = last = temp;
            }else{
                last->next = temp;
                last = last->next;
            }
            if(temp->next!=NULL) pq.push(temp->next);
        }
        return head;
