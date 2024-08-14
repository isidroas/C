#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 200

int prime_factors(unsigned n, unsigned * res)
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
        if (size > MAX_SIZE){
          printf("execeded maximum size %d. Increase the value of MAX_SIZE\n", MAX_SIZE);
          return -1;
        }
        res[size-1] = i;
    }

    /* add a terminator */ 
    size++;
    if (size > MAX_SIZE){
      printf("execeded maximum size %d. Increase the value of MAX_SIZE\n", MAX_SIZE);
      return -1;
    }
    res[size-1] = 0;

    return 0;
}

int main(void)
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
    return 0;
}
