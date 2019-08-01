  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

  #include <stdio.h>
  #include <stdlib.h>
  #include <windows.h>

  typedef int bool ;
  typedef char * string255 ;
  typedef char * string2 ;

  #define True 1
  #define False 0

  /** Implémentation **\: LISTE DE CHAINES DE CARACTERES**/

  /** Listes lin?aires cha?n?es **/

  typedef struct chaine chaine;
struct chaine
 {
     char  mots[100];
 };

  typedef string255 Typeelem_Ls   ;
  typedef struct Maillon_Ls * Pointeur_Ls ;

  struct Maillon_Ls
    {
      Typeelem_Ls  Val ;
      Pointeur_Ls Suiv ;
    } ;

  Pointeur_Ls Allouer_Ls (Pointeur_Ls *P)
    {
      *P = (struct Maillon_Ls *) malloc( sizeof( struct Maillon_Ls)) ;
      (*P)->Val = malloc(255 * sizeof(string255));
      (*P)->Suiv = NULL;
    }

  void Aff_val_Ls(Pointeur_Ls P, Typeelem_Ls Val)
    {
      strcpy( P->Val , Val );
    }

  void Aff_adr_Ls( Pointeur_Ls P,  Pointeur_Ls Q)
    {
      P->Suiv = Q ;
    }

  Pointeur_Ls Suivant_Ls(  Pointeur_Ls P)
    { return( P->Suiv ) ;  }

  Typeelem_Ls Valeur_Ls( Pointeur_Ls P)
    { return( P->Val) ; }

  void Liberer_Ls ( Pointeur_Ls P)
    { free (P);}


  /** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tcb Type_Tcb  ;
  typedef Type_Tcb * Typestr_Tcb ;
  typedef string2 Type1_Tcb  ;
  typedef bool Type2_Tcb  ;
  struct Tcb
    {
      Type1_Tcb Champ1 ;
      Type2_Tcb Champ2 ;
    };

  Type1_Tcb Struct1_Tcb ( Typestr_Tcb S)
    {
      return  S->Champ1 ;
    }

  Type2_Tcb Struct2_Tcb ( Typestr_Tcb S)
    {
      return  S->Champ2 ;
    }

  void Aff_struct1_Tcb ( Typestr_Tcb S, Type1_Tcb Val )
    {
      strcpy( S->Champ1 , Val );
    }

  void Aff_struct2_Tcb ( Typestr_Tcb S, Type2_Tcb Val )
    {
       S->Champ2 = Val ;
    }


  /** Arbres de recherche binaire **/

  typedef Typestr_Tcb Typeelem_ATcb   ;
  typedef struct Noeud_ATcb * Pointeur_ATcb ;

  struct Noeud_ATcb
    {
      Typeelem_ATcb  Val ;
      Pointeur_ATcb Fg ;
      Pointeur_ATcb Fd ;
      Pointeur_ATcb Pere ;
     } ;

  Typeelem_ATcb Info_ATcb( Pointeur_ATcb P )
    { return P->Val;   }

  Pointeur_ATcb Fg_ATcb( Pointeur_ATcb P)
    { return P->Fg ; }

  Pointeur_ATcb Fd_ATcb( Pointeur_ATcb P)
    { return P->Fd ; }

  Pointeur_ATcb Pere_ATcb( Pointeur_ATcb P)
    { return P->Pere ; }

  void Aff_info_ATcb ( Pointeur_ATcb P, Typeelem_ATcb Val)
    {
      Typeelem_ATcb _Temp ;
      _Temp = malloc(sizeof(Typestr_Tcb));
      _Temp->Champ1 = malloc(2 * sizeof(string2));
      /* Affectation globale de structure */
      strcpy(_Temp->Champ1, Val->Champ1);
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
       P->Val = Val ;
    }

  void Aff_fg_ATcb( Pointeur_ATcb P, Pointeur_ATcb Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATcb( Pointeur_ATcb P, Pointeur_ATcb Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATcb( Pointeur_ATcb P, Pointeur_ATcb Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATcb( Pointeur_ATcb *P)
    {
      *P = (struct Noeud_ATcb *) malloc( sizeof( struct Noeud_ATcb))   ;
      (*P)->Val = malloc(sizeof(Typestr_Tcb));
      (*P)->Val->Champ1 = malloc( 2 * sizeof(string2));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATcb( Pointeur_ATcb P)
    { free( P ) ; }


  /** Implémentation **\: TABLEAU DE CHAINES DE CARACTERES**/

  /** Tableaux **/

  typedef string255 Typeelem_V15s ;
  typedef Typeelem_V15s * Typevect_V15s ;

  Typeelem_V15s Element_V15s ( Typevect_V15s V , int I1  )
    {
      return  *(V + I1-1 ) ;
    }

  void Aff_element_V15s ( Typevect_V15s V  , int I1 ,  Typeelem_V15s Val )
    {
     strcpy( *(V + I1-1 ) , Val );
    }


  /** Variables du programme principal **/
  int I;
  int E;
  string255 Lettre;
  Pointeur_Ls Tete;
  Pointeur_ATcb Racin;
  Typevect_V15s Tabl;
  string255 Mot;
  Pointeur_ATcb Racineee;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }

  char  *Aleachaine ( int N )
    {
      int k;
      char  * Chaine = malloc(N+1);

      char Chr1[26] = "abcdefghijklmnopqrstuvwxyz";
      char Chr2[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

      for (k=0;k<N; k++)
        switch ( rand() % 2 ){
        case 0 :  *(Chaine+k) = Chr1[rand() % 26] ; break ;
        case 1 :  *(Chaine+k) = Chr2[rand() % 26] ; break ;
        }
      Chaine[k] =  '\0' ;

      return (Chaine);
    }

  char *Caract ( string255 Ch , int I )
    {
      char *s = malloc(2);
      s[0] = Ch[I-1];
      s[1] = '\0';
      return  s;
    }

  int Longchaine ( string255 Ch  )
    {
      return strlen(Ch);
    }


  /** Prototypes des fonctions **/
int k ;
  void Creation_listem (Pointeur_Ls *Mountete , int *Nbr_elements);
  void Affichage_listem (Pointeur_Ls *Tetemoun);
  void Echange_mot (Pointeur_Ls *Mouna , Pointeur_Ls *Mounb);
  void Tri_lmotmo (Pointeur_Ls *Lmot_mouna);
  void Crea_arbremo (Pointeur_ATcb *Racine_moun , Pointeur_Ls *Lmot , int *Nbr_mot);
  void Afficher_arbre (Pointeur_ATcb *Tr);
  void Affichage (Pointeur_ATcb *Rnoe , string255 *Mot);
  void Affichage2 (Pointeur_ATcb *Rnoe , string255 *Mot , int *Taille3);
  void Affichage_r (Pointeur_ATcb *Rnoe , string255 *Mot , int *Type , string255 *Ch);
  void Recherche (Pointeur_ATcb *Racineee);
  void Creation_listem_f (Pointeur_Ls *Mountete  ,char premier[30],int *Cpt_moun);
  /******************AFFICHAGE GRAPHIQUE*********************/
    void menu(chaine *lechoix,Pointeur_ATcb Rnoe );
    void intro(void);
    void fin(void);
    int choix (chaine *lechoix);
/******************AFFICHAGE GRAPHIQUE*********************/










/**** grafic                **/
void menu(chaine *lechoix,Pointeur_ATcb Racin)
{ int *e,*d,*n;
  int x,y,nb_c;
     Lettre = malloc(255 * sizeof(string255));
     Tabl = malloc(15 * 255  * sizeof(string255));
     int _Izw2;for (_Izw2=0; _Izw2<15; ++_Izw2);
     int cpt=0;
     char mot[30],premier[30],liste[30];
       Tabl[_Izw2]= malloc(255 * sizeof(string255));
     Mot = malloc(255 * sizeof(string255));


     E  =  15;
    // printf ( " %d", E ) ;

  FILE *f;
//  cree_cle(&n,&e,&d);
  //char name[20],mot[20],rmp[20];
  char dest[20];
  int k=1;
  char psw[20]; ////////--- pour l'acces aux cles ---////////////
  char *old_locale, *saved_locale;
  deb:
  basemenu();
  switch(choix(lechoix))
  { case 1: system("cls");
   int i,x=0,y=0,ch;int type;

        ch=1;
        basemenu();
         chaine menu1[]={    "   >>        Cree l'arbre Aleatoire         <<   ",
                             "   >>    Cree l'arbre d'apres un fichier    <<   ",
                             "   >>                                       <<   ",
                             "   >>                                       <<   ",
                             "   >>                                       <<   ",
                             "   >>                Retour                 <<   "};
     do{
      for(i=0;i<6;i++)
        {if(i==ch){
            textbackground(2);
            textcolor(15);
             printdirection(menu1[i].mots,"right",35,(22+i+1),0);
             }
         else{     textbackground(15);
                   textcolor(0);
             printdirection(menu1[i].mots,"right",35,(22+i+1),0);
             }

    }

    x=readkey();
    switch(x){
     case 336 : ch = (ch+1)%6;
                break;
     case 328: ch = (ch+5)%6;
               break;
     case 13 :
         y=1;
        break;

       }

 }while(y!=1);
 //ch+1


        switch(ch+1){
            char mot[30];
        case 1:
            system("cls");
            //bande();
            //printf("test\n");
            textcolor(15);

             Creation_listem ( & Tete , & E ) ;
             Tri_lmotmo ( & Tete ) ;
             printf("\n");
             printf("\n");
             printf("\n");
             printf (" Tri de la liste reussi                                                                                                \n" ) ;
             //Affichage_listem ( & Tete ) ;
             printf (" Creation arb depuis la fonction aleatoirechaine ...                                                                                                      \n" ) ;
             Crea_arbremo ( & Racin , & Tete , & E ) ;
             printf("\n");
             printf("\n");
             printf("\n");
             textbackground(2);
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                              Creation d'arbre reussite                                                 ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                       Appuyez sur n'importe quelle touche pour RETOUR (AFFICHAGE + RECHERCHE)                          ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             textbackground(0);

            system("pause");
            break;
        case 2:
            system("cls");
            //bande();
            //printf("test\n");
            textcolor(15);
           // textbackground(2);
            FILE *fic = fopen("test.txt","r");

            while(!feof(fic))
            {
                fscanf(fic,"%s",mot);
                //printf("%s \n",mot);
              //  strcpy(liste,mot);
                cpt = cpt +1;
                if (cpt == 1){
                    strcpy(premier,mot);
                }
               // printf("%s",liste);
                //printf("\n");

           }//printf("%d",cpt);


            fclose(fic);
            E = cpt;
            //printf("this is E = %d",E);
            //printf("lay lay %s \n",premier);

            Creation_listem_f (& Tete,premier,&E );

           /******************************** chghol hadha kml l'appel + rani zedt des variables*******************************/
             //Creation_listem ( & Tete , & E ) ;
             Tri_lmotmo ( & Tete ) ;
             printf("\n");
             printf("\n");
             printf("\n");
             printf (" Tri de la liste reussi                                                                                                \n" ) ;
             //Affichage_listem ( & Tete ) ;
             printf (" Creation arb depuis la fonction aleatoirechaine ...                                                                                                      \n" ) ;
             Crea_arbremo ( & Racin , & Tete , & E ) ;
             printf("\n");
             printf("\n");
             printf("\n");
             textbackground(2);
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                              Creation d'arbre reussite                                                 ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                       Appuyez sur n'importe quelle touche pour RETOUR (AFFICHAGE + RECHERCHE)                          ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             textbackground(0);
            system("pause");
            break;textcolor(2);
           system("pause");
           break;
        }
           system("pause");
           break;
    case 2: system("cls");
            //bande();
            textcolor(15);
            textbackground(2);
            printf ("\n                                                                                                                        ") ;
            printf ("\n                                                 Affichage de tous les mots                                             ") ;
            printf ("\n                                                                                                                        ") ;
            printf ("\n                                                                                                                        ") ;
            printf ("\n                                                                                                                        ") ;
            printf("\n");
            printf("\n");
            gotoxy(1,5);
            textbackground(0);
            strcpy (Mot,   "-") ;
            Affichage ( & Racin , & Mot) ;
            system("pause");
            break;
    case 3: system("cls");
            //bande();
            textcolor(15);
            textbackground(2);
            printf ("\n                                                                                                                        ") ;
            printf ("\n                                                                                                                        ") ;
            printf ("\n                                                    Rechrech des mots                                                   ") ;
            printf ("\n                                                                                                                        ") ;
            printf ("\n                                                                                                                        ") ;
            printf("\n");
            printf("\n");
            gotoxy(1,5);
            textbackground(0);
            Recherche(&Racin);
            system("pause");
            break;
    case 4:
            system("cls");
            //bande();
            textcolor(15);
            textbackground(2);
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             textbackground(0);
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("                               moi                                                                                         ");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             printf("\n");
             textbackground(2);
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
             printf ("\n                                                                                                                        ") ;
            gotoxy(1,5);
            system("pause");
            break;
    case 5:

          system("pause");
            break;

    case 6:

          goto fin;

  }
  goto deb;
  fin:
  fin();
}
void  basemenu(void)
{int i,y,a=0,z,d,b;
system("mode con lines=40 cols=120");
system("cls");
system("COLOR 02");
        blancln(5);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
moverect("up");
textbackground(10);
textcolor(15);
y=7;
gotoxy(35,y);
 printf("%c%c%c%c%c   %c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c     %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(35,y+1);
 printf("%c%c%c%c%c%c %c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c    %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(35,y+2);
 printf("%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c        %c%c%c%c%c%c   %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(35,y+3);
 printf("%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c  %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(35,y+4);
 printf("%c%c%c  %c%c%c  %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(35,y+5);
 printf("%c%c%c   %c   %c%c%c   %c%c%c        %c%c%c%c  %c%c%c%c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(35,y+6);
 printf("%c%c%c       %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c    %c%c%c%c%c   %c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(35,y+7);
 printf("%c%c%c       %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c     %c%c%c%c    %c%c%c%c%c%c%c ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
gotoxy(30,20);
textcolor(2);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(30,22);delay(50);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(30,23);delay(50);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(30,24);delay(50);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(30,25);delay(50);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(30,26);delay(50);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(30,27);delay(50);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(30,28);delay(50);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(30,29);delay(50);

printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(30,31);delay(50);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
textcolor(2);
z=86;
d=20;
textbackground(0);
b=10;  textbackground(b);

printdirection("                                                     \n","left",z,d+2,0);textbackground(b);
printdirection("                                                     \n","left",z,d+3,0);textbackground(b);
printdirection("                                                     \n","left",z,d+4,0);textbackground(b);
printdirection("                                                     \n","left",z,d+5,0);textbackground(b);
printdirection("                                                     \n","left",z,d+6,0);textbackground(b);
printdirection("                                                     \n","left",z,d+7,0);textbackground(b);
printdirection("                                                     \n","left",z,d+8,0);textbackground(b);
printdirection("                                                     \n","left",z,d+9,0);

}
//-----------------------------------------------------------------------------------------------
void intro(void){int y;
system("mode con lines=40 cols=120");
system("COLOR 07");
 y=1;
 textcolor(2);
  gotoxy(1,y);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+1);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+2);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+3);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+4);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+5);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+6);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+7);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+8);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+9);
delay(500);
  decalrectangle(1);
  //**********************************************************************************************************************
    textbackground(0);
    textcolor(10);

        printdirection("Ecole Nationale Superieur en Informatique d'Alger ","right",38,1,45);

        printdirection("Annee Universitaire 2018/2019","right",49,2,45) ;
        decalrectangle(2);
        textcolor(2);
textbackground(0);
gotoxy(35,10);
 printf("%c%c%c%c%c%c%c%c%c%c             %c%c%c%c%c%c%c%c%c        \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219) ;delay(50);gotoxy(35,11);
 printf("    %c%c                 %c%c     %c%c             \n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);delay(50);gotoxy(35,12);
 printf("    %c%c                 %c%c     %c%c             \n",219,219,219,219,219,219,219,219,219,219);delay(50);gotoxy(35,13);
 printf("    %c%c                 %c%c%c%c%c%c%c%c%c       \n",219,219,219,219,219,219,219,219,219,219,219,219,219);delay(50);gotoxy(35,14);
 printf("    %c%c                 %c%c                  \n",219,219,219,219,219,219,219);delay(50);gotoxy(35,15);
 printf("    %c%c                 %c%c            \n",219,219,219,219,219,219,219,219,219,219,219);
delay(300);
 decalrectangle(3);
textbackground(0);
textcolor(2);
 gotoxy(14,20);

printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);gotoxy(14,21);
printf("%c                                                                                            %c\n",186,186);gotoxy(14,22);
printf("%c                                                                                            %c\n",186,186);gotoxy(14,23);
printf("%c                                                                                            %c\n",186,186);gotoxy(14,24);
printf("%c                                                                                            %c\n",186,186);gotoxy(14,25);
printf("%c                                                                                            %c\n",186,186);gotoxy(14,26);
printf("%c                                                                                            %c\n",186,186);gotoxy(14,27);
printf("%c                                                                                            %c\n",186,186);gotoxy(14,28);
textbackground(0);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
printdirection(">","down",20,22,60);
printdirection("Realise par : ","left",35,22,60);

printdirection(" e ","down",64,23,60);
printdirection(" n ","down",63,23,60);
printdirection(" i ","down",62,23,60);
printdirection(" d ","down",61,23,60);
printdirection("ad ","down",60,23,60);
printdirection("nE ","down",59,23,60);
printdirection("ua ","down",58,23,60);
printdirection("ol7 ","down",57,23,60);
printdirection("MA0 ","down",56,23,60);
printdirection("||| ","down",54,23,60);
printdirection("I e ","down",52,23,60);
printdirection("LIp ","down",51,23,60);
printdirection("ARu ","down",50,23,60);
printdirection("MSo ","down",49,23,60);
printdirection("MAr ","down",48,23,60);
printdirection("ANG ","down",47,23,60);
printdirection(" | Semestre 02","right",80,24,30);
printdirection("> Encadree par :       Prof D_Zegour","right",20,27,45);
textbackground(0);
gotoxy(wherex()-14,wherey()+3);
system("pause");
}
void fin(void){
    system("COLOR 02");
    system("cls");
    textbackground(15);
    textcolor(0);
    decalrectangle(1);
    textcolor(15);
    textbackground(0);
    printdirection("           Nous vous remercions d'avoir utiliser notre programme    ","right",20,2,30 );
delay(1000);
textbackground(15);
    textcolor(0);
decalrectangle(2);
decalrectangle(3);
gotoxy(15,10);
    textbackground(2);
    textcolor(15);
    printdirection("  Pour toute remarque contactez nous sur :  ","right",wherex()+24,wherey(),20);textbackground(2);
    printdirection("       ","down",60,wherey()+4,15);
     textbackground(0);textcolor(15);
    printdirection(" AMMALI Mouna ","right",24,16,15);
        textbackground(15);textcolor(0);
     printdirection(" e-mail: im_ammali@esi.dz ","right",17,18,15);
     textbackground(0);textcolor(15);
    printdirection(" NASRI Ala-Eddine ","right",85,16,15);
        textbackground(15);textcolor(0);
     printdirection(" e-mail: ia_nasri@esi.dz ","right",79,18,15);


       gotoxy(38,wherey()+7);
       textcolor(2);
       system("pause");
}
int choix (chaine *lechoix){
    int i,x=0,y=0,ch;

ch=1;
 do{
  for(i=0;i<6;i++)
    {if(i==ch){
        textbackground(2);
        textcolor(15);
         printdirection(lechoix[i].mots,"right",35,(22+i+1),0);
         }
     else{     textbackground(15);
               textcolor(0);
         printdirection(lechoix[i].mots,"right",35,(22+i+1),0);
         }

    }
    x=readkey();
    switch(x){
     case 336 : ch = (ch+1)%6;
                break;
     case 328: ch = (ch+5)%6;
               break;
     case 13 :
         y=1;
        break;

       }

 }while(y!=1);
 return ch+1;
                      }
//----------------------------------Bibliotheque Conio pour l'interface graphique ----------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
typedef enum
{
    BLACK,          /**< black color */
    BLUE,           /**< blue color */
    GREEN,          /**< green color */
    CYAN,           /**< cyan color */
    RED,            /**< red color */
    MAGENTA,        /**< magenta color */
    BROWN,          /**< brown color */
    LIGHTGRAY,      /**< light gray color */
    DARKGRAY,       /**< dark gray color */
    LIGHTBLUE,      /**< light blue color */
    LIGHTGREEN,     /**< light green color */
    LIGHTCYAN,      /**< light cyan color */
    LIGHTRED,       /**< light red color */
    LIGHTMAGENTA,   /**< light magenta color */
    YELLOW,         /**< yellow color */
    WHITE           /**< white color */
} COLORS;

/*@{*/
/**
 * This defines enables you to use all MinGW conio.h functions without
 * underscore.
 */
#define cgets   _cgets
#define cprintf _cprintf
#define cputs   _cputs
#define cscanf  _cscanf

#ifdef UNICODE
    #define cgetws   _cgetws
    #define getwch   _getwch
    #define getwche  _getwche
    #define putwch   _putwch
    #define ungetwch _ungetwch
    #define cputws   _cputws
    #define cwprintf _cwprintf
    #define cwscanf  _cwscanf
#endif
/*@}*/

/**
 * Define alias for _conio_gettext.
 * If you want to use gettext function from some other library
 * (e.g. GNU gettext) you have to define _CONIO_NO_GETTEXT_ so you won't get
 * name conflict.
 */
#ifndef _CONIO_NO_GETTEXT_
  #define gettext _conio_gettext
#endif

#define ScreenClear clrscr

/**
 * @anchor cursortypes
 * @name Cursor types
 * Predefined cursor types. */
/*@{*/
#define _NOCURSOR 0         /**< no cursor */
#define _SOLIDCURSOR 100    /**< cursor filling whole cell */
#define _NORMALCURSOR 20    /**< cursor filling 20 percent of cell height */
/*@}*/

/**
 * Structure holding information about screen.
 * @see gettextinfo
 * @see inittextinfo
 */
struct text_info {
    unsigned char curx;          /**< cursor coordinate x */
    unsigned char cury;          /**< cursor coordinate y */
    unsigned short attribute;    /**< current text attribute */
    unsigned short normattr;     /**< original value of text attribute after
                                      start of the application. If you don't
                                      called the <TT>inittextinfo</TT> on the
                                      beginning of the application, this always
                                      will be black background and light gray
                                      foreground */
    unsigned char screenwidth;   /**< screen width */
    unsigned char screenheight;  /**< screen height */
};

/**
 * Structure used by gettext/puttext.
 * @see _conio_gettext
 * @see puttext
 */
struct char_info {
#ifdef UNICODE
    wchar_t letter;        /**< character value */
#else
    char letter;           /**< character value */
#endif
    unsigned short attr;   /**< attribute value */
};

static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;
static struct text_info __text_info = {
    1, 1,
    LIGHTGRAY + (BLACK << 4),
    LIGHTGRAY + (BLACK << 4),
    80, 25
};
static int __CONIO_TOP = 0;
static int __CONIO_LEFT = 0;
void  basemenu(void);
static void
__fill_text_info (void)
{
    CONSOLE_SCREEN_BUFFER_INFO info;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    __CONIO_LEFT = info.srWindow.Left;
    __CONIO_TOP = info.srWindow.Top;
    __text_info.curx = info.dwCursorPosition.X - __CONIO_LEFT + 1;
    __text_info.cury = info.dwCursorPosition.Y - __CONIO_TOP  + 1;
    __text_info.attribute = info.wAttributes;
    __text_info.screenwidth  = info.srWindow.Right - info.srWindow.Left + 1;
    __text_info.screenheight = info.srWindow.Bottom - info.srWindow.Top + 1;
}

void
gettextinfo (struct text_info * info)
{
    __fill_text_info();
    *info = __text_info;
}

void
inittextinfo (void)
{
    CONSOLE_SCREEN_BUFFER_INFO info;

    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &info);
    __text_info.normattr = info.wAttributes;
}

void
clrscr (void)
{
    DWORD written;
    int i;

    __fill_text_info();
    for (i = __CONIO_TOP; i < __CONIO_TOP + __text_info.screenheight; i++) {
      FillConsoleOutputAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
        __FOREGROUND + (__BACKGROUND << 4), __text_info.screenwidth,
        (COORD) {__CONIO_LEFT, i},
        &written);
      FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
        __text_info.screenwidth,
        (COORD) {__CONIO_LEFT, i},
        &written);
    }
    gotoxy (1, 1);
}


void
clreol (void)
{
    COORD coord;
    DWORD written;

    __fill_text_info();
    coord.X = __CONIO_LEFT + __text_info.curx - 1;
    coord.Y = __CONIO_TOP  + __text_info.cury - 1;

    FillConsoleOutputAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
      __FOREGROUND + (__BACKGROUND << 4),
      __text_info.screenwidth - __text_info.curx + 1, coord, &written);
    FillConsoleOutputCharacter (GetStdHandle (STD_OUTPUT_HANDLE),
      ' ', __text_info.screenwidth - __text_info.curx + 1, coord, &written);
    gotoxy (__text_info.curx, __text_info.cury);
}


