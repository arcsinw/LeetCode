

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (!l1 || !l2) { return l1 ? l1 : l2;}

    ListNode* result;
    if (l1->val < l2->val)
    {
        result = l1;
        l1 = l1->next;
    }
    else
    {
        result = l2;
        l2 = l2->next;
    }

    ListNode* cur = result;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }

        cur = cur->next;
    }

    if (l1)
    {
        cur->next = l1;
    }
    else
    {
        cur->next = l2;
    }

    return result;
}
