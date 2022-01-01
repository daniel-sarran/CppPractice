#include <iostream>
using namespace std;

// making of a dynamic array

int main() {
    int size;
    cout << "Size: ";
    cin >> size;

    // int myArray[size];
    int* myArray = new int[size];

    // new has allocated an array of the size specified by user.
    for (int i = 0; i < size; i++) {
        cout << "Array[" << i << "] ";
        cin >> myArray[i];
    }
    // The following two are identical in what they do
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";  // myArray is an address, bracket takes to
                                    // index... and dereferences?
    }
    for (int i = 0; i < size; i++) {
        cout << *(myArray + i)
             << " ";  // myArray + i accesses the index, dereference that
    }
    cout << endl;

    // Deallocating memory!! Use this in contrast with `new`
    delete[] myArray;  // Square brackets just like on line 16
    myArray = NULL;    // Array will not point to anything, good practice since
                       // points to nothing
}