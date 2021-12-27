#include <iostream>
#include <vector>

using namespace std;

void fillVector(vector<int>&);
// fillVector
// @param vector<int>& ALWAYS pass your vectors in by reference
// don't want to modify it? pass in const vector<int>&

void printVector(const vector<int>&);
// printVector
// @ param const vector<int>& and vector to be printed

void reverse(const vector<int>&);
// reverse
// @param const vector<int>& - vector to be printed backwards

int main() {
    vector<int> v;
    fillVector(v);
    printVector(v);
    reverse(v);
}

void fillVector(vector<int>& new_vector) {
    cout << "Type in a list of numbers";
    int input;
    cin >> input;

    while (input != -1) {
        new_vector.push_back(input);
        cin >> input;
    }
    cout << endl;
}

void printVector(const vector<int>& new_vector) {
    for (unsigned int i = 0; i < new_vector.size(); i++) {
        cout << new_vector[i] << " ";
    }
    cout << endl;
}

void reverse(const vector<int>& v) {
    cout << "Reversed: ";
    for (unsigned int i = v.size(); i > 0; i--) {
        cout << v[i - 1] << " ";
    }
    cout << endl;
}