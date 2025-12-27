#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *Tree;

void initTree(Tree *T);
void populateTree(Tree *T, int arr[], int size);
void insertTree(Tree *T, int data);
void insertRecursion(Tree *T, int data);
bool isFound(Tree T, int x);
bool isFoundRecursion(Tree T, int x);
void deleteElem(Tree *T, int x);
void preOrder(Tree T);

void initTree(Tree *T) {
	*T = NULL;
}

void populateTree(Tree *T, int arr[], int size) {
	for (int i = 0; i < size; i++) {
        insertRecursion(T, arr[i]);

        // uncomment if you wanna try non-recursion
        // insertTree(T, arr[i]);
	}
}

void insertTree(Tree *T, int data) {
	Tree temp = (Tree)malloc(sizeof(struct node));
	if(temp != NULL) {
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;

		Tree *trav;

		for (trav = T; *trav != NULL && (*trav)->data != data; 
				trav = (*trav)->data > data ? &(*trav)->left : &(*trav)->right){}

        if(*trav == NULL) {
            *trav = temp; // connect if element not found
        }
	}
}

void insertRecursion(Tree *T, int data) {
    if(*T == NULL) {
        Tree temp = (Tree)malloc(sizeof(struct node));
        if(temp != NULL) {
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            *T = temp;
        }
    }
    else if(data < (*T)->data) {
        insertRecursion(&(*T)->left, data);
    }
    else if(data > (*T)->data) {
        insertRecursion(&(*T)->right, data);
    }
}

bool isFound(Tree T, int x) {
    while(T != NULL && T->data != x) {
        if(T->data < x) {
            T = T->right;
        }
        else {
            T = T->left;
        }
    }

    return T == NULL ? false : true;
}

bool isFoundRecursion(Tree T, int x) {
    if(T == NULL) return false;
    if(T->data == x) return true;

    return (T->data < x) ? isFoundRecursion(T->right, x) : isFoundRecursion(T->left, x);
}  

void deleteElem(Tree *T, int x) {
    Tree* trav = T;
    Tree temp;

    while(*trav != NULL && (*trav)->data != x) {
        if((*trav)->data < x) {
            trav = &(*trav)->right;
        }
        else {
            trav = &(*trav)->left;
        }
    }

    if(*trav != NULL) {
        // if right is NULL then it can either have NO children or a left child
        if((*trav)->right == NULL) {
            temp = *trav;
            *trav = temp->left; // temp->left is either NULL or a node
        }
        else {
            Tree *successor = &(*trav)->right; // since right is not NULL, we start from there

            while((*successor)->left != NULL) { // while it is not the left-most node, keep traversing
                successor = &(*successor)->left;
            }

            (*trav)->data = (*successor)->data; // trav gets the data of successor
            temp = (*successor);
            *successor = temp->right; // gets the right node, which can either be NULL or a node
        }

        free(temp);
    }
}
   
void preOrder(Tree T) { 
	if (T != NULL) {
        printf("%d ", T->data);
		preOrder(T->left);
		preOrder(T->right);
	}
    else {
        printf("_ ");
    }
}

int main() {
    Tree T;
	int arr[] = {4, 2, 5, 2, 1};
	int size = sizeof(arr) / sizeof(arr[0]);

    initTree(&T);
	populateTree(&T, arr, size);

    int x = 4;
    printf("LOOP: %d %s in the tree\n", x, isFound(T, x) ? "IS" : "IS NOT");

    x = 2;
    printf("RECURSION: %d %s in the tree\n", x, isFound(T, x) ? "IS" : "IS NOT");

    x = 2;
    printf("\nBefore deleting %d: (Pre-order traversal)\n", x);
    preOrder(T);

    deleteElem(&T, x);

    printf("\nAfter deleting %d: (Pre-order traversal)\n", x);
    preOrder(T);

    return 0;
}

