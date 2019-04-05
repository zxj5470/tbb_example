#include <iostream>
#include <tbb/task_group.h>

using namespace tbb;

int Fib(int n) {
    if (n < 2) {
        return n;
    } else {
        int x, y;
        task_group g;
        g.run([&] { x = Fib(n - 1); }); // spawn a task
        g.run([&] { y = Fib(n - 2); }); // spawn another task
        g.wait();                // wait for both tasks to complete
        return x + y;
    }
}

int main() {
    int ret = Fib(34);
    std::cout << ret << std::endl;
    return 0;
}