// Code based on:
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//
#pragma once

#include <stdexcept>
#include "SLinkedList.h"

using namespace std;

template <typename E>
class LinkedStack {		                  		// stack as a linked list
public:
   LinkedStack() :
   stack(), numberOfElements(0) {}              // constructor
   int size() const {return numberOfElements;}  // number of items in stack
   bool empty() const
      { return numberOfElements == 0; }         // is the stack empty?
   E& top() throw(length_error);          // the top element
   void push(const E& e);                       // push element onto stack
   void pop() throw(length_error);              // pop the stack
   void printAll() throw(length_error);         // print all
private:                                        // member data
   SLinkedList<E> stack;                        // stack of elements
   int numberOfElements;                        // number of elements
};


// get the top element
template <typename E>
E& LinkedStack<E>::top() throw(length_error) {
   if (empty()) throw length_error("Top of empty stack");
   return stack.front();
}

// push element onto stack
template <typename E>
void LinkedStack<E>::push(const E& e) {
   ++numberOfElements;
   stack.addFront(e);
}

// pop the stack
template <typename E>
void LinkedStack<E>::pop() throw(length_error) {
   if (empty()) throw length_error("Pop from empty stack");
   --numberOfElements;
   stack.removeFront();
}

// print all elements on stack
template <typename E>
void LinkedStack<E>::printAll() throw(length_error) {
   if (empty()) throw length_error("Empty stack");
   cout<< "Top of current stack: {" << stack.front() << "}" << endl;
}