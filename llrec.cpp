#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.

 */
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  if (head == nullptr)
  {
    smaller = nullptr;
    larger = nullptr;
    return;
  }
  Node* next_ptr = head->next;
  llpivot(next_ptr, smaller, larger, pivot);
  
  if (head->val > pivot)
  {
    head->next = larger;
    larger = head;
  }

  else
  {
    head->next = smaller;
    smaller = head;
  }

  head = next_ptr;
}