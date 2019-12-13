#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hist_hotels.h"

void supprimer_hist_hotels (char nom1[] ){


hist a;
FILE *f;
FILE *f1 ;
f1 =NULL;
f=fopen("paiementhotels.txt","r+") ;
f1=fopen("agents1.txt","a");
if (f!= NULL)
{

while (fscanf(f,"%s %s %s %s %s %s %s %s %s \n",a.nom,a.pays,a.nbe,a.prixch,a.nbch,a.adultes,a.enfants,a.bebes)!=EOF) {
if (strcmp(nom1 ,a.nom)!=0)
{


fprintf(f1,"%s %s %s %s %s %s %s %s \n",a.nom,a.pays,a.nbe,a.prixch,a.nbch,a.adultes,a.enfants,a.bebes);

}
}
}


fclose(f);
fclose(f1);
remove("paiementhotels.txt");
rename("agents1.txt","paiementhotels.txt");

}
void afficher_hist_hotels (GtkWidget *liste)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store ;


 

char nom[20];
char pays [20];
char nbe [10] ;
char prixch[20];
char nbch[77];
char adultes[20];
char enfants[10] ;
char bebes[20];

store=NULL;

FILE *f1 ;

store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nom",renderer,"text",NOM111,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

            renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("pays",renderer,"text",PAYS111,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nbe",renderer,"text",NBE,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	    
             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("prixch",renderer,"text",PRIXCH,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	     renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("nbch",renderer,"text",NBCH,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	       renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("adultes",renderer,"text",ADULTES,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("enfants",renderer,"text",ENFANTS,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	    
             renderer=gtk_cell_renderer_text_new ();
            column=gtk_tree_view_column_new_with_attributes ("bebes",renderer,"text",BEBES,NULL);
            gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	     
}


	    store =gtk_list_store_new(NUM_COL111,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING ,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING );



            f1=fopen("paiementhotels.txt","r");
            if (f1!=NULL){
		while (fscanf(f1,"%s %s %s %s %s %s %s %s \n",nom,pays,nbe,prixch,nbch,adultes,enfants,bebes)!=EOF) {
            gtk_list_store_append(store,&iter);
            gtk_list_store_set
            (store,&iter,NOM111,nom,PAYS111,pays,NBE,nbe,PRIXCH,prixch,NBCH,nbch,ADULTES,adultes,ENFANTS,enfants,BEBES,bebes,-1);
		}
		}
		fclose(f1);
            gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
            g_object_unref(store);
}


void modifier_hist_hotels (hist a1)
{
payer_hotels=create_payer_hotels();
gtk_widget_show(payer_hotels);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"valider_modifier_payer_hotels")));
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8;
GtkWidget *input9;
char nomn[300];
char paysn[300];
char nben[300];
char prixn[300];
char nbn[300];
char adultesn[300];
char enfantsn[300];
char bebesn[300];
char totn[300];

char nom[300];
char pays[300];
char nbe[300];
char prix[300];
char nb[300];
char adultes[300];
char enfants[300];
char bebes[300];
char tot[300];
int a,b;
a=atoi(prix);
b=atoi(nb);
input1=lookup_widget(button,"nomh");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(button,"paysh");
strcpy(pays,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(button,"nbeh");  
strcpy(nbe,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(button,"prixh");
strcpy(prix,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(button,"nbh");
strcpy(nb,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(button,"adultesh");
strcpy(adultes,gtk_entry_get_text(GTK_ENTRY(input6)));
input7=lookup_widget(button,"enfantsh");
strcpy(enfants,gtk_entry_get_text(GTK_ENTRY(input7)));
input8=lookup_widget(button,"bebesh");  
strcpy(bebes,gtk_entry_get_text(GTK_ENTRY(input8)));
a=b*a;
sprintf(tot,a);
input9=lookup_widget(button,"toth");
strcpy(tot,gtk_entry_get_text(GTK_ENTRY(input9)));



FILE *f;
FILE *tmp;
f=fopen("paiementhotels.txt","a1");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s \n",nomn,paysn,nben,prixn,nbn,adultesn,enfantsn,bebesn,totn)!=EOF)
{
if (strcmp(nom,nomn)!=0)
fprintf(tmp,"%s %s %s %s %s %s %s %s %s \n",nom,pays,nbe,prix,nb,adultes,enfants,bebes,tot);
else 
fprintf(tmp,"%s %s %s %s %s %s %s %s %s \n",nomn,paysn,nben,prixn,nbn,adultesn,enfantsn,bebesn,totn);
}
fclose(f); 
fclose(tmp);
rename("paiementhotels.tmp","paiementhotels.txt");
gtk_widget_destroy(payer_hotels);

}
