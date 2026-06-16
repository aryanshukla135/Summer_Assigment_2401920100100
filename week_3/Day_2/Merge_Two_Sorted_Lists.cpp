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
    ListNode* solve(ListNode* first , ListNode* second){
         ListNode* curr1 = first ;
         ListNode* next1 = first->next ;
         ListNode* curr2 = second ;
         ListNode* next2 = second->next ;

         if(next1 == nullptr){
            curr1->next= curr2;
            return first ;
         }

         while(next1 != nullptr && curr2 != nullptr){
               if(curr2->val >= curr1->val && curr2->val <= next1->val){
                    curr1->next = curr2 ;
                    next2=curr2->next;
                    curr2->next = next1 ;
                    curr1 = curr2 ;
                    curr2=next2;
            
               }else{
                    curr1 = next1 ;
                    next1 = curr1->next ;

                    if(next1 == nullptr){
                        curr1->next = curr2 ;
                        return first ;
                    }
               }
         }
         return first ;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
              if(list1==nullptr){
                 return list2;
              }
              if(list2==nullptr){
                 return list1;
              }
              ListNode*ans =nullptr;

              if(list1->val <= list2->val){
                ans = solve(list1,list2);
              }else{
                ans = solve(list2,list1);
              }
            return ans ;
    }
};
