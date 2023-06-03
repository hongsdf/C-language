#include <stdio.h>
#include <string.h>
#include <malloc.h>



typedef struct Node {
	char szName[32];
	struct Node* next;
	struct Node* prev;

} Node;
Node* g_head;
Node* g_tail; //끝 노드 추가
int g_size = 0; // 전체 큐 길이
////////////////////////////////////////////////////////////////////////
// double LinkedLidst
void InitList(); // 노드 생성
void ReleaseList(); // 노드 전체 삭제
void PrintList(); // 노드 전체 출력
void InsertAtHead(); // 앞 노드 생성
void InsertAtTail(); // 뒤 노드 생성
int GetLength();
int GetSize(); // 노드 전체 사이즈
void deleteNode(); // 노드 삭제
Node* findNode(); // 노드 찾기
void deleteAllNode();//전체 노스 삭제
void InsertAtPoint(int,const char*); // 특정 위치에 삽입시키기
//////////////////////////////////////////////////////////////////


void InitList()
{
	// 초기화
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

// void 전체 노드 출력
void PrintList()
{
	Node* temp = g_head;
	while (temp != NULL)
	{
		printf("Curr[%p] %s Next[%p]\n", temp, temp->szName, temp->next);
		temp = temp->next;
	}
}

// 앞 노드 생성
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

// 뒤 노드 추가
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
// 전체 노드 삭제
void deleteAllNode()
{
	Node* temp = g_head->next;
	Node* deleteTemp = NULL;
	while (temp != NULL)
	{
		if (strcmp(temp->szName, "Dummy") == 0) return;
		else {
			printf("삭제 되었습니다. %s\n", temp->szName);
			deleteTemp = temp;
			temp = temp->next;
			free(deleteTemp);
		}
		
		
	}

}
// 특정 위치 삽입
void InsertAtPoint(int i,const char * pszData)
{
	Node* temp = g_head;

	// new Node
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	strcpy_s(pNewNode->szName, sizeof(pNewNode->szName), pszData);
	int j = 0;
	
	if (i > g_size) {
		puts("전체 범위를 초과하여 마지막 노드에 추가 됩니다.\n");
		InsertAtTail(pszData);
		return;
	}
	

	 
	while (temp != NULL)
	{
		if (i == j) {
			printf("%d 번째 위치에 %s 이 삽입되었습니다.\n", j, pNewNode->szName);
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



// 특정 노드 찾기
Node* findNode(const char* pszData)
{
	Node* temp = g_head;
	while (temp != NULL)
	{
		if (strcmp(temp->szName, pszData) == 0) {
			printf("%s를 찾았다.", pszData);
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

	InitList(); // 전체 
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
	printf("LinkedList 사이즈 %d\n", length); 

	Node* temp = findNode("number07");
	printf("%s\n", temp->szName); 
	// 전체 노드 삭제 테스트
	// deleteAllNode();
	 
	
    InsertAtPoint(9, "TEST2");
	// 맨챂 추가
	InsertAtPoint(0, "TEST3");
	  
	PrintList();
	return 0;
}