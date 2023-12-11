#include <stdio.h>

int linearSearch(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n;
    printf("\nEnter the size of the array:");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter the elements of the array:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int element;
    printf("\nEnter the element to search: ");
    scanf("%d", &element);

    int result = linearSearch(arr, n, element);

    if (result != -1) {
        printf("\nElement %d found at index %d", element, result);
    } else {
        printf("\nElement %d not found in the array", element);
    }

    return 0;
}
