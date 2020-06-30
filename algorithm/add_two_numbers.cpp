#include <iostream>
#include <stdlib.h>
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
    ListNode *ans = new ListNode;
    ListNode *ans_h = ans;
    int carry = 0;

    while (l1 || l2 || carry > 0)
    {
        int num = 0;
        if (l1)
        {
            num += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            num += l2->val;
            l2 = l2->next;
        }
        ans->val = (num + carry) % 10;
        carry = (num + carry) / 10;
        if (l1 || l2 || carry > 0)
        {
            ans->next = new ListNode;
            ans = ans->next;
        }
    }

    return ans_h;
}

void print_list(ListNode *l)
{
    while (l)
    {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

ListNode *create(int num)
{
    ListNode *l = new ListNode;
    ListNode *h = l;
    while (num != 0)
    {
        l->val = num % 10;
        num = num / 10;
        if (num != 0)
        {
            l->next = new ListNode;
            l = l->next;
        }
    }
    return h;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 = create(3421);
    ListNode *l2 = create(46522);
    print_list(l1);
    print_list(l2);
    print_list(addTwoNumbers(l1, l2));

    return 0;
}
