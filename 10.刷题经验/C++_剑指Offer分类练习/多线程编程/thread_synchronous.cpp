
#include <list>
#include <iostream>
#include <pthread.h>
#include "semaphore.h"


struct Job
{
    Job(int x=0,int y=0):x(x),y(y) {}
    int x,y;
};

//一半临界区代码越短越好，执行时间越短越好，使用C++ stl可能并不是最好选择
std::list<Job*> job_queue;
//定一个互斥对象
pthread_mutex_t job_queue_mutex=PTHREAD_MUTEX_INITIALIZER;

//控制作业数目的信号量
sem_t job_queue_count;


void ProcessJob(Job* job)
{
    std::cout<<"Thread"<<(int)pthread_self();
    std::cout<<"processing("<<job->x<<","<<job->y<<")\n";
}

//处理作业时候需要枷锁
void* DequeueJob(void *arg)
{   
    while(true)
    {
        Job* job=NULL;
        
        sem_wait(&job_queue_count);//等待作业中有作业


        //被多个线程共享资源，锁定互斥，才能访问共享资源
        pthread_mutex_lock(&job_queue_mutex);

         if(!job_queue.empty())
       {
        job=job_queue.front();
        job_queue.pop_front();
       }
       pthread_mutex_unlock(&job_queue_mutex);

       if(!job) break;

        ProcessJob(job);

        delete job;
        job=NULL;
      

    }
   

    return NULL;
}

//作业入队需要枷锁
void* EnqueueJob(void* arg)
{
    Job* job=reinterpret_cast<Job*>(arg);
    pthread_mutex_lock(&job_queue_mutex);
    job_queue.push_back(job);
    
    //新作业入队，发布信号量
     sem_post(&job_queue_count);


    //入队时候也输出线程ID和作业内容信息
    std::cout<<"Thread"<<(int)pthread_self();
    std::cout<<"enqueueing("<<job->x<<","<<job->y<<")\n";

    pthread_mutex_unlock(&job_queue_mutex);

    return NULL;
}

int main()
{
    int i;
    pthread_t threads[8];
    if(!job_queue.empty())
        job_queue.clear();
    
    sem_init(&job_queue_count,0,0);//初始化，非进程共享，初始值为0


    for(i=0;i<5;++i)
    {
        Job* job=new Job(i+1,(i+1)*2);
        pthread_create(&threads[i],NULL,EnqueueJob,job);
    }

    for(i=5;i<8;++i)
        pthread_create(&threads[i],NULL,DequeueJob,NULL);
    for(i=0;i<8;++i)
        pthread_join(threads[i],NULL);//等待结束

    
    sem_destroy(&job_queue_count);//销毁作业信号量

    return 0;
}
