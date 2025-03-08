#include <stdio.h>

void SetArray(int **, int *n);
void PrintArray(int[], int n, const char comment[20]);
int BinarySearch(int[], int n, int find);
void MergeSort(int t[], int k);
void Merge(int *u, int m, int *v, int n, int *t);

int main() {
    int n = 0, pos = -1, find = -1, *data;
    SetArray(&data, &n);
    PrintArray(data, n, "Origin");

    MergeSort(data, n);
    PrintArray(data, n, "Sorted");

    printf("Search (value): ");
    scanf("%d", &find);
    pos = BinarySearch(data, n, find);

    if (pos != -1) {
        printf("FOUND %d at POSITION = Arr[%d]\n", data[pos], pos);
    } else {
        printf("Value %d not found in the array.\n", find);
    }

    delete[] data; // Properly deallocate memory
    return 0;
}

void PrintArray(int *Arr, int n, const char comment[20]) {
    printf("\n%s: ", comment);
    for (int i = 0; i < n; i++) {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

void SetArray(int **Arr, int *n) {
    printf("Enter the number of elements: ");
    scanf("%d", n);
    *Arr = new int[*n]; // Dynamically allocate memory for array

    printf("Enter %d elements: ", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &(*Arr)[i]);
    }
}

int BinarySearch(int arr[], int n, int find) {
    int i = 0, j = n - 1, m = 0, pos = -1;
    while (i <= j) { // Corrected the condition to 'i <= j'
        m = (i + j) / 2;
        if (arr[m] < find)
            i = m + 1;
        else if (arr[m] > find)
            j = m - 1;
        else {
            pos = m; // Found the element
            break;
        }
    }
    return pos;
}

void MergeSort(int t[], int k) {
    int n = k;
    int M = n / 2;
    if (n <= 1) return;

    int *u = new int[M];
    int *v = new int[n - M];

    for (int i = 0; i < M; i++) {
        u[i] = t[i];
    }
    for (int i = M; i < n; i++) {
        v[i - M] = t[i];
    }
    MergeSort(u, M);
    MergeSort(v, n - M);

    Merge(u, M, v, n - M, t);

    delete[] u;
    delete[] v;
}

void Merge(int *u, int m, int *v, int n, int *t) {
    int i = 0, j = 0;
    for (int k = 0; k < m + n; k++) {
        if (i >= m) {
            t[k] = v[j];
            j++;
        } else if (j >= n) {
            t[k] = u[i];
            i++;
        } else if (u[i] < v[j]) {
            t[k] = u[i];
            i++;
        } else {
            t[k] = v[j];
            j++;
        }
    }
}