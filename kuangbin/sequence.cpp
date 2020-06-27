#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct StudentStructure
{
	int id;
	char name[20];
	double score;
} stu;

typedef struct StudentSequenceList
{
	stu *base;
	int elemFinalNum;
} stusql;


int InitList(stusql &L)
{
	L.base = (stu*)malloc(sizeof(stu));
	if(!L.base)
	{
		printf("初始化出错。\n");
		return 0;
	}
	L.elemFinalNum = 1;//表尾后一个元素的序号 = 表长
	return 1;
}

int CreateElem(stusql &L, stu e)
{
	stu *newbase;
	newbase = (stu*)realloc(L.base, (L.elemFinalNum + 1)*sizeof(stu));
	if(!newbase)
	{
		printf("分配内存出错。\n");
		return 0;
	}
	L.base = newbase;
	L.base[L.elemFinalNum] = e;
	L.elemFinalNum++;
	return 1;
}

int InsertList(stusql &L, int i)
{
	stu e;
	if(!(i >= 1 && i <= L.elemFinalNum))
	{
		printf("插入位置不正确。\n");
		return 0;
	}
	printf("学号:");
	scanf("%d", &e.id);
	printf("姓名:");
	scanf("%s", e.name);
	printf("成绩:");
	scanf("%lf", &e.score);
	stu *newbase;
	newbase = (stu*)realloc(L.base, (L.elemFinalNum + 1)*sizeof(stu));
	if(!newbase)
	{
		printf("分配内存出错。\n");
		return 0;
	}
	L.base = newbase;
	L.elemFinalNum++;

	stu *q = &(L.base[i]);
	stu *p = &(L.base[L.elemFinalNum - 1]);

	while(p >= q)
	{
		*(p + 1) = *p;
		p--;
	}

	*q = e;
	return 1;


}

int DestroyList(stusql &L)
{
	if(!L.base)
	{
		printf("信息为空.\n");
		return 0;
	}
	free(L.base);
	L.base = NULL;
	return 1;
}

int DispalyList(stusql &L)
{
	if(L.elemFinalNum == 1)
	{
		printf("当前无信息可查看.\n");
		return 0;
	}

	stu *p = &(L.base[1]);
	stu *q = &(L.base[L.elemFinalNum - 1]);
	while(p <= q)
	{
		printf("\n学号： %d\n", p->id);
		printf("姓名： %s\n", p->name);
		printf("成绩： %.2lf\n\n", p->score);
		p++;
	}
	return 1;

}

int ListDelete(stusql &L)
{
	int i;
	printf("查找序号为：");
	scanf("%d",&i);
	if(L.elemFinalNum == 1)
	{
		printf("信息为空。\n");
		return 0;
	}
	if(!(i >= 1 && i < L.elemFinalNum))
	{
		printf("删除位置不正确。\n");
		return 0;
	}
	stu *p = &(L.base[i]);
	stu *q = &(L.base[L.elemFinalNum - 1]);
	while(p < q)
	{
		*p = *(p + 1);
		p++;
	}
	printf("删除成功。\n");
	L.elemFinalNum--;
	return 1;

}

int ListLenth(stusql &L)
{
	return (L.elemFinalNum - 1);
}

int SearchList(stusql &L)
{
	system("cls");
	int i;
	printf("查找序号为：");
	scanf("%d",&i);
	if(i >= L.elemFinalNum || i<1)
	{
		printf("查找序号有误\n");
		return 0;
	}


	stu *p = &(L.base[i]);
	printf("\n学号： %d\n", p->id);
	printf("姓名： %s\n", p->name);
	printf("成绩： %.2lf\n\n", p->score);
	return 1;
}

stu *ListFind(stusql &L)
{
	int op = 0;
	int flag;
	stu e;
	while(!op)
	{
		printf("\n1.按学号查找。");
		printf("\n2.按姓名查找。\n");
		scanf("%d",&op);
		if(op == 1)
		{
			printf("\n请输入学号：");
			scanf("%d",&e.id);
			break;
		}
		else if(op == 2)
		{
			printf("\n请输入姓名：");
			scanf("%s",e.name);
			break;
		}
		else
		{
			op = 0;
			printf("输入有误。");
		}
	}
	stu *p = &L.base[1];
	stu *q = &L.base[L.elemFinalNum-1];
	flag = 0;
	if(op == 1)
	{
		while(flag == 0 && p <= q)
		{
			if(p->id == e.id)
			{
				flag = 1;
				break;
			}
			else
			{
				p++;
			}
		}

	}
	else if(op == 2)
	{
		while(flag == 0 && p <= q)
		{
			if(!strcmp(e.name,p->name))
			{
				flag = 1;
				break;
			}
			else
				p++;

		}

	}
	else
	{
		printf("发生错误。");
	}
	if(flag)
		return p;
	else
        {

            printf("发生错误。");
            return NULL;
        }



}

void Menu()
{
	printf("1.新建信息\n");
	printf("2.插入信息\n");
	printf("3.查找结点\n");
	printf("4.清除所有信息并初始化\n");
	printf("5.查看所有信息\n");
	printf("6.打印信息元素长度\n");
	printf("7.删除元素\n");
	printf("8.搜索元素\n");
	printf("\n-1.退出\n");
}


void LoopMenu()
{
    int m = 1;
	printf("==========\n");
	printf("输入0返回菜单:");
	while(~scanf("%d", &m))
	{
		if(!m)
			break;

	}
	system("cls");
}

int main()
{
	stusql h;
	stu e;
	stu *fe;
	int i;
	int n;
	if(InitList(h))
		printf("\n顺序表初始化成功。\n\n");

	while(1)
	{
		Menu();
		printf("\n输入序号以继续:");
		scanf("%d", &n);
		switch(n)
		{
			case 1:
				system("cls");
				printf("新建信息:\n");
				printf("学号:");
				scanf("%d", &e.id);
				printf("姓名:");
				scanf("%s", e.name);
				printf("成绩:");
				scanf("%lf", &e.score);
				if(CreateElem(h, e))
					printf("创建成功。\n");
				LoopMenu();
				break;
			case 2:
				system("cls");
				printf("插入信息:\n");
				printf("插入序号为:\n");
				scanf("%d", &i);
				if(InsertList(h, i))
					printf("插入成功。\n");
				LoopMenu();
				break;
			case 3:

				if(SearchList(h))
					printf("搜索完毕。\n");
				LoopMenu();
				break;


			case 4:
				if(DestroyList(h))
				{
					printf("销毁完毕。\n再次初始化...");
					if(InitList(h))
						printf("\n顺序表初始化成功。\n\n");
				}
				LoopMenu();
				break;


			case 5:
				system("cls");
				if(DispalyList(h))
					printf("\n");
				LoopMenu();
				break;
			case 6:
				system("cls");
				printf("元素个数为为%d\n",ListLenth(h));
				LoopMenu();
				break;
			case 7:
				system("cls");
				if(ListDelete(h))
					printf("\n");
				LoopMenu();
				break;
			case 8:
				system("cls");
				fe = ListFind(h);
				printf("\n学号： %d\n", fe->id);
				printf("姓名： %s\n", fe->name);
				printf("成绩： %.2lf\n\n", fe->score);
				LoopMenu();
				break;
			case -1:
				exit(0);
			default:
				system("cls");
		}

	}

	free(h.base);
	return 0;
}




