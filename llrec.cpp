#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if (head == NULL)
    {
        return;
    }
    smaller = NULL;
    larger = NULL;
    pivotNode(head, smaller, larger, pivot);
}

void pivotNode(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    Node *tmp;
    if (head == NULL) {
        return;
    }
    if (head->val <= pivot)
    {
        if (head->next != NULL)
        {
            tmp = head->next;
            smaller = head;
            pivotNode(head->next, smaller->next,  larger, pivot);
        }
    }
    else
    {
        if (head->next != NULL)
        {
            tmp = head->next;
            larger = head;
            pivotNode(head->next, smaller,  larger->next, pivot);
        }
    }
}
