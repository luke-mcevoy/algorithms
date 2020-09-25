#include <iostream>
#include <sstream>

using namespace std;

int one(int a, int b) {
    int c = a - b,
        d = (c >> 7) & 1,
        myst = a - c * d;
    return myst;
}

int two(int x) {
    return (x && !(x & (x - 1)));
}

int three(int x, int y) {
    int s, c;
    s = x ^ y;
    c = x & y;
    while (c != 0) {
        c = c << 1;
        x = s;
        y = c;
        s = x ^ y;
        c = x & y;
    }
    return s;
}

int main(int argc, char * const argv[]) {
    
    cout << "func1 for (3, 7): " << one(3,7) << endl;
    cout << "func1 for (8, 7): " << one(8,7) << endl;

    for (int i = 1; i <= 8; i++) {
        cout << "func2 for i: " << i << " = " << two(i) << endl;
    }

    cout << "func3 for (5, 7): " << three(5,7) << endl;
    cout << "func3 for (2, 8): " << three(2,8) << endl;

   return 0;

}