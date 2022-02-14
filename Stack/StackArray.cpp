//--------------------------------------------------------------------
//
//  Lab 6                                          
// 
//  StackArray.cpp
//
//--------------------------------------------------------------------

#ifndef STACKARRAY_CPP
#define STACKARRAY_CPP

#include <iostream>
#include "StackArray.h"

using namespace std;

/// Precondition: Stack must exist.\n
/// Postcondition: Initializes the stack to be equivalent to the other Stack object parameter.\n
/// Inputs: StackLinked object referenced to other.\n
/// Outputs: None.
template <typename DataType>
StackArray<typename DataType>::StackArray(const StackArray& other)
{
	maxSize = other.maxSize;
	top = other.top;
	dataItems = new DataType[maxSize];
	for (int i = 0; i <= top; i++)
	{
		dataItems[i] = other.dataItems[i];
	}
}

//--------------------------------------------------------------------

/// Precondition: Stack must exist.\n
/// Postcondition: Frees the memory used to store the stack.\n
/// Inputs: None.\n
/// Outputs: None.
template <typename DataType>
StackArray<typename DataType>::~StackArray()
{
	clear();
}

//--------------------------------------------------------------------

/// Precondition: Stack must exist.\n
/// Postcondition: Creates an empty stack.\n
/// Inputs: An integer.\n
/// Outputs: None.
template <typename DataType>
StackArray<typename DataType>::StackArray(int maxNumber)
{
	maxSize = maxNumber;
	top = -1;
	dataItems = new DataType[maxNumber];

}

//--------------------------------------------------------------------

/// Precondition: Must be a valid stack.\n
/// Postcondition: This will set the stack equivalent to other Stack object parameter.\n
/// Inputs: StackLinked object referenced to other.\n
/// Outputs: Returns the reference to the modified stack.
template <typename DataType>
StackArray<typename DataType>& StackArray<typename DataType>:: operator=(const StackArray& other)
{
	if (this != &other) 
		return *this;

	if (maxSize < other.maxSize) 
	{
		delete[] dataItems;
		dataItems = new DataType[other.maxSize];
	}
	maxSize = other.maxSize;
	top = other.top;
	for (int i = 0; i <= top; i++)
	{

		dataItems[i] = other.dataItems[i];
	}

	return *this;
}

//--------------------------------------------------------------------

/// Precondition: Stack must NOT be full.\n
/// Postcondition: Places newDataItem on the top of the stack.\n
/// Inputs: DataType object referenced to newDataItem.\n
/// Outputs: Outputs statement "Can't add item. Stack is full." if stack is full.
template <typename DataType>
void StackArray<typename DataType>::push(const DataType& newDataItem) 
{
	dataItems[top + 1] = newDataItem;
	top++;
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
DataType StackArray<typename DataType>::pop()
{
	DataType p = dataItems[top];
	dataItems[top] = 0;
	top--;
	maxSize--;
	return dataItems[top + 1];
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
void StackArray<typename DataType>::clear()
{
	delete[] dataItems;
}

//--------------------------------------------------------------------

/// Precondition: Stack must exist.\n
/// Postcondition: If the stack is empty, it will return true.\n
/// Inputs: None.\n
/// Outputs: Returns top = to -1.
template <typename DataType>
bool StackArray<typename DataType>::isEmpty() const
{
	return top == -1;
}

//--------------------------------------------------------------------

/// Precondition: Stack must exist.\n
/// Postcondition: If the stack is full, it will return true.\n
/// Inputs: None.\n
/// Outputs: Returns top = maxSize -1.
template <typename DataType>
bool StackArray<typename DataType>::isFull() const
{
	return top == maxSize - 1;
}

#endif	
