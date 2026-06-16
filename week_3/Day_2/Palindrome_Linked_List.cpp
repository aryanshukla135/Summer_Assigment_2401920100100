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
private :
    ListNode* getMiddle(ListNode* head){
           
           ListNode* slow = head ;
           ListNode* fast = head ;

           while(fast != nullptr && fast->next != nullptr){
             slow = slow->next ;
             fast = fast->next->next ;
           }
           return slow ;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head ;
        ListNode* prev = nullptr ;
        ListNode* nextNode = nullptr;

        while(curr != nullptr ){
            nextNode = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = nextNode ;
        }
        return prev ;
    }
public:
    bool isPalindrome(ListNode* head) {
         if(head == nullptr || head->next == nullptr){
              return true ;
         }

         ListNode* mid = getMiddle(head);
         ListNode* revHead = reverse(mid);
         ListNode* temp = head ;
         
         while(revHead != nullptr ){
            
            if(temp->val != revHead->val){
                return false ;
            }
            revHead = revHead->next;
            temp = temp->next ;
         }
         return true ;
    }
};
