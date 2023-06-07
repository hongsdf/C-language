#include <stdio.h>

typedef struct Test
{
	int param1;
	int param2;
	int param3;
} Test;

//  함수 포인터의 배열선언
int (*g_list[5])(Test*);

int add(Test * param1)
{
	return 0;
}
int sub(Test* param2)
{
	return 0;
}
int multi(Test* param3)
{
	return 0;
}
int div(Test* pararm1)
{
	return 0;
}



void init_list()
{
	g_list[1] = add;
	g_list[2] = sub;
	g_list[3] = multi;
	g_list[4] = div;
}



int main(void)
{
	init_list();
	int instructions[1024] = { 0 };
	int pc = 0;

	Test Param = { 0 };

	while (instructions[pc])
	{
		switch (instructions[pc])
		{
		//case 1: //ADD
		//	break;
		//case 2: //SUB
		//	break;
		//case 3: // MULT
		//	break;
		//case 4: // DIV
		//	break;
	     // Lookup배열

			g_list[instructions[pc]](&Param);
		}
		pc++;
	}

	return 0;
}