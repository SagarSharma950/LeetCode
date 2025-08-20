class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->val == temp->next->val){
                ListNode* dup = temp->next;
                temp->next = temp->next->next;
                delete dup;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};