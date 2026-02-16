#include <iostream>
#include <iomanip>
using namespace std;

double totaleDaPagare(double importo) {
    // Sconto 20% se importo > 500
    if (importo > 500.0) {
        importo = importo * 0.80;
    }

    // Spedizione: gratis se importo > 200, altrimenti 4 euro
    if (importo <= 200.0) {
        importo = importo + 4.0;
    }

    return importo;
}

int main() {
    const int N = 3;

    double prezzi[N] = {15.00, 80.00, 35.00}; // esempi: cambia come vuoi
    string nomi[N] = {"Maglietta", "Scarpe", "Pantaloni"};

    int pezzi[N];
    double importo = 0.0;

    cout << "Inserisci i pezzi comprati per i 3 prodotti (in sequenza):\n";

    for (int i = 0; i < N; i++) {
        cout << "Pezzi di " << nomi[i] << ": ";
        cin >> pezzi[i];

        importo += pezzi[i] * prezzi[i];
    }

    double daPagare = totaleDaPagare(importo);

    cout << fixed << setprecision(2);
    cout << "Importo prodotti: " << importo << " euro\n";
    cout << "Totale da pagare: " << daPagare << " euro\n";

    return 0;
}