#include <iostream>
using namespace std;

/*
    Write a recursive function that finds and returns the sum of the elements of an int array.
    Also, write a program to test your function.
*/

int sumArray(int array[], int size, int indx = 0);

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int size = 11;
    int sum = sumArray(array, size);
    cout << "Sum of the elements: " << sum << endl;
    return 0;
}

int sumArray(int array[], int size, int indx){
    // Base case: when the index reaches the end of the array
    if (indx == size)
        return 0; 
    // Recursive case
    else
        return array[indx] + sumArray(array, size, indx + 1);
}
