 do
{
    printf("\nMenu:\n");
    printf("1. Ajouter un element en tete de la liste\n");
    printf("2. Ajouter un element en fin de la liste\n");
    printf("3. Supprimer un element en tete de la liste\n");
    printf("4. Supprimer un element en fin de la liste\n");
    printf("5. Afficher la liste en ordre avant\n");
    printf("6. Afficher la liste en ordre arriere\n");
    printf("7. Inserer l'element E dans une position P donnee\n");
    printf("8. Chercher la premiere occurrence d'un element E donne\n");
    printf("9. Chercher la derniere occurrence d'un element E donne\n");
    printf("10. Supprimer l'element E d'une position P donnee\n");
    printf("11. Supprimer toutes les occurrences d'un element E donne dans la liste\n");
    printf("12. Calculer le nombre d'occurrences de l'element E donne dans la liste\n");
    printf("13. Calculer le nombre d'elements de la liste\n");
    printf("14. Transformer une liste simplement chainee en une liste doublement chainee\n");
    printf("15. Trier en ordre croissant une liste doublement chainee\n");
    printf("16. Inserer un entier X dans une liste doublement chainee triee\n");
    printf("17. Supprimer toutes les occurrences d'une valeur cherchee dans une liste doublement chainee\n");
    printf("0. Quitter\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        L = ajout_en_tete(L, val);
        Afficher_Liste(L);
        break;
    case 2:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        L = ajout_Fin(L, val);
        Afficher_Liste(L);
        break;
    case 3:
        L = supprimer_en_tete(L);
        Afficher_Liste(L);
        break;
    case 4:
        L = supprimer_Fin(L);
        Afficher_Liste(L);
        break;
    case 5:
        Afficher_Liste_Avant(L);
        break;
    case 6:
        Afficher_Liste_Arriere(L);
        break;
    case 7:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        printf("Entrez une position: ");
        scanf("%d", &pos);
        inserer_au_position(L, val, pos);
        Afficher_Liste(L);
        break;
    case 8:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        
         p = chercher_premiere_occurrence(L, val);
        if (p > 0)
        {
            printf("Premiere occurrence de %d trouvee a position %d.\n", val,p);
        }
        else
        {
            printf("Premiere occurrence de %d non trouvee.\n", val);
        }
        break;
    case 9:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        
        p = chercher_derniere_occurrence(L, val);
        if (p > 0)
        {
            printf("Derniere occurrence de %d trouvee a position %d.\n", val,p);
        }
        else
        {
            printf("Derniere occurrence de %d non trouvee.\n", val);
        }
        break;
    case 10:
        printf("Entrez une position: ");
        scanf("%d", &pos);
        supprimer_au_position(L, pos);
        Afficher_Liste(L);
        break;
    case 11:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        supprimer_toutes_occurrences(L, val);
        Afficher_Liste(L);
        break;
    case 12:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        printf("Nombre d'occurrences de %d: %d\n", val, compter_occurrences(L, val));
        break;
    case 13:
        printf("Nombre d'elements dans la liste: %d\n", compter_elements(L));
        break;
    case 14:
        doubl = transformer_en_doublement_chainee(listesimple, doubl);
        printf("Liste transformee en doublement chainee.\n");
        printf("avant\n");
        Afficher_Liste_Avant(doubl);
        printf("arriere\n");
        Afficher_Liste_Arriere(doubl);
        break;
    case 15:
        trier_liste(L);
        printf("Liste triee en ordre croissant.\n");
        Afficher_Liste(L);
        break;
    case 16:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        inserer_dans_liste_triee(L, val);
        Afficher_Liste(L);
        break;
    case 17:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        supprimer_toutes_occurrences_dans_liste(L, val);
        Afficher_Liste(L);
        break;
    case 0:
        printf("Quitter...\n");
        break;
    default:
        printf("Choix invalide. Veuillez reessayer.\n");
        break;
    }
} while (choix != 0);
