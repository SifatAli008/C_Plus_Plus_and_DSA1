#include<iostream>
using namespace std;

void swap(int a, int b, int arr[]) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    int arr[] = {7, 9, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sort: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    int flag;

    for (int i = 0; i < n - 1; i++) {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(j, j + 1, arr);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }

    cout << endl << "After sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
