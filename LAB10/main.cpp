#include "Vector2.h"
#include <cassert>
#include <iostream>

int main() {
    Vector2 v1;
    assert(v1.x == 0 && v1.y == 0);

    Vector2 v2(3.0f, 4.0f);
    assert(v2.x == 3.0f && v2.y == 4.0f);

    Vector2 v3 = v2 * 2.0f;
    assert(v3.x == 6.0f && v3.y == 8.0f);

    Vector2 v4 = 2.0f * v2;
    assert(v4.x == 6.0f && v4.y == 8.0f);

    Vector2 v5 = v3 / 2.0f;
    assert(v5.x == 3.0f && v5.y == 4.0f);

    v1 += v2;
    assert(v1.x == 3.0f && v1.y == 4.0f);
    
    Vector2 v6 = v1 + v2;
    assert(v6.x == 6.0f && v6.y == 8.0f);

    v6 -= v2;
    assert(v6.x == 3.0f && v6.y == 4.0f);

    Vector2 v7 = v6 - v1;
    assert(v7.x == 0.0f && v7.y == 0.0f);

    v2 *= 3.0f;
    assert(v2.x == 9.0f && v2.y == 12.0f);

    v2 /= 3.0f;
    assert(v2.x == 3.0f && v2.y == 4.0f);

    assert(v2[0] == 3.0f);
    assert(v2[1] == 4.0f);

    v2[0] = 10.0f;
    v2[1] = 20.0f;
    assert(v2.x == 10.0f && v2.y == 20.0f);

    std::cout << "Vector: " << v2 << std::endl;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}