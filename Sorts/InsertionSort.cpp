#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>

using namespace std;

vector <int> ordenar;

void geraRandom(int n){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(-10000,10000);
    for(int i=0; i<n; i++){
        ordenar.push_back(distribution(gen));
    }
}   

void insertionSort(int n){
    int key, j;
    for(int i=1; i<n;i++){
        key = ordenar[i];
        j=i-1;
        while (j >= 0 && ordenar[j] > key) {
            ordenar[j + 1] = ordenar[j];
            j = j - 1;
        }
        ordenar[j + 1] = key;
    }
}

int main(){
    cout << "Bem vindo à ordenação por InsertionSort! Digite o número de elementos que deseja ordenar: ";
    int n; cin >> n; cout << "\n";
    geraRandom(n);
    auto start = chrono::high_resolution_clock::now();
    insertionSort(n);
    auto end = chrono::high_resolution_clock::now();
    auto durationSec = chrono::duration<double>(end - start).count();
    for(int i=0; i<n; i++){
        cout << ordenar[i] << " ";
    }
    cout << "\n";
    cout << "Tempo de execução do InsertionSort: " << fixed << setprecision(3) << durationSec << " segundos.\n";
    return 0;
}