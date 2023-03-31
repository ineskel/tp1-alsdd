#ifndef QUESTION_2_H_INCLUDED
#define QUESTION_2_H_INCLUDED

void verif_av_ds_aero(struct node *liste_avions)
{
	//procédure qui vérifie si l'av se trv dans l'aéroport
	struct node *temp = liste_avions;
	int n = 1;
	bool trv = false;
	char a1 = 'A', m1 = 'M';
	char randomcode[100];
	printf("Veuillez entrer le code de l'avion dont vous cherchez : ");
	scanf("%s", randomcode);

	while (temp != NULL && trv != true)
	{
		if (strcmp(temp->avion.code, randomcode) == 0)
		{
			if ((temp->avion.state == a1) || (temp->avion.state == m1))
			{
				printf("1\nL'avion est dans l'aeroport. \n");
				trv = true;
			}
			else
			{
				printf("-1\nL'avion existe dans la liste mais il n'est pas dans l'aeroport. \n");
				trv = true;
			}
		}

		temp = temp->next;
	}

	if (trv == false)
	{
		printf("Cet avion n'a pas ete introduit dans la liste.\n");
	}
}

#endif // QUESTION_2_H_INCLUDED
