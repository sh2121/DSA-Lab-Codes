#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("\nEnter the number of nodes:");
    scanf("%d", &n);

    printf("\nEnter the values of the nodes:");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\nInorder Traversal:");
    inorder(root);

    printf("\nPreorder Traversal:");
    preorder(root);

    printf("\nPostorder Traversal:");
    postorder(root);

    return 0;
}
