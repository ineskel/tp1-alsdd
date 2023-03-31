#ifndef QUESTION_8_H_INCLUDED
#define QUESTION_8_H_INCLUDED

struct node* SortedMergestate(struct node *a, struct node *b)
{
	struct node *result = NULL;
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;

	if (a->avion.state <= b->avion.state)
	{
		result = a;
		result->next = SortedMergestate(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMergestate(a, b->next);
	}

	return result;
}

void MergeSortstate(struct node **headRef)
{
	struct node *head = *headRef;
	struct node * a;
	struct node * b;

	// Base case -- length 0 or 1
	if ((head == NULL) ||
		(head->next == NULL))
	{
		return head;
	}

	FrontBackSplit(head, &a, &b);

	MergeSortstate(&a);
	MergeSortstate(&b);

	*headRef = SortedMergestate(a, b);
}

void split(struct node **head, struct node **AList, struct node **DList, struct node **MList)
{
	*AList = NULL;
	*DList = NULL;
	*MList = NULL;

	struct node *current_sublist = NULL;
	struct node *sublist_tail = NULL;

	struct node *current_node = *head;
	while (current_node != NULL)
	{
		if (current_sublist == NULL || current_node->avion.state != current_sublist->avion.state)
		{
			if (sublist_tail != NULL)
			{
				sublist_tail->next = NULL;
			}

			current_sublist = current_node;

			switch (current_node->avion.state)
			{
				case 'A':
					*
					AList = current_node;
					break;
				case 'D':
					*
					DList = current_node;
					break;
				case 'M':
					*
					MList = current_node;
					break;
			}
		}

		sublist_tail = current_node;
		current_node = current_node->next;
	}

	if (sublist_tail != NULL)
	{
		sublist_tail->next = NULL;
	}
}

void scinder(struct node **head, struct node **AList, struct node **DList, struct node **MList)
{
	MergeSortstate(head);
	split(head, AList, DList, MList);
	printf("\nListe des avions atterits: \n");
	if (*AList == NULL)
	{
		printf("Aucune avion est atterit pour le moment.\n\n");
	}
	else
	{
		affichage(*AList);
	}

	printf("\nListe des avions decolles: \n");
	if (*DList == NULL)
	{
		printf("Aucune avion est decolle pour le moment.\n\n");
	}
	else
	{
		affichage(*DList);
	}

	printf("\nListe des avions en maintenance: \n");
	if (*MList == NULL)
	{
		printf("Aucune avion est en maintenance pour le moment.\n\n");
	}
	else
	{
		affichage(*MList);
	}
}


#endif	// QUESTION_8_H_INCLUDED
