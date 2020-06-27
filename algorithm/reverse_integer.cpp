#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int reverse(int x)
{
    int n = 0;
    int int_max = 2147483648 - 1;
    int int_min = -2147483648;

    while (x != 0)
    {
        if (n > int_max / 10 || n < int_min / 10)
        {
            return 0;
        }

        n = n * 10 + x % 10;
        x /= 10;
    }

    return n;
}

int main(int argc, char const *argv[])
{
    int test1 = 123;
    cout << reverse(test1) << endl;
    return 0;
}
