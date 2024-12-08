#include <stdio.h>
#include <stdlib.h>
typedef struct ElementListe
{
    int val;
    struct ElementListe *prec;
    struct ElementListe *suiv;
} Element;
typedef struct DList
{
    struct ElementListe *debut;
    struct ElementListe *fin;
} liste;
liste *initialiser_Liste(liste *L)
{
    L = malloc(sizeof(liste));
    L->debut = NULL;
    L->fin = NULL;
    return L;
}
int estVide(liste *L)
{
    if (L->debut == NULL)
        return 1;
    else
        return 0;
}



liste *ajout_en_tete(liste *L, int X)
{
    Element *newElement = malloc(sizeof(Element));
    newElement->val = X;
    newElement->prec = NULL;
    if (estVide(L))
    {
        newElement->suiv = NULL;
        L->debut = newElement;
        L->fin = newElement;
    }
    else
    {
        newElement->suiv = L->debut;
        L->debut->prec = newElement;
        L->debut = newElement;
    }
    return L;
}




void Afficher_Liste(liste *L)
{
    if (estVide(L))
    {
        printf("Liste Vide\n");
        return;
    }
    Element *tmp = L->debut;
    while (tmp != NULL)
    {
        printf("%d <-> ", tmp->val);
        tmp = tmp->suiv;
    }
    printf("NULL\n");
}
liste *ajout_Fin(liste *L, int X)
{
    Element *newElement = malloc(sizeof(Element));
    newElement->val = X;
    newElement->suiv = NULL;
    if (estVide(L))
    {
        newElement->prec = NULL;
        L->debut = newElement;
        L->fin = newElement;
    }
    else
    {
        newElement->prec = L->fin;
        L->fin->suiv = newElement;
        L->fin = newElement;
    }
    return L;
}
liste *supprimer_en_tete(liste *L)
{
    if (!estVide(L))
    {
        if (L->debut == L->fin)
        {
            free(L);
            return initialiser_Liste(L);
        }
        else
        {
            Element *suppElement = L->debut;
            suppElement->suiv->prec = NULL;
            L->debut = suppElement->suiv;
            free(suppElement);
        }
    }
    return L;
}
liste *supprimer_Fin(liste *L)
{
    if (!estVide(L))
    {
        if (L->debut == L->fin)
        {
            free(L);
            return initialiser_Liste(L);
        }
        else
        {
            Element *suppElement = L->fin;
            suppElement->prec->suiv = NULL;
            L->fin = suppElement->prec;
            free(suppElement);
        }
    }
    return L;
}
void Afficher_Liste_Avant(liste *L)
{
    if (estVide(L))
        printf("Liste Vide\n");
    else
    {
        Element *tmp = L->debut;
        while (tmp != NULL)
        {
            printf(" %d ", tmp->val);
            tmp = tmp->suiv;
        }
        printf("\n");
    }
}
void Afficher_Liste_Arriere(liste *L)
{
    if (estVide(L))
        printf("Liste Vide\n");
    else
    {
        Element *tmp = L->fin;
        while (tmp != NULL)
        {
            printf(" %d ", tmp->val);
            tmp = tmp->prec;
        }
        printf("\n");
    }
}
void inserer_au_position(liste *L, int val, int pos)
{
    Element *newElement = (Element *)malloc(sizeof(Element));
    newElement->val = val;
    newElement->suiv = NULL;
    newElement->prec = NULL;

    if (pos == 1)
    {
        newElement->suiv = L->debut;
        if (L->debut != NULL)
        {
            L->debut->prec = newElement;
        }
        L->debut = newElement;
        if (L->fin == NULL)
        {
            L->fin = newElement;
        }
        return;
    }

    Element *tmp = L->debut;
    for (int i = 1; i < pos - 1 && tmp != NULL; i++)
    {
        tmp = tmp->suiv;
    }

    if (tmp == NULL)
    {
        printf("Position invalide\n");
        free(newElement);
        return;
    }

    newElement->suiv = tmp->suiv;
    newElement->prec = tmp;
    if (tmp->suiv != NULL)
    {
        tmp->suiv->prec = newElement;
    }
    tmp->suiv = newElement;
    if (newElement->suiv == NULL)
    {
        L->fin = newElement;
    }
}
Element *chercher_premiere_occurrence(liste *L, int val)
{
    Element *tmp = L->debut;
    while (tmp != NULL)
    {
        if (tmp->val == val)
        {
            return tmp;
        }
        tmp = tmp->suiv;
    }
    return NULL;
}


