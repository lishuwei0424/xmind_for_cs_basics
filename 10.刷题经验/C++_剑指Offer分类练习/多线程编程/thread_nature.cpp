#include <pthread.h>
#include <iostream>
using namespace std;


//临界区设定,保证里面代码要么没做。要么做完了
void Transfer(double* accounts,int from,int to,double amount)
{
    int ocs;

    //将线程设置为不可撤销，进入临界
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,&ocs);

    accounts[to]+=amount;
    accounts[from]-=amount;

    //恢复线程的撤销状态，离开临界区
    pthread_setcancelstate(ocs,NULL);
}


//线程局部存储

static pthread_key_t tlk;//关联线程日志文件指针的键
 void WriteToThreadLog(const char* msg)
 {
     FILE* fp=(FILE*)pthread_getspecific(tlk);
     fprintf(fp,"%d:%s\n",(int)pthread_self(),msg);
 }

void CloseThreadLog(void* fp)
{
    fclose((FILE*)fp);
}
void* ThreadFunc(void *arg)
{
    char filename[255];
    FILE* fp;

    //生成与线程ID配套的日志文件
    sprintf(filename,"thread%d.log",(int)pthread_self());
    fp=fopen(filename,"w");

    //设置线程日志文件指针与键的局部存储关联
    pthread_setspecific(tlk,fp);
    //向日志中写入数据，不同的线程会写入不同的文件
    WriteToThreadLog("Thread starting...");
    return NULL;


}

//线程清除
void* AllocateBuffer(size_t size)
{
    return malloc(size);
}
void DeallocateBuffer(void* buffer)
{
    free(buffer);
}
void DoSomeWork()
{
    void* temp_buffer=AllocateBuffer(1024);
    //注册清除处理函数
    pthread_cleanup_push(DeallocateBuffer,temp_buffer);

    //取消除测，传递值非0,实施清除任务
    pthread_cleanup_pop(1);

}

//线程清除异常处理
class EThreadExit
{
    public:
        EThreadExit(void* ret_val):_thread_ret_val(ret_val){}

        //实际退出线程，使用对象构造时的返回值
         void* DoThreadExit()
         {
             pthread_exit(_thread_ret_val);
         }
    private:
        void* _thread_ret_val;

};

void* ThreadFunc(void* arg)
{
    try
    {
        
        if(线程需要退出)
            throw EThreadExit(线程返回值);

        
    }
    catch(const EThreadExit& e)
    {
        e.DoThreadExit();//执行线程退出动作
    }

    return NULL;
    
}

int main()
// {
//     pthread_attr_t attr;
//     pthread_t thread;
    
//     //初始化线程属性
//     pthread_attr_init(&attr);
//     //设置线程属性的分离状态
//     pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

//     //创建线程
//     pthread_create(&thread,&ThreadFunc,NULL);
//     //清除线程属性对象
//     pthread_attr_destory(&attr);
//     //无需链接该线程
//     return 0;

// }

{
    int i;
    pthread_t threads[8];
    //创建键，使用CloseThreadLog()函数作为其清除程序
    pthread_key_create(&tlk,CloseThreadLog);

    for(i=0;i<8;++i)
        pthread_create(&threads[i],NULL,ThreadFunc,NULL);
    for(i=0;i<8;++i)
        pthread_join(threads[i],NULL);

    pthread_key_delete(tlk);

    return 0;
}