#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <time.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "users.h"
#include "string.h"
#include "Hotels.h"
#include "vols.h"
#include "voiture.h"
#include "sejours.h"
#include "coordonnees.h"
#include "cordvoiture.h"
#include "cordsejours.h"
#include "cordvol.h"
#include "profile.h"
#include "rec.h"
#include "hist_hotels.h"
  GtkWidget *notebook1;
  GtkWidget *modifier_reclamation_client;
  GtkWidget *espace_client;
  GtkWidget *Reclamation;
  GtkWidget *Vols;
  GtkWidget *Location_voitures;
  GtkWidget *payer_hotels;
  GtkWidget *login;
  GtkWidget *Sejours;
  GtkWidget *Hotels;
  GtkWidget *Login;
  GtkWidget *treeview_vols_client;
  GtkWidget *treeview_hotels_client;
  GtkWidget *treeview_reclamation_client;
  GtkWidget *treeview_location_voiture_client;
GtkWidget *treeview_payer_hotels;
  GtkWidget *EspaceAgent;
  GtkWidget *treeview_sejours_client;
  GtkWidget *payer_vols;
  GtkWidget *payer_sejours;
  GtkWidget *payer_location_voitures;
  GtkWidget *profile;
  GtkWidget *Modification_des_informations;
  GtkWidget *historique_payer_hotels;
 GtkWidget *modifiier_payer_hotels;

	
/*void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *DEPART; 
gchar *DESTINATION;
gchar *DATEDEPART;
gchar *DATERETOUR;



GtkWidget *payer_hotels;*GtkWidget *current;
GtkTreeIter iter;
GtkWidget *L17;
GtkWidget *L18;
GtkWidget *L19;
GtkWidget *E6;
GtkWidget *E7;
GtkWidget *E8;
GtkWidget *E9;
GtkWidget *E10;
GtkWidget *E14;
GtkWidget *E15;
GtkWidget *E16;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&DEPART,1,&DESTINATION,2,&DATEDEPART,3,&DATERETOUR,-1);}
payer_vols = create_payer_vols();

E6=lookup_widget(payer_vols,"departv");
E7=lookup_widget(payer_vols,"destinationv");
E8=lookup_widget(payer_vols,"datedepartv");
E9=lookup_widget(payer_vols,"dateretourv");

gtk_entry_set_text(GTK_ENTRY(E6),DEPART);
gtk_entry_set_text(GTK_ENTRY(E7),DESTINATION);
gtk_entry_set_text(GTK_ENTRY(E8),DATEDEPART);
gtk_entry_set_text(GTK_ENTRY(E9),DATERETOUR);
gtk_widget_show (payer_vols);


}*/


/*void
on_Rechercher_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}*/

/*
void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


nomHotelEntry=lookup_widget(current,"entry2");
prixEntry=lookup_widget(current,"entry6");
PaysEntry=lookup_widget(current,"entry3");
nombre_etoiles=lookup_widget(current,"entry4");
chambres_disponibles=lookup_widget(current,"entry5");


gtk_entry_set_text(GTK_ENTRY(prixEntry),PRIX);
gtk_entry_set_text(GTK_ENTRY(nomHotelEntry),nom);
gtk_entry_set_text(GTK_ENTRY(PaysEntry),pays);
gtk_entry_set_text(GTK_ENTRY(nombre_etoiles),nbr);
gtk_entry_set_text(GTK_ENTRY(chambres_disponibles),chb);

}
*/

/* gboolean
on_Hotels_button_press_event           (GtkLabel        *label,
                                        gchar           *arg1,
                                        gpointer         user_data)
{*/

/*  return FALSE;
}
*/
/*
void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}
*/
/*
void
on_treeview4_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
}
*/

void
on_envoyer_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter_recmlamation;
espace_client=create_espace_client();
gtk_widget_show(espace_client);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"espace_client")));
//gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"window_ajouter_recmlamation")));
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;

char nom[300];
char prenom[300];
char cin[300];
char date[300];
char message[300];



input1=lookup_widget(button,"nomc");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(button,"prenomc");
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(button,"cinc");  
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(button,"datec");
strcpy(date,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(button,"messagec");
strcpy(message,gtk_entry_get_text(GTK_ENTRY(input5)));


FILE *f;
f=fopen("reclamation.txt","a+");
fprintf(f,"%s %s %s %s %s\n",nom,prenom,cin,date,message);
fclose(f); 

gtk_widget_show(Reclamation);
  treeview_hotels_client=lookup_widget(espace_client,"treeview_hotels_client");
  affichage_Hotels (treeview_hotels_client);
  treeview_vols_client=lookup_widget(espace_client,"treeview_vols_client");
  affichage_vols (treeview_vols_client);
  treeview_location_voiture_client=lookup_widget(espace_client,"treeview_location_voiture_client");
  affichage_voiture (treeview_location_voiture_client);
  treeview_sejours_client=lookup_widget(espace_client,"treeview_sejours_client");
  affichage_sejours (treeview_sejours_client);
 treeview_reclamation_client=lookup_widget(espace_client,"treeview_reclamation_client");
  afficher_reclamation (treeview_reclamation_client);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"window_ajouter_recmlamation")));
notebook1=lookup_widget(espace_client,"notebook1");
	gtk_notebook_set_current_page(notebook1,4);

}


