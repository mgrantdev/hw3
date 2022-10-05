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
    if (head == NULL)
        return;

    // @condition Make sure to equalize the pointer positions at the end
    if(head->next == NULL) {
        if(head->val <= pivot) {
            larger = larger->next;
        } else {
            smaller = smaller->next;
        }
    }

    // @condition Compare value against pivot and switch accordingly
    if (head->val <= pivot)
    {
        smaller = head;
        head = head->next;
        pivotNode(head, smaller->next, larger, pivot);
    }
    else
    {
        larger = head;
        head = head->next;
        pivotNode(head, smaller, larger->next, pivot);
    }
}
