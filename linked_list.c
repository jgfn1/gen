// Also works as a Stack 
#include "stdio.h"
#include "stdlib.h"

typedef struct linked_list
{
	struct linked_list* next;
	int val;
} lists;

lists* list_pos(lists* head, int pos);
lists* list_find(lists* head, int value);

lists* list_insert(lists* cur, int v);
int list_delete(lists* cur);

void enqueue(lists* front, lists* rear, int v);
int dequeue(lists* front, lists* rear);

int main(void)
{
	/*int n;
	scanf("%d", n);*/
	lists* head = (lists*) malloc(sizeof(lists));
	head->next = NULL;

	/*//Teste list_insert
	lists* test = list_insert(head, 10);
	printf("Valor inserido(10): %d\n", test->next->val);
	//Teste list_delete
	list_insert(head, 15);
	printf("Valor removido: %d\n", list_delete(head));
	printf("Valor removido: %d\n", list_delete(head));
	printf("Valor removido: %d\n", list_delete(head));
	//Teste list_pos
	list_insert(head, 15);
	list_insert(head, 114);
	list_insert(head, 12);
	list_insert(head, 20);
	test = list_pos(head, 1);
	printf("Val da posição %d: %d\n", 1, test->val);
	test = list_pos(head, 2);
	printf("Val da posição %d: %d\n", 2, test->val);
	test = list_pos(head, 3);
	printf("Val da posição %d: %d\n", 3, test->val);
	test = list_pos(head, 4);
	printf("Val da posição %d: %d\n", 4, test->val);*/

	return 0;
}

lists* list_pos(lists* head, int pos)
{
	int i = 0;
	lists* cur = head;
	while(i < pos && cur != NULL)
	{
		cur = cur->next;
		++i;
	}
	return cur;
}

lists* list_find(lists* head, int value)
{
	lists* cur = head;
	while((cur->next != NULL) && (cur->next->val != v))
		cur = cur->next;
	return cur;
}

lists* list_insert(lists* cur, int v)	// Push
{
	lists* N  = (lists*) malloc(sizeof(lists));
	N->val = v;
	N->next = cur->next;
	cur->next = N;
	return cur;
}

int list_delete(lists* cur)	//Pop
{
	if(cur->next != NULL)
	{
		lists* p = cur->next;
		int v = p->val;
		cur->next = p->next;
		free(p);
		return v;
	}
}

void enqueue(lists* front, lists* rear, int v)
{
	lists* new_rear = list_insert(rear, v);
	rear = new_rear->next;
}

int dequeue(lists* front, lists* rear)
{
	int v = list_delete(front);
	lists* new_rear;
	lists* new_front = front;
	if(new_front == NULL)
	{
		new_rear = new_front;
		rear = new_rear;
		front = new_front;
	}
	return v;
}