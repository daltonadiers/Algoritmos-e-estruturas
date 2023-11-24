#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;

void geraRandom(int arr[], int n){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(-10000,10000);
    for(int i=0; i<n; i++){
        arr[i]=distribution(gen);
    }
}

void merge(int array[], int const left, int const mid, int const right){
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)rightArray[j] = array[mid + 1 + j];
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]<= rightArray[indexOfSubArrayTwo]){
            array[indexOfMergedArray]= leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else{
            array[indexOfMergedArray]=rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}


void mergeSort(int array[], int const begin, int const end){
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main(){
    cout << "Digite o número de elementos a serem ordenados: ";
    int n; cin >> n;cout << "\n";
    int *arr = new int[n];
    geraRandom(arr, n);
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n-1);
    auto end = chrono::high_resolution_clock::now();
    auto durationSec = chrono::duration<double>(end - start).count();
    for(int i=0; i<n; i++){   // ATENÇÃO: A COMPLEXIDADE DESSE LAÇO NÃO SERÁ CONTABILIZADA NO TIMER FINAL
        cout << arr[i] << " ";
    }cout << "\n";
    cout << "Tempo de execução do MergeSort: " << fixed << setprecision(3) << durationSec << " segundos.\n";
    delete[] arr;
    return 0;
}