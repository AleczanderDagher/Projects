// HashTable.cpp

#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP


#include <stdexcept>
#include <iostream>
#include "HashTable.h"
#include "show10.cpp"

using namespace std;

/// Precondition: Hash table must exist.\n
/// Postcondition: "Creates an empty hash table."\n
/// Inputs: an integer.\n
/// Outputs: None.
template<typename DataType, typename KeyType>
inline HashTable<DataType, KeyType>::HashTable(int initTableSize)
{
	tableSize = initTableSize;
	dataTable = new BSTree<DataType, KeyType>[initTableSize];
}

//-----------------------------------------------------------------------------

/// Precondition: Hash table must exist.\n
/// Postcondition: "Initializes the hash table to be equivalent to the HashTable parameter 'other'."\n
/// Inputs: HashTable object referenced to other.\n
/// Outputs: None.
template<typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& other)
{
	*this = other;
}

//-----------------------------------------------------------------------------

/// Precondition: Hash table must be valid.\n
/// Postcondition: "Sets the hash table to be equivalent to the 'other' HashTable object parameter
/// and returns a reference to this object."\n
/// Inputs: HashTable object referenced to other.\n
/// Outputs: This will return the reference to the 'other' object.
template<typename DataType, typename KeyType>
HashTable<DataType, KeyType>& HashTable<DataType, KeyType>::operator=(const HashTable& other)
{
	if (this = &other)
	{
		return *this;
	}
	if (!isEmpty())
	{
		clear();
	}
	copyTable(other);
	return *this;
}

//-----------------------------------------------------------------------------

/// Precondition: Hash table object exists.\n
/// Postcondition: "Frees the memory used to store a hash table."\n
/// Inputs: None.\n
/// Outputs: None.
template<typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable()
{
	clear();
}

//-----------------------------------------------------------------------------

/// Precondition: Hash table must exist and must not be full.\n
/// Postcondition: "Inserts newDataItem into the appropiate binary search tree. If data item with the same
/// key as newDataItem already exists in the binary search tree, then updates that data item with 
/// newDataItem, otherwise it inserts in the binary search tree."\n
/// Inputs: DataType object referenced to newDataItem.\n
/// Outputs: None.
template<typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem)
{
	int index = newDataItem.hash(newDataItem.getKey()) % tableSize;
	dataTable[index].insert(newDataItem);
}

//-----------------------------------------------------------------------------

/// Precondition: Hash table items must exist.\n
/// Postcondition: Removes the data item from the hash table.\n
/// Inputs: KeyType object referenced to deleteKey.\n
/// Outputs: Returns true if data item is found and deleted, and returns false if it doesn't find it. 
template<typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey)
{
	DataType temp;
	int index = temp.hash(deleteKey) % tableSize;
	return dataTable[index].remove(deleteKey);
}

//-----------------------------------------------------------------------------

/// Precondition: Hash table must exist.\n
/// Postcondition: The function will return true if the data item is found 
/// & if it doesn't, it returns false.\n
/// Inputs: KeyType object referenced to searchKey and DataType object referenced to returnItem.\n\n
/// Outputs: Returns true if data item is found, returns false if otherwise. Also returns data item found.
template<typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const
{
	int index = returnItem.hash(searchKey) % tableSize;
	return dataTable[index].retrieve(searchKey, returnItem);
}

//-----------------------------------------------------------------------------

/// Precondition: Hash table must exist.\n
/// Postcondition: Removes all data items in the hash table.\n
/// Inputs: None.\n
/// Outputs: None.
template<typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear()
{
	for (int i = 0; i < tableSize; i++)
	{
		dataTable[i].clear();
	}
}

//-----------------------------------------------------------------------------

/// Precondition: Hash table must exist.\n
/// Postcondition: "Returns true if hash table is empty, otherwise it returns false."\n
/// Inputs: None.\n
/// Outputs: "Returns true if hash table is empty, otherwise it returns false."
template<typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const
{
	for (int i = 0; i < tableSize; i++)
	{
		if (dataTable[i].isEmpty() == false)
		{
			return false;
		}
	}
	return true;
}

//-----------------------------------------------------------------------------

/// Precondition: Hash table must be valid.\n
/// Postcondition: "Sets the hash table to be equivalent to the 'source' HashTable object parameter.
/// Inputs: HashTable object referenced to source.\n
/// Outputs: None.
template<typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source)
{
	delete dataTable;
	dataTable = new BSTree<DataType, KeyType>[source.tableSize];
	for (int i = 0; i < source.tableSize; i++)
	{
		dataTable[i] = source.dataTable[i];
	}
}

#endif