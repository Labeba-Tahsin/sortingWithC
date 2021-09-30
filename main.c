#include<stdio.h>
int main() {
    int inputArray[] = {5, 15, -3, 6, 9, 20, 100, -78};
    printArray(inputArray, "Unsorted Array:");

    bubbleSort(inputArray);
    quickSort(inputArray);
    mergeSort(inputArray);
    insertionSort(inputArray);
    return 0;
}

void printArray(int arr[], char msg[]) {
    printf("%s\t",msg);
    for(int i=0;i<sizeof(arr);i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[]) {
    int n=sizeof(arr);
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printArray(arr,"Bubble sort:");
}

void quickSort(arr){
    quickSortRecursion(arr,0,sizeof(arr)-1);
    printArray(arr,"Quick sort:");
}

void quickSortRecursion(int arr[],int low,int high) {
    if(low<high ){
        int pivot=partition(arr,low,high);
        quickSortRecursion(arr,low,pivot-1);
        quickSortRecursion(arr,pivot+1,high);
    }
}

void swap(int arr[],int i,int j) {
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[],int low,int high){
    int i=low-1;
    int pivotValue=arr[high];
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivotValue){
            i=i+1;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1, high);
    return (i+1);
}

void mergeSort(arr){
    mergeSortRecursion(arr,0,sizeof(arr)-1);
    printArray(arr,"Merge sort:");
}

void mergeSortRecursion(int arr[],int left,int right){
    if(left < right) {
        int mid=(left+right-1)/2;
        mergeSortRecursion(arr,left,mid);
        mergeSortRecursion(arr,mid+1,right);
        merge(arr,left,right,mid);
    }
}

void merge(int arr[],int left,int right,int mid){
    int sizeL=mid-left+1;
    int sizeR=right-mid;
    int leftArr[sizeL]; int rightArr[sizeR];
    for(int i=0;i<sizeL;i++){
        leftArr[i]=arr[left+i];
    }
    for(int i=0;i<sizeR;i++){
        rightArr[i]=arr[mid+1+i];
    }
    int initIndex=left;
    int i=0,j=0;
    while(i<sizeL && j <sizeR){
        if (leftArr[i] <= rightArr[j]) {
            arr[initIndex] = leftArr[i];
            i++;
        }
        else {
            arr[initIndex] = rightArr[j];
            j++;
        }
        initIndex++;
    }
    while (i < sizeL) {
        arr[initIndex] = leftArr[i];
        i++;
        initIndex++;
    }
    while (j < sizeR) {
        arr[initIndex] = rightArr[j];
        j++;
        initIndex++;
    }
}

void insertionSort(int arr[]){
    int n=sizeof(arr);
    int pointerElem,j;
    for(int i=1;i<n;i++){
        pointerElem=arr[i];
        j=i-1;
        while(arr[j]>pointerElem && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=pointerElem;
    }
    printArray(arr,"Insertion sort:");
}


