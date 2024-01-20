#include <stdio.h>
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            return binarySearchRecursive(arr, mid + 1, high, key);
        else
            return binarySearchRecursive(arr, low, mid - 1, key);
    }
    return -1;
}

int main() {
    int n;
    printf("\nEnter the size of the array:");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter %d elements in ascending order:", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("\nEnter the element to search:");
    scanf("%d", &key);

    int result = binarySearchRecursive(arr, 0, n - 1, key);
    if (result != -1) {
        printf("\nElement %d found at index %d", key, result);
    } else {
        printf("\nElement %d not found in the array", key);
    }
     return 0;
}
