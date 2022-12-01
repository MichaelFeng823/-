#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXEDGE 20
#define MAXVEX 14

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

/* 邻接矩阵结构 */
typedef struct
{
	int vexs[MAXVEX];            //顶点数组
	int arc[MAXVEX][MAXVEX];     //顶点的邻接矩阵
	int numVertexes, numEdges;   //顶点数、边数
}MGraph;

/* 邻接表结构****************** */
typedef struct EdgeNode /* 边表结点  */
{
	int adjvex;    /* 邻接点域，存储该顶点对应的下标 */
	int weight;		/* 用于存储权值，对于非网图可以不需要 */
	struct EdgeNode* next; /* 链域，指向下一个邻接点 */
}EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
	int in;	/* 顶点入度 */
	int data; /* 顶点域，存储顶点信息 */
	EdgeNode* firstedge;/* 边表头指针 */
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges; /* 图中当前顶点数和边数 */
}graphAdjList, * GraphAdjList; /* 邻接表结构*/
/* **************************** */


void CreateMGraph(MGraph* G)/* 构件图 */
{
	int i, j;

	/* printf("请输入边数和顶点数:"); */
	G->numEdges = MAXEDGE;
	G->numVertexes = MAXVEX;

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		G->vexs[i] = i;
	}

	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	//初始化边上的权值(没有所谓的权值了在这里)
	//只有这两点之间有没有这条有向边
	G->arc[0][4] = 1;
	G->arc[0][5] = 1;
	G->arc[0][11] = 1;
	G->arc[1][2] = 1;
	G->arc[1][4] = 1;
	G->arc[1][8] = 1;
	G->arc[2][5] = 1;
	G->arc[2][6] = 1;
	G->arc[2][9] = 1;
	G->arc[3][2] = 1;
	G->arc[3][13] = 1;
	G->arc[4][7] = 1;
	G->arc[5][8] = 1;
	G->arc[5][12] = 1;
	G->arc[6][5] = 1;
	G->arc[8][7] = 1;
	G->arc[9][10] = 1;
	G->arc[9][11] = 1;
	G->arc[10][13] = 1;
	G->arc[12][9] = 1;

}

/* 利用邻接矩阵构建邻接表 */
void CreateALGraph(MGraph G, GraphAdjList* GL)
{
	int i, j;
	EdgeNode* e;

	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));

	(*GL)->numVertexes = G.numVertexes;
	(*GL)->numEdges = G.numEdges;
	for (i = 0; i < G.numVertexes; i++) /* 读入顶点信息，建立顶点表 */
	{
		(*GL)->adjList[i].in = 0;
		(*GL)->adjList[i].data = G.vexs[i];
		(*GL)->adjList[i].firstedge = NULL; 	/* 将边表置为空表 */
	}

	for (i = 0; i < G.numVertexes; i++) /* 建立边表 */
	{
		for (j = 0; j < G.numVertexes; j++)
		{
			if (G.arc[i][j] == 1)
			{
				e = (EdgeNode*)malloc(sizeof(EdgeNode));
				e->adjvex = j;					/* 邻接序号为j  */
				e->next = (*GL)->adjList[i].firstedge;	/* 将当前顶点上的指向的结点指针赋值给e */
				(*GL)->adjList[i].firstedge = e;		/* 将当前顶点的指针指向e  */
				(*GL)->adjList[j].in++;

			}
		}
	}

}

/* 拓扑排序，若GL无回路，则输出拓扑排序序列并返回1，若有回路返回0。 */
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode* e;
	int i, k, gettop;
	int top = 0;  /* 用于栈指针下标  */
	int count = 0;/* 用于统计输出顶点的个数  */
	int* stack;	/* 建栈将入度为0的顶点入栈  */
	stack = (int*)malloc(GL->numVertexes * sizeof(int));

	for (i = 0; i < GL->numVertexes; i++)
		if (0 == GL->adjList[i].in) /* 将入度为0的顶点入栈 */
			stack[++top] = i;
	while (top != 0)
	{
		gettop = stack[top--];
		printf("%d -> ", GL->adjList[gettop].data);
		count++;        /* 输出i号顶点，并计数 */
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (!(--GL->adjList[k].in))  /* 将i号顶点的邻接点的入度减1，如果减1后为0，则入栈 */
				stack[++top] = k;
		}
	}
	printf("\n");
	if (count < GL->numVertexes)
		return ERROR;
	else
		return OK;
}
//前言
//最开始用到了
//由int vexs[MAXVEX](顶点数组)
//int arc[MAXVEX][MAXVEX](顶点的邻接矩阵)
//int numVertexes(顶点数) numEdges(边数)
//组成的邻接矩阵结构

//这个算法一共用到了三类数据结构、
//1、由(in(入读(int))、
//   data(v1(结点对应名称))、
//   (EdgeNode* )firstedge(边表结构指针))组成的顶点表结点结构
//2、由(adjvex(邻接点域-当前邻接点下标))、
//   weight(权值)
//   (EdgeNode* next(链域--指向下一个邻接点))组成的边表结点结构
//3、由(AdjList(顶点表结点数组))、
//   numVertexes(图中当前顶点数)、
//   numEdges(图中当前边数)组成的图的总结构
//   
int main(void)
{
	MGraph G;   //实例化邻接矩阵
	GraphAdjList GL;   //实例化邻接表结构
	int result;
	CreateMGraph(&G);  //构建图
	CreateALGraph(G, &GL);  //利用邻接矩阵构建邻接表
	result = TopologicalSort(GL); /* 拓扑排序，若GL无回路，则输出拓扑排序序列并返回1，若有回路返回0。 */
	printf("result:%d", result);
	system("pause");
	return 0;
}