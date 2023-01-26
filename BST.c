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

void displayNLR(Tree tree) {
    if(tree == NULL) return;
    printf("%d, ", tree->val);
    displayNLR(tree->left);
    displayNLR(tree->right);
}

void displayLRN(Tree tree) {
    if(tree == NULL) return;
    displayLRN(tree->left);
    displayLRN(tree->right);
    printf("%d, ", tree->val);
}

void main() {
        int ch, a;
        Tree tree = NULL;
        printf("CMDs: insert(1), display-inorder(2), display-preorder(3), display-postorder(4), exit(0)\n");
        while(1) {
                printf("CMD?> "); scanf("%d", &ch);
                switch(ch) {
                        case 0: return;
                        case 1: printf("Ele: "); scanf("%d", &a);
                                tree = insert(tree, a); break;
                        case 2: displayLNR(tree); printf("\n"); break;
                        case 3: displayNLR(tree); printf("\n"); break;
                        case 4: displayLRN(tree); printf("\n"); break;
                        default: printf("Bad CMD\n");
                }
        }
}
