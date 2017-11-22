#ifndef ANALIZADORLEXICO_C
#define ANALIZADORLEXICO_C
#include <analizadorlexico.h>
#include<string.h>

lista *tokens;
int analisisCount;
int pal = 0;
string auxiliar;
void inicio(string entrada)
{

    analisisCount = 0;
    pal = 0;
    auxiliar = (char*)malloc(sizeof(char)*LINE_SIZE);
    tokens = nuevaLista();
    while(entrada[analisisCount]!='\0')
    {
        if( entrada[analisisCount]>=97 && entrada[analisisCount]<=122 )//SI VIENE UNA LETRA PRIMERO
        {
            auxiliar[pal]=entrada[analisisCount];
            analisisCount++;
            pal++;
            l1(entrada);
        }
        else if((entrada[analisisCount]==36))//SI VIENE SIMBOLO DE DOLAR $
        {
            auxiliar[pal] = entrada[analisisCount];
            analisisCount++;
            pal++;
            l3(entrada);

        }
        else if(entrada[analisisCount]==61)//SI VIENE SIMBOLO DE IGUAL =
        {
            auxiliar[pal] = entrada[analisisCount];
            analisisCount++;
            pal++;
            l4(entrada);
        }
        else if(entrada[analisisCount]==64)//SI VIENE SIMBOLO @
        {
            auxiliar[pal] = entrada[analisisCount];
            analisisCount++;
            pal++;
            l5(entrada);
        }
        else if((entrada[analisisCount]==47))//INICIO DE COMENTARIOS CON /
        {
            analisisCount++;
            //FUNCION DONDE LE TOCA
            l6(entrada);
        }
        else if(entrada[analisisCount]==34)//INICIO DE CADENAS
        {
            analisisCount++;
            l9(entrada);
        }
        else if( (entrada[analisisCount]>=48) || (entrada[analisisCount]<=57) )//VIENE NUMERO
        {
            auxiliar[pal] = entrada[analisisCount];
            analisisCount++;
            pal++;
            l10(entrada);
        }
        else
        {
            //ES OTRO TIPO DE CARACTER ERROR
            printf("Lexical Error: Unidentified Character: %c\n", entrada[analisisCount]);
            break;
        }
    }
    imprime(tokens);
    liberaCadena(entrada);
    deleteLista(tokens);
}

/*------------------------------*/
/*----LETRAS IDENTIFICADORES----*/
void l1(string entrada)
{
    if( (entrada[analisisCount]>=97 && entrada[analisisCount]<=122) || (entrada[analisisCount]>=48 && entrada[analisisCount]<=57) || (entrada[analisisCount]==95))
    {
        auxiliar[pal]=entrada[analisisCount];
        analisisCount++;
        pal++;
        l1(entrada);
    }
    else if( (entrada[analisisCount]==46) || (entrada[analisisCount]==100) || (entrada[analisisCount]==105) || (entrada[analisisCount]==107) || (entrada[analisisCount]==115))
    {
        auxiliar[pal]=entrada[analisisCount];
        analisisCount++;
        pal++;
        l2(entrada);
    }
    else
    {
        //ACEPTANDO TOKEN ID
        //string temp=auxiliar;
        string temp = (char*)calloc(LINE_SIZE,sizeof(char));
        strcpy(temp,auxiliar);
        string temp2 = (char*)malloc(sizeof(char)*LINE_SIZE);
        int res = compruebaTipo(auxiliar);
        if(res == TRUE)
        {
            strcpy(temp2, auxiliar);
        }
        else
        {
            temp2 = "id";
        }
        token *n = newToken(temp, temp2);
        inserta(tokens,n);
        //imprime(tokens);
        liberaCadena(auxiliar);
        pal = 0;
    }
}
void l2(string entrada)
{
    if( (entrada[analisisCount]==46) || (entrada[analisisCount]==100) || (entrada[analisisCount]==105) || (entrada[analisisCount]==107) || (entrada[analisisCount]==115) )
    {
        auxiliar[pal]=entrada[analisisCount];
        analisisCount++;
        pal++;
        l2(entrada);
    }
    else
    {
        //string temp=auxiliar;
        string temp = (char*)calloc(LINE_SIZE,sizeof(char));
        strcpy(temp,auxiliar);
        string temp2 = "disk_file";
        token *n = newToken(temp, temp2);
        inserta(tokens,n);
        //imprime(tokens);
        liberaCadena(auxiliar);
        pal = 0;
    }
}
/*--FIN LETRAS IDENTIFICADORES--*/
/*------------------------------*/

