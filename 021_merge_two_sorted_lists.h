#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *listOne, ListNode *listTwo)
    {
        ListNode *list = nullptr;
        ListNode *temp = nullptr;

        while(!(isEmpty(listOne) && isEmpty(listTwo)))
        {
            if(isEmpty(listOne) && (!isEmpty(listTwo)))
            {
                temp = pop(&listTwo);
            }
            else if(isEmpty(listTwo) && (!isEmpty(listOne)))
            {
                temp = pop(&listOne);
            }
            else if(listOne->val < listTwo->val)
            {
                temp = pop(&listOne);
            }
            else
            {
                temp = pop(&listTwo);
            }

            pushBackOneNode(&list, temp);
        }

        return list;
    }

    ListNode *pop(ListNode **head)
    {
        ListNode *temp = *head;
        *head = (*head)->next;
        temp->next = nullptr;
        return temp;
    }

    void pushBackOneNode(ListNode **head, ListNode *node)
    {
        if((*head) == nullptr)
        {
            *head = node;
        }

        ListNode *temp = *head;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = node;
        node->next = nullptr;
    }

    bool isEmpty(ListNode *list)
    {
        if(list == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};