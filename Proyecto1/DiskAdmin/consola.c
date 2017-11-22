#ifndef CONSOLA_C
#define CONSOLA_C
#include<consola.h>

/*VAR GLOBLAES*/
int continua = TRUE;
/*FIN VAR GLOBALES*/

/*---------------------------*/
void iniciaConsola()
{
    string entrada = malloc(sizeof(char)*LINE_SIZE);
    //int tamanio = 0;
    while (continua)
    {
        printf(">>> ");
        gets(entrada);
        entrada = quitameEspacios(entrada);
        pasameAMinuscula(entrada);
        inicio(entrada);
    }
}
/*---------------------------*/
int numeroLetras(string linea)
{
    int i;
    int cont = 0;
    for(i = 0; linea[i]!='\0';i++)
    {
        cont++;
    }
    return cont;
}
/*---------------------------*/
string quitameEspacios(string linea)
{
    int x;
    int y;
    string nueva = malloc(sizeof(char)*LINE_SIZE);
    for(x = y = 0; linea[x] != '\0'; x++)
    {
        if(linea[x]!=' ')
        {
            nueva[y++] = linea[x];
        }
    }
    return nueva;
}
/*---------------------------*/
void pasameAMinuscula(string linea)
{
    int x;
    for(x =0; linea[x]!='\0';x++)
    {
        linea[x] = tolower(linea[x]);
    }
}

#endif // CONSOLA_C
