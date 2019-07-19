//
//  stack_p1.h
//
//
//  Created by Resch,Cheryl on 5/30/18.
//
// Elba Chimilio
// Section: 7303

#ifndef stack_p1_h
#define stack_p1_h
#include <iostream>
using namespace std;

template <typename T>
class stack_p1{

private:
	struct stackN{ //Structure for the stack nodes
	T value; // Value in the node
	stackN *next; // Pointer to the next node
};
   
   stackN *top; // Pointer to the stack top

public:
   // Constructor
   stack_p1(){
       top = NULL;
   }

   // Stack operations
   bool isEmpty();
   T pop();
   void push(T item);
   T peek();
};

// Pushes onto the stack

template <typename T>
void stack_p1<T>::push(T item){
   stackN *newNode; // Pointer to a new node

   // Allocate a new node and store item there
   newNode = new stackN;
   newNode->value = item;

   // No nodes in the list -> make newNode the first node
   if (isEmpty()){
       top = newNode;
       newNode->next = NULL;
   }else{ // Else, insert newNode before top
       newNode->next = top;
       top = newNode;
   }
}

// Pops the value at the top of the stack

template <typename T>
T stack_p1<T>::pop(){

   // First make sure the stack isn't empty
   if (isEmpty()){
       return 0;
   }else if (!isEmpty()){
        stackN *topNode = top;
        top = top->next;
        T value = topNode->value;
        delete topNode;
        return value;
    }
}

template<typename T>
T stack_p1<T>::peek(){
    if (!isEmpty()){
        return top->value;
    }else{
		return 0;
	}
}

// isEmpty returns true if the stack is empty, false if it isn't

template <typename T>
bool stack_p1<T>::isEmpty(){
   bool status;
   if (!top){
       status = true;
   }else{
       status = false;
   }
   return status;
}
#endif
