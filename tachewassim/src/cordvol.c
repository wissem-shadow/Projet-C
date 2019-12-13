#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "cordvol.h"

void afficher_coord1 (GtkWidget *treeview1,char t[])
{
	
  GtkTreeViewColumn   *column;
  GtkCellRenderer     *renderer;
  GtkListStore  *store;
  GtkTreeIter    iter;

	char depart[30];
	char destination[30];
	char datedepart[30];
	char dateretour[30];


FILE *f ;
store =NULL ;
store=gtk_tree_view_get_model(treeview1);
if (store == NULL)
{
           

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("depart",renderer,"text",DEPART1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("destination",renderer,"text",DESTINATION1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("datedepart",renderer,"text",DATEDEPART1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("dateretour",renderer,"text",DATERETOUR1,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1),column);
}


store =gtk_list_store_new(NUM_COLL1,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );


            f=fopen("vols.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s %s",depart,destination,datedepart,dateretour)!=EOF)
{ 	
	if ((strcmp(destination,t)==0))
{
gtk_list_store_append (store, &iter);
  gtk_list_store_set
            (store,&iter,DEPART1,depart,DESTINATION1,destination,DATEDEPART1,datedepart,DATERETOUR1,dateretour,-1);
}
}
fclose(f);
   gtk_tree_view_set_model (GTK_TREE_VIEW (treeview1),GTK_TREE_MODEL (store));
   g_object_unref (store);
}}
