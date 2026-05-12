
#include <stdio.h>


void insertionSort(int arr[], int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        int key = arr[i], j = i - 1;
        while (j >= l && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}


void hybridSort(int arr[], int l, int r, int k) {
    if (r - l + 1 <= k) {
        insertionSort(arr, l, r);
        return;
    }
    int m = l + (r - l) / 2;
    hybridSort(arr, l, m, k);
    hybridSort(arr, m + 1, r, k);
    merge(arr, l, m, r);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {39, 9, 81, 45, 90, 27, 72, 18};
    int n = 8;
    int k = 3; 

    printf("Input:  "); printArray(arr, n);
    hybridSort(arr, 0, n - 1, k);
    printf("Output: "); printArray(arr, n);
    return 0;
}
