#include <iostream>
#include <vector>
using namespace std;

int GetNumber() { return 5; }

int Add(int a, int b) { return a + b; }

bool AscendingCompare(int a, int b) { return a < b; }
bool DescendingCompare(int a, int b) { return a > b; }

void PrintArray(vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << ' ';
    }
    cout << endl;
}
// Notice that the two functions below are ALMOST identical except for
// comparator
void SortAscending(vector<int>& A) {
    for (int start = 0; start < A.size(); start++) {
        int best = start;

        for (int current = start + 1; current < A.size(); current++) {
            // passing comparison via function pointer here
            // is current < best? If yes, best = current
            // so best means smallest here, or minimum maybe
            if (AscendingCompare(A[current], A[best])) {
                best = current;
            }
        }
        swap(A[start], A[best]);
    }
}
void SortDescending(vector<int>& A) {
    for (int start = 0; start < A.size(); start++) {
        int best = start;

        for (int current = start + 1; current < A.size(); current++) {
            // passing comparison via function pointer here
            if (DescendingCompare(A[current], A[best])) {
                best = current;
            }
        }
        swap(A[start], A[best]);
    }
}
// Below is an improved version passing a comparator function via a function
// pointer. Note the syntax of the argument.
void Sort(vector<int>& A, bool (*comparator)(int, int)) {
    for (int start = 0; start < A.size(); start++) {
        int best = start;

        for (int current = start + 1; current < A.size(); current++) {
            // comparison passed via function pointer used here
            if (comparator(A[current], A[best])) {
                best = current;
            }
        }
        swap(A[start], A[best]);
    }
}

int main() {
    cout << "GetNumber() example" << endl;
    cout << GetNumber() << endl;
    // What if we did not include ()? Should be passing a function right?
    // But we need to pass the pointer instead.
    int (*function_pointer)();  // We COULD put parameters in parens
    // Now we have successfully created a funciton pointer
    function_pointer = GetNumber;
    cout << function_pointer() << endl;

    cout << "Add() example" << endl;
    cout << Add(2, 3) << endl;
    int (*function_pointer_2)(int, int) = Add;
    cout << function_pointer_2(2, 3) << endl;

    // Typical use? Depends. Consider a sort function that takes a comparator
    // To decide how to compare values -- sort ascending or descending?
    // See below:
    vector<int> nums = {2, 5, 1, 6, 0, 10};
    SortAscending(nums);
    PrintArray(nums);

    bool (*comparator_ptr)(int, int) = AscendingCompare;
    Sort(nums, comparator_ptr);
    PrintArray(nums);
}