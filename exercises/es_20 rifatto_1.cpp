#include <iostream>
#include <iomanip>
using namespace std;

double guadagnoQuotidiano(int copie, double prezzo)
{
    return copie * prezzo;
}

int main()
{
    const int N = 3;

    // Prezzi dei 3 principali quotidiani (modifica come vuoi)
    double prezzi[N] = {1.50, 1.80, 2.00};
    string nomi[N] = {"Repubblica", "Corriere", "Gazzetta"};

    int copie[N];
    double totale = 0.0;

    cout << "Inserisci le copie vendute dei 3 quotidiani (in sequenza):\n";

    for (int i = 0; i < N; i++)
    {
        cout << "Copie quotidiano " << nomi[i] << ": ";
        cin >> copie[i];

        totale += guadagnoQuotidiano(copie[i], prezzi[i]);
    }

    cout << fixed << setprecision(2);
    cout << "Guadagno complessivo: " << totale << " euro\n";

    return 0;
}
