SOIENT
       I,E : ENTIER ;
       Lettre : CHAINE ;
       Tete : POINTEUR VERS UNE LISTE DE CHAINE ;
       Creation_listem : ACTION ;
       Affichage_listem : ACTION ;
       Echange_mot : ACTION ;
       Tri_lmotmo : ACTION ;
       Crea_arbremo : ACTION;
       Racin: ARB DE ( CAR , BOOLEEN ) ;
       afficher_arbre : ACTION;
       Affichage : ACTION;
       Affichage_r : ACTION;
       Affichage2 : ACTION;
       Tabl UN TABLEAU ( 15 ) DE CHAINE ;
       Mot : CHAINE;
       recherche : action;
       Racineee DES POINTEUR VERS UN ARB DE ( CAR , BOOLEEN ) ;
      /*************************PPPPPPPPPROGRAMME PRINCIPAL*******************************/

   DEBUT
       E := 15;
       ECRIRE ( E ) ;
       APPEL Creation_listem ( Tete , E ) ;
       APPEL Tri_lmotmo ( Tete ) ;
       ECRIRE ( '' , ' Tri de la liste réussi' ) ;
       APPEL Affichage_listem ( Tete ) ;
       APPEL Crea_arbremo( Racin, Tete,E);
       Ecrire('Affichage des mots');
       Mot:='-';
       APPEL Affichage(Racin, Mot);
       Appel recherche(Racin);
   FIN
  /***********************************************/
   ACTION Creation_listem ( Mountete , Nbr_elements )
   SOIENT
       Mountete : POINTEUR VERS UNE LISTE DE CHAINE ;
       Nbr_elements : ENTIER ;
       Mounq , Mounp : POINTEUR VERS UNE LISTE DE CHAINE ;
       Mot : CHAINE ;
       N : ENTIER ;
       Cpt_moun : ENTIER ;

   DEBUT
       ALLOUER ( Mountete ) ;
       Mounp := Mountete ;
       N := ( ALEANOMBRE ( 14 ) ) + 1 ;
       Mot := ALEACHAINE ( N ) ;
       AFF_VAL ( Mountete , Mot ) ;
       Cpt_moun := 1 ;
       TANTQUE ( Cpt_moun <> Nbr_elements )
           ALLOUER ( Mounq ) ;
           AFF_ADR ( Mounp , Mounq ) ;
           Mounp := Mounq ;
           N := ( ALEANOMBRE ( 14 ) + 1 ) ;
           Mot := ALEACHAINE ( N ) ;
           AFF_VAL ( Mounp , Mot ) ;
           Cpt_moun := Cpt_moun + 1 ;

       FINTANTQUE ;
       AFF_ADR ( Mounp , NIL ) ;

   FIN
  /********************************************************/
   ACTION Affichage_listem ( Tetemoun )
   SOIENT
       Tetemoun : POINTEUR VERS UNE LISTE DE CHAINE ;
       Actu_moun : POINTEUR VERS UNE LISTE DE CHAINE ;

   DEBUT
       Actu_moun := Tetemoun ;
       TANTQUE ( Actu_moun <> NIL )
           ECRIRE ( VALEUR ( Actu_moun ) ) ;
           Actu_moun := SUIVANT ( Actu_moun ) ;

       FINTANTQUE ;

   FIN
  /************************************************************/
   ACTION Echange_mot ( Mouna , Mounb )
   SOIENT
       Mouna , Mounb DES POINTEURS VERS UNE LISTE DE CHAINE ;
       Mounsauv : CHAINE ;

   DEBUT
       Mounsauv := VALEUR ( Mouna ) ;
       AFF_VAL ( Mouna , VALEUR ( Mounb ) ) ;
       AFF_VAL ( Mounb , Mounsauv ) ;

   FIN
  /************************************************************/
   ACTION Tri_lmotmo ( Lmot_mouna )
   SOIENT
       Lmot_mouna : POINTEUR VERS UNE LISTE DE CHAINE ;
       Ptr_mouna : POINTEUR VERS UNE LISTE DE CHAINE ;
       Mot1 , Mot2 : CHAINE ;

   DEBUT
       Ptr_mouna := Lmot_mouna ;
       TANTQUE ( Ptr_mouna <> NIL ) ET ( SUIVANT ( Ptr_mouna ) <> NIL )
           Mot2 := VALEUR ( SUIVANT ( Ptr_mouna ) ) ;
           Mot1 := VALEUR ( Ptr_mouna ) ;
           SI ( Mot1 > Mot2 )
               APPEL Echange_mot ( Ptr_mouna , SUIVANT ( Ptr_mouna ) ) ;
               Ptr_mouna := Lmot_mouna ;

           SINON
               Ptr_mouna := SUIVANT ( Ptr_mouna ) ;

           FINSI ;

       FINTANTQUE ;

   FIN
  /******************************************************************/
 ACTION Crea_arbremo ( Racine_moun , Lmot , Nbr_mot )
 SOIENT
     Racine_moun , Pmoun , Qmoun : ARB DE( CAR , BOOLEEN ) ;
     S , P : STRUCTURE ( CAR , BOOLEEN ) ;
     Nbr_mot , I , Cpt : ENTIER ;
     Lmot , Current : POINTEUR VERS UNE LISTE DE CHAINES ;
     Lettre : CHAINE ;
     Inser  : CHAINE ;
     Exist  : CAR;
     Arb_moun , Narb , Nouv, larb : ARB DE ( CAR , BOOLEEN ) ;

 DEBUT
      Racine_moun:=Nil;
    /*Insertion des premieres lettres*/
      CREERNOEUD ( Racine_moun ) ;
      /*Creation racine*/
      Lettre := VALEUR ( Lmot ) ;
      AFF_STRUCT ( S , 1 , CARACT ( Lettre , 1 ) ) ;
      SI ( LONGCHAINE ( Lettre ) > 1 )
         AFF_STRUCT ( S , 2 , FAUX ) ;
     SINON
         AFF_STRUCT ( S , 2 , VRAI ) ;
     FINSI ;
     AFF_INFO ( Racine_moun , S ) ;
     Pmoun := Racine_moun ;
     Current := SUIVANT ( Lmot ) ;
    /*Insertion premiere lettre des elements suivants*/
     TANTQUE ( Current <> NIL )
         Lettre := VALEUR ( Current ) ;
         SI ( CARACT ( Lettre , 1 ) <> STRUCT(Info(Pmoun),1) )
        /*Eviter qu'un meme caractere se repete*/
             CREERNOEUD ( Qmoun ) ;
             AFF_FD ( Pmoun , Qmoun ) ;
             Pmoun := Qmoun ;
            /*Affectation des valeurs*/
             AFF_STRUCT ( S , 1 , CARACT ( Lettre , 1 ) ) ;
             SI ( LONGCHAINE ( Lettre ) > 1 )
                 AFF_STRUCT ( S , 2 , FAUX ) ;
             SINON
                 AFF_STRUCT ( S , 2 , VRAI ) ;
             FINSI ;
             AFF_INFO ( Qmoun, S ) ;
         FINSI ;
         Current := SUIVANT ( Current ) ;
     FINTANTQUE ;

    /*Insertion de la suite des mots*/
     Current := Lmot ;
    /*Retour au debut de la liste des mots*/
     Cpt := 1 ;
     TANTQUE ( Cpt < Nbr_mot+1 )
         Arb_moun := Racine_moun ;
         S := INFO ( Racine_moun ) ;
         Exist := STRUCT ( S , 1 ) ;
         Inser := VALEUR ( Current ) ;
        /*Recherche de la premiere lettre*/
         TANTQUE ( CARACT ( Inser , 1 ) <> Exist )  ET (Arb_moun<>NIL)
             Arb_moun := FD ( Arb_moun ) ;
             S := INFO ( Arb_moun ) ;
             Exist := STRUCT ( S , 1 ) ;
         FINTANTQUE ;
         I := 2 ;
         TANTQUE ( I < LONGCHAINE ( Inser )+1 )
          /*Insertion de la suite*/
             SI ( FG ( Arb_moun ) = NIL )
               TANTQUE(I< LONGCHAINE(inser)+1)
                  CREERNOEUD ( Nouv ) ;
                  AFF_FG ( Arb_moun , Nouv ) ;
                  AFF_STRUCT ( S , 1 , CARACT ( Inser , I ) ) ;
                  SI ( I = LONGCHAINE ( Inser ) )
                     AFF_STRUCT ( S , 2 , VRAI ) ;
                  SINON
                     AFF_STRUCT ( S , 2 , FAUX ) ;
                  FINSI ;
                  AFF_INFO ( Nouv , S ) ;
                  Arb_moun:=Nouv;
                 i:=i+1;
               FINTANTQUE;
             SINON
                CREERNOEUD ( Nouv ) ;
                 Narb := FG ( Arb_moun ) ;
                 TANTQUE ( Narb <> NIL )
                     larb:=Narb;
                     Narb := FD ( Narb ) ;
                 FINTANTQUE ;
                 /*Premier elet a inserer a droite*/
                   AFF_FD ( larb , Nouv ) ;
                    AFF_STRUCT ( S , 1 , CARACT ( Inser , I ) ) ;
                    SI ( I  = LONGCHAINE ( Inser ) )
                       AFF_STRUCT ( S , 2 , VRAI ) ;
                    SINON
                       AFF_STRUCT ( S , 2 , FAUX ) ;
                    FINSI ;
                    AFF_INFO ( Nouv , S ) ;
                    Arb_moun:=nouv;
                    I:=i+1;
                 TANTQUE(I< LONGCHAINE(inser)+1)
                    CREERNOEUD ( Nouv ) ;
                    AFF_FG ( Arb_moun , Nouv ) ;
                    AFF_STRUCT ( S , 1 , CARACT ( Inser , I ) ) ;
                    SI ( I  = LONGCHAINE ( Inser ) )
                       AFF_STRUCT ( S , 2 , VRAI ) ;

                    SINON
                       AFF_STRUCT ( S , 2 , FAUX ) ;

                    FINSI ;
                    AFF_INFO ( Nouv , S ) ;
                    Arb_moun:=nouv;
                    I:=i+1;
                  FINTANTQUE;
             FINSI;
         FINTANTQUE ;
         Cpt := Cpt + 1 ;
        Current:=SUIVANT(Current);
     FINTANTQUE ;

 FIN
 /**********************/
 ACTION afficher_arbre(tr)
