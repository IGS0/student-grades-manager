#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grades_manager.h"


int main(int argc, char *argv[])
{

    Opilane opilased[MAKSIMAALNE_OPILASI];
    HinneKirje hinded[MAKSIMAALNE_OPILASI];

    
    const char *opilaste_fail;
    const char *hinnete_fail;
    const char *save_fail;
    int mode = 0;
    int valik;
    char aine[MAKS_AINE];
	Sisestumine(argv, argc, &opilaste_fail, &hinnete_fail, &save_fail, &mode, &valik, aine);

    int opilaste_arv = loeOpilasteFail(opilaste_fail, opilased, mode);
    int hindete_arv = loeHinneteFail(hinnete_fail, hinded, mode);

    kysiKoikOppeained(hinded, hindete_arv, mode);
	
	Otsing(aine, hinded, hindete_arv, mode);

    salvestaJaPrindiFiltreeritudHinded(save_fail,aine, opilased, opilaste_arv, 
												hinded, hindete_arv, mode, valik);


    return 0;
}

/**
 * Description:    Määrab failinimed vastavalt kasutaja sisestusele või 
 * 													kasutab vaikimisi nimesid.
 *
 * Parameters:     argv - koht käsureal(terminalis)
 * 				   argc - kokku kohti
 * 				   opilaste_fail - fail kus on õpelaste andmed
 * 				   hinnete_fail - fail kus on õppeaine ja õpelase hinded
 * 				   save_fail - lõpp fail, kus salvestatakse vastus
 * 				   mode - teksti näitamis režiim
 * 				   valik - kus näidata vastus
 * 				   aine - valitud aine
 * 
 * Return:         none
 */
void Sisestumine(char *argv[], const int argc, const char **opilaste_fail, 
	const char **hinnete_fail, const char **save_fail, int *mode, int *valik, char aine[])
{
    // Kontrolli, kas käsurea argumente on piisavalt
    if (argc == 1)
    {
      // Kasutaja ei sisestanud käsurea argumente, kasuta vaikimisi failinimesid
        *opilaste_fail = "fail1.txt";
        *hinnete_fail = "fail2.txt";
        *save_fail = "Andmed.txt";
    }
    else if (argc == 3)
    {
		if (strcmp(argv[1], "fail") == 0 || strcmp(argv[1], "kõik") == 0 || strcmp(argv[1], "terminal") == 0)
        {
            if (strcmp(argv[1], "kõik") == 0)
            {
                *mode = 1;
                *valik = 3;
                strcpy(aine, argv[2]);
            }
            else if (strcmp(argv[1], "fail") == 0)
            {
                *mode = 1;
                *valik = 1;
                strcpy(aine, argv[2]);
            }
            else if (strcmp(argv[1], "terminal") == 0)
            {
                *mode = 1;
                *valik = 2;
                strcpy(aine, argv[2]);
            }
			// Kasutaja ei sisestanud käsurea argumente, kasuta vaikimisi failinimesid
			*opilaste_fail = "fail1.txt";
			*hinnete_fail = "fail2.txt";
			*save_fail = "Andmed.txt";
        }
        else
        {
        // Kasutaja sisestas mõlemad failinimed
        *opilaste_fail = argv[1];
        *hinnete_fail = argv[2];
        *save_fail = "Andmed.txt";
        }
    }
    else if (argc == 4)
    {
        // Kasutaja sisestas mõlemad failinimed
        *opilaste_fail = argv[1];
        *hinnete_fail = argv[2];
        *save_fail = argv[3];
    }
    else if (argc == 5)
    {
        // Kasutaja sisestas mõlemad failinimed
        *opilaste_fail = argv[1];
        *hinnete_fail = argv[2];
        *save_fail = "Andmed.txt";
        
        if (strcmp(argv[3], "fail") == 0 || strcmp(argv[3], "kõik") == 0 || strcmp(argv[3], "terminal") == 0)
        {
            if (strcmp(argv[3], "kõik") == 0)
            {
                *mode = 1;
                *valik = 3;
                strcpy(aine, argv[4]);
            }
            else if (strcmp(argv[3], "fail") == 0)
            {
                *mode = 1;
                *valik = 1;
                strcpy(aine, argv[4]);
            }
            else if (strcmp(argv[3], "terminal") == 0)
            {
               *mode = 1;
                *valik = 2;
                strcpy(aine, argv[4]);
            }
        }
        else
        {
			printf("Teine argument peab olema 'fail', 'kõik', 'terminal' või failinimi, mis lõpeb '.txt'.\n");
            exit(1);
        }
        
    }
    else if (argc == 6)
    {
        // Kasutaja sisestas mõlemad failinimed
        *opilaste_fail = argv[1];
        *hinnete_fail = argv[2];
        *save_fail = argv[3];
        
        if (strcmp(argv[4], "fail") == 0 || strcmp(argv[4], "kõik") == 0 || strcmp(argv[4], "terminal") == 0)
        {
            if (strcmp(argv[4], "kõik") == 0)
            {
                *mode = 1;
                *valik = 3;
                strcpy(aine, argv[5]);
            }
            else if (strcmp(argv[4], "fail") == 0)
            {
                *mode = 1;
                *valik = 1;
                strcpy(aine, argv[5]);
            }
            else if (strcmp(argv[4], "terminal") == 0)
            {
                *mode = 1;
                *valik = 2;
                strcpy(aine, argv[5]);
            }
        }
        else
        {
			printf("4 argument peab olema 'fail', 'kõik', 'terminal' või failinimi, mis lõpeb '.txt'.\n");
            exit(1);
        }
    }
    else
    {
        printf("\n> 1.Kasutamine: %s <opilaste_fail> <hinnete_fail> <save_fail>\n"
        , argv[0]);
        printf(" või\n");
        printf("> 2.Kasutamine: %s <opilaste_fail> <hinnete_fail>\n", argv[0]);
        printf(" või\n");
        printf("> 3.Kasutamine: %s\n",argv[0]);
        printf(" või\n");
        printf("> 4.Kasutamine: %s <kuhu näidata> <aine>\n", argv[0]);
        printf(" või\n");
        printf("> 5.Kasutamine: %s <opilaste_fail> <hinnete_fail> <kuhu näidata> <aine>\n", argv[0]);
        printf(" või\n");
        printf("> 6.Kasutamine: %s <opilaste_fail> <hinnete_fail> <kuhu save_fail> <kuhu näidata> <aine>\n\n", argv[0]);
        exit(1);
    }
}


