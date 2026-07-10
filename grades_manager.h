#ifndef ANDMED_H
#define ANDMED_H

#define MAKSIMAALNE_OPILASI 10
#define ISIKUKOOD 12
#define OPILASE_KOOD 10
#define MAKSIMAALNE_ARV 20
#define MAKS_AINE 30
#define MAKS_HINNE 5
#define MIN_HINNE 0
#define MAKS_ISIKKOOD 11

typedef struct
{
    int opilase_kood[OPILASE_KOOD];
    char eesnimi[MAKSIMAALNE_ARV];
    char perekonnanimi[MAKSIMAALNE_ARV];
    char isikukood[ISIKUKOOD];
} Opilane;

typedef struct
{
    char isikukood[ISIKUKOOD];
    char aine[MAKS_AINE];
    int hinne;
} HinneKirje;

void Sisestumine(char *argv[], const int argc, const char **opilaste_fail, 
							const char **hinnete_fail, const char **save_fail, int *mode, int *valik, char aine[]);
void Otsing(char aine[], HinneKirje hinded[], int hindete_arv, int mode);

int loeOpilasteFail(const char *failinimi, Opilane opilased[], int mode);
int loeHinneteFail(const char *failinimi, HinneKirje hinded[], int mode);
void salvestaJaPrindiFiltreeritudHinded(const char *failinimi, char aine[], 
	Opilane opilased[], int opilaste_arv, HinneKirje hinded[], int hindete_arv, int mode, int valik);
void kysiKoikOppeained(HinneKirje hinded[], int hindete_arv, int mode);
char* saaHinneteKirjeldus(int hinne);

#endif 
