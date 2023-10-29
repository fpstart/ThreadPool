#ifndef __ZEROREF_THREADPOOL_H__
#define __ZEROREF_THREADPOOL_H__
#include <chrono>
#include <ratio>
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
#include "./ThreadPool.cpp"
#endif