#include<stdio.h>
#include<stdlib.h>


struct DoublyLinkedList;
typedef struct DoublyLinkedList* DLL;
struct DoublyLinkedList {
        int val;
        DLL next, prev;
};

DLL new(DLL prev, int a) {
        DLL dll = malloc(sizeof(DLL));
        dll->prev = prev;
        dll->next = NULL;
        dll->val = a;
        return dll;
}

DLL addFront(DLL dll, int a) {
        DLL newDll = new(NULL, a);
        newDll->next = dll;
        return newDll;
}

DLL addRear(DLL dll, int a) {
        if(dll == NULL) return new(NULL, a);
        DLL trav = dll;
        while(trav->next != NULL) trav = trav->next;
        trav->next = new(trav, a);
        return dll;
}

DLL delFront(DLL dll) {
        if(dll == NULL) {
                printf("Underflow\n");
                return NULL;
        }
        DLL newDll = dll->next;
        free(dll);
        return newDll;
}

DLL delRear(DLL dll) {
        if(dll == NULL) {
                printf("Underflow\n");
                return NULL;
        }
        if(dll->next == NULL) {
                free(dll);
                return NULL;
        }
        DLL trav = dll;
        while(trav->next->next != NULL) trav = trav->next;
        DLL temp = trav->next;
        free(temp);
        trav->next = NULL;
        return dll;
}

void display(DLL dll) {
        DLL trav = dll;
        printf("{");
        while(trav != NULL) {
                printf("%d, ", trav->val);
                trav = trav->next;
        }
        printf("}\n");
}

int search(DLL dll, int a) {
    DLL trav = dll;
    int i = 0;
    while(trav != NULL) {
        if(trav->val == a) return i;
        i++;
        trav = trav->next;
    }
    return -1;
}

void main() {
        int ch, a;
        DLL dll = NULL;
        printf("CMDs: add-front(1), add-rear(2), del-front(3), del-rear(4), display(5), search(6), exit(0)\n");
        while(1) {
                printf("CMD?> "); scanf("%d", &ch);
                switch(ch) {
                        case 0: return;
                        case 1: printf("Ele: "); scanf("%d", &a);
                                dll = addFront(dll, a); break;
                        case 2: printf("Ele: "); scanf("%d", &a);
                                dll = addRear(dll, a); break;
                        case 3: dll = delFront(dll); break;
                        case 4: dll = delRear(dll); break;
                        case 5: display(dll); break;
                        case 6: printf("Ele: "); scanf("%d", &a);
                                printf("i: %d\n", search(dll, a)); break;
                        default: printf("Bad CMD\n");
                }
        }
}

// output: 
// CMDs: add-front(1), add-rear(2), del-front(3), del-rear(4), display(5), search(6), exit(0)
// CMD?> 1
// Ele: 1
// CMD?> 1
// Ele: 2
// CMD?> 2
// Ele: 3
// CMD?> 2
// Ele: 4
// CMD?> 5
// {2, 1, 3, 4, }
// CMD?> 6
// Ele: 3
// i: 2
// CMD?> 3
// CMD?> 3
// CMD?> 5
// {3, 4, }
// CMD?> 2
// Ele: 1
// CMD?> 5
// {3, 4, 1, }
// CMD?> 4
// CMD?> 4
// CMD?> 5
// {3, }
// CMD?> 0
