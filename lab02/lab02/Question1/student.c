// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen


int max = 100;
char stack[100];
int top = -1;

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == max - 1;
}

int push (char v){
    if(isFull()){
        return 0;
    }
    stack[++top] = v;
    return 1;
}

char pop(){
    if(isEmpty()){
        return 'a';
    }
    return stack[top--];
}

char peek(){
    if(isEmpty()){
        return 'a';
    }
    return stack[top];
}

void reset(){
    top = -1;
}

bool isValid(const char *s) {
    reset();
    // TODO: Implement using a stack.
    //
    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    // - Scan the string from left to right:
    //   - If you see an opening bracket, push it.
    //   - If you see a closing bracket:
    //       * stack must not be empty
    //       * top of stack must match the closing bracket type
    //       * then pop
    // - At the end, stack must be empty.
    //
    // Helpful matching pairs:
    //   ')' matches '('
    //   ']' matches '['
    //   '}' matches '{'
    //
    // Corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    //
    // Note:
    // - Input contains only bracket characters, per the prompt.
    if(s==NULL)return false;
    int n = strlen(s);
    for(int i=0;i<n;i++){
        char c = s[i];
        if(c == '{' || c == '[' || c == '('){
            push(c);
        }
        if ((c == '}') || (c == ']') || (c == ')')){
            char e = peek();
            if((c == '}' && e == '{')||(c == ']' && e == '[')||(c == ')' && e == '(')){
                pop();
            } else {
                return false;
            }
        }
    }
    if(!isEmpty()){
        return false;
    }
    return true;
}
