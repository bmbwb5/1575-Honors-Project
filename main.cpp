//include here
#include <iostream>
#include "rootishArrayStack.h"
#include "binaryHeap.h"
using namespace std;

int main()
{
   rootishArrayStack dog;
   binaryHeap cat;
   string line;
   int count = 0;
  //use dog or cat for whichever data structure you want to compile into a program
   while (getline(cin, line))
   {
      count++;
      int x = stoi(line);
      cat.add(x);
   }
   for(int i = 0; i < count-1; i++)
   {
      cat.removeSmallest();
   }
}
