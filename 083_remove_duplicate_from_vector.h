#pragma once


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* currentNode = head;
        ListNode* tmpNode = head->next;

        while(currentNode->next != nullptr)
        {
            if(currentNode->val == tmpNode->val)
            {
                ListNode* deleteNode = deleteNextNode(currentNode);
                delete deleteNode;
            }
            else
            {
                currentNode = currentNode->next;
            }

            tmpNode = currentNode->next;
        }

        return head;
    }

    ListNode* deleteNextNode(ListNode* node)
    {
        if(node == nullptr)
        {
            return nullptr;
        }

        ListNode* tmp = node->next;
        node->next = tmp->next;
        tmp->next = nullptr;
        return tmp;
    }
};