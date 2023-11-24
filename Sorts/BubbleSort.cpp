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

void bubbleSort(int n){
    for(int i=0; i<n; i++){
        for (int j = 0; j < n - 1 - i; j++) {  // A CADA ITERAÇÃO DE I, GARANTIMOS QUE O MAIOR ELEMENTO ESTEJA NA ÚLTIMA POSIÇÃO, PENULTIMA E ASSIM POR DIANTE, POR ISSO NÃO PRECISAMOS MAIS TESTAR
            if (ordenar[j] > ordenar[j + 1]) {
                swap(ordenar[j], ordenar[j + 1]);
            }
        }
    }
}

int main(){
    cout << "Bem vindo à ordenação por BubbleSort! Digite o número de elementos que deseja ordenar: ";
    int n; cin >> n; cout << "\n";
    geraRandom(n);
    auto start = chrono::high_resolution_clock::now();
    bubbleSort(n);
    auto end = chrono::high_resolution_clock::now();
    auto durationSec = chrono::duration<double>(end - start).count();
    for(int i=0; i<n; i++){ // ATENÇÃO: A COMPLEXIDADE DESSE LAÇO NÃO SERÁ CONTABILIZADA NO TIMER FINAL
        cout << ordenar[i] << " ";
    }
    cout << "\n";
    cout << "Tempo de execução do BubbleSort: " << fixed << setprecision(3) << durationSec << " segundos.\n";
    return 0;
}