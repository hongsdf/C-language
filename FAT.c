#include <stdio.h>


int main()
{
	FILE* fp = NULL;
	if (fopen_s(&fp, "test2.dat", "wb"))
	{
		return 1;
	}

	fwrite("\x00\x11\x22\x33", 4, 1, fp); // 64bit �� �ִ� 8byte�� �޸� 
	fwrite("\x44\x55\x66\x77", 4, 1, fp);
	fwrite("\x88\x99\xAA\xBB", 4, 1, fp);
	//fseek(fp, 1024 * 1024 * 1024, SEEK_SET); // disk Ȯ��
	fwrite("ABCD", 4, 1, fp);
	fclose(fp);


	return 0;
}



