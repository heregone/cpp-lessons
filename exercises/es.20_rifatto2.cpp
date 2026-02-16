#include <iostream>

using namespace std;

const int N = 3;

string nomi[N] = {"Gazzetta", "Corriere", "Repubblica"};
double prezzi[N] = {(1, 5), 2, 3};

double totale;

void calcoloTotale(int nGazzetta, int nCorriere, int nRepubblica)
{
    cout << "il totale e': " << nGazzetta * prezzi[0] + nCorriere * prezzi[1] + nRepubblica * prezzi[2] << endl;
}

void registroVendite(){

int quantita[N];


    for(int i=0; i<N; i++){
    cout << "inserisci il valore di vendita di: " << nomi[i];
    cin >> quantita[i];}
   calcoloTotale(quantita[0], quantita[1], quantita[2]);
}

int main(){

    registroVendite();

}

//RISOLTO CON RIFERIMENTO A PUNTATORE VARIABILE
/*
#include <iostream>
#include <string>
using namespace std;

const int N = 3;

string nomi[N]   = {"Gazzetta", "Corriere", "Repubblica"};
double prezzi[N] = {1.5, 2.0, 3.0}; // NOTA: 1.5 si scrive con il punto, non (1, 5) [web:54]

void leggiQuantita(const string &nome, int &q) {   // q passato per riferimento [web:39][web:41]
    cout << "Inserisci il numero di copie vendute di " << nome << ": ";
    cin >> q;
    if (q < 0) q = 0;
}

void calcoloTotale(const int quantita[], double &totale) { // totale per riferimento [web:39][web:41]
    totale = 0.0;
    for (int i = 0; i < N; i++) {
        totale += quantita[i] * prezzi[i];
    }
}

void registroVendite() {
    int quantita[N];
    double totale;

    for (int i = 0; i < N; i++) {
        leggiQuantita(nomi[i], quantita[i]); // qui passi direttamente la “cella” dell’array per riferimento
    }

    calcoloTotale(quantita, totale);

    cout << "Il totale e': " << totale << " euro" << endl;
}

int main() {
    registroVendite();
    return 0;
}*/