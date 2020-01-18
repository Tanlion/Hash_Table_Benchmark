/**********************************************************************
 File Name: RBTree.cpp                                                *
 Assignment: Hash Tables Benchmark 2.                                 *
 Author: Tian Liang.                                                  *
 Course: CS5329, Fall 2019.                                           *
 Instructor: Metsis Vangelis.                                         *
 This file is the implement file of RBTree class declaration.         *
 Each member function has been defined here.                          *
 *********************************************************************/

#include "RBTree.h"

//**********************************************************************
// RBTree: Initialize the Red-Black tree root to be NULL.              *
//**********************************************************************
RBTree::RBTree() {
    root = NULL;
}


//**********************************************************************
// leftRotate: To rotate TreeNode y to its left direction.             *
//**********************************************************************
void RBTree::leftRotate(TreeNode* x){
    //Set x's right child is y
    TreeNode* y = x->right;
    
    //Set left child. Set x point to y.left, y.left to x.
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    
    //Set x's parent and y's parent.
    y->parent = x->parent;
    if (x->parent == NULL) { // If x is the root.
        root = y;
    }
    else if (x == x->parent->left) { // If x is the left child.
        x->parent->left = y;
    }
    else {                           // If x is the right child.
        x->parent->right = y;
    }
    
    //Set x as y's left child, y as x's parent.
    y->left =x;
    x->parent = y;

}


//**********************************************************************
// rightRotate: To rotate TreeNode y to its right direction.           *
//**********************************************************************
void RBTree::rightRotate(TreeNode* y){
    
    TreeNode* x = y->left;
    
    //Set right child
    y->left = x->right;
    if (x->right != NULL) {
        x->right->parent = y;
    }
    
    //Set parent
    x->parent = y->parent;
    if (y->parent == NULL) {
        root = x;
    }
    else if (y == y->parent->right) {
        y->parent->right = x;
    }
    else {
        y->parent->left = x;
    }
    
    x->right = y;
    y->parent = x;
 
}


//**********************************************************************
// insertFixup: Member function to fix up the color of inserted node's *
// parent, uncle and grand parent.                                     *
// z: The insert TreeNode.                                             *
//**********************************************************************
void RBTree::insertFixup(TreeNode* root, TreeNode* z){
    
    while (z->parent && z->parent->color == RED ) {   ///****
        //If z-parent is z->grand 's left child.
        if (z->parent == z->parent->parent->left) {
            TreeNode* y = z->parent->parent->right;
            
            //Case 1: Red uncle y.
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                //Case 2: Black uncle y and  z is a right child.
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                // Case 3: Black uncle y and z is a left child.
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        }
        
        //If z-parent is z->grand 's right child.
        else {
            TreeNode* y = z->parent->parent->right;
            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if ( z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        } //else
    } //while
    root->color = BLACK;
}



//**********************************************************************
// insertRB: Member function to insert a TreeNode z to a Red-Black tree*
//**********************************************************************
void RBTree::insertRB(TreeNode* root, TreeNode* z){
    TreeNode* y = NULL;
    TreeNode* x = root;
    
    //To traverse the tree, if < to left part, else to right.
    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    
    z->parent = y;
    if (y == NULL) {
        root = z;
    }
    else if (z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
    z->color = RED;
    
    insertFixup(root,z);   

}



//**********************************************************************
// insertRB: Overload of the insertRB(TreeNode*, TreeNode*) function.  *
// In this overload, directly insert a integer throught new a TreeNode *
// and call insertRB(TreeNode*, TreeNode*) function.                   *
//**********************************************************************
void RBTree::insertRB(int target) {
    TreeNode *z = NULL;
    
    //If create a new node unsuccessfully, then return.
    if ( (z = new TreeNode(target, BLACK, NULL, NULL, NULL)) == NULL)
        return;
    
    insertRB(root, z);
}



//**********************************************************************
// searchRB: Member function to find a integer in Red-Black tree.      *
// target: the number needed to be found.                              *
//**********************************************************************
RBTree::TreeNode* RBTree::searchRB(int target){
    
    TreeNode* indexNode = root; // use indexNode to traverse current tree.
    while (indexNode != NULL) {
        //current key less than target, go to right part to find target.
        if (indexNode->key < target) {
            indexNode = indexNode->right;
        }
        else if (indexNode->key > target) {
            indexNode = indexNode->left;
        }
        else {
            break;
        }
    }
    return indexNode;
}


