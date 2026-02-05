/*
 * ESERCIZIO 22 - Assicurazione auto
 * 
 * In un mese una societa' di assicurazioni ha stipulato N contratti
 * assicurativi su autovetture in base ai seguenti criteri:
 * 
 *   - Se l'auto ha cilindrata maggiore di 2000 cc:
 *     Costo = Quota fissa Q + 2% del prezzo della vettura
 * 
 *   - Altrimenti:
 *     Costo = Quota fissa Q + 1% del prezzo della vettura
 * 
 * Scrivi un algoritmo e il relativo programma in C++.
 * 
 * Cosa impariamo:
 * - Ciclo for per ripetere operazioni
 * - Condizioni if-else
 * - Calcolo percentuali
 * - Accumulatori (somma totale)
 */

#include <iostream>
using namespace std;

// ============================================
// SEZIONE 1: COSTANTI
// ============================================

// Soglia di cilindrata per il calcolo
const int ENGINE_THRESHOLD = 2000;  // 2000 cc

// Percentuali da applicare
const double PERCENTAGE_HIGH = 0.02;  // 2% per cilindrata > 2000
const double PERCENTAGE_LOW = 0.01;   // 1% per cilindrata <= 2000

// ============================================
// SEZIONE 2: FUNZIONE PER CALCOLARE COSTO SINGOLO CONTRATTO
// ============================================

/*
 * Funzione: calculateInsuranceCost
 * 
 * Calcola il costo dell'assicurazione per una singola auto.
 * 
 * Parametri:
 *   - fixedQuota:    la quota fissa Q
 *   - engineCC:      cilindrata in cc
 *   - carPrice:      prezzo della vettura
 * 
 * Restituisce: il costo del contratto
 */
double calculateInsuranceCost(double fixedQuota, int engineCC, double carPrice) {
    
    double percentageAmount;  // Importo percentuale da aggiungere
    double totalCost;         // Costo totale contratto
    
    // STEP 1: Verifica la cilindrata
    if (engineCC > ENGINE_THRESHOLD) {
        // Cilindrata alta: applica 2%
        percentageAmount = carPrice * PERCENTAGE_HIGH;
    } else {
        // Cilindrata normale: applica 1%
        percentageAmount = carPrice * PERCENTAGE_LOW;
    }
    
    // STEP 2: Calcola il costo totale
    totalCost = fixedQuota + percentageAmount;
    
    return totalCost;
}

// ============================================
// SEZIONE 3: PROGRAMMA PRINCIPALE
// ============================================

int main() {
    
    // -----------------------------------------
    // STEP 1: Dichiarazione variabili
    // -----------------------------------------
    int numberOfContracts;      // Numero di contratti N
    double fixedQuota;          // Quota fissa Q (uguale per tutti)
    
    // Variabili per ogni contratto
    int engineDisplacement;     // Cilindrata in cc
    double vehiclePrice;        // Prezzo vettura
    double contractCost;        // Costo singolo contratto
    
    // Variabile per il totale
    double totalRevenue = 0;    // Incasso totale della societa'
    
    // -----------------------------------------
    // STEP 2: Input - Dati generali
    // -----------------------------------------
    cout << "=== SOCIETA' ASSICURAZIONI - CALCOLO CONTRATTI ===" << endl;
    cout << endl;
    
    cout << "Regole di calcolo:" << endl;
    cout << "  - Cilindrata > 2000 cc: Quota + 2% prezzo auto" << endl;
    cout << "  - Cilindrata <= 2000 cc: Quota + 1% prezzo auto" << endl;
    cout << endl;
    
    cout << "Inserisci la quota fissa Q (euro): ";
    cin >> fixedQuota;
    
    cout << "Quanti contratti sono stati stipulati? ";
    cin >> numberOfContracts;
    
    // -----------------------------------------
    // STEP 3: Ciclo per ogni contratto
    // -----------------------------------------
    cout << endl;
    cout << "--- INSERIMENTO DATI CONTRATTI ---" << endl;
    
    // Usiamo un ciclo for per elaborare ogni contratto
    for (int i = 1; i <= numberOfContracts; i++) {
        
        cout << endl;
        cout << "Contratto " << i << " di " << numberOfContracts << ":" << endl;
        
        // Input dati del contratto
        cout << "  Cilindrata dell'auto (in cc): ";
        cin >> engineDisplacement;
        
        cout << "  Prezzo della vettura (euro): ";
        cin >> vehiclePrice;
        
        // Calcola il costo del contratto
        contractCost = calculateInsuranceCost(fixedQuota, engineDisplacement, vehiclePrice);
        
        // Mostra il costo di questo contratto
        cout << "  -> Costo contratto: " << contractCost << " euro" << endl;
        
        // Aggiungi al totale (accumulatore)
        totalRevenue = totalRevenue + contractCost;
    }
    
    // -----------------------------------------
    // STEP 4: Output - Riepilogo finale
    // -----------------------------------------
    cout << endl;
    cout << "=== RIEPILOGO MENSILE ===" << endl;
    cout << "Numero contratti stipulati: " << numberOfContracts << endl;
    cout << "Quota fissa per contratto: " << fixedQuota << " euro" << endl;
    cout << "INCASSO TOTALE DEL MESE: " << totalRevenue << " euro" << endl;
    
    return 0;
}
