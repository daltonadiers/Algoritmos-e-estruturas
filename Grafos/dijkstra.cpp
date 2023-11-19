#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#define INF ((int)1e9)

using namespace std;

typedef pair <int , int > ii;
typedef vector <ii > vii;


int N, M;
vector <int> dist;
vector <vii> LG;

void dijkstra(int s){
    dist.assign(N, INF);
    dist[s] = 0;
    priority_queue <ii , vector <ii >, greater <ii > > Q;
    Q.push(ii(0, s));
    while (!Q.empty ()){
        int u = Q.top (). second; Q.pop ();
        for(auto e : LG[u]){
            int v = e.first , w = e.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                Q.push(ii(dist[v], v));
            }
        }
    }
}

int main(){
    cout << "Bem vindo ao algoritmo de dijsktra! Escreva em seguida o número de vértices e arestas: ";
    cin >> N >> M; cout << "\n";
    LG.resize(N);
    int a,b,c; 
    for(int i=0; i<M; i++){
        cout << "Digite o vértice origem e destino e o peso da aresta: ";
        cin >> a >> b >> c;
        if (a >= 0 && a < N && b >= 0 && b < N) {
            LG[a].push_back(make_pair(b, c));
        } else {
            cout << "Vértices fora do intervalo válido. Insira valores válidos.\n";
            i--;
        }
    }
    while(true){
        cout << "Você está no realizar consultas, digite 0 para sair, 1 para realizar nova consulta: \n";
        int p; cin >> p;
        if(p==0)break;
        cout << "Digite o source: ";int aux;
        cin >>  aux;
        dijkstra(aux);
        for(int i=0; i<(int)dist.size();i++){
            cout << "Distância para o vértice " << i << " é igual a: " << dist[i] << endl;
        }
    }
    return 0;
}