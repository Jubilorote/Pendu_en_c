#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define TAILLE_MAX 40

char lireCaractere()      /* l utilisateur rentre sa lettre*/
{

    char caractere = 0;

    caractere = getchar(); // On lit le premier caract�re
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas d�j�

    // On lit les autres caract�res m�moris�s un � un jusqu'� l'\n (pour les effacer)
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caract�re qu'on a lu

}
void affiche(int tableau[], int tailleTableau)
{
    int i;

    for (i = 0 ; i < (tailleTableau) ; i++)
    {
        printf("%c\n", tableau[i]);
    }
}
void lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;
   // On lit le texte saisi au clavier
   if (fgets(chaine, longueur, stdin) != NULL)  // Pas d'erreur de saisie ?
   {
       positionEntree = strchr(chaine, '\n'); // On recherche l'"Entr�e"
       if (positionEntree != NULL) // Si on a trouv� le retour � la ligne
       {
           *positionEntree = '\0'; // On remplace ce caract�re par \0
       }
        // On renvoie 1 si la fonction s'est d�roul�e sans erreur
   }
}



/*

    FILE* fichier = NULL;
    int caractereActuel= 0;
    int nombreDeMot=0;
	fichier = fopen("listeDesMots.txt", "r"); /* Quand il se trouve dans le meme dossier du projet. Si sous dossier �crire le sous dossier/test.txt*/
	/*int i = 0;
	if(fichier != NULL)
	{
		//On lit et on ecrit dans le fichier
		rewind(fichier);
            do
            {
            caractereActuel=fgetc(fichier);
            if (caractereActuel='\n')
            {
                nombreDeMot++;
            }
            } while(caractereActuel != EOF);
        rewind(fichier);
        int motAlea = rand()%(nombreDeMot+1);
        while (i< motAlea)
        {
            caractereActuel=fgetc(fichier);
            if(caractereActuel='\n')
            {
                i++;
            }
        }
        fgets(*mot,TAILLE_MAX, fichier);

		fclose(fichier);
	}
	else
	{
	printf("Le fichier n'a pu s'ouvrir");
	}
	printf("nombreDeMot %d", nombreDeMot);

}
/*int comparerChaine(char chr1,char chr2, int longueur)
{
    int i=0;
    int compteur=0;
    for(i=0; i<longueur; i++)
    {
        if (chr1[i]==chr2[i])
        {
           compteur++;
        }
    }
   if (compteur==longeur)
   {
       return 0;
   }
   else{
        return 1;
   }
}*/