void
on_mon_profil_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
/*espace_client=create_espace_client();
profile=create_profile();
gtk_widget_show(profile);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"espace_client")));

GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;

char nom[33];
char prenom[33];
char cin[33];
char date[33];
char tel[33];
char adresse[33];
char mdp[33];

affiche_profile(nom,prenom,cin,date,tel,adresse,mdp);
output1=lookup_widget(button,"nomp");
gtk_entry_set_text(GTK_ENTRY(output1),nom);
output2=lookup_widget(button,"prenomp");
gtk_entry_set_text(GTK_ENTRY(output2),prenom);
output3=lookup_widget(button,"sexep");  
gtk_entry_set_text(GTK_ENTRY(output3),cin);
output4=lookup_widget(button,"datep");
gtk_entry_set_text(GTK_ENTRY(output4),date);
output5=lookup_widget(button,"telp");
gtk_entry_set_text(GTK_ENTRY(output5),tel);
output6=lookup_widget(button,"adressep");
gtk_entry_set_text(GTK_ENTRY(output6),adresse);
output7=lookup_widget(button,"mdpp");
gtk_entry_set_text(GTK_ENTRY(output7),mdp);
*/
}


void
on_se_deconnecter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
espace_client=lookup_widget(button,"espace_client");
		gtk_widget_destroy(espace_client);
		Login=create_Login();
		gtk_widget_show(Login);
}


void
on_payerhotels_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
payer_hotels=create_payer_hotels();
gtk_widget_show(payer_hotels);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"payer_hotels")));
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8;
GtkWidget *input9;


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
f=fopen("paiementhotels.txt","a+");
fprintf(f,"%s %s %s %s %s %s %s %s %s \n",nom,pays,nbe,prix,nb,adultes,enfants,bebes,tot);
fclose(f); 

gtk_widget_destroy(payer_hotels);

}


void
on_login_button_clicked             (GtkButton	*objet_graphique,
                                        gpointer         user_data)
{
 GtkWidget *input1;  
  GtkWidget *input2;
  GtkWidget *output;
  GtkWidget *loginn; 

  




  char login[20];
  char password[20];
  int logg;
  
  input1=lookup_widget(objet_graphique,"identifiant_entry");
  strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));

  input2=lookup_widget(objet_graphique,"password_entry"); 
  strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));

  output=lookup_widget(objet_graphique,"output_login"); 
  logg=verifier(login,password);
switch(logg)
{
case 2:espace_client= create_espace_client();

  loginn =lookup_widget(objet_graphique,"Login");
  treeview_hotels_client=lookup_widget(espace_client,"treeview_hotels_client");
  affichage_Hotels (treeview_hotels_client);
  treeview_vols_client=lookup_widget(espace_client,"treeview_vols_client");
  affichage_vols (treeview_vols_client);
  treeview_location_voiture_client=lookup_widget(espace_client,"treeview_location_voiture_client");
  affichage_voiture (treeview_location_voiture_client);
  treeview_sejours_client=lookup_widget(espace_client,"treeview_sejours_client");
  affichage_sejours (treeview_sejours_client);
  treeview_reclamation_client=lookup_widget(espace_client,"treeview_reclamation_client");
  afficher_reclamation (treeview_reclamation_client);
  gtk_widget_hide (loginn);  
  gtk_widget_show (espace_client);

  break;
default :gtk_label_set_text(GTK_LABEL(output),"Verifier vos paramètres !!");

}
}




void
on_payervols_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
payer_vols=create_payer_vols();

gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"payer_vols")));
gtk_widget_show(payer_vols);
GtkWidget *input10;
GtkWidget *input11;
GtkWidget *input12;
GtkWidget *input13;
GtkWidget *input14;
GtkWidget *input15;
GtkWidget *input16;



char depart[300];
char destination[300];
char datedepart[300];
char dateretour[300];
char nbrvoy[300];
char classsou[300];
char prix[300];





input10=lookup_widget(button,"departv");
strcpy(depart,gtk_entry_get_text(GTK_ENTRY(input10)));
input11=lookup_widget(button,"destinationv");
strcpy(destination,gtk_entry_get_text(GTK_ENTRY(input11)));
input12=lookup_widget(button,"datedepartv");  
strcpy(datedepart,gtk_entry_get_text(GTK_ENTRY(input12)));
input13=lookup_widget(button,"dateretourv");
strcpy(dateretour,gtk_entry_get_text(GTK_ENTRY(input13)));
input14=lookup_widget(button,"nbvoyv");
strcpy(nbrvoy,gtk_entry_get_text(GTK_ENTRY(input14)));
input15=lookup_widget(button,"classouv");
strcpy(classsou,gtk_entry_get_text(GTK_ENTRY(input15)));
input16=lookup_widget(button,"prixv");
strcpy(prix,gtk_entry_get_text(GTK_ENTRY(input16)));




FILE *f;
f=fopen("paiementvols.txt","a+");
fprintf(f,"%s %s %s %s %s %s %s \n",depart,destination,datedepart,dateretour,nbrvoy,classsou,prix);
fclose(f); 

gtk_widget_destroy(payer_vols);


}


void
on_payerlocationvoitures_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
payer_location_voitures=create_payer_location_voitures();
gtk_widget_show(payer_location_voitures);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"payer_location_voitures")));

GtkWidget *input17;
GtkWidget *input18;
GtkWidget *input19;
GtkWidget *input20;
GtkWidget *input21;
GtkWidget *input22;
GtkWidget *input23;
GtkWidget *input24;
typedef struct

{

char payss[100];
char ville[100];
char agence[100];
char modele[100];
char prix[100];
char date[100];
char nombre[100];
char tot[100];    

}p;



p a;



input17=lookup_widget(button,"payl");
strcpy(a.payss,gtk_entry_get_text(GTK_ENTRY(input17)));

