// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <stdexcept>
#include <iostream>

using namespace std;

#include "BSTree.cpp"

template <typename DataType, typename KeyType>
class HashTable {
  public:
/// Precondition: Hash table must exist.\n
/// Postcondition: "Creates an empty hash table."\n
/// Inputs: an integer.\n
/// Outputs: None.  
    HashTable(int initTableSize);
    //-----------------------------------------------------------------------------
/// Precondition: Hash table must exist.\n
/// Postcondition: "Initializes the hash table to be equivalent to the HashTable parameter 'other'."\n
/// Inputs: HashTable object referenced to other.\n
/// Outputs: None.
    HashTable(const HashTable& other);
    //-----------------------------------------------------------------------------
/// Precondition: Hash table must be valid.\n
/// Postcondition: "Sets the hash table to be equivalent to the 'other' HashTable object parameter
/// and returns a reference to this object."\n
/// Inputs: HashTable object referenced to other.\n
/// Outputs: This will return the reference to the 'other' object.
    HashTable& operator=(const HashTable& other);
    //-----------------------------------------------------------------------------
/// Precondition: Hash table object exists.\n
/// Postcondition: "Frees the memory used to store a hash table."\n
/// Inputs: None.\n
/// Outputs: None.
    ~HashTable();
    //-----------------------------------------------------------------------------
/// Precondition: Hash table must exist and must not be full.\n
/// Postcondition: "Inserts newDataItem into the appropiate binary search tree. If data item with the same
/// key as newDataItem already exists in the binary search tree, then updates that data item with 
/// newDataItem, otherwise it inserts in the binary search tree."\n
/// Inputs: DataType object referenced to newDataItem.\n
/// Outputs: None.
    void insert(const DataType& newDataItem);
    //-----------------------------------------------------------------------------
/// Precondition: Hash table items must exist.\n
/// Postcondition: Removes the data item from the hash table.\n
/// Inputs: KeyType object referenced to deleteKey.\n
/// Outputs: Returns true if data item is found and deleted, and returns false if it doesn't find it.
    bool remove(const KeyType& deleteKey);
    //-----------------------------------------------------------------------------
/// Precondition: Hash table must exist.\n
/// Postcondition: The function will return true if the data item is found 
/// & if it doesn't, it returns false.\n
/// Inputs: KeyType object referenced to searchKey and DataType object referenced to returnItem.\n\n
/// Outputs: Returns true if data item is found, returns false if otherwise. Also returns data item found.
    bool retrieve(const KeyType& searchKey, DataType& returnItem) const;
    //-----------------------------------------------------------------------------
/// Precondition: Hash table must exist.\n
/// Postcondition: Removes all data items in the hash table.\n
/// Inputs: None.\n
/// Outputs: None.
    void clear();
    //-----------------------------------------------------------------------------
/// Precondition: Hash table must exist.\n
/// Postcondition: "Returns true if hash table is empty, otherwise it returns false."\n
/// Inputs: None.\n
/// Outputs: "Returns true if hash table is empty, otherwise it returns false."
    bool isEmpty() const;
    //-----------------------------------------------------------------------------

    void showStructure() const;
    //-----------------------------------------------------------------------------

    //-----------------------------------------------------------------------------
  private:
/// Precondition: Hash table must be valid.\n
/// Postcondition: "Sets the hash table to be equivalent to the 'source' HashTable object parameter.
/// Inputs: HashTable object referenced to source.\n
/// Outputs: None.
    void copyTable(const HashTable& source);

    int tableSize;
    BSTree<DataType, KeyType>* dataTable;
};

#endif	// ifndef HASHTABLE_H
