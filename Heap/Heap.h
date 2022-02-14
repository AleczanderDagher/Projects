//--------------------------------------------------------------------
//
//  Laboratory 11                                             Heap.h
//
//  Class declaration for the array implementation of the Heap ADataType
//
//--------------------------------------------------------------------

#ifndef HEAP_H
#define HEAP_H

#include <stdexcept>
#include <iostream>

using namespace std;

template < typename KeyType=int >
class Less {
  public:
    bool operator()(const KeyType &a, const KeyType &b) const { return a < b; }
};

template < typename DataType, typename KeyType=int, typename Comparator=Less<KeyType> >
class Heap
{
  public:

    static const int DEFAULT_MAX_HEAP_SIZE = 10;    // Default maximum heap size

    // Constructor
    //--------------------------------------------------------------------
    /// Default constructor + basic constr\n
/// Precondition: Heap must exist.\n
/// Postcondition:"Creates an empty heap and allocates enough memory for a heap containing 'maxNumber'
/// data items."\n
/// Inputs: An integer.\n
/// Outputs: None.
    Heap ( int maxNumber = DEFAULT_MAX_HEAP_SIZE ); 
    //--------------------------------------------------------------------
    /// Copy constructor\n
/// Precondition: Stack must exist.\n
/// Postcondition: "Initializes an object to be an equivalent copy of 'other'."\n
/// Inputs: Heap object referenced to other.\n
/// Outputs: None.
    Heap ( const Heap& other );		    
    //--------------------------------------------------------------------
    /// Overloaded assignment operator\n
/// Precondition: Must be a valid heap.\n
/// Postcondition: This will set the heap equivalent to the other heap object parameter.\n
/// Inputs: Heap object referenced to other.\n
/// Outputs: Returns the reference to the modified heap.
    Heap& operator= ( const Heap& other );  
    //--------------------------------------------------------------------
    /// Destructor\n
/// Precondition: Heap must exist.\n
/// Postcondition: Frees the memory used to destroy the heap.\n
/// Inputs: None.\n
/// Outputs: None.
    ~Heap ();

    // Heap manipulation operations
    //--------------------------------------------------------------------
    /// Insert a data item\n
/// Precondition: Heap must exist and must not be full.\n
/// Postcondition: Inserts the new data item into the heap.\n
/// Inputs: DataType object referenced to newDataItem.\n
/// Outputs: Returns "The list is full" if size == maxSize.
    void insert(const DataType& newDataItem);    
    //--------------------------------------------------------------------
    /// Remove max priority element\n
/// Precondition: Heap must exist and must not be empty.\n
/// Postcondition: Removes the highest priority data item and returns it.\n
/// Inputs: None.\n
/// Outputs: Returns "The list is empty" if size == 0, otherwise it returns removed item.   
    DataType remove ();  
    //--------------------------------------------------------------------
    /// Clear heap\n
/// Precondition: Heap must exist along with the data items in it.\n
/// Postcondition: All the data items in the heap are removed.\n
/// Inputs: None.\n
/// Outputs: None.  
    void clear ();                          
    //--------------------------------------------------------------------

    // Heap status operations
    //--------------------------------------------------------------------
    /// Heap is empty\n
/// Precondition: Heap must exist.\n
/// Postcondition: If the heap is empty it returns true, otherwise it retuns false.\n
/// Inputs: None.\n
/// Outputs: Returns true if size == 0, otherwise it returns false.
    bool isEmpty () const;                  
    //--------------------------------------------------------------------
    /// Heap is full\n
/// Precondition: Heap must exist.\n
/// Postcondition: If the heap is full, it returns true, otherwise it returns false.\n
/// Inputs: None.\n
/// Outputs: Returns true if size == maxSize, otherwise it returns false. 
    bool isFull () const;                   

    // Output the heap structure -- used in testing/debugging
    void showStructure () const;

  private:

    // Recursive helper of the showStructure() function
    void showSubtree ( int index, int level ) const;

    // Data members
    int maxSize,   // Maximum number of elements in the heap
        size;      // Actual number of elements in the heap
    DataType *dataItems; // Array containing the heap elements

    Comparator comparator;
};

#endif	//#ifndef HEAP_H
