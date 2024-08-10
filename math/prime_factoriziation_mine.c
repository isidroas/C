#include <assert.h>
#include <stdlib.h>

unsigned int *prime_factors(unsigned int n)
{
    unsigned *res = NULL, *current = NULL, i = 2;
    res = current = malloc(sizeof(unsigned) * 20);
    while (n > 1 && i <= n)
    {
        if (n % i)
        {
            i++;
            continue;
        }
        n = n / i;
        *current = i;
        current++;
        // TODO: check if overflow. when i%20 == 0?
        if((i-1)%20==0){
          // minus one because we have to leave room to the terminator
          res = realloc(res, (i + 20)*sizeof(unsigned));
          if (res == NULL) {
            return NULL;
          }
        }
    }
    *current = 0;  // terminator
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

    array = prime_factors(1<< 31);
    assert(array[0]==2);
    assert(array[30]==2);
    assert(array[31]==0);
    free(array);
    return 0;
}
