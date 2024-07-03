#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz.h"

#define IME_DATOTEKE "rezultati.txt"
#define MAX_IGRACI 100

// Definicija varijable igrac
Igrac igrac = { "", 0 };


void inicijalizirajPitanja(Pitanje* pitanja, int brojPitanja) {
    if (!pitanja || brojPitanja <= 0) {
        printf("Neispravni parametri za inicijalizaciju pitanja.\n");
        return;
    }

    strncpy(pitanja[0].pitanje, "Tko je osvojio Svjetsko prvenstvo u nogometu 2018. godine?", MAX_TEKST - 1);
    pitanja[0].pitanje[MAX_TEKST - 1] = '\0';
    strncpy(pitanja[0].opcije[0], "Brazil", MAX_TEKST - 1);
    pitanja[0].opcije[0][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[0].opcije[1], "Njemacka", MAX_TEKST - 1);
    pitanja[0].opcije[1][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[0].opcije[2], "Francuska", MAX_TEKST - 1);
    pitanja[0].opcije[2][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[0].opcije[3], "Argentina", MAX_TEKST - 1);
    pitanja[0].opcije[3][MAX_TEKST - 1] = '\0';
    pitanja[0].tocanOdgovor = 2;
    pitanja[0].brojOpcija = 4;

    strncpy(pitanja[1].pitanje, "Koja drzava ima najvise osvojenih Svjetskih prvenstava u nogometu?", MAX_TEKST - 1);
    pitanja[1].pitanje[MAX_TEKST - 1] = '\0';
    strncpy(pitanja[1].opcije[0], "Brazil", MAX_TEKST - 1);
    pitanja[1].opcije[0][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[1].opcije[1], "Njemacka", MAX_TEKST - 1);
    pitanja[1].opcije[1][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[1].opcije[2], "Italija", MAX_TEKST - 1);
    pitanja[1].opcije[2][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[1].opcije[3], "Argentina", MAX_TEKST - 1);
    pitanja[1].opcije[3][MAX_TEKST - 1] = '\0';
    pitanja[1].tocanOdgovor = 0;
    pitanja[1].brojOpcija = 4;

    strncpy(pitanja[2].pitanje, "Koja je najstarija aktivna nogometna reprezentacija na svijetu?", MAX_TEKST - 1);
    pitanja[2].pitanje[MAX_TEKST - 1] = '\0';
    strncpy(pitanja[2].opcije[0], "Engleska", MAX_TEKST - 1);
    pitanja[2].opcije[0][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[2].opcije[1], "Skotska", MAX_TEKST - 1);
    pitanja[2].opcije[1][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[2].opcije[2], "Argentina", MAX_TEKST - 1);
    pitanja[2].opcije[2][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[2].opcije[3], "Urugvaj", MAX_TEKST - 1);
    pitanja[2].opcije[3][MAX_TEKST - 1] = '\0';
    pitanja[2].tocanOdgovor = 0;
    pitanja[2].brojOpcija = 4;

    strncpy(pitanja[3].pitanje, "Koja je reprezentacija osvojila prvo Svjetsko prvenstvo u nogometu?", MAX_TEKST - 1);
    pitanja[3].pitanje[MAX_TEKST - 1] = '\0';
    strncpy(pitanja[3].opcije[0], "Argentina", MAX_TEKST - 1);
    pitanja[3].opcije[0][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[3].opcije[1], "Brazil", MAX_TEKST - 1);
    pitanja[3].opcije[1][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[3].opcije[2], "Urugvaj", MAX_TEKST - 1);
    pitanja[3].opcije[2][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[3].opcije[3], "Italija", MAX_TEKST - 1);
    pitanja[3].opcije[3][MAX_TEKST - 1] = '\0';
    pitanja[3].tocanOdgovor = 2;
    pitanja[3].brojOpcija = 4;

    strncpy(pitanja[4].pitanje, "Koji je jedini klub osim Dinama u zadnjih 10 godina osvojio HNL?", MAX_TEKST - 1);
    pitanja[4].pitanje[MAX_TEKST - 1] = '\0';
    strncpy(pitanja[4].opcije[0], "Hajduk", MAX_TEKST - 1);
    pitanja[4].opcije[0][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[4].opcije[1], "Osijek", MAX_TEKST - 1);
    pitanja[4].opcije[1][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[4].opcije[2], "Lokomotiva", MAX_TEKST - 1);
    pitanja[4].opcije[2][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[4].opcije[3], "Rijeka", MAX_TEKST - 1);
    pitanja[4].opcije[3][MAX_TEKST - 1] = '\0';
    pitanja[4].tocanOdgovor = 3;
    pitanja[4].brojOpcija = 4;

    strncpy(pitanja[5].pitanje, "Tko drzi rekord za najvise golova u jednoj sezoni HNL-a?", MAX_TEKST - 1);
    pitanja[5].pitanje[MAX_TEKST - 1] = '\0';
    strncpy(pitanja[5].opcije[0], "Leon Benko", MAX_TEKST - 1);
    pitanja[5].opcije[0][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[5].opcije[1], "Andrej Kramaric", MAX_TEKST - 1);
    pitanja[5].opcije[1][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[5].opcije[2], "Eduardo Da Silva", MAX_TEKST - 1);
    pitanja[5].opcije[2][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[5].opcije[3], "Romano Obilinovic", MAX_TEKST - 1);
    pitanja[5].opcije[3][MAX_TEKST - 1] = '\0';
    pitanja[5].tocanOdgovor = 2;
    pitanja[5].brojOpcija = 4;

    strncpy(pitanja[6].pitanje, "Koji je od sljedecih velikih europskih klubova 2011. gostovao na Poljudu?", MAX_TEKST - 1);
    pitanja[6].pitanje[MAX_TEKST - 1] = '\0';
    strncpy(pitanja[6].opcije[0], "Barcelona", MAX_TEKST - 1);
    pitanja[6].opcije[0][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[6].opcije[1], "Real Madrid", MAX_TEKST - 1);
    pitanja[6].opcije[1][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[6].opcije[2], "Liverpool", MAX_TEKST - 1);
    pitanja[6].opcije[2][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[6].opcije[3], "Chelsea", MAX_TEKST - 1);
    pitanja[6].opcije[3][MAX_TEKST - 1] = '\0';
    pitanja[6].tocanOdgovor = 0;
    pitanja[6].brojOpcija = 4;

    strncpy(pitanja[7].pitanje, "Koji je klub u 2023./24. sezoni osvojio ligu neporazen?", MAX_TEKST - 1);
    pitanja[7].pitanje[MAX_TEKST - 1] = '\0';
    strncpy(pitanja[7].opcije[0], "Inter Milan", MAX_TEKST - 1);
    pitanja[7].opcije[0][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[7].opcije[1], "Real Madrid", MAX_TEKST - 1);
    pitanja[7].opcije[1][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[7].opcije[2], "Bayer Leverkusen", MAX_TEKST - 1);
    pitanja[7].opcije[2][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[7].opcije[3], "Manchester City", MAX_TEKST - 1);
    pitanja[7].opcije[3][MAX_TEKST - 1] = '\0';
    pitanja[7].tocanOdgovor = 2;
    pitanja[7].brojOpcija = 4;

    strncpy(pitanja[8].pitanje, "Kojem igracu je posljednja utakmica u karijeri bila finale Svjetskog prvenstva?", MAX_TEKST - 1);
    pitanja[8].pitanje[MAX_TEKST - 1] = '\0';
    strncpy(pitanja[8].opcije[0], "Zinedineu Zidaneu", MAX_TEKST - 1);
    pitanja[8].opcije[0][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[8].opcije[1], "Mariju Mandzukicu", MAX_TEKST - 1);
    pitanja[8].opcije[1][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[8].opcije[2], "Miroslavu Kloseu", MAX_TEKST - 1);
    pitanja[8].opcije[2][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[8].opcije[3], "Ronaldu Nazariu", MAX_TEKST - 1);
    pitanja[8].opcije[3][MAX_TEKST - 1] = '\0';
    pitanja[8].tocanOdgovor = 0;
    pitanja[8].brojOpcija = 4;

    strncpy(pitanja[9].pitanje, "Koji je hrvatski nogometas jedini igrao za Real Madrid i Barcelonu?", MAX_TEKST - 1);
    pitanja[9].pitanje[MAX_TEKST - 1] = '\0';
    strncpy(pitanja[9].opcije[0], "Mateo Kovacic", MAX_TEKST - 1);
    pitanja[9].opcije[0][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[9].opcije[1], "Robert Prosinecki", MAX_TEKST - 1);
    pitanja[9].opcije[1][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[9].opcije[2], "Alen Halilovic", MAX_TEKST - 1);
    pitanja[9].opcije[2][MAX_TEKST - 1] = '\0';
    strncpy(pitanja[9].opcije[3], "Ivica Olic", MAX_TEKST - 1);
    pitanja[9].opcije[3][MAX_TEKST - 1] = '\0';
    pitanja[9].tocanOdgovor = 1;
    pitanja[9].brojOpcija = 4;
}



