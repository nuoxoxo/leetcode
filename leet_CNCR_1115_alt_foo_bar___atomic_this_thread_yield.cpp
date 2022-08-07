class FooBar {
private:
    int             n;
    atomic<bool>    alt; // added

public:
    FooBar(int n)
    {
        this->n = n;
        alt = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++)
        {
		/* solution part start */
		while (alt)
		{
			this_thread::yield();
		}
		/* end */

		// printFoo() outputs "foo". Do not change or remove this line.
		printFoo();

		alt = !alt; // added
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++)
        {
		/* solution part start */
		while (!alt)
		{
			this_thread::yield();
		}
		/* end */

		// printBar() outputs "bar". Do not change or remove this line.
		printBar();

		alt = !alt; // added
        }
    }
};
