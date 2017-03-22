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

// ���� ɾ�� �޸� ��ѯ ���� ��ת

//void backaddnode(Node **ppnode, int num, datatype data); //����һ���ڵ�
Node *backaddnode(Node *ppnode, int num, datatype data);
Node *searchfirst(Node *pnode, int num); // ��ѯ
void showallnode(Node *pnode); //��ʾ���нڵ�
int change(Node *pnode, int oldnum, int newnum); // �޸�
Node *rev(Node *pnode); // ��ת
Node *delete(Node *pnode, int num); // ɾ��
Node * insert(Node *pnode, int findnum, int newnum, datatype data); //����
void sort(Node *pnode, char ch); // ch==>  ch==<