/*
 * ESERCIZIO 19 - Biglietto traghetto
 * 
 * Crea una funzione che restituisce il prezzo del biglietto 
 * di un traghetto in base alle seguenti tariffe:
 * 
 * PERSONE:
 *   - Adulto:  10 euro
 *   - Bambino:  5 euro
 *   - Anziano:  7 euro
 * 
 * MEZZI:
 *   - Automobile: 50 euro
 *   - Motociclo:  30 euro
 *   - Furgone:    70 euro
 *   - Camion:    100 euro
 * 
 * La funzione deve restituire il costo complessivo.
 * Esempio: 2 adulti + 1 motociclo = 50 euro
 * 
 * Cosa impariamo:
 * - Funzioni con molti parametri
 * - Calcoli semplici
 * - Costanti per i prezzi
 */

#include <iostream>
using namespace std;

// ============================================
// SEZIONE 1: COSTANTI DEI PREZZI
// ============================================

// Prezzi delle persone
const int PRICE_ADULT = 10;
const int PRICE_CHILD = 5;
const int PRICE_ELDERLY = 7;

// Prezzi dei mezzi
const int PRICE_CAR = 50;
const int PRICE_MOTORCYCLE = 30;
const int PRICE_VAN = 70;
const int PRICE_TRUCK = 100;

// ============================================
// SEZIONE 2: FUNZIONE PER CALCOLARE IL COSTO
// ============================================

/*
 * Funzione: calculateFerryTicket
 * 
 * Calcola il costo totale del biglietto del traghetto.
 * 
 * Parametri:
 *   - adults:      numero di adulti
 *   - children:    numero di bambini
 *   - elderly:     numero di anziani
 *   - cars:        numero di automobili
 *   - motorcycles: numero di motocicli
 *   - vans:        numero di furgoni
 *   - trucks:      numero di camion
 * 
 * Restituisce: il costo totale in euro
 */
int calculateFerryTicket(int adults, int children, int elderly,
                         int cars, int motorcycles, int vans, int trucks) {
    
    // STEP 1: Calcola il costo delle persone
    int peopleCost = 0;
    peopleCost = peopleCost + (adults * PRICE_ADULT);
    peopleCost = peopleCost + (children * PRICE_CHILD);
    peopleCost = peopleCost + (elderly * PRICE_ELDERLY);
    
    // STEP 2: Calcola il costo dei mezzi
    int vehicleCost = 0;
    vehicleCost = vehicleCost + (cars * PRICE_CAR);
    vehicleCost = vehicleCost + (motorcycles * PRICE_MOTORCYCLE);
    vehicleCost = vehicleCost + (vans * PRICE_VAN);
    vehicleCost = vehicleCost + (trucks * PRICE_TRUCK);
    
    // STEP 3: Calcola il totale
    int totalCost = peopleCost + vehicleCost;
    
    return totalCost;
}

// ============================================
// SEZIONE 3: PROGRAMMA PRINCIPALE
// ============================================

int main() {
    
    // -----------------------------------------
    // STEP 1: Dichiarazione variabili
    // -----------------------------------------
    
    // Variabili per le persone
    int numAdults;
    int numChildren;
    int numElderly;
    
    // Variabili per i mezzi
    int numCars;
    int numMotorcycles;
    int numVans;
    int numTrucks;
    
    // Variabile per il risultato
    int totalTicketPrice;
    
    // -----------------------------------------
    // STEP 2: Input - Acquisizione dati
    // -----------------------------------------
    cout << "=== CALCOLO BIGLIETTO TRAGHETTO ===" << endl;
    cout << endl;
    
    cout << "--- PERSONE ---" << endl;
    cout << "Numero adulti (10 euro cad.): ";
    cin >> numAdults;
    
    cout << "Numero bambini (5 euro cad.): ";
    cin >> numChildren;
    
    cout << "Numero anziani (7 euro cad.): ";
    cin >> numElderly;
    
    cout << endl;
    cout << "--- MEZZI ---" << endl;
    cout << "Numero automobili (50 euro cad.): ";
    cin >> numCars;
    
    cout << "Numero motocicli (30 euro cad.): ";
    cin >> numMotorcycles;
    
    cout << "Numero furgoni (70 euro cad.): ";
    cin >> numVans;
    
    cout << "Numero camion (100 euro cad.): ";
    cin >> numTrucks;
    
    // -----------------------------------------
    // STEP 3: Elaborazione - Chiamata funzione
    // -----------------------------------------
    totalTicketPrice = calculateFerryTicket(numAdults, numChildren, numElderly,
                                            numCars, numMotorcycles, numVans, numTrucks);
    
    // -----------------------------------------
    // STEP 4: Output - Mostra risultato
    // -----------------------------------------
    cout << endl;
    cout << "--- RIEPILOGO ---" << endl;
    cout << "Persone: " << numAdults << " adulti, " 
         << numChildren << " bambini, " 
         << numElderly << " anziani" << endl;
    cout << "Mezzi: " << numCars << " auto, " 
         << numMotorcycles << " moto, "
         << numVans << " furgoni, "
         << numTrucks << " camion" << endl;
    cout << endl;
    cout << "TOTALE BIGLIETTO: " << totalTicketPrice << " euro" << endl;
    
    return 0;
}
