//
//  Prim.cpp
//  Prim
//
//  Created by Setsuna on 2018/5/21.
//  Copyright © 2018年 Setsuna. All rights reserved.
//
#include "Prim.h"

Prim::Prim()
{
    visitIndex = 0;
    unvisitedIndex = 0;
    linesIndex = 0;
    //初始化未被访问节点
    for(char i = 0; i < MAX_LINE; i++)
    {
        visit[i] = i;
        unvisited[i] = i;
    }
}

Prim::~Prim()
{
    
}

void Prim::fit(char* graph)
{
    visit[visitIndex++] = 0;    // 访问第0个节点
    unvisited[0] = -1;          // 将第0个节点状态设置为已访问
    char row,col,sum = 0;
    Edge tmp_edge;
    while(visitIndex<MAX_LINE)
    {
        int min = 200;
        for(char i = 0; i < visitIndex; i++)
        {
            row = visit[i];
            for(char j = 0; j < MAX_LINE; j++)
            {
                if(unvisited[j] == -1)
                    continue;
                col = unvisited[j];
                if(*(graph+row*7+col) == -1)
                    continue;
                if(*(graph+row+col*7) < min)
                {
                    min = *(graph+row*7+col);
                    tmp_edge.row = row;
                    tmp_edge.col = col;
                }
            }
            
        }
        //找到最小min
        lines[linesIndex++] = tmp_edge;
        visit[visitIndex++] = tmp_edge.col;
        unvisited[tmp_edge.col] = -1;
        sum+=min;
    }
    //打印path和sum
    for(int i = 0; i < linesIndex; i++)
    {
        printf("<%d,%d>\n",lines[i].row+1,lines[i].col+1);
    }
    printf("total num is %d\n",sum);
    return;
}
