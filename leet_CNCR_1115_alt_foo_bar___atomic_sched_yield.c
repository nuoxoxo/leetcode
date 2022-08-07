
#include <signal.h>

typedef struct
{
    int             n;
    sig_atomic_t    alt; // added
}   FooBar;

FooBar* fooBarCreate(int n)
{
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;

    obj->alt = 0; // added

    return obj;
}

void foo(FooBar* obj)
{    
    for (int i = 0; i < obj->n; i++)
    {
        /* added part start */
        while (obj->alt)
        {
            sched_yield();
        }
        /* end */

        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();

        obj->alt = 1; // added
    }
}

void bar(FooBar* obj)
{    
    for (int i = 0; i < obj->n; i++)
    {
        /* added part start */
        while (!obj->alt)
        {
            sched_yield();
        }
        /* end */

        // printBar() outputs "bar". Do not change or remove this line.
        printBar();

        obj->alt = 0; // added
    }
}

void fooBarFree(FooBar* obj) {}
