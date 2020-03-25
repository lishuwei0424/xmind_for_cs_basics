#include <iostream>
using namespace std;
#include <thread>

#include <cmath>

//2-2
void* IsPrime(void* n)
{
	unsigned long p=reinterpret_cast<unsigned long>(n);
	unsigned long i=3u,t=(unsigned long)sqrt(p)+1u;
	if(p==2u)
		return reinterpret_cast<void*>(true);
	if(p%2u==0u)
		return reinterpret_cast<void*>(false);

	while(i<=t)
	{
		if(p%i==0u)
			return reinterpret_cast<void*>(false);
			i+=2u;
	}
	return reinterpret_cast<void*>(true);
}

//2-1
// class InfoPrinted
// {
// public:
// 	InfoPrinted(char c,int n):_c(c),_n(n){}
// 	void Show() const
// 	{ for(int i=0;i<_n;i++)
// 		std::cerr<<_c;
		
// 	}
// private:
// 	char _c;
// 	int _n;
// };
   
// void* PrintInfo(void* info)
// {
// 	InfoPrinted* p=reinterpret_cast<InfoPrinted*>(info);//亚星指针
// 	if(p)	p->Show();
// 	return NULL;
// }


// 1
// void* PrintA(void* unused)
// {
// while(true) std::cerr<<'a';
// return NULL;
// }

// void* PrintZ(void* unused)
// {
// while(true) std::cerr<<'z';
// return NULL;
// }


int main()
{      
        //1
	//pthread_t thread_id;
	//pthread_create(&thread_id,NULL,&PrintA,NULL);
	//PrintZ(NULL);
     
    //     //2-1
    //     pthread_t tid1,tid2;
	// //构造InfoPrinted类的动态对象，作为线程函数参数传递给线程tid1
	// //输出100个‘a'
	// InfoPrinted* p=new InfoPrinted('a',100);
    //    pthread_create(&tid1,NULL,&PrintInfo,reinterpret_cast<void*>(p));
    //   //构造InfoPrinted类的动态对象，作为线程函数参数传递给线程tid2
	// //输出100个‘z'

	//   InfoPrinted* q=new InfoPrinted('z',100);
    //    pthread_create(&tid2,NULL,&PrintInfo,reinterpret_cast<void*>(q));

	//    //2-1程序大部分情况下不会输出结果
	//    //主线程不结束，子线程不会结束，因此子线程可以用主线程的参数
	//    pthread_join(tid1,NULL);
	//    pthread_join(tid2,NULL);

	//2-2
	pthread_t tids[8];
	bool primalities[8];
	int i;
	for(i=0;i<8;i++)
		pthread_create(&tids[i],NULL,&IsPrime,reinterpret_cast<void*>(i+2));
	for(i=0;i<8;i++)
		pthread_join(tids[i],reinterpret_cast<void**>(&primalities[i]));
	for(i=0;i<8;i++)
		std::cout<<primalities[i]<<" "<<endl;
		

 	return 0;
}
