#ifndef ROOTISHARRAYSTACK
#define ROOTISHARRAYSTACK
#include <iostream>
#include <math.h>
#include "ADT.h"
using namespace std;

class rootishArrayStack : public ADT
{
   public:
//constructor (starts with 1 block holding no elements)
     rootishArrayStack()
      {
         blocks = new int*[1];
         blocks[0] = new int[1];
         numBlocks = 1;
         numElements = 0;
         //ex: block[1][0] returns element in block 1 index 0
      }

//destructor
     ~rootishArrayStack()
     {
        for(int i = 0; i < numBlocks; i++)
        {
           delete[] blocks[i];
        }
        delete[] blocks;
     }

//adds element to the end of the arrayStack
      void add(int element)
      {
         //if The arrayStack is full, add another box to the end
         if(numBlocks*(numBlocks+1)/2 < numElements+1)
         {
            grow();
         }
         numElements++;
         set(element, numElements-1);
      }

//Finds and erases the smallest element in the arrayStack
      void removeSmallest()
      {
         int smallestIndex = 0;
         int smallestNum = -1;
         //check if arraystack is empty
         if(numElements > 0)
         {
            //loop and find smallest value
            for(int i = 0; i < numElements; i++)
            {
               int a = indexToBlock(i);
               int b = i - a*(a+1)/2;
               int currentNum = blocks[a][b];
               if(currentNum < smallestNum || smallestNum == -1)
               {
                  smallestNum = currentNum;
                  smallestIndex = i;
               }
           }
           erase(smallestIndex);
       }
       //if empty, tell user
       else
       {
            cout << "There are no elements to remove!" << endl;
         }
       }
//-----------------------------*---------------------------------
//functions that might be exculsive to RootArrayStack:

//converts given index into what block the index is found in
      int indexToBlock(int i)
      {
         double db = (-3.0 + sqrt(9 + 8*i)) / 2.0;
         int b = (int)ceil(db);
         return b;
      }

//add a block to the array
      void grow()
      {
      //create and setup temp array
         int** temp = new int*[numBlocks + 1];
     //set elements in temp to block elements
         for(int i = 0; i < numBlocks; i++)
         {
            temp[i] = blocks[i]; 
         }
        numBlocks++;
    //clean up and set blocks to temp; properly allocate new block
        delete[] blocks;
        blocks = temp;
        blocks[numBlocks-1] = new int[numBlocks];
      }

//set an element in the array at given position (an index) into given element
      void set(int element, int position)
      {
         if(position <= numElements)
         {
            int c = indexToBlock(position);
            int d = position - c*(c+1)/2;
            blocks[c][d] = element;
         }
      }

//print out all elements in array
      void printArray()
      {
         for(int i = 0; i < numElements; i++)
         {
            int b = indexToBlock(i);
            int j = i - b*(b+1)/2;
            cout << blocks[b][j] << endl;
         }
      }

//remove element at given index from array
      void erase(int index)
      {
         int replacingIndex;
         for(int i = index; i < numElements-1; i++)
         {
            replacingIndex = i+1;
            
            int currentc = indexToBlock(i);
            int currentd = i - currentc*(currentc+1)/2;
            
            int replacingc = indexToBlock(replacingIndex);
            int replacingd = replacingIndex - replacingc*(replacingc+1)/2;
            
            blocks[currentc][currentd] = blocks[replacingc][replacingd];
         }
         numElements--;
      }

   private:
   int **blocks;
   int numBlocks;
   int numElements;
};

#endif
