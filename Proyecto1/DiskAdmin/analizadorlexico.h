#ifndef ANALIZADORLEXICO_H
#define ANALIZADORLEXICO_H
#include <general.h>
#include <listatoken.h>

/*PROTOTIPO DE FUNCIONES*/

void inicio(string entrada);
int numChar(char c);
void liberaCadena(string entrada);
string buscaAtributo(string valor);
string buscaAtributo2(string valor);
int compruebaTipo(string valor);
//LETRAS IDS
/*------------------------------*/
void l1(string entrada);
void l2(string entrada);
/*------------------------------*/
//COMANDOS
/*------------------------------*/
void l3(string entrada);
/*------------------------------*/
//OTROS
/*------------------------------*/
void l4(string entrada);
void l5(string entrada);
/*------------------------------*/
//COMENTARIOS
/*------------------------------*/
void l6(string entrada);
void l7(string entrada);
void l8(string entrada);
/*------------------------------*/
//CADENAS
/*------------------------------*/
void l9(string entrada);
void l10(string entrada);
/*------------------------------*/
#endif // ANALIZADORLEXICO_H
