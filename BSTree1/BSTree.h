//--------------------------------------------------------------------
//
//  Laboratory 9                                    BSTree.h
//
//  Class declarations for the linked implementation of the Binary
//  Search Tree ADT -- including the recursive helpers of the
//  public member functions
//
//--------------------------------------------------------------------

#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include <iostream>

using namespace std;

template < typename DataType, class KeyType >    // DataType : tree data item
class BSTree                                     // KeyType : key field
{
public:

    // "Constructors."
   //-------------------------------------------------------------------------------------------
    // "Default constructor."\n
    //Precondition: BSTree must be empty.\n
    //Postcondition: Sets the BSTree.\n
    //Inputs: None.\n
    //Outputs: root is equal to NULL.
    BSTree();
    //-------------------------------------------------------------------------------------------
    // "Copy constructor."\n
    //Precondition: BSTree must exist.
    //Postcondition: This will create an empty tree.\n
    //Inputs: BSTree object referenced to source.
    //Outputs: Makes the tree empty.
    BSTree(const BSTree<DataType, KeyType>& other);   
    //-------------------------------------------------------------------------------------------
    // "Overloaded assignment operator."
    //Precondition: The source tree is a valid tree.\n
    //Postcondition: This will create a deep copy of the sourceTree BSTree.\n
    //Inputs: The sourceTree.
    //Outputs: This will return the reference to the sourceTree.
    BSTree& operator= (const BSTree<DataType, KeyType>& other);
    //-------------------------------------------------------------------------------------------
    // "Destructor."\n
    //Precondition: When a BSTree object exists.\n
    //Postcondition: This will free the memory that is used by the tree.\n
    //Inputs: None.\n
    //Outputs: None
    ~BSTree();
    //-------------------------------------------------------------------------------------------
    // "Binary search tree manipulation operations."
    //-------------------------------------------------------------------------------------------
    // "Insert data item."\n
    //Precondition: BSTree object must exist.\n
    //Postcondition: This function inserts a new node into the tree.\n
    //Inputs: newDataItem, which represents any DataType object.\n
    //Outputs: None.
    void insert(const DataType& new_data_item);
    //-------------------------------------------------------------------------------------------
    // "Retrieve data item."\n
    //Precondition: BSTree object must exist.\n
    //Postcondition: The function will return true if the data item is found & if it doesn't, it returns false.
    //Inputs: searchKey, which represents a reference to a KeyType object & searchDataItem, which represents
    //a reference to a DataType object.\n
    //Outputs: Returns true if data item is found, returns false if otherwise.
    bool retrieve(const KeyType& search_key, DataType& search_data_item) const;
    //-------------------------------------------------------------------------------------------
    // "Remove data item."\n
    //Precondition: When a BSTree object exists.\n
    //Postcondition: This will delete the node and update the BSTree object.\n
    //Inputs: deleteKey, which is a reference to object of type KeyType.\n
    //Outputs: Returns true if data item is found and deleted, and returns false if it doesn't find it.
    bool remove(const KeyType& delete_key);
    //-------------------------------------------------------------------------------------------
    // "Output keys in ascending order."
    //Precondition: BSTree object has to exist.\n
    //Postcondition: This function prints out the keys in the tree in ascending order.
    //Inputs: None.\n
    //Outputs: Prints out the keys in a tree in ascending order.
    void writeKeys() const;   
    //-------------------------------------------------------------------------------------------
    // "Clear tree."\n
    //Precondition: When a BSTree exists.\n
    //Postcondition: This will remove all the nodes from the tree.\n
    //Inputs: None.\n
    //Outputs: None.
    void clear();                                
    //-------------------------------------------------------------------------------------------
    // Binary search tree status operations
    //-------------------------------------------------------------------------------------------
    // "Tree is empty."\n
    //Precondition: If BSTree exists.\n
    //Postcondition: This function returns true if a tree is empty. Returns false if otherwise.\n
    //Inputs: None
    //Outputs: Returns root to 0.
    bool isEmpty() const;                        
    //-------------------------------------------------------------------------------------------
    // "Output the tree structure -- used in testing/debugging."
    //Precondition: BSTree must exist.
    //Postcondition: This function prints out the keys in the binary search tree.
    //Inputs: None.\n
    //Outputs: This outputs the keys in the BSTree.
    void showStructure() const;
    //-------------------------------------------------------------------------------------------
    // "In-lab operations."
    //-------------------------------------------------------------------------------------------
    // "Height of tree."
    //Precondition: BSTree has to exist.\n
    //Postcondition: This function returns the height of the BSTree.\n
    //Inputs: None.\n
    //Outputs: Returns the height of the BSTree as an integer.
    int getHeight() const;
    //-------------------------------------------------------------------------------------------
    // "Number of nodes in tree."
    //Precondition: BSTree has to exist.\n
    //Postcondition: This function will return the count of the subtree.\n
    //Inputs: None.
    //Outputs: Prints out the # of nodes in the tree.
    int getCount() const;			  
    //-------------------------------------------------------------------------------------------
protected:

