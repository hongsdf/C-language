#include <stdio.h>
#include <string.h>
#include <malloc.h>

//[1]���ڿ� ������ �Լ�
//	Q1. �ñ� �� => free�� ���� �ʾƼ� fd���� ����ϴ� ���ΰ�?
//  R1. ���ڿ����� �ݵ�� NULL �̶�� ���� Ȯ���� �˰� �Ǿ���. ���ڿ� ���� + 1�� �����ؾߵȴ�.

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
// [2] strcat�����ϱ�



// [3] strcmp �޸� �� �����ϱ�





int main()
{
	// �Է� �ޱ�
	// char* test = "MyTEST";
	
	char* test = (char *)malloc(sizeof(char) * 13); // �ִ� 12�ڸ������� �Է� ����
	memset(test, 0, sizeof(char) * 13);
	scanf_s("%s", test,sizeof(char) * 13);
	// My_strrev()
	char* pTEST = (char*)malloc(sizeof(char) * 13);
	memset(pTEST, 0, sizeof(char) * 13);
	// ���� �� Ȯ��
	// 
	// ���� ������ ����
	char* temp = test;
	int i = 0; 
	// �� ���ڸ� �Է��ߴ��� �˾ƾ���
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