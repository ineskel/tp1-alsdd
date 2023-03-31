#ifndef MACHINE_ABSTRAITE_H_INCLUDED
#define MACHINE_ABSTRAITE_H_INCLUDED

// Definition des structures pour les dates et les avions
struct record_date
{
	int day;
	int month;
	int year;
};

struct record_avion
{
	char code[100];
	float capacity;
	char state;
	struct record_date date;
	int nb_vols;
};

struct node
{
	int data;
	struct record_avion avion;
	struct node * next; /*Address*/
}*head;

void Allouer(struct node **ptr)
{
	*ptr = (struct node *) malloc(sizeof(struct node));
	/*ptr->next=NULL; */
}

void Liberer(struct node *ptr)
{
	free(ptr);
}

struct node* Suivant(struct node *ptr) /*retourner l'adresse du prochain élément contenu dans le maillon P*/
{
	return (ptr->next);
}

int Valeur(struct node *P) /*retourner l'information contenue dans le maillon P*/
{
	return (P->data);
}

void Aff_val(struct node *P, struct record_avion avion) /*affecter l'information au champ vam du maillon P*/
{
	P->avion = avion;
}

void Aff_adr(struct node *P, struct node *Q) /*lier P à une autre adresse*/
{
	P->next = Q;
}

/*
 *Display entire list
 */
void traverseList()
{
	struct node * temp;

	/*Return if list is empty*/
	if (head == NULL)
	{
		printf("List is empty.");
		return;
	}

	temp = head;
	while (temp != NULL)
	{
		printf("%d --> ", Valeur(temp)); /*Print data of current node*/
		temp = Suivant(temp); /*Move to next node*/
	}

	printf("NULL");
}

/*----Fonction qui calcule la taille de la liste----*/
int countNodes()
{
	int count = 0;
	struct node * temp;

	temp = head;

	while (temp != NULL)
	{
		count++;
		temp = Suivant(temp);
	}

	return count;
}

/*-----------Fonction qui calcule le nombre d'occurence------------------*/

int nombreOccurrencesElement(int x)
{
	int nbOccurrences = 0;
	struct node * temp;
	temp = head;
	x = Valeur(head);
	while (temp != NULL)
	{
		if ((Valeur(temp) == x))
			nbOccurrences++;
		temp = Suivant(temp);
	}

	return nbOccurrences;
}

int maxOccurence()
{
	struct node *p = head;

	int max = -1;
	int res;
	while (p != NULL)
	{
		/*counting the frequency of current element:*/
		/*p->data*/
		struct node *q = p->next;
		int count = 1;
		while (q != NULL)
		{
			if (p->data == q->data)
				count++;
			q = q->next;
		}

		/*if current counting is greater than max*/
		if (max < count)
		{
			res = p->data;
			max = count;
		}

		p = p->next;
	}

	return res;
}

//-----------------------------------
// Procédure Fusion de deux LLC
//----------------------------------
void Fusionner(struct node *tete1, struct node *tete2, struct node **tete3)
{
	struct node *dernier, *nouveau, *p, *t1 = tete1, *t2 = tete2;
	*tete3 = NULL;
	while (t1 != NULL && t2 != NULL)
	{
		Allouer(&nouveau);	//nouveau=malloc(sizeof(struct node));
		Aff_adr(nouveau, NULL);	//nouveau->next=NULL;
		if (Valeur(t1) < Valeur(t2))	//(t1->data < t2->data)
		{
			nouveau->data = t1->data;
			t1 = Suivant(t1);	//t1=t1->next;
		}
		else
		{
			nouveau->data = t2->data;
			t2 = Suivant(t2);
		}	//t2=t2->next;}

		if (*tete3 == NULL)
		{ *tete3 = nouveau;
		}
		else
		{
			Aff_adr(dernier, nouveau);
		}	//dernier->next=nouveau;}

		dernier = nouveau;
	}

	if (t1 != NULL)
	{
		p = t1;
	}
	else
	{
		p = t2;
	}

	while (p != NULL)
	{
		Allouer(&nouveau);	//nouveau=malloc(sizeof(struct node));
		Aff_adr(nouveau, NULL);	//nouveau->next=NULL;
		nouveau->data = p->data;
		Aff_adr(dernier, nouveau);	//dernier->next=nouveau;
		dernier = nouveau;
		p = Suivant(p);	//p=p->next;
	}

	printf("Fusion terminee avec succes\n");
}

//--------------------------------
// Procédure affichage d'une LLC
//----------------------------
void Afficher(struct node *tete)
{
	struct node *p = tete;
	printf("Tete->");
	while (p != NULL)
	{
		printf("(%d)->", Valeur(p));
		p = p->next;
	}

	printf("Fin\n");
}

//----------------------------------
//Procédure éclatement d'une LLC
//---------------------------------
void Eclater(struct node *tete, struct node **T4, struct node **T5)
{
	struct node *nouveau, *p = tete;
	*T4 = NULL; *T5 = NULL;
	while (p != NULL)
	{
		Allouer(&nouveau);	//nouveau=malloc(sizeof(struct node));
		nouveau->data = p->data;
		p = Suivant(p);	//p->next;
		if (Valeur(nouveau) < 0)
		{
			Aff_adr(nouveau, *T4);	//nouveau->next=*T4;
			*T4 = nouveau;
		}
		else
		{
			Aff_adr(nouveau, *T5);	//    nouveau->next=*T5;
			*T5 = nouveau;
		}
	}

	printf("Eclatement termine avec succes\n");
}


#endif	// MACHINE_ABSTRAITE_H_INCLUDED