/**
 * Description:    Loeb õpilaste andmete failist õpilaste andmed massiivi.
 *
 * Parameters:     failinimi - millest fali loeb
 * 				   opilased[] - andme klass
 *	 			   mode - teksti näitamis režiim

 * 				   
 * Return:         opilaste_arv
 */
 
// Parandatud loeOpilasteFail funktsioon
int loeOpilasteFail(const char *failinimi, Opilane opilased[], int mode)
{
    FILE *fail = fopen(failinimi, "r");
    if (fail == NULL)
    {
        printf("Viga faili1 '%s' avamisel.\n", failinimi);
        exit(1); 
    }


    int opilaste_arv = 0; // Alusta loendamist nullist


    while (fscanf(fail, "%d %s %s %s", (opilased + opilaste_arv)->opilase_kood, 
                                   (opilased + opilaste_arv)->eesnimi, 
                                    (opilased + opilaste_arv)->perekonnanimi, 
                                     (opilased + opilaste_arv)->isikukood) == 4)
    {
		
		
        if (strlen((opilased + opilaste_arv)->isikukood) != MAKS_ISIKKOOD)
        {
            printf("Viga 1 faili real %d: Isikukood on pikem või lühem kui %d.\n"
            "Parandage ja proovige uuesti.\n", opilaste_arv + 1, MAKS_ISIKKOOD);
            fclose(fail);
            exit(1); 
        }

		
        opilaste_arv++;

        
                
        if (opilaste_arv + 1  > MAKSIMAALNE_OPILASI)
		{
			if(mode == 0){
				
			printf("Failis 1 on rohkem kui %d rida. Katkestame lugemise.\n\n", 
														MAKSIMAALNE_OPILASI);
			}
			break;
		}
    }
    
    fclose(fail); // Sulge fail edukal lugemisel
    return opilaste_arv; // Tagasta õpilaste arv
}

/**
 * Description:    Loeb hinnete failist hinnete andmed massiivi.
 *
 * Parameters:     failinimi - millest fali loeb
 * 				   hinded[] - andme klass
 * 				   mode - teksti näitamis režiim

 * 				   
 * Return:         hindete_arv
 */