Element *chercher_derniere_occurrence(liste *L, int val)
{
    Element *tmp = L->fin;
    while (tmp != NULL)
    {
        if (tmp->val == val)
        {
            return tmp;
        }
        tmp = tmp->prec;
    }
    return NULL;
}
void supprimer_au_position(liste *L, int pos)
{
    if (estVide(L))
    {
        printf("Liste Vide\n");
        return;
    }

    Element *tmp = L->debut;
    if (pos == 1)
    {
        L->debut = tmp->suiv;
        if (L->debut != NULL)
        {
            L->debut->prec = NULL;
        }
        else
        {
            L->fin = NULL;
        }
        free(tmp);
        return;
    }





    for (int i = 1; i < pos && tmp != NULL; i++)
    {
        tmp = tmp->suiv;
    }

    if (tmp == NULL)
    {
        printf("Position invalide\n");
        return;
    }

    if (tmp->suiv != NULL)
    {
        tmp->suiv->prec = tmp->prec;
    }
    else
    {
        L->fin = tmp->prec;
    }
    if (tmp->prec != NULL)
    {
        tmp->prec->suiv = tmp->suiv;
    }
    free(tmp);
}
void supprimer_toutes_occurrences(liste *L, int val)
{
    Element *tmp = L->debut;
    while (tmp != NULL)
    {
        Element *next = tmp->suiv;
        if (tmp->val == val)
        {
            if (tmp->prec != NULL)
            {
                tmp->prec->suiv = tmp->suiv;
            }
            else
            {
                L->debut = tmp->suiv;
            }
            if (tmp->suiv != NULL)
            {
                tmp->suiv->prec = tmp->prec;
            }
            else
            {
                L->fin = tmp->prec;
            }
            free(tmp);
        }
        tmp = next;
    }
}
int compter_occurrences(liste *L, int val)
{
    int count = 0;
    Element *tmp = L->debut;
    while (tmp != NULL)
    {
        if (tmp->val == val)
        {
            count++;
        }
        tmp = tmp->suiv;
    }
    return count;
}



int compter_elements(liste *L)
{
    int count = 0;
    Element *tmp = L->debut;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->suiv;
    }
    return count;
}




liste *transformer_en_doublement_chainee(liste *L)
{
    if (estVide(L))
    {
        return L;
    }
    Element *tmp = L->debut;
    Element *prev = NULL;
    while (tmp != NULL)
    {
        tmp->prec = prev;
        prev = tmp;
        tmp = tmp->suiv;
    }
    return L;
}





void trier_liste(liste *L)
{
    if (estVide(L))
    {
        return;
    }
    Element *i, *j;
    int temp;
    for (i = L->debut; i != NULL; i = i->suiv)
    {
        for (j = i->suiv; j != NULL; j = j->suiv)
        {
            if (i->val > j->val)
            {
                temp = i->val;
                i->val = j->val;
                j->val = temp;
            }
        }
    }
}






