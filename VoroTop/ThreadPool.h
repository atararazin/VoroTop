#include <mutex>
#include <iostream>
#include <condition_variable>
#include <thread>
#include <queue>

/***
 * This class manages a thread pool
 */

class ThreadPool {
public:
    ThreadPool() : done(false) {
        // This returns the number of threads supported by the system. If the
        // function can't figure out this information, it returns 0. 0 is not good,
        // so we create at least 1
        auto numberOfThreads = std::thread::hardware_concurrency();
        if (numberOfThreads == 0) {
            numberOfThreads = 1;
        }

        for (unsigned i = 0; i < numberOfThreads; ++i) {
            // The threads will execute the private member `doWork`. Note that we need
            // to pass a reference to the function (namespaced with the class name) as
            // the first argument, and the current object as second argument
            threads.push_back(std::thread(&ThreadPool::doWork, this));
        }
    }

    // The destructor joins all the threads so the program can exit gracefully.
    // This will be executed if there is any exception (e.g. creating the threads)
    ~ThreadPool() {
        // So threads know it's time to shut down
        done = true;

        // Wake up all the threads, so they can finish and be joined
        workQueueConditionVariable.notify_all();
        for (auto& thread : threads) {
            if (thread.joinable()) {
                thread.join();
            }
        }
    }

    // This function will be called by the server every time there is a request
    // that needs to be processed by the thread pool
    void queueWork() {

        // Notify one thread that there are requests to process
        workQueueConditionVariable.notify_one();
    }

private:
    // This condition variable is used for the threads to wait until there is work
    // to do
    std::condition_variable_any workQueueConditionVariable;

    // We store the threads in a vector, so we can later stop them gracefully
    std::vector<std::thread> threads;

    // This will be set to true when the thread pool is shutting down. This tells
    // the threads to stop looping and finish
    bool done;

    //my addition
    std::mutex printingM;
    int coutning = 0;
    void doWork() {
        while (!done) {
            processRequest();
        }
    }

    void processRequest() {
        printingM.lock();
        std::cout << "working..." << coutning <<std::endl;
        coutning++;
        if(coutning == 50){
            done = true;
        }
        printingM.unlock();
    }
};