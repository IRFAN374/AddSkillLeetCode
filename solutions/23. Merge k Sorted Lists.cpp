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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=NULL;
        int listSize=lists.size();
        if(listSize == 0) return head;
        
        int low =0,high = listSize-1;
        ListNode *curr = DivideAndMerge(lists,low,high);
        return curr;
    }
    
   ListNode *DivideAndMerge(vector<ListNode*>& lists,int low,int high){
       while(low<high){
           lists[low] = mergeList(lists[low],lists[high]); 
           low++;
           high--;
           if(low>=high){
               low=0;
               high =high;
           }
       }
        // if(low<high){
        //     int mid = low + (high -low)/2;
        //     ListNode *l1= DivideAndMerge(lists,low,mid);
        //     ListNode *l2 =DivideAndMerge(lists,mid+1,high);
        //     mergeList(l1,l2);
        // }
        return lists[0]; // return something
