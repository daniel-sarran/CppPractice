// https://www.youtube.com/watch?v=kiUGf_Z08RQ&ab_channel=CodeBeauty

#include <iostream>
using namespace std;

void PrintNumber(int *number_ptr) { cout << *number_ptr << endl; }
void PrintLetter(char *char_ptr) { cout << *char_ptr << endl; }
void print(void *ptr, char type) {
    switch (type) {
        case 'i':
            cout << *((int *)ptr) << endl;
            break;
        case 'c':
            cout << *((char *)ptr) << endl;
            break;
    }
}
int main() {
    int n = 5;
    char c = 'a';

    // pointer must be of same type as what it points to
    int *ptr = &n;

    print(&n, 'i');
    print(&c, 'c');

    return 0;
}