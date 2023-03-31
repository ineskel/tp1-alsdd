#ifndef QUESTION_5_H_INCLUDED
#define QUESTION_5_H_INCLUDED

void compteur_avions(struct node *liste_avions)
{
	int nb_decolles = 0;
	int nb_atterits = 0;
	struct node *current_node = liste_avions;

	while (current_node != NULL)
	{
		if (current_node->avion.state == 'A')
		{
			nb_atterits++;
		}

		if (current_node->avion.state == 'D')
		{
			nb_decolles++;
		}

		current_node = Suivant(current_node);
	}

	printf("Nombre d'avions atteris : %d\n", nb_atterits);
	printf("Nombre d'avions decolles : %d\n\n\n", nb_decolles);
}

#endif // QUESTION_5_H_INCLUDED