SOIENT
tr UN POINTEUR VERS UN ARB DE (CAR,BOOLEEN);
str UNE STRUCTURE (CAR,BOOLEEN);
DEBUT
     SI(tr<>NIL)
           APPEL afficher_arbre(FG(tr));
           str:=INFO(tr);
           ECRIRE(STRUCT(str,1),STRUCT(str,2));
           APPEL afficher_arbre(FD(tr));
     FSI;
FIN
/******************************/
ACTION Affichage ( Rnoe , Mot )
   SOIENT
       Rnoe DES POINTEUR VERS UN ARB DE ( CAR , BOOLEEN ) ;
       Str UNE STRUCTURE ( CAR , BOOLEEN ) ;
       Mot , Mot2 UNE CHAINE ;


   DEBUT
       SI ( Rnoe <> NIL )
           Mot2 := Mot ;
           Str := INFO ( Rnoe ) ;
           Mot := Mot + STRUCT ( Str , 1 ) ;
           SI ( STRUCT ( Str , 2 ) <>FAUX  )

               ECRIRE ( Mot ) ;
           FSI ;
           APPEL Affichage ( FD ( Rnoe ) ,Mot2 ) ;
           APPEL Affichage ( FG ( Rnoe ) ,Mot ) ;


       FSI ;

   FIN
