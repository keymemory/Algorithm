#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct LinkedQueue {
	struct LinkedNode *front, *rear;
} linkedQueue;

typedef struct LinkedNode {
	element queue;
	struct LinkedNode *link;
} linkedNode;

linkedQueue *createLinkedQueue() {
	linkedQueue *Q;
	Q = (linkedQueue*)malloc(sizeof(linkedQueue));
	Q->front = NULL, Q->rear = NULL;
	return Q;
}

linkedNode *createLinkedNode(element data) {
	linkedNode *N;
	N = (linkedNode*)malloc(sizeof(linkedNode));
	N->queue = data, N->link = NULL;
	return N;
}

void enQueue(linkedQueue *Q, element item) {
	linkedNode *N1;
	N1 = createLinkedNode(item);
	if (Q->front == NULL) {
		Q->front == N1, Q->rear = N1;
	}
	else
		Q->rear->link = N1, Q->rear = N1;
}

element deQueue(linkedQueue *Q) {
	linkedNode *temp;
	element data;

	if (Q->front == NULL) {
		return (element)NULL;
	}
	else {
		temp = Q->front, data = temp->queue;
		Q->front = Q->front->link;

		if (Q->front == NULL)
			Q->rear = NULL;

		free(temp);
		return data;
	}
}

void printQueue(linkedQueue *Q) {
	linkedNode *temp;
	temp = Q->front;

	while (temp) {
		printf("%3c", temp->queue);
		temp = temp->link;
	}

	printf("\n\n\n");
}

int main() {
	linkedQueue *Q1 = createLinkedQueue();

	printf("insert A: "); enQueue(Q1, 'A'); printQueue(Q1);
	printf("insert B: "); enQueue(Q1, 'B'); printQueue(Q1);
	printf("insert C: "); enQueue(Q1, 'C'); printQueue(Q1);

	printf("Delete Q: "); deQueue(Q1); printQueue(Q1);
	printf("Delete Q: "); deQueue(Q1); printQueue(Q1);
	printf("Delete Q: "); deQueue(Q1); printQueue(Q1);

	return 0;
}