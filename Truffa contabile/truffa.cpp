/*
Raffaele Tranquillini - testo del problema: https://cms.di.unipi.it/#/task/ois_truffa/statement
*/

#include <fstream>
#include <algorithm>

 using namespace std;


 int main()
 {
     ifstream in("input.txt");
     ofstream out("output.txt");

     int N, Nneg, somma, counter;
     somma = 0;
     Nneg = 0;
     counter = 0;
     in >> N;

     int bilancio[N];
     int negativi[N];

     for(int i = 0; i < N; i++) {
         in >> bilancio[i];
         somma += bilancio[i];
         if(bilancio[i] < 0) {
             Nneg++;
             negativi[Nneg-1] = bilancio[i];
         }
     }

     sort(negativi, negativi+Nneg);

     while(somma <= 0) {
         if(Nneg > counter) {
             somma += (negativi[counter] * -2);
         } else {
             // impossibile
             break;
         }
         counter++;
     }

     out << counter;

     return 0;
 }