/***********************************/
ACTION Affichage2 ( Rnoe , Mot ,taille3)
   SOIENT
       Rnoe DES POINTEUR VERS UN ARB DE ( CAR , BOOLEEN ) ;
       Str UNE STRUCTURE ( CAR , BOOLEEN ) ;
       Mot , Mot2 UNE CHAINE ;
       print,taille3 un entier ;


   DEBUT
       SI ( Rnoe <> NIL )
           Mot2 := Mot ;
           Str := INFO ( Rnoe ) ;
           Mot := Mot + STRUCT ( Str , 1 ) ;
           SI ( STRUCT ( Str , 2 ) <>FAUX  )
           print := 0;

            si ( (CARACT(Mot,taille3))<> (CARACT(Mot,taille3) ))
               print := 1;
            finsi;

               si print = 0
               ECRIRE ( Mot ) ;
               finsi;
           FSI ;
           APPEL Affichage2 ( FD ( Rnoe ) ,Mot2 , taille3) ;
           APPEL Affichage2 ( FG ( Rnoe ) ,Mot ,taille3) ;


       FSI ;

   FIN

   /******************** affichge rechreche *************************/

   ACTION Affichage_r ( Rnoe , Mot ,type,ch )
   SOIENT
       Rnoe DES POINTEUR VERS UN ARB DE ( CAR , BOOLEEN ) ;
       Str UNE STRUCTURE ( CAR , BOOLEEN ) ;
       Mot , Mot2 UNE CHAINE ;
       ch une chaine;
       taille_m un entier      ;
       type,i,j,d,taille,print un entier;

   DEBUT
       SI ( Rnoe <> NIL )
           Mot2 := Mot ;
           Str := INFO ( Rnoe ) ;
           Mot := Mot + STRUCT ( Str , 1 ) ;
           SI ( STRUCT ( Str , 2 ) <>FAUX  )


           taille := longchaine(ch);
           si type = 1; /************ rechreche "*" avec/sans"?" *************/
               i := 1;
               tantque (i<=taille)
                       si (CARACT(ch,i)= '?')
                          type := 4;
                       finsi;
                       i := i +1;
               fintantque  ;
               si (type=1) et (CARACT(ch,taille)= '*')
                        type := 3;
               finsi;
               si (type=1) et (CARACT(ch,taille)<> '*')
                        type := 5;
               finsi;
           finsi;

           si type = 2 /************* '???' sans '*' ***********/

               si LONGCHAINE ( mot ) = taille
                  print := 0;
                        i := 0;
                        tantque (i<=taille)
                        si (CARACT(ch,i)<> '?') et (CARACT(ch,i) <> CARACT(mot,i))
                           print := 1;
                        finsi;
                        i := i +1
                        fintantque;
               sinon
                  print :=1;
               finsi;

               si (print = 0)
                  ecrire(Mot);
               finsi;
           finsi;


           si type = 3 /************* Mot* ***********************/
              ecrire(Mot);
                 /* Appel Affichage(Rnoe , Mot);    */
           finsi;

           si type = 4 /******************* fiha '*' et '?' ******************/
              print := 0;
              tantque (i<=taille)
                      si (CARACT(ch,i) = '*')
                      j := 1;
                      tantque (j<=i)
                        si (CARACT(ch,j)<> '?') et (CARACT(ch,j) <> CARACT(Mot,j))
                        print := 1;
                        j := j +1;
                        finsi
                      fintantque;
                      d := taille -i ;
                      j := 0 ;
                      tantque (j<d)
                        si (CARACT(ch,taille-j)<> '?') et (CARACT(ch,taille-j) <> CARACT(Mot,taille_m-j))
                        print := 1;
                        j := j +1;
                        finsi;
                      fintantque;
                      finsi;
                      i := i +1;
              fintantque;
              si (print = 0)
                 ecrire(Mot);
              finsi;
           finsi;

           si type = 5 /******************* Mo*T ******************/
           print := 0;
           /*ecrire(mot);*/
           taille_m := longchaine(Mot);
           /*ecrire(ch);   */
           si ( (CARACT(Mot,taille_m))<> (CARACT(ch,taille) ))
               print := 1;
               /*ecrire('no way'); */
            finsi;

               si print = 0
               ECRIRE ( Mot ) ;
               finsi;

           /*Appel Affichage2(Rnoe,Mot,taille);  */
           Finsi;

           FSI ;
           APPEL Affichage_r ( FD ( Rnoe ) ,Mot2,type,ch ) ;
           APPEL Affichage_r ( FG ( Rnoe ) ,Mot,type,ch ) ;


       FSI;

   FIN

