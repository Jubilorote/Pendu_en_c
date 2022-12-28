#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "lecturecaractere.h"
#define TAILLE_MAX 100

char lireCaractere();
void affiche(int tableau[], int tailleTableau);
void lire(char *chaine, int longueur);



int main (int argc , char *argv[])
{
    char mot[TAILLE_MAX]="";
    char chaine1[TAILLE_MAX]="";
    char chaine2[TAILLE_MAX]="";
    int *positionEntree=NULL;

                        FILE* fichier = NULL; // ouverture fichier
                        int caractereActuel= 0;
                        int nombreDeMot=-1;
                        fichier = fopen("listeDesMots.txt", "r"); /* Quand il se trouve dans le meme dossier du projet. Si sous dossier écrire le sous dossier/test.txt*/
                        int n = 0;//OK
                        int nombreAleatoire = 0;
                        if(fichier != NULL)
                        {
                            //On lit et on ecrit dans le fichier
                            // OK
                                do
                                {
                                caractereActuel=fgetc(fichier);
                                    if (caractereActuel='\n')
                                    {
                                        nombreDeMot++;// on compte le nombre de mot en comptant le nombre de retour a la ligne
                                    }
                                } while(fgets(chaine1, TAILLE_MAX, fichier)!= NULL);// jusqu'a la fin
                            rewind(fichier);
                            srand(time(NULL));
                            nombreAleatoire = (rand()%(nombreDeMot+1));

                            while (n < nombreAleatoire)
                            {
                               fgets(chaine2, TAILLE_MAX, fichier);
                               positionEntree = strchr(chaine2, '\n');
                               //printf("%s",chaine2); // On recherche l'"Entrée"
                                if (positionEntree != NULL) // Si on a trouvé le retour à la lign
                                {
                                   *positionEntree = '\0'; // On remplace ce caractère par \0
                                }// on lit juqu'au mot alea
                               //printf("%s\n",chaine2)
                               n++;
                            }

                            if(fgets(mot, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
                                {
                                    //printf("%s", mot); // On affiche la chaîne qu'on vient de lire
                                }
                        fclose(fichier);
                        }
                        else
                        {
                        printf("Le fichier n'a pu s'ouvrir");
                        }
                        //printf("nombreDeMot %d\n", nombreDeMot);



        char *motAffiche = NULL;
    /* initialisation mot OK */
        int vie = 10;
        printf("Bienvenue dans le Pendu !\n");
    /* le nombre de caractere du mot*/
        int longueurChaine = strlen(mot)-1;// calcul la longueur de mot
        //printf("la longueur de chaine est %d\n", longueurChaine);
        //printf("le mot est %s", mot);
        int p=0;
        /*while(p < longueurChaine)
        {
            caractereActuel=mot[p];
            //printf("%c",caractereActuel);
            p++;
        }
    /* le tableau mystere*/
        motAffiche = malloc(longueurChaine * sizeof(motAffiche)); // creation du tableau
        char stockLettre[TAILLE_MAX]; //Stock toute les lettre deja rentre
        char *lettreDoublon= NULL; // Renvoie NULL si aucun doublon

    /* On initialise le pointeur et verifie que la memoire est pris en charge */
        if ( motAffiche == NULL)
        {
            exit(0);
        }

    /* On initialise le tableau cache OK */
        int j = 0;
        for (j=0 ; j < longueurChaine ; j++)  // on met les * partout
        {
            motAffiche[j] = '*';
        }
        printf("%s\n",motAffiche); /* On affiche le mot cache */


        int compteur = 0;
        int m=0;

        while(vie > 0 && compteur < longueurChaine) /*ici a checker*/
        {
                int compteurVie= 0;
                printf("Il vous reste %d coups a jouer", vie); // donne le reste de coups
                printf(" %s\nProposez une lettre : ", motAffiche); // propose une lettre
                /* l utilisateur rentre une lettre OK*/
                char lettre = lireCaractere();               // donne une lettre OK
                /* On recherche la lettre presente dans le mot */
                //printf("vous avez choisi %c\n", lettre);
                /* On verifie que la lettre n a pas ete deja taper*/
                m++;
                lettreDoublon = strchr(stockLettre, lettre);
                if(lettreDoublon == NULL) // si pas de doublon
                {
                    int i = 0;
                    for(i= 0 ; i < longueurChaine; i++)
                    {
                        //printf("le nombre d iteration de la chaine est %d \n",i);
                        //printf("lettre controle %c\n", mot[i]);
                        if(mot[i] == lettre)
                        {
                            motAffiche[i] = mot[i];
                            compteur++;
                            /*printf("compteur est a %d\n", compteur);
                            printf("longueurChaine est a %d\n",longueurChaine);*/
                            //printf("le mot affiche est %s\n", motAffiche);
                            //printf("le mot a deviner est %s\n", mot);
                        }
                        else
                        {
                            compteurVie++;
                                if(compteurVie == longueurChaine)
                                {
                                    vie--;
                                }

                        }
                    }
                    stockLettre[m]=lettre;
                }
        }
        if(vie > 0)
        {
        printf("\nGagne le mot secret etait bien %s !",mot);
        }
        else{
            printf("\n--GAME OVER--\nLe mot etait %s!",mot);
        }
        free(motAffiche);
        return 0;

    }
