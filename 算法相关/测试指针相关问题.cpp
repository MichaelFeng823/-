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
//		printf("执行析构方法！\n");
//	}
//public:
//	int* numpointer;
//	int num;
//};
//
////学到了，学到了，终于理解了！
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
//	//int * preHead = new int(-1);      // preHead(指针变量所指向对象在内存中存储的地址) 5563128
//									  // &preHead(指针变量在内存中所存储的地址)  5241340
//									  // *preHead(指针变量所指向对象所在的地址所存储的值) -1
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