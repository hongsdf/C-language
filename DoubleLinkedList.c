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
void deleteAllNode();//��ü �뽺 ����
void InsertAtPoint(int,const char*); // Ư�� ��ġ�� ���Խ�Ű��
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
	while (temp != NULL)
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
// ��ü ��� ����
void deleteAllNode()
{
	Node* temp = g_head->next;
	Node* deleteTemp = NULL;
	while (temp != NULL)
	{
		if (strcmp(temp->szName, "Dummy") == 0) return;
		else {
			printf("���� �Ǿ����ϴ�. %s\n", temp->szName);
			deleteTemp = temp;
			temp = temp->next;
			free(deleteTemp);
		}
		
		
	}

}
// Ư�� ��ġ ����
void InsertAtPoint(int i,const char * pszData)
{
	Node* temp = g_head;

	// new Node
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	strcpy_s(pNewNode->szName, sizeof(pNewNode->szName), pszData);
	int j = 0;
	
	if (i > g_size) {
		puts("��ü ������ �ʰ��Ͽ� ������ ��忡 �߰� �˴ϴ�.\n");
		InsertAtTail(pszData);
		return;
	}
	

	 
	while (temp != NULL)
	{
		if (i == j) {
			printf("%d ��° ��ġ�� %s �� ���ԵǾ����ϴ�.\n", j, pNewNode->szName);
			pNewNode->prev = temp;
			pNewNode->next = temp->next;

			temp->next = pNewNode;
			pNewNode->next->prev = temp;

			return;
		}
		
			
		
		temp = temp->next;
		++j;
	}
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
			g_size--;
			return;
		}

		temp = temp->next;
	}
}


int main(void)
{

	InitList(); // ��ü 
	InsertAtTail("number00");
	InsertAtHead("number04");
	InsertAtHead("number05");
	InsertAtHead("number06");
	InsertAtTail("number01");
	InsertAtTail("number02");
	InsertAtTail("number03");
	InsertAtTail("TEST");

	PrintList();
	int length = GetLength();
	printf("LinkedList ������ %d\n", length); 

	Node* temp = findNode("number07");
	printf("%s\n", temp->szName); 
	// ��ü ��� ���� �׽�Ʈ
	// deleteAllNode();
	 
	
    InsertAtPoint(9, "TEST2");
	// �ǪR �߰�
	InsertAtPoint(0, "TEST3");
	  
	PrintList();
	return 0;
}