void
delline (void)
{
    COORD coord;
    SMALL_RECT rect;
    CHAR_INFO fillchar;

    __fill_text_info();
    coord.X = __CONIO_LEFT;
    coord.Y = __CONIO_TOP + __text_info.cury - 1;
    rect.Left = __CONIO_LEFT;
    rect.Top = __CONIO_TOP + __text_info.cury;
    rect.Right = __CONIO_LEFT + __text_info.screenwidth - 1;
    rect.Bottom = __CONIO_TOP + __text_info.screenheight - 1;
    fillchar.Attributes = __FOREGROUND + (__BACKGROUND << 4);
#ifdef UNICODE
    fillchar.Char.UnicodeChar = L' ';
    ScrollConsoleScreenBufferW (GetStdHandle (STD_OUTPUT_HANDLE),
      &rect, NULL, coord, &fillchar);
#else
    fillchar.Char.AsciiChar = ' ';
    ScrollConsoleScreenBufferA (GetStdHandle (STD_OUTPUT_HANDLE),
      &rect, NULL, coord, &fillchar);
#endif


    gotoxy (__text_info.curx, __text_info.cury);
}

void
insline (void)
{
    COORD coord;
    SMALL_RECT rect;
    CHAR_INFO fillchar;

    __fill_text_info();
    coord.X = __CONIO_LEFT;
    coord.Y = __CONIO_TOP + __text_info.cury;
    rect.Left = __CONIO_LEFT;
    rect.Top = __CONIO_TOP + __text_info.cury - 1;
    rect.Right = __CONIO_LEFT + __text_info.screenwidth - 1;
    rect.Bottom = __CONIO_TOP + __text_info.screenheight - 2;
    fillchar.Attributes = __FOREGROUND + (__BACKGROUND << 4);
#ifdef UNICODE
    fillchar.Char.UnicodeChar = L' ';
    ScrollConsoleScreenBufferW (GetStdHandle (STD_OUTPUT_HANDLE),
      &rect, NULL, coord, &fillchar);
#else
    fillchar.Char.AsciiChar = ' ';
    ScrollConsoleScreenBufferA (GetStdHandle (STD_OUTPUT_HANDLE),
      &rect, NULL, coord, &fillchar);
#endif

    gotoxy (__text_info.curx, __text_info.cury);
}

