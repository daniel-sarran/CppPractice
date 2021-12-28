#include <iostream>
using namespace std;

// Using pointers for arrays

int main() {
    ////    Example 1
    // array variable is actually the address of the first element
    int lucky_numbers[5] = {2, 3, 5, 7, 9};
    cout << lucky_numbers << endl;

    // which you can verify as follows
    cout << &lucky_numbers[0] << endl;

    // indexing
    cout << lucky_numbers[2] << endl;

    // this is an equivalent statement to previous
    cout << *(lucky_numbers + 2) << endl;

    ////    Example 2
    // Let's build an array from user input, note indexing through [ ]
    int lucky_numbers_2[5];
    for (int i = 0; i < 5; i++) {
        cout << "Number: ";
        cin >> lucky_numbers_2[i];
    }

    // Print the final array, note indexing through dereferenced ptr & offset
    for (int i = 0; i < 5; i++) {
        cout << *(lucky_numbers_2 + i) << " ";
    }
    cout << endl;

    return 0;
}