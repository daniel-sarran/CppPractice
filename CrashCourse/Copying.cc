#include <iostream>
#include <string>

struct Vector2 {
    float x, y;
};

int main() {
    // Primitives
    int a = 2;
    int b = a;  // What I'm doing here is actually creating a copy of `a`

    // Objects
    Vector2 c = {2, 3};
    Vector2 d =
        c;  // This is also a copy of c, two separate variables at two addresses

    Vector2* e = new Vector2();  // now on the heap because `new`
    Vector2* f = e;  // now its a copy of the POINTER, so same object
    f->x = 2;        // now e.x is 2

    // And remember references& are aliases, not objects
}