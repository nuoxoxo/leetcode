

#include "pthread.h"
#include "semaphore.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct 
{
    int         n;

    sem_t       foo_; // added
    sem_t       bar_; // added
    
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;

    sem_init(& obj->foo_, 0, 0); // added
    sem_init(& obj->bar_, 0, 1); // added

    return obj;
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++)
    {
        sem_wait(& obj->bar_); // added

        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();

        sem_post(& obj->foo_); // added
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++)
    {
        sem_wait(& obj->foo_); // added

        // printBar() outputs "bar". Do not change or remove this line.
        printBar();

        sem_post(& obj->bar_); // added
    }
}

void fooBarFree(FooBar* obj)
{
    sem_destroy(& obj->foo_); // added
    sem_destroy(& obj->bar_); // added
}
