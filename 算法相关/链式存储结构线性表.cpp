//#include<stdio.h>
//#include<iostream>
//#include<time.h>
//using namespace std;
//#define ok 1
//#define error 0
//#define true 1
//#define false 0
//
//typedef int ElemType;
//
//typedef struct Node
//{
//	ElemType data;
//	struct Node * next;
//};
//
//typedef struct Node * LinkList;   //定义LinkList
//
//typedef int Status;
///*Status 是函数的类型，其值是函数结果状态代码，如OK等*/
//
//
///*初始条件：顺序线性表L已存在,1<= i <= ListLength(L)*/
///*操作结果：用e返回L中第i个数据元素的值*/
//Status visit(ElemType c)
//{
//    printf("%d ",c);
//    return ok;
//}
//
///* 初始化链式线性表 */
//Status InitList(LinkList *L) 
//{ 
//    *L=(LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
//    if(!(*L)) /* 存储分配失败 */
//            return error;
//    (*L)->next=NULL; /* 指针域为空 */
//
//    return ok;
//}
//
///* 初始条件：链式线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
//Status ListEmpty(LinkList L)
//{ 
//    if(L->next)
//		return false;
//    else
//		return true;
//}
//
///* 初始条件：链式线性表L已存在。操作结果：返回L中数据元素个数 */
//int ListLength(LinkList L)
//{
//    int i=0;
//    LinkList p=L->next; /* p指向第一个结点 */
//    while(p)                        
//    {
//        i++;
//        p=p->next;
//    }
//    return i;
//}
//
//
//Status GetItem(LinkList L,int i,ElemType * e)
//{
//	int j;
//	LinkList p; //声明一个节点
//	p = L->next;   //让P指向链表L的第一个节点
//	j = 1;      //j为计数器
//	while(p && j < i)   //p不为空且或者计数器j还没有等于i时，循环继续
//	{
//		p = p->next;    //让p指向下一个节点
//		++j;
//	}
//
//	if(!p || j > i)
//		return error;   //第i个元素不存在
//	*e = p->data;       //取出第i个元素的数据
//
//}
//
///* 初始条件：链式线性表L已存在 */
///* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
///* 若这样的数据元素不存在，则返回值为0 */
//int LocateElem(LinkList L,ElemType e)
//{
//    int i=0;
//    LinkList p=L->next;
//    while(p)
//    {
//        i++;
//        if(p->data==e) /* 找到这样的数据元素 */
//                return i;
//        p=p->next;
//    }
//
//    return 0;
//}
//
//
//
//
//
///*初始条件：顺序线性表L已存在,1<= i <= ListLength(L)*/
///*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
//Status LinkInsert(LinkList * L,int i, ElemType  e)
//{
//	int j;
//	LinkList p,s;
//	p = *L;
//	j = 1;
//	while (p && j < i)    //寻找第i个节点
//	{
//		p = p->next;
//		++j;
//	}
//
//	if(!p || j < i)
//		return error;    //第i个元素不存在
//	s = (LinkList)malloc(sizeof(Node));  //生成新节点（c标准函数）
//	s->data = e;
//	s->next = p->next;   //将p的后继节点赋值给s的后继
//	p->next = s;         //将s赋值给p的后继
//	return ok;
//}
//
///*初始条件：顺序线性表L已存在,1<= i <= ListLength(L)*/
///*操作结果：删除L中第i个数据元素，并用e返回，L的长度减1*/
//Status ListDelete(LinkList * L, int i, ElemType * e)
//{
//	int j;
//	LinkList p,q;
//	p = *L;
//	j = 1;
//	while (p->next && j < i)  //遍历寻找第i个元素
//	{
//		p = p->next;
//		++j;
//	}
//
//	if(!(p->next) || j > i)
//		return error;         //第i个元素不存在
//	q = p->next;
//	p->next = q->next;        //将q的后继赋值给p的后继
//	*e = q->data;             //将q节点中的数据给*e
//	free(q);                  //让系统回收此节点，释放内存
//	return ok;
//}
//
///* 初始条件：链式线性表L已存在 */
///* 操作结果：依次对L的每个数据元素输出 */
//Status ListTraverse(LinkList L)
//{
//    LinkList p=L->next;
//    while(p)
//    {
//        visit(p->data);
//        p=p->next;
//    }
//    printf("\n");
//    return ok;
//}
//
///*随机产生n个元素的值，建立带表头节点的单链线性表L(头插法)*/
//void CreateListHead(LinkList * L, int n)
//{
//	LinkList p;
//	int i;
//	srand(time(0));    //初始化随机数种子
//	*L = (LinkList)malloc(sizeof(Node));
//	(*L)->next = NULL;     //先建立一个带头节点的单链表
//	for(int i = 0; i < n; i++)
//	{
//		p = (LinkList)malloc(sizeof(Node));  //生成新节点
//		p->data = rand()%100+1;              //生成100以内的数字
//		p->next = (*L)->next;
//		(*L)->next = p;                      //插入到表头
//	}
//}
//
///*随机产生n个元素的值，建立带表头结点的单链线性表L(尾插法)*/
//void CreateListTail(LinkList * L,int n)
//{
//	LinkList p,r;
//	int i;
//	srand(time(0));    //初始化随机数种子
//	*L = (LinkList)malloc(sizeof(Node));  //为整个线性表
//	r = *L;            //r为指向尾部的结点
//	for(int i = 0; i < n; i++)
//	{
//		p = (Node*)malloc(sizeof(Node));   //生成新结点
//		p->data = rand()%100+1;            //随机生成100以内的数字
//		r->next = p;                       //将表尾终端结点的指针指向新结点
//		r = p;                             //将当前的新结点定义为表尾终端结点
//	}
//	r->next = NULL;                        //表示当前链表结束
//}
///*初始条件：顺序线性表L已存在，操作结果：将L重置为空表*/
//Status ClearList(LinkList * L)
//{
//	LinkList p,q;
//	p = (*L)->next;          //P指向第一个结点
//	while(p)
//	{
//		q = p->next;
//		free(p);
//		p = q;
//	}
//	(*L)->next = NULL;       //头结点指针域为空
//	return ok;
//}
//
////int main()
////{
////	LinkList L;
////    ElemType e;
////    Status i;
////    int j,k;
////    i=InitList(&L);
////    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
////    for(j=1;j<=5;j++)
////		i=LinkInsert(&L,1,j);
////    printf("在L的表头依次插入1～5后：L.data=");
////    ListTraverse(L); 
////
////    printf("ListLength(L)=%d \n",ListLength(L));
////    i=ListEmpty(L);
////    printf("L是否空：i=%d(1:是 0:否)\n",i);
////
////    i=ClearList(&L);
////    printf("清空L后：ListLength(L)=%d\n",ListLength(L));
////    i=ListEmpty(L);
////    printf("L是否空：i=%d(1:是 0:否)\n",i);
////
////    for(j=1;j<=10;j++)
////		LinkInsert(&L,j,j);
////    printf("在L的表尾依次插入1～10后：L.data=");
////    ListTraverse(L); 
////
////    printf("ListLength(L)=%d \n",ListLength(L));
////
////    LinkInsert(&L,1,0);
////    printf("在L的表头插入0后：L.data=");
////    ListTraverse(L); 
////    printf("ListLength(L)=%d \n",ListLength(L));
////
////	GetItem(L,5,&e);
////    printf("第5个元素的值为：%d\n",e);
////    for(j=3;j<=4;j++)
////    {
////            k=LocateElem(L,j);
////            if(k)
////                    printf("第%d个元素的值为%d\n",k,j);
////            else
////                    printf("没有值为%d的元素\n",j);
////    }
////    
////
////    k=ListLength(L); /* k为表长 */
////    for(j=k+1;j>=k;j--)
////    {
////            i=ListDelete(&L,j,&e); /* 删除第j个数据 */
////            if(i==error)
////                    printf("删除第%d个数据失败\n",j);
////            else
////                    printf("删除第%d个的元素值为：%d\n",j,e);
////    }
////    printf("依次输出L的元素：");
////    ListTraverse(L); 
////
////    j=5;
////    ListDelete(&L,j,&e); /* 删除第5个数据 */
////    printf("删除第%d个的元素值为：%d\n",j,e);
////
////    printf("依次输出L的元素：");
////    ListTraverse(L); 
////
////    i=ClearList(&L);
////    printf("\n清空L后：ListLength(L)=%d\n",ListLength(L));
////    CreateListHead(&L,20);
////    printf("整体创建L的元素(头插法)：");
////    ListTraverse(L); 
////    
////    i=ClearList(&L);
////    printf("\n删除L后：ListLength(L)=%d\n",ListLength(L));
////    CreateListTail(&L,20);
////    printf("整体创建L的元素(尾插法)：");
////    ListTraverse(L); 
////
////	system("pause");
////	return 0;
////}