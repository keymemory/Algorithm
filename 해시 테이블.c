#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 10
#define T_SIZE 13

typedef struct {
	char key[MAX_CHAR];
} element;

void createHashTable(element hashT[]) {
	int i;
	for (i = 0; i < T_SIZE; i++)
		hashT[i].key[0] = (char)NULL;
}

int transform(char *key) {
	int number = 0;

	while (*key)
		number += *(key++);

	return number;
}

int hash(char *key) {
	return (transform(key) % T_SIZE);
}

void insertHashTable(element item, element hashT[]) {
	int j, hashValue;
	static int count = 0;
	hashValue = hash(item.key);
	j = hashValue;

	while (count < T_SIZE) {
		if (hashT[j].key[0] == (char)NULL) {
			hashT[j] = item;
			count++;
			return;
		}

		j = (j + 1) % T_SIZE;
	}
}

char *searchHashTable(element hashTable[], int key) {
	char *result = "ex";
	

	return result;
}

int main() {
	element hashTable[T_SIZE], item1;
	char* searchResult;
	int i, searchKey = 0;

	createHashTable(hashTable);

	strcpy(item1.key, "for"); insertHashTable(item1, hashTable);
	strcpy(item1.key, "while"); insertHashTable(item1, hashTable);
	strcpy(item1.key, "do"); insertHashTable(item1, hashTable);
	strcpy(item1.key, "else"); insertHashTable(item1, hashTable);
	strcpy(item1.key, "if"); insertHashTable(item1, hashTable);
	strcpy(item1.key, "function"); insertHashTable(item1, hashTable);

	strcpy(item1.key, "exit"); insertHashTable(item1, hashTable);
	strcpy(item1.key, "return"); insertHashTable(item1, hashTable);
	strcpy(item1.key, "break"); insertHashTable(item1, hashTable);
	strcpy(item1.key, "continue"); insertHashTable(item1, hashTable);
	strcpy(item1.key, "elseif"); insertHashTable(item1, hashTable);
	strcpy(item1.key, "switch"); insertHashTable(item1, hashTable);
	strcpy(item1.key, "case"); insertHashTable(item1, hashTable);
	strcpy(item1.key, "for"); insertHashTable(item1, hashTable);

	printf("Hash Table : \n"); printf("_________________\n");

	for (i = 0; i < T_SIZE; i++)
		printf("%d - %s \n", i, hashTable[i].key);
	printf("_________________\n");
	getchar();

	printf("Hash Tale Search : "); scanf("%d", &searchKey);
	searchResult = searchHashTable(hashTable, searchKey);
	printf("\n\n");
	getchar();

	return 0;
}