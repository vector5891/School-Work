#include <iostream>
#include <thread>
//#include <ctime>
//using namespace std;

//had to add "TARGET_LINK_LIBRARIES(ConcurrencyTest pthread)" to the cmake file
//in CLion in order for the compiler to work
//will soon test this in other compilers/environments


void bubbleSort(int arr[], int arrSize);
void insertSort(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main(){
    const int arrSize = 10;
    int Arr1[arrSize] = { 1, 27, 89, 12, 78, 19, 0, 1, 12, 3};
    int Arr2[arrSize] = { 4, 13, 90, 90, 15, 13, 4, 5, 6, 12};
    //time_t start = time(NULL);
    std::thread thread1(bubbleSort, Arr1, arrSize);
    //thread1.join(); // sequential
    std::thread thread2(insertSort, Arr2, arrSize);
    std::thread threadP1(printArray, Arr1, arrSize);
    std::thread threadP2(printArray, Arr2, arrSize);
    std::cout << "ARRAYS READY\n";
    thread1.join();
    thread2.join();
    //time_t stop = time(NULL);
    threadP1.join();
    threadP2.join();
    //cout << "ELAPSED " << (stop - start) << "\n"
    std::cout << "Printing out the array without using threads "<< std::endl;
    printArray(Arr1, arrSize);
    std::cout << std::endl;
    printArray(Arr2, arrSize);
    return 0;
}

/*
 * what I've learned from doing this:
 * the multi-thread processes occur in an uniformed order even though it's written linearly
 * an unregulated/uncontrolled multi-thread process will yield different results every time (obvious)
 * We(professor League) tried timing how long it took for the threads to execute & join(),
 * it was inaccurate -- yields 20 seconds every time (?????)
 * */

void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void bubbleSort(int arr[], int arrSize){
    int temp;
    for (int i = 0; i < arrSize; i++){
        for (int j = 0; j < arrSize - i; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void insertSort(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        int j = i;
        while ((j > 0) && (arr[j-1] > arr[j])){
            std::swap(arr[j], arr[j-1]);
            j--;
        }
    }
}