// Funkcija za prikaz izbornika
void prikaziIzbornik() {
    printf("1. Rjesavanje kviza\n");
    printf("2. Prikaz rezultata\n");
    printf("3. Brisanje rezultata\n");
    printf("4. Pretrazivanje pitanja po broju\n");
    printf("5. Izlaz\n");
}


void odgovoriNaPitanja(Pitanje* pitanja, int brojPitanja) {
    if (!pitanja || brojPitanja <= 0) {
        printf("Neispravni parametri za rjesavanje kviza.\n");
        return;
    } 
    igrac.rezultat = 0; // Resetiranje rezultata prije pocetka

    for (int i = 0; i < brojPitanja; ++i) {
        printf("%s\n", pitanja[i].pitanje);
        for (int j = 0; j < pitanja[i].brojOpcija; ++j) { 
            printf("%d. %s\n", j + 1, pitanja[i].opcije[j]);
        }
        int odgovor;
        printf("Vas odgovor: ");
        scanf("%d", &odgovor);
        getchar(); // Očistite ulazni spremnik nakon scanf
        if (odgovor == pitanja[i].tocanOdgovor + 1) {
            igrac.rezultat++;
        }
    }

    // Spremi rezultat u datoteku (koncept 17)
    spremiRezultat(IME_DATOTEKE);
    printf("Završili ste kviz! Vaš rezultat je %d/%d.\n", igrac.rezultat, brojPitanja);
}

