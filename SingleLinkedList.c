#include <stdio.h>
#include <string.h>
#include <malloc.h>



typedef struct Node {
	char szName[32];
	struct Node* next;
	struct Node* prev;

} Node;
Node* g_head;
Node* g_tail; //�� ��� �߰�
int g_size = 0; // ��ü ť ����
////////////////////////////////////////////////////////////////////////
// double LinkedLidst
void InitList(); // ��� ����
void ReleaseList(); // ��� ��ü ����
void PrintList(); // ��� ��ü ���
void InsertAtHead(); // �� ��� ����
void InsertAtTail(); // �� ��� ����
int GetLength();
int GetSize(); // ��� ��ü ������
void deleteNode(); // ��� ����
Node* findNode(); // ��� ã��
// void insertAtPoint() Ư�� ��ġ�� ���Խ�Ű��
//////////////////////////////////////////////////////////////////


void InitList()
{ 
	// �ʱ�ȭ
	g_head = (Node*)malloc(sizeof(Node));
	g_head->next = NULL;
	g_head->prev = NULL;
	strcpy_s(g_head->szName, sizeof(g_head->szName), "Dummy");

	g_tail = (Node*)malloc(sizeof(Node));
	g_tail->next = NULL;
	g_tail->prev = NULL;
	strcpy_s(g_tail->szName, sizeof(g_tail->szName), "Dummy");

	// g_Head <-> g_tail
	g_tail->prev = g_head;
	g_head->next = g_tail;

}

// void ��ü ��� ���
void PrintList()
{
	Node* temp = g_head;
	while (temp!= NULL)
	{
		printf("Curr[%p] %s Next[%p]\n", temp, temp->szName, temp->next);
		temp = temp->next;
	}
}

// �� ��� ����
void InsertAtHead(const char* pszdata)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	memset(temp, 0, sizeof(Node));
	strcpy_s(temp->szName, sizeof(temp->szName), pszdata);

	temp->prev = g_head;
	temp->next = g_head->next;

	g_head->next = temp;
	temp->next->prev = temp;

	g_size++;
}

// �� ��� �߰�
void InsertAtTail(const char* pszData)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	memset(temp, 0, sizeof(temp));
	strcpy_s(temp->szName, sizeof(temp->szName), pszData);


	temp->prev = g_tail->prev;
	temp->next = g_tail;

	
	temp->prev->next = temp;
	g_tail->prev = temp;

	g_size++;
}
int GetLength()
{
	return GetSize();
}

int GetSize() {
	return g_size;
}


// Ư�� ��� ã��
Node* findNode(const char* pszData)
{
	Node* temp = g_head;
	while (temp != NULL)
	{
		if (strcmp(temp->szName, pszData) == 0) {
			printf("%s�� ã�Ҵ�.", pszData);
			return temp;
		}
		temp = temp->next;
	}

	return NULL;
}

void deleteNode(const char* pszName)
{
	Node* temp = g_head;
	Node* deletetemp = NULL;
	while (temp != NULL)
	{
		if (strcmp(temp->szName, pszName) == 0)
		{
			deletetemp = temp;
			temp->prev->next = temp->next;
			free(deletetemp);
			return;
		}

		temp = temp->next;
	}
}
 

int main(void)
{
	
	InitList(); // ��ü 
	InsertAtHead("number04");
	InsertAtHead("number05");
	InsertAtHead("number06");
	InsertAtTail("number01");
	InsertAtTail("number02");
	InsertAtTail("number03");

	PrintList(); 
	int length = GetLength();
	printf("LinkedList ������ %d\n", length);
	 
	 Node *temp = findNode("number07");
	 printf("%s", temp->szName);
	 
	 deleteNode("number03");
	 PrintList();
	  
	 puts("-------------------------------------------------"); 
	 deleteNode("number06"); 
	 PrintList();
	

	return 0;
}