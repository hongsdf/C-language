#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

// �н��� ����
// scanf() �Լ��� ���� ����� ���ڿ��� �Է� �޴´�. ���� ������ �Է� �޴� ���
//scanf("%[^\n]s", str) // ������ ���ۿ� \n�� ���Ұ� �ȴ�.
// getchar(); // ���� ����

// tolower(int c) : �� �ҹ��� ��ȯ �޼���

int main(void) { 
	while (1) {
		int cnt = 0 , i = 0; // i�� ������ ���� ����
		char str[255] = ""; // �� �� ���ڿ� �ʱ�ȭ
		
		scanf("%[^\n]s", str); // \n�� �ƴҶ����� �Է��� �޴´�.�� ������ �Է¹޴� ���̴�.
		getchar(); // \n�� ���ۿ� ���������Ƿ� �������Ѵ�.


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
		count++; // ���� ���� �߰�
		char line[255]; // �Է� ���� ���ڿ��� ������ �迭
		// fgets �Լ�
		fgets(line, sizeof(line), stdin);
		
		//scanf("%[^\n]", line); // \n�� ���� ������ ��� ���ڸ� �Է� ����
		int cnt = 0;

		char* Pfline = line;
		if (*(Pfline) == '#') break; //���� ��ġ
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