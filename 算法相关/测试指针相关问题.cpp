//#include "stdio.h"    
//#include "stdlib.h"   
//class Demo
//{
//public:
//	Demo()
//	{
//		num = 10;
//		numpointer = new int(20);
//	}
//	~Demo()
//	{
//		if (numpointer != NULL)
//		{
//			delete numpointer;
//			numpointer = NULL;
//		}
//		printf("ִ������������\n");
//	}
//public:
//	int* numpointer;
//	int num;
//};
//
////ѧ���ˣ�ѧ���ˣ���������ˣ�
//int main()
//{
//
//	Demo* demo = new Demo;
//
//	printf("%d\n", demo->num);
//	printf("%d\n", *(demo->numpointer));
//	int* otherpoint = demo->numpointer;
//	delete demo;
//	printf("%d\n", *otherpoint);
//	delete otherpoint;
//	//int * preHead = new int(-1);      // preHead(ָ�������ָ��������ڴ��д洢�ĵ�ַ) 5563128
//									  // &preHead(ָ��������ڴ������洢�ĵ�ַ)  5241340
//									  // *preHead(ָ�������ָ��������ڵĵ�ַ���洢��ֵ) -1
//
//	//int * prev = preHead;            
//	//printf("%d\n", preHead);
//	//printf("%d\n", &preHead);
//	//printf("%d\n", &prev);
//
//	//int* prev_next = new int(1);
//
//	//prev = prev_next;
//
//	//printf("%d\n", preHead);
//	//printf("%d\n", *prev);
//
//	//if(&preHead == *(*preHead))
//
//	system("pause");
//}