#include<iostream>
using namespace std;

void merge(int array[], int left, int mid, int right){
    int subArr_a = mid - left + 1;
    int subArr_b = right - mid;

    int *leftArr = new int[subArr_a];
    int *rightArr = new int[subArr_b];

    for (int i = 0; i < subArr_a; i++){
        leftArr[i] = array[left + i];
    }
    for (int j = 0; j < subArr_b; j++){
        rightArr[j] = array[mid+1+j];
    }

    int index_one = 0, index_two = 0, index_merged = left;

    while (index_one < subArr_a && index_two < subArr_b){
        if (leftArr[index_one] <= rightArr[index_two]){
            array[index_merged] = leftArr[index_one];
            index_one++;
        }
        else{
            array[index_merged] = rightArr[index_two];
            index_two++;
        }
        index_merged++;
    }

    while (index_one < subArr_a){
        array[index_merged] = leftArr[index_one];
        index_one++;
        index_merged++;
    }
    while (index_two < subArr_b){
        array[index_merged] = rightArr[index_two];
        index_two++;
        index_merged++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void merge_sort(int array[], int begin, int end){
    if (begin >= end){
        return;
    }

    int mid = begin + (end - begin)/2;

    merge_sort(array,begin,mid);
    merge_sort(array,mid+1,end);

    merge(array,begin,mid,end);
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    merge_sort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);

    return 0;
}
