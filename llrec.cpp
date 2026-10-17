#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    //Base Case
    if (head == nullptr){
        smaller = nullptr; larger = nullptr;
        return;
    }
    //save curr node & adv head
    Node* current = head;
    head = head->next;
    //go through the rest of the list (recursive call)
    llpivot(head,smaller,larger,pivot);

    if (current->val <= pivot){
        //including current node in front of smaller list
        current->next = smaller;
        smaller = current;
    } else {
        current->next = larger;
        larger = current;
    }
}