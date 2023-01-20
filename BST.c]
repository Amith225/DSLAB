#include<stdio.h>
#include<stdlib.h>


struct Node;
typedef struct Node* Tree;
struct Node {
        int val;
        Tree right, left;
};

Tree new(int a) {
        Tree tree = malloc(sizeof(Tree));
        tree->val = a;
        tree->right = NULL;
        tree->left = NULL;
        return tree;
}

Tree insert(Tree tree, int a) {
    if(tree == NULL) return new(a);
    Tree trav = tree, temp;
    while(1) {
        if(a >= trav->val) {
            if(trav->right == NULL) {
                trav->right = new(a); break;
            }
            trav = trav->right;
        }
        else {
            if(trav->left == NULL) {
                trav->left = new(a); break;
            }
            trav = trav->left;
        }
    }
    return tree;
}

void displayLNR(Tree tree) {
    if(tree == NULL) return;
    displayLNR(tree->left);
    printf("%d, ", tree->val);
    displayLNR(tree->right);
}

void main() {
        int ch, a;
        Tree tree = NULL;
        printf("CMDs: insert(1), display-lnr(2), exit(0)\n");
        while(1) {
                printf("CMD?> "); scanf("%d", &ch);
                switch(ch) {
                        case 0: return;
                        case 1: printf("Ele: "); scanf("%d", &a);
                                tree = insert(tree, a); break;
                        case 2: displayLNR(tree); printf("\n"); break;
                        default: printf("Bad CMD\n");
                }
        }
}
