#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>


enum
{ NOM111,
PAYS111,
NBE,
PRIXCH,
NBCH,
ADULTES,
ENFANTS,
BEBES,

NUM_COL111
};

typedef struct hist 
{
char nom[20];
char pays [20];
char nbe [10] ;
char prixch[20];
char nbch[77];
char adultes[20];
char enfants[10] ;
char bebes[20];


} hist ;


void supprimer_hist_hotels (char nom1[] );
void afficher_hist_hotels (GtkWidget *liste) ;

//void modifier_reclamation (agents a1);