input18=lookup_widget(button,"vil");  
strcpy(a.ville,gtk_entry_get_text(GTK_ENTRY(input18)));
input19=lookup_widget(button,"agel");
strcpy(a.agence,gtk_entry_get_text(GTK_ENTRY(input19)));
input19=lookup_widget(button,"modl");
strcpy(a.modele,gtk_entry_get_text(GTK_ENTRY(input20)));
input21=lookup_widget(button,"pril");
strcpy(a.prix,gtk_entry_get_text(GTK_ENTRY(input21)));
input22=lookup_widget(button,"dpcl");
strcpy(a.date,gtk_entry_get_text(GTK_ENTRY(input22)));
input21=lookup_widget(button,"nbjl");
strcpy(a.nombre,gtk_entry_get_text(GTK_ENTRY(input21)));
input22=lookup_widget(button,"totl");
strcpy(a.tot,gtk_entry_get_text(GTK_ENTRY(input22)));




FILE *f;
f=fopen("paiementvoiture.txt","a+");
fprintf(f,"%s %s %s %s %s %s %s %s\n",a.payss,a.ville,a.agence,a.modele,a.prix,a.date,a.nombre,a.tot);
fclose(f); 

gtk_widget_destroy(payer_location_voitures);
}


void
on_modifier_clicked                    (GtkWidget     *button,
                                        gpointer         user_data)
{
//Modification_des_informations=create_Modification_des_informations();
//gtk_widget_show(Modification_des_informations);
//gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"Modification_des_informations")));


GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output8;
char nom[33];
char prenom[33];
char cin[33];
char date[33];
char tel[33];
char adresse[33];
char mdp[33];
char sexe[33];
affiche_profile(nom,prenom,sexe,date,tel,adresse,mdp,cin);
output1=lookup_widget(button,"nomp");
gtk_entry_set_text(GTK_ENTRY(output1),nom);
output2=lookup_widget(button,"prenomp");
gtk_entry_set_text(GTK_ENTRY(output2),prenom);
output3=lookup_widget(button,"sexep");  
gtk_entry_set_text(GTK_ENTRY(output3),sexe);
output4=lookup_widget(button,"datep");
gtk_entry_set_text(GTK_ENTRY(output4),date);
output5=lookup_widget(button,"telp");
gtk_entry_set_text(GTK_ENTRY(output5),tel);
output6=lookup_widget(button,"adressep");
gtk_entry_set_text(GTK_ENTRY(output6),adresse);
output7=lookup_widget(button,"mdpp");
gtk_entry_set_text(GTK_ENTRY(output7),mdp);

output8=lookup_widget(button,"cinp");
gtk_entry_set_text(GTK_ENTRY(output8),cin);
}



void
on_vols_button_enter                   (GtkButton       *button,
                                        gpointer         user_data)
{

char t[20];
        GtkWidget *treeview_vols_client;
        GtkWidget *input1;
	input1=lookup_widget(button,"rechercher_vols_entry");
	treeview_vols_client=lookup_widget(button,"treeview_vols_client");
	strcpy(t,gtk_entry_get_text(GTK_ENTRY(input1)));
	afficher_coord1 (treeview_vols_client,t);

}


void
on_hotels_button_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
char t[20];
        GtkWidget *treeview_hotels_client;
        GtkWidget *input1;
	input1=lookup_widget(button,"rechercher_hotel_entry");
	treeview_hotels_client=lookup_widget(button,"treeview_hotels_client");
	strcpy(t,gtk_entry_get_text(GTK_ENTRY(input1)));
	afficher_coord (treeview_hotels_client,t);
}


void
on_voitures_button_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char t[20];
        GtkWidget *treeview_location_voiture_client;
        GtkWidget *input1;
	input1=lookup_widget(button,"rechercher_voiture_entry");
	treeview_location_voiture_client=lookup_widget(button,"treeview_location_voiture_client");
	strcpy(t,gtk_entry_get_text(GTK_ENTRY(input1)));
	afficher_coord3 (treeview_location_voiture_client,t);
}


void
on_retourprofile_clicked               (GtkWidget      *button,
                                        gpointer         user_data)
{

profile=create_profile();
  Modification_des_informations =lookup_widget(button,"Modification_des_informations");
  gtk_widget_hide (Modification_des_informations);  
  gtk_widget_show (profile);

}


void
on_sejours_button_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
char t[20];
        GtkWidget *treeview_sejours_client;
        GtkWidget *input1;
	input1=lookup_widget(button,"rechercher_sejours_entry");
	treeview_sejours_client=lookup_widget(button,"treeview_sejours_client");
	strcpy(t,gtk_entry_get_text(GTK_ENTRY(input1)));
	afficher_coord4 (treeview_sejours_client,t);
}


void
on_payer_sejours_button_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
payer_sejours=create_payer_sejours();
gtk_widget_show(payer_sejours);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"payer_sejours")));

GtkWidget *input17;
GtkWidget *input18;
GtkWidget *input19;
GtkWidget *input20;
GtkWidget *input21;
GtkWidget *input22;

typedef struct p

{
char nomm[10];
char payss[10];
char categoriee[10];
char p[10];
char fl[10];
char to[10];
    

}p;



p a;



input17=lookup_widget(button,"noms");
strcpy(a.nomm,gtk_entry_get_text(GTK_ENTRY(input17)));
input18=lookup_widget(button,"payss");  
strcpy(a.payss,gtk_entry_get_text(GTK_ENTRY(input18)));
input19=lookup_widget(button,"nbes");
strcpy(a.categoriee,gtk_entry_get_text(GTK_ENTRY(input19)));
input19=lookup_widget(button,"prixs");
strcpy(a.p,gtk_entry_get_text(GTK_ENTRY(input20)));
input21=lookup_widget(button,"flexibilite");
strcpy(a.fl,gtk_entry_get_text(GTK_ENTRY(input21)));
input22=lookup_widget(button,"tots");
strcpy(a.to,gtk_entry_get_text(GTK_ENTRY(input22)));





