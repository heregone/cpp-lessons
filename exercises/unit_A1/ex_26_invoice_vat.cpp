/*
 * ESERCIZIO 26 - Fattura con IVA (Scontrino)
 * 
 * Un'azienda fornisce dei prodotti, alcuni dei quali sono esenti da IVA.
 * 
 * Scrivi un algoritmo e il relativo programma in C++ che riporti
 * l'incasso della societa' a fine mese e che visualizzi la fattura finale.
 * 
 * Il prezzo di uno o piu' prodotti dello stesso tipo deve essere
 * restituito da una funzione che accetta come parametri:
 *   - Costo del singolo prodotto
 *   - IVA da applicare (0 se esente)
 *   - Numero di esemplari del prodotto acquistato
 * 
 * L'algoritmo acquisisce le informazioni necessarie e le passa alla
 * funzione, che determina la singola voce dello scontrino.
 * 
 * In caso di articoli differenti, la funzione deve essere eseguita
 * piu' volte.
 * 
 * NOTA: Acquisire in fase iniziale il numero di articoli presenti
 * nello scontrino.
 * 
 * Cosa impariamo:
 * - Funzione per calcolo singola voce
 * - Ciclo per elaborare piu' articoli
 * - IVA e calcoli fiscali base
 * - Formattazione output (scontrino)
 */

#include <iostream>
using namespace std;

// ============================================
// SEZIONE 1: FUNZIONE - Calcola voce scontrino
// ============================================

/*
 * Funzione: calculateLineTotal
 * 
 * Calcola il totale di una singola voce dello scontrino,
 * applicando l'IVA se necessario.
 * 
 * Parametri:
 *   - unitPrice:  prezzo unitario del prodotto
 *   - vatRate:    aliquota IVA (es: 22 per 22%, oppure 0 se esente)
 *   - quantity:   numero di pezzi acquistati
 * 
 * Restituisce: il totale della voce (con IVA inclusa)
 */
double calculateLineTotal(double unitPrice, double vatRate, int quantity) {
    
    // STEP 1: Calcola il subtotale senza IVA
    double subtotal = unitPrice * quantity;
    
    // STEP 2: Calcola l'importo IVA
    // L'aliquota IVA arriva come numero intero (es: 22),
    // quindi dividiamo per 100 per ottenere la percentuale
    double vatAmount = subtotal * (vatRate / 100);
    
    // STEP 3: Calcola il totale con IVA
    double totalWithVat = subtotal + vatAmount;
    
    return totalWithVat;
}

/*
 * Funzione: printLineDetails
 * 
 * Stampa i dettagli di una voce dello scontrino.
 * Questa funzione e' di supporto per la visualizzazione.
 * 
 * Parametri:
 *   - lineNumber: numero progressivo della voce
 *   - unitPrice:  prezzo unitario
 *   - vatRate:    aliquota IVA
 *   - quantity:   quantita'
 *   - lineTotal:  totale della voce
 */
void printLineDetails(int lineNumber, double unitPrice, double vatRate, 
                      int quantity, double lineTotal) {
    
    cout << "  " << lineNumber << ") ";
    cout << quantity << " x " << unitPrice << " euro";
    
    if (vatRate > 0) {
        cout << " (IVA " << vatRate << "%)";
    } else {
        cout << " (esente IVA)";
    }
    
    cout << " = " << lineTotal << " euro" << endl;
}

// ============================================
// SEZIONE 2: PROGRAMMA PRINCIPALE
// ============================================

int main() {
    
    // -----------------------------------------
    // STEP 1: Dichiarazione variabili
    // -----------------------------------------
    
    int numberOfItems;          // Numero di articoli DIVERSI nello scontrino
    
    // Variabili per input di ogni articolo
    double productPrice;        // Prezzo unitario
    double productVat;          // Aliquota IVA (0 se esente)
    int productQuantity;        // Quantita'
    double lineTotal;           // Totale della singola voce
    
    // Variabile per il totale dello scontrino
    double grandTotal = 0;
    
    // -----------------------------------------
    // STEP 2: Input numero articoli
    // -----------------------------------------
    cout << "=== FATTURA / SCONTRINO ===" << endl;
    cout << endl;
    
    cout << "Quanti articoli diversi ci sono nello scontrino? ";
    cin >> numberOfItems;
    
    // Controllo input valido
    if (numberOfItems <= 0) {
        cout << "Nessun articolo da registrare." << endl;
        return 0;  // Esce dal programma
    }
    
    // -----------------------------------------
    // STEP 3: Intestazione scontrino
    // -----------------------------------------
    cout << endl;
    cout << "======================================" << endl;
    cout << "           SCONTRINO FISCALE         " << endl;
    cout << "======================================" << endl;
    cout << endl;
    
    // -----------------------------------------
    // STEP 4: Ciclo per ogni articolo
    // -----------------------------------------
    
    for (int i = 1; i <= numberOfItems; i++) {
        
        cout << "--- Articolo " << i << " di " << numberOfItems << " ---" << endl;
        
        // Input dati articolo
        cout << "Prezzo unitario (euro): ";
        cin >> productPrice;
        
        cout << "Aliquota IVA (es: 22, 10, 4 oppure 0 se esente): ";
        cin >> productVat;
        
        cout << "Quantita': ";
        cin >> productQuantity;
        
        // Calcola il totale usando la funzione
        lineTotal = calculateLineTotal(productPrice, productVat, productQuantity);
        
        // Mostra i dettagli della voce
        printLineDetails(i, productPrice, productVat, productQuantity, lineTotal);
        
        // Aggiungi al totale generale
        grandTotal = grandTotal + lineTotal;
        
        cout << endl;
    }
    
    // -----------------------------------------
    // STEP 5: Output finale
    // -----------------------------------------
    cout << "======================================" << endl;
    cout << "TOTALE SCONTRINO: " << grandTotal << " euro" << endl;
    cout << "======================================" << endl;
    cout << endl;
    cout << "        GRAZIE E ARRIVEDERCI         " << endl;
    cout << "======================================" << endl;
    
    return 0;
}
