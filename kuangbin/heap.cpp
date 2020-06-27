/* 20161506146 汤鸿剑  */ 
/* Windows 10 / Dev C++ / VScode */
#include <stdio.h>
#include <stdlib.h>

const int minn = -1000;
const int maxn = 1000;
typedef struct fqlist
{
	char ch;
	int freq;
	struct fqlist *lc = NULL;
	struct fqlist *rc = NULL;
} fq, *fqptr;

typedef struct minheap
{
	fqptr data;
	int size;
	int capacity;
} minheap, *mhptr;

/*
typedef struct hft
{
	fq node;
	struct hft *lc, *rc;
} hft, *hftptr;
*/
int isfull(mhptr h)
{
	return (h->size == h->capacity);
}

int isempty(mhptr h)
{
	return (h->size == 0);
}

mhptr createh(int maxsize)
{
	mhptr h = (mhptr)malloc(sizeof(minheap));
	h->data = (fqptr)malloc((maxsize + 1)*sizeof(fqlist));
	h->size = 0;
	h->capacity = maxn;
	h->data[0].freq = minn;
	for(int i = 1; i < maxsize + 1; i++, h->size++)
	{
		getchar();
		printf("序号：%d\n", i);
		printf("输入字符：");
		scanf("%c", &h->data[i].ch);
		printf("输入频率：");
		scanf("%d", &h->data[i].freq);
		printf("\n");
	}
	return h;
}


void percdown(mhptr h, int parent)
{
	int child;
	fq x;
	x = h->data[parent];
	for(; parent * 2 <= h->size; parent = child)
	{
		child = parent * 2;
		if((child != h->size) && (h->data[child].freq > h->data[child + 1].freq))
			child++;
		if(x.freq <= h->data[child].freq) break;
		else
			h->data[parent] = h->data[child];
	}
	h->data[parent] = x;
}

void buildh(mhptr h)
{
	for(int i = h->size / 2; i > 0; i--)
	{
		percdown(h, i);
	}
}

fq deletemin(mhptr h)
{
	fq x, min;
	int parent, child;
	x.freq = -1;
	x.ch = '-';
	if(isempty(h))
		return x;
	min = h->data[1];
	x = h->data[h->size--];
	for(parent = 1; parent * 2 <= h->size; parent = child)
	{
		child = parent * 2;
		if((child != h->size) && (h->data[child].freq > h->data[child + 1].freq))
			child++;
		if((x.freq > h->data[child].freq))
			h->data[parent] = h->data[child];
		else
			break;
	}
	h->data[parent] = x;
	return min;
}

int insert(mhptr h, fq x)
{
	//h->data[0]为哨兵,其freq为-1000
	if(isfull(h))
		return 0;
	int i = ++h->size;
	for( ; h->data[i / 2].freq > x.freq; i /= 2)
		h->data[i] = h->data[i / 2];
	h->data[i] = x;
	return 1;
}

void createhft(mhptr h)
{
	fq elem;
	int n = h->size - 1;

	for(int i = 0; i < n; i++)
	{
		elem.ch = '-';
		elem.lc = (fqptr)malloc(sizeof(fq));
		*elem.lc = deletemin(h);

		elem.rc = (fqptr)malloc(sizeof(fq));
		*elem.rc = deletemin(h);

		elem.freq = elem.lc->freq + elem.rc->freq;
		insert(h, elem);
	}
}


void pretraval(fqptr p, int i, char *code)
{
	if(p)
	{
		if(!p->lc && !p->rc)
		{
			code[i] = '\0';
			printf("字符：%c  编码：%s 频率：%d\n", p->ch, code, p->freq);
		}
		code[i] = '0';
		pretraval(p->lc, i+1, code);
		code[i] = '1';
		pretraval(p->rc, i+1, code);
	}
}

int main()
{
	int maxsize;
	printf("输入表的大小：");
	scanf("%d", &maxsize);
	char code[maxsize];
	mhptr h = createh(maxsize);
	buildh(h);
/*
	fq elem;
	do
	{
		elem = deletemin(h);
		printf("%c %d ",elem.ch, elem.freq);
	}
	while(elem.freq != -1);
*/
	createhft(h);
	fqptr p = &h->data[1];
	pretraval(p, 0, code);
	system("pause");
	return 0;
}
