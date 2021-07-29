#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef char element;
typedef struct LinkedNode {
	element data;
	struct LinkedNode *link;
} StackNode;

typedef struct LinkedStack {
	StackNode *top;
} Stack;

Stack *createLinkedNode() {
	Stack*S;
	S = (Stack*)malloc(sizeof(Stack));
	S->top = NULL;
	return S;
}

StackNode *createStackNode(element data) {
	StackNode *N;
	N = (StackNode*)malloc(sizeof(StackNode));
	N->data = data;
	N->link = NULL;
	return N;
}

void push(Stack *S, element symbol) {
	StackNode *newN;
	newN = createStackNode(symbol);
	newN->link = S->top;
	S->top = newN;
}

element pop(Stack*S) {
	StackNode *tempN;
	
	if (S->top == NULL) {
		return (element)NULL;
	}
	else {
		tempN = S->top;
		S->top = S->top->link;
		return tempN->data;
	}
}

int testPair(Stack*S, char*E) {
	char symbol, open_pair;
	int i, len = strlen(E);

	for (i = 0; i < len; i++) {
		symbol = E[i];

		switch (symbol) {
		case '(':
		case '[':
		case '{':
			push(S, symbol);
			break;
		case ')':
		case ']':
		case '}':
			if (S->top == -1)
				return 0;
			else {
				open_pair = pop(S);

				if ((open_pair == '(' && symbol != ')') || (open_pair == '[' && symbol != ']')
					|| (open_pair == '{' && symbol != '}'))
					return 0;

				else
					break;
			}
		}
	}

	if (S->top == -1)
		return 1;
	else
		return 0;
}

int main() {
	char *expression = "{ (A + B) - 3 }*5 + [{cos(x + y) + 7}-7]*4";
	Stack *S = (Stack*)malloc(sizeof(Stack));
	S->top = -1;

	printf("%s", expression);
	if (testPair(S, expression) == 1)
		printf("\n expression`s OK");
	else
		printf("\n expression`s not OK");
	printf("\n\n\n");

	return 0;
}