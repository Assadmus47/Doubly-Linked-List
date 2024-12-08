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
typedef struct cellule cellule;
typedef cellule *Liste;

struct cellule {
    int val;
    struct cellule *suivant;
};

cellule *initialiser_Liste_simple(cellule *liste) {
    liste = NULL;
    return liste;
}

Liste Ajouter_Debut_Liste(cellule *liste, int valeur) {
    Liste newcellule = malloc(sizeof(cellule));
    newcellule->val = valeur;
    newcellule->suivant = liste;
    return newcellule;
}
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
int chercher_premiere_occurrence(liste *L, int val)
{
    Element *tmp = L->debut;
    int pos = 1;
    while (tmp != NULL)
    {
        if (tmp->val == val)
        {
            return pos;
        }
        pos++;
        tmp = tmp->suiv;
    }
    return 0;
}
int chercher_derniere_occurrence(liste *L, int val)
{
    Element *tmp = L->fin;
    int pos = compter_elements(L);
    while (tmp != NULL)
    {
        if (tmp->val == val)
        {
            return pos;
        }
        pos--;
        tmp = tmp->prec;
    }
    return 0;
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

liste *transformer_en_doublement_chainee(Liste liste_simple, liste *L_doublon) {
    if (liste_simple == NULL) {
        return NULL;
    }
    L_doublon = initialiser_Liste(L_doublon);
    
    cellule *current = liste_simple;
    while (current != NULL) {
        L_doublon = ajout_Fin(L_doublon, current->val);
        current = current->suivant;
    }
    
    return L_doublon;
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
    int p=0;
    liste *doubl = initialiser_Liste(doubl);
    cellule *listesimple = initialiser_Liste_simple(listesimple);
listesimple = Ajouter_Debut_Liste(listesimple, 5);
listesimple = Ajouter_Debut_Liste(listesimple, 3);
listesimple = Ajouter_Debut_Liste(listesimple, 56);
listesimple = Ajouter_Debut_Liste(listesimple, 2);
listesimple = Ajouter_Debut_Liste(listesimple, 1);
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


    return 0;
}