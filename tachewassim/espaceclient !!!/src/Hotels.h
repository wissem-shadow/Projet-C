
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

enum
{ NOM,
NBRETOILE,
PAYS,
PRIXCHAMBRE,
NUM_COL
};


typedef struct hotel 
{
char nomHotel[20];
char pays [20];
char  nbrEtoiles [10];
char prix [10] ;


} hotel ;


void affichage_Hotels (GtkWidget *treeview3);
/*
void ajouter_Hotel(hotel h);
void supprimer_hotel (char nomHotel1[]);*/
