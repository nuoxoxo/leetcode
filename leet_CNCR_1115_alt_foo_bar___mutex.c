
# include "pthread.h"

typedef struct 
{
    pthread_mutex_t     mtx_foo; // +
    pthread_mutex_t     mtx_bar; // +
    int                 n;
    
}   FooBar;

FooBar* fooBarCreate(int n)
{
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;

    pthread_mutex_init(& obj->mtx_foo, NULL); // +
    pthread_mutex_init(& obj->mtx_bar, NULL); // +

    return obj;
}

void foo(FooBar* obj)
{
    for (int i = 0; i < obj->n; i++)
    {
        pthread_mutex_lock(& obj->mtx_bar); // +
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        pthread_mutex_unlock(& obj->mtx_foo); // +
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++)
    {
        pthread_mutex_lock(& obj->mtx_foo); // +
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        pthread_mutex_unlock(& obj->mtx_bar); // +
    }
}

void fooBarFree(FooBar* obj)
{
    if (obj)
        free(obj);
}
