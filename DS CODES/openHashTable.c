#include <stdio.h>
#include <stdlib.h>

#define MAX_HASH_SIZE 1000

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[MAX_HASH_SIZE];
int comparisons = 0;

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Insert into hash table
void insert(int key, int m) {
    int index = hash(key, m);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search key in hash table
int search(int key, int m) {
    int index = hash(key, m);
    Node* current = hashTable[index];
    while (current != NULL) {
        comparisons++;
        if (current->key == key)
            return 1;
        current = current->next;
    }
    return 0;
}

// Reset hash table
void resetHashTable(int m) {
    for (int i = 0; i < m; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    int mVals[] = {10, 20, 50};
    int nVals[] = {50, 100, 200};

    printf("Hash Table Size (m) | Keys Inserted (n) | Successful Search Comparisons | Unsuccessful Search Comparisons\n");
    printf("--------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        int m = mVals[i];
        for (int j = 0; j < 3; j++) {
            int n = nVals[j];
            resetHashTable(m);

            // Insert random keys
            for (int k = 0; k < n; k++) {
                insert(rand() % 1000, m);
            }

            // Search for a key that was inserted (likely successful)
            comparisons = 0;
            search(rand() % 1000, m);
            int successCmp = comparisons;

            // Search for a key not inserted (unsuccessful)
            comparisons = 0;
            search(2001, m);  // 2001 is outside insert range
            int failureCmp = comparisons;

            printf("%17d | %16d | %30d | %32d\n", m, n, successCmp, failureCmp);
        }
    }

    return 0;
}
