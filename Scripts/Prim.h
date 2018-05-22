//
//  Prim.h
//  Prim
//
//  Created by Setsuna on 2018/5/21.
//  Copyright © 2018年 Setsuna. All rights reserved.
//

#ifndef Prim_h
#define Prim_h

#include <iostream>
#include <stdio.h>
#include <queue>
#define MAX_LINE 7  //图的节点数
#endif /* Prim_h */

// 定义边
typedef struct
{
    char row;
    char col;
}Edge;

// 定义Prim算法类
class Prim
{
private:
    char visit[MAX_LINE]; //存储访问过的节点
    char unvisited[MAX_LINE]; //存储未被访问过的节点
    int visitIndex,unvisitedIndex,linesIndex; //索引
    Edge lines[MAX_LINE*MAX_LINE];
    
public:
    Prim(/* args */);
    ~Prim();
    void fit(char* graph);
};
