#include <iostream>
using namespace std;
class ADT
{
   public:
   //add an element into the ADT
      virtual void add(int element) = 0;
   //remove lowest element function
      virtual void removeSmallest() = 0;
};