FILE *f;
f=fopen("paiementsejours.txt","a+");
fprintf(f,"%s %s %s %s %s %s \n",a.nomm,a.payss,a.categoriee,a.p,a.fl,a.to);
fclose(f); 

gtk_widget_destroy(payer_sejours);
}





void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
espace_client=create_espace_client();
  profile =lookup_widget(button,"profile");
  gtk_widget_hide (profile);  
  gtk_widget_show (espace_client);
  treeview_hotels_client=lookup_widget(espace_client,"treeview_hotels_client");
  affichage_Hotels (treeview_hotels_client);
  treeview_vols_client=lookup_widget(espace_client,"treeview_vols_client");
  affichage_vols (treeview_vols_client);
  treeview_location_voiture_client=lookup_widget(espace_client,"treeview_location_voiture_client");
  affichage_voiture (treeview_location_voiture_client);
  treeview_sejours_client=lookup_widget(espace_client,"treeview_sejours_client");
  affichage_sejours (treeview_sejours_client);
}


void
on_profil_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
espace_client=create_espace_client();
profile=create_profile();
gtk_widget_show(profile);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"espace_client")));

GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output8;
char nom[33];
char prenom[33];
char sexe[33];
char date[33];
char tel[33];
char adresse[33];
char mdp[33];
char cin[33];
affiche_profile(nom,prenom,sexe,date,tel,adresse,mdp,cin);
output1=lookup_widget(button,"nomp");
gtk_entry_set_text(GTK_ENTRY(output1),nom);
output2=lookup_widget(button,"prenomp");
gtk_entry_set_text(GTK_ENTRY(output2),prenom);
output3=lookup_widget(button,"sexep");  
gtk_entry_set_text(GTK_ENTRY(output3),sexe);
output4=lookup_widget(button,"datep");
gtk_entry_set_text(GTK_ENTRY(output4),date);
output5=lookup_widget(button,"telp");
gtk_entry_set_text(GTK_ENTRY(output5),tel);
output6=lookup_widget(button,"aressep");
gtk_entry_set_text(GTK_ENTRY(output6),adresse);
output7=lookup_widget(button,"mdpp");
gtk_entry_set_text(GTK_ENTRY(output7),mdp);
output8=lookup_widget(button,"cinp");
gtk_entry_set_text(GTK_ENTRY(output8),cin);
gtk_widget_show(profile);

on_modifier_clicked(profile,user_data);
}



void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
espace_client=create_espace_client();
gtk_widget_show(espace_client);
  treeview_hotels_client=lookup_widget(espace_client,"treeview_hotels_client");
  affichage_Hotels (treeview_hotels_client);
  treeview_vols_client=lookup_widget(espace_client,"treeview_vols_client");
  affichage_vols (treeview_vols_client);
  treeview_location_voiture_client=lookup_widget(espace_client,"treeview_location_voiture_client");
  affichage_voiture (treeview_location_voiture_client);
  treeview_sejours_client=lookup_widget(espace_client,"treeview_sejours_client");
  affichage_sejours (treeview_sejours_client);
 treeview_reclamation_client=lookup_widget(espace_client,"treeview_reclamation_client");
  afficher_reclamation (treeview_reclamation_client);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"espace_client")));
}


void
on_modifier1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
profile=create_profile();
espace_client=create_espace_client();
//gtk_widget_hide(GTK_WIDGET(lookup_widget(objet,"Modifier_information")));
GtkEntry *input1;
GtkEntry *input2;
GtkEntry *input3;
GtkEntry *input4;
GtkEntry *input5;
GtkEntry *input6;
GtkEntry *input7;
GtkEntry *input8;
typedef struct profile
{
char Nom[30];
char Prenom[10];
char sexe[10];
char Date[300];
char tel[10];
char adresse[30];
char mot[30];
char cin[30];
}profile;
profile p,p1;
input1=lookup_widget(objet,"nomp");
strcpy(p.Nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet,"prenomp");
strcpy(p.Prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet,"sexp");
strcpy(p.sexe,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(objet,"datep");
strcpy(p.Date,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(objet,"telp");
strcpy(p.tel,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(objet,"adressep");
strcpy(p.adresse,gtk_entry_get_text(GTK_ENTRY(input6)));
input7=lookup_widget(objet,"mdpp");

strcpy(p.mot,gtk_entry_get_text(GTK_ENTRY(input7)));
input8=lookup_widget(objet,"cinp");

strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input8)));
treeview_hotels_client=lookup_widget(espace_client,"treeview_hotels_client");
  affichage_Hotels (treeview_hotels_client);
  treeview_vols_client=lookup_widget(espace_client,"treeview_vols_client");
  affichage_vols (treeview_vols_client);
  treeview_location_voiture_client=lookup_widget(espace_client,"treeview_location_voiture_client");
  affichage_voiture (treeview_location_voiture_client);
  treeview_sejours_client=lookup_widget(espace_client,"treeview_sejours_client");
  affichage_sejours (treeview_sejours_client);
 treeview_reclamation_client=lookup_widget(espace_client,"treeview_reclamation_client");
  afficher_reclamation (treeview_reclamation_client);

