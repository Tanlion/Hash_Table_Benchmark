/*********************************************************************
File Name: main.cpp                                                  *
Assignment: Hash Tables Benchmark 2.                                 *
Author: Tian Liang.                                                  *
Course: CS5329, Fall 2019.                                           *
Instructor: Metsis Vangelis.                                         *
**********************************************************************/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

#include "LinkedList.h"
#include "RBTree.h"

// the same number of the array and the sorted array.

//**********************************************************************
// creatData: this function create a vector of random numbers.         *
//**********************************************************************
 void creatData(std::vector<int> &data, int min, int max) {
     for (int i = 0; i < data.size(); i++) {
         data[i] = rand() % (max - min + 1) + min ;
         //cout << data[i] << " ";
     }
 }


//*********************************************************************
// myHash: this function calculate the hash number based on key and   *
// slot size. To make sure the hash number would fall in slot.        *
//*********************************************************************
int myHash(int key, int slotSize) {
    return (key * key / 771 ) % slotSize;
}

//*********************************************************************
// This is the drive function of LinkedList class and RBTree class.   *
//*********************************************************************
int main(int argc, const char * argv[]) {

    srand((unsigned)time(NULL)); //Time seed.
    int min = 1000, max = 1010;
    
    int slotSize, index, loadSize;
    int loadFactor = 25;
    clock_t t_start, t_end;
    
    std::vector<int> key;   // the random number
    std::vector<int> target; //to search
    std::vector<LinkedList> hashtable1;
    std::vector<RBTree> hashtable2;
    
    
    //Used to print charts.
    string slotC[] = {"10000", "20000", "40000", "80000"};
    string loadF[] = {"0.25", "0.5", "0.75", "1"};
    string llrb[] = {"LL", "RBT"};
    
    const int ROW = sizeof(loadF) / sizeof(loadF[0]);
    const int COL = sizeof(slotC) / sizeof(slotC[0]);
    const int TYPE = sizeof(llrb) / sizeof(llrb[0]);
    int insertChart[ROW][COL][TYPE];
    int searchChart[ROW][COL][TYPE];

    
    //For different size of the hash table.
    for (slotSize = 10000; slotSize <= 80000; slotSize *= 2) {
        //Initialize size.
        hashtable1.resize(slotSize);
        hashtable2.resize(slotSize);
        
        // For different condition of load factor.
        for (loadFactor = 25; loadFactor <= 100; loadFactor += 25) {
            
            loadSize = (int) slotSize * loadFactor / 100;
            key.resize(loadSize, 0);
            target.resize(loadSize, 0);  //use to search
            creatData(key,min,max);
            creatData(target, min, max);
            int lf = (loadFactor / 25 - 1);     // For output chart
            int ss = (int) log2(slotSize / 10000); // // For output chart
            
            //for (int i = 0; i <1000; i++){
            //    cout << key[i] <<" ";
            //}
            //cout << endl;
            
            
            
            //Linked List Insertion.
            t_start = clock();
            for (int i = 0; i < key.size(); ++i) {
                index = myHash(key[i], loadSize);
                hashtable1[index].insertLL(key[i]);
            }
            t_end = clock();
            insertChart[lf][ss][0] = t_end - t_start;
            
            //Red-Black Tree Insertion.
            t_start = clock();
            for (int i = 0; i < key.size(); ++i) {
                index = myHash(key[i], loadSize);
                hashtable2[index].insertRB(key[i]);
            }
            t_end = clock();
            insertChart[lf][ss][1] = t_end - t_start;
            
            //Linked List Search.
            t_start = clock();
            for (int i = 0; i < target.size(); ++i) {
                index = myHash(target[i], loadSize);
                hashtable1[index].searchLL(key[i]);
            }
            t_end = clock();
            searchChart[lf][ss][0] = t_end - t_start;
            
            //Red-Black Tree Search.
            t_start = clock();
            for (int i = 0; i < target.size(); ++i) {
                index = myHash(target[i], loadSize);
                hashtable2[index].searchRB(key[i]);
            }
            t_end = clock();
            searchChart[lf][ss][1] = t_end - t_start;
            
        }
    }
    

//**********************************************************************
// Output insertion charts.                                            *
//**********************************************************************

    
    
    cout << endl << endl;
    cout << "Insertion chart: " << endl;
    cout << "\t" <<"  ";
    for (int i = 0; i < COL; i++) {
        cout << left << setw(20) << slotC[i] ;
    }
    cout << endl;
    cout << "\t" <<"  ";
    for (int i = 0; i < COL ; i++) {
        for (int k = 0; k < TYPE; k++) {
            cout << setw(10) << llrb[k];
        }
    }
    cout << endl;
    for (int i = 0; i < ROW; i++) {
        cout << setw(10) << loadF[i];
        for (int j = 0; j < COL; j++) {
            for (int k = 0; k < TYPE; k++) {
                cout << setw(10) << insertChart[i][j][k];
            }
        }
        cout << endl;
    }
    cout << endl << endl << endl;
   
    
//**********************************************************************
// Output research chart.                                              *
//**********************************************************************
    cout << "Search chart: " << endl;
    cout << "\t" <<"  ";
    for (int i = 0; i < COL; i++) {
        cout << left << setw(20) << slotC[i];
    }
    cout << endl;
    cout << "\t" <<"  ";
    for (int i = 0; i < COL ; i++) {
        for (int k = 0; k < TYPE; k++) {
            cout << setw(10) << llrb[k];
        }
    }
    cout <<  endl;
    for (int i = 0; i < ROW; i++) {
        cout << setw(10) << loadF[i];
        for (int j = 0; j < COL; j++) {
            for (int k = 0; k < TYPE; k++) {
                cout << setw(10) << searchChart[i][j][k];
            }
        }
        cout << endl;
    }
    cout << endl << endl << endl;

}

