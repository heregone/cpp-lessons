/*
 * ESERCIZIO 20 - Edicola - Guadagno quotidiani
 * 
 * Un edicolante registra all'interno di un programma il numero
 * di copie dei tre principali quotidiani venduti ogni giorno.
 * 
 * Realizza una funzione che visualizzi il guadagno complessivo
 * per uno specifico quotidiano.
 * 
 * Nota: L'esercizio non specifica i prezzi, quindi usiamo
 * prezzi di esempio che lo studente puo' modificare.
 * 
 * Cosa impariamo:
 * - Funzioni con parametri
 * - Switch-case per scegliere tra opzioni
 * - Moltiplicazione per calcolare guadagni
 */

#include <iostream>
using namespace std;

// ============================================
// SEZIONE 1: COSTANTI
// ============================================

// Prezzi dei quotidiani (in euro)
// Lo studente puo' modificare questi valori
const double PRICE_NEWSPAPER_1 = 1.50;  // Quotidiano 1
const double PRICE_NEWSPAPER_2 = 1.80;  // Quotidiano 2
const double PRICE_NEWSPAPER_3 = 1.20;  // Quotidiano 3

// Guadagno dell'edicolante (percentuale sul prezzo)
// Di solito l'edicolante guadagna circa il 20% sul prezzo di copertina
const double PROFIT_PERCENTAGE = 0.20;  // 20%

// ============================================
// SEZIONE 2: FUNZIONE PER CALCOLARE IL GUADAGNO
// ============================================

/*
 * Funzione: calculateDailyProfit
 * 
 * Calcola il guadagno giornaliero per un quotidiano specifico.
 * 
 * Parametri:
 *   - newspaperNumber: quale quotidiano (1, 2 o 3)
 *   - copiesSold:      numero di copie vendute
 * 
 * Restituisce: il guadagno in euro
 */
double calculateDailyProfit(int newspaperNumber, int copiesSold) {
    
    // STEP 1: Determina il prezzo del quotidiano
    double price;
    
    switch (newspaperNumber) {
        case 1:
            price = PRICE_NEWSPAPER_1;
            break;
        case 2:
            price = PRICE_NEWSPAPER_2;
            break;
        case 3:
            price = PRICE_NEWSPAPER_3;
            break;
        default:
            // Quotidiano non valido, restituisce 0
            price = 0;
            break;
    }
    
    // STEP 2: Calcola l'incasso totale
    double totalRevenue = price * copiesSold;
    
    // STEP 3: Calcola il guadagno (percentuale dell'incasso)
    double profit = totalRevenue * PROFIT_PERCENTAGE;
    
    return profit;
}

/*
 * Funzione: showNewspaperProfit
 * 
 * Visualizza il guadagno per un quotidiano specifico.
 * Questa funzione stampa direttamente i risultati.
 * 
 * Parametri:
 *   - newspaperNumber: quale quotidiano (1, 2 o 3)
 *   - copiesSold:      numero di copie vendute
 */
void showNewspaperProfit(int newspaperNumber, int copiesSold) {
    
    // Calcola il guadagno usando l'altra funzione
    double profit = calculateDailyProfit(newspaperNumber, copiesSold);
    
    // Mostra il risultato
    cout << "Quotidiano " << newspaperNumber << ":" << endl;
    cout << "  Copie vendute: " << copiesSold << endl;
    cout << "  Guadagno: " << profit << " euro" << endl;
}

// ============================================
// SEZIONE 3: PROGRAMMA PRINCIPALE
// ============================================

int main() {
    
    // -----------------------------------------
    // STEP 1: Dichiarazione variabili
    // -----------------------------------------
    int selectedNewspaper;  // Quotidiano scelto (1, 2 o 3)
    int soldCopies;         // Copie vendute
    double dailyProfit;     // Guadagno calcolato
    
    // -----------------------------------------
    // STEP 2: Input - Acquisizione dati
    // -----------------------------------------
    cout << "=== EDICOLA - CALCOLO GUADAGNO QUOTIDIANI ===" << endl;
    cout << endl;
    
    cout << "Quotidiani disponibili:" << endl;
    cout << "  1 - Quotidiano 1 (prezzo: " << PRICE_NEWSPAPER_1 << " euro)" << endl;
    cout << "  2 - Quotidiano 2 (prezzo: " << PRICE_NEWSPAPER_2 << " euro)" << endl;
    cout << "  3 - Quotidiano 3 (prezzo: " << PRICE_NEWSPAPER_3 << " euro)" << endl;
    cout << endl;
    
    cout << "Quale quotidiano vuoi analizzare? (1, 2 o 3): ";
    cin >> selectedNewspaper;
    
    cout << "Quante copie sono state vendute oggi? ";
    cin >> soldCopies;
    
    // -----------------------------------------
    // STEP 3: Elaborazione e Output
    // -----------------------------------------
    cout << endl;
    cout << "--- RISULTATO ---" << endl;
    
    // Usa la funzione che mostra il risultato
    showNewspaperProfit(selectedNewspaper, soldCopies);
    
    // Calcola anche il guadagno da mostrare in modo diverso
    dailyProfit = calculateDailyProfit(selectedNewspaper, soldCopies);
    
    cout << endl;
    cout << "Il guadagno dell'edicolante e' di " << dailyProfit << " euro" << endl;
    cout << "(Margine di guadagno: " << (PROFIT_PERCENTAGE * 100) << "%)" << endl;
    
    return 0;
}
