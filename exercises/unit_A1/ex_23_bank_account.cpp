/*
 * ESERCIZIO 23 - Gestione conto corrente
 * 
 * Scrivi un algoritmo e il relativo programma in C++ per la gestione
 * di un conto corrente. Su tale conto possono essere svolti 
 * tre tipi di operazioni:
 *   - Versamento
 *   - Prelevamento  
 *   - Emissione di assegni
 * 
 * Dopo aver introdotto il saldo iniziale, si potranno inserire
 * le varie operazioni digitandone il tipo e la somma.
 * 
 * A richiesta dell'utente, l'algoritmo dovra' fornire:
 *   - Numero dei versamenti effettuati e somma totalmente versata
 *   - Numero dei prelevamenti effettuati e somma totalmente prelevata
 *   - Numero degli assegni emessi e somma prelevata tramite essi
 *   - Saldo finale
 * 
 * Cosa impariamo:
 * - Menu con do-while
 * - Switch-case per gestire scelte
 * - Contatori e accumulatori multipli
 * - Gestione di un programma interattivo
 */

#include <iostream>
using namespace std;

// ============================================
// SEZIONE 1: COSTANTI PER IL MENU
// ============================================

const int OPTION_DEPOSIT = 1;      // Versamento
const int OPTION_WITHDRAWAL = 2;   // Prelevamento
const int OPTION_CHECK = 3;        // Emissione assegno
const int OPTION_SHOW_REPORT = 4;  // Mostra riepilogo
const int OPTION_EXIT = 0;         // Esci

// ============================================
// SEZIONE 2: FUNZIONE PER MOSTRARE IL MENU
// ============================================

/*
 * Funzione: showMenu
 * 
 * Mostra il menu delle operazioni disponibili.
 * Non ha parametri e non restituisce nulla (void).
 */
void showMenu() {
    cout << endl;
    cout << "--- MENU OPERAZIONI ---" << endl;
    cout << "1. Versamento" << endl;
    cout << "2. Prelevamento" << endl;
    cout << "3. Emissione assegno" << endl;
    cout << "4. Mostra riepilogo" << endl;
    cout << "0. Esci" << endl;
    cout << "Scelta: ";
}

// ============================================
// SEZIONE 3: FUNZIONE PER MOSTRARE IL RIEPILOGO
// ============================================

/*
 * Funzione: showReport
 * 
 * Mostra il riepilogo di tutte le operazioni effettuate.
 * 
 * Parametri:
 *   - numDeposits:      numero di versamenti
 *   - totalDeposits:    somma totale versata
 *   - numWithdrawals:   numero di prelevamenti
 *   - totalWithdrawals: somma totale prelevata
 *   - numChecks:        numero di assegni emessi
 *   - totalChecks:      somma totale assegni
 *   - currentBalance:   saldo attuale
 */
void showReport(int numDeposits, double totalDeposits,
                int numWithdrawals, double totalWithdrawals,
                int numChecks, double totalChecks,
                double currentBalance) {
    
    cout << endl;
    cout << "========== RIEPILOGO CONTO ==========" << endl;
    cout << endl;
    
    cout << "VERSAMENTI:" << endl;
    cout << "  Numero operazioni: " << numDeposits << endl;
    cout << "  Totale versato: " << totalDeposits << " euro" << endl;
    cout << endl;
    
    cout << "PRELEVAMENTI:" << endl;
    cout << "  Numero operazioni: " << numWithdrawals << endl;
    cout << "  Totale prelevato: " << totalWithdrawals << " euro" << endl;
    cout << endl;
    
    cout << "ASSEGNI:" << endl;
    cout << "  Numero assegni emessi: " << numChecks << endl;
    cout << "  Totale assegni: " << totalChecks << " euro" << endl;
    cout << endl;
    
    cout << "======================================" << endl;
    cout << "SALDO ATTUALE: " << currentBalance << " euro" << endl;
    cout << "======================================" << endl;
}

// ============================================
// SEZIONE 4: PROGRAMMA PRINCIPALE
// ============================================

