#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

class FooBar
{
private:
    int n;
    mutex m_mutex;
    condition_variable m_fooCond;
    condition_variable m_barCond;
    bool m_isFooComplete;
    bool m_isBarComplete;

public:
    FooBar(int n)
    {
        this->n = n;
        m_isFooComplete = false;
        m_isBarComplete = true;
    }

    void foo(function<void()> printFoo)
    {
        for(int i = 0; i < n; i++)
        {
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            unique_lock<mutex> lock(m_mutex);
            m_barCond.notify_one();
            m_isFooComplete = true;
            m_isBarComplete = false;

            while(!m_isBarComplete)
            {
                m_fooCond.wait(lock);
            }
        }
    }

    void bar(function<void()> printBar)
    {
        for(int i = 0; i < n; i++)
        {
            unique_lock<mutex> lock(m_mutex);

            while(!m_isFooComplete)
            {
                m_barCond.wait(lock);
            }

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            m_isFooComplete = false;
            m_isBarComplete = true;
            m_fooCond.notify_one();
        }
    }
};