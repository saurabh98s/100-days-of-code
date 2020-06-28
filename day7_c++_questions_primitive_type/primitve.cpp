#include <stdio.h>
#include <iostream>
using namespace std;

short parity1(unsigned long x)
{
    short result = 0;
    while (x)
    {
        result ^= (x & 1); //^ means XOR & is AND Operation
        x >>= 1;           //right shift bit operator
    }

    return result;
}

short parity2(unsigned long x)
{
    short result = 0;
    while (x) {
        result^=1;
        x&=(x-1);
    }
    return result;
}

int main()
{
    cout << parity1(50);
}