void
movetext (int left, int top, int right, int bottom, int destleft, int desttop)
{
    struct char_info * buffer;

    buffer = malloc ((right - left + 1) * (bottom - top + 1) * sizeof(struct char_info));
    gettext (left, top, right, bottom, buffer);
    puttext (destleft, desttop, destleft + right - left, desttop + bottom - top, buffer);
    free(buffer);
}

void
_conio_gettext (int left, int top, int right, int bottom,
  struct char_info * buf)
{
    int i;
    SMALL_RECT r;
    CHAR_INFO* buffer;
    COORD size;

    __fill_text_info();
    r = (SMALL_RECT) {__CONIO_LEFT + left - 1, __CONIO_TOP + top - 1,
      __CONIO_LEFT + right - 1, __CONIO_TOP + bottom - 1};
    size.X = right - left + 1;
    size.Y = bottom - top + 1;
    buffer = malloc (size.X * size.Y * sizeof(CHAR_INFO));

    ReadConsoleOutput (GetStdHandle (STD_OUTPUT_HANDLE),
      (PCHAR_INFO) buffer, size, (COORD) {0, 0}, &r);

    for (i = 0; i < size.X * size.Y; i++)
    {
#ifdef UNICODE
        buf[i].letter = buffer[i].Char.UnicodeChar;
#else
        buf[i].letter = buffer[i].Char.AsciiChar;
#endif
        buf[i].attr = buffer[i].Attributes;
    }
    free (buffer);
}

