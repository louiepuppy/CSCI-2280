#include <iostream>
using namespace std;

/*  
    Consider the following problem: How many ways can a committee of four people be selected
    from a group of 10 people? There are many other similar problems in which you are asked 
    to find the number of ways to select a set of items from a given set of items. The general
    problem can be stated as follows: Find the number of ways r different things can be chosen
    from a set of n items, in which r and n are nonnegative integers and r <= n. Suppose C(n, r)
    denotes the number of ways r different things can be chosen from a set of n items. Then,
    C(n, r) is given by the followuing formula:

    C(n, r) = n! / (r!(n-r)!)

    in which the exclamation point denotes the factorial function. Moreover, C(n, 0) = C(n, n) = 1.
    It is also known that C(n, r) = C(n - 1, r - 1) + C(n - 1, r).
    (2, 3, 4, 6)

    a. Write a recursive algorithm to determine C(n, r). Identify the base case(s) and the general
    case(s).
    b. Using your recursive algorithm, determine C(5, 3) and C(9, 4)
*/

int combinations(int& recursions, int n, int r);

int main(){
    int recursions1 = 0;
    int recursions2 = 0;
    int numCombinations1, numCombinations2;
    numCombinations1 = combinations(recursions1, 5, 3);
    numCombinations2 = combinations(recursions2, 9, 4);
    cout << "C(5, 3) = " << numCombinations1 << " (recursions: " << recursions1 << ")" << endl;
    cout << "C(9, 4) = " << numCombinations2 << " (recursions: " << recursions2 << ")" << endl;
    return 0;
}

int combinations(int& recursions, int n, int r){
    if(r == 0 || r == n){
        return 1;
    } else {
        recursions++;
        return combinations(recursions, n - 1, r - 1) + combinations(recursions, n - 1, r);
    }
}
