#include <iostream>
using namespace std;

// 2D arrays

int main() {
    int rows, cols;
    cout << "rows, cols: ";
    cin >> rows >> cols;

    // Top level array is a pointer to an array of pointers
    // Double pointer identifer to array of single pointers
    int** table = new int*[rows];
    for (int i = 0; i < rows; i++) {
        // Bottom level array holds values
        table[i] = new int[cols];
    }

    table[1][2] = 88;

    // Anytime 'new' is used, need to use 'delete' for proper mem mgmt
    // Order matters, we cannot delete table first, then we would not dealloc
    // The array of pointers... instead only deallocating the identifier.
    // Instead delete each dynamic array by removing the pointer and its alloc
    // memory.
    for (int i = 0; i < rows; i++) {
        delete[] table[i];
    }

    // Then, delete the top level dynamic array
    delete[] table;

    // Finally, delete the identifier pointing to what is now empty space
    table = NULL;
}