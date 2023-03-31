#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct record_date {
  int day;
  int month;
  int year;
};

struct record_avion {
  char code[100];
  float capacity;
  char state;
  struct record_date date;
  int nb_vols;
};   

struct node {
  struct record_avion avion;
  struct node * next; 
}* head, *liste_avions;



int main() 
   {
       int nb,i;
       char av[100];
       bool trv=false;

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

     atr_node=liste_avions;      
     printf("atchou code ta3 l'avion:");
     scanf(" %s",&av);
     while (atr_node!=NULL && trv!=true)
         {
            printf(" %s",atr_node->avion.code);
            if (strcmp(atr_node->avion.code,av)==0)  
               {
                 printf("av trv hh, code: %s",atr_node->avion.code);
                 trv=true;
               }
             atr_node=atr_node->next;  
         }
      if (trv!=false) 
         {
           printf("no av, -1");
         }   
         return 0;            
      }
     
