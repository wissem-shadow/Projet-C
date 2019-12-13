#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "cordvoiture.h"

void afficher_coord3 (GtkWidget *treeview3,char t[])
{
	
  GtkTreeViewColumn   *column;
  GtkCellRenderer     *renderer;
  GtkListStore  *store;
  GtkTreeIter    iter;

	char pays[30];
	char ville[30];
	char agence[30];
	char modele[30];


FILE *f ;
store =NULL ;
store=gtk_tree_view_get_model(treeview3);
if (store == NULL)
{
           

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("pays",renderer,"text",PAYSS1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("ville",renderer,"text",VILLE1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("agence",renderer,"text",AGENCE1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("modele",renderer,"text",MODELE1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);
}


store =gtk_list_store_new(NUM_COLLL1,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );

	f = fopen("voiture.txt", "r");
	
   	if (f!=NULL)
{
     while (fscanf(f,"%s %s %s %s",pays,ville,agence,modele)!=EOF)
{ 	
	if ((strcmp(pays,t)==0))
{
gtk_list_store_append (store, &iter);
  gtk_list_store_set
            (store,&iter,PAYSS1,pays,VILLE1,ville,AGENCE1,agence,MODELE1,modele,-1);
}
}
fclose(f);
   gtk_tree_view_set_model (GTK_TREE_VIEW (treeview3),GTK_TREE_MODEL (store));
   g_object_unref (store);
}}
