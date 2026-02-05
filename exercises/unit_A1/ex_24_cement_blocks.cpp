/*
 * ESERCIZIO 24 - Magazzino blocchi di cemento
 * 
 * Scrivi un algoritmo e il relativo programma in C++ che preveda
 * il carico e scarico del magazzino di una societa' che produce
 * blocchi di cemento per costruzioni.
 * 
 * L'algoritmo deve essere rappresentato funzionalmente dal seguente menu:
 *   1. Inserisci nuovi blocchi nel magazzino
 *   2. Vendi blocchi
 *   3. Visualizza numero di blocchi presenti
 * 
 * Ogni voce del menu deve essere gestita da un singolo sottoalgoritmo.
 * 
 * VINCOLI:
 *   - Non si puo' vendere piu' blocchi di quelli disponibili
 *   - Capienza massima del magazzino: 2000 pezzi
 * 
 * Cosa impariamo:
 * - Menu interattivo
 * - Funzioni per ogni operazione
 * - Controllo limiti (min e max)
 * - Passaggio parametri per riferimento (&)
 */

#include <iostream>
using namespace std;

// ============================================
// SEZIONE 1: COSTANTI
// ============================================

const int MAX_CAPACITY = 2000;  // Capienza massima magazzino
const int MIN_STOCK = 0;        // Minimo (non si puo' andare sotto zero)

// Opzioni menu
const int MENU_ADD = 1;
const int MENU_SELL = 2;
const int MENU_SHOW = 3;
const int MENU_EXIT = 0;

// ============================================
// SEZIONE 2: FUNZIONE - Mostra menu
// ============================================

void showMenu() {
    cout << endl;
    cout << "--- GESTIONE MAGAZZINO BLOCCHI CEMENTO ---" << endl;
    cout << "1. Inserisci nuovi blocchi nel magazzino" << endl;
    cout << "2. Vendi blocchi" << endl;
    cout << "3. Visualizza numero di blocchi presenti" << endl;
    cout << "0. Esci" << endl;
    cout << "Scelta: ";
}

// ============================================
// SEZIONE 3: FUNZIONE - Inserimento blocchi
// ============================================

/*
 * Funzione: addBlocks
 * 
 * Aggiunge blocchi al magazzino, rispettando la capienza massima.
 * 
 * Parametri:
 *   - currentStock: quantita' attuale (passata per RIFERIMENTO,
 *                   cosi' possiamo modificarla)
 * 
 * Nota: Il simbolo & dopo int significa "passaggio per riferimento".
 * Questo permette alla funzione di modificare la variabile originale.
 */
void addBlocks(int& currentStock) {
    
    int blocksToAdd;
    
    cout << "Quanti blocchi vuoi aggiungere? ";
    cin >> blocksToAdd;
    
    // Controllo: non possiamo aggiungere numeri negativi
    if (blocksToAdd < 0) {
        cout << "ERRORE: Non puoi inserire un numero negativo!" << endl;
        return;  // Esce dalla funzione senza fare nulla
    }
    
    // Calcola il nuovo totale
    int newTotal = currentStock + blocksToAdd;
    
    // Controllo: non superare la capienza massima
    if (newTotal > MAX_CAPACITY) {
        cout << "ERRORE: La capienza massima e' " << MAX_CAPACITY << " blocchi!" << endl;
        cout << "Blocchi attuali: " << currentStock << endl;
        cout << "Spazio disponibile: " << (MAX_CAPACITY - currentStock) << " blocchi" << endl;
        return;  // Esce dalla funzione senza fare nulla
    }
    
    // Tutto ok, aggiorna lo stock
    currentStock = newTotal;
    cout << "Blocchi aggiunti con successo!" << endl;
    cout << "Nuova quantita' in magazzino: " << currentStock << " blocchi" << endl;
}

// ============================================
// SEZIONE 4: FUNZIONE - Vendita blocchi
// ============================================

/*
 * Funzione: sellBlocks
 * 
 * Vende blocchi dal magazzino, controllando la disponibilita'.
 * 
 * Parametri:
 *   - currentStock: quantita' attuale (passata per riferimento)
 */
void sellBlocks(int& currentStock) {
    
    int blocksToSell;
    
    cout << "Quanti blocchi vuoi vendere? ";
    cin >> blocksToSell;
    
    // Controllo: non possiamo vendere numeri negativi
    if (blocksToSell < 0) {
        cout << "ERRORE: Non puoi vendere un numero negativo!" << endl;
        return;
    }
    
    // Controllo: non possiamo vendere piu' di quanto abbiamo
    if (blocksToSell > currentStock) {
        cout << "ERRORE: Non hai abbastanza blocchi in magazzino!" << endl;
        cout << "Blocchi disponibili: " << currentStock << endl;
        cout << "Blocchi richiesti: " << blocksToSell << endl;
        return;
    }
    
    // Tutto ok, aggiorna lo stock
    currentStock = currentStock - blocksToSell;
    cout << "Vendita effettuata con successo!" << endl;
    cout << "Blocchi rimanenti in magazzino: " << currentStock << " blocchi" << endl;
}

// ============================================
// SEZIONE 5: FUNZIONE - Visualizza stock
// ============================================

/*
 * Funzione: showStock
 * 
 * Visualizza la situazione attuale del magazzino.
 * 
 * Parametri:
 *   - currentStock: quantita' attuale (solo lettura, non modifica)
 */
void showStock(int currentStock) {
    
    cout << endl;
    cout << "=== SITUAZIONE MAGAZZINO ===" << endl;
    cout << "Blocchi presenti: " << currentStock << endl;
    cout << "Spazio disponibile: " << (MAX_CAPACITY - currentStock) << endl;
    cout << "Capienza massima: " << MAX_CAPACITY << endl;
    
    // Percentuale di riempimento
    double percentageFull = (double(currentStock) / MAX_CAPACITY) * 100;
    cout << "Riempimento: " << percentageFull << "%" << endl;
    cout << "==============================" << endl;
}

// ============================================
// SEZIONE 6: PROGRAMMA PRINCIPALE
// ============================================

int main() {
    
    // -----------------------------------------
    // STEP 1: Inizializzazione
    // -----------------------------------------
    
    // Stock iniziale del magazzino
    int stock = 0;
    
    // Variabile per la scelta dell'utente
    int choice;
    
    // -----------------------------------------
    // STEP 2: Messaggio di benvenuto
    // -----------------------------------------
    cout << "=== SISTEMA GESTIONE MAGAZZINO BLOCCHI CEMENTO ===" << endl;
    cout << "Capienza massima: " << MAX_CAPACITY << " blocchi" << endl;
    cout << "Stock iniziale: " << stock << " blocchi" << endl;
    
    // -----------------------------------------
    // STEP 3: Ciclo principale
    // -----------------------------------------
    
    do {
        // Mostra il menu
        showMenu();
        cin >> choice;
        
        // Gestisci la scelta
        switch (choice) {
            
            case MENU_ADD:
                // Inserisci nuovi blocchi
                addBlocks(stock);  // Passa stock per riferimento
                break;
                
            case MENU_SELL:
                // Vendi blocchi
                sellBlocks(stock);  // Passa stock per riferimento
                break;
                
            case MENU_SHOW:
                // Visualizza situazione
                showStock(stock);
                break;
                
            case MENU_EXIT:
                cout << endl;
                cout << "Arrivederci!" << endl;
                showStock(stock);  // Mostra situazione finale
                break;
                
            default:
                cout << "Scelta non valida. Riprova." << endl;
                break;
        }
        
    } while (choice != MENU_EXIT);
    
    return 0;
}
