#include <iostream>
#include <string>

// Const keyword makes an identifier constant
// Const can mean to make the identifier constant, if a variable
// Const can mean to make the contents of at an address constant, if a pointer

int main() {
    // CONST BEFORE TYPE
    int a = 5;
    a = 2;  // a can be reassigned

    const int b = 5;
    b = 2;  // b cannot be reassigned

    int* c = new int;  // declare pointer on heap
    *c = 2;            // c is now 2
    c = (int*)&b;      // c is now pointing to the constant, 5
    std::cout << *c << std::endl;

    // CONST AFTER TYPE, before pointer
    int const* d = new int;
    const int* e =
        new int;  // These two are identical syntax, if before pointer sign

    // CONST AFTER TYPE, AFTER TYPE
    int* const f = new int;  // The pointer is constant

    // CONST BEFORE AND AFTER TYPE
    const int* const g = new int;  // Can't change g NOR contents of g

    // CONST for METHOD names in a CLASS?
    class Entity {
       private:
        int m_X, m_Y;
        int* m_Z;

       public:
        int GetX() const {
            return m_X;
        }  // Here const is a "promise" not to modify the class
        // Makes sense to write const with a getter

        int GetX() { return m_X; }

        void SetX(int x) { m_X = x; }

        // x is a pointer
        const int* const GetX() const {
            return m_X;  // returns a pointer, promises not to update
        }
    }
}