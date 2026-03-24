// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      struct ListNode* next = head;
      struct ListNode* prev = NULL;
      struct ListNode* head_new = head;
      while(next != NULL && next->next != NULL){
            struct ListNode* one = next;
            struct ListNode* two = one->next;
            next = two->next;
            if(prev == NULL){head_new = two;}
            else{prev->next = two;}
            two->next = one;
            one->next = next;
            prev = one;
      }
      return head_new;
}