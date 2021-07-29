#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef char element;
typedef struct ArrayQueue {
	int front, rear;
	element queue[MAX_QUEUE_SIZE];
} arrayQueue;

arrayQueue *createArrayQueue() {
	arrayQueue *Q;
	Q = (arrayQueue*)malloc(sizeof(arrayQueue));
	Q->front = -1, Q->rear = -1;
	return Q;
}

void enQueue(arrayQueue *Q, element item) {
	if (Q->rear == MAX_QUEUE_SIZE - 1) {
		return;
	}
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

element deQueue(arrayQueue *Q) {
	if (Q->front == Q->rear) {
		return (element)NULL;
	}
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

void printQueue(arrayQueue *Q) {
	int i; 

	if (Q->front == Q->rear) {
		return;
	}
	else {
		for (i = Q->front + 1; i < Q->rear + 1; i++)
			printf("%3c", Q->queue[i]);
	}

	printf("\n\n\n");
}

int main() {
	arrayQueue *Q1 = createArrayQueue();

	printf("insert A: "); enQueue(Q1, 'A'); printQueue(Q1);
	printf("insert B: "); enQueue(Q1, 'B'); printQueue(Q1);
	printf("insert C: "); enQueue(Q1, 'C'); printQueue(Q1);

	printf("Delete Q: "); deQueue(Q1); printQueue(Q1);
	printf("Delete Q: "); deQueue(Q1); printQueue(Q1);
	printf("Delete Q: "); deQueue(Q1); printQueue(Q1);

	return 0;
}