// Funkcija za prikaz najboljih rezultata
// Funkcija za prikaz najboljih rezultata
void prikaziNajboljeRezultate() {
    Igrac igraci[MAX_IGRACI];
    int brojIgraca = 0;

    ucitajRezultate(IME_DATOTEKE, igraci, &brojIgraca);

    if (brojIgraca == 0) {
        printf("Nema rezultata za prikaz.\n");
        return;
    }

    sortirajRezultate(igraci, brojIgraca, usporediRezultate);

    printf("Najbolji rezultati:\n");
    for (int i = 0; i < brojIgraca; ++i) {
        printf("%s - %d\n", igraci[i].ime, igraci[i].rezultat);
    }
}

// Funkcija za brisanje rezultata
void izbrisiRezultate(const char* imeDatoteke) {
    if (remove(imeDatoteke) == 0) {
        printf("Datoteka %s je uspjesno izbrisana.\n", imeDatoteke);
    }
    else {
        perror("Pogreska prilikom brisanja datoteke");
    }
}

// Funkcija za spremanje rezultata u datoteku
void spremiRezultat(const char* imeDatoteke) {
    FILE* datoteka = fopen(imeDatoteke, "a");
    if (datoteka == NULL) {
        perror("Pogreska prilikom otvaranja datoteke");
        return;
    }
    fprintf(datoteka, "Igrac: %s, Rezultat: %d\n", igrac.ime, igrac.rezultat);
    fclose(datoteka);
}

// Funkcija za učitavanje rezultata iz datoteke
void ucitajRezultate(const char* imeDatoteke, Igrac* igraci, int* brojIgraca) {
    FILE* datoteka = fopen(imeDatoteke, "r");
    if (!datoteka) {
        perror("Pogreska prilikom otvaranja datoteke");
        return;
    }

    // Postavljanje na pocetak datoteke prije citanja
    rewind(datoteka);

    *brojIgraca = 0;
    while (fscanf(datoteka, "Igrac: %49[^,], Rezultat: %d\n", igraci[*brojIgraca].ime, &igraci[*brojIgraca].rezultat) == 2) {
        (*brojIgraca)++;
        if (*brojIgraca >= MAX_IGRACI) {
            printf("Dostignut maksimalni broj igraca.\n");
            break;
        }
    }

    fclose(datoteka);
}

// Funkcija za oslobađanje dinamički alocirane memorije
void oslobodiMemoriju(Pitanje* pitanja) {
    if (pitanja != NULL) {
        free(pitanja);
        pitanja = NULL;
    }
}

// Funkcija za usporedbu rezultata
typedef int (*UsporedbaFunc)(const void*, const void*);

// Funkcija za usporedbu rezultata
int usporediRezultate(const void* a, const void* b) {
    Igrac* igracA = (Igrac*)a;
    Igrac* igracB = (Igrac*)b;
    return igracB->rezultat - igracA->rezultat; // Silazni redoslijed
}

// Funkcija za sortiranje rezultata koristeći pokazivač na funkciju
void sortirajRezultate(Igrac* igraci, int brojIgraca, UsporedbaFunc usporedba) {
    qsort(igraci, brojIgraca, sizeof(Igrac), usporedba);
}


// Funkcija za pretragu pitanja po broju
void pretraziPitanjePoBroju(Pitanje* pitanja, int brojPitanja) {
    if (brojPitanja == 0) {
        printf("Nema pitanja za pretrazivanje.\n");
        return;
    }

    int broj;
    printf("Unesite broj pitanja koje zelite pretraziti (1-%d): ", brojPitanja);
    scanf("%d", &broj);
    getchar(); // Očistite ulazni spremnik nakon scanf

    if (broj < 1 || broj > brojPitanja) {
        printf("Neispravan broj pitanja.\n");
        return;
    }

    int index = broj - 1;
    printf("Pitanje %d: %s\n", broj, pitanja[index].pitanje);
    for (int j = 0; j < pitanja[index].brojOpcija; ++j) { // Koristimo brojOpcija
        printf("%d. %s\n", j + 1, pitanja[index].opcije[j]);
    }
    printf("\n"); // Dodajte ovaj redak kako bi se osigurao razmak nakon ispisivanja pitanja i opcija
}
