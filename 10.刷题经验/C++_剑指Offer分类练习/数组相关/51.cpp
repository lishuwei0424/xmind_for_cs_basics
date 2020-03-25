// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

 #include <iostream>
using namespace std;

//数组{7,5,6,4}中一共存在5个逆序对，分别是（7,6），（7,5），（7,4），（6,4），（5,4）

//先分成两个数组，{7,5} {6,4}，判断可以构成
//然后进行排序{5,7 }  {4,6}
//在上面上个数组定义两个指针分别指向最后一个元素，p1-7  p2-6 同时定义一个辅助数组依次存放最大值
//p1>p2,则存在数值2中的逆序对，，，，跑p1<p2则把存在

 int InversePairsCore(int* data, int* copy,int start,int end);

int InversePairs(int* data,int leng)
{
    if(data==nullptr || leng<0)
        return 0;

    int* copy=new int[leng];
    for(int i=0;i<leng;++i)
        copy[i]=data[i];

    int count=InversePairsCore(data,copy,0,leng-1);

}

 int InversePairsCore(int* data, int* copy,int start,int end)
 {
     if(start==end)
     {
         copy[start]=data[start];
         return 0;
     }

    int leng=(end-start)/2;

    int left=InversePairsCore(copy,data,start,start+leng);//前半部分额
    int right=InversePairsCore(copy,data,start+leng+1,end);//后半部分

    //i初始化为前半段最后一个数字的下标
    int i=start+leng;
    //j初始化后半段最后一个数字的下标
    int j=end;

    int indexCopy=end;
    int count=0;

    while(i>=start && j>=start+leng+1)
    {
        if(data[i]>data[j])
        {
            //肯定存在逆对
            //把最大数放在辅助数组
            copy[indexCopy--]=data[i--];
            //就是i和后面的几个都组成逆对
            count+=j-start-leng;

        }

        else
        {
            copy[indexCopy--]=data[j--];//不存在逆对，把j放在辅助数组里，j--前移再继续比较
        }
    }

    for(;i>=start;--i)
        copy[indexCopy--]=data[i];

    for(;j>=start+leng+1;--j)
        copy[indexCopy--]=data[j];

    return left+right+count;
     
 }

int main()
{
     int data[] = { 1, 2, 3, 4, 7, 6, 5 };
  
    int result=InversePairs(data,sizeof(data)/sizeof(int));

    cout<<result<<endl;

    return 0;
}