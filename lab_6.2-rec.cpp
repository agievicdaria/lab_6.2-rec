#include <iostream>
#include <climits>

using namespace std;

void generateArray(int arr[], int size, int lower, int upper, int i) {
    arr[i] = lower + rand() % (upper - lower + 1);
    if (i < size - 1) {
        generateArray(arr, size, lower, upper, i + 1);
    }
}

void printArray(const int arr[], int n) {
    if (n > 0) {
        cout << arr[n - 1] << " ";
        printArray(arr, n - 1);
    } else {
        cout << endl;
    }
}

void swapMinMax(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int maxIndex = start;
    int minIndex = start;

    for (int i = start; i <= end; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        } else if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    int temp = arr[maxIndex];
    arr[maxIndex] = arr[minIndex];
    arr[minIndex] = temp;

    swapMinMax(arr, start + 1, end - 1);
}


int main() {
    int n, min, max;
    cout << "Введіть розмір масиву: "; cin >> n;
    cout << "Введіть мінімальне значення масиву: "; cin >> min;
    cout << "Введіть максимальне значення масиву: "; cin >> max;

    int arr[n];

    generateArray(arr, n, min, max, 0);
    cout << "Початковий масив:" << endl;
    printArray(arr, n);

    swapMinMax(arr, 0, n - 1);

    cout << "Модифікований масив:" << endl;
    printArray(arr, n);

    return 0;
}