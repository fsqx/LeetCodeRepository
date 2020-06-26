#pragma once
#include <unordered_set>
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
    ListNode* removeDuplicateNodes(ListNode* head)
    {
        ListNode *perHead = new ListNode(-1);
        perHead->next = head;
        ListNode *tmpHead = perHead;
        unordered_set<int> nodeValueSet;

        while(tmpHead->next != NULL)
        {
            if(nodeValueSet.find(tmpHead->next->val) != nodeValueSet.end())
            {
                ListNode *delNode = tmpHead->next;
                tmpHead->next = delNode->next;
            }
            else
            {
                nodeValueSet.insert(tmpHead->next->val);
                tmpHead = tmpHead->next;
            }
        }

        tmpHead = perHead->next;
        delete perHead;
        return tmpHead;
    }
};