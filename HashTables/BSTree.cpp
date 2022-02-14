//--------------------------------------------------------------------
//
//  Lab 9                                            
//  BSTree.cpp
//  
//
//--------------------------------------------------------------------

#ifndef BSTREE_CPP
#define BSTREE_CPP

#include <iostream>
#include "BSTree.h"

using namespace std;

//--------------------------------------------------------------------

//Precondition: When there is no BSTree nodes. 
//Postcondition: This will create a binary search tree node that contains nodeDataItem, left
//leftPtr, and rightPtr.\n
//Inputs: nodeDataItem (DataType object), leftPtr (BSTree object passed as pointer), and rightPtr
//(BSTree object passed as pointer).\n
//Outputs: Assigns dataItem to nodeDataItem, left to leftPtr, and right to rightPtr.
template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode(const DataType& node_data_item, BSTreeNode* left_pointer,
BSTreeNode* right_pointer)
{
    dataItem = node_data_item;
    left = left_pointer;
    right = right_pointer;
}

//--------------------------------------------------------------------

//Precondition: BSTree must be empty.\n
//Postcondition: Sets the BSTree.\n
//Inputs: None.\n
//Outputs: root is equal to NULL.
template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>::BSTree()
{
    root = NULL;
}

//--------------------------------------------------------------------

//Precondition: BSTree must exist.
//Postcondition: This will create an empty tree.\n
//Inputs: BSTree object referenced to source.
//Outputs: Makes the tree empty.
template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>::BSTree(const BSTree& source)
{
    root = NULL;
    copy_tree(source);
}

//--------------------------------------------------------------------

//Precondition: The source tree is a valid tree.\n
//Postcondition: This will create a deep copy of the sourceTree BSTree.\n
//Inputs: The sourceTree.
//Outputs: This will return the reference to the sourceTree.
template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>:: operator= (const BSTree& source_tree)
{
    if (this != &source_tree)
    {
        clear();
        copy_tree(source_tree);
        return *this;
    }
    else
    {
        return *this;
    }
}

//--------------------------------------------------------------------

//Precondition: BSTree must exist.\n
//Postcondition: This function will set a tree equal to the sourceTree.\n
//Inputs: sourceTree, which is a BSTree object.\n
//Outputs: None.
template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::copy_tree(const BSTree<DataType, KeyType>& source_tree)
{
    copy_tree_helper(root, source_tree.root);
}

//--------------------------------------------------------------------

//Precondition: 2 BSTreeNode objects must exist.\n
//Postcondition: This function makes a tree equal to another tree.\n
//Inputs: p and sourcePtr, which represent 2 BSTreeNode objects.\n
//Outputs: None.
template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::copy_tree_helper(BSTreeNode*& n, const BSTreeNode* source_pointer)
{
    if (n != 0) {
        n = new BSTreeNode(source_pointer->dataItem, 0, 0);
        copy_tree_helper(n->left, source_pointer->left);
        copy_tree_helper(n->right, source_pointer->right);
    }
}

//--------------------------------------------------------------------

//Precondition: When a BSTree object exists.\n
//Postcondition: This will free the memory that is used by the tree.\n
//Inputs: None.\n
//Outputs: None
template < typename DataType, typename KeyType >
BSTree<DataType, KeyType>:: ~BSTree()
{
    clear();
}

//--------------------------------------------------------------------

//Precondition: BSTree object must exist.\n
//Postcondition: This function inserts a new node into the tree.\n
//Inputs: newDataItem, which represents any DataType object.\n
//Outputs: None.
template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::insert(const DataType& new_data_item)
{
    insert_helper(root, new_data_item);
}

//--------------------------------------------------------------------

//Precondition: BSTree & DataType object must exist.\n
//Postcondition: This function inserts newDataItem in the subtree pointed to by p.\n
//Inputs: p, which represents a BSTreeNode object passed as a reference & 
//newDataItem, which represents a DataType object that is passed by a reference.\n
//Outputs: None.
template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::insert_helper(BSTreeNode*& n, const DataType& new_data_item)
{
    if (n == 0) // Insert
        n = new BSTreeNode(new_data_item, 0, 0);
    else if (new_data_item.getKey() < n->dataItem.getKey())
        insert_helper(n->left, new_data_item);
    else if (new_data_item.getKey() > n->dataItem.getKey())
        insert_helper(n->right, new_data_item);
    else
        n->dataItem = new_data_item;
}