void
puttext (int left, int top, int right, int bottom, struct char_info * buf)
{
    int i;
    SMALL_RECT r;
    CHAR_INFO* buffer;
    COORD size;

    __fill_text_info();
    r = (SMALL_RECT) {__CONIO_LEFT + left - 1, __CONIO_TOP + top - 1,
      __CONIO_LEFT + right - 1, __CONIO_TOP + bottom - 1};
    size.X = right - left + 1;
    size.Y = bottom - top + 1;
    buffer = malloc (size.X * size.Y * sizeof(CHAR_INFO));

    for (i = 0; i < size.X * size.Y; i++)
    {
#ifdef UNICODE
        buffer[i].Char.UnicodeChar = buf[i].letter;
#else
        buffer[i].Char.AsciiChar = buf[i].letter;
#endif
        buffer[i].Attributes = buf[i].attr;
    }

    WriteConsoleOutput (GetStdHandle (STD_OUTPUT_HANDLE),
      buffer, size, (COORD) {0, 0}, &r);
    free (buffer);
}

void
gotoxy(int x, int y)
{
  COORD c;

  c.X = __CONIO_LEFT + x - 1;
  c.Y = __CONIO_TOP  + y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void
cputsxy (int x, int y, char * str)
{
    gotoxy (x, y);
    cputs (str);
}

void
putchxy (int x, int y, char ch)
{
    gotoxy (x, y);
    putch (ch);
}

void
_setcursortype (int type)
{
    CONSOLE_CURSOR_INFO Info;

    if (type == 0) {
        Info.bVisible = FALSE;
    } else {
      Info.dwSize = type;
      Info.bVisible = TRUE;
    }
    SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE),
      &Info);
}


void
textattr (int _attr)
{
    __FOREGROUND = _attr & 0xF;
    __BACKGROUND = _attr >> 4;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), _attr);
}

void
normvideo (void)
{
    textattr (__text_info.normattr);
}

void
textbackground (int color)
{
    __BACKGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
      __FOREGROUND + (color << 4));
}


void
textcolor (int color)
{
    __FOREGROUND = color;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
      color + (__BACKGROUND << 4));
}


int
wherex (void)
{
    __fill_text_info();
    return __text_info.curx;
}


int
wherey (void)
{
    __fill_text_info();
    return __text_info.cury;
}

char *
getpass (const char * prompt, char * str)
{
    int maxlength = str[0];
    int length = 0;
    int ch = 0;
    int x, y;

    cputs(prompt);
    __fill_text_info();
    x = __text_info.curx;
    y = __text_info.cury;

    while (ch != '\r') {
        ch = getch();
        switch (ch) {
            case '\r' : /* enter */
                break;
            case '\b' : /* backspace */
                if (length > 0) putchxy (x + --length, y, ' ');
                gotoxy (x + length, y);
                break;
            default:
                if (length < maxlength) {
                    putchxy (x + length, y, '*');
                    str[2 + length++] = ch;
                }
        }
    }

    str[1] = length;
    str[2 + length] = '\0';
    return &str[2];
}

void
highvideo (void)
{
    if (__FOREGROUND < DARKGRAY) textcolor(__FOREGROUND + 8);
}

void
lowvideo (void)
{
    if (__FOREGROUND > LIGHTGRAY) textcolor(__FOREGROUND - 8);
}

void
delay (int ms)
{
    Sleep(ms);
}

void
switchbackground (int color)
{
    struct char_info* buffer;
    int i;

    buffer = malloc(__text_info.screenwidth * __text_info.screenheight *
      sizeof(struct char_info));
    _conio_gettext(1, 1, __text_info.screenwidth, __text_info.screenheight,
      buffer);
    for (i = 0; i < __text_info.screenwidth * __text_info.screenheight; i++) {
        unsigned short attr = buffer[i].attr & 0xF;
        buffer[i].attr = (color << 4) | attr;
    }
    puttext(1, 1, __text_info.screenwidth, __text_info.screenheight, buffer);
    free(buffer);
}

void
flashbackground (int color, int ms)
{
    struct char_info* buffer;

    buffer = malloc(__text_info.screenwidth * __text_info.screenheight *
      sizeof(struct char_info));
    _conio_gettext(1, 1, __text_info.screenwidth, __text_info.screenheight,
      buffer);
    switchbackground(color);
    delay(ms);
    puttext(1, 1, __text_info.screenwidth, __text_info.screenheight, buffer);
    free(buffer);
}

void
clearkeybuf (void)
{
    while (kbhit()) {
        getch();
    }
}

#ifdef __cplusplus
}
#endif

//--------------------------------------------------------------------------------------------------------------------------
void bande(void){
    int i;
   for(i=1;i<41;i++){
        textbackground(2);
    printdirection("                ","right",105,i,0);
   }

   }


