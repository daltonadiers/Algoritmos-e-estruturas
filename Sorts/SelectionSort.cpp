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

void selectionSort(int n){
    int indiceMinimo;
    for(int i=0;i<n-1;i++){
        indiceMinimo=i;
        for(int j=i+1;j<n;j++){
            if(ordenar[j]<ordenar[indiceMinimo])indiceMinimo=j;
        }
        if(indiceMinimo!=i)swap(ordenar[indiceMinimo],ordenar[i]);
    }
}

int main(){
    cout << "Bem vindo à ordenação por SelectionSort! Digite o número de elementos que deseja ordenar: ";
    int n; cin >> n; cout << "\n";
    geraRandom(n);
    auto start = chrono::high_resolution_clock::now();
    selectionSort(n);
    auto end = chrono::high_resolution_clock::now();
    auto durationSec = chrono::duration<double>(end - start).count();
    for(int i=0; i<n; i++){ // ATENÇÃO: A COMPLEXIDADE DESSE LAÇO NÃO SERÁ CONTABILIZADA NO TIMER FINAL
        cout << ordenar[i] << " ";
    }
    cout << "\n";
    cout << "Tempo de execução do SelectionSort: " << fixed << setprecision(3) << durationSec << " segundos.\n";
    return 0;
}