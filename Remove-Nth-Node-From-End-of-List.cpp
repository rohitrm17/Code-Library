#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int size(ListNode *head)
    {
        int c = 0;
        if (head == NULL)
            return 0;
        ListNode *ptr = head;
        while (ptr != NULL)
        {
            c++;
            ptr = ptr->next;
        }
        return c;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int c = size(head);

        if (c - n == 0)
            return head->next;

        ListNode *ptr = head;
        for (int i = 0; i < c - n - 1; i++)
            ptr = ptr->next;

        ptr->next = ptr->next->next;

        return head;
    }
};

int main()
{
    return 0;
}