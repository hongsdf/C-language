#define _CRT_SECURE_NO_WARNINGS // unsafe ���� ��� ���� �޼��� ����
#include <stdio.h>


// C99 ǥ�� ���� �����ϱ� ������ �ζ��� __INLINE ������ ������ ��ũ�ο� ����.
// ��ũ�ζ�  �����ϴܰ迡�� ���ڿ� ġȯ�ϴ� �۾�
// �ζ��� �Լ��� ������ �ܰ迡�� �Լ��� ���� ��Ű�� �۾�

#define PRINT printf


//int add(int a, int b) {
//
//	return a + b;
//}
//
//int sub(int a, int b, int c)
//{
//	return a - b - c;
//}
//
//typedef struct TestFunc
//{
//	int a;
//	int b;
//	int (*pfFunc)(int, int);
//} TestFunc;

// �Լ� ������
//int main()
//{
//	int result = 0;
//	result = add(3, 4);
//	printf("%d \n", result);
//
//	//�Լ� ����
//	int (*pfAdd)(int, int) = add;
//	int answer = (*pfAdd)(3, 4);
//	printf("%d \n", answer);
//
//	int (*pfSub)(int, int, int) = sub;
//	int ans = (*pfSub)(5, 7, 3);
//	printf("%d \n", ans);
//
//	TestFunc testfunc = { 0 };
//	testfunc.a = 3;
//	testfunc.b = 3;
//	testfunc.pfFunc = add;
//	printf("%d %d %d", testfunc.a, testfunc.b, testfunc.pfFunc(3,4));
//
//	return  0;
//}