/*------------------------------*/
/*---------COMANDOS-------------*/
void l3(string entrada)
{
    if( (entrada[analisisCount]>=97 && entrada[analisisCount]<=122) || (entrada[analisisCount]>=48 && entrada[analisisCount]<=57) || (entrada[analisisCount]==95))
    {
        auxiliar[pal]=entrada[analisisCount];
        analisisCount++;
        pal++;
        l3(entrada);
    }
    else
    {
        int ul = strlen(auxiliar);
        auxiliar[ul] = '\0';
        //string temp = auxiliar;
        string temp = (char*)calloc(LINE_SIZE,sizeof(char));
        strcpy(temp,auxiliar);
        string temp2 = (char*)malloc(sizeof(char)*LINE_SIZE);
        string aux1 = (char*)malloc(sizeof(char)*LINE_SIZE);
        aux1 = buscaAtributo(auxiliar);
        if(aux1)
        {
            strcpy(temp2,aux1);
            token *n = newToken(temp, temp2);
            inserta(tokens, n);
            //imprime(tokens);
        }
        else
        {
            int x = strlen(auxiliar);
            printf("Atributo no reconocido.... %s\n", auxiliar);
            analisisCount++;
        }
        liberaCadena(auxiliar);
        pal = 0;

    }
}
/*---------FIN COMANDOS---------*/
/*------------------------------*/

/*------------------------------*/
void l4(string entrada)
{
    if(entrada[analisisCount] == 62)
    {
        //string temp=auxiliar;
        auxiliar[pal]=entrada[analisisCount];
        analisisCount++;
        pal++;
        string temp = (char*)calloc(LINE_SIZE,sizeof(char));
        strcpy(temp,auxiliar);
        string temp2 = "t_igual";
        token *n = newToken(temp, temp2);
        inserta(tokens,n);
        //imprime(tokens);
        liberaCadena(auxiliar);
        pal = 0;
    }
    else
    {
        liberaCadena(auxiliar);
        pal = 0;
    }
}
/*------------------------------*/

/*------------------------------*/
void l5(string entrada)
{
    if((entrada[analisisCount]>=97 && entrada[analisisCount]<=122) || (entrada[analisisCount]>=48 && entrada[analisisCount]<=57) || (entrada[analisisCount]==95) )
    {
        auxiliar[pal]=entrada[analisisCount];
        analisisCount++;
        pal++;
        l5(entrada);
    }
    else
    {
        string temp = (char*)calloc(LINE_SIZE,sizeof(char));
        strcpy(temp,auxiliar);
        string temp2 = (char*)malloc(sizeof(char)*LINE_SIZE);
        string aux1 = (char*)malloc(sizeof(char)*LINE_SIZE);
        aux1 = buscaAtributo2(auxiliar);
        if(aux1)
        {
            strcpy(temp2,aux1);
            token *n = newToken(temp, temp2);
            inserta(tokens, n);
            //imprime(tokens);
        }
        else
        {
            printf("Atributo no reconocido.... %s\n", auxiliar);
            analisisCount++;
        }
        liberaCadena(auxiliar);
        pal = 0;
    }
}

/*------------------------------*/

