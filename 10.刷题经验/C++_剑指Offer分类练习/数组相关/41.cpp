

// 面试题41：数据流中的中位数
// 题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
// 中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
// 那么中位数就是所有数值排序之后中间两个数的平均值。

#include <iostream>
using namespace std;
#include <cstring>

#include <algorithm>
#include <vector>
#include <functional>

#include <stdexcept>
//设计一个大顶堆和一个小顶堆，max在前，min在后，满足两者的数目相等，或者仅仅相差1
//此时若相差1，则取min中的最小值，若相等取max的最大值和min最小值和的一半

template<typename T> 
class DynamicArrary
{
    public: 
        void Insert(T num)
        {   
            //奇数
            if(((min.size() + max.size()) &1)==0 )
            {
                if(max.size()>0 && num<max[0])
                {
                    //新插入的数比大顶堆最大还大
                    //则把最大拿出来，放在小顶堆
                    //这样就保证大顶堆的数始终小于小顶堆，即排序前进
                    max.push_back(num);
                    push_heap(max.begin(),max.end(),less<T>());
                    //以上两个命令连用，把num放在合适位置，放在max的最大值位置

                    num=max[0];
                    
                    //以下两个也连用，使最大值出来
                    pop_heap(max.begin(),max.end(),less<T>());
                    max.pop_back();
                }
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());
        }
            

            else
            {    
                //同理新插入的num比最小堆的最小值小，把最小值拿出来，放在最大堆里
                if(min.size()>0 && min[0]<num)
                {
                 
                    min.push_back(num);
                   push_heap(min.begin(),min.end(),greater<T>());

                num=min[0];

                pop_heap(min.begin(),min.end(),greater<T>());
                min.pop_back();
                }
                
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<T>());
            }
        }

        T GetMedian()
        {
            int size=min.size()+max.size();
            if(size==0)
                //throw exception("no numbers are available");
            {
                   std::logic_error ex("no numbers are available");
                   throw std::exception(ex);
            }
             

            T median=0;
            if((size & 1)==1)//奇数
                median=min[0];
            else
              median=(min[0]+max[0])/2;

            return median;
        }

    private:
        vector<T> min;
        vector<T> max;
};




int main(int argc, char* argv[])
{
    DynamicArrary<double> numbers;

    numbers.Insert(5);
    numbers.Insert(2);
    numbers.Insert(3);
    numbers.Insert(4);
    numbers.Insert(1);

  
        double result=numbers.GetMedian();

        cout<<result<<endl;
       
    
  
    return 0;
}

