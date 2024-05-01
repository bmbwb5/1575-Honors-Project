#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
   for(int i = 1; i <= stoi(argv[1]); i++)
   {
      int x = i;
      cout << x << endl;
   }
}

//currently prints out numbers in increasing value from 1 to user input
//if you want to do decreasing inputs, change the for loop to (i = stoi(argv[1]); i <= 1; i++)
//if you want random inputs, change "int x = i" to "int x = rand() % (num);
