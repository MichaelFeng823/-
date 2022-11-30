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
//#define MAXEDGE 20             //������
//#define MAXVEX 20              //�������
//#define GRAPH_INFINITY 65535   //���Ȩֵ
//
//typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
//
////ͼ�ṹ
//typedef struct
//{
//	int vexs[MAXVEX];                //����±�����
//	int arc[MAXVEX][MAXVEX];         //��Ӧͼ���ڽӾ���
//	int numVertexes, numEdges;       //�����,�Լ�����
//}MGraph;
//
//typedef int Patharc[MAXVEX];    /* ���ڴ洢���·���±������ */
//typedef int ShortPathTable[MAXVEX];/* ���ڴ洢���������·����Ȩֵ�� */
//
///* ����ͼ */
//void CreateMGraph(MGraph* G)
//{
//	int i, j;
//
//	/* printf("����������Ͷ�����:"); */
//	G->numEdges = 16;
//	G->numVertexes = 9;
//
//	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
//	{
//		G->vexs[i] = i;
//	}
//
//	//����ͼ���ڽӾ���Ϊ�Գƾ���
//	for (i = 0; i < G->numVertexes; i++)/* ��ʼ��ͼ */
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
//	//��ʼ����Ӧ�ߵ�Ȩֵ
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
//	//����ͼ���ڽӾ���Ϊ�Գƾ���
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
///*  Dijkstra�㷨����������G��v0���㵽���ඥ��v�����·��P[v]����Ȩ����D[v] */
///*  P[v]��ֵΪǰ�������±�,D[v]��ʾv0��v�����·�����Ⱥ� */
//void ShortestPath_Dijkstra(MGraph G, int v0, Patharc* P, ShortPathTable* D)
//{
//	int v, w, k, min;
//	int final[MAXVEX];/* final[w]=1��ʾ��ö���v0��vw�����·�� */    
//					  //��Ϊ��V0��ĳ�����Ƿ��Ѿ�������·���ı�� ��V0-VW���н����final[w] = 1;
//	for (v = 0; v < G.numVertexes; v++)    /* ��ʼ������ */
//	{
//		final[v] = 0;			/* ȫ�������ʼ��Ϊδ֪���·��״̬ */
//		(*D)[v] = G.arc[v0][v];/* ����v0�������ߵĶ������Ȩֵ */
//		(*P)[v] = -1;				/* ��ʼ��·������PΪ-1  */
//	}
//
//	(*D)[v0] = 0;  /* v0��v0·��Ϊ0 */
//	final[v0] = 1;    /* v0��v0����Ҫ��·�� */    
//					  //��v0-v0���н��
//	                  //��ʱfinal����Ϊ{1,0,0,0,0,0,0,0} ��ʼ���������
//
//	/* ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·�� */
//	//���v��1��ʼ�����Ǵ�0��ʼ
//	for (v = 1; v < G.numVertexes; v++)
//	{
//		min = GRAPH_INFINITY;    /* ��ǰ��֪��v0������������ */
//		for (w = 0; w < G.numVertexes; w++) /* Ѱ����v0����Ķ��� */
//		{
//			if (!final[w] && (*D)[w] < min)
//			{
//				k = w;            //��¼��ǰ����±�
//				min = (*D)[w];    /* w������v0������� */
//			}
//		}
//		final[k] = 1;    /* ��Ŀǰ�ҵ�������Ķ�����Ϊ1 */
//		//�����ƺ�������ҳ��붥������� ����������õ���һ����������Сֵ
//		//�˶�ѭ���ǹؼ�
//		for (w = 0; w < G.numVertexes; w++) /* ������ǰ���·�������� */
//		{
//			/* �������v�����·������������·���ĳ��ȶ̵Ļ� */
//			//����(v0->v2)D[2] = 5,����v0->v1->v2 = D[2] = min + 3 = 4;
//			//v0->v1->v3=D[3] = min + 7 = 8,v0->v1->v4=D[4]=min+5=6;
//			//���,D���鵱ǰֵΪ{0,1,4,8,6,65535,65535,65535,65535}
//			//��P[2] = 1,P[3] = 1,P[4] = 1;
//			//��ʾ����˼��v0��v2��v3��v4������·�����ǵ�ǰȥ=
//			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
//			{ /*  ˵���ҵ��˸��̵�·�����޸�D[w]��P[w] */
//				(*D)[w] = min + G.arc[k][w];  /* �޸ĵ�ǰ·������ */
//				(*P)[w] = k;
//			}
//		}
//	}
//}
//
//int main(void)
//{
//	int i, j, v0;
//	MGraph G;          //ʵ����ͼ����
//	Patharc P;         //ʵ�������·���±�����
//	ShortPathTable D; /* ��ĳ�㵽�����������·�� */
//	v0 = 0;
//
//	CreateMGraph(&G); //����ͼ
//
//	ShortestPath_Dijkstra(G, v0, &P, &D);
//
//	printf("���·����������:\n");
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
//	printf("\nԴ�㵽����������·������Ϊ:\n");
//	for (i = 1; i < G.numVertexes; ++i)
//		printf("v%d - v%d : %d \n", G.vexs[0], G.vexs[i], D[i]);
//	system("pause");
//	return 0;
//}