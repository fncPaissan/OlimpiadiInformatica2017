/*
Francesco Paissan - testo del problema: https://cms.di.unipi.it/#/task/spartizione/statement
*/

#include <fstream>
#include <cmath>

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int p, g, o, t = 0, gT = 1;

    in >> g; //input del numero di gemme
    in >> p; //input del numero di persone

    o = p - 1;  //gemme ad ogni giro senza toto

    while(g > 0){
        t += gT;    //aggiunge le gemme di toto per ogni giro sommandole a quelle precedenti
        g = g - (gT + o);   //diminuisce il numero di gemme in base a quante ne sono state distribuite

        if (g < 0){     //se il numero di gemme diventa minore di 0, allora sono state considerate gemme di troppo
            t = t - gT; //torniamo al valore precedente del totale
            g = g + (gT + o);   //torniamo al valore precedente di gemme

            t += g; //sommiamo il totale alle gemme rimaste
            g = -1; //usciamo dal loop
        }
        gT++;   //incremento counter
    }
    out << t;   //output del totale

    return 0;
}
