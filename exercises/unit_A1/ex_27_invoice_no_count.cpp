/*
 * ESERCIZIO 27 - Fattura modificata (senza conteggio iniziale)
 * 
 * Modifica del precedente algoritmo (esercizio 26):
 * 
 * NON e' piu' disponibile inizialmente il numero di articoli 
 * presenti nello scontrino.
 * 
 * Deve essere prevista una condizione che stabilisca la fine
 * dell'inserimento degli articoli e quindi la terminazione
 * dell'algoritmo.
 * 
 * SOLUZIONE: L'utente inserisce articoli finche' vuole.
 * Per terminare, inserisce 0 come prezzo oppure sceglie 
 * di non continuare.
 * 
 * Cosa impariamo:
 * - Ciclo while con condizione di uscita
 * - Controllo utente per terminare
 * - Differenza tra ciclo for (numero noto) e while (numero ignoto)
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
 * (Stessa funzione dell'esercizio 26)
 */
double calculateLineTotal(double unitPrice, double vatRate, int quantity) {
    
    double subtotal = unitPrice * quantity;
    double vatAmount = subtotal * (vatRate / 100);
    double totalWithVat = subtotal + vatAmount;
    
    return totalWithVat;
}

/*
 * Funzione: printLineDetails
 * 
 * Stampa i dettagli di una voce dello scontrino.
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
    
    // Variabili per input di ogni articolo
    double productPrice;
    double productVat;
    int productQuantity;
    double lineTotal;
    
    // Contatore articoli (lo incrementiamo noi)
    int itemCount = 0;
    
    // Variabile per il totale dello scontrino
    double grandTotal = 0;
    
    // Variabile per controllare se continuare
    char continueChoice;
    bool keepGoing = true;  // Flag per continuare il ciclo
    
    // -----------------------------------------
    // STEP 2: Intestazione scontrino
    // -----------------------------------------
    cout << "=== FATTURA / SCONTRINO ===" << endl;
    cout << endl;
    cout << "Inserisci gli articoli uno alla volta." << endl;
    cout << "Per terminare: inserisci 0 come prezzo, oppure digita 'n' quando chiesto." << endl;
    cout << endl;
    
    cout << "======================================" << endl;
    cout << "           SCONTRINO FISCALE         " << endl;
    cout << "======================================" << endl;
    cout << endl;
    
    // -----------------------------------------
    // STEP 3: Ciclo WHILE - continua finche' l'utente vuole
    // -----------------------------------------
    
    // Usiamo while invece di for perche' NON sappiamo
    // quanti articoli l'utente inserira'
    
    while (keepGoing) {
        
        // Incrementa il contatore articoli
        itemCount = itemCount + 1;
        
        cout << "--- Articolo " << itemCount << " ---" << endl;
        
        // Input prezzo
        cout << "Prezzo unitario (0 per terminare): ";
        cin >> productPrice;
        
        // CONDIZIONE DI USCITA 1: prezzo = 0
        if (productPrice <= 0) {
            cout << "Inserimento terminato (prezzo zero o negativo)." << endl;
            itemCount = itemCount - 1;  // Non contare questo articolo
            break;  // Esce dal ciclo while
        }
        
        // Input IVA
        cout << "Aliquota IVA (0 se esente): ";
        cin >> productVat;
        
        // Input quantita'
        cout << "Quantita': ";
        cin >> productQuantity;
        
        // Controllo quantita' valida
        if (productQuantity <= 0) {
            cout << "Quantita' non valida, articolo ignorato." << endl;
            itemCount = itemCount - 1;
        } else {
            // Calcola il totale usando la funzione
            lineTotal = calculateLineTotal(productPrice, productVat, productQuantity);
            
            // Mostra i dettagli della voce
            printLineDetails(itemCount, productPrice, productVat, 
                           productQuantity, lineTotal);
            
            // Aggiungi al totale generale
            grandTotal = grandTotal + lineTotal;
        }
        
        cout << endl;
        
        // CONDIZIONE DI USCITA 2: chiedi all'utente se vuole continuare
        cout << "Vuoi aggiungere un altro articolo? (s/n): ";
        cin >> continueChoice;
        
        // Se l'utente scrive 'n' o 'N', termina
        if (continueChoice == 'n' || continueChoice == 'N') {
            keepGoing = false;  // Imposta il flag a false
            cout << "Inserimento terminato." << endl;
        }
        
        cout << endl;
    }
    
    // -----------------------------------------
    // STEP 4: Output finale
    // -----------------------------------------
    
    // Verifica se almeno un articolo e' stato inserito
    if (itemCount == 0) {
        cout << "Nessun articolo registrato." << endl;
    } else {
        cout << "======================================" << endl;
        cout << "Articoli totali: " << itemCount << endl;
        cout << "TOTALE SCONTRINO: " << grandTotal << " euro" << endl;
        cout << "======================================" << endl;
        cout << endl;
        cout << "        GRAZIE E ARRIVEDERCI         " << endl;
        cout << "======================================" << endl;
    }
    
    return 0;
}
