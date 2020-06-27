/* 20161506146 汤鸿剑  */ 
/* Windows 10 / Dev C++ / VScode */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct StudentElem
{
	int id;
	char name[20];
	double score;
} stu;

typedef struct StudentList
{
	stu data;
	int elemF;
	struct StudentList *next;
} stul;

void LoopCLS()
{
	getchar();
	printf("\n回车以返回菜单。\n");
	while(getchar()!='\n');
	system("cls");
	return;
}

stul* InitList(stul *h)
{
	h = (stul*)malloc(sizeof(stul));
	h->next = NULL;
	h->elemF = 1;
	return h;
}

void Destroy(stul *h)
{
	free(h);
	h = NULL;
}

/*
stul* ClearList(stul *h)
{
	if(h)
	{
		free(h);
		h = (stul*)malloc(sizeof(stul));
		return h;
	}
	else
	{
		printf(" 0");
		return NULL;
	}
}

int ListEmpty(stul *h)
{
	if(h->next)
	{
		return 1;
	}
	else
		return 0;
}
*/

int ListLength(stul *h)
{
	stul *p;
	int i = 0;
	p = h->next;
	while(p)
	{
		i++;
		p = p->next;
	}
	return i;
}

int GetElem(stul *h, int i)
{
	stul *p = h;
	if(i<1 || i> h->elemF-1)
	{
		printf("查找位置有误。\n");
		return 0;
	}
	while(i--)
	{
		p = p->next;
	}
	printf("\n学号：%d\n", p->data.id);
	printf("姓名：%s\n", p->data.name);
	printf("成绩：%.2lf\n", p->data.score);
	return 1;
}

int ElemFind(stul *h)
{
	int op = 2;
	stu ef;
	stul *p;
	p = h->next;
	printf("输入1按学号查找，输入0按姓名查找:\n");
	while(op != 1 && op!= 0)
		scanf("%d", &op);
	if(op)
	{
		printf("输入学号：");
		scanf("%d", &ef.id);
	}
	else
	{
		printf("输入姓名：");
		scanf("%s", &ef.name);
	}
	if(op)
	{
		while(p && ef.id != p->data.id)
			p = p->next;
		if(p)
		{
			printf("%d\n", p->data.id);
			printf("%s\n", p->data.name);
			printf("%.2lf\n", p->data.score);
			return 1;
		}
		else
		{
			printf("未找到元素。");
			return 0;
		}
	}
	else
	{
		while(p && strcmp(ef.name,p->data.name))
		{
			p = p->next;
		}
		if(p)
		{
			printf("学号: %d\n", p->data.id);
			printf("姓名：%s\n", p->data.name);
			printf("成绩：%.2lf\n", p->data.score);
			return 1;
		}
		else
		{
			printf("未找到元素。");
			return 0;
		}
	}
}

int CreateElem(stul *h)
{
	//采用头插法
	stul *tmp;
	tmp = h->next;
	h->next = (stul*)malloc(sizeof(stul));
	printf("\n请输入:\n");
	printf("学号: ");
	scanf("%d", &h->next->data.id);
	printf("姓名: ");
	scanf("%s", h->next->data.name);
	printf("成绩: ");
	scanf("%lf", &h->next->data.score);
	h->next->next = tmp;
	h->elemF++;
	return 1;
}

int ViewElem(stul *h)
{
	stul *p = h->next;
	if(!p)
	{
		printf("无元素可查看。");
		return 0;
	}
	while(p)
	{
		printf("\n学号：%d\n", p->data.id);
		printf("姓名：%s\n", p->data.name);
		printf("成绩：%.2lf\n\n", p->data.score);
		p = p->next;
	}
	return 1;
}

