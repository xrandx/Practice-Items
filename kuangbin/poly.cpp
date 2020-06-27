/* 20161506146 汤鸿剑  */ 
/* Windows 10 / Dev C++ / VScode */

#include <stdio.h>
#include <stdlib.h>

typedef struct tag_poly
{
	int coef;
	int exp;
	struct tag_poly *next;
} poly, *polylnk;


int InitPoly(polylnk &head, polylnk &tail)
{
	head = (poly*)malloc(sizeof(poly));
	head->next = NULL;
	head->exp = -1;
	head->coef = -1;
	tail = head;
	return 1;
}

int PolyCreate(polylnk &head, polylnk &tail, poly elem)
{
	polylnk p;
	p = (poly*)malloc(sizeof(poly));
	*p = elem;
	tail->next = p;
	tail = p;
	p->next = NULL;
	return 1;
}

int ViewPoly(polylnk head)
{
	polylnk p;
	p = head->next;
	printf("\nF(x) = ");
	while(p)
	{
		printf("%dx^%d", p->coef, p->exp);
		if(p->next)
			printf(" + ");
		p = p->next;
	}
	printf("\n");
	return 1;
}

int MergePoly(polylnk &h1, polylnk &h2)
{
	polylnk p1, p2, tmp1, tmp2, pre;
	pre = h1;
	p1 = h1->next;
	p2 = h2->next;
	while(p1 && p2)
	{
		if(p1->exp > p2->exp)
		{
			pre->next = p2;
			tmp2 = p2->next;
			p2->next = p1;
			pre = p1;
			p1 = p1->next;
			p2 = tmp2;
		}
		else if(p1->exp < p2->exp)
		{
			pre = p1;
			tmp1 = p1->next;
			p1->next = p2;
			tmp2 = p2->next;
			p2->next = tmp1;
			p2 = tmp2;
			p1 = tmp1;
		}
		else
		{
			p1->coef = p1->coef + p2->coef;
			pre = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	if(!p1 && p2)
		pre->next = p2;
    return 1;
}

int main()
{
	polylnk pa, pb;
	polylnk ta, tb;
	poly e;
	InitPoly(pa, ta);
	InitPoly(pb, tb);
	printf("\n\n输入第一个多项式：\n");
	printf("输入系数和指数（用空格隔开，同时为0时结束）:\n");
	while(1)
	{
		scanf("%d %d", &e.coef, &e.exp);
		if(!e.coef)	break;
		PolyCreate(pa, ta, e);
	}
	ViewPoly(pa);
	printf("\n\n输入第二个多项式：\n");
	printf("输入系数和指数（用空格隔开，同时为0时结束）:\n");
	while(1)
	{
		scanf("%d %d", &e.coef, &e.exp);
		if(!e.coef)	break;
		PolyCreate(pb, tb, e);
	}
	ViewPoly(pb);
	MergePoly(pa, pb);
	printf("\n\n\n合并后：\n");
	ViewPoly(pa);
	printf("\n\n");
	system("pause");
	return 0;
}
