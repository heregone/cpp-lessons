/*
 * ESERCIZIO 25 - Blocchi cemento: peso e trasporto
 * 
 * Aggiungi al precedente esercizio (esercizio 24) una funzione
 * (punto 4 del menu) che restituisca il peso complessivo di una
 * vendita di blocchi per determinare se il mezzo di trasporto
 * e' in grado di trasportarli.
 * 
 * Peso del singolo blocco: 4,5 kg
 * 
 * Cosa impariamo:
 * - Calcolo peso totale
 * - Confronto con capacita' di carico
 * - Estensione di un programma esistente
 */

#include <iostream>
using namespace std;

// ============================================
// SEZIONE 1: COSTANTI
// ============================================

const int MAX_CAPACITY = 2000;      // Capienza massima magazzino
const double BLOCK_WEIGHT = 4.5;    // Peso di un singolo blocco (kg)

// Opzioni menu
const int MENU_ADD = 1;
const int MENU_SELL = 2;
const int MENU_SHOW = 3;
const int MENU_CHECK_TRANSPORT = 4;  // NUOVA OPZIONE
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
    cout << "4. Verifica peso per trasporto" << endl;  // NUOVA VOCE
    cout << "0. Esci" << endl;
    cout << "Scelta: ";
}

// ============================================
// SEZIONE 3: FUNZIONE - Inserimento blocchi
// ============================================

void addBlocks(int& currentStock) {
    
    int blocksToAdd;
    
    cout << "Quanti blocchi vuoi aggiungere? ";
    cin >> blocksToAdd;
    
    if (blocksToAdd < 0) {
        cout << "ERRORE: Non puoi inserire un numero negativo!" << endl;
        return;
    }
    
    int newTotal = currentStock + blocksToAdd;
    
    if (newTotal > MAX_CAPACITY) {
        cout << "ERRORE: La capienza massima e' " << MAX_CAPACITY << " blocchi!" << endl;
        cout << "Spazio disponibile: " << (MAX_CAPACITY - currentStock) << " blocchi" << endl;
        return;
    }
    
    currentStock = newTotal;
    cout << "Blocchi aggiunti! Nuova quantita': " << currentStock << endl;
}

// ============================================
// SEZIONE 4: FUNZIONE - Vendita blocchi
// ============================================

void sellBlocks(int& currentStock) {
    
    int blocksToSell;
    
    cout << "Quanti blocchi vuoi vendere? ";
    cin >> blocksToSell;
    
    if (blocksToSell < 0) {
        cout << "ERRORE: Non puoi vendere un numero negativo!" << endl;
        return;
    }
    
    if (blocksToSell > currentStock) {
        cout << "ERRORE: Non hai abbastanza blocchi!" << endl;
        cout << "Blocchi disponibili: " << currentStock << endl;
        return;
    }
    
    currentStock = currentStock - blocksToSell;
    cout << "Vendita effettuata! Blocchi rimanenti: " << currentStock << endl;
}

// ============================================
// SEZIONE 5: FUNZIONE - Visualizza stock
// ============================================

void showStock(int currentStock) {
    cout << endl;
    cout << "=== SITUAZIONE MAGAZZINO ===" << endl;
    cout << "Blocchi presenti: " << currentStock << endl;
    cout << "Peso totale in magazzino: " << (currentStock * BLOCK_WEIGHT) << " kg" << endl;
    cout << "Spazio disponibile: " << (MAX_CAPACITY - currentStock) << " blocchi" << endl;
    cout << "==============================" << endl;
}

// ============================================
// SEZIONE 6: FUNZIONE - Calcola peso vendita
// ============================================

/*
 * Funzione: calculateWeight
 * 
 * Calcola il peso totale di un certo numero di blocchi.
 * 
 * Parametri:
 *   - numberOfBlocks: quanti blocchi
 * 
 * Restituisce: peso totale in kg
 */
double calculateWeight(int numberOfBlocks) {
    double totalWeight = numberOfBlocks * BLOCK_WEIGHT;
    return totalWeight;
}

