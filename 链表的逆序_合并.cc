//翻转链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };

class Solution{
    public:
    ListNode* ReverseList(ListNode *head){
        if(head !=NULL && head->next !=NULL){
            ListNode *pre = NULL;
            ListNode *curr = head;
            ListNode *post = NULL;
            
            while (curr)
            {
                post = curr->next; //保存curr后面的链表
                curr->next = pre;  //链表翻转
                pre = curr;  //pre链表后移
                curr = post; //curr链表后移
            }
            return pre;
        }
        else
            return head;


        //递归解法
        // if(head != NULL && head->next!=NULL){
        //     ListNode *curr = reverseList(head->next);
        //     head->next->next = head;
        //     head->next = NULL;
        //     return curr;
        // }
        // else 
        //     return head;
    }
};







//有序链表合并
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *pre = head;

        while(l1 != NULL && l2 != NULL){
            if(l1->val<l2->val){
                pre->next = l1;
                l1 = l1->next;
            }
            else{
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }

        pre->next = l1 == NULL ? l2 : l1;
        return head->next;

        //递归方法
        // if(l1 == NULL){
        //     return l2;
        // }
        // else if (l2 == NULL)
        // {
        //     return l1;
        // }
        // else if(l1->val<l2->val){
        //     l1->next = mergeTwoLists(l1->next, l2);
        //     return l1;
        // }
        // else {
        //     l2->next = mergeTwoLists(l1, l2->next);
        //     return l2;
        // }
    }
};
