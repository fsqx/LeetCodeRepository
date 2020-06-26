#include "mainHead.h"



int main(int argc, char *argv[])
{
    //ListNode *head = new ListNode(1);
    //ListNode *tmpHead = head;
    //for(int i = 1; i < 4; i++)
    //{
    //    ListNode *tmp = new ListNode(i);
    //    tmpHead->next = tmp;
    //    tmpHead = tmp;
    //}
    //for(int i = 3; i > 0; i--)
    //{
    //    ListNode *tmp = new ListNode(i);
    //    tmpHead->next = tmp;
    //    tmpHead = tmp;
    //}
    //vector<vector<int> > matrix = { {1, 1, 1}, {1, 0, 1}, {1, 1, 1} };
    Solution solution;
    string a = "abcdefg";
    string b = "jiskdi";
    solution.findLUSlength(a, b);
    system("pause");
    return 0;
}