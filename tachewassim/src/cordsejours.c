#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "cordsejours.h"

void afficher_coord4 (GtkWidget *treeview4,char t[])
{
	
  GtkTreeViewColumn   *column;
  GtkCellRenderer     *renderer;
  GtkListStore  *store;
  GtkTreeIter    iter;
	char hotel[30];
	char ville[30];
	char categorie[30];


FILE *f ;
store =NULL ;
store=gtk_tree_view_get_model(treeview4);
if (store == NULL)
{
           

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("hotel",renderer,"text",HOTELL1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("ville",renderer,"text",VILLEE1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("categorie",renderer,"text",CATEGORIEE1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview4),column);
}


store =gtk_list_store_new(NUM_COLLLL1,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING );

            f=fopen("sejours.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s",hotel,ville,categorie)!=EOF) 
{ 	
	if (strcmp(ville,t)==0)
{
gtk_list_store_append (store, &iter);
  gtk_list_store_set
            (store,&iter,HOTELL1,hotel,VILLEE1,ville,CATEGORIEE1,categorie,-1);
}
}
fclose(f);
   gtk_tree_view_set_model (GTK_TREE_VIEW (treeview4),GTK_TREE_MODEL (store));
   g_object_unref (store);
}}