int main() {
    
    // -----------------------------------------
    // STEP 1: Dichiarazione variabili
    // -----------------------------------------
    
    // Saldo del conto
    double balance;
    
    // Contatori delle operazioni
    int depositCount = 0;
    int withdrawalCount = 0;
    int checkCount = 0;
    
    // Accumulatori delle somme
    double depositTotal = 0;
    double withdrawalTotal = 0;
    double checkTotal = 0;
    
    // Variabili per input utente
    int userChoice;
    double amount;
    
    // -----------------------------------------
    // STEP 2: Input saldo iniziale
    // -----------------------------------------
    cout << "=== GESTIONE CONTO CORRENTE ===" << endl;
    cout << endl;
    
    cout << "Inserisci il saldo iniziale del conto (euro): ";
    cin >> balance;
    
    cout << "Saldo iniziale registrato: " << balance << " euro" << endl;
    
    // -----------------------------------------
    // STEP 3: Ciclo principale del menu
    // -----------------------------------------
    
    // Usiamo do-while perche' vogliamo mostrare il menu almeno una volta
    do {
        // Mostra il menu
        showMenu();
        cin >> userChoice;
        
        // Gestisci la scelta dell'utente
        switch (userChoice) {
            
            case OPTION_DEPOSIT:
                // --- VERSAMENTO ---
                cout << "Importo da versare (euro): ";
                cin >> amount;
                
                // Aggiorna il saldo (aumenta)
                balance = balance + amount;
                
                // Aggiorna contatore e accumulatore
                depositCount = depositCount + 1;
                depositTotal = depositTotal + amount;
                
                cout << "Versamento effettuato. Nuovo saldo: " << balance << " euro" << endl;
                break;
                
            case OPTION_WITHDRAWAL:
                // --- PRELEVAMENTO ---
                cout << "Importo da prelevare (euro): ";
                cin >> amount;
                
                // Verifica se c'e' abbastanza saldo
                if (amount > balance) {
                    cout << "ERRORE: Saldo insufficiente!" << endl;
                    cout << "Saldo disponibile: " << balance << " euro" << endl;
                } else {
                    // Aggiorna il saldo (diminuisce)
                    balance = balance - amount;
                    
                    // Aggiorna contatore e accumulatore
                    withdrawalCount = withdrawalCount + 1;
                    withdrawalTotal = withdrawalTotal + amount;
                    
                    cout << "Prelevamento effettuato. Nuovo saldo: " << balance << " euro" << endl;
                }
                break;
                
            case OPTION_CHECK:
                // --- EMISSIONE ASSEGNO ---
                cout << "Importo dell'assegno (euro): ";
                cin >> amount;
                
                // Verifica se c'e' abbastanza saldo
                if (amount > balance) {
                    cout << "ERRORE: Saldo insufficiente per emettere l'assegno!" << endl;
                    cout << "Saldo disponibile: " << balance << " euro" << endl;
                } else {
                    // Aggiorna il saldo (diminuisce)
                    balance = balance - amount;
                    
                    // Aggiorna contatore e accumulatore
                    checkCount = checkCount + 1;
                    checkTotal = checkTotal + amount;
                    
                    cout << "Assegno emesso. Nuovo saldo: " << balance << " euro" << endl;
                }
                break;
                
            case OPTION_SHOW_REPORT:
                // --- MOSTRA RIEPILOGO ---
                showReport(depositCount, depositTotal,
                          withdrawalCount, withdrawalTotal,
                          checkCount, checkTotal,
                          balance);
                break;
                
            case OPTION_EXIT:
                // --- ESCI ---
                cout << endl;
                cout << "Grazie per aver usato il programma!" << endl;
                
                // Mostra riepilogo finale prima di uscire
                showReport(depositCount, depositTotal,
                          withdrawalCount, withdrawalTotal,
                          checkCount, checkTotal,
                          balance);
                break;
                
            default:
                // Scelta non valida
                cout << "Scelta non valida. Riprova." << endl;
                break;
        }
        
    } while (userChoice != OPTION_EXIT);
    
    return 0;
}
