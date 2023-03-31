#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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

int main()
   {
      struct node *liste_avions;
      liste_avions=malloc(sizeof (struct node));
      int nb,i;

      

      //remplir:
       printf("NB avions svp:\t");
       scanf("%d",&nb);
       for (i=0;i<=(nb-1);i++)
          {
             struct node *nv_node=malloc(sizeof(struct node));
             nv_node->next=NULL;

             printf("code avion svp:\t");
             scanf("%s",&nv_node->avion.code);
             printf("capacité svp:\t");
             scanf("%f",&nv_node->avion.capacity);
             printf("état svp:");
             scanf(" %c\t",&nv_node->avion.state);
             printf("jour de fabrication svp:\t");
             scanf(" %d",&nv_node->avion.date.day);
             printf("mois de fabrication svp:\t");
             scanf("%d",&nv_node->avion.date.month);
             printf("year of fab svp:\t");
             scanf("%d",&nv_node->avion.date.year);
             printf("entrez nb vols svp:\t");
             scanf("%d",&nv_node->avion.nb_vols);

             if (liste_avions == NULL) 
                {
                  liste_avions=nv_node;
                }
             else 
                {
                  struct node *ct_node=liste_avions;
                  while (ct_node->next!=NULL)
                      {
                        ct_node=ct_node->next;
                      }
                  ct_node->next=nv_node;
                }   
          }
//afficher:
      struct node *atr_node=liste_avions;
      int n=1;
      while (atr_node!=NULL)  
           {
             printf("avion num %d\n",n);
             printf("code: %s\n",atr_node->avion.code);
             printf("capacity: %f\n",atr_node->avion.capacity);
             printf("state: %c\n", atr_node->avion.state);
             printf("date de khedmation: %d/%d/%d\n",atr_node->avion.date.day,atr_node->avion.date.month,atr_node->avion.date.year);
             printf("nb vols: %d\n", atr_node->avion.nb_vols);

             atr_node=atr_node->next;
             n++;
           } 

      //supprimer:
      atr_node=liste_avions;
      while (atr_node!=NULL)
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
       





      return 0;

   }