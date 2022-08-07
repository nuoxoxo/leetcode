class FooBar {
private:
    int             n;
    mutex           food; // added
    mutex           bart; // added

public:
    FooBar(int n)
    {
        this->n = n;
        bart.lock(); // added
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++)
        {
            food.lock(); // added

            // printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            bart.unlock(); // added
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++)
        {
            bart.lock(); // added
            // printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            food.unlock(); // added
        }
    }
};
