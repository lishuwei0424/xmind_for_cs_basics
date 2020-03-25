/*
// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H
*/

#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <stack>


bool hasPathCore(const char* matrix,int rows,int cols,int row,int col,const char* str,int& pathLeng,bool* visited);

//回溯法，从一点出发，查找它周围的四个点是否满足下一个点
bool hasPath(const char* matrix,int rows,int cols,const char* str)
{
    if(matrix==NULL || rows<1 || cols<1 || str==NULL)
        return false;

    //定一个是否遍历到的矩阵，记录这个数已经遍历过了
    bool *visited=new bool[rows*cols];
    memset(visited,0,rows*cols);

    //要找的字符串的路径长度
    int pathLeng=0;
    for(int row=0;row<rows;++row)
    {
        for(int col=0;col<cols;++col)
        {
            if(hasPathCore(matrix,rows,cols,row,col,str,pathLeng,visited))
                return true;
        }
    }

    delete[] visited;

    return false;
}

bool hasPathCore(const char* matrix,int rows,int cols,int row,int col,const char* str,int& pathLeng,bool* visited)
{
    //找到结尾了
    if(str[pathLeng]=='\0')
        return true;

    //开始查找matrix中是否有str中的字符
    bool hasPath=true;
    if(row>=0 && row<rows && col>=0 && col<=cols && matrix[row*cols+col]==str[pathLeng] && !visited[row*cols+col])
    {
        ++pathLeng;//找到一个相等
        //路过了
        visited[row*cols+col]=true;

        //从它的四周开始查找下一个
        hasPath=hasPathCore(matrix,rows,cols,row,col-1,str,pathLeng,visited)
            || hasPathCore(matrix,rows,cols,row-1,col,str,pathLeng,visited)
            || hasPathCore(matrix,rows,cols,row,col+1,str,pathLeng,visited)
            || hasPathCore(matrix,rows,cols,row+1,col,str,pathLeng,visited);

        //如果都没找到，回到上一个节点
        if(!hasPath)
        {
            --pathLeng;
            visited[row*cols+col]=false;
        }
    }

    return hasPath;
}

int main()
{  
//ABTG
//CFCS
//JDEH

//BFCE

     const char* matrix = "ABTGCFCSJDEH";
     const char* str = "BFCE";

     bool result=hasPath(matrix,3,4,str);
     cout<<result<<endl;


    return 0;
}