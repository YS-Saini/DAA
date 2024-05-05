#include<iostream>
using namespace std;

int item_no = 0;

struct item{
    int sno = ++item_no;
    int profit;
    int weight;
    bool picked = false;
    float profitByWeight;
};

void merge(item array[], int left, int mid, int right){
    int subArr_a = mid - left + 1;
    int subArr_b = right - mid;

    item *leftArr = new item[subArr_a];
    item *rightArr = new item[subArr_b];

    for (int i = 0; i < subArr_a; i++){
        leftArr[i] = array[left + i];
    }
    for (int j = 0; j < subArr_b; j++){
        rightArr[j] = array[mid+1+j];
    }

    int index_one = 0, index_two = 0, index_merged = left;

    while (index_one < subArr_a && index_two < subArr_b){
        if (leftArr[index_one].profitByWeight >= rightArr[index_two].profitByWeight){
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

void merge_sort(item array[], int begin, int end){
    if (begin >= end){
        return;
    }

    int mid = begin + (end - begin)/2;

    merge_sort(array,begin,mid);
    merge_sort(array,mid+1,end);

    merge(array,begin,mid,end);
}

int main(){
    const int n = 5;
    item* item_list = new item[5];
    int profits[] = {5,8,10,13,16};
    int weights[] = {2,3,4,5,7};

    for (int i = 0; i < 5; i++){
        item* temp = new item;
        temp->profit = profits[i];
        temp->weight = weights[i];
        temp->profitByWeight = (float) temp->profit / (float) temp->weight;
        item_list[i] = *temp;
        delete temp;
    }
    
    merge_sort(item_list,0,4);

    for (int i = 0; i < 5; i++){
        cout << item_list[i].sno << " " << item_list[i].profit << " " << item_list[i].profitByWeight << endl;
    }

    delete[] item_list;
    return 0;
}
