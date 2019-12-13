#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "coordonnees.h"

void afficher_coord (GtkWidget *treeview2,char t[])
{
	
  GtkTreeViewColumn   *column;
  GtkCellRenderer     *renderer;
  GtkListStore  *store;
  GtkTreeIter    iter;

char nom [100];
char pays[100] ;
char nbr_etoiles [10];
char prix [10];
FILE *f;
store=NULL;
store=gtk_tree_view_get_model(treeview2);
	if (store==NULL) {

		 renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nom",renderer,"text",NOM1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("",renderer,"text",PAYS1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);

           renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nbr_etoiles",renderer,"text",NBRETOILE1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("prix",renderer,"text",PRIXCHAMBRE1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2),column);

	
                
	}
store =gtk_list_store_new(NUM_COL1,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING );

	f = fopen("hotel.txt", "r");
	
   	if (f!=NULL)
{
     while (fscanf(f,"%s %s %s %s",nom,pays,nbr_etoiles,prix)!=EOF)
{ 	
	if ((strcmp(nom,t)==0))
{
gtk_list_store_append (store, &iter);
  gtk_list_store_set
            (store,&iter,NOM1,nom,PAYS1,pays,PRIXCHAMBRE1,prix,NBRETOILE1,nbr_etoiles,-1);
}
}
fclose(f);
   gtk_tree_view_set_model (GTK_TREE_VIEW (treeview2),GTK_TREE_MODEL (store));
   g_object_unref (store);
}}
