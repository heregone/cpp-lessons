/*
 * ESERCIZIO 21 - Negozio online - Ordine con sconto e spedizione
 * 
 * Un negozio di abbigliamento online effettua:
 *   - Sconto del 20% per importi superiori a 500 euro
 *   - Spedizione gratuita per importi superiori a 200 euro
 *   - Altrimenti spese di spedizione di 4 euro
 * 
 * Realizza una funzione in grado di ritornare il valore complessivo
 * che un utente deve pagare per il suo ordine.
 * 
 * Cosa impariamo:
 * - Condizioni multiple (if-else)
 * - Calcolo percentuali (sconto)
 * - Logica delle soglie
 */

#include <iostream>
using namespace std;

// ============================================
// SEZIONE 1: COSTANTI
// ============================================

// Soglie per le condizioni
const double DISCOUNT_THRESHOLD = 500.0;  // Soglia per lo sconto
const double FREE_SHIPPING_THRESHOLD = 200.0;  // Soglia spedizione gratis

// Valori delle condizioni
const double DISCOUNT_PERCENTAGE = 0.20;  // 20% di sconto
const double SHIPPING_COST = 4.0;         // Costo spedizione

// ============================================
// SEZIONE 2: FUNZIONE PER CALCOLARE IL TOTALE
// ============================================

/*
 * Funzione: calculateOrderTotal
 * 
 * Calcola il totale da pagare per un ordine online.
 * 
 * Regole:
 *   - Se importo > 500 euro -> sconto 20%
 *   - Se importo > 200 euro -> spedizione gratis
 *   - Altrimenti -> spedizione 4 euro
 * 
 * Attenzione: lo sconto si applica PRIMA di valutare la spedizione!
 * 
 * Parametro:
 *   - orderAmount: importo dell'ordine prima dello sconto
 * 
 * Restituisce: totale da pagare
 */
double calculateOrderTotal(double orderAmount) {
    
    double finalAmount;     // Importo dopo eventuale sconto
    double shippingFee;     // Costo spedizione
    double totalToPay;      // Totale finale
    
    // STEP 1: Verifica se si applica lo sconto
    if (orderAmount > DISCOUNT_THRESHOLD) {
        // Applica lo sconto del 20%
        double discountValue = orderAmount * DISCOUNT_PERCENTAGE;
        finalAmount = orderAmount - discountValue;
        
        cout << "  -> Sconto 20% applicato: -" << discountValue << " euro" << endl;
    } else {
        // Nessuno sconto
        finalAmount = orderAmount;
        cout << "  -> Nessuno sconto (ordine sotto i " << DISCOUNT_THRESHOLD << " euro)" << endl;
    }
    
    // STEP 2: Verifica spedizione gratuita
    // Nota: si valuta l'importo ORIGINALE, non quello scontato
    // (interpretazione comune, ma puo' variare)
    if (orderAmount > FREE_SHIPPING_THRESHOLD) {
        // Spedizione gratuita
        shippingFee = 0;
        cout << "  -> Spedizione gratuita!" << endl;
    } else {
        // Spedizione a pagamento
        shippingFee = SHIPPING_COST;
        cout << "  -> Spedizione: " << SHIPPING_COST << " euro" << endl;
    }
    
    // STEP 3: Calcola il totale
    totalToPay = finalAmount + shippingFee;
    
    return totalToPay;
}

// ============================================
// SEZIONE 3: PROGRAMMA PRINCIPALE
// ============================================

int main() {
    
    // -----------------------------------------
    // STEP 1: Dichiarazione variabili
    // -----------------------------------------
    double orderValue;   // Valore dell'ordine inserito dall'utente
    double finalTotal;   // Totale calcolato dalla funzione
    
    // -----------------------------------------
    // STEP 2: Input - Acquisizione dati
    // -----------------------------------------
    cout << "=== NEGOZIO ONLINE - CALCOLO ORDINE ===" << endl;
    cout << endl;
    
    cout << "Regole del negozio:" << endl;
    cout << "  - Sconto 20% per ordini sopra " << DISCOUNT_THRESHOLD << " euro" << endl;
    cout << "  - Spedizione gratis sopra " << FREE_SHIPPING_THRESHOLD << " euro" << endl;
    cout << "  - Altrimenti spedizione: " << SHIPPING_COST << " euro" << endl;
    cout << endl;
    
    cout << "Inserisci il valore del tuo ordine (euro): ";
    cin >> orderValue;
    
    // -----------------------------------------
    // STEP 3: Elaborazione - Chiamata funzione
    // -----------------------------------------
    cout << endl;
    cout << "--- CALCOLO IN CORSO ---" << endl;
    finalTotal = calculateOrderTotal(orderValue);
    
    // -----------------------------------------
    // STEP 4: Output - Mostra risultato
    // -----------------------------------------
    cout << endl;
    cout << "--- RIEPILOGO ORDINE ---" << endl;
    cout << "Valore ordine: " << orderValue << " euro" << endl;
    cout << "TOTALE DA PAGARE: " << finalTotal << " euro" << endl;
    
    return 0;
}
