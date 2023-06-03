#include <stdio.h>
#include <string.h>
#include <malloc.h>

//[1]문자열 뒤집기 함수
//	Q1. 궁금 증 => free를 하지 않아서 fd값을 출력하는 것인가?
//  R1. 문자열끝은 반드시 NULL 이라는 것을 확실히 알게 되었다. 문자열 길이 + 1로 선언해야된다.

//  
char*  My_strrev(char* array, int size) {
	
	int len = size;
	char *temp= (char *)malloc(sizeof(char) * 13);
	memset(temp, 0, sizeof(char) * 13);


	// MyTest
	for(int i= 0; i <size; ++i)
	{
		*(temp + i)= *(array + len - 1);
		len--;

	}
	
	
	return temp ;
}
// [2] strcat구현하기



// [3] strcmp 메모리 비교 구현하기





int main()
{
	// 입력 받기
	// char* test = "MyTEST";
	
	char* test = (char *)malloc(sizeof(char) * 13); // 최대 12자리까지만 입력 가능
	memset(test, 0, sizeof(char) * 13);
	scanf_s("%s", test,sizeof(char) * 13);
	// My_strrev()
	char* pTEST = (char*)malloc(sizeof(char) * 13);
	memset(pTEST, 0, sizeof(char) * 13);
	// 글자 수 확인
	// 
	// 이중 포인터 생성
	char* temp = test;
	int i = 0; 
	// 몇 글자를 입력했는지 알아야함
	while (*test != NULL) {
		i++;
		test++;
	}



	pTEST =  My_strrev(temp,i);
	while (*pTEST != '\0')
	{
		printf("%c", *(pTEST++));
	}

	
	 

	return 0;
}