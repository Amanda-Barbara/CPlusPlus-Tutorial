//
// Created by light on 19-12-25.
//

#include <iostream>
#include <cassert>

int main() {
    const int alignment=5;
    printf("(alignment & (alignment - 1)) = %d\n. ", (alignment & (alignment - 1)));
    assert((alignment & (alignment - 1)) == 0);
    static_assert((alignment & (alignment - 1)) == 3, "Alignment must be power of two");
    return 0;
}