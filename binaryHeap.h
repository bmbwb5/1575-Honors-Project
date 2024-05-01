#ifndef BINARYHEAP
#define BINARYHEAP
#include <iostream>
using namespace std;

class binaryHeap : public ADT
{
  private:
    int num_elems;
    int max_elems;
    int *data;


   public:
//constructor
   binaryHeap()
   {
      num_elems = 0;
      max_elems = 3;
      data = new int[3];
   }

//destructor
   ~binaryHeap()
   {
      delete [] data;
      data = nullptr;
   }

//add a value to the heap
   void add(int value)
   {
      if(num_elems == max_elems)
      {
         reserve(max_elems*2);
      }
      
      //val is put in avaliable space
      data[num_elems] = value;
      int current = num_elems;
//shift up
      while(current > 0 && (data[current] < data[(current - 1) / 2]))
      {
         int temp = data[current];
         data[current] = data[(current - 1) / 2];
         data[(current - 1) / 2] = temp;
         current = (current - 1) / 2;
      }
      num_elems++;
   }

//Remove the smallest element (on top)
   void removeSmallest()
   {
      if(num_elems == 0)
      {
         cout << "heap is empty!" << endl;
         return;
      }
      
      data[0] = data[num_elems - 1];
      num_elems--;
      siftDown(0);
   }

   void printArray()
   {
      int c = 0;
      while(c < num_elems)
      {
         cout << data[c] << " ";
         c++;
      }
   }

//increase heap (array) size if too small
void reserve(int new_max_elems)
{
  //Allocate new storage array
   int* temp = new int[new_max_elems];
  //Perform a deep copy of the data
  for(int k=0; k < num_elems; k++)
    temp[k] = data[k];
  //De-allocate old storage array
  delete [] data;
  //Redirect data pointer
  data = temp;
  //Update capacity
  max_elems = new_max_elems;
}

   private:
//move a value into its correct position
   void siftDown(int start_index)
   {
      int current_index = start_index;
//make sure current_index isnt leaf
      while((2*current_index+1) < num_elems)
      {
         int smaller_child = 2*current_index + 1;
//determine smaller child
         if((smaller_child + 1 < num_elems) && data[smaller_child] > data[smaller_child+1])
            smaller_child++;
         
         if(data[current_index] > data[smaller_child])
         {
          //swap if parent is larger
            int temp = data[current_index];
            data[current_index] = data[smaller_child];
            data[smaller_child] = temp;
            current_index = smaller_child;
         }
         else
            return;
      }
   }

};

#endif
