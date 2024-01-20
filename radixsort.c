#include <stdio.h>

void radix_sort(int arr[], int n) {
    int max = 0; 
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int output[n];
        int count[10] = {0};
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

int main() {
    int n;
    printf("\nEnter the number of elements:");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter the elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    radix_sort(arr, n);

    printf("\nSorted array is:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
