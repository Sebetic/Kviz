#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktura za pitanje
typedef struct {
    char pitanje[256];
    char opcije[4][256];
    int tocanOdgovor;
} Pitanje;

// Struktura za igraca
typedef struct {
    char ime[50];
    int rezultat;
} Igrac;

void inicijalizirajPitanja(Pitanje* pitanja, int brojPitanja);
void prikaziIzbornik();
void odgovoriNaPitanja(Pitanje* pitanja, int brojPitanja);
void prikaziNajboljeRezultate();
void izbrisiRezultate(const char* imeDatoteke);
void spremiRezultat(const char* imeDatoteke);
void ucitajRezultate(const char* imeDatoteke);
void oslobodiMemoriju(Pitanje* pitanja);
void sortirajRezultate(Igrac* igraci, int brojIgraca);

void ucitajRezultate(const char* imeDatoteke, Igrac* igraci, int* brojIgraca);
void pretraziPitanjePoBroju(Pitanje* pitanja, int brojPitanja);

extern Igrac igrac;