void decalrectangle(int much)
{int y;
if(much==1){y=11;}
if(much==2){y=21;}
if(much==3){y=31;}
textbackground(0);
textcolor(0);

gotoxy(1,y-10);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y-9);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y-8);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y-7);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y-6);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y-5);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y-4);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y-3);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y-2);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y-1);
delay(10);
textbackground(2);
textcolor(2);
gotoxy(1,y);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+1);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+2);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+3);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+4);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+5);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+6);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+7);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+8);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(1,y+9);

}
void moverect(char mot[4])

{ int i,y;
    if (strcmp(mot,"up")==0){y=35;
    for(i=0;i<25;i++){
    gotoxy(1,y-i);
textcolor(2);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
if(i!=0)
{gotoxy(1,y-i+5);
textbackground(0);
textcolor(0);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
 textbackground(2);
}delay(50);
}}
if(strcmp(mot,"down")==0)
{y=10;
    for(i=0;i<25;i++){
    gotoxy(1,y+i);
textcolor(2);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
if(i!=0)
{gotoxy(1,y+i);
textbackground(15);
textcolor(15);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
 textbackground(3);
}delay(50);
}

}
}
 int readkey(void) //Lit une touche du clavier
{
    int key;
    clearkeybuf();
    key=getch();
    if (key==0){
        key=getch()+256;}
    if( key==224){
        key=getch()+256;}

    return key;
}


