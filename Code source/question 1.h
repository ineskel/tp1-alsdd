#ifndef QUESTION_1_H_INCLUDED
#define QUESTION_1_H_INCLUDED

float verif_capacity()
{
	float cap;
	bool verify = false;
	while (!verify)
	{
		if (scanf("%f", &cap) == 1)
		{
			verify = true;
		}
		else
		{
			printf("Erreur lors de la lecture, veuillez entrer un nombre reel.\n");
			printf("  Entrez de nouveaux la capacite de l'avion : ");
			while (getchar() != '\n') {}	// Cette boucle permet de vider le buffer pour eviter une boucle infinie
		}
	}

	return cap;
}

int verif_nb_avions()
{
	float nbavions;
	bool verify = false;
	while (!verify)
	{
		if (scanf("%f", &nbavions) == 1)
		{
			verify = true;
			nbavions = (int) nbavions;
		}
		else
		{
			printf("Erreur lors de la lecture, veuillez entrer un nombre entier.\n");
			printf("  Entrez de nouveaux le nombre d'avions : ");
			while (getchar() != '\n') {}	// Cette boucle permet de vider le buffer pour eviter une boucle infinie
		}
	}

	return nbavions;
}

int verif_nb_vols()
{
	float nbvols;
	bool verify = false;
	while (!verify)
	{
		if (scanf("%f", &nbvols) == 1)
		{
			verify = true;
			nbvols = (int) nbvols;
		}
		else
		{
			printf("Erreur lors de la lecture, veuillez entrer un nombre entier.\n");
			printf("  Entrez de nouveaux le nombre de vols de l'avion : ");
			while (getchar() != '\n') {}	// Cette boucle permet de vider le buffer pour eviter une boucle infinie
		}
	}

	return nbvols;
}

int func_verif_date(int borne1, int borne2, char str[50])
{
	float number;
	bool verify = false;
	while (!verify)
	{
		if (scanf("%f", &number) == 1 && (number >= borne1 && number <= borne2))
		{
			verify = true;
			number = (int) number;
		}
		else
		{
			printf("Erreur lors de la lecture, veuillez entrer un nombre entier entre %d et %d.\n", borne1, borne2);
			printf("  Entrez de nouveaux %s de fabrication l'avion : ", str);
			while (getchar() != '\n') {}	// Cette boucle permet de vider le buffer pour eviter une boucle infinie
		}
	}

	return number;
}

int verif_date(char letter)
{
	int d;
	int B1, B2;
	char text[50];
	switch (letter)
	{
		case 'd':
			B1 = 1;
			B2 = 31;
			strcpy(text, "le jour");
			break;
		case 'm':
			B1 = 1;
			B2 = 12;
			strcpy(text, "le mois");
			break;
		case 'y':
			B1 = 1903;
			B2 = 2023;
			strcpy(text, "l'annee");
			break;
	}

	return func_verif_date(B1, B2, text);
}

char verif_state()
{
	char state;
	bool verify = false;
	while (!verify)
	{
		if (scanf(" %c", &state) == 1 && ((toupper(state) == 'M') || (toupper(state) == 'A') || (toupper(state) == 'D')))
		{
			verify = true;
		}
		else
		{
			printf("Erreur lors de la lecture, veuillez entrer un charactere (D s'il a decolle, A s'il a atterrit, M s'il est en maintenance technique.)\n");
			printf("  Entrez de nouveaux l'etat de l'avion : ");

			while (getchar() != '\n') {}	// Cette boucle permet de vider le buffer pour eviter une boucle infinie
		}
	}

	return toupper(state);
}

void remplir(struct node **liste_avions)
{
	printf("Entrez le nombre des avions : ");
	int nb_avions;
	nb_avions = verif_nb_avions();

	// Boucle de lecture des données des avions
	for (int i = 1; i <= nb_avions; i++)
	{
		printf("\n- Avion %d :\n", i);

		// Allouer la memoire pour un nouveau node
		struct node *new_node = malloc(sizeof(struct node));
		new_node->next = NULL;

		printf("  Entrez le code de l'avion : ");
		scanf("%s", &new_node->avion.code);
		printf("  Entrez la capacite de l'avion : ");
		new_node->avion.capacity = verif_capacity();
		printf("  Entrez l'etat de l'avion : ");
		new_node->avion.state = verif_state();
		printf("  Entrez la date de fabrication de l'avion : \n");
		printf("    Annee : ");
		new_node->avion.date.year = verif_date('y');
		printf("    Mois : ");
		new_node->avion.date.month = verif_date('m');
		printf("    Jour : ");
		new_node->avion.date.day = verif_date('d');
		printf("  Entrez le nombre des vols : ");
		new_node->avion.nb_vols = verif_nb_vols();

		// Add the new node to the list
		if (*liste_avions == NULL)
		{
			// First node
            *liste_avions = new_node;
		}
		else
		{
			struct node *current_node = *liste_avions;
			while (current_node->next != NULL)
			{
				current_node = current_node->next;
			}

			current_node->next = new_node;
		}
	}

	printf("\nla liste a ete remplie avec succes!\n\n\n");
}

void affichage(struct node *liste_avions)
{
	// Boucle d'affichage des données des avions
	struct node *current_node = liste_avions;
	int i = 1;
	while (current_node != NULL)
	{
		printf("\n- Avion %d :\n", i);
		printf("  Code : %s\n", current_node->avion.code);
		printf("  Capacite : %f\n", current_node->avion.capacity);
		printf("  Etat : %c\n", toupper(current_node->avion.state));
		printf("  Date de fabrication : %d-%d-%d\n", current_node->avion.date.day, current_node->avion.date.month, current_node->avion.date.year);
		printf("  Nombre de vols : %d\n", current_node->avion.nb_vols);
		printf("\n");
		printf("\n");

		current_node = current_node->next;
		i++;
	}
}

#endif // QUESTION_1_H_INCLUDED
