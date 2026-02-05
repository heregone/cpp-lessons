/*
 * ESERCIZIO 18 - Sconto sul secondo prodotto
 * 
 * Un negozio effettua uno sconto del 30% sul secondo prodotto 
 * meno caro acquistato.
 * 
 * Realizza una funzione che acquisisce i prezzi dei due prodotti 
 * e restituisce il totale da pagare.
 * 
 * Cosa impariamo:
 * - Funzioni con parametri
 * - Confronto tra valori (if)
 * - Calcolo percentuali
 * - Return di valori
 */

#include <iostream>
using namespace std;

// ============================================
// SEZIONE 1: FUNZIONE PER CALCOLARE IL TOTALE
// ============================================

/*
 * Funzione: calculateTotal
 * 
 * Calcola il totale da pagare applicando lo sconto del 30%
 * al prodotto meno caro.
 * 
 * Parametri:
 *   - price1: prezzo del primo prodotto
 *   - price2: prezzo del secondo prodotto
 * 
 * Restituisce: il totale da pagare
 */
double calculateTotal(double price1, double price2) {
    
    // STEP 1: Determina quale prodotto costa meno
    double cheaperPrice;   // Prezzo del prodotto piu' economico
    double fullPrice;      // Prezzo del prodotto piu' caro
    
    if (price1 < price2) {
        // Il primo prodotto e' quello meno caro
        cheaperPrice = price1;
        fullPrice = price2;
    } else {
        // Il secondo prodotto e' quello meno caro (o sono uguali)
        cheaperPrice = price2;
        fullPrice = price1;
    }
    
    // STEP 2: Calcola lo sconto sul prodotto meno caro
    // Sconto = 30% del prezzo
    double discountAmount = cheaperPrice * 0.30;
    
    // STEP 3: Prezzo scontato del prodotto meno caro
    double discountedPrice = cheaperPrice - discountAmount;
    
    // STEP 4: Calcola il totale
    // Totale = prezzo pieno + prezzo scontato
    double total = fullPrice + discountedPrice;
    
    // Restituisci il totale
    return total;
}

// ============================================
// SEZIONE 2: PROGRAMMA PRINCIPALE
// ============================================

int main() {
    
    // -----------------------------------------
    // STEP 1: Dichiarazione variabili
    // -----------------------------------------
    double productPrice1;  // Prezzo del primo prodotto
    double productPrice2;  // Prezzo del secondo prodotto
    double totalToPay;     // Totale da pagare
    
    // -----------------------------------------
    // STEP 2: Input - Acquisizione prezzi
    // -----------------------------------------
    cout << "=== CALCOLO SCONTO 30% SUL PRODOTTO MENO CARO ===" << endl;
    cout << endl;
    
    cout << "Inserisci il prezzo del primo prodotto (euro): ";
    cin >> productPrice1;
    
    cout << "Inserisci il prezzo del secondo prodotto (euro): ";
    cin >> productPrice2;
    
    // -----------------------------------------
    // STEP 3: Elaborazione - Chiamata funzione
    // -----------------------------------------
    totalToPay = calculateTotal(productPrice1, productPrice2);
    
    // -----------------------------------------
    // STEP 4: Output - Mostra risultato
    // -----------------------------------------
    cout << endl;
    cout << "--- RIEPILOGO ---" << endl;
    cout << "Prezzo prodotto 1: " << productPrice1 << " euro" << endl;
    cout << "Prezzo prodotto 2: " << productPrice2 << " euro" << endl;
    cout << "Sconto 30% applicato al prodotto meno caro" << endl;
    cout << endl;
    cout << "TOTALE DA PAGARE: " << totalToPay << " euro" << endl;
    
    return 0;
}
