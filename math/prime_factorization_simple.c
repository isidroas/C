#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

int prime_factors(unsigned n, unsigned* res)
{
    unsigned i = 2, size = 0;
    assert(res);
    while (n > 1 && i <= n)
    {
        if (n % i)
        {
            i++;
            continue;
        }
        n = n / i;
        size++;
        if (size > MAX_SIZE)
        {
            printf("execeded maximum size %d. Increase the value of MAX_SIZE\n",
                   MAX_SIZE);
            return -1;
        }
        res[size - 1] = i;
    }

    /* add a terminator */
    size++;
    if (size > MAX_SIZE)
    {
        printf("execeded maximum size %d. Increase the value of MAX_SIZE\n",
               MAX_SIZE);
        return -1;
    }
    res[size - 1] = 0;

    return 0;
}

void test(void)
{
    unsigned array[MAX_SIZE];
    prime_factors(12, array);
    assert(array[0] == 2);
    assert(array[1] == 2);
    assert(array[2] == 3);
    assert(array[3] == 0);

    prime_factors(11, array);
    assert(array[0] == 11);
    assert(array[1] == 0);

    prime_factors(1 << 31, array);
    assert(array[0] == 2);
    assert(array[30] == 2);
    assert(array[31] == 0);
}

void print_array(unsigned* array)
{
    for (int i = 0; i < MAX_SIZE && array[i] != 0; i++)
    {
        if (i != 0)
            printf("-");
        printf("%d", array[i]);
    }
    printf("\n");
}

int main(void)
{
    unsigned n;
    unsigned array[MAX_SIZE];

    test();

    printf("Enter an integer in range [2, %u]\n> ", UINT_MAX);
    if (scanf("%u", &n) != 1)
    {
        printf("failed scanf\n");
        return 1;
    }

    if (prime_factors(n, array))
        return 2;

    print_array(array);
}
