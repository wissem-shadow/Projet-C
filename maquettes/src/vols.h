
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

enum
{ DEPART,
DESTINATION,
DATEDEPART,
DATERETOUR,
NUM_COLL
};
void affichage_vols (GtkWidget *treeview3) ;
void recherchervols(char depart[300]);
