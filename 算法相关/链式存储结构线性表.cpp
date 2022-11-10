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
//typedef struct Node * LinkList;   //����LinkList
//
//typedef int Status;
///*Status �Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��*/
//
//
///*��ʼ������˳�����Ա�L�Ѵ���,1<= i <= ListLength(L)*/
///*�����������e����L�е�i������Ԫ�ص�ֵ*/
//Status visit(ElemType c)
//{
//    printf("%d ",c);
//    return ok;
//}
//
///* ��ʼ����ʽ���Ա� */
//Status InitList(LinkList *L) 
//{ 
//    *L=(LinkList)malloc(sizeof(Node)); /* ����ͷ���,��ʹLָ���ͷ��� */
//    if(!(*L)) /* �洢����ʧ�� */
//            return error;
//    (*L)->next=NULL; /* ָ����Ϊ�� */
//
//    return ok;
//}
//
///* ��ʼ��������ʽ���Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
//Status ListEmpty(LinkList L)
//{ 
//    if(L->next)
//		return false;
//    else
//		return true;
//}
//
///* ��ʼ��������ʽ���Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
//int ListLength(LinkList L)
//{
//    int i=0;
//    LinkList p=L->next; /* pָ���һ����� */
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
//	LinkList p; //����һ���ڵ�
//	p = L->next;   //��Pָ������L�ĵ�һ���ڵ�
//	j = 1;      //jΪ������
//	while(p && j < i)   //p��Ϊ���һ��߼�����j��û�е���iʱ��ѭ������
//	{
//		p = p->next;    //��pָ����һ���ڵ�
//		++j;
//	}
//
//	if(!p || j > i)
//		return error;   //��i��Ԫ�ز�����
//	*e = p->data;       //ȡ����i��Ԫ�ص�����
//
//}
//
///* ��ʼ��������ʽ���Ա�L�Ѵ��� */
///* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
///* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
//int LocateElem(LinkList L,ElemType e)
//{
//    int i=0;
//    LinkList p=L->next;
//    while(p)
//    {
//        i++;
//        if(p->data==e) /* �ҵ�����������Ԫ�� */
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
///*��ʼ������˳�����Ա�L�Ѵ���,1<= i <= ListLength(L)*/
///*�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1*/
//Status LinkInsert(LinkList * L,int i, ElemType  e)
//{
//	int j;
//	LinkList p,s;
//	p = *L;
//	j = 1;
//	while (p && j < i)    //Ѱ�ҵ�i���ڵ�
//	{
//		p = p->next;
//		++j;
//	}
//
//	if(!p || j < i)
//		return error;    //��i��Ԫ�ز�����
//	s = (LinkList)malloc(sizeof(Node));  //�����½ڵ㣨c��׼������
//	s->data = e;
//	s->next = p->next;   //��p�ĺ�̽ڵ㸳ֵ��s�ĺ��
//	p->next = s;         //��s��ֵ��p�ĺ��
//	return ok;
//}
//
///*��ʼ������˳�����Ա�L�Ѵ���,1<= i <= ListLength(L)*/
///*���������ɾ��L�е�i������Ԫ�أ�����e���أ�L�ĳ��ȼ�1*/
//Status ListDelete(LinkList * L, int i, ElemType * e)
//{
//	int j;
//	LinkList p,q;
//	p = *L;
//	j = 1;
//	while (p->next && j < i)  //����Ѱ�ҵ�i��Ԫ��
//	{
//		p = p->next;
//		++j;
//	}
//
//	if(!(p->next) || j > i)
//		return error;         //��i��Ԫ�ز�����
//	q = p->next;
//	p->next = q->next;        //��q�ĺ�̸�ֵ��p�ĺ��
//	*e = q->data;             //��q�ڵ��е����ݸ�*e
//	free(q);                  //��ϵͳ���մ˽ڵ㣬�ͷ��ڴ�
//	return ok;
//}
//
///* ��ʼ��������ʽ���Ա�L�Ѵ��� */
///* ������������ζ�L��ÿ������Ԫ����� */
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
///*�������n��Ԫ�ص�ֵ����������ͷ�ڵ�ĵ������Ա�L(ͷ�巨)*/
//void CreateListHead(LinkList * L, int n)
//{
//	LinkList p;
//	int i;
//	srand(time(0));    //��ʼ�����������
//	*L = (LinkList)malloc(sizeof(Node));
//	(*L)->next = NULL;     //�Ƚ���һ����ͷ�ڵ�ĵ�����
//	for(int i = 0; i < n; i++)
//	{
//		p = (LinkList)malloc(sizeof(Node));  //�����½ڵ�
//		p->data = rand()%100+1;              //����100���ڵ�����
//		p->next = (*L)->next;
//		(*L)->next = p;                      //���뵽��ͷ
//	}
//}
//
///*�������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L(β�巨)*/
//void CreateListTail(LinkList * L,int n)
//{
//	LinkList p,r;
//	int i;
//	srand(time(0));    //��ʼ�����������
//	*L = (LinkList)malloc(sizeof(Node));  //Ϊ�������Ա�
//	r = *L;            //rΪָ��β���Ľ��
//	for(int i = 0; i < n; i++)
//	{
//		p = (Node*)malloc(sizeof(Node));   //�����½��
//		p->data = rand()%100+1;            //�������100���ڵ�����
//		r->next = p;                       //����β�ն˽���ָ��ָ���½��
//		r = p;                             //����ǰ���½�㶨��Ϊ��β�ն˽��
//	}
//	r->next = NULL;                        //��ʾ��ǰ�������
//}
///*��ʼ������˳�����Ա�L�Ѵ��ڣ������������L����Ϊ�ձ�*/
//Status ClearList(LinkList * L)
//{
//	LinkList p,q;
//	p = (*L)->next;          //Pָ���һ�����
//	while(p)
//	{
//		q = p->next;
//		free(p);
//		p = q;
//	}
//	(*L)->next = NULL;       //ͷ���ָ����Ϊ��
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
////    printf("��ʼ��L��ListLength(L)=%d\n",ListLength(L));
////    for(j=1;j<=5;j++)
////		i=LinkInsert(&L,1,j);
////    printf("��L�ı�ͷ���β���1��5��L.data=");
////    ListTraverse(L); 
////
////    printf("ListLength(L)=%d \n",ListLength(L));
////    i=ListEmpty(L);
////    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
////
////    i=ClearList(&L);
////    printf("���L��ListLength(L)=%d\n",ListLength(L));
////    i=ListEmpty(L);
////    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
////
////    for(j=1;j<=10;j++)
////		LinkInsert(&L,j,j);
////    printf("��L�ı�β���β���1��10��L.data=");
////    ListTraverse(L); 
////
////    printf("ListLength(L)=%d \n",ListLength(L));
////
////    LinkInsert(&L,1,0);
////    printf("��L�ı�ͷ����0��L.data=");
////    ListTraverse(L); 
////    printf("ListLength(L)=%d \n",ListLength(L));
////
////	GetItem(L,5,&e);
////    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
////    for(j=3;j<=4;j++)
////    {
////            k=LocateElem(L,j);
////            if(k)
////                    printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
////            else
////                    printf("û��ֵΪ%d��Ԫ��\n",j);
////    }
////    
////
////    k=ListLength(L); /* kΪ�� */
////    for(j=k+1;j>=k;j--)
////    {
////            i=ListDelete(&L,j,&e); /* ɾ����j������ */
////            if(i==error)
////                    printf("ɾ����%d������ʧ��\n",j);
////            else
////                    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
////    }
////    printf("�������L��Ԫ�أ�");
////    ListTraverse(L); 
////
////    j=5;
////    ListDelete(&L,j,&e); /* ɾ����5������ */
////    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
////
////    printf("�������L��Ԫ�أ�");
////    ListTraverse(L); 
////
////    i=ClearList(&L);
////    printf("\n���L��ListLength(L)=%d\n",ListLength(L));
////    CreateListHead(&L,20);
////    printf("���崴��L��Ԫ��(ͷ�巨)��");
////    ListTraverse(L); 
////    
////    i=ClearList(&L);
////    printf("\nɾ��L��ListLength(L)=%d\n",ListLength(L));
////    CreateListTail(&L,20);
////    printf("���崴��L��Ԫ��(β�巨)��");
////    ListTraverse(L); 
////
////	system("pause");
////	return 0;
////}