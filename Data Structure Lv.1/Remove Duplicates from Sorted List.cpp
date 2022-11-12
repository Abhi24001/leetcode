class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;
        ListNode* temp=head;
        ListNode* cur=head->next;
        while(cur!=NULL)
        {
            if(cur->val==temp->val)
            {
               temp->next=cur->next;
            }else 
            {
                temp=cur;
            }
            cur=cur->next;
        }
        return head;
    }
};
