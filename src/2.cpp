#include <iostream>

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode *root = nullptr, *l3 = nullptr;

    while (l1 || l2 || carry)
    {
        if (l1)
        {
            carry += l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            carry += l2->val;
            l2 = l2->next;
        }

        if (l3)
        {
            l3->next = new ListNode(carry % 10);
            l3 = l3->next;
        }
        else
        {
            root = new ListNode(carry % 10);
            l3 = root;
        }

        carry /= 10;
    }

    return root;
}

int main()
{

}
