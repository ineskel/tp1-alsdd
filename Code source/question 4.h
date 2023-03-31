#ifndef QUESTION_4_H_INCLUDED
#define QUESTION_4_H_INCLUDED

void FrontBackSplit(struct node *source,
	struct node **frontRef,
	struct node **backRef)
{
	struct node * fast;
	struct node * slow;
	slow = source;
	fast = source->next;

	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

struct node* SortedMergecapacity (struct node *a, struct node *b)
{
	struct node *result = NULL;
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;

	if (a->avion.capacity <= b->avion.capacity)
	{
		result = a;
		result->next = SortedMergecapacity (a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMergecapacity (a, b->next);
	}

	return result;
}



void MergeSortcapacity (struct node **headRef)
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

	MergeSortcapacity (&a);
	MergeSortcapacity (&b);

	*headRef = SortedMergecapacity(a, b);
}

#endif // QUESTION_4_H_INCLUDED
