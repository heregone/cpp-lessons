#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Array dei tipi e prezzi
const string tipiPersone[] = {"adulto", "bambino", "anziano"};
const int prezziPersone[] = {10, 5, 7};
const int numPersone = 3;

const string tipiMezzi[] = {"automobile", "motociclo", "furgone", "camion"};
const int prezziMezzi[] = {50, 30, 70, 100};
const int numMezzi = 4;

// Funzione per trovare il prezzo di un tipo
int trovaPrezzoPersona(const string& tipo) {
    for (int i = 0; i < numPersone; i++) {
        if (tipiPersone[i] == tipo) {
            return prezziPersone[i];
        }
    }
    return -1; // non trovato
}

int trovaPrezzoMezzo(const string& tipo) {
    for (int i = 0; i < numMezzi; i++) {
        if (tipiMezzi[i] == tipo) {
            return prezziMezzi[i];
        }
    }
    return -1; // non trovato
}

// Funzione di input
double calcolaTotale() {
    double totale = 0;
    string input;
    
    cout << "Inserisci persone e mezzi (formato: 'tipo numero', scrivi 'ok' per terminare)" << endl;
    cout << "Tipi disponibili:" << endl;
    cout << "  Persone: adulto (10€), bambino (5€), anziano (7€)" << endl;
    cout << "  Mezzi: automobile (50€), motociclo (30€), furgone (70€), camion (100€)" << endl;
    cout << endl;
    
    while (true) {
        cout << "> ";
        getline(cin, input);
        
        // Controlla se l'utente vuole terminare
        if (input == "ok") {
            break;
        }
        
        // Parse dell'input
        stringstream ss(input);
        string tipo;
        int numero;
        
        ss >> tipo >> numero;
        
        if (ss.fail() || numero <= 0) {
            cout << "Input non valido. Usa il formato: 'tipo numero'" << endl;
            continue;
        }
        
        // Converti il tipo in minuscolo
        for (char& c : tipo) {
            c = tolower(c);
        }
        
        // Cerca prima nelle persone
        int prezzo = trovaPrezzoPersona(tipo);
        if (prezzo != -1) {
            totale += prezzo * numero;
            cout << "Aggiunti " << numero << " " << tipo << " = " << (prezzo * numero) << "€" << endl;
            continue;
        }
        
        // Poi cerca nei mezzi
        prezzo = trovaPrezzoMezzo(tipo);
        if (prezzo != -1) {
            totale += prezzo * numero;
            cout << "Aggiunti " << numero << " " << tipo << " = " << (prezzo * numero) << "€" << endl;
            continue;
        }
        
        // Non trovato
        cout << "Tipo '" << tipo << "' non riconosciuto." << endl;
    }
    
    return totale;
}

int main() {
    double totale = calcolaTotale();
    cout << "\n==================================" << endl;
    cout << "Costo totale: " << totale << " euro" << endl;
    cout << "==================================" << endl;
    
    return 0;
}
