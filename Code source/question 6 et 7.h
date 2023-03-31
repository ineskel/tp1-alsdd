#ifndef QUESTION_6_ET_7_H_INCLUDED
#define QUESTION_6_ET_7_H_INCLUDED

void min_vols_less10(struct node *liste_avions)
{
	struct node *current_node = liste_avions;
	int i = 0;
	printf("Entrez le nombre minimal de vols: ");
	int min;
	scanf("%d", &min);
	while (current_node != NULL)
	{
		if (current_node->avion.date.year > 2013 && current_node->avion.nb_vols >= min)
		{
			i++;
			if (i == 1)
			{
				printf("Les avions qui ont assure %d vols au minimum et agees de moins de 10 ans sont: \n", min);
			}

			printf("-Avion %d :\n", i);
			printf("  Code : %s\n", current_node->avion.code);
			printf("  Nombre de vols : %d\n", current_node->avion.nb_vols);
			printf("  Annee de fabrication : %d\n", current_node->avion.date.year);
		}

		current_node = Suivant(current_node);
	}

	if (i == 0)
	{
		printf("Aucune des avions dans l'aeroport a assure ce nombre de vols et est agee de moins de 10 ans\n\n\n");
	}
}




void max_vols_less10(struct node *liste_avions)
{
	struct node *current_node = liste_avions;
	int i = 0;
	printf("Entrez le nombre maximal de vols: ");
	int max;
	scanf("%d", &max);
	while (current_node != NULL)
	{
		if (current_node->avion.date.year > 2013 && current_node->avion.nb_vols <= max)
		{
			i++;
			if (i == 1)
			{
				printf("Les avions qui ont assure %d vols au maximum et agees de moins de 10 ans sont: \n", max);
			}

			printf("-Avion %d :\n", i);
			printf("  Code : %s\n", current_node->avion.code);
			printf("  Nombre de vols : %d\n", current_node->avion.nb_vols);
			printf("  Annee de fabrication : %d\n", current_node->avion.date.year);
		}

		current_node = Suivant(current_node);
	}

	if (i == 0)
	{
		printf("Aucune des avions dans l'aeroport a assure ce nombre de vols et est agee de moins de 10 ans\n\n\n");
	}
}

#endif // QUESTION_6_ET_7_H_INCLUDED
