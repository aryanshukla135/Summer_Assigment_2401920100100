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
private:
    int countNodes(ListNode* head){
         ListNode* curr = head ;
         int cnt =0;
         while(curr != nullptr){
            cnt++;
            curr = curr->next ;
         }
         return cnt ;
    }   

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
          if(head->next==nullptr){
            return nullptr ;
          }
          int totalNode = countNodes(head);
          int toDel = totalNode - n;

          ListNode* curr = head ; 
          ListNode* prev = nullptr ;
          int cnt =0;
          while(curr != nullptr && cnt != toDel){
               prev = curr ;
               cnt++;
               curr = curr->next ;
          }
          if(prev == nullptr){
            return curr->next;
          }
          prev->next = curr->next ;

           return head ;

    }
};
