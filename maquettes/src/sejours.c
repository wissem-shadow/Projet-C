#include <gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sejours.h"
 
void affichage_sejours (GtkWidget *treeview3) {

GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;

	char hotel[30];
	char ville[30];
	char categorie[30];


FILE *f ;
store =NULL ;
store=gtk_tree_view_get_model(treeview3);
if (store == NULL)
{
           

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("hotel",renderer,"text",HOTELL,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("ville",renderer,"text",VILLEE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("categorie",renderer,"text",CATEGORIEE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3),column);
}


store =gtk_list_store_new(NUM_COLLLL,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING );



            f=fopen("sejours.txt","r");
            if (f!=NULL){
		while (fscanf(f,"%s %s %s",hotel,ville,categorie)!=EOF) {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set
            (store,&iter,HOTELL,hotel,VILLEE,ville,CATEGORIEE,categorie,-1);
		}
		}
		fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(treeview3),GTK_TREE_MODEL(store));
            g_object_unref(store);
	    
}
