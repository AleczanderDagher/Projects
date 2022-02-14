//--------------------------------------------------------------------
//
//  Laboratory 6                                         StackLinked.h
// 
//  Class declaration for the linked implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKLINKED_H
#define STACKLINKED_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType> {

  public:
    /// Precondition: Stack must exist.\n
    /// Postcondition: Creates an empty stack.\n
    /// Inputs: An integer.\n
    /// Outputs: None.
    StackLinked(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    //--------------------------------------------------------------------

    /// Precondition: Stack must exist.\n
    /// Postcondition: Initializes the stack to be equivalent to the other Stack object parameter.\n
    /// Inputs: StackLinked object referenced to other.\n
    /// Outputs: None.
    StackLinked(const StackLinked& other);
    //--------------------------------------------------------------------

    /// Precondition: Must be a valid stack.\n
    /// Postcondition: This will set the stack equivalent to other Stack object parameter.\n
    /// Inputs: StackLinked object referenced to other.\n
    /// Outputs: Returns the reference to the modified stack.
    StackLinked& operator=(const StackLinked& other);
    //--------------------------------------------------------------------

    /// Precondition: Stack must exist.\n
    /// Postcondition: Frees the memory used to store the stack.\n
    /// Inputs: None.\n
    /// Outputs: None.
    ~StackLinked();
    //--------------------------------------------------------------------

    /// Precondition: Stack must NOT be full.\n
    /// Postcondition: Places newDataItem on the top of the stack.\n
    /// Inputs: DataType object referenced to newDataItem.\n
    /// Outputs: Outputs statement "Can't add item. Stack is full." if stack is full.
    void push(const DataType& newDataItem);
    //--------------------------------------------------------------------

    /// Precondition: Stack must NOT be empty.\n
    /// Postcondition: Removes the top data item from the stack and returns the
    /// value of the deleted item.\n
    /// Inputs: None.\n
    /// Outputs: Returns the value of the item that was removed from the stack. Also outputs statement 
    /// "No item to pop. Stack is empty." if stack is empty.
    DataType pop();
    //--------------------------------------------------------------------

    /// Precondition: Data items must be present in stack.\n
    /// Postcondition: Gets rid of all the data items in the stack.\n
    /// Inputs: None.\n
    /// Outputs: None.
    void clear();
    //--------------------------------------------------------------------

    /// Precondition: Stack must exist.\n
    /// Postcondition: If the stack is empty, it will return true.\n
    /// Inputs: None.\n
    /// Outputs: Returns top = to 0.
    bool isEmpty() const;
    //--------------------------------------------------------------------

    /// Precondition: Stack must exist.\n
    /// Postcondition: If the stack is full, it will return true.\n
    /// Inputs: None.\n
    /// Outputs: Returns false if stack is not full.
    bool isFull() const;
    //--------------------------------------------------------------------
    void showStructure() const;

  private:

    class StackNode {
      public:
     /// Precondition: Stack node must exist.\n
     /// Postcondition: This creates a stack node containing a new data item and the next pointer.\n
     /// Inputs: DataType object referenced to nodeData and "nextPtr", which represents a pointer of 
     /// a StackNode object type.\n
     /// Outputs: None.
	StackNode(const DataType& nodeData, StackNode* nextPtr);

	DataType dataItem;
	StackNode* next;
    };

    StackNode* top;
};

#endif		//#ifndef STACKARRAY_H

