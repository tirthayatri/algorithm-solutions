#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int length;
} SeqList;

int INSERT_ORDER(SeqList *va, int x) {
    if (va->length >= MAXSIZE) {
        return 0;
    }
    
    int i;
    for (i = va->length - 1; i >= 0 && va->data[i] > x; i--) {
        va->data[i + 1] = va->data[i];
    }
    
    va->data[i + 1] = x;
    va->length++;
    
    return 1;
}

void initList(SeqList *va) {
    va->length = 0;
}

void insertEnd(SeqList *va, int value) {
    if (va->length < MAXSIZE) {
        va->data[va->length] = value;
        va->length++;
    }
}

void printList(SeqList *va) {
    for (int i = 0; i < va->length; i++) {
        printf("%d", va->data[i]);
        if (i < va->length - 1) {
            printf("->");
        }
    }
    printf("\n");
}

int main() {
    SeqList va;
    initList(&va);
    
    insertEnd(&va, 1);
    insertEnd(&va, 2);
    insertEnd(&va, 4);
    insertEnd(&va, 5);
    insertEnd(&va, 7);
    
    printf(" ‰»Î£∫");
    printList(&va);
    
    int x = 3;
    printf(" ‰»Î£∫%d\n", x);
    
    INSERT_ORDER(&va, x);
    
    printf(" ‰≥ˆ£∫");
    printList(&va);
    
    return 0;
}