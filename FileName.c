#define _CRT_SECURE_NO_WARNINGS // unsafe 보안 경고 에러 메세지 무시
#include <stdio.h>


// C99 표준 부터 지원하기 시작한 인라인 __INLINE 장점은 기존의 매크로와 같다.
// 매크로란  컴파일단계에서 문자열 치환하는 작업
// 인라인 함수란 컴파일 단계에서 함수를 삽입 시키는 작업

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

// 함수 포인터
//int main()
//{
//	int result = 0;
//	result = add(3, 4);
//	printf("%d \n", result);
//
//	//함수 원형
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