#include "linknode.h"

#if 0
void backaddnode(Node **ppnode, int num, datatype data) //增加一个节点
{
	Node *pnewnode = (Node *)malloc(sizeof(Node));
	pnewnode->num = num;
	pnewnode->data = data;
	pnewnode->pNext = NULL;
	if (*ppnode == NULL)
	{
		*ppnode = pnewnode; //存储新建节点的地址
	}
	else
	{
		Node *p = *ppnode;
		while (p->pNext != NULL)
		{
			p = p->pNext;
		}
		p->pNext = pnewnode;
	}
}
#endif // 0

Node * backaddnode(Node * ppnode, int num, datatype data)
{
	Node *pnewnode = (Node *)malloc(sizeof(Node));
	pnewnode->num = num;
	pnewnode->data = data;
	pnewnode->pNext = NULL;
	if (ppnode == NULL)
	{
		ppnode = pnewnode; //存储新建节点的地址
	}
	else
	{
		Node *p = ppnode;
		while (p->pNext != NULL)
		{
			p = p->pNext;
		}
		p->pNext = pnewnode;
	}
	return ppnode;
}

void showallnode(Node *pnode) //显示所有节点
{
	printf("\n打印链表:  \n");
	while (pnode != NULL)
	{
		printf("%p, %p ", pnode, pnode->pNext);
		printf("%d, %d\n", pnode->num, pnode->data);
		pnode = pnode->pNext;
	}
}

Node *searchfirst(Node *pnode, int num)
{
	for (Node *p = pnode; p != NULL; p = p->pNext)
	{
		if(num==p->num) return p;
	}
	return NULL;
}

int change(Node *pnode, int oldnum, int newnum)
{
#if 0
	for (Node *p = pnode; p != NULL; p = p->pNext)
	{
		if (oldnum == p->num)
		{
			p->num = newnum;
			return 1;
		};
	}
	return NULL;
#endif // 0

AAA: 
	if (pnode != NULL)
	{
		if (oldnum == pnode->num)
		{
			pnode->num = newnum;
			return 1;
		}
		pnode = pnode->pNext;
		goto AAA;
	}
	
	return 0;
}

Node *rev(Node *pnode)
{
	Node *p1, *p2, *p3;
	p1 = p2 = p3 = NULL;
	if (pnode == NULL || pnode->pNext == NULL)
	{
		return pnode;
	}
	else
	{
		p1 = pnode;
		p2 = pnode->pNext;
		while (p2 != NULL)
		{
			p3 = p2->pNext;
			p2->pNext = p1;//地址转向
			p1 = p2;
			p2 = p3;
		}
		pnode->pNext = NULL;
		pnode = p1;
		return pnode;
	}

}

Node *delete(Node *pnode, int num)
{
	Node *p1 = NULL, *p2 = NULL;
	p1 = pnode;
	while (p1 != NULL)
	{
		if (p1->num == num)
		{
			break;
		}
		else
		{
			p2 = p1; //保存上一个节点
			p1 = p1->pNext;
		}
	}

	if (p1 == pnode)
	{
		pnode = p1->pNext;
		free(p1);
	}
	else
	{
		p2->pNext = p1->pNext;
		free(p1);
	}
	return pnode;

}

Node * insert(Node *pnode, int findnum, int newnum, datatype data)
{
	Node *p1, *p2;

	p1 = p2 = NULL;
	p1 = pnode;
	while (p1 != NULL)
	{
		if (p1->num == findnum)
		{
			break;
		}
		else
		{
			p2 = p1; //保存上一个节点
			p1 = p1->pNext;
		}
	}
	Node *pnewnode = malloc(sizeof(Node));
	pnewnode->num = newnum;
	pnewnode->data = data;

	if (pnode == p1)
	{
		pnewnode->pNext = pnode;
		pnode = pnewnode;
	}
	else
	{
		pnewnode->pNext = p1;
		p2->pNext = pnewnode;
	}
	return pnode;
}

void sort(Node *pnode, char ch)
{
	if (ch == '<')
	{
		for (Node *p1=pnode; p1 != NULL; p1 = p1->pNext)
		{
			for (Node *p2=pnode; p2 != NULL; p2 = p2->pNext)
			{
				if (p1->num < p2->num)
				{
					Node tnode = {p1->num, p1->data};
					p1->num = p2->num;
					p2->num = tnode.num;

					p1->data = p2->data;
					p2->data = tnode.data;
				}
			}
		}
	}
	else
	{
		for (Node *p1 = pnode; p1 != NULL; p1 = p1->pNext)
		{
			for (Node *p2 = pnode; p2 != NULL; p2 = p2->pNext)
			{
				if (p1->num > p2->num)
				{
					Node tnode = { p1->num, p1->data};
					p1->num = p2->num;
					p2->num = tnode.num;

					p1->data = p2->data;
					p2->data = tnode.data;
				}
			}
		}
	}
}