// Parandatud loeHinneteFail funktsioon
int loeHinneteFail(const char *failinimi, HinneKirje hinded[], int mode)
{
    FILE *fail = fopen(failinimi, "r");
    if (fail == NULL)
    {
        printf("Viga faili2 '%s' avamisel.\n", failinimi);
        exit(1); 
    }

    int hindete_arv = 0; // Alusta loendamist nullist

    
    while (fscanf(fail, "%s %s %d", (hinded + hindete_arv)->isikukood, 
										(hinded + hindete_arv)->aine, 
										&(hinded + hindete_arv)->hinne) == 3)
    {
        
        
        
        if ((hinded + hindete_arv)->hinne > MAKS_HINNE || (hinded + hindete_arv)->hinne < MIN_HINNE)
        {
            printf("Viga 2 faili real %d: Hinde väärtus on suurem kui %d või"
						" väiksem kui %d.\nParandage ja proovige uuesti\n", 
												hindete_arv + 1, MAKS_HINNE, MIN_HINNE);
            fclose(fail);
			exit(1); 
        }
        
        if (strlen((hinded + hindete_arv)->isikukood) != MAKS_ISIKKOOD)
        {
           printf("Viga 2 faili real %d: Isikukood on pikem või lühem kui %d."
           "\nParandage ja proovige uuesti.\n", hindete_arv +1, MAKS_ISIKKOOD);
           printf(" %s\n", (hinded + hindete_arv)->isikukood);
           fclose(fail);
		exit(1); 
        }
		
        hindete_arv++;
        
        if (hindete_arv + 1 > MAKSIMAALNE_OPILASI)
		{
			if(mode == 0){
				
			printf("Failis 2 on rohkem kui %d rida. Katkestame lugemise.\n\n", 
														MAKSIMAALNE_OPILASI);
			}
			break;
		}
    }

    fclose(fail); // Sulge fail edukal lugemisel
    return hindete_arv; // Tagasta hindete arv
}


/**
 * Description:    Väljastab olemasolevad õppeained ja vastavad hinnete arvud.
 *
 * Parameters:     
 * 				   hinded[] - andme klass
 * 				   hindete_arv - mitu õpelasi on 2 failis
 *  			   mode - teksti näitamis režiim

 * 
 * Return:         none
 */
void kysiKoikOppeained(HinneKirje hinded[], int hindete_arv, int mode)
{
	if(mode == 0)
	{
		printf("Olemasolevad õppeained ja vastavad hinnete arvud:\n");
	}

    for (int i = 0; i < hindete_arv; i++)  
    {
        int leitud = 0;
        int hinnete_arv = 0; // Uus muutuja hinnete arvu jälgimiseks
        
        for (int j = 0; j < i; j++)
        {
            if (strcasecmp((hinded+i)->aine, (hinded+j)->aine) == 0)
            {
                leitud = 1;
                break;
            }
        }

        if (!leitud)
        {
            // Loenda hinnete arv vastavale õppeainele
            for (int k = i; k < hindete_arv; k++)
            {
                if (strcasecmp((hinded+i)->aine, (hinded+k)->aine) == 0)
                {
                    hinnete_arv++;
                }
            }
				if(mode == 0)
				{
					printf("%s (%d hinnet)\n", (hinded+i)->aine, hinnete_arv);
				}
        }
    }
}


/**
 * Description:    Tagastab hinnete kirjelduse vastavalt hinnetele.
 *
 * Parameters:     hinne - salvestatud hinned
 * Return:         none
 */
char* saaHinneteKirjeldus(int hinne) 
{

		switch (hinne)
		{
			case 0:
				return "...-49%";
			case 1:
				return "50%-59%";
			case 2:
				return "60%-69%";
			case 3:
				return "70%-79%";
			case 4:
				return "80%-89%";
			case 5:
				return "90%-...";
			default:
				return "Tundmatu hinne";
		}
	
}

/**
 * Description: Küsib kasutajalt õppeaine nime, mille kohta hindeid soovitakse näha.
 *
 * Parameters:   aine- millist aine otsitakse 
 * 				 hinded - andme klass
 * 				 hindete_arv - mitu inimest 1 failis
 * 		         mode - teksti näitamis režiim
 * Return:       none
 */
