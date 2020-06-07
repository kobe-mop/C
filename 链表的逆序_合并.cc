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




//翻转数组
#include <iostream>
using namespace std; 
void reversal(int arr[], int n)
{
    int temp;
 
    for(int i=0; i<n/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}
void list(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
int main() 
{
    int arr[] = {78, 86, 90, 83, 74, 68, 74, 80, 69, 79, 89, 93};
    int n = 12;
     
    cout<<"翻转前："<<endl;
    list(arr, n);
 
    reversal(arr, n);
 
    cout<<"翻转后："<<endl;
    list(arr, n);
 
    return 0;
}



//有序链表合并
void* mergeList(Node *head1, Node *head2){
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;
	
	Node *head = NULL;
	Node *p1 = NULL;
	Node *p2 = NULL;
	
	if(head1->data <= head2->data){
		head = head1;
		p1 = head1->next;
		p2= head2;
	}
	else{
		head = head2;
		p2 = head2->next;
		p1 = head1;
	}
	
	Node *pcurrent = head;
	while(p1 !=NULL && p2 != NULL)
	{
		if(p1->data <= p2->data){
			pcurrent->next = p1;
			pcurrent = p1;
			p1= p1->next;
			}
		else{
			pcurrent->next = p2;
			pcurrent = p2;
			p2= p2->next;
		}
	}
	
	if(p1 == NULL)
		pcurrent->next = p2;
	
	if(p2 == NULL)
		pcurrent->next = p1;
	
	return head;	
}

//有序链表递归方法合并
void* mergeListRecursive(Node *head1, Node *head2){
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;
	
	Node *head = NULL;
	
	if(head1->data <= head2->data){
		head = head1;
		head->next = mergeListRecursive(head1->next,head2);
	}
	else{
		head = head2;
		head->next = mergeListRecursive(head1,head2->next);
	}
	
	return head;	
}
