#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "linknode.h"

int main()
{
	Node *pnode = NULL;

	pnode = backaddnode(pnode, 1, 11);
	pnode = backaddnode(pnode, 32, 22);
	pnode = backaddnode(pnode, 3, 22);
	pnode = backaddnode(pnode, 4, 22);
	pnode = backaddnode(pnode, 51, 22);
	showallnode(pnode);
	//pnode = rev(pnode);
	/*pnode = delete(pnode, 1);
	showallnode(pnode)*/;
	//pnode = insert(pnode, 3, 21, 90);
	sort(pnode, '>');
	showallnode(pnode);




#if 0
	backaddnode(&pnode, 1, 11);
	backaddnode(&pnode, 2, 11);
	backaddnode(&pnode, 3, 11);
	backaddnode(&pnode, 4, 11);

	Node *pfind = searchfirst(pnode, 5);
	if (pfind == NULL)
	{
		printf("没有找到");
	}
	else
	{
		printf("找到了 %p , %d , %d , %p", pfind, pfind->num, pfind->data, pfind->pNext);
	}

	
#endif // 0
	system("pause");
}
