#ifndef LISTATOKEN_H
#define LISTATOKEN_H
#include<general.h>
typedef struct token
{
    string tipo;
    string val;
}token;

typedef struct nodo
{
    token *tok;
    struct nodo *next;
}nodo;

typedef struct lista
{
    nodo *primero;
    int sz;
}lista;

/*METODOS*/
void inserta(lista *list, token *nuevo);
void imprime(lista *list);
nodo *newNodo(token *n);
token *newToken(string val, string tipo);
lista *nuevaLista();
nodo *pop(lista *l);
void peek(lista *l);
void deleteLista(lista *l);

#endif // LISTATOKEN_H
\
