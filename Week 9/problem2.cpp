#include <iostream>
using namespace std;

/*  
    Suppose that intArray is an array of integers, and length specifies the number of elements in intArray.
    Also suppose that low and high are two integers such that 0 <= low < length, 0 <= high < length, and low < high.
    That is, low and high are two indicies in intArray. Write a recursive definition that reverses the elements
    in intArray between low and high. (2, 3, 4, 6)
*/

void reverseArray(int array[], const int LENGTH, int low, int high);

int main()
{
    const int LENGTH = 4;
    int intArray[LENGTH] = {2, 3, 4, 6};
    int low = 0;
    int high = LENGTH - 1;

    for (int i = 0; i < LENGTH; i++)
    {
        cout << intArray[i] << " ";
    }
    cout << endl;

    reverseArray(intArray, LENGTH, low, high);

    return 0;
}

void reverseArray(int array[], const int LENGTH, int low, int high)
{
    int i;

    // base case
    if (low >= high)
    {
        cout << "Finished:" << endl;

        for (i = 0; i < LENGTH; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
        return;
    }
    // recursive case
    else if (low < high)
    {
        int temp = array[low];
        array[low] = array[high];       // swap low and high
        array[high] = temp;    
        for (i = 0; i < LENGTH; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
        reverseArray(array, LENGTH, low + 1, high - 1);
    }
    
}