#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
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
struct Node* createBinaryTree() {
    struct Node* root = NULL;
    int n, value;

    printf("\nEnter the number of nodes:");
    scanf("%d", &n);
    printf("\nEnter the values of the nodes:");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    return root;
}
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = createBinaryTree();

    printf("\nInorder Traversal:");
    inorderTraversal(root);

    printf("\nPreorder Traversal:");
    preorderTraversal(root);

    printf("\nPostorder Traversal:");
    postorderTraversal(root);

    return 0;
}
