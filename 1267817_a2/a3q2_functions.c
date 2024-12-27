#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "a3q2_header.h"

/*
 * The downHeap function performs the downheap algorithm.
 * The key at the passed position is swapped with the key of it's child with the largest value.
 * If the key is smaller, than both of it's children's keys then no swap happens.
 * After swap, the downHeap is called again to the new position of the swapped key and it terminates when it's value is smaller than both children.
*/
void downHeap(int key[20], int pos, int array[20][10]){

    //If no children
    if(isParent(pos) == false){
        return;
    }

    //If no right child
    if((2 * pos + 2) >= 20){
        if(key[pos] < key[2 * pos + 1]){
            swap(pos, 2 * pos + 1, key, array);
        }
        //Call with the new position
        downHeap(key, 2 * pos + 1, array);
        return;
    }

    //If the key is smaller than at least one child
    if(key[pos] < key[2 * pos + 1] || key[pos] < key[2 * pos + 2]){
        //If the left child is the largest
        if(key[2 * pos + 1] > key[2 * pos + 2]){
            swap(pos, 2 * pos + 1, key, array);
            downHeap(key, 2 * pos + 1, array);
        }
        //If the right child is the largest
        else{
            swap(pos, 2 * pos + 2, key, array);
            downHeap(key, 2 * pos + 2, array);
        }
    }

}

// The isParent function returns true if the passed position has a child or false if there's no child
bool isParent(int keyPos){
    //If at least the left child exists
    if((2 * keyPos + 1) < 20){
        return true;
    }

    return false;

}

// The swap function swaps 2 rows in the 2D array and the key array. It receives the position of the 2 rows to be swapped, the key array, and the 2D array in its arguements.
void swap(int key1Pos, int key2Pos, int key[20], int array[20][10]){
    int tempArray[10];
    for(int i=0; i < 10; i++){
        tempArray[i] = array[key1Pos][i];
    }
    int tempKey = key[key1Pos];

    key[key1Pos] = key[key2Pos];
    for(int i=0; i < 10; i++){
        array[key1Pos][i] = array[key2Pos][i];
    }

    key[key2Pos] = tempKey;
    for(int i=0; i < 10; i++){
        array[key2Pos][i] = tempArray[i];
    }

}
