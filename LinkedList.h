/**********************************************************************
 File Name: LinkedList.h                                              *
 Assignment: Hash Tables Benchmark 2.                                 *
 Author: Tian Liang.                                                  *
 Course: CS5329, Fall 2019.                                           *
 Instructor: Metsis Vangelis.                                         *
 This file is the header file of LinkedList class declaration.        *
**********************************************************************/

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include <vector>
using namespace std;


class LinkedList {
    
public:
    struct Node{
        int key;
        Node *next;
    };
    
    Node* head;
    LinkedList();
    void insertLL(int);
    int searchLL(int);

};

#endif /* LinkedList_h */
