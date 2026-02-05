# C++ Tutoring - Esercizi Didattici

Progetto per lezioni private di C++. Contiene esercizi risolti con codice semplice, ben commentato e didattico.

## Struttura

```
cpp_tutoring/
├── exercises/          # Esercizi organizzati per unità/pagina
│   └── unit_A1/        # Esercizi Unità A1
│       ├── ex_18_discount.cpp
│       ├── ex_19_ferry.cpp
│       └── ...
├── docs/
│   └── EXERCISES_INDEX.md   # Indice esercizi da fare
└── README.md
```

## Come Usare

1. Ogni esercizio è in un file `.cpp` separato
2. I commenti spiegano ogni passaggio
3. Variabili in inglese, commenti in italiano
4. Codice semplice, niente soluzioni complesse

## Compilazione

```bash
# Con g++
g++ exercises/unit_A1/ex_18_discount.cpp -o ex_18

# Esegui
./ex_18
```

## Per il Tutor

Quando ricevi una nuova pagina di esercizi:
1. Aggiorna `docs/EXERCISES_INDEX.md` con i nuovi esercizi
2. Crea i file `.cpp` nella cartella appropriata
3. Commit e push su GitHub

---

**Nota**: Questo progetto è completamente separato da altri progetti di sviluppo.
