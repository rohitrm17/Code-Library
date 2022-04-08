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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode();
    ListNode *p1 = l1, *p2 = l2, *p3 = ans;
    int carry = 0, s;
    while (p1 != NULL && p2 != NULL)
    {
        s = p1->val + p2->val + carry;
        carry = s / 10;
        s = s % 10;
        p3->next = new ListNode(s);
        p3 = p3->next;
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p1 != NULL && carry)
    {
        s = p1->val + carry;
        carry = s / 10;
        s %= 10;
        p3->next = new ListNode(s);
        p3 = p3->next;
        p1 = p1->next;
    }

    while (p2 != NULL && carry)
    {
        s = p2->val + carry;
        carry = s / 10;
        s %= 10;
        p3->next = new ListNode(s);
        p3 = p3->next;
        p2 = p2->next;
    }
    while (carry)
    {
        s = carry % 10;
        carry /= 10;
        p3->next = new ListNode(s);
        ;
        p3 = p3->next;
    }

    if (p1 != NULL)
        p3->next = p1;

    if (p2 != NULL)
        p3->next = p2;

    return ans->next;
}

int main()
{
    return 0;
}