void blancln(int nombreln)
{ int i;
for(i=0;i<nombreln;i++){printf(" \n");}
}
void printdirection(char mot[120],char direction[6],int x ,int y ,int delai)//Impression dans une direction donnée
{int i;

    if(strcmp(direction,"up")==0)
{for(i=0;i<strlen(mot);i++)
 {   gotoxy(x,y-i);
     printf("%c",mot[i]);
     delay(delai);

 }
}
    if(strcmp(direction,"down")==0)
    { for(i=0;i<strlen(mot);i++)
    {gotoxy(x,y+i);
     printf("%c",mot[i]);
     delay(delai);
    }

    }
    if(strcmp(direction,"right")==0)
    { for(i=0;i<strlen(mot);i++)
    {gotoxy(x+i,y);
    printf("%c",mot[i]);
    delay(delai);
    }}
    if(strcmp(direction,"left")==0)
    { for(i=0;i<strlen(mot);i++)
    {gotoxy(x-i,y);
    printf("%c",mot[strlen(mot)-i-1]);
    delay(delai);
    }

    }
textbackground(0);}
/***********************************************/
/*******************MODULES DE GESTION*********************/
























  /***********************************************/
  void Creation_listem (Pointeur_Ls *Mountete , int *Nbr_elements)
    {
      /** Variables locales **/
      Pointeur_Ls Mounq;
      Pointeur_Ls Mounp;
      string255 Mot;
      int N;
      int Cpt_moun;

      /** Corps du module **/
     Mot = malloc(255 * sizeof(string255));
     Allouer_Ls(&*Mountete ) ;
     Mounp  =  *Mountete ;
     N  =  ( Aleanombre(14 ) ) + 1 ;
     strcpy (Mot,   Aleachaine(N )) ;
     Aff_val_Ls(*Mountete , Mot ) ;
     Cpt_moun  =  1 ;
     while( ( Cpt_moun != *Nbr_elements )) {
       Allouer_Ls(&Mounq ) ;
       Aff_adr_Ls(Mounp , Mounq ) ;
       Mounp  =  Mounq ;
       N  =  ( Aleanombre(14 ) + 1 ) ;
       strcpy (Mot,   Aleachaine(N )) ;
       Aff_val_Ls(Mounp , Mot ) ;
       Cpt_moun  =  Cpt_moun + 1 ;

     } ;
     Aff_adr_Ls(Mounp , NULL ) ;

    }
  /********************************************************/
  void Affichage_listem (Pointeur_Ls *Tetemoun)
    {
      /** Variables locales **/
      Pointeur_Ls Actu_moun;

      /** Corps du module **/
     Actu_moun  =  *Tetemoun ;
     while( ( Actu_moun != NULL )) {
       printf ( " %s", Valeur_Ls(Actu_moun) ) ;
       Actu_moun  =  Suivant_Ls(Actu_moun ) ;

     } ;

    }
  /************************************************************/
  void Echange_mot (Pointeur_Ls *Mouna , Pointeur_Ls *Mounb)
    {
      /** Variables locales **/
      string255 Mounsauv;

      /** Corps du module **/
     Mounsauv = malloc(255 * sizeof(string255));
     strcpy (Mounsauv,   Valeur_Ls(*Mouna )) ;
     Aff_val_Ls(*Mouna , Valeur_Ls(*Mounb ) ) ;
     Aff_val_Ls(*Mounb , Mounsauv ) ;

    }
  /************************************************************/
  void Tri_lmotmo (Pointeur_Ls *Lmot_mouna)
    {
      /** Variables locales **/
      Pointeur_Ls Ptr_mouna;
      string255 Mot1;
      string255 Mot2;
      Pointeur_Ls _Px1;

      /** Corps du module **/
     Mot1 = malloc(255 * sizeof(string255));
     Mot2 = malloc(255 * sizeof(string255));
     Ptr_mouna  =  *Lmot_mouna ;
     while( ( Ptr_mouna != NULL ) && ( Suivant_Ls(Ptr_mouna ) != NULL )) {
       strcpy (Mot2,   Valeur_Ls(Suivant_Ls(Ptr_mouna ) )) ;
       strcpy (Mot1,   Valeur_Ls(Ptr_mouna )) ;
       if( (strcmp( Mot1, Mot2) > 0  )) {
         _Px1 =  Suivant_Ls(Ptr_mouna ) ;
         Echange_mot ( & Ptr_mouna , &_Px1) ;
         Ptr_mouna  =  *Lmot_mouna ;
         }
       else
         {
         Ptr_mouna  =  Suivant_Ls(Ptr_mouna ) ;

       } ;

     } ;

    }
  /******************************************************************/
  void Crea_arbremo (Pointeur_ATcb *Racine_moun , Pointeur_Ls *Lmot , int *Nbr_mot)
    {
      /** Variables locales **/
      Pointeur_ATcb Pmoun =NULL;
      Pointeur_ATcb Qmoun =NULL;
      Typestr_Tcb S;
      Typestr_Tcb P;
      int I;
      int nb=0;
      int Cpt;
      Pointeur_Ls Current=NULL;
      string255 Lettre;
      string255 Inser;
      string2 Exist;
      Pointeur_ATcb Arb_moun=NULL;
      Pointeur_ATcb Narb=NULL;
      Pointeur_ATcb Nouv=NULL;
      Pointeur_ATcb Larb=NULL;

      /** Corps du module **/
     S = malloc(sizeof(Typestr_Tcb));
     S->Champ1 = malloc(2 * sizeof(string2));
     P = malloc(sizeof(Typestr_Tcb));
     P->Champ1 = malloc(2 * sizeof(string2));
     Lettre = malloc(255 * sizeof(string255));
     Inser = malloc(255 * sizeof(string255));
     Exist = malloc(2 * sizeof(string2));
     *Racine_moun  =  NULL ;
    /*Insertion des premieres lettres*/
     Creernoeud_ATcb(&*Racine_moun ) ;
    /*Creation racine*/
     strcpy (Lettre,   Valeur_Ls(*Lmot )) ;
     Aff_struct1_Tcb(S  , Caract(Lettre , 1 ) ) ;
     if( ( Longchaine(Lettre ) > 1 )) {
       Aff_struct2_Tcb(S  , False ) ;
       }
     else
       {
       Aff_struct2_Tcb(S  , True ) ;

     } ;
     Aff_info_ATcb(*Racine_moun , S ) ;
     Pmoun  =  *Racine_moun ;
     Current  =  Suivant_Ls(*Lmot ) ;
    /*Insertion premiere lettre des elements suivants*/
     while( ( Current != NULL )) {
       strcpy (Lettre,   Valeur_Ls(Current )) ;
      /*Eviter qu'un meme caractere se repete*/
       if( (strcmp( Caract(Lettre , 1 ), Struct1_Tcb(Info_ATcb(Pmoun )  )) != 0  )) {
         Creernoeud_ATcb(&Qmoun ) ;
         Aff_fd_ATcb(Pmoun , Qmoun ) ;
         Pmoun  =  Qmoun ;
        /*Affectation des valeurs*/
         Aff_struct1_Tcb(S  , Caract(Lettre , 1 ) ) ;
         if( ( Longchaine(Lettre ) > 1 )) {
           Aff_struct2_Tcb(S  , False ) ;
           }
         else
           {
           Aff_struct2_Tcb(S  , True ) ;

         } ;

         Aff_info_ATcb(Qmoun , S ) ;

       } ;
       Current  =  Suivant_Ls(Current ) ;

     } ;
    /*Insertion de la suite des mots*/
     Current  =  *Lmot ;
    /*Retour au debut de la liste des mots*/
     Cpt  =  1 ;
     while( ( Cpt < *Nbr_mot + 1 )) {
       Arb_moun  =  *Racine_moun ;
      /* Affectation globale de structure */
       strcpy(S->Champ1,   Info_ATcb(*Racine_moun )->Champ1);
       S->Champ2 =   Info_ATcb(*Racine_moun )->Champ2;
 ;
       strcpy (Exist,   Struct1_Tcb(S  )) ;
       strcpy (Inser,   Valeur_Ls(Current )) ;
      /*Recherche de la premiere lettre*/
       while( (strcmp( Caract(Inser , 1 ), Exist) != 0  ) && ( Arb_moun != NULL )) {
         Arb_moun  =  Fd_ATcb(Arb_moun ) ;
      /* Affectation globale de structure */
         strcpy(S->Champ1,   Info_ATcb(Arb_moun )->Champ1);
         S->Champ2 =   Info_ATcb(Arb_moun )->Champ2;
 ;
         strcpy (Exist,   Struct1_Tcb(S  )) ;

       } ;
       I  =  2 ;
      /*Insertion de la suite*/
       while( ( I < Longchaine(Inser ) + 1 )) {
         if( ( Fg_ATcb(Arb_moun ) == NULL )) {
           while( ( I < Longchaine(Inser ) + 1 )) {
             Creernoeud_ATcb(&Nouv ) ;
             Aff_fg_ATcb(Arb_moun , Nouv ) ;
             Aff_struct1_Tcb(S  , Caract(Inser , I ) ) ;
             if( ( I == Longchaine(Inser ) )) {
               Aff_struct2_Tcb(S  , True ) ;
               }
             else
               {
               Aff_struct2_Tcb(S  , False ) ;

             } ;
             Aff_info_ATcb(Nouv , S ) ;
             Arb_moun  =  Nouv ;
             I  =  I + 1 ;

           } ;
           }
         else
           {
           Creernoeud_ATcb(&Nouv ) ;
           Narb  =  Fg_ATcb(Arb_moun ) ;
           while( ( Narb != NULL )) {
             Larb  =  Narb ;
             Narb  =  Fd_ATcb(Narb ) ;

           } ;
          /*Premier elet a inserer a droite*/
           Aff_fd_ATcb(Larb , Nouv ) ;
           Aff_struct1_Tcb(S  , Caract(Inser , I ) ) ;
           if( ( I == Longchaine(Inser ) )) {
             Aff_struct2_Tcb(S  , True ) ;
             }
           else
             {
             Aff_struct2_Tcb(S  , False ) ;

           } ;
           Aff_info_ATcb(Nouv , S ) ;
           Arb_moun  =  Nouv ;
           I  =  I + 1 ;
           while( ( I < Longchaine(Inser ) + 1 )) {
             Creernoeud_ATcb(&Nouv ) ;
             Aff_fg_ATcb(Arb_moun , Nouv ) ;
             Aff_struct1_Tcb(S  , Caract(Inser , I ) ) ;
             if( ( I == Longchaine(Inser ) )) {
               Aff_struct2_Tcb(S  , True ) ;
               }
             else
               {
               Aff_struct2_Tcb(S  , False ) ;

             } ;
             Aff_info_ATcb(Nouv , S ) ;
             Arb_moun  =  Nouv ;
             I  =  I + 1 ;

           } ;

         } ;

       } ;
       Cpt  =  Cpt + 1 ;
       Current  =  Suivant_Ls(Current ) ;



     } ;

    }
  /**********************/
  void Afficher_arbre (Pointeur_ATcb *Tr)
    {
      /** Variables locales **/
      Typestr_Tcb Str;
      Pointeur_ATcb _Px1;
      Pointeur_ATcb _Px2;

      /** Corps du module **/
     Str = malloc(sizeof(Typestr_Tcb));
     Str->Champ1 = malloc(2 * sizeof(string2));
     if( ( *Tr != NULL )) {
       _Px1 =  Fg_ATcb(*Tr ) ;
       Afficher_arbre ( &_Px1) ;
      /* Affectation globale de structure */
       strcpy(Str->Champ1,   Info_ATcb(*Tr )->Champ1);
       Str->Champ2 =   Info_ATcb(*Tr )->Champ2;
 ;
       printf ( " %s", Struct1_Tcb(Str) );
       printf ( " %d", Struct2_Tcb(Str) ) ;
       _Px2 =  Fd_ATcb(*Tr ) ;
       Afficher_arbre ( &_Px2) ;

     } ;

    }
  /******************************/
  void Affichage (Pointeur_ATcb *Rnoe , string255 *Mot)
    {
      /** Variables locales **/
      Typestr_Tcb Str;
      string255 Mot2;
      string255 _Sx;
      Pointeur_ATcb _Px1;
      char c[30];
      Pointeur_ATcb _Px2;

      /** Corps du module **/
     Str = malloc(sizeof(Typestr_Tcb));
     Str->Champ1 = malloc(2 * sizeof(string2));
     Mot2 = malloc(255 * sizeof(string255));
     _Sx = malloc(255 * sizeof(string255));
     if( ( *Rnoe != NULL )) {
       strcpy (Mot2,   *Mot) ;
      /* Affectation globale de structure */
       strcpy(Str->Champ1,   Info_ATcb(*Rnoe )->Champ1);
       Str->Champ2 =   Info_ATcb(*Rnoe )->Champ2;
 ;
       strcpy (_Sx, *Mot);
       strcpy (*Mot,  strcat(_Sx, Struct1_Tcb(Str  ))) ;
       if( ( Struct2_Tcb(Str  ) != False )) {

        // printf ( "%17s   |   ", *Mot) ;
         if(k<128){
                 if(k<128){
                printf ( "%17s   |   ", *Mot) ;
        }
        else{
        printf("\n");
        printf("\n");
        printf("\n");
        textbackground(12);
        printf("\n                                         Voulez vous continuer oui ou non!?                                             \n");
        textbackground(0);
        scanf("%s",c);
        if(strcmp(c,"oui")==0){ textbackground(0);system("cls");textbackground(2);k=0;
        printf ("\n                                                                                                                        ") ;
        printf ("\n                                                 Affichage de tous les mots                                             ") ;
        printf ("\n                                                                                                                        ") ;
        printf ("\n                                                                                                                        ") ;
        textbackground(0);
        }
        else system("pause");
//            break;
        }

         k ++;
        }
        else{
        printf("\n");
        printf("\n");
        printf("\n");
        textbackground(12);
        printf("\n                                         Voulez vous continuer oui ou non!?                                             \n");
        textbackground(0);
        scanf("%s",c);
        if(strcmp(c,"oui")==0){ textbackground(0);system("cls");textbackground(2);k=0;
        printf ("\n                                                                                                                        ") ;
        printf ("\n                                                 Affichage de tous les mots                                             ") ;
        printf ("\n                                                                                                                        ") ;
        printf ("\n                                                                                                                        ") ;
        textbackground(0);
        }
        else system("pause");
//            break;
        }

       //  k ++;
        //printf("aahhhh ya trydha :    %d",k);
         //printf("\n");

       } ;
       _Px1 =  Fd_ATcb(*Rnoe ) ;
       Affichage ( &_Px1, & Mot2 ) ;
       _Px2 =  Fg_ATcb(*Rnoe ) ;
       Affichage ( &_Px2, & *Mot) ;

     } ;

    }
  /***********************************/
  void Affichage2 (Pointeur_ATcb *Rnoe , string255 *Mot , int *Taille3)
    {
      /** Variables locales **/
      Typestr_Tcb Str;
      string255 Mot2;
      int Print;
      string255 _Sx;
      Pointeur_ATcb _Px1;
      Pointeur_ATcb _Px2;

      /** Corps du module **/
     Str = malloc(sizeof(Typestr_Tcb));
     Str->Champ1 = malloc(2 * sizeof(string2));
     Mot2 = malloc(255 * sizeof(string255));
     _Sx = malloc(255 * sizeof(string255));
     if( ( *Rnoe != NULL )) {
       strcpy (Mot2,   *Mot) ;
      /* Affectation globale de structure */
       strcpy(Str->Champ1,   Info_ATcb(*Rnoe )->Champ1);
       Str->Champ2 =   Info_ATcb(*Rnoe )->Champ2;
 ;
       strcpy (_Sx, *Mot);
       strcpy (*Mot,  strcat(_Sx, Struct1_Tcb(Str  ))) ;
       if( ( Struct2_Tcb(Str  ) != False )) {
         Print  =  0 ;
         if( (strcmp( ( Caract(*Mot , *Taille3 ) ), ( Caract(*Mot , *Taille3 ) )) != 0  )) {
           Print  =  1 ;

         } ;
         if( Print == 0) {
           printf ( " %s", *Mot ) ;
           printf("\n");

         } ;

       } ;
       _Px1 =  Fd_ATcb(*Rnoe ) ;
       Affichage2 ( &_Px1, & Mot2 , & *Taille3 ) ;
       _Px2 =  Fg_ATcb(*Rnoe ) ;
       Affichage2 ( &_Px2, & *Mot , & *Taille3 ) ;

     } ;

    }
  /********************  affichge rechreche *************************/
  void Affichage_r (Pointeur_ATcb *Rnoe , string255 *Mot , int *Type , string255 *Ch)
    {
      /** Variables locales **/
      Typestr_Tcb Str;
      string255 Mot2;
      int I;
      int J;
      int D;
      int Taille;
      int taille_m;
      char c[10];
      int Print;
      string255 _Sx;
      Pointeur_ATcb _Px1;
      Pointeur_ATcb _Px2;

      /** Corps du module **/
     Str = malloc(sizeof(Typestr_Tcb));
     Str->Champ1 = malloc(2 * sizeof(string2));
     Mot2 = malloc(255 * sizeof(string255));
     _Sx = malloc(255 * sizeof(string255));
     if( ( *Rnoe != NULL )) {
       strcpy (Mot2,   *Mot) ;
      /* Affectation globale de structure */
       strcpy(Str->Champ1,   Info_ATcb(*Rnoe )->Champ1);
       Str->Champ2 =   Info_ATcb(*Rnoe )->Champ2;
 ;
       strcpy (_Sx, *Mot);
       strcpy (*Mot,  strcat(_Sx, Struct1_Tcb(Str  ))) ;
       if( ( Struct2_Tcb(Str  ) != False )) {
         Taille  =  Longchaine(*Ch ) ;
         if( *Type == 1) {
          /************  rechreche "*"" avec/sans"?" *************/
           I  =  1 ;
           while( ( I <= Taille )) {
             if( (strcmp( Caract(*Ch , I ), "?") == 0  )) {
               *Type  =  4 ;

             } ;
             I  =  I + 1 ;

           } ;
           if( ( *Type == 1 ) && (strcmp( Caract(*Ch , Taille ), "*") == 0  )) {
             *Type  =  3 ;

           } ;
           if( ( *Type == 1 ) && (strcmp( Caract(*Ch , Taille ), "*") != 0  )) {
             *Type  =  5 ;

           } ;

         } ;
        /*************  '???' sans '*'' ***********/
         if( *Type == 2) {
           if( Longchaine(*Mot ) == Taille) {
             Print  =  0 ;
             I  =  0 ;
             while( ( I <= Taille )) {
               if( (strcmp( Caract(*Ch , I ), "?") != 0  ) && (strcmp( Caract(*Ch , I ), Caract(*Mot , I )) != 0  )) {
                 Print  =  1 ;

               } ;
               I  =  I + 1;
             } ;
             }
           else
             {
             Print  =  1 ;

           } ;
           if( ( Print == 0 )) {
              //  printf("---");
             if(k<128){
                printf ( "%17s   |   ", *Mot) ;
        }
        else{
        printf("\n");
        printf("\n");
        printf("\n");
        textbackground(12);
        printf("\n                                         Voulez vous continuer oui ou non!?                                             \n");
        textbackground(0);
        scanf("%s",c);
        if(strcmp(c,"oui")==0){ textbackground(0);system("cls");textbackground(2);k=0;
        printf ("\n                                                                                                                        ") ;
        printf ("\n                                                 Affichage de tous les mots                                             ") ;
        printf ("\n                                                                                                                        ") ;
        printf ("\n                                                                                                                        ") ;
        textbackground(0);
        }
        else system("pause");
//            break;
        }

         k ++;
              //  printf("---");
             //printf("\n");

           } ;

         } ;
        /*************  *Mot*  ***********************/
         if( *Type == 3) {
                 //  printf("---");
             if(k<128){
                printf ( "%17s   |   ", *Mot) ;
        }
        else{
        printf("\n");
        printf("\n");
        printf("\n");
        textbackground(12);
        printf("\n                                         Voulez vous continuer oui ou non!?                                             \n");
        textbackground(0);
        scanf("%s",c);
        if(strcmp(c,"oui")==0){ textbackground(0);system("cls");textbackground(2);k=0;
        printf ("\n                                                                                                                        ") ;
        printf ("\n                                                 Affichage de tous les mots                                             ") ;
        printf ("\n                                                                                                                        ") ;
        printf ("\n                                                                                                                        ") ;
        textbackground(0);
        }
        else system("pause");
//            break;
        }

         k ++;
              //  printf("---");
             //printf("\n");
          // Affichage ( & *Rnoe , & *Mot ) ;

         } ;
        /*******************  fiha '*'' et '?' ******************/
         if( *Type == 4) {
           Print  =  0 ;
           while( ( I <= Taille )) {
             if( (strcmp( Caract(*Ch , I ), "*") == 0  )) {
               J  =  1 ;
               while( ( J <= I )) {
                 if( (strcmp( Caract(*Ch , J ), "?") != 0  ) && (strcmp( Caract(*Ch , J ), Caract(*Mot , J )) != 0  )) {
                   Print  =  1 ;

                 }
                 J  =  J + 1 ;
               } ;
               D  =  Taille - I ;
               J  =  0 ;
               while( ( J < D )) {
                 if( (strcmp( Caract(*Ch , Taille - J ), "?") != 0  ) && (strcmp( Caract(*Ch , Taille - J ), Caract(*Mot , taille_m - J )) != 0  )) {
                   Print  =  1 ;

                 } ;
                    J  =  J + 1 ;
               } ;

             } ;
             I  =  I + 1 ;

           } ;
           if( ( Print == 0 )) {
              //  printf("---");
            if(k<128){
                printf ( "%17s   |   ", *Mot) ;
        }
        else{
        printf("\n");
        printf("\n");
        printf("\n");
        textbackground(12);
        printf("\n                                         Voulez vous continuer oui ou non!?                                             \n");
        textbackground(0);
        scanf("%s",c);
        if(strcmp(c,"oui")==0){ textbackground(0);system("cls");textbackground(2);k=0;
        printf ("\n                                                                                                                        ") ;
        printf ("\n                                                 Affichage de tous les mots                                             ") ;
        printf ("\n                                                                                                                        ") ;
        printf ("\n                                                                                                                        ") ;
        textbackground(0);
        }
        else system("pause");
//            break;
        }

         k ++;
              //  printf("---");
             //printf("\n");

           } ;

         } ;
        /*******************  Mo*TT ******************/
         if( *Type == 5) {
         taille_m = Longchaine(*Mot)       ;
          // Affichage2 ( & *Rnoe , & *Mot , & Taille ) ;
          if( (strcmp( ( Caract(*Mot , taille_m ) ), ( Caract(*Ch , Taille ) )) != 0  )) {
             Print  =  1 ;

           } ;
           if( Print == 0) {
           //     printf("---");
             if(k<128){
                printf ( "%17s   |   ", *Mot) ;
        }
        else{
        printf("\n");
        printf("\n");
        printf("\n");
        textbackground(12);
        printf("\n                                         Voulez vous continuer oui ou non!?                                             \n");
        textbackground(0);
        scanf("%s",c);
        if(strcmp(c,"oui")==0){ textbackground(0);system("cls");textbackground(2);k=0;
        printf ("\n                                                                                                                        ") ;
        printf ("\n                                                 Affichage de tous les mots                                             ") ;
        printf ("\n                                                                                                                        ") ;
        printf ("\n                                                                                                                        ") ;
        textbackground(0);
        }
        else system("pause");
//            break;
        }

         k ++;
         //  printf("---");
          //   printf("\n");

           } ;

         } ;

       } ;
       _Px1 =  Fd_ATcb(*Rnoe ) ;
       Affichage_r ( &_Px1, & Mot2 , & *Type , & *Ch ) ;
       _Px2 =  Fg_ATcb(*Rnoe ) ;
       Affichage_r ( &_Px2, & *Mot , & *Type , & *Ch ) ;

     } ;

    }
  /***************************rrechreche *****************************/
  void Recherche (Pointeur_ATcb *Racineee)
    {
      /** Variables locales **/
      Pointeur_ATcb Par;
      string255 Ch;
      string255 Ch2;
      string2 Cmp;
      string2 Cmp2;
      string2 Mot;
      int I;
      int J;
      int Cbn;
      int Taille2;
      int Type;
      int Taille;
      int Gh;
      int Lecture;
      Typestr_Tcb P;
      string255 _Sx;

      /** Corps du module **/
     Ch = malloc(255 * sizeof(string255));
     Ch2 = malloc(255 * sizeof(string255));
     Cmp = malloc(2 * sizeof(string2));
     Cmp2 = malloc(2 * sizeof(string2));
     Mot = malloc(2 * sizeof(string2));
     P = malloc(sizeof(Typestr_Tcb));
     P->Champ1 = malloc(2 * sizeof(string2));
     _Sx = malloc(255 * sizeof(string255));
     Par  =  *Racineee ;
     Lecture  =  0 ;
     while( ( Lecture == 0 )) {
        printf("\n");
        printf("\n");
       printf ( " %s", "donner le mot : " ) ;
      /* lecture */
       scanf ( " %[^\n]", Ch ) ;
       printf("\n");
       printf ( " %s", "vous avez entre :" );
       printf ( " %s \n", Ch ) ;
       printf("\n recherche\n");
       printf("\n");
       printf ( " %s", "les mots sont: \n" ) ;
       printf("\n");
       Taille  =  Longchaine(Ch ) ;
      /* condition*/
       I  =  1 ;
       Type  =  0 ;
       Gh  =  0 ;
       while( ( I <= Taille )) {
         Lecture  =  1 ;
         if(strcmp( Caract(Ch , I ), "*") == 0 ) {
           Gh  =  Gh + 1 ;
           Type  =  1 ;
           Lecture  =  1 ;
           if( ( Gh > 1 )) {
             printf ( " %s", "le mot est faux" ) ;
             Lecture  =  0 ;
             I  =  Taille ;

           } ;

         } ;
         if( (strcmp( Caract(Ch , I ), "?") == 0  ) && ( Type == 0 )) {
           Type  =  2 ;
           Lecture  =  1 ;

         } ;
         if( (strcmp( Caract(Ch , 1 ), "*") == 0  ) || (strcmp( Caract(Ch , 1 ), "?") == 0  )) {
           printf ( " %s", "le mot est faux " ) ;
           I  =  Taille ;
           Lecture  =  0 ;

         } ;
         I  =  I + 1 ;

       }
     } ;
     I  =  1 ;
     Cbn  =  1 ;
     strcpy (Ch2,   "") ;
     while( ( I <= Taille ) && ( Cbn != 0 )) {
       if( (strcmp( Caract(Ch , I ), "?") == 0  ) || (strcmp( Caract(Ch , I ), "*") == 0  )) {
         Cbn  =  0 ;

       } ;
       if( (strcmp( Caract(Ch , I ), "?") != 0  ) && (strcmp( Caract(Ch , I ), "*") != 0  ) && ( Cbn != 0 )) {
         strcpy (_Sx, Ch2);
         strcpy (Ch2,  strcat(_Sx, Caract(Ch , I ))) ;

       } ;
       I  =  I + 1 ;

     } ;
     Taille2  =  Longchaine(Ch2 ) ;
     I  =  0 ;
    /************************  Rechreche CAAA.... **************************/
     while( ( I < Taille2 ) && ( Par != NULL )) {
       I  =  I + 1 ;
       strcpy (Cmp2,   Caract(Ch2 , I )) ;
      /* Affectation globale de structure */
       strcpy(P->Champ1,   Info_ATcb(Par )->Champ1);
       P->Champ2 =   Info_ATcb(Par )->Champ2;
 ;
       strcpy (Cmp,   Struct1_Tcb(P  )) ;
      /*si cmp < cmp2
            ecrire('n"existe pas works') ;
            i := taille2+1;
         finsi; */
       if(strcmp( Cmp, Cmp2) == 0 ) {
         Par  =  Fg_ATcb(Par ) ;
         if( I == Taille2) {
           if( Type == 0) {
             ;
             if( ( Struct2_Tcb(P  ) == True )) {
               printf ( " %s", Ch2 );
               printf ( " %s", "existe" ) ;
               }
             else
               {
               printf ( " %s", "n'existe pas" ) ;

             } ;
             }
           else
             {
             Affichage_r ( & Par , & Ch2 , & Type , & Ch ) ;

           } ;

         } }
      /* cmp # cmp2 */
       else
         {
         Par  =  Fd_ATcb(Par ) ;
         I  =  I - 1 ;

       } ;
       if( ( Par == NULL )) {
         printf ( " %s", "n'existe pas" ) ;

       }
     }
    }