/*
 * Funzione: checkTransport
 * 
 * Verifica se un mezzo di trasporto puo' portare un certo
 * numero di blocchi, confrontando il peso con la portata.
 * 
 * Parametri:
 *   - currentStock: blocchi disponibili in magazzino
 */
void checkTransport(int currentStock) {
    
    int blocksForDelivery;
    double vehicleCapacity;
    
    // STEP 1: Chiedi quanti blocchi devono essere trasportati
    cout << endl;
    cout << "--- VERIFICA TRASPORTO ---" << endl;
    cout << "Blocchi disponibili in magazzino: " << currentStock << endl;
    cout << endl;
    
    cout << "Quanti blocchi devono essere trasportati? ";
    cin >> blocksForDelivery;
    
    // Controllo: non piu' di quelli disponibili
    if (blocksForDelivery > currentStock) {
        cout << "ERRORE: Non ci sono abbastanza blocchi in magazzino!" << endl;
        return;
    }
    
    if (blocksForDelivery <= 0) {
        cout << "ERRORE: Inserisci un numero valido di blocchi!" << endl;
        return;
    }
    
    // STEP 2: Calcola il peso totale
    double totalWeight = calculateWeight(blocksForDelivery);
    
    cout << endl;
    cout << "Peso singolo blocco: " << BLOCK_WEIGHT << " kg" << endl;
    cout << "Numero blocchi: " << blocksForDelivery << endl;
    cout << "PESO TOTALE: " << totalWeight << " kg" << endl;
    cout << endl;
    
    // STEP 3: Chiedi la portata del mezzo
    cout << "Qual e' la portata massima del mezzo di trasporto (kg)? ";
    cin >> vehicleCapacity;
    
    // STEP 4: Confronta e mostra risultato
    cout << endl;
    if (totalWeight <= vehicleCapacity) {
        // Il mezzo puo' trasportare i blocchi
        cout << "OK! Il mezzo puo' trasportare i blocchi." << endl;
        cout << "Peso da trasportare: " << totalWeight << " kg" << endl;
        cout << "Portata mezzo: " << vehicleCapacity << " kg" << endl;
        cout << "Margine disponibile: " << (vehicleCapacity - totalWeight) << " kg" << endl;
    } else {
        // Il mezzo NON puo' trasportare i blocchi
        cout << "ATTENZIONE! Il mezzo NON puo' trasportare i blocchi." << endl;
        cout << "Peso da trasportare: " << totalWeight << " kg" << endl;
        cout << "Portata mezzo: " << vehicleCapacity << " kg" << endl;
        cout << "Eccesso di peso: " << (totalWeight - vehicleCapacity) << " kg" << endl;
        
        // Suggerimento: quanti blocchi puo' portare al massimo
        int maxBlocks = int(vehicleCapacity / BLOCK_WEIGHT);
        cout << endl;
        cout << "Suggerimento: il mezzo puo' trasportare al massimo " 
             << maxBlocks << " blocchi." << endl;
    }
}

// ============================================
// SEZIONE 7: PROGRAMMA PRINCIPALE
// ============================================

int main() {
    
    int stock = 0;
    int choice;
    
    cout << "=== SISTEMA GESTIONE MAGAZZINO BLOCCHI CEMENTO ===" << endl;
    cout << "Peso singolo blocco: " << BLOCK_WEIGHT << " kg" << endl;
    cout << "Capienza massima: " << MAX_CAPACITY << " blocchi" << endl;
    
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            
            case MENU_ADD:
                addBlocks(stock);
                break;
                
            case MENU_SELL:
                sellBlocks(stock);
                break;
                
            case MENU_SHOW:
                showStock(stock);
                break;
                
            case MENU_CHECK_TRANSPORT:
                checkTransport(stock);
                break;
                
            case MENU_EXIT:
                cout << "Arrivederci!" << endl;
                break;
                
            default:
                cout << "Scelta non valida." << endl;
                break;
        }
        
    } while (choice != MENU_EXIT);
    
    return 0;
}
