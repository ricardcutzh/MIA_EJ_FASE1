#ifndef LISTATOKEN_C
#define LISTATOKEN_C
#include<listatoken.h>

/*---------------------*/
void inserta(lista *list, token *nuevo)
{
    if(list->sz==0)
    {
        list->primero = newNodo(nuevo);
        list->sz++;
    }
    else
    {
        nodo *aux = list->primero;
        while(aux->next)
        {
            aux = aux->next;
        }
        aux->next = newNodo(nuevo);
        list->sz++;

    }
}
/*---------------------*/
nodo *newNodo(token *n)
{
    nodo *nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->tok = n;
    nuevo->next = NULL;
    return nuevo;
}
/*---------------------*/
token *newToken(string val, string tipo)
{
    token *nuevo = (token*)malloc(sizeof(token));
    nuevo->tipo = tipo;
    nuevo->val = val;
    return nuevo;
}
/*---------------------*/
void imprime(lista *list)
{
    printf("------------------IMPRIMIENDO LISTA-----------------\n");
    if(list->sz==0)
    {
        printf("LISTA VACIA\n");
    }
    else
    {
        nodo *aux = list->primero;
        while (aux!=NULL)
        {
            printf("val: %s\ tipo: %s\n", aux->tok->val,aux->tok->tipo);
            aux = aux->next;
        }
    }
    printf("------------------FIN IMPRIMIENDO LISTA-----------------\n");
}
/*---------------------*/
lista *nuevaLista()
{
    lista *l = (lista*)malloc(sizeof(lista));
    l->primero = NULL;
    l->sz = 0;
    return l;
}
/*---------------------*/
nodo *pop(lista *l)
{
    nodo *aux;
    if(l->sz!=0)
    {
        aux = l->primero;
        l->primero = l->primero->next;
        l->sz--;
        return aux;
    }
    else
    {
        return NULL;
    }
}
/*---------------------*/
void peek(lista *l)
{
    if(l->sz!=0)
    {
        printf("primero: %s\n", l->primero->tok->val);
    }
    else
    {
        printf("lista esta vacia\n");
    }
}
/*---------------------*/
void deleteLista(lista *l)
{
    nodo *aux;
    while(l->sz!=0)
    {
        aux = pop(l);
        aux = NULL;
        free(aux);
    }
    l = NULL;
    free(l);
}

#endif // LISTATOKEN_C