FILE *f;
FILE *f1;
f1=NULL ;
f=fopen("profileclient.txt","a");
//f1=fopen("profileclient.tmp","w");
fprintf(f,"%s %s %s %s %s %s %s %s\n",p.Nom,p.Prenom,p.sexe,p.Date,p.tel,p.adresse,p.mot,p.cin) ;
/*
if (f!= NULL)
{
while (fscanf(f,"%s %s %s %s %s %s %s %s\n",p1.Nom,p1.Prenom,p1.sexe,p1.Date,p1.tel,p1.adresse,p1.mot,p1.cin)!=EOF) {
if (strcmp(p.Nom ,p1.Nom)==0)
{
fprintf(f1,"%s %s %s %s %s %s %s %s\n",p.Nom,p.Prenom,p.sexe,p.Date,p.tel,p.adresse,p.mot,p.cin) ;
}
else
fprintf(f1,"%s %s %s %s %s %s %s %s\n",p1.Nom,p1.Prenom,p1.sexe,p1.Date,p1.tel,p1.adresse,p1.mot,p1.cin) ;
}
*/
fclose(f);
//fclose(f1);
//remove("profileclient.txt");
//rename ("profileclient.tmp","profileclient.txt");
gtk_widget_show(espace_client);
}


void
on_valider_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview_reclamation_client_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	gchar *name;
	gchar *surname;
	gchar *cin;
	gchar *datee;
	gchar *mes;



	GtkWidget *current;
	GtkTreeIter iter;


	GtkEntry *nom_client;
	GtkEntry *prenom_client;
	GtkEntry *cin_client;
	GtkEntry *date_client;
	GtkEntry *mes_client;




GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&name,1,&surname,2,&cin,3,&datee,4,&mes,-1);}

current=lookup_widget(treeview,"espace_client");


	cin_client=lookup_widget(current,"entry_cin_reclamation");
	gtk_entry_set_text(GTK_ENTRY(cin_client),cin);
	nom_client=lookup_widget(current,"entry_nom_reclamation");
	gtk_entry_set_text(GTK_ENTRY(nom_client),name);
	prenom_client=lookup_widget(current,"entry_prenom_reclamation");
	gtk_entry_set_text(GTK_ENTRY(prenom_client),surname);
	date_client=lookup_widget(current,"entry_date_reclamation");
	gtk_entry_set_text(GTK_ENTRY(date_client),datee);
	mes_client=lookup_widget(current,"entry_mes_reclamation");
	gtk_entry_set_text(GTK_ENTRY(mes_client),mes);
	
}


void
on_ajouter_reclamation_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_ajouter_recmlamation;
window_ajouter_recmlamation=create_window_ajouter_recmlamation();
gtk_widget_show(window_ajouter_recmlamation);



gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"espace_client")));
}


void
on_supprimer_reclamation_clicked       (GtkButton       *widget,
                                        gpointer         user_data)
{
	char num_CIN [10] ;
	
	GtkWidget *current;
	GtkWidget *treeview_vols_client;
	
	GtkEntry *cin_client_reclamation;

	current=lookup_widget(widget,"espace_client");
	treeview_vols_client=lookup_widget(widget,"treeview_reclamation_client");

	cin_client_reclamation=lookup_widget(current,"entry_cin_reclamation");
	


  	strcpy(num_CIN,gtk_entry_get_text(GTK_ENTRY(cin_client_reclamation)));


  	supprimer_reclamation (num_CIN);
  	afficher_reclamation (treeview_vols_client);
}

void
on_modifier_reclamation_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
	agents a;
	GtkWidget *current;
	
//GtkWidget *treeview1;	
        
	GtkEntry *nom_client;
	GtkEntry *prenom_client;	
	GtkEntry *mes_client;
	GtkEntry *cin_client;
        GtkEntry *date_client;

	GtkEntry *nom_client1;
	GtkEntry *prenom_client1;
	GtkEntry *mes_client1;
	GtkEntry *cin_client1;
        GtkEntry *date_client1;

	current=lookup_widget(button,"espace_client");
	//treeview1=lookup_widget(button,"treeview_reclamation_client");
	modifier_reclamation_client=create_modifier_reclamation_client();  

	nom_client=lookup_widget(current,"entry_nom_reclamation");
	prenom_client=lookup_widget(current,"entry_prenom_reclamation");
	cin_client=lookup_widget(current,"entry_cin_reclamation");
	mes_client=lookup_widget(current,"entry_mes_reclamation");
	date_client=lookup_widget(current,"entry_date_reclamation");


	strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(nom_client)));
  	strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_client)));
  	strcpy(a.mes,gtk_entry_get_text(GTK_ENTRY(mes_client)));
	strcpy(a.num_CIN,gtk_entry_get_text(GTK_ENTRY(cin_client)));
	strcpy(a.date,gtk_entry_get_text(GTK_ENTRY(date_client)));

	nom_client1=lookup_widget(modifier_reclamation_client,"nomc_modif");
	prenom_client1=lookup_widget(modifier_reclamation_client,"prenomc_modif");
	mes_client1=lookup_widget(modifier_reclamation_client,"mesc_modif");
	cin_client1=lookup_widget(modifier_reclamation_client,"cinc_modif");
	date_client1=lookup_widget(modifier_reclamation_client,"datec_modif");


  	
	gtk_entry_set_text(GTK_ENTRY(nom_client1),a.nom);
	gtk_entry_set_text(GTK_ENTRY(prenom_client1),a.prenom);
	gtk_entry_set_text(GTK_ENTRY(mes_client1),a.mes);
	gtk_entry_set_text(GTK_ENTRY(cin_client1),a.num_CIN);
	gtk_entry_set_text(GTK_ENTRY(date_client1),a.date);




	gtk_widget_hide(current);
	gtk_widget_show(modifier_reclamation_client);
}


