#ifndef QUESTION_3_H_INCLUDED
#define QUESTION_3_H_INCLUDED

struct node* supp_av(struct node *liste_avions)
{
    struct node *temp = liste_avions;
    struct node *prec = NULL;

    while (temp != NULL) {
        if (temp->avion.state == 'M' && temp->avion.date.year <= 2003) {
            if (prec == NULL) {
                struct node *actu = liste_avions;
                liste_avions = liste_avions->next;
                free(actu);
                temp = liste_avions;
            }
            else {
                struct node *actu = temp;
                temp = temp->next;
                prec->next = temp;
                free(actu);
            }
        }
        else {
            prec = temp;
            temp = temp->next;
        }
    }
    return liste_avions;
}


#endif // QUESTION_3_H_INCLUDED
