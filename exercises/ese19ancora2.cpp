#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int prezzi[] = {10, 5, 7, 50, 30, 70, 100};

int calcoloTotale(int nAdulti, int nBambini, int nAnziani, int nAutomobili,
     int nMotocicli, int nFurgone, int nCamion){
        int totale=0;
        totale =nAdulti * prezzi[0] + nBambini * prezzi[1] + nAnziani * prezzi[2] + nAutomobili * prezzi[3] +
         nMotocicli * prezzi[4] + nFurgone * prezzi[5] + nCamion * prezzi[6];


        return totale;
}

void richiediDati(){
    int nAdulti, nBambini, nAnziani, nAutomobili, nMotocicli, nFurgone, nCamion;

    cout << "inserisci il numero di adulti: ";
    cin >> nAdulti;
    
    cout << "inserisci il numero di nBambini: ";
    cin >> nBambini;
    
    
    cout << "inserisci il numero di nAnziani: "; 
    cin >> nAnziani; 

    cout << "inserisci il numero di nAutomobili: ";
    cin >> nAutomobili;
    
    cout << "inserisci il numero di nMotocicli: ";
    cin >> nMotocicli;

    cout << "inserisci il numero di nFurgone: ";
    cin >> nFurgone;

    cout << "inserisci il numero di nCamion: ";
    cin >> nCamion;

 cout << calcoloTotale(nAdulti, nBambini, nAnziani, nAutomobili, nMotocicli, nFurgone, nCamion);
}

int main(){

    richiediDati();
    return 0;

}

