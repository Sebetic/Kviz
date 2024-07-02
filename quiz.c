#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz.h"

#define IME_DATOTEKE "rezultati.txt"
#define MAX_IGRACI 100

// Statička varijabla za igraca (koncept 5)
Igrac igrac = { "", 0 };

// Funkcija za inicijalizaciju pitanja
void inicijalizirajPitanja(Pitanje* pitanja, int brojPitanja) {
    if (!pitanja || brojPitanja <= 0) {
        printf("Neispravni parametri za inicijalizaciju pitanja.\n");
        return;
    }
    strcpy(pitanja[0].pitanje, "Tko je osvojio Svjetsko prvenstvo u nogometu 2018. godine?");
    strcpy(pitanja[0].opcije[0], "Brazil");
    strcpy(pitanja[0].opcije[1], "Njemacka");
    strcpy(pitanja[0].opcije[2], "Francuska");
    strcpy(pitanja[0].opcije[3], "Argentina");
    pitanja[0].tocanOdgovor = 2;

    strcpy(pitanja[1].pitanje, "Koja drzava ima najviše osvojenih Svjetskih prvenstava u nogometu?");
    strcpy(pitanja[1].opcije[0], "Brazil");
    strcpy(pitanja[1].opcije[1], "Njemacka");
    strcpy(pitanja[1].opcije[2], "Italija");
    strcpy(pitanja[1].opcije[3], "Argentina");
    pitanja[1].tocanOdgovor = 0;

    strcpy(pitanja[2].pitanje, "Koja je najstarija aktivna nogometna reprezentacija na svijetu?");
    strcpy(pitanja[2].opcije[0], "Engleska");
    strcpy(pitanja[2].opcije[1], "Skotska");
    strcpy(pitanja[2].opcije[2], "Argentina");
    strcpy(pitanja[2].opcije[3], "Urugvaj");
    pitanja[2].tocanOdgovor = 0;

    strcpy(pitanja[3].pitanje, "Koja je reprezentacija osvojila prvo Svjetsko prvenstvo u nogometu?");
    strcpy(pitanja[3].opcije[0], "Argentina");
    strcpy(pitanja[3].opcije[1], "Brazil");
    strcpy(pitanja[3].opcije[2], "Urugvaj");
    strcpy(pitanja[3].opcije[3], "Italija");
    pitanja[3].tocanOdgovor = 2;


    strcpy(pitanja[4].pitanje, "Koji je jedini klub osim Dinama u zadnjih 10 godina osvojio HNL?");
    strcpy(pitanja[4].opcije[0], "Hajduk");
    strcpy(pitanja[4].opcije[1], "Osijek");
    strcpy(pitanja[4].opcije[2], "Lokomotiva");
    strcpy(pitanja[4].opcije[3], "Rijeka");
    pitanja[4].tocanOdgovor = 3;

    strcpy(pitanja[5].pitanje, "Tko drzi rekord za najvise golova u jednoj sezoni HNL-a?");
    strcpy(pitanja[5].opcije[0], "Leon Benko");
    strcpy(pitanja[5].opcije[1], "Andrej Kramaric");
    strcpy(pitanja[5].opcije[2], "Eduardo Da Silva");
    strcpy(pitanja[5].opcije[3], "Romano Obilinovic");
    pitanja[5].tocanOdgovor = 2;
    
    strcpy(pitanja[6].pitanje, "Koji je od sljedecih velikih europskih klubova 2011. gostovao na Poljudu?");
    strcpy(pitanja[6].opcije[0], "Barcelona");
    strcpy(pitanja[6].opcije[1], "Real Madrid");
    strcpy(pitanja[6].opcije[2], "Liverpool");
    strcpy(pitanja[6].opcije[3], "Chelsea");
    pitanja[6].tocanOdgovor = 0;

    strcpy(pitanja[7].pitanje, "Koji je klub u 2023./24. sezoni osvojio ligu neporažen?");
    strcpy(pitanja[7].opcije[0], "Inter Milan");
    strcpy(pitanja[7].opcije[1], "Real Madrid");
    strcpy(pitanja[7].opcije[2], "Bayer Leverkusen");
    strcpy(pitanja[7].opcije[3], "Manchester City");
    pitanja[7].tocanOdgovor = 2;

    strcpy(pitanja[8].pitanje, "Kojem igraču je posljednja utakmica u karijeri bila finale Svjetskog prvenstva?");
    strcpy(pitanja[8].opcije[0], "Zinedineu Zidaneu");
    strcpy(pitanja[8].opcije[1], "Mariju Mandžukicu");
    strcpy(pitanja[8].opcije[2], "Miroslavu Kloseu");
    strcpy(pitanja[8].opcije[3], "Ronaldu Nazariu");
    pitanja[8].tocanOdgovor = 0;


    strcpy(pitanja[9].pitanje, "Koji je hrvatski nogometas jedini igrao za Real Madrid i Barcelonu");
    strcpy(pitanja[9].opcije[0], "Mateo Kovacic");
    strcpy(pitanja[9].opcije[1], "Robert Prosinecki");
    strcpy(pitanja[9].opcije[2], "Alen Halilovic");
    strcpy(pitanja[9].opcije[3], "Ivica Olic");
    pitanja[9].tocanOdgovor = 1;




}

