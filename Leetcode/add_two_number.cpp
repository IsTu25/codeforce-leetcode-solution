class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= new ListNode(0);
        ListNode* current = head;
        int carry=0;
        
        while(l1!=NULL || l2 != NULL || carry > 0){
            int x = (l1 != NULL) ? l1 -> val: 0;
            int y = (l2 != NULL) ? l2 -> val: 0;
            int sum = x+y+carry;

            carry = sum / 10;
            sum = sum % 10;

            current ->next = new ListNode(sum);
            current = current -> next;

            if(l1 != NULL)l1 = l1-> next;
            if(l2 != NULL)l2 = l2-> next;

        }
        ListNode* result = head->next;
        delete head;
        return result;
    }
};