/***************************rechreche *****************************/

   ACTION recherche (Racineee)

 soient

       Racineee DES POINTEUR VERS UN ARB DE ( CAR , BOOLEEN ) ;
       par DES POINTEUR VERS UN ARB DE ( CAR , BOOLEEN ) ;
       ch,ch2 une chaine;
       cmp,cmp2,Mot des car;
       i,j,cbn,taille2,type,taille,gh,lecture des entiers;
       p : STRUCTURE ( CAR , BOOLEEN ) ;

 DEBUT

 /***************************** Lecture ********************************/

 par := Racineee;
 lecture := 0 ;
 Tantque (lecture = 0)
 ecrire('donner le mot');             /* lecture */
 lire(ch);
 ecrire('vous avez entré :',ch) ;
 ecrire('les mots sont: ');
 taille := LONGCHAINE ( ch );                      /* condition*/
 i := 1;
 type := 0;
 gh := 0;
 tantque (i<=taille)
     lecture := 1     ;
     si CARACT(ch,i)= '*'
        gh := gh + 1;
        type := 1;
        lecture := 1;
        si (gh > 1 )
           ecrire('le mot est faux');
           lecture := 0;
           i := taille;
        finsi;
     finsi;
     si (CARACT(ch,i)= '?') et (type = 0 )
        type := 2;
        lecture := 1;
     finsi;
     si (CARACT(ch,1)= '*') ou( CARACT(ch,1)= '?' )
        ecrire('le mot est faux ');
        i := taille;
        lecture := 0;
     finsi;
     i := i +1;
 fintantque
 fintantque;


 i := 1 ;
 cbn := 1;
 ch2 := '';

 tantque (i<=taille) et (cbn<>0)
         si (CARACT(ch,i)= '?') ou (CARACT(ch,i)= '*')
            cbn := 0;
         finsi;
         si (CARACT(ch,i)<> '?') et (CARACT(ch,i)<> '*')  et (cbn<>0)
            ch2 := ch2 + CARACT(ch,i);
         finsi;
         i := i +1;
 fintantque  ;
 taille2 := LONGCHAINE(ch2);
 i := 0;

 /************************ Rechreche CAAA.... **************************/

 TANTQUE (i<taille2)et(par<>NIL)

         i := i +1;
         cmp2 := CARACT(ch2,i);
         p := info(par);
         cmp := struct(p,1);
         /*si cmp < cmp2
            ecrire('n"existe pas works') ;
            i := taille2+1;
         finsi; */
         si cmp = cmp2
            par := FG(par);
            si i = taille2
               si type = 0;
                  si (struct(p,2) = vrai )
                  ecrire(ch2,'existe');
                  sinon
                  ecrire('n"existe pas');
                  finsi;
               sinon
                  APPEL Affichage_r (par, ch2,type,ch);
               finsi;
            finsi
         sinon /* cmp # cmp2 */
            par := FD(par);
            i := i -1;
         finsi;
         si (par=NIL)
            ecrire('n"existe pas');
         finsi
 FINTANTQUE
 Fin


