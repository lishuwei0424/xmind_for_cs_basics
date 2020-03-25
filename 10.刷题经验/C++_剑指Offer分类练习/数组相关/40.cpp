
// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <functional>

//定义最大堆，最上面就是最大元素
//创建一个大小为k的数据容器来存储最小的k个数字，每次从输入的n个整数中读入一个数
//若容器中已有的数字少于k个，则直接把这次读入的整数放入容器;
//若已经有了k个数字，也就是容器满了，把大堆的最大元素和当前数字比较，替换

typedef multiset<int,greater<int>> intSet;
typedef multiset<int,greater<int>>::iterator setIterator;

void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k)
{
    leastNumbers.clear();

    if(k<1 || data.size()<k)
        return;

    vector<int>::const_iterator iter=data.begin();
    for(;iter!=data.end();++iter)
    {
        if(leastNumbers.size()<k)
            leastNumbers.insert(*iter);

        else
        {
            setIterator iterGreatest=leastNumbers.begin();//把大顶堆的最大数拿出来
            
            if(*iter<*(leastNumbers.begin()))
            {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
        
    }
}


int main(int argc, char* argv[])
{   
   int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    intSet leastNumbers;

    vector<int> vectorData;
    for(int i = 0; i <  sizeof(data) / sizeof(int); ++ i)
        vectorData.push_back(data[i]);

    GetLeastNumbers(vectorData,leastNumbers,4);
   for(setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
          printf("%d\t", *iter);
     printf("\n\n");


    return 0;
}

