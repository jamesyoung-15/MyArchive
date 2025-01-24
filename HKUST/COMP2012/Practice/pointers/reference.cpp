#include <iostream>
using namespace std;

int main ()
{
    int arr[] {1,3,5,7};
    for(int &k : arr)
    {
        k++;
        cout<< k <<endl;
    }
    for(int k : arr)
    {
        cout<< k <<endl;
    }
  return 0;
}