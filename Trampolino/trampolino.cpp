#include <fstream>
#include <vector>

using namespace std;

int salta(int N, vector <int> E);

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, eT = 0;
    vector <int> e;

    in >> n;
    e.resize(n);

    for(int i = 0; i < n; i++){
        in >> e[i];
    }

    out << salta(n, e);

    return 0;
}

int salta(int N, vector <int> E) {
    int posizione_corrente = 0, ultima_controllata = 0, soluzione = 0;

    while (posizione_corrente < N) {
        soluzione++;
        int posizione_successiva = posizione_corrente + E[posizione_corrente];

        if (posizione_successiva >= N)
            break;
        int distanza_raggiungibile = posizione_successiva + E[posizione_successiva];

        for (int i = posizione_successiva - 1; i > ultima_controllata; --i) {
            if (i + E[i] > distanza_raggiungibile) {
                posizione_successiva = i;
                distanza_raggiungibile = i + E[i];
            }
        }

        ultima_controllata = posizione_corrente + E[posizione_corrente];
        posizione_corrente = posizione_successiva;
    }

    return soluzione;
}
