// 面试题47：礼物的最大价值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
// （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或
// 者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
// 算你最多能拿到多少价值的礼物？

/*
    //四行四列
    int values[][4] = {
        { 1, 10, 3, 8 },
        { 12, 2, 9, 6 },
        { 5, 7, 4, 11 },
        { 3, 7, 16, 5 }
    };

    1-12-5-7-7-16
*/

#include <algorithm>
#include <iostream>
using namespace std;

//定义一个函数f(i,j)表示达到坐标（i，j)的格子时能拿到的礼物总和最大值
//两种途径到达f(i,j),第一中f(i-1,j)和f(i,j-1)
//f(i,j)=max(f(i-1,j),f(i,j-1))+gift(i,j)

//由于递归有大量的重复计算。为了缓存中间的计算结果，需要一个辅助的二维数组
//数组中坐标为（i，j)的元素表示到达坐标为（i，j)的格子时能拿到的礼物价值总和的最大值

/*int getMax_value(const int* values, int rows, int cols)
{
    if(values==NULL || rows<=0 || cols<=0)
        return 0;
    
    int** max_Values=new int*[rows];//定义一个二维数组
    for(int i=0;i<rows;++i)
        max_Values[i]=new int[cols];

    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            int left=0;
            int up=0;

            if(i>0)
                up=max_Values[i-1][j];

            if(j>0)
                left=max_Values[i][j-1];

            max_Values=std::max(left,up)+values[i*cols+j];
        }
    }

    int max_Value=max_Values[rows-1][cols-1];

    for(int i=0;i<rows;++i)
        delete[] max_Values[i];
    delete[] max_Values;

    return max_Value;
}*/

int getMaxValue(const int* values, int rows, int cols)
{
    if(values == nullptr || rows <= 0 || cols <= 0)
        return 0;

    int** maxValues = new int*[rows];
    for(int i = 0; i < rows; ++i)
        maxValues[i] = new int[cols];

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            int left = 0;
            int up = 0;

            if(i > 0)
                up = maxValues[i - 1][j];

            if(j > 0)
                left = maxValues[i][j - 1];

            maxValues[i][j] = std::max(left, up) + values[i * cols + j];
        }
    }

    int maxValue = maxValues[rows - 1][cols - 1];

    for(int i = 0; i < rows; ++i)
        delete[] maxValues[i];
    delete[] maxValues;

    return maxValue;
}

int main()
{
     int values[][4] = {
        { 1, 10, 3, 8 },
        { 12, 2, 9, 6 },
        { 5, 7, 4, 11 },
        { 3, 7, 16, 5 }
    };

    int result=getMaxValue( (const int*) values, 4, 4);
    cout<<result<<endl;

    return 0;
}