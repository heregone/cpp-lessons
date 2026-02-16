#include <iostream>
#include <string>
using namespace std;

void generaScontrino(double aPrezzo[], string aNomeProdotto[], double aIva[],
                     int aNumeroEsemplari[], int numeroLineeScontrino)
{
    double totale = 0;

    for (int i = 0; i < numeroLineeScontrino; i++)
    {
        cout << aNumeroEsemplari[i] << " " << aNomeProdotto[i]
             << " " << aPrezzo[i] << "€ IVA " << aIva[i] * 100 << "%" << endl;

        totale = totale + aNumeroEsemplari[i] * aPrezzo[i] * (aIva[i] + 1);
    }

    cout << "il totale e': " << totale << "€" << endl;
}

void acquisisci()
{
    const int MAX = 100;

    double prezzi[MAX];
    string nomiProdotto[MAX];
    double iva[MAX];
    int numeriEsemplari[MAX];

    int numeroLineeScontrino = 0;

    while (numeroLineeScontrino < MAX)
    {
        string tmpNomeInserito;
        cout << "inserisci un nome di prodotto o 'ok' per terminare: ";
        cin >> tmpNomeInserito;

        if (tmpNomeInserito == "ok")
        {
            break;
        }

        nomiProdotto[numeroLineeScontrino] = tmpNomeInserito;

        cout << "inserisci il prezzo del prodotto: ";
        cin >> prezzi[numeroLineeScontrino];

        cout << "inserisci l'iva del prodotto (es. 0.22): ";
        cin >> iva[numeroLineeScontrino];

        cout << "inserisci il numero di esemplari: ";
        cin >> numeriEsemplari[numeroLineeScontrino];

        numeroLineeScontrino++;
    }

    generaScontrino(prezzi, nomiProdotto, iva, numeriEsemplari, numeroLineeScontrino);
}

int main()
{
    acquisisci();
    return 0;
}
