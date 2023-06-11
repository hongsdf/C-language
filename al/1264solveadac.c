#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

// 학습한 내용
// scanf() 함수를 통해 사용자 문자열을 입력 받는다. 조건 한줄을 입력 받는 방법
//scanf("%[^\n]s", str) // 마지막 버퍼에 \n이 남았게 된다.
// getchar(); // 버퍼 비우기

// tolower(int c) : 대 소문자 변환 메서드

int main(void) { 
	while (1) {
		int cnt = 0 , i = 0; // i는 한행의 글자 갯수
		char str[255] = ""; // 한 행 문자열 초기화
		
		scanf("%[^\n]s", str); // \n이 아닐때가지 입력을 받는다.즉 한줄을 입력받는 것이다.
		getchar(); // \n이 버퍼에 남아있으므로 비워줘야한다.


		if (str[0] == '#' && str[1] == '\0')
			break;

		while (str[i] != '\0') {
			char c = tolower(str[i]);
			if (c == 'a' || c == 'e' ||
				c == 'i' || c == 'o' ||
				c == 'u')
				cnt++;
			i++;
		}

		printf("%d\n", cnt);
	}
	return 0;
}












/*
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	int arr[255] = { 0 };
	int count = 0;
	int i = 0;
	while (1)
	{
		count++; // 질문 갯수 추가
		char line[255]; // 입력 받을 문자열을 저장할 배열
		// fgets 함수
		fgets(line, sizeof(line), stdin);
		
		//scanf("%[^\n]", line); // \n이 나올 때까지 모든 문자를 입력 받음
		int cnt = 0;

		char* Pfline = line;
		if (*(Pfline) == '#') break; //종료 위치
		while (*(Pfline) != '\0') {
			if (*(Pfline) == 'a' || *(Pfline) == 'e' || *(Pfline) == 'i' || *(Pfline) == 'o' || *(Pfline) == 'u'||
				* (Pfline) == 'A' || *(Pfline) == 'E' || *(Pfline) == 'I' || *(Pfline) == 'O' || *(Pfline) == 'U') {
				cnt++;
			}
			Pfline++;

		}
		*(arr + i) = cnt;
		i++;


	}
	int j = 0;
	while (j < count-1)
	{
		printf("%d\n", arr[j]);
		j++;
	}
	

	return 0;
}
*/