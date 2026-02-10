#include <iostream>
using namespace std;

void generaScontrino(double aPrezzo[], string aNomeProdotto[], double aIva[], int aNumeroEsemplari[], int numeroLineeScontrino)
{
    double totale = 0;
    for (int i = 0; i < numeroLineeScontrino; i++)
    {
        cout << aNumeroEsemplari[i] << " " << aNomeProdotto[i] << " " << aPrezzo[i] << "€ IVA " << aIva[i] * 100 << "%" << endl;
        totale = totale + aNumeroEsemplari[i] * aPrezzo[i] * (aIva[i] + 1);
    }

    cout << "il totale e': " << totale << "€" << endl;
}

void acquisisci()
{
    double prezzi[100];
    string nomiProdotto[100];
    double iva[100];
    int numeriEsemplari[100];
    int numeroLineeScontrino = 0;

    for (int i = 0; i < 100; i++)
    {

        string tmpNomeInserito;
        cout << "inserisci un nome di prodotto o 'ok' per terminare: ";
        cin >> tmpNomeInserito;
        if (tmpNomeInserito == "ok")
        {
            break;
        }
        nomiProdotto[i] = tmpNomeInserito;

        cout << "inserisci il prezzo del prodotto: ";
        cin >> prezzi[i];
        cout << "inserisci l'iva del prodotto: ";
        cin >> iva[i];
        cout << "inserisci il numero di esemplari: ";
        cin >> numeriEsemplari[i];
        numeroLineeScontrino++;
    }
    generaScontrino(prezzi, nomiProdotto, iva, numeriEsemplari, numeroLineeScontrino);
}

int main()
{
    acquisisci();
    return 0;
}