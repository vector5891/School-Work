#include <iostream>
#include <time.h>

using namespace std;
void heapFunc(int arr[], int arrSize, int index);
void heapSort(int arr[], int arrSize);
void printArr(int arr[], int arrSize);

int main() {
    srand(time(NULL));
    //
    cout << "--------------\nunsorted Array: \n";
    const int arrSize = 50000;
    int Arr[arrSize] = {};
    for(int i = 0; i < arrSize; i++) {   //random arr[i] values
        Arr[i] = rand() % 100000 + 1;
    }
    printArr(Arr, arrSize);
    //
    heapSort(Arr, arrSize);
    cout << "\nsorted Array \n";
    printArr(Arr, arrSize);

    return 0;
}

void printArr(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i++){
        cout << arr[i];
        if(i < arrSize -1){
            cout << ", ";
        }
        if((i%1000 == 0) && (i != 0)){
            cout << endl;
        }
    }
    cout << endl;
}
void heapSort(int arr[], int arrSize){
    for (int i = arrSize / 2 - 1; i >= 0; i--) {
        heapFunc(arr, arrSize, i);
    }
    for (int i= arrSize-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapFunc(arr, i, 0);
    }
}
void heapFunc(int arr[], int arrSize, int index) {
    int largest =     index;
    int left    = 2 * index + 1;
    int right   = 2 * index + 2;

    if (left < arrSize && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < arrSize && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapFunc(arr, arrSize, largest);
    }
}
