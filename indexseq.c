#include <stdio.h>
struct Record {
    int key;
};
int indexSequentialSearch(struct Record records[], int index[], int n, int key) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        if (key >= index[i] && key < index[i + 1])
            break;
    }
    for (j = index[i]; j < index[i + 1]; j++) {
        if (records[j].key == key)
            return j;
    }

    return -1;
}

int main() {
    int n, i;
    printf("Enter the number of records: ");
    scanf("%d", &n);

    struct Record records[n];
    int index[n];
    printf("Enter the records:\n");
    for (i = 0; i < n; i++) {
        printf("Enter key for record %d: ", i + 1);
        scanf("%d", &records[i].key);
        index[i] = i;
    }

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    int result = indexSequentialSearch(records, index, n, key);
    if (result != -1) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not found\n");
    }
      return 0;
}