/********** module cree depuis un fichier txt *******************/

void Creation_listem_f (Pointeur_Ls *Mountete ,char premier[30],int *Cpt_moun)
    {
      /** Variables locales **/
      Pointeur_Ls Mounq;
      Pointeur_Ls Mounp;
      string255 Mot;
      int N;
      int cpt=1;
     // int Cpt_moun;
      char mot[30],liste[30];
      FILE *fic = fopen("test.txt","r");

      /** Corps du module **/
     Mot = malloc(255 * sizeof(string255));
     Allouer_Ls(&*Mountete ) ;
     Mounp  =  *Mountete ;
     strcpy(mot,premier);
     //strcpy(mot,premier);
     Aff_val_Ls(*Mountete , mot ) ;
     //Cpt_moun  =  1 ;
     while( !feof(fic)) {
         cpt = cpt+1;
            if (cpt > 2)
            {
               Allouer_Ls(&Mounq ) ;
                Aff_adr_Ls(Mounp , Mounq ) ;
                Mounp  =  Mounq ;
            }

       fscanf(fic,"%s",mot);
       Aff_val_Ls(Mounp , mot ) ;
       //Cpt_moun  =  Cpt_moun + 1 ;

     } ;
     Aff_adr_Ls(Mounp , NULL ) ;
     //printf("cpt mooun = %d",Cpt_moun);
     fclose(fic);

    }










