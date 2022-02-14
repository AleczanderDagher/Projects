//--------------------------------------------------------------------
//
//  Lab 6                                          
// 
//  StackLinked.cpp
//
//--------------------------------------------------------------------

#ifndef STACKLINKED_CPP
#define STACKLINKED_CPP

#include <iostream>
#include "StackLinked.h"

using namespace std;

/// Precondition: Stack must exist.\n
/// Postcondition: Initializes the stack to be equivalent to the other Stack object parameter.\n
/// Inputs: StackLinked object referenced to other.\n
/// Outputs: None.
template <typename DataType>
StackLinked<typename DataType>::StackLinked(const StackLinked& other)
{
	top = nullptr;
	operator=(other);
}

//--------------------------------------------------------------------

/// Precondition: Stack node must exist.\n
/// Postcondition: This creates a stack node containing a new data item and the next pointer.\n
/// Inputs: DataType object referenced to nodeData and "nextPtr", which represents a pointer of 
/// a StackNode object type.\n
/// Outputs: None.
template <typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr)
{
	dataItem = nodeData;
	next = nextPtr;
}

//--------------------------------------------------------------------

/// Precondition: Stack must exist.\n
/// Postcondition: Frees the memory used to store the stack.\n
/// Inputs: None.\n
/// Outputs: None.
template <typename DataType>
StackLinked<typename DataType>::~StackLinked()
{
	clear();
}

//--------------------------------------------------------------------

/// Precondition: Stack must exist.\n
/// Postcondition: Creates an empty stack.\n
/// Inputs: An integer.\n
/// Outputs: None.
template <typename DataType>
StackLinked<typename DataType>::StackLinked(int maxNumber)
{
	DataType dataItem = nullptr;
	StackNode* next = nullptr;
	top = nullptr;
}

//--------------------------------------------------------------------

/// Precondition: Must be a valid stack.\n
/// Postcondition: This will set the stack equivalent to other Stack object parameter.\n
/// Inputs: StackLinked object referenced to other.\n
/// Outputs: Returns the reference to the modified stack.
template <typename DataType>
StackLinked<typename DataType>& StackLinked<typename DataType>:: operator=(const StackLinked& other)
{
	if (this != &other) 
		return *this;

	clear(); 
	if (!other.isEmpty()) 
	{
		top = new StackNode(other.top->dataItem, 0);
		StackNode* other_temp = other.top->next;
		StackNode* this_temp = 0, * previous = top;

		while (other_temp != 0)
		{
			this_temp = new StackNode(other_temp->dataItem, 0);
			previous->next = other->top;
			previous = top;
			other_temp = previous;
		}
	}

	return *this;
}

//--------------------------------------------------------------------

//--------------------------------------------------------------------

/// Precondition: Stack must NOT be full.\n
/// Postcondition: Places newDataItem on the top of the stack.\n
/// Inputs: DataType object referenced to newDataItem.\n
/// Outputs: Outputs statement "Can't add item. Stack is full." if stack is full.
template <typename DataType>
void StackLinked<typename DataType>::push(const DataType& newDataItem) 
{

	StackNode* stack = new StackNode(newDataItem, top);
	stack->dataItem = newDataItem;
	stack->next = top;
	if (isFull()) 
	{
		cout << "Can't add item. Stack is full." << endl;
	}
	
}

//--------------------------------------------------------------------

/// Precondition: Stack must NOT be empty.\n
/// Postcondition: Removes the top data item from the stack and returns the
/// value of the deleted item.\n
/// Inputs: None.\n
/// Outputs: Returns the value of the item that was removed from the stack. Also outputs statement 
/// "No item to pop. Stack is empty." if stack is empty.
template <typename DataType>
DataType StackLinked<typename DataType>::pop()
{
	StackNode* new_top = top->next;
	StackNode* tempNode = top;
	top = new_top;
	return tempNode->dataItem;
	delete tempNode;
	if (isEmpty())
	{
		cout << "No item to pop. Stack is empty." << endl;
	}
}

//--------------------------------------------------------------------

/// Precondition: Data items must be present in stack.\n
/// Postcondition: Gets rid of all the data items in the stack.\n
/// Inputs: None.\n
/// Outputs: None.
template <typename DataType>
void StackLinked<typename DataType>::clear()
{
	delete top;
	top = nullptr;
}

//--------------------------------------------------------------------

/// Precondition: Stack must exist.\n
/// Postcondition: If the stack is empty, it will return true.\n
/// Inputs: None.\n
/// Outputs: Returns top = to 0.
template <typename DataType>
bool StackLinked<typename DataType>::isEmpty() const
{
	return top == 0;
}

//--------------------------------------------------------------------

/// Precondition: Stack must exist.\n
/// Postcondition: If the stack is full, it will return true.\n
/// Inputs: None.\n
/// Outputs: Returns false if stack is not full.
template <typename DataType>
bool StackLinked<typename DataType>::isFull() const
{
	return false;
}

#endif	

