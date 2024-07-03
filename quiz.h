#ifndef QUIZ_H
#define QUIZ_H

#define MAX_OPCIJE 4
#define MAX_PITANJA 100
#define MAX_TEKST 300  // Preimenovano s MAX_IME na MAX_TEKST

typedef struct {
    char pitanje[MAX_TEKST];
    char opcije[MAX_OPCIJE][MAX_TEKST];
    int tocanOdgovor;
    int brojOpcija;
} Pitanje;

typedef struct {
    char ime[50];  // Ostaje ime igraca
    int rezultat;
} Igrac;

// Deklaracija varijable igrac
extern Igrac igrac;

// Definicija pokazivača na funkciju za usporedbu
typedef int (*UsporedbaFunc)(const void*, const void*);

// Deklaracije funkcija
void inicijalizirajPitanja(Pitanje* pitanja, int brojPitanja);
void prikaziIzbornik();
void odgovoriNaPitanja(Pitanje* pitanja, int brojPitanja);
void prikaziNajboljeRezultate();
void izbrisiRezultate(const char* imeDatoteke);
void spremiRezultat(const char* imeDatoteke);
void ucitajRezultate(const char* imeDatoteke, Igrac* igraci, int* brojIgraca);
void oslobodiMemoriju(Pitanje* pitanja);
int usporediRezultate(const void* a, const void* b);
void sortirajRezultate(Igrac* igraci, int brojIgraca, UsporedbaFunc usporedba);
void pretraziPitanjePoBroju(Pitanje* pitanja, int brojPitanja);

#endif // QUIZ_H
