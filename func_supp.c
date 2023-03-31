#include <stdio.h>
#include <stdlib.h>

void supp_av(**liste_avions)
    {
        if (liste_avions == NULL)
            { 
                printf("La liste est vide.");
            }
        if (liste_avions!=NULL)
            {
                if (liste_avions->next->avion.state == 'M' && liste_avions->next->avion.date.year>=2003)
                    {
                        struct node *temp;
                        temp=liste_avions;
                        list_avions=liste_avions->next;
                        free(temp);
                    }
                else 
                    {
                        while (atr_node!=NULL) //supprimer maillon milieu
                            {
                                if ((atr_node->next->avion.date.year>=2003) && (atr_node->next->avion.state =='M')) //on teste si le prochain vérifie les conditions, et ce pour avoir l'emplacement mémoire de l'avion à supprimer.
                                  {
                                     struct node *actu;
                                     actu=atr_node->next; //on sauvegarde l'adresse de l'avion à supprimer
                                     atr_node->next=actu->next; //on relie le maillon sur lequel on pointe avec celui qui suit le maillon à supprimer
                                     free(actu);  //supprimer l'avion
                                  }
                                atr_node=atr_node->next;    
                            }           
                    }  
                if (atr_node->next->next == NULL && atr_node->next->avion.state == 'M' && atr_node->next->avion.date.year>=2003)
                    {
                        struct node *temp;
                        temp=atr_node->next;
                        free(temp);
                        atr_node->next=NULL;
                    }      
            }    
    }