/*------------------------------*/
void l6(string entrada)
{
    if(entrada[analisisCount]==42)//*
    {
        //SIGUIENTE ESTADO
        analisisCount++;
        l7(entrada);
    }
}
void l7(string entrada)
{
    while(entrada[analisisCount]!=42)
    {
        analisisCount++;
    }
    analisisCount++;
    l8(entrada);
}
void l8(string entrada)
{
    if(entrada[analisisCount]==47)
    {
        analisisCount++;
    }
    liberaCadena(auxiliar);
    pal = 0;
}
/*------------------------------*/

/*------------------------------*/
void l9(string entrada)
{
    while(entrada[analisisCount]!=34)
    {
        auxiliar[pal]=entrada[analisisCount];
        analisisCount++;
        pal++;
    }
    string temp = (char*)calloc(LINE_SIZE,sizeof(char));
    strcpy(temp,auxiliar);
    token *n = newToken(temp,"cadena");
    inserta(tokens,n);
    liberaCadena(auxiliar);
    pal = 0;
    analisisCount++;
}
/*------------------------------*/

/*------------------------------*/
void l10(string entrada)
{
    if((entrada[analisisCount]>=48) && (entrada[analisisCount]<=57))
    {
        auxiliar[pal] = entrada[analisisCount];
        analisisCount++;
        pal++;
        l10(entrada);
    }
    else
    {
        string temp = (char*)calloc(LINE_SIZE,sizeof(char));
        strcpy(temp,auxiliar);
        token *n = newToken(temp,"numero");
        inserta(tokens,n);
        liberaCadena(auxiliar);
        pal = 0;
    }
}
/*------------------------------*/

/*------------------------------*/
/*------------------------------*/
int numChar(char c)
{
    return (int)c;
}
void liberaCadena(string entrada)
{    
    free(entrada);
    entrada =  NULL;
    entrada = (char*)calloc(LINE_SIZE,sizeof(char));
}

int compruebaTipo(string valor)
{
    if(strcmp(valor,"mkdisk")==0)
    {
        return TRUE;
    }
    else if(strcmp(valor,"rmdisk")==0)
    {
        return TRUE;
    }
    else if(strcmp(valor,"fdisk")==0)
    {
        return TRUE;
    }
    else if(strcmp(valor, "mount")==0)
    {
        return TRUE;
    }
    else if (strcmp(valor, "unmount")==0)
    {
        return TRUE;
    }
    else if (strcmp(valor, "mkfs")==0)
    {
        return TRUE;
    }
    else if(strcmp(valor, "mkfile")==0)
    {
        return TRUE;
    }
    else if(strcmp(valor, "rm")==0)
    {
        return TRUE;
    }
    else if(strcmp(valor, "cp")==0)
    {
        return TRUE;
    }
    else if(strcmp(valor, "mv")==0)
    {
        return TRUE;
    }
    else if(strcmp(valor, "find")==0)
    {
        return TRUE;
    }
    else if(strcmp(valor, "ls")==0)
    {
        return TRUE;
    }
    else if(strcmp(valor, "cat")==0)
    {
        return TRUE;
    }
    else if(strcmp(valor, "loss")==0)
    {
        return TRUE;
    }
    else if(strcmp(valor, "rep")==0)
    {
        return TRUE;
    }
    return FALSE;
}

string buscaAtributo(string valor)
{
    if(strcmp(valor,"$size")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "$path")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "$name")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "$id")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "$fileid")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "$dest")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "$iddest")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "$order")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "$filen")==0)
    {
        return valor;
    }
    return NULL;
}
string buscaAtributo2(string valor)
{
    if(strcmp(valor,"@unit")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "@type")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "@fit")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "@delete")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "@add")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "@mov")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "@p")==0)
    {
        return valor;
    }
    else if(strcmp(valor, "@cont")==0)
    {
        return valor;
    }
    return NULL;
}

/*------------------------------*/
/*------------------------------*/

#endif // ANALIZADORLEXICO_C