void inserer_dans_liste_triee(liste *L, int val)
{
    Element *newElement = (Element *)malloc(sizeof(Element));
    newElement->val = val;
    newElement->suiv = NULL;
    newElement->prec = NULL;

    if (estVide(L) || L->debut->val >= val)
    {
        newElement->suiv = L->debut;
        if (L->debut != NULL)
        {
            L->debut->prec = newElement;
        }
        L->debut = newElement;
        if (L->fin == NULL)
        {
            L->fin = newElement;
        }
        return;
    }

    Element *tmp = L->debut;
    while (tmp->suiv != NULL && tmp->suiv->val < val)
    {
        tmp = tmp->suiv;
    }

    newElement->suiv = tmp->suiv;
    newElement->prec = tmp;
    if (tmp->suiv != NULL)
    {
        tmp->suiv->prec = newElement;
    }
    tmp->suiv = newElement;
    if (newElement->suiv == NULL)
    {
        L->fin = newElement;
    }
}









void supprimer_toutes_occurrences_dans_liste(liste *L, int val)
{
    Element *tmp = L->debut;
    while (tmp != NULL)
    {
        Element *next = tmp->suiv;
        if (tmp->val == val)
        {
            if (tmp->prec != NULL)
            {
                tmp->prec->suiv = tmp->suiv;
            }
            else
            {
                L->debut = tmp->suiv;
            }
            if (tmp->suiv != NULL)
            {
                tmp->suiv->prec = tmp->prec;
            }
            else
            {
                L->fin = tmp->prec;
            }
            free(tmp);
        }
        tmp = next;
    }
}
int main()
{
    int choix = 0, val, pos;
    liste *L= initialiser_Liste(L);
do {
    printf("\nMenu:\n");
    printf("1. Inserer l'element E dans une position P donnee\n");
    printf("2. Chercher la premiere occurrence d'un element E donne\n");
    printf("3. Chercher la derniere occurrence d'un element E donne\n");
    printf("4. Supprimer l'element E d'une position P donnee\n");
    printf("5. Supprimer toutes les occurrences d'un element E donne dans la liste\n");
    printf("6. Calculer le nombre d'occurrences de l'element E donne dans la liste\n");
    printf("7. Calculer le nombre d'elements de la liste\n");
    printf("8. Transformer une liste simplement chainee en une liste doublement chainee\n");
    printf("9. Trier en ordre croissant une liste doublement chainee\n");
    printf("10. Inserer un entier X dans une liste doublement chainee triee\n");
    printf("11. Supprimer toutes les occurrences d'une valeur recherchee dans une liste doublement chainee\n");
    printf("0. Quitter\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);

    switch (choix) {
    case 1:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        printf("Entrez une position: ");
        scanf("%d", &pos);
        inserer_au_position(L, val, pos);
        Afficher_Liste(L);
        break;
    case 2:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        Element *premiere = chercher_premiere_occurrence(L, val);
        if (premiere != NULL) {
            printf("Premiere occurrence de %d trouvee.\n", val);
        } else {
            printf("Premiere occurrence de %d non trouvee.\n", val);
        }
        break;
    case 3:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        Element *derniere = chercher_derniere_occurrence(L, val);
        if (derniere != NULL) {
            printf("Derniere occurrence de %d trouvee.\n", val);
        } else {
            printf("Derniere occurrence de %d non trouvee.\n", val);
        }
        break;
    case 4:
        printf("Entrez une position: ");
        scanf("%d", &pos);
        supprimer_au_position(L, pos);
        Afficher_Liste(L);
        break;
    case 5:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        supprimer_toutes_occurrences(L, val);
        Afficher_Liste(L);
        break;
    case 6:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        printf("Nombre d'occurrences de %d: %d\n", val, compter_occurrences(L, val));
        break;
    case 7:
        printf("Nombre d'elements dans la liste: %d\n", compter_elements(L));
        break;
    case 8:
        transformer_en_doublement_chainee(L);
        printf("Liste transformee en doublement chainee.\n");
        Afficher_Liste(L);
        break;
    case 9:
        trier_liste(L);
        printf("Liste triee en ordre croissant.\n");
        Afficher_Liste(L);
        break;
    case 10:
        printf("Entrez une valeur: ");
        scanf("%d", &val);
        inserer_dans_liste_triee(L, val);
        Afficher_Liste(L);
        break;
    case 11:
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

return 0;
}

