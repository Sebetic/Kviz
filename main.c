#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz.h"

#define IME_DATOTEKE "rezultati.txt"

// Makro funkcija za provjeru uspješnosti alokacije memorije (koncept 8)
#define PROVJERI_ALOKACIJU(ptr) \
    do { \
        if (!(ptr)) { \
            perror("Neuspjela alokacija memorije"); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)

// ključna riječ extern za globalne varijable (koncept 7)
extern Igrac igrac;

int main() {
    // Static varijabla (koncept 5)
    static int brojPitanja = 10;

    // Lokalne varijable
    int izbor;
    Igrac* igraci = NULL;

    // Unos imena igrača
    printf("Unesite svoje ime: ");
    fgets(igrac.ime, sizeof(igrac.ime), stdin);
    igrac.ime[strcspn(igrac.ime, "\n")] = 0;

    // Dinamička alokacija memorije za pitanja (koncept 14, 15)
    Pitanje* pitanja = (Pitanje*)malloc(brojPitanja * sizeof(Pitanje));
    PROVJERI_ALOKACIJU(pitanja);

    // Inicijalizacija pitanja
    inicijalizirajPitanja(pitanja, brojPitanja);

    // Prikaz izbornika samo na početku (koncept 9)
    prikaziIzbornik();

    // Obrada odabira korisnika
    do {
        printf("Unesite svoj odabir: ");
        scanf("%d", &izbor);
        getchar(); // Očistite ulazni spremnik nakon scanf

        switch (izbor) {
        case 1:
            odgovoriNaPitanja(pitanja, brojPitanja);
            break;
        case 2:
            prikaziNajboljeRezultate();
            break;
        case 3:
            izbrisiRezultate(IME_DATOTEKE); // Funkcija za brisanje datoteke
            break;
        case 4:
            pretraziPitanjePoBroju(pitanja, brojPitanja);
            break;
        case 5:
            printf("Izlaz iz programa.\n");
            break;
        default:
            printf("Neispravan odabir, pokušajte ponovno.\n");
            break;
        }
    } while (izbor != 5);

    // Oslobađanje dinamički alocirane memorije
    oslobodiMemoriju(pitanja);

    return 0;
}