// Funkcija za prikaz izbornika
void prikaziIzbornik() {
    printf("1. Rjesavanje kviza\n");
    printf("2. Prikaz rezultata\n");
    printf("3. Brisanje rezultata\n");
    printf("4. Pretrazivanje pitanja po broju\n");
    printf("5. Izlaz\n");
}

// Funkcija za rješavanje kviza
void odgovoriNaPitanja(Pitanje* pitanja, int brojPitanja) {
    if (!pitanja || brojPitanja <= 0) {
        printf("Neispravni parametri za rjesavanje kviza.\n");
        return;
    }
    igrac.rezultat = 0; 

    for (int i = 0; i < brojPitanja; ++i) {
        printf("%s\n", pitanja[i].pitanje);
        for (int j = 0; j < 4; ++j) {
            printf("%d. %s\n", j + 1, pitanja[i].opcije[j]);
        }
        int odgovor;
        printf("Vas odgovor: ");
        scanf("%d", &odgovor);
        getchar(); 
        if (odgovor == pitanja[i].tocanOdgovor + 1) {
            igrac.rezultat++;
        }
    }

    // Spremi rezultat u datoteku (koncept 17)
    spremiRezultat(IME_DATOTEKE);
    printf("Završili ste kviz! Vaš rezultat je %d/%d.\n", igrac.rezultat, brojPitanja);
}

// Funkcija za prikaz najboljih rezultata
void prikaziNajboljeRezultate() {
    Igrac igraci[MAX_IGRACI];
    int brojIgraca = 0;

    ucitajRezultate(IME_DATOTEKE, igraci, &brojIgraca);

    if (brojIgraca == 0) {
        printf("Nema rezultata za prikaz.\n");
        return;
    }

    sortirajRezultate(igraci, brojIgraca);

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
int usporediRezultate(const void* a, const void* b) {
    Igrac* igracA = (Igrac*)a;
    Igrac* igracB = (Igrac*)b;
    return igracB->rezultat - igracA->rezultat; // Silazni redoslijed
}

// Funkcija za sortiranje rezultata
void sortirajRezultate(Igrac* igraci, int brojIgraca) {
    qsort(igraci, brojIgraca, sizeof(Igrac), usporediRezultate);
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
    getchar(); 

    if (broj < 1 || broj > brojPitanja) {
        printf("Neispravan broj pitanja.\n");
        return;
    }

    int index = broj - 1;
    printf("Pitanje %d: %s\n", broj, pitanja[index].pitanje);
    for (int j = 0; j < 9; ++j) {
        printf("%d. %s\n", j + 1, pitanja[index].opcije[j]);
    }
    printf("\n"); 
}
