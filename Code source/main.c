#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "machine abstraite.h"
#include "menu.h"
#include "question 1.h"
#include "question 2.h"
#include "question 3.h"
#include "question 4.h"
#include "question 5.h"
#include "question 6 et 7.h"
#include "question 8.h"




#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

int main()
{
	struct node *liste_avions = NULL;
	int option;
	bool liste_remplie = false;
	do {
		dessin();
		menu();
		printf("\n\n              Choisissez une option : ");
		scanf("%d", &option);
		system(CLEAR);

		switch (option)
		{
			case 1:
				if (!liste_remplie)
				{
					printf("\n-------------REMPLISSAGE DE LA LISTE D'AVIONS-------------\n\n");
					remplir(&liste_avions);
					liste_remplie = true;
				}
				else
				{
					printf("La liste des avions est deja remplie.\n");
				}

				break;
			case 2:
				if (liste_remplie)
				{
					printf("\n-------------VERIFICATIONS DES AVIONS DANS L'AEROPORT-------------\n\n");
					verif_av_ds_aero(liste_avions);
				}
				else
				{
					printf("La liste des avions n'a pas encore ete remplie.\n");
				}

				break;
			case 3:
				if (liste_remplie)
				{
					printf("\n-------------SUPPRESSION-------------\n\n");
                    liste_avions=supp_av(liste_avions);
                    printf("les avions plus ages que 20 ans et en maintenance ont ete supprimes avec succes! Voici la nouvelle liste: \n");
                    affichage(liste_avions);
				}
				else
				{
					printf("La liste des avions n'a pas encore ete remplie.\n");
				}

				break;
			case 4:
				if (liste_remplie)
				{
					printf("\n-------------TRI DES AVIONS PAR ORDRE DE CAPACITE-------------\n\n");
					MergeSortcapacity (&liste_avions);
					printf("La liste d'avions a ete triee par ordre de capacite avec succes! Voici la nouvelle liste: \n\n");
					affichage(liste_avions);
				}
				else
				{
					printf("La liste des avions n'a pas encore ete remplie.\n");
				}

				break;
			case 5:
				if (liste_remplie)
				{
					printf("\n-------------COMPTAGE DES AVIONS ATTERITS ET DECOLLES-------------\n\n");
					compteur_avions(liste_avions);
				}
				else
				{
					printf("La liste des avions n'a pas encore ete remplie.\n");
				}

				break;
			case 6:
				if (liste_remplie)
				{
					printf("\n-------------AVIONS QUI ONT ASSURE LE NOMBRE MAXIMAL DE VOLS ET AGES MOINS DE 10 ANS-------------\n\n");
					max_vols_less10(liste_avions);
				}
				else
				{
					printf("La liste des avions n'a pas encore ete remplie.\n");
				}

				break;
			case 7:
				if (liste_remplie)
				{
					printf("\n-------------AVIONS QUI ONT ASSURE LE NOMBRE MINIMAL DE VOLS ET AGES MOINS DE 10 ANS-------------\n\n");

					min_vols_less10(liste_avions);
				}
				else
				{
					printf("La liste des avions n'a pas encore ete remplie.\n");
				}

				break;

			case 8:
				if (liste_remplie)
				{
					printf("\n-------------SCINDER LA LISTE EN TROIS-------------\n\n");

					struct node *listeA = NULL;
					struct node *listeD = NULL;
					struct node *listeM = NULL;
					scinder(&liste_avions, &listeA, &listeD, &listeM);
				}
				else
				{
					printf("La liste des avions n'a pas encore ete remplie.\n");
				}

				break;
			case 0:
				printf("Au revoir !\n");
				break;
			default:
				printf("Option invalide.\n\n\n");
		}

		printf("Appuyez sur une touche pour retourner au menu...");
		getch();
		system(CLEAR);
	} while (option != 0);
	return 0;

	// Libération de la mémoire allouée pour la liste d'avions
	struct node *current_node = liste_avions;
	while (current_node != NULL)
	{
		struct node *next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	affichage(liste_avions);
}