//--------------------------------------------------------------------

//Precondition: BSTree object must exist.\n
//Postcondition: The function will return true if the data item is found & if it doesn't, it returns false.
//Inputs: searchKey, which represents a reference to a KeyType object & searchDataItem, which represents
//a reference to a DataType object.\n
//Outputs: Returns true if data item is found, returns false if otherwise.
template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::retrieve(const KeyType& search_key, DataType& search_data_item) const
{
    return retrieve_helper(root, search_key, search_data_item);
}

//--------------------------------------------------------------------

//Precondition: BSTree object has to exist.\n
//Postcondition: The function will return true if the data item is found & if it doesn't, it returns false.\n
//Inputs: p (represents a reference to object of of type BSTreeNode), searchKey (represents reference to 
// object of type KeyType), and searchDataItem (represents a reference to object of of type DataType).\n
//Outputs: Returns true if data item is found, returns false if otherwise.
template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::retrieve_helper(BSTreeNode* n, const KeyType& search_key,
    DataType& search_data_item) const
{
    bool result;

    if (n == 0)
    {
        result = false;
    }
    else if (search_key < n->dataItem.getKey())
    {
        result = retrieve_helper(n->left, search_key, search_data_item);
    }
    else if (search_key > n->dataItem.getKey())
    {
        result = retrieve_helper(n->right, search_key, search_data_item);
    }
    else
    {
        search_data_item = n->dataItem;
        result = true;
    }

    return result;
}

//--------------------------------------------------------------------

//Precondition: When a BSTree object exists.\n
//Postcondition: This will delete the node and update the BSTree object.\n
//Inputs: deleteKeym, which is a reference to object of type KeyType.\n
//Outputs: Returns true if data item is found and deleted, and returns false if it doesn't find it.
template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::remove(const KeyType& delete_key)
{
    return remove_helper(root, delete_key);
}

//--------------------------------------------------------------------

//Precondition: When a BSTree object exists.\n
//Postcondition: This will delete the node and update the BSTree object.\n
//Inputs: deleteKey, which is a reference to object of type KeyType. And p, 
//which represents a BSTreeNode object passed as a reference.\n
//Outputs: Returns true if data item is found and deleted, and returns false if it doesn't find it.
template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::remove_helper(BSTreeNode*& n, const KeyType& delete_key)
{
    BSTreeNode* delete_pointer; 
    int result;                 

    if (n == 0)
        result = false;                           
    else if (delete_key < n->dataItem.getKey())
        result = remove_helper(n->left, delete_key);
    else if (delete_key > n->dataItem.getKey())
        result = remove_helper(n->right, delete_key);
    else
    {                                            
        delete_pointer = n;
        if (n->left == 0)
        {
            n = n->right;                    
            delete delete_pointer;
        }
        else if (n->right == 0)
        {
            n = n->left;                     
            delete delete_pointer;
        }
        else
            
        {
            BSTreeNode* temp = n->left;
            while (temp->right) 
            {
                temp = temp->right;
            }
            n->dataItem = temp->dataItem;
            remove_helper(n->left, temp->dataItem.getKey());

        }
        result = true;
    }

    return result;
}

//--------------------------------------------------------------------

//Precondition: BSTree object has to exist.\n
//Postcondition: This function prints out the keys in the tree in ascending order.
//Inputs: None.\n
//Outputs: Prints out the keys in a tree in ascending order.
template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::writeKeys() const
{
    write_keys_helper(root);
    cout << endl;
}

//--------------------------------------------------------------------

//Precondition: BSTree object must exist.\n
//Postcondition: This function outputs the keys in the subtree pointed to by BSTreeNode* p.\n
//Inputs: p, which represents a pointer of a BSTree object.\n
//Outputs: None.
template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::write_keys_helper(BSTreeNode* n) const
{
    if (n != 0)
    {
        write_keys_helper(n->left);
        cout << n->dataItem.getKey() << " ";
        write_keys_helper(n->right);
    }
}

