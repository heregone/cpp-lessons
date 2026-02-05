# Agent Instructions - C++ Tutoring

> Regole per lavorare su questo progetto di tutoring C++.

---

## 🎯 Obiettivo

Creare esercizi C++ didattici per uno studente principiante.

---

## ⚠️ IMPORTANTE - ISOLAMENTO

**Questo progetto è COMPLETAMENTE SEPARATO da altri progetti!**

- NON toccare MAI `c:\a_bp` o qualsiasi altra cartella
- Lavorare SOLO dentro `c:\a_otherCode\cpp_tutoring`
- NON creare branch su altri repository

---

## 📋 Workflow Esercizi

1. **Ricevo immagine pagina libro**
   - Leggo gli esercizi nella pagina
   - Aggiorno `docs/EXERCISES_INDEX.md`
   - Creo i file `.cpp` per ogni esercizio

2. **Per ogni esercizio**:
   - Creo file in `exercises/unit_XX/ex_NN_nome.cpp`
   - Scrivo codice SEMPLICE e DIDATTICO
   - Aggiungo commenti che spiegano TUTTO
   - Marco come completato in `EXERCISES_INDEX.md`

3. **Commit e Push**
   - Commit con messaggio chiaro
   - Push su GitHub

---

## 🔧 Stile Codice

| Regola | Esempio |
|--------|---------|
| Variabili in INGLESE | `price`, `quantity`, `total` |
| Commenti in ITALIANO | `// Calcola il totale` |
| Nomi descrittivi | `numberOfItems` non `n` |
| Funzioni separate | Una funzione per ogni compito |
| Input/Output chiari | Messaggi comprensibili |

### Struttura Tipica File

```cpp
/*
 * ESERCIZIO N - Titolo
 * 
 * Descrizione dell'esercizio dal libro.
 * 
 * Cosa impariamo:
 * - Concetto 1
 * - Concetto 2
 */

#include <iostream>
using namespace std;

// ============================================
// SEZIONE 1: FUNZIONI
// ============================================

// Descrizione funzione
int miaFunzione(int param) {
    // Spiegazione passo passo
    return risultato;
}

// ============================================
// SEZIONE 2: MAIN
// ============================================

int main() {
    // STEP 1: Dichiarazione variabili
    
    // STEP 2: Input
    
    // STEP 3: Elaborazione
    
    // STEP 4: Output
    
    return 0;
}
```

---

## 📁 Struttura Cartelle

```
cpp_tutoring/
├── exercises/
│   └── unit_A1/      # Esercizi Unità A1 (pagina 49, ecc.)
│   └── unit_A2/      # Future unità
├── docs/
│   ├── EXERCISES_INDEX.md   # Tracciamento esercizi
│   └── AGENTS.md           # Questo file
├── .gitignore
└── README.md
```

---

## ✅ Checklist Prima di Commit

1. [ ] Codice compila senza errori
2. [ ] Commenti spiegano ogni passaggio
3. [ ] Variabili in inglese
4. [ ] `EXERCISES_INDEX.md` aggiornato
5. [ ] Un commit per ogni esercizio completato
