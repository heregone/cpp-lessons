#include <iostream>
using namespace std;

const int MAX = 2000;

void inserisciBlocchi(int magazzino[], int &presenti) {
    int q;
    cout << "Quanti blocchi vuoi inserire? ";
    cin >> q;

    if (q < 0) q = 0;
    if (presenti + q > MAX) {
        cout << "Supera la capienza! Inserisco solo " << (MAX - presenti) << " blocchi.\n";
        q = MAX - presenti;
    }

    for (int i = presenti; i < presenti + q; i++) {
        magazzino[i] = 1;
    }
    presenti += q;
}

void vendiBlocchi(int magazzino[], int &presenti) {
    int q;
    cout << "Quanti blocchi vuoi vendere? ";
    cin >> q;

    if (q < 0) q = 0;
    if (q > presenti) {
        cout << "Non puoi vendere piu' di quelli presenti! Vendo solo " << presenti << " blocchi.\n";
        q = presenti;
    }

    for (int i = presenti - 1; i >= presenti - q; i--) {
        magazzino[i] = 0;
    }
    presenti -= q;
}

void visualizzaPresenti(int presenti) {
    cout << "Blocchi presenti in magazzino: " << presenti << " / " << MAX << "\n";
}

int main() {
    int magazzino[MAX] = {0};
    int presenti = 0;

    int scelta;
    do {
        cout << "\n--- MENU MAGAZZINO ---\n";
        cout << "1) Inserisci nuovi blocchi\n";
        cout << "2) Vendi blocchi\n";
        cout << "3) Visualizza numero blocchi presenti\n";
        cout << "0) Esci\n";
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: inserisciBlocchi(magazzino, presenti); break;
            case 2: vendiBlocchi(magazzino, presenti); break;
            case 3: visualizzaPresenti(presenti); break;
            case 0: cout << "Uscita...\n"; break;
            default: cout << "Scelta non valida.\n";
        }
    } while (scelta != 0);

    return 0;
}
