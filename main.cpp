#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

/*
This thread is currently ideal
*/
void foo(int Z)
{
    while(1)
    {
        cout<<"Hello I am thread-1, give me some task"<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

class thread_obj {
public:
    void operator()(int x)
    {
        while(1)
        {
            cout<<"Hello I am thread-2, give me some task"<<endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
};

int main()
{
    /*Use function pointer to call the thread*/
    thread th1(foo, 3);

    /*Function object is used to call thread*/
    thread th2(thread_obj(), 3);

    /*TODO:Define a Lambda Expression and use threading*/

    /*Wait for thread t1 to finish*/
    th1.join();

    /*Wait for thread t2 to finish*/
    th2.join();

    return 0;
}
