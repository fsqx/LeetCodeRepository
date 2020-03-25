#include <mutex>
#include <condition_variable>

using namespace std;

class Foo
{
public:
    Foo()
    {
        m_isFirstThreadComplete = true;
        m_isSecondThreadComplete = false;
    }

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        unique_lock<mutex> lock(m_firstMutex);
        m_firstCond.notify_one();
        m_isFirstThreadComplete = true;
    }

    void second(function<void()> printSecond)
    {
        while(!m_isFirstThreadComplete)
        {
            unique_lock<mutex> lock(m_firstMutex);
            m_firstCond.wait(lock);
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        unique_lock<mutex> lock2(m_secondMutex);
        m_secondCond.notify_one();
        m_isSecondThreadComplete = true;
    }

    void third(function<void()> printThird)
    {
        while(!m_isSecondThreadComplete)
        {
            unique_lock<mutex> lock(m_secondMutex);
            m_secondCond.wait(lock);
        }

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    mutex m_firstMutex;
    condition_variable m_firstCond;
    bool m_isFirstThreadComplete;

    mutex m_secondMutex;
    condition_variable m_secondCond;
    bool m_isSecondThreadComplete;

};