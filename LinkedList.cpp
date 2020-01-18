/**********************************************************************
 File Name: LinkedList.cpp                                            *
 Assignment: Hash Tables Benchmark 2.                                 *
 Author: Tian Liang.                                                  *
 Course: CS5329, Fall 2019.                                           *
 Instructor: Metsis Vangelis.                                         *
 This file is the implement file of LinkedList class declaration.     *
 Each member function has been defined here.                          *
 *********************************************************************/

#include "LinkedList.h"
#include <stdio.h>
#include <vector>
using namespace std;

//**********************************************************************
// RBTree: Initialize the linked list's head to be NULL.               *
//**********************************************************************
LinkedList::LinkedList() {
    head = NULL;
}

//**********************************************************************
// insertLL: Member function to insert an integer to a linked list.    *
//**********************************************************************
void LinkedList::insertLL(int target) {
    Node *p;
    p = new Node;
    p->key = target;
    p->next = head;
    head = p;
    return;

}


//**********************************************************************
// searchLL: Member function to find a integer in a linked list.       *
// target: the number needed to be found.                                *
//**********************************************************************
int LinkedList::searchLL(int target){
    Node *p = head;
    while (p->key != target) {
        p = p->next;
    }
    if (p)
        return p->key;
    else
        return INT_MIN;
}
