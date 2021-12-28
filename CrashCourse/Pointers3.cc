#include <iostream>
using namespace std;

int GetMin(int numbers[], int size) {
    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

int GetMax(int numbers[], int size) {
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

void GetMinAndMax(int numbers[], int size, int* min_ptr, int* max_ptr) {
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > *max_ptr) {
            *max_ptr = numbers[i];
        }
        if (numbers[i] < *min_ptr) {
            *min_ptr = numbers[i];
        }
    }
}

int main() {
    // Here is an example -- numbers is an address
    int numbers[5] = {5, 4, -2, 29, 6};
    cout << numbers << endl;
    cout << GetMin(numbers, 5) << endl;
    cout << GetMax(numbers, 5) << endl;
    return 0;

    // Example passing some variables by reference
    int min = numbers[0];
    int max = numbers[0];
    GetMinAndMax(numbers, 5, &min, &max);
    // if we simply passed min and max, will create *COPIES* of min and max
    cout << "Min, Max = " << min << ", " << max << endl;
}