    class BSTreeNode                  // "Inner class: facilitator for the BSTree class"
    {
    public:

        // "Constructor."\n
        //Precondition: When there is no BSTree nodes. 
        //Postcondition: This will create a binary search tree node that contains nodeDataItem, left
        //leftPtr, and rightPtr.\n
        //Inputs: nodeDataItem (DataType object), leftPtr (BSTree object passed as pointer), and rightPtr
        //(BSTree object passed as pointer).\n
        //Outputs: Assigns dataItem to nodeDataItem, left to leftPtr, and right to rightPtr.
        BSTreeNode(const DataType& node_data_item, BSTreeNode* left_pointer, BSTreeNode* right_pointer);
       
        // Data members
        DataType dataItem;         // "Binary search tree data item"
        BSTreeNode* left,    // "Pointer to the left child"
            * right;   // "Pointer to the right child"

    };

    
    // "Recursive helpers for the public member functions."
    //-------------------------------------------------------------------------------------------
    //Precondition: When a BSTree object exists.\n
    //Postcondition: This will delete the node and update the BSTree object.\n
    //Inputs: deleteKey, which is a reference to object of type KeyType. And p, 
    //which represents a BSTreeNode object passed as a reference.\n
    //Outputs: Returns true if data item is found and deleted, and returns false if it doesn't find it.
    bool remove_helper(BSTreeNode*& n, const KeyType& delete_key);
    //-------------------------------------------------------------------------------------------
    //Precondition: When a BSTree exists.\n
    //Postcondition: This will clear the subtree pointed to by p.\n
    //Inputs: "p" (represents a pointer of a BSTree object type).\n
    //Outputs: Deletes the subtree pointed to by p.
    void clear_helper(BSTreeNode* n);
    //-------------------------------------------------------------------------------------------
    //Precondition: BSTree object must exist.\n
    //Postcondition: The function will return true if the data item is found & if it doesn't, it returns false.
    //Inputs: searchKey, which represents a reference to a KeyType object & searchDataItem, which represents
    //a reference to a DataType object.\n
    //Outputs: Returns true if data item is found, returns false if otherwise.
    bool retrieve_helper(BSTreeNode* n, const KeyType& search_key, DataType& search_data_item) const;
    //-------------------------------------------------------------------------------------------
    //Precondition: BSTree has to exist.\n
    //Postcondition: This function returns the height of the BSTree that is pointed to by p.\n
    //Inputs: "p", which represents a pointer of a BSTree object type.\n
    //Outputs: Prints out the height of the subtree pointed to by p.
    int  get_height_helper(BSTreeNode* n) const;
    //-------------------------------------------------------------------------------------------
    //Precondition: BSTree has to exist.\n
    //Postcondition: This function will return the count of the subtree that is pointed to by p.\n
    //Inputs: "p", which represents a pointer of a BSTree object type.\n
    //Outputs: Returns an integer that is incremented by 1. 
    int  get_count_helper(BSTreeNode* n) const;
    //-------------------------------------------------------------------------------------------
    //Precondition: BSTree must exist.\n
    //Postcondition: This function will set a tree equal to the sourceTree.\n
    //Inputs: sourceTree, which is a BSTree object.\n
    //Outputs: None.
    void copy_tree(const BSTree<DataType, KeyType>& other_tree);
    //-------------------------------------------------------------------------------------------
    //Precondition: BSTree must exist.\n
    //Postcondition: This function prints out the keys in the binary search tree.\n
    //Inputs: "p" (represents a pointer of a BSTree object type) & level (integer).\n
    //Outputs: Prints out the subtree.
    void show_helper(BSTreeNode* n, int level) const;
    //-------------------------------------------------------------------------------------------
    //Precondition: BSTree & DataType object must exist.\n
    //Postcondition: This function inserts newDataItem in the subtree pointed to by p.\n
    //Inputs: p, which represents a BSTreeNode object passed as a reference & 
    //newDataItem, which represents a DataType object that is passed by a reference.\n
    //Outputs: None.
    void insert_helper(BSTreeNode*& n, const DataType& new_data_item);
    //-------------------------------------------------------------------------------------------
    //Precondition: 2 BSTreeNode objects must exist.\n
    //Postcondition: This function makes a tree equal to another tree.\n
    //Inputs: p and sourcePtr, which represent 2 BSTreeNode objects.\n
    //Outputs: None.
    void copy_tree_helper(BSTreeNode*& n, const BSTreeNode* other_pointer);
    //-------------------------------------------------------------------------------------------
    //Precondition: BSTree object must exist.\n
    //Postcondition: This function outputs the keys in the subtree pointed to by BSTreeNode* p.\n
    //Inputs: p, which represents a pointer of a BSTree object.\n
    //Outputs: None.
    void write_keys_helper(BSTreeNode* n) const;
    //-------------------------------------------------------------------------------------------
    // "Data member."
    // "Pointer to the root node."
    BSTreeNode* root;   
};

#endif	// define BSTREE_H