void Otsing(char aine[], HinneKirje hinded[], int hindete_arv, int mode)
{
    int aine_leitud;

    while (1)
    {
		if(mode == 0)
		{
			printf("Sisestage õppeaine nimi: ");
			scanf("%s", aine);
		}
		
        aine_leitud = 0;

        for (int i = 0; i < hindete_arv; i++)
        {
            if (strcasecmp(aine, (hinded + i)->aine) == 0)
            {
                aine_leitud = 1;
                break;
            }
        }

        if (aine_leitud)
        {
            break; // väljub tsüklist, kui õppeaine leiti
        }

			printf("Viga! Õppeainet '%s' pole saadaval.\n", aine);

                if (mode == 1)
				{
					exit(1);
				}

    }
}


/**
 * Description: Salvestab ja/või väljastab filtreeritud hinded vastavalt kasutaja valikule.
 *
 * Parameters:   failinimi - millest fali loeb
 * 				 aine - valitud aine
 * 				 opilased[] - andme klass
 * 				 hinded[] - andme klass
 * 				 hindete_arv - mitu õpelasi on 2 failis
 * 		   	     mode - teksti näitamis režiim
 * 		   	     valik - kus näidata vastus
 * 
 * Return:       none
 */
void salvestaJaPrindiFiltreeritudHinded(const char *failinimi, char aine[], 
	Opilane opilased[], int opilaste_arv, HinneKirje hinded[], int hindete_arv, int mode, int valik)
{
    
    do
    {
		if(mode == 0)
		{
			printf("Valige tegevus:\n");
			printf("1. Salvesta andmed ainult faili\n");
			printf("2. Väljasta andmed ainult terminalis\n");
			printf("3. Salvesta ja väljasta \n");
			scanf("%d", &valik);
		}
        
        if (valik != 1 && valik != 2 && valik != 3)
        {
            printf("Vale sisend. Palun sisestage number.\n");
            // Puhasta puhvrid, et vältida lõputut tsüklit
            while (getchar() != '\n')
                continue;
            valik = 0; // Määra vaikimisi väärtus
        }
        
    } while (valik != 1 && valik != 2 && valik != 3);

    FILE *valjundFail = NULL;

    if (valik == 1 || valik == 3)
    {
        valjundFail = fopen(failinimi, "w");

        if (valjundFail == NULL)
        {
            printf("Viga väljundfaili avamisel.\n");
            exit(1);
        }
    }
    
	if(valik == 0)
	{
			printf("Õpilased, kes on ainet '%s' lõpetanud:\n", aine);
	}
		
    int leitud = 0; // Kontrollimuutuja

    for (int j = 0; j < hindete_arv; j++)
    {
        if (strcasecmp((hinded + j)->aine, aine) == 0)
        {
            leitud = 0;
            for (int i = 0; i < opilaste_arv; i++)
            {
                if (strcmp((opilased + i)->isikukood, (hinded + j)->isikukood) == 0)
                {
                    leitud = 1;
                    if(valik != 1)
					{	

						printf("\nÕpilase kood: %ls\n", (opilased + i)->opilase_kood);
						printf("Nimi: %s %s\n", (opilased + i)->eesnimi, 
												(opilased + i)->perekonnanimi);
						printf("Isikukood: %s\n", (opilased + i)->isikukood);
						printf("Aine: %s\n", (hinded + j)->aine);
						printf("Hinne: %d (%s)\n", (hinded + j)->hinne, 
										saaHinneteKirjeldus((hinded + j)->hinne));
					}
                    
                    if(valik != 2)
                    {
						fprintf(valjundFail, "\nÕpilase kood: %ls\n", 
												(opilased + i)->opilase_kood);
						fprintf(valjundFail, "Nimi: %s %s\n", (opilased + i)->eesnimi,
												(opilased + i)->perekonnanimi);
						fprintf(valjundFail, "Isikukood: %s\n", (opilased + i)->isikukood);
						fprintf(valjundFail, "Aine: %s\n", (hinded + j)->aine);
						fprintf(valjundFail, "Hinne: %d (%s)\n", 
						(hinded + j)->hinne, saaHinneteKirjeldus((hinded + j)->hinne));

						fprintf(valjundFail, "\n");
						break;
					}
                }
            }

            if (!leitud)
            {
                printf("Andmed puuduvad õpilasele isikukoodiga %s\n", 
													(hinded + j)->isikukood);
            }
        }
    }

    if (valik != 2)
    {
        fclose(valjundFail);
        
    }
}
