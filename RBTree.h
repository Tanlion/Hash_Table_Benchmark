/**********************************************************************
 File Name: RBTree.h                                                  *
 Assignment: Hash Tables Benchmark 2.                                 *
 Author: Tian Liang.                                                  *
 Course: CS5329, Fall 2019.                                           *
 Instructor: Metsis Vangelis.                                         *
 This file is the header file of RBTree class declaration.            *
 *********************************************************************/

#ifndef RBTree_h
#define RBTree_h

#include <stdio.h>


class RBTree {

public:

enum COLOR{RED, BLACK};
    
    struct TreeNode{
        int key;
        TreeNode *left, *right, *parent;
        COLOR color;
        
        TreeNode(int k, COLOR c):
            key(k), color(c),parent(NULL), left(NULL), right(NULL)
        {}
        
        TreeNode(int k, COLOR c, TreeNode *parent, TreeNode *left, TreeNode *right):
            key(k), color(c),parent(parent), left(left), right(right)
        {}
        
        
    };
 
    TreeNode *root;
 
    RBTree();
    void leftRotate(TreeNode*);
    void rightRotate(TreeNode*);
    void insertFixup(TreeNode*,TreeNode*);
    void insertRB(TreeNode*, TreeNode*);
    void insertRB(int);
    TreeNode* searchRB(int);
};
#endif /* RBTree_h */