//--------------------------------------------------------------------

//Precondition: When a BSTree exists.\n
//Postcondition: This will remove all the nodes from the tree.\n
//Inputs: None.\n
//Outputs: None.
template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::clear()
{
    clear_helper(root);
    root = 0;
}

//--------------------------------------------------------------------

//Precondition: When a BSTree exists.\n
//Postcondition: This will clear the subtree pointed to by p.\n
//Inputs: "p" (represents a pointer of a BSTree object type).\n
//Outputs: Deletes the subtree pointed to by p.
template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::clear_helper(BSTreeNode* n)
{
    if (n != 0)
    {
        clear_helper(n->left);
        clear_helper(n->right);
        delete n;
    }
}

//--------------------------------------------------------------------

//Precondition: If BSTree exists.\n
//Postcondition: This function returns true if a tree is empty. Returns false if otherwise.\n
//Inputs: None
//Outputs: Returns root to 0.
template < typename DataType, typename KeyType >
bool BSTree<DataType, KeyType>::isEmpty() const
{
    return root == 0;
}

//--------------------------------------------------------------------

//Precondition: BSTree must exist.
//Postcondition: This function prints out the keys in the binary search tree.
//Inputs: None.\n
//Outputs: This outputs the keys in the BSTree.
template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::showStructure() const
{
    if (root == 0)
        cout << "Tree is empty." << endl;
    else
    {
        cout << endl;
        show_helper(root, 1);
        cout << endl;
    }
}

//--------------------------------------------------------------------

//Precondition: BSTree must exist.\n
//Postcondition: This function prints out the keys in the binary search tree.\n
//Inputs: "p" (represents a pointer of a BSTree object type) & level (integer).\n
//Outputs: Prints out the subtree.
template < typename DataType, typename KeyType >
void BSTree<DataType, KeyType>::show_helper(BSTreeNode* n, int level) const
{
    if (n != 0)
    {
        show_helper(n->right, level + 1);         
        for (int i = 0; i < level; i++)    
            cout << "\t";
        cout << " " << n->dataItem.getKey();   
        if ((n->left != 0) &&          
            (n->right != 0))
            cout << "<";
        else if (n->right != 0)
            cout << "/";
        else if (n->left != 0)
            cout << "\\";
        cout << endl;
        show_helper(n->left, level + 1);          
    }
}

//--------------------------------------------------------------------

//Precondition: BSTree has to exist.\n
//Postcondition: This function returns the height of the BSTree.\n
//Inputs: None.\n
//Outputs: Returns the height of the BSTree as an integer.
template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::getHeight() const
{
    return get_height_helper(root);
}

//--------------------------------------------------------------------

//Precondition: BSTree has to exist.\n
//Postcondition: This function returns the height of the BSTree that is pointed to by p.\n
//Inputs: "n", which represents a pointer of a BSTree object type.\n
//Outputs: Prints out the height of the subtree pointed to by p.
template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::get_height_helper(BSTreeNode* n) const
{
    int length_of_left, length_of_right, result;   

    if (n == 0)
        result = 0;                    
    else
    {
        length_of_left = get_height_helper(n->left) + 1;    
        length_of_right = get_height_helper(n->right) + 1;   
        if (length_of_left >= length_of_right)                  
            result = length_of_left;
        else
            result = length_of_right;
    }

    return result;
}
//--------------------------------------------------------------------

//Precondition: BSTree has to exist.\n
//Postcondition: This function will return the count of the subtree.\n
//Inputs: None.
//Outputs: Prints out the # of nodes in the tree.
template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::getCount() const
{
    return get_count_helper(root);
}

//--------------------------------------------------------------------

//Precondition: BSTree has to exist.\n
//Postcondition: This function will return the count of the subtree that is pointed to by p.\n
//Inputs: "n", which represents a pointer of a BSTree object type.\n
//Outputs: Returns an integer that is incremented by 1. 
template < typename DataType, typename KeyType >
int BSTree<DataType, KeyType>::get_count_helper(BSTreeNode* n) const
{
    if (n == 0) 
    {
        return 0;
    }

    return get_count_helper(n->left) + get_count_helper(n->right) + 1;
}


#endif	
