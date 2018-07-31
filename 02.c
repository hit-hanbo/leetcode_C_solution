#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void Add_Node(struct ListNode* head, int val)
{
    struct ListNode *tail = NULL;
    while(head->next != NULL)
    {
        head = head->next;
    }
    tail = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = tail;
    tail->val = val;
    tail->next = NULL;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int sum, cs = 0;
    struct ListNode *head = NULL;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    while(l1 && l2)
    {
        sum = l1->val + l2->val + cs;
        if(sum < 10)
        {
            Add_Node(head, sum);
            cs = 0;
        }
        else
        {
            Add_Node(head, sum % 10);
            cs = 1;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 == NULL && l2 != NULL)
    {
        sum = cs + l2->val;
        if(sum < 10)
        {
            Add_Node(head, sum);
            cs = 0;
        }
        else
        {
            Add_Node(head, sum % 10);
            cs = 1;
        }
        l2 = l2->next;
    }
    while(l1 != NULL && l2 == NULL)
    {
        sum = cs + l1->val;
        if(sum < 10)
        {
            Add_Node(head, sum);
            cs = 0;
        }
        else
        {
            Add_Node(head, sum % 10);
            cs = 1;
        }
        l1 = l1->next;
    }
    if(l1 == NULL && l2 == NULL)
    {
        if(cs == 1)
            Add_Node(head, cs);
    }
    return head->next;
}

int main()
{
    struct ListNode l1, l2, l3, l4, l5, l6;
    struct ListNode *head = NULL;
    l1.val = 1;
    l2.val = 0;
    l3.val = 0;
    l4.val = 9;
    l5.val = 9;
    l6.val = 9;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = NULL;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = NULL;
    head = addTwoNumbers(&l1, &l4);
    printf("%d %d %d %d\n", head->val, head->next->val, head->next->next->val, head->next->next->next->val);
    return 0;
}