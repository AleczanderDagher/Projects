//--------------------------------------------------------------------
//
//  Laboratory 11                                             Heap.cpp
//
//  
//
//--------------------------------------------------------------------

#ifndef HEAP_CPP
#define HEAP_CPP

#include<iostream>
#include<string>
#include"Heap.h"

using namespace std;

/// Precondition: Heap must exist.\n
/// Postcondition:"Creates an empty heap and allocates enough memory for a heap containing 'maxNumber'
/// data items."\n
/// Inputs: An integer.\n
/// Outputs: None.
template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>::Heap(int maxNumber)
{
    size = NULL;
    maxSize = maxNumber;
    dataItems = new DataType[maxNumber];
}

//--------------------------------------------------------------------

/// Precondition: Stack must exist.\n
/// Postcondition: "Initializes an object to be an equivalent copy of 'other'."\n
/// Inputs: Heap object referenced to other.\n
/// Outputs: None.
template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>::Heap(const Heap& other)
{
    *this = other;
}

//--------------------------------------------------------------------

/// Precondition: Must be a valid heap.\n
/// Postcondition: This will set the heap equivalent to the other heap object parameter.\n
/// Inputs: Heap object referenced to other.\n
/// Outputs: Returns the reference to the modified heap.
template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>& Heap<DataType, KeyType, Comparator>::operator= (const Heap& other)
{
    if (this == &other)
        return *this;
    if (size != 0)
        clear();
    size = other.size;
    maxSize = other.maxSize;
    for (int i = 0; i < size; i++)
        dataItems[i] = other.dataItems[i];

    return *this;
}

//--------------------------------------------------------------------

/// Precondition: Heap must exist.\n
/// Postcondition: Frees the memory used to destroy the heap.\n
/// Inputs: None.\n
/// Outputs: None.
template < typename DataType, typename KeyType, typename Comparator >
Heap<DataType, KeyType, Comparator>::~Heap()
{
    clear();
}

//--------------------------------------------------------------------

/// Precondition: Heap must exist and must not be full.\n
/// Postcondition: Inserts the new data item into the heap.\n
/// Inputs: DataType object referenced to newDataItem.\n
/// Outputs: Returns "The list is full" if size == maxSize.
template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::insert(const DataType& newDataItem)
{
    if (size == maxSize)
    {
        cout << "The list is full." << endl;
    }

    int index = size;
    dataItems[size] = newDataItem;
    
    while (comparator(dataItems[index].getPriority(), dataItems[(index - 1) / 2].getPriority()))
    {
        DataType data = dataItems[index];
        dataItems[index] = dataItems[(index - 1) / 2];
        dataItems[(index - 1) / 2] = data;
        index = (index - 1) / 2;
    }

    size++;        
}

//--------------------------------------------------------------------

/// Precondition: Heap must exist and must not be empty.\n
/// Postcondition: Removes the highest priority data item and returns it.\n
/// Inputs: None.\n
/// Outputs: Returns "The list is empty" if size == 0, otherwise it returns removed item.
template < typename DataType, typename KeyType, typename Comparator >
DataType Heap<DataType, KeyType, Comparator>::remove()
{
    if (size == 0)
    {
        cout << "The list is empty." << endl;
    }

    DataType remElement = dataItems[0];
    dataItems[0] = dataItems[size];

    size--;

    int index = 0;
    while (index < size)
    {
        if ((index * 2) + 1 <= size)
        {
            if (comparator(dataItems[(index * 2) + 1].getPriority(),dataItems[index].getPriority()))
            {
                DataType temp = dataItems[index];
                dataItems[index] = dataItems[(index * 2) + 1];
                dataItems[(index * 2) + 1] = temp;
                index = (index * 2) + 1;
            }
            else
            {
                return remElement;
            }
        }

        else if ((index * 2) + 2 <= size)
        {
            if (comparator(dataItems[index].getPriority(),dataItems[(index * 2) + 1].getPriority()) &&
                comparator(dataItems[index].getPriority(),
                    dataItems[(index * 2) + 2].getPriority()))
            {
                return remElement;
            }

            else if (comparator(dataItems[(index * 2) + 2].getPriority(), 
                dataItems[(index * 2) + 1].getPriority()))
            {
                DataType temp = dataItems[index];
                dataItems[index] = dataItems[(index * 2) + 2];
                dataItems[(index * 2) + 2] = temp;
                index = (index * 2) + 2;
            }
            
            else
            {
                DataType temp = dataItems[index];
                dataItems[index] = dataItems[index + 1];
                dataItems[(index * 2) + 1] = temp;
                index = (index * 2) + 1;
            }
        }
        
        else
        {
            return remElement;
        }
    }
    return remElement;
}

//--------------------------------------------------------------------

/// Precondition: Heap must exist along with the data items in it.\n
/// Postcondition: All the data items in the heap are removed.\n
/// Inputs: None.\n
/// Outputs: None.
template < typename DataType, typename KeyType, typename Comparator >
void Heap<DataType, KeyType, Comparator>::clear()
{
    size = 0;
    delete dataItems;
}

//--------------------------------------------------------------------

/// Precondition: Heap must exist.\n
/// Postcondition: If the heap is empty it returns true, otherwise it retuns false.\n
/// Inputs: None.\n
/// Outputs: Returns true if size == 0, otherwise it returns false.
template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType, KeyType, Comparator>::isEmpty() const
{
    if (size == 0)
    {
        return true;
    }
    else
        return false;
}

//--------------------------------------------------------------------

/// Precondition: Heap must exist.\n
/// Postcondition: If the heap is full, it returns true, otherwise it returns false.\n
/// Inputs: None.\n
/// Outputs: Returns true if size == maxSize, otherwise it returns false. 
template < typename DataType, typename KeyType, typename Comparator >
bool Heap<DataType, KeyType, Comparator>::isFull() const
{
    if (size == maxSize)
    {
        return true;
    }
    else
        return false;
    
}

//--------------------------------------------------------------------

#endif
