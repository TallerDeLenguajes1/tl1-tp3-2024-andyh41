#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

 
int main() {

    int cant;
    char **lista;
    printf("ingrese la cantidad de nombres\n");
    scanf("%d",&cant);
    lista = (char**) malloc(sizeof(char*) * cant);
    char *buff;
    buff = (char*)malloc(sizeof(char) * 100);

    for (int i = 0; i < cant; i++)
    {
        printf("Ingrese el nombre %d: \n", i+1);
        if (i == 0)
        {
            getchar(); 
        }
        fgets(buff, 99, stdin);

        lista[i] =(char*) malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(lista[i], buff);
    }

    for (int j = 0; j < 5; j++)
    {
        printf("-\n");
        puts(lista[j]);
        free(lista[j]);
    }
    
    free(buff);

    getchar();
    getchar();
    return 0;
}