#include <iostream>
#include <string>

struct Vector3 {
    float x, y, z;
};

int main() {
    // Create value on stack
    int value = 5;

    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;

    Vector3 vector;
    // No need to free memory on stack. Stack pops off on its own to next
    // stack frame.

    // Create value on heap -- with `new` keyword
    // `new` basically calls `malloc` -- any program starts with x amount of
    // free space allocated. `malloc` goes through the "free list" and allocates
    // memory, with a ton of bookkeeping, and returns the pointer.
    int* heap_value = new int;
    *heap_value = 5;

    int* heap_array = new int[5];
    heap_array[0] = 1;
    heap_array[1] = 2;
    heap_array[2] = 3;
    heap_array[3] = 4;
    heap_array[4] = 5;

    Vector3* heap_vector = new Vector3();
    // Delete allocated memory on heap
    delete heap_value;
    delete[] heap_array;
    delete[] heap_vector;

    // Smart pointers: will call NEW and DELETE for you
}