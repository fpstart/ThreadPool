#ifndef __ZEROREF_THREADPOOL_H__
#define __ZEROREF_THREADPOOL_H__
#include <chrono>
#include <ratio>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <future>
#include <vector>
#include <deque>
#include <queue>
#include <memory>
namespace zeroref
{
  class ThreadPool
  {
    public:
      ThreadPool(int coreThreadNum,int maxThreadNum,std::chrono::duration<double,std::ratio<1,1000>> keepAliveTime);
      ~ThreadPool();
      template <typename FUNC,typename... ARGS>
      auto execute(FUNC func,ARGS... args);
  }
}

#endif