/***************main*****************************/

  int main(int argc, char *argv[])
    {/*
     Lettre = malloc(255 * sizeof(string255));
     Tabl = malloc(15 * 255  * sizeof(string255));
     int _Izw2;for (_Izw2=0; _Izw2<15; ++_Izw2);
     int cpt=0;
     char mot[30],premier[30],liste[30];
       Tabl[_Izw2]= malloc(255 * sizeof(string255));
     Mot = malloc(255 * sizeof(string255));


      E  =  15;
    // printf ( " %d", E ) ;

    /*************************** il faut 9bl la fonction t3 fichier ndirou hadha *******************/
     /*FILE *fic = fopen("test.txt","r");

    while(!feof(fic))
           {
                fscanf(fic,"%s",mot);
                //printf("%s \n",mot);
              //  strcpy(liste,mot);
                cpt = cpt +1;
                if (cpt == 1){
                    strcpy(premier,mot);
                }
               // printf("%s",liste);
                //printf("\n");

           }printf("%d",cpt);


    fclose(fic);
    E = cpt;
    printf("this is E = %d",E);
    printf("lay lay %s \n",premier);

     Creation_listem_f (& Tete,premier,&E );

   /******************************** chghol hadha kml l'appel + rani zedt des variables*******************************/
     //Creation_listem ( & Tete , & E ) ;
    /* Tri_lmotmo ( & Tete ) ;
     printf ( " %s", "" );
     printf ( " %s", " Tri de la liste reussi" ) ;
     Affichage_listem ( & Tete ) ;
     printf ( " %s", " creation arb" ) ;
     Crea_arbremo ( & Racin , & Tete , & E ) ;
     printf ( " %s", "Affichage des mots" ) ;
     strcpy (Mot,   "-") ;
     //Affichage ( & Racin , & Mot ) ;*/
     //Recherche ( & Racin ) ;
     chaine lechoix[]=  { "   >>     Cree l'arbre Aleatoire/Ficher     <<   ",
                          "   >>       Afficher l'arbre des mots       <<   ",
                          "   >>        Chrecher uu ou des mot(s)      <<   ",
                          "   >>               .Read.me                <<   ",
                          "   >>                                       <<   ",
                          "   >>                 EXIT                  <<   ",};


                       //   intro();
    menu(lechoix,Racin);


      system("PAUSE");
      return 0;
    }
