#pragma once
#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}

};
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *head = nullptr;
    ListNode *rstHead = nullptr;
    ListNode *tempL1 = l1;
    ListNode *tempL2 = l2;

    while(tempL1 != nullptr || tempL2 != nullptr)
    {
        int rstVar;

        if(tempL1 == nullptr)
        {
            rstVar = tempL2->val;
            tempL2 = tempL2->next;
        }
        else if(tempL2 == nullptr)
        {
            rstVar = tempL1->val;
            tempL1 = tempL1->next;
        }
        else
        {
            rstVar = tempL1->val + tempL2->val;
            tempL1 = tempL1->next;
            tempL2 = tempL2->next;
        }

        ListNode *newNode = new ListNode(rstVar);

        if(head == nullptr)
        {
            head = newNode;
            rstHead = newNode;
        }
        else
        {
            head->next = newNode;
            head = head->next;
        }
    }

    head = rstHead;

    while(head != nullptr)
    {
        if(head->val > 9)
        {
            if(head->next != nullptr)
            {
                head->next->val += head->val / 10;
                head->val = head->val % 10;
            }
            else
            {
                ListNode *newNode = new ListNode(head->val / 10);
                head->next = newNode;
                head->val = head->val % 10;
            }
        }

        head = head->next;
    }

    return rstHead;
}