int InsertList(stul *h, int i)
{
	stul *p = h;
	stul *tmp;
	if(i<1 || i> h->elemF-1)
	{
		printf("插入位置有误。\n");
		return 0;
	}
	i--;
	while(i--)
	{
		p = p->next;
	}
	tmp = p->next;
	p->next = (stul*)malloc(sizeof(stul));
	h->elemF++;
	printf("请输入:\n");
	printf("学号:");
	scanf("%d", &p->next->data.id);
	printf("姓名:");
	scanf("%s", p->next->data.name);
	printf("成绩：");
	scanf("%lf", &p->next->data.score);
	p->next->next = tmp;
	return 1;
}

int DeleteElem(stul *h, int i)
{
	stul *p = h;
	stul *tmp;
	if(i<1 || i> h->elemF-1)
	{
		printf("删除位置有误。\n");
		return 0;
	}
	i--;
	while(i--)
	{
		p = p->next;
	}
	tmp = p->next->next;
	free(p->next);
	p->next = tmp;
	h->elemF--;
	return 1;
}

void MergeList(stul *h, stul *h2)
{
	stul *p;
	p = h;
	while(1)
	{
		if(!p->next)
			break;
		p = p->next;
	}
	p->next = h2->next;
	return;
}

int ModifyElem(stul *h, int i)
{
	stul *p = h;
	if(i<1 || i> h->elemF-1)
	{
		printf("位置有误。\n");
		return 0;
	}
	while(i--)
	{
		p = p->next;
	}
	printf("已找到，请输入:\n");
	printf("学号：");
	scanf("%d", &p->data.id);
	printf("姓名：");
	scanf("%s", p->data.name);
	printf("成绩：");
	scanf("%lf", &p->data.score);

}
void menu()
{
	printf("1.新建链表元素\n");
	printf("2.插入链表元素\n");
	printf("3.删除链表元素\n");
	printf("4.按序号查找链表元素\n");
	printf("5.按姓名学号查找元素\n");
	printf("6.修改链表元素\n");
	printf("7.查看元素个数\n");
	printf("8.浏览所有元素\n");
	printf("9.新建链表并合并\n");
	printf("\n0.清空所用内存并退出\n");
}

int main()
{
	stul *h;
	h = NULL;
	int i;
	int op;
	if(h = InitList(h))
		printf("初始化链表成功。\n");
	while(1)
	{
		menu();
		scanf("%d", &op);
		switch(op)
		{
			case 1:
				system("cls");
				if(CreateElem(h))
					printf("创建完毕。\n");
				break;
			case 2:
				system("cls");
				printf("输入插入元素位置:");
				scanf("%d",&i);
				if(InsertList(h, i))
					printf("插入完毕。");
				break;
			case 3:
				system("cls");
				printf("输入删除元素位置:");
				scanf("%d",&i);
				if(DeleteElem(h, i))
					printf("删除完毕。");
				break;
			case 4:
				system("cls");
				printf("输入查找元素位置:");
				scanf("%d",&i);
				if(GetElem(h, i))
					printf("完毕。");
				break;
			case 5:
				system("cls");
				if(ElemFind(h))
					printf("完毕。\n");
				break;
			case 6:
				system("cls");
				printf("输入元素位置:");
				scanf("%d",&i);
				if(ModifyElem(h, i))
					printf("完毕。\n");
				break;
			case 7:
				system("cls");
				printf("元素个数为 %d 个\n", ListLength(h));
				printf("表长为 %d 个", h->elemF);
				break;
			case 8:
				system("cls");
				ViewElem(h);
				break;
			case 9:
				system("cls");
				stul* h2;
				int n;
				h2 = InitList(h2);
				printf("输入新建元素个数:");
				scanf("%d",&n);
				for(i=0; i<n; i++)
				{
					CreateElem(h2);
				}
				MergeList(h, h2);
				break;
			case 0:
				system("cls");
				Destroy(h);
				exit(1);
				break;
			default:
				system("cls");
				printf("输入失误。");
				break;
		}
		LoopCLS();
	}


	return 0;
}


