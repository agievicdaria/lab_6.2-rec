#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

void generateArray(int arr[], int size, int lower, int upper, int i) {
    if (i < size) {
        arr[i] = lower + rand() % (upper - lower + 1);
        generateArray(arr, size, lower, upper, i + 1);
    }
}

void printArray(const int arr[], int n, int i) {
    if (i < n) {
        cout << setw(4) << arr[i] << " ";
        printArray(arr, n, i + 1);
    } else {
        cout << endl;
    }
}

void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapMinMax(int arr[], int start, int end, int minIndex, int maxIndex) {
    if (start <= end) {
        if (arr[start] < arr[minIndex]) {
            minIndex = start;
        } else if (arr[start] > arr[maxIndex]) {
            maxIndex = start;
        }
        swapMinMax(arr, start + 1, end, minIndex, maxIndex);
    } else {
        swapElements(arr[minIndex], arr[maxIndex]);
    }
}

int main() {
    int n, min, max;
    cout << "Введіть розмір масиву: "; cin >> n;
    cout << "Введіть мінімальне значення масиву: "; cin >> min;
    cout << "Введіть максимальне значення масиву: "; cin >> max;

    int arr[n];

    generateArray(arr, n, min, max, 0);
    cout << "Початковий масив:" << endl;
    printArray(arr, n, 0);

    int minIndex = 0;
    int maxIndex = 0;

    swapMinMax(arr, 0, n - 1, minIndex, maxIndex);

    cout << "Модифікований масив:" << endl;
    printArray(arr, n, 0);

    return 0;
}
