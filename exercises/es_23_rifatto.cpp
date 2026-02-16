#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_OP = 1000;

// tipo: 'V' = versamento, 'P' = prelevamento, 'A' = assegno
void aggiungiOperazione(char tipi[], double importi[], int &n) {
    if (n >= MAX_OP) {
        cout << "Raggiunto numero massimo di operazioni.\n";
        return;
    }

    char t;
    double s;
    cout << "Tipo (V=versamento, P=prelievo, A=assegno): ";
    cin >> t;
    cout << "Somma: ";
    cin >> s;

    // normalizzo un minimo
    if (t >= 'a' && t <= 'z') t = char(t - 'a' + 'A');
    if (s < 0) s = 0;

    if (t != 'V' && t != 'P' && t != 'A') {
        cout << "Tipo non valido.\n";
        return;
    }

    tipi[n] = t;
    importi[n] = s;
    n++;
}

void stampaReport(double saldoIniziale, char tipi[], double importi[], int n) {
    int numV = 0, numP = 0, numA = 0;
    double totV = 0.0, totP = 0.0, totA = 0.0;

    for (int i = 0; i < n; i++) {
        if (tipi[i] == 'V') { numV++; totV += importi[i]; }
        else if (tipi[i] == 'P') { numP++; totP += importi[i]; }
        else if (tipi[i] == 'A') { numA++; totA += importi[i]; }
    }

    double saldoFinale = saldoIniziale + totV - totP - totA;

    cout << fixed << setprecision(2);
    cout << "\n--- REPORT ---\n";
    cout << "Versamenti: " << numV << " | Totale versato: " << totV << " euro\n";
    cout << "Prelevamenti: " << numP << " | Totale prelevato: " << totP << " euro\n";
    cout << "Assegni: " << numA << " | Totale prelevato con assegni: " << totA << " euro\n";
    cout << "Saldo finale: " << saldoFinale << " euro\n";
}

int main() {
    double saldoIniziale;
    cout << "Inserisci saldo iniziale: ";
    cin >> saldoIniziale;

    char tipi[MAX_OP];
    double importi[MAX_OP];
    int n = 0;

    int scelta;
    do {
        cout << "\n--- MENU CONTO CORRENTE ---\n";
        cout << "1) Inserisci operazione\n";
        cout << "2) Stampa report\n";
        cout << "0) Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: aggiungiOperazione(tipi, importi, n); break;
            case 2: stampaReport(saldoIniziale, tipi, importi, n); break;
            case 0: cout << "Uscita...\n"; break;
            default: cout << "Scelta non valida.\n";
        }
    } while (scelta != 0);

    return 0;
}
