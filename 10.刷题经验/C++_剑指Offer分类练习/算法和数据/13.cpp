/*
// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
*/

#include <iostream>
using namespace std;

//同12，回溯法
//机器人从（0,0）开始，判断满足不？然后四周查找
int movingCountCore(int threshold,int rows,int cols,int row,int col,bool* visited);
bool check(int threshold,int rows,int cols,int row,int col,bool* visited);
int getDigitSum(int data);

int movingCount(int threshold,int rows,int cols)
{
    if(threshold<0 || rows<=0 || cols<=0)
        return 0;

    //定义一个矩阵，判断走过没哦
    bool *visited=new bool[rows*cols];
    for(int i=0;i<rows*cols;++i)
        visited[i]=false;

    //开始计算多少个格子
    int count=movingCountCore(threshold,rows,cols,0,0,visited);

    delete[] visited;

    return count;
}

int movingCountCore(int threshold,int rows,int cols,int row,int col,bool* visited)
{
    //计算机器人可以走多少格子
    int count=0;

    if(check(threshold,rows,cols,row,col,visited))
    {
       visited[row*cols+col]=true;

       count=1+movingCountCore(threshold,rows,cols,row,col-1,visited)+
                movingCountCore(threshold,rows,cols,row-1,col,visited)+
                movingCountCore(threshold,rows,cols,row,col+1,visited)+
                movingCountCore(threshold,rows,cols,row+1,col,visited);
    }

    return count;
}

bool check(int threshold,int rows,int cols,int row,int col,bool* visited)
{
    //检查是否满足阈值条件
    if(row>=0 && row<=rows && col>=0 && col<cols
    && getDigitSum(row)+getDigitSum(col)<=threshold
    && !visited[row*cols+col])
        return true;

    return false;
}

//计算位数的和
int getDigitSum(int data)
{
    int sum=0;
    while(data>0)
    {
        sum+=data%10;
        data/=10;
    }

    return sum;
}
int main()
{
    int result=movingCount(5,10,10);

    cout<<result<<endl;

    return 0;

}