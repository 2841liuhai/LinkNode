#pragma once
#include <stdio.h>
#include <stdlib.h>

#define datatype int

struct node
{
	int num;
	datatype data;
	struct node *pNext;
};

typedef struct node Node;

// 增加 删除 修改 查询 排序 反转

//void backaddnode(Node **ppnode, int num, datatype data); //增加一个节点
Node *backaddnode(Node *ppnode, int num, datatype data);
Node *searchfirst(Node *pnode, int num); // 查询
void showallnode(Node *pnode); //显示所有节点
int change(Node *pnode, int oldnum, int newnum); // 修改
Node *rev(Node *pnode); // 逆转
Node *delete(Node *pnode, int num); // 删除
Node * insert(Node *pnode, int findnum, int newnum, datatype data); //插入
void sort(Node *pnode, char ch); // ch==>  ch==<