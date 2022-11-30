//#include "stdio.h"    
//#include "stdlib.h"   
//#include "io.h"  
//#include "math.h"  
//#include "time.h"
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//#define MAXEDGE 20             //最大边数
//#define MAXVEX 20              //最大结点数
//#define GRAPH_INFINITY 65535   //最大权值
//
//typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
//
////图结构
//typedef struct
//{
//	int vexs[MAXVEX];                //结点下标数组
//	int arc[MAXVEX][MAXVEX];         //对应图的邻接矩阵
//	int numVertexes, numEdges;       //结点数,以及边数
//}MGraph;
//
//typedef int Patharc[MAXVEX];    /* 用于存储最短路径下标的数组 */
//typedef int ShortPathTable[MAXVEX];/* 用于存储到各点最短路径的权值和 */
//
///* 构件图 */
//void CreateMGraph(MGraph* G)
//{
//	int i, j;
//
//	/* printf("请输入边数和顶点数:"); */
//	G->numEdges = 16;
//	G->numVertexes = 9;
//
//	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
//	{
//		G->vexs[i] = i;
//	}
//
//	//无向图的邻接矩阵为对称矩阵
//	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
//	{
//		for (j = 0; j < G->numVertexes; j++)
//		{
//			if (i == j)
//				G->arc[i][j] = 0;
//			else
//				G->arc[i][j] = G->arc[j][i] = GRAPH_INFINITY;
//		}
//	}
//
//	//初始化对应边的权值
//	G->arc[0][1] = 1;
//	G->arc[0][2] = 5;
//	G->arc[1][2] = 3;
//	G->arc[1][3] = 7;
//	G->arc[1][4] = 5;
//
//	G->arc[2][4] = 1;
//	G->arc[2][5] = 7;
//	G->arc[3][4] = 2;
//	G->arc[3][6] = 3;
//	G->arc[4][5] = 3;
//
//	G->arc[4][6] = 6;
//	G->arc[4][7] = 9;
//	G->arc[5][7] = 5;
//	G->arc[6][7] = 2;
//	G->arc[6][8] = 7;
//
//	G->arc[7][8] = 4;
//
//	//无向图的邻接矩阵为对称矩阵
//	for (i = 0; i < G->numVertexes; i++)
//	{
//		for (j = i; j < G->numVertexes; j++)
//		{
//			G->arc[j][i] = G->arc[i][j];
//		}
//	}
//
//}
//
///*  Dijkstra算法，求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v] */
///*  P[v]的值为前驱顶点下标,D[v]表示v0到v的最短路径长度和 */
//void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D)
//{
//	int v, w, k, min;
//	int final[MAXVEX];/* final[w]=1表示求得顶点v0至vw的最短路径 */    
//					  //是为了V0到某顶点是否已经求得最短路径的标记 如V0-VW已有结果则final[w] = 1;
//	for (v = 0; v < G.numVertexes; v++)    /* 初始化数据 */
//	{
//		final[v] = 0;			/* 全部顶点初始化为未知最短路径状态 */
//		(*D)[v] = G.arc[v0][v];/* 将与v0点有连线的顶点加上权值 */
//		(*P)[v] = -1;				/* 初始化路径数组P为-1  */
//	}
//
//	(*D)[v0] = 0;  /* v0至v0路径为0 */
//	final[v0] = 1;    /* v0至v0不需要求路径 */    
//					  //即v0-v0已有结果
//	                  //此时final数组为{1,0,0,0,0,0,0,0} 初始化工作完成
//
//	/* 开始主循环，每次求得v0到某个v顶点的最短路径 */
//	//因此v从1开始而不是从0开始
//	for (v = 1; v < G.numVertexes; v++)
//	{
//		min = GRAPH_INFINITY;    /* 当前所知离v0顶点的最近距离 */
//		for (w = 0; w < G.numVertexes; w++) /* 寻找离v0最近的顶点 */
//		{
//			if (!final[w] && (*D)[w] < min)
//			{
//				k = w;            //记录当前结点下标
//				min = (*D)[w];    /* w顶点离v0顶点更近 */
//			}
//		}
//		final[k] = 1;    /* 将目前找到的最近的顶点置为1 */
//		//这个设计很巧妙，先找出离顶点最近的 这里好像利用到了一个遍历找最小值
//		//此段循环是关键
//		for (w = 0; w < G.numVertexes; w++) /* 修正当前最短路径及距离 */
//		{
//			/* 如果经过v顶点的路径比现在这条路径的长度短的话 */
//			//本来(v0->v2)D[2] = 5,现在v0->v1->v2 = D[2] = min + 3 = 4;
//			//v0->v1->v3=D[3] = min + 7 = 8,v0->v1->v4=D[4]=min+5=6;
//			//因此,D数组当前值为{0,1,4,8,6,65535,65535,65535,65535}
//			//而P[2] = 1,P[3] = 1,P[4] = 1;
//			//表示的意思是v0到v2、v3、v4点的最短路径他们的前去=
//			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
//			{ /*  说明找到了更短的路径，修改D[w]和P[w] */
//				(*D)[w] = min + G.arc[k][w];  /* 修改当前路径长度 */
//				(*P)[w] = k;
//			}
//		}
//	}
//}
//
//int main(void)
//{
//	int i, j, v0;
//	MGraph G;          //实例化图对象
//	Patharc P;         //实例化最短路径下标数组
//	ShortPathTable D; /* 求某点到其余各点的最短路径 */
//	v0 = 0;
//
//	CreateMGraph(&G); //构建图
//
//	ShortestPath_Dijkstra(G, v0, &P, &D);
//
//	printf("最短路径倒序如下:\n");
//	for (i = 1; i < G.numVertexes; ++i)
//	{
//		printf("v%d - v%d : ", v0, i);
//		j = i;
//		while (P[j] != -1)
//		{
//			printf("%d ", P[j]);
//			j = P[j];
//		}
//		printf("\n");
//	}
//	printf("\n源点到各顶点的最短路径长度为:\n");
//	for (i = 1; i < G.numVertexes; ++i)
//		printf("v%d - v%d : %d \n", G.vexs[0], G.vexs[i], D[i]);
//	system("pause");
//	return 0;
//}