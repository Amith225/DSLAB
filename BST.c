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

Tree minValueNode(Tree tree) {
    Tree trav = tree;
    while(trav != NULL && trav->left != NULL) {
        trav = trav->left;
    }
    return trav;
}

Tree deleteNode(Tree tree, int a) {
    if (tree == NULL) return tree;

    if (a < tree->val)
        tree->left = deleteNode(tree->left, a);
    else if (a > tree->val)
        tree->right = deleteNode(tree->right, a);
    else {
        // zero or single child
        if (tree->left == NULL) {
            Tree temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL) {
            Tree temp = tree->left;
            free(tree);
            return temp;
        }
 
        // two children
        Tree temp = minValueNode(tree->right);
        tree->val = temp->val;
        tree->right = deleteNode(tree->right, temp->val);
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
        printf("CMDs: insert(1), display-inorder(2), display-preorder(3), display-postorder(4), del(5), exit(0)\n");
        while(1) {
                printf("CMD?> "); scanf("%d", &ch);
                switch(ch) {
                        case 0: return;
                        case 1: printf("Ele: "); scanf("%d", &a);
                                tree = insert(tree, a); break;
                        case 2: displayLNR(tree); printf("\n"); break;
                        case 3: displayNLR(tree); printf("\n"); break;
                        case 4: displayLRN(tree); printf("\n"); break;
                        case 5: printf("Ele: "); scanf("%d", &a);
                                tree = deleteNode(tree, a); break;
                        default: printf("Bad CMD\n");
                }
        }
}

// output(old, dosent include deleteNode):
// CMDs: insert(1), display-inorder(2), display-preorder(3), display-postorder(4), exit(0)
// CMD?> 1
// Ele: 7
// CMD?> 1
// Ele: 1
// CMD?> 1
// Ele: 0
// CMD?> 1
// Ele: 3
// CMD?> 1
// Ele: 2
// CMD?> 1
// Ele: 5
// CMD?> 1
// Ele: 4
// CMD?> 1
// Ele: 6
// CMD?> 1
// Ele: 9
// CMD?> 1
// Ele: 8
// CMD?> 1
// Ele: 10
// CMD?> 2
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
// CMD?> 3
// 7, 1, 0, 3, 2, 5, 4, 6, 9, 8, 10, 
// CMD?> 4
// 0, 2, 4, 6, 5, 3, 1, 8, 10, 9, 7, 
// CMD?> 
