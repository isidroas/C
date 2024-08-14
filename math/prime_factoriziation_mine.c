#include <assert.h>
#include <stdlib.h>

/* https://en.wikipedia.org/wiki/Dynamic_array */
void ensure_array_size(unsigned **parray, unsigned size)
{
    if (!size)
        return;

    #define STEP 20
    unsigned bytes = ((size - 1) / STEP + 1) * STEP * sizeof(unsigned);

    /* printf("size: %u, bytes %lu\n", size, bytes / sizeof(unsigned)); */
    if (*parray == NULL)
        *parray = malloc(bytes);
    else
        // realloc is efficent when the same size is requested? if not we could wrap this call `if (((size-1)%STEP)==0)`
        *parray = realloc(*parray, bytes);
    assert(*parray);
}

void append_array(unsigned **parray, unsigned *size, unsigned value)
{
    (*size)++;
    ensure_array_size(parray, *size);
    (*parray)[*size - 1] = value;
}

unsigned *prime_factors(unsigned n)
{
    unsigned *res = NULL, i = 2, size = 0;
    while (n > 1 && i <= n)
    {
        if (n % i)
        {
            i++;
            continue;
        }
        n = n / i;
        append_array(&res, &size, i);
    }
    append_array(&res, &size, 0);  // terminator
    return res;
}

int main(void)
{
    unsigned int *array = NULL;
    array = prime_factors(12);
    assert(array[0] == 2);
    assert(array[1] == 2);
    assert(array[2] == 3);
    assert(array[3] == 0);
    free(array);

    array = prime_factors(11);
    assert(array[0] == 11);
    assert(array[1] == 0);
    free(array);

    array = prime_factors(1 << 31);
    assert(array[0] == 2);
    assert(array[30] == 2);
    assert(array[31] == 0);
    free(array);
    return 0;
}
