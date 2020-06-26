#pragma once
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(head == NULL)
        {
            return NULL;
        }

        // 构造头结点
        ListNode *firstHead = new ListNode(0);
        firstHead->next = head;
        ListNode *tmpHead = firstHead;
        ListNode *aimNode = firstHead;
        int nodeCount = 0;

        while(tmpHead->next != NULL)
        {
            if(nodeCount != n)
            {
                nodeCount++;
            }
            else
            {
                aimNode = aimNode->next;
            }

            tmpHead = tmpHead->next;
        }

        ListNode *delNode = aimNode->next;
        aimNode->next = delNode->next;
        delNode->next = NULL;
        // 移除后的头结点可能为空。
        head = firstHead->next;
        delete firstHead;
        return head;
    }
};