void
on_valider_reclamation_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

	agents a1;
	GtkWidget *current;
	
		GtkWidget* notebook1;	
        
	GtkEntry *nom_rec;
	GtkEntry *prenom_rec;
	GtkEntry *mes;
	GtkEntry *cin_rec;
        GtkEntry *date_rec;

	current=lookup_widget(button,"modifier_reclamation_client");
	espace_client=create_espace_client();  

	nom_rec=lookup_widget(current,"nomc_modif");
	prenom_rec=lookup_widget(current,"prenomc_modif");
	cin_rec=lookup_widget(current,"cinc_modif");
	
	date_rec=lookup_widget(current,"datec_modif");
        mes=lookup_widget(current,"mesc_modif");

	strcpy(a1.nom,gtk_entry_get_text(GTK_ENTRY(nom_rec)));
  	strcpy(a1.prenom,gtk_entry_get_text(GTK_ENTRY(prenom_rec)));
	strcpy(a1.num_CIN,gtk_entry_get_text(GTK_ENTRY(cin_rec)));
        strcpy(a1.date,gtk_entry_get_text(GTK_ENTRY(date_rec))); 
	strcpy(a1.mes,gtk_entry_get_text(GTK_ENTRY(mes)));

	notebook1=lookup_widget(espace_client,"notebook1");
	gtk_notebook_set_current_page(notebook1,4);
	treeview_reclamation_client=lookup_widget(espace_client,"treeview_reclamation_client)");
	modifier_reclamation(a1);


treeview_hotels_client=lookup_widget(espace_client,"treeview_hotels_client");
  affichage_Hotels (treeview_hotels_client);
  treeview_vols_client=lookup_widget(espace_client,"treeview_vols_client");
  affichage_vols (treeview_vols_client);
  treeview_location_voiture_client=lookup_widget(espace_client,"treeview_location_voiture_client");
  affichage_voiture (treeview_location_voiture_client);
  treeview_sejours_client=lookup_widget(espace_client,"treeview_sejours_client");
  affichage_sejours (treeview_sejours_client);
 treeview_reclamation_client=lookup_widget(espace_client,"treeview_reclamation_client");
  afficher_reclamation (treeview_reclamation_client);		
	gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"modifier_reclamation_client")));
	gtk_widget_show(espace_client);
gtk_widget_show(treeview_reclamation_client);
}

void
on_hist_payer_hotels_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
espace_client=lookup_widget(button,"espace_client");

		historique_payer_hotels=create_historique_payer_hotels();

treeview_payer_hotels=lookup_widget(historique_payer_hotels,"treeview_payer_hotels");
afficher_hist_hotels (treeview_payer_hotels);
		gtk_widget_show(historique_payer_hotels);
gtk_widget_show(treeview_payer_hotels);
}


void
on_treeview_payer_hotels_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{



	gchar *nom;
	gchar *pays;
	gchar *nbe;
	gchar *prix;
	gchar *nbch;
	gchar *adultes;
	gchar *enfants;
	gchar *bebes;

	
	GtkWidget *current;
	GtkTreeIter iter;

	GtkWidget *nom_hotelss;
	GtkEntry *pays_hotel;
	GtkEntry *nbe_hotel;	
	GtkEntry *prix_hotel;
	GtkEntry *nbch_hotel;
        GtkEntry *adultes_hotel;
        GtkEntry *enfants_hotel;
	GtkEntry *bebes_hotel;


	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&pays,2,&nbe,3,&prix,4,&nbch,5,&adultes,6,&enfants,7,&bebes,-1);
	}

	current=lookup_widget(treeview,"historique_payer_hotels");
	nom_hotelss=lookup_widget(current,"nom_hotels");

pays_hotel=lookup_widget(current,"pays_hotels");
nbe_hotel=lookup_widget(current,"nbe_hotels");
prix_hotel=lookup_widget(current,"prix_hotels");
nbch_hotel=lookup_widget(current,"nbch_hotels");
adultes_hotel=lookup_widget(current,"adultes_hotels");
enfants_hotel=lookup_widget(current,"enfants_hotels");
bebes_hotel=lookup_widget(current,"bebes_hotels");

	gtk_entry_set_text(GTK_ENTRY(nom_hotelss),nom);
	gtk_entry_set_text(GTK_ENTRY(pays_hotel),pays);
	gtk_entry_set_text(GTK_ENTRY(nbe_hotel),nbe);
	gtk_entry_set_text(GTK_ENTRY(prix_hotel),prix);
	gtk_entry_set_text(GTK_ENTRY(nbch_hotel),nbch);
	gtk_entry_set_text(GTK_ENTRY(adultes_hotel),adultes);
	gtk_entry_set_text(GTK_ENTRY(enfants_hotel),enfants);
	gtk_entry_set_text(GTK_ENTRY(bebes_hotel),bebes);

}


void
on_modifier_payer_hotels_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
hist a;
	GtkWidget *current;
	GtkWidget *treeview1;

	GtkWidget* historique_payer_hotels;	
        GtkWidget* modifier_payer_hotels;
	GtkEntry *nom_hotel;
	GtkEntry *pays_hotel;
	GtkEntry *nbe_hotel;	
	GtkEntry *prix_hotel;
	GtkEntry *nbch_hotel;
        GtkEntry *adultes_hotel;
        GtkEntry *enfants_hotel;
	GtkEntry *bebes_hotel;



	GtkEntry *nom_hotel1;
	GtkEntry *pays_hotel1;
	GtkEntry *nbe_hotel1;	
	GtkEntry *prix_hotel1;
	GtkEntry *nbch_hotel1;
        GtkEntry *adultes_hotel1;
        GtkEntry *enfants_hotel1;
	GtkEntry *bebes_hotel1;



	current=lookup_widget(button,"historique_payer_hotels");
	treeview1=lookup_widget(button,"treeview_payer_hotels");
	modifier_payer_hotels=create_modifier_payer_hotels();  

	nom_hotel=lookup_widget(current,"nom_hotels");
	pays_hotel=lookup_widget(current,"pays_hotels");
	nbe_hotel=lookup_widget(current,"nbe_hotels");
	prix_hotel=lookup_widget(current,"prix_hotels");
	nbch_hotel=lookup_widget(current,"nbch_hotels");
	adultes_hotel=lookup_widget(current,"adultes_hotels");
        enfants_hotel=lookup_widget(current,"enfants_hotels");
	bebes_hotel=lookup_widget(current,"bebes_hotels");


	strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(nom_hotel)));
  	strcpy(a.pays,gtk_entry_get_text(GTK_ENTRY(pays_hotel)));
  	strcpy(a.nbe,gtk_entry_get_text(GTK_ENTRY(nbe_hotel)));
  	strcpy(a.prixch,gtk_entry_get_text(GTK_ENTRY(prix_hotel))); 	
	strcpy(a.nbch,gtk_entry_get_text(GTK_ENTRY(nbch_hotel)));
	strcpy(a.adultes,gtk_entry_get_text(GTK_ENTRY(adultes_hotel)));
  	strcpy(a.enfants,gtk_entry_get_text(GTK_ENTRY(enfants_hotel))); 	
	strcpy(a.bebes,gtk_entry_get_text(GTK_ENTRY(bebes_hotel)));




	nom_hotel1=lookup_widget(modifier_payer_hotels,"nom_modif");
	pays_hotel1=lookup_widget(modifier_payer_hotels,"pays_modif");
	nbe_hotel1=lookup_widget(modifier_payer_hotels,"nbe_modif");
	prix_hotel1=lookup_widget(modifier_payer_hotels,"prix_modif");
	nbch_hotel1=lookup_widget(modifier_payer_hotels,"nbch_modif");
	adultes_hotel1=lookup_widget(modifier_payer_hotels,"adultes_modif");
        enfants_hotel1=lookup_widget(modifier_payer_hotels,"enfants_modif");
	bebes_hotel1=lookup_widget(modifier_payer_hotels,"bebs_modif");


  	
	gtk_entry_set_text(GTK_ENTRY(nom_hotel1),a.nom);
	gtk_entry_set_text(GTK_ENTRY(pays_hotel1),a.pays);
	gtk_entry_set_text(GTK_ENTRY(nbe_hotel1),a.nbe);
	gtk_entry_set_text(GTK_ENTRY(prix_hotel1),a.prixch);
	gtk_entry_set_text(GTK_ENTRY(nbch_hotel1),a.nbch);
	gtk_entry_set_text(GTK_ENTRY(adultes_hotel1),a.adultes);
	gtk_entry_set_text(GTK_ENTRY(enfants_hotel1),a.enfants);
	gtk_entry_set_text(GTK_ENTRY(bebes_hotel1),a.bebes);




	gtk_widget_hide(current);
	gtk_widget_show(modifier_payer_hotels);
}


	



/*void
on_modifier_payer_hotels_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}*/


void
on_supprimer_payer_hotels_clicked      (GtkWidget       *button,
                                        gpointer         user_data)
{
	char nom1[10] ;
	GtkWidget *treeview_vols_client;
	GtkEntry *nom_hotels;
	
	treeview_vols_client=lookup_widget(button,"treeview_payer_hotels");
	nom_hotels=lookup_widget(button,"nom_hotels");
	

  	strcpy(nom1,gtk_entry_get_text(GTK_ENTRY(nom_hotels)));


  	supprimer_hist_hotels (nom1);
  	afficher_hist_hotels (treeview_vols_client);
}


void
on_treeview_vols_client_row_activated  (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{gchar *DEPART; 
gchar *DESTINATION;
gchar *DATEDEPART;
gchar *DATERETOUR;



GtkWidget *payer_hotels;
/*GtkWidget *current;*/
GtkTreeIter iter;
GtkWidget *L17;
GtkWidget *L18;
GtkWidget *L19;
GtkWidget *E6;
GtkWidget *E7;
GtkWidget *E8;
GtkWidget *E9;
GtkWidget *E10;
GtkWidget *E14;
GtkWidget *E15;
GtkWidget *E16;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&DEPART,1,&DESTINATION,2,&DATEDEPART,3,&DATERETOUR,-1);}
payer_vols = create_payer_vols();

E6=lookup_widget(payer_vols,"departv");
E7=lookup_widget(payer_vols,"destinationv");
E8=lookup_widget(payer_vols,"datedepartv");
E9=lookup_widget(payer_vols,"dateretourv");

gtk_entry_set_text(GTK_ENTRY(E6),DEPART);
gtk_entry_set_text(GTK_ENTRY(E7),DESTINATION);
gtk_entry_set_text(GTK_ENTRY(E8),DATEDEPART);
gtk_entry_set_text(GTK_ENTRY(E9),DATERETOUR);
gtk_widget_show (payer_vols);



}


void
on_treeview_hotels_client_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *NOMH; 
gchar *PAYSH;
gchar *NBEH;
gchar *PRIXH;



GtkWidget *payer_hotels;
/*GtkWidget *current;*/
GtkTreeIter iter;
GtkWidget *L17;
GtkWidget *L18;
GtkWidget *L19;
GtkWidget *E6;
GtkWidget *E7;
GtkWidget *E8;
GtkWidget *E9;
GtkWidget *E10;
GtkWidget *E14;
GtkWidget *E15;
GtkWidget *E16;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&NOMH,1,&PAYSH,2,&NBEH,3,&PRIXH,-1);}
payer_hotels = create_payer_hotels();

E6=lookup_widget(payer_hotels,"nomh");
E7=lookup_widget(payer_hotels,"paysh");
E8=lookup_widget(payer_hotels,"nbeh");
E9=lookup_widget(payer_hotels,"prixh");

gtk_entry_set_text(GTK_ENTRY(E6),NOMH);
gtk_entry_set_text(GTK_ENTRY(E7),NBEH);
gtk_entry_set_text(GTK_ENTRY(E8),PAYSH);
gtk_entry_set_text(GTK_ENTRY(E9),PRIXH);
gtk_widget_show (payer_hotels);

}


void
on_treeview_location_voiture_client_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *PAYS; 
gchar *VILLE;
gchar *AGENCE;
gchar *MODELE;



GtkWidget *payer_location_voitures;
/*GtkWidget *current;*/
GtkTreeIter iter;
GtkWidget *L17;
GtkWidget *L18;
GtkWidget *L19;
GtkWidget *E6;
GtkWidget *E7;
GtkWidget *E8;
GtkWidget *E9;
GtkWidget *E10;
GtkWidget *E14;
GtkWidget *E15;
GtkWidget *E16;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&PAYS,1,&VILLE,2,&AGENCE,3,&MODELE,-1);}
payer_location_voitures = create_payer_location_voitures();

E6=lookup_widget(payer_location_voitures,"payl");
E7=lookup_widget(payer_location_voitures,"vil");
E8=lookup_widget(payer_location_voitures,"agel");
E9=lookup_widget(payer_location_voitures,"modl");

gtk_entry_set_text(GTK_ENTRY(E6),PAYS);
gtk_entry_set_text(GTK_ENTRY(E7),VILLE);
gtk_entry_set_text(GTK_ENTRY(E8),AGENCE);
gtk_entry_set_text(GTK_ENTRY(E9),MODELE);
notebook1=lookup_widget(espace_client,"notebook1");
	gtk_notebook_set_current_page(notebook1,4);
gtk_widget_show (payer_location_voitures);

}


void
on_treeview_sejours_client_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *HOTELS; 
gchar *VILLES;
gchar *CATEGORIES;
GtkWidget *payer_sejours;
/*GtkWidget *current;*/
GtkTreeIter iter;
GtkWidget *L17;
GtkWidget *L18;
GtkWidget *L19;
GtkWidget *E6;
GtkWidget *E7;
GtkWidget *E8;
GtkWidget *E9;
GtkWidget *E10;
GtkWidget *E14;
GtkWidget *E15;
GtkWidget *E16;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&HOTELS,1,&VILLES,2,&CATEGORIES,-1);}
payer_sejours = create_payer_sejours();

E6=lookup_widget(payer_sejours,"noms");
E7=lookup_widget(payer_sejours,"payss");
E8=lookup_widget(payer_sejours,"nbes");


gtk_entry_set_text(GTK_ENTRY(E6),HOTELS);
gtk_entry_set_text(GTK_ENTRY(E7),VILLES);
gtk_entry_set_text(GTK_ENTRY(E8),CATEGORIES);

gtk_widget_show (payer_sejours);


}


void
on_valider_modifier_payer_hotels_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
 hist a1;
        GtkWidget *current;
        GtkWidget *treeview1;

        GtkWidget* espace_client;
	GtkWidget* notebook;
	       

        GtkEntry *nom;
        GtkEntry *pays;
        GtkEntry *nbe; 
        GtkEntry *prixch;
        GtkEntry *nbch;
        GtkEntry *adultes;
        GtkEntry *enfants;
        GtkEntry *bebes;

        


        current=lookup_widget(button,"espace_client");
        treeview1=lookup_widget(button,"treeview_payer_hotels");
        

        nom=lookup_widget(current,"nom_modif");
        pays=lookup_widget(current,"pays_modif");
        nbe=lookup_widget(current,"nbe_modif");
        prixch=lookup_widget(current,"prix_modif");
        nbch=lookup_widget(current,"nbch_modif");
        adultes=lookup_widget(current,"adultes_modif");
        enfants=lookup_widget(current,"enfants_modif");
        bebes=lookup_widget(current,"bebs_modif");


        strcpy(a1.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
        strcpy(a1.pays,gtk_entry_get_text(GTK_ENTRY(pays)));
        strcpy(a1.nbe,gtk_entry_get_text(GTK_ENTRY(nbe)));
        strcpy(a1.prixch,gtk_entry_get_text(GTK_ENTRY(prixch)));     
        strcpy(a1.nbch,gtk_entry_get_text(GTK_ENTRY(nbch)));
        strcpy(a1.adultes,gtk_entry_get_text(GTK_ENTRY(adultes)));
        strcpy(a1.enfants,gtk_entry_get_text(GTK_ENTRY(enfants)));
        strcpy(a1.bebes,gtk_entry_get_text(GTK_ENTRY(bebes)));


        treeview1=lookup_widget(espace_client,"treeview_payer_hotels");
	modifier_hist_hotels (a1);
	afficher_hist_hotels(treeview1);
	gtk_widget_hide(current);
	gtk_widget_show(espace_client);
        
}

