#ifndef __ZEROREF_THREADPOOL_H__
#define __ZEROREF_THREADPOOL_H__
#include <chrono>
#include <ratio>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <future>
#include <forward_list>
#include <deque>
#include <queue>
#include <memory>
#include <function>
namespace zeroref
{
  class ThreadPool
  {
    public:
    ThreadPool(int coreThreadNum, int maxThreadNum, std::chrono::duration < double, std::ratio < 1, 1000>> keepAliveTime);
    ~ThreadPool();
    template < typename FUNC,typename... ARGS >
    auto execute(FUNC func, ARGS... args) -> std::future < std::result_of(FUNC(ARGS...))::type >
    void stop();
    protected:
    void coreThread();
    void tempThread();
    private:
    std::forward_list<std::thread> mThreadList;
    std::queue<std::function<void()>> mTaskList;
    std::atomic<bool> isStop;
    std::mutex mTaskLock;
    std::condition_variable mTaskCond;
  };
};

#endif