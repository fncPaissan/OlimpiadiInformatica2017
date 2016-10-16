/*
Francesco Paissan - testo del problema:https://cms.di.unipi.it/#/task/discesa/statement
*/

#include <fstream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > d;
vector<vector<int> > pyr;

int sol(int i, int j);

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N;
    d.resize(N);
    pyr.resize(N);
    for (unsigned i=0; i<N; i++) {
        for (unsigned j=0; j<=i; j++) {
            int a;
            in >> a;
            pyr[i].push_back(a);
        }
        d[i].resize(i+1, -1);
    }
    out <<  sol(0, 0) << endl;
}

int sol(int i, int j) {
    if(i == N-1)
        return pyr[i][j];

    if(d[i][j] != -1)
        return d[i][j];

    d[i][j] = pyr[i][j] + max(sol(i+1, j), sol(i+1, j+1));

    return d[i][j];
}
