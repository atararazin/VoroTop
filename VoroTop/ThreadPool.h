#include <mutex>
#include <iostream>
#include <condition_variable>
#include <thread>
#include <queue>

/***
 * This class manages a thread pool
 */

/*
class ThreadPool {
public:
    ThreadPool() : done(false) {
        //outputFile = new OutputFile();
        //outputFile->createFile("graphs100");
        //voroOutputFile = new GraphsFile("/home/atara/VoroTop/tests/graphs2");

        in;
        in.open("numbers_in", fstream::in);
        out.open("numbers_out", fstream::out);


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
        outputFile->closeFile();
        delete(outputFile);
        delete(voroOutputFile);

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
    std::mutex inFileMutex;
    std::mutex outFileMutex;
    OutputFile *outputFile;
    GraphsFile *voroOutputFile;
    ifstream in;
    fstream out;
    string toWrite[10];
    int upto = 0;
    int prev = 1;


    int coutning = 0;
    void doWork() {
        while (!done) {
            processRequest();
        }
    }

    void processRequest() {
        /*inFileMutex.lock();
        pair<string, int> line = voroOutputFile->readOneLine();
        printf("done line");
        if(line.first == ""){
            done = true;
            //return;
        }
        inFileMutex.unlock();

        WeinbergGraph<int> *graph = new WeinbergGraph<int>(line.first);
        WeinbergVector<int>* wvector = new WeinbergVector<int>(graph);
        wvector->calculate();
        wvector->print();

        outFileMutex.lock();
        outputFile->saveData(wvector->getCanonicalVector(), line.second);
        outFileMutex.unlock();
        delete(wvector);
        delete(graph);
        */
/*
        inFileMutex.lock();
        string line;
        getline(in, line);
        //int lineNum = stoi(line);
        inFileMutex.unlock();

        outFileMutex.lock();

        out << "line" << line << endl;
        outFileMutex.unlock();
    }
};*/







#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>
// TAKEN FROM https://github.com/progschj/ThreadPool
class ThreadPool {
public:
    ThreadPool(size_t);
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args)
    -> std::future<typename std::result_of<F(Args...)>::type>;
    ~ThreadPool();
private:
    // need to keep track of threads so we can join them
    std::vector< std::thread > workers;
    // the task queue
    std::queue< std::function<void()> > tasks;

    // synchronization
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
        :   stop(false)
{
    for(size_t i = 0;i<threads;++i)
        workers.emplace_back(
                [this]
                {
                    for(;;)
                    {
                        std::function<void()> task;

                        {
                            std::unique_lock<std::mutex> lock(this->queue_mutex);
                            this->condition.wait(lock,
                                                 [this]{ return this->stop || !this->tasks.empty(); });
                            if(this->stop && this->tasks.empty())
                                return;
                            task = std::move(this->tasks.front());
                            this->tasks.pop();
                        }

                        task();
                    }
                }
        );
}

// add new work item to the pool
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args)
-> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;

    auto task = std::make_shared< std::packaged_task<return_type()> >(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );

    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);

        // don't allow enqueueing after stopping the pool
        if(stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        tasks.emplace([task](){ (*task)(); });
    }
    condition.notify_one();
    return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for(std::thread &worker: workers)
        worker.join();
}

#endif
