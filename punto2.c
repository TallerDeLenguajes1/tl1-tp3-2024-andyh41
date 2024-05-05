#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#define FIL 100
#define COL 100


void CargarMatriz(int M[FIL][COL], int DIMF, int DIMC);
void MostrarMatriz(int M[FIL][COL], int DIMF, int DIMC);
void promedio(int M[FIL][COL], int DIMF, int DIMC);
void maxymin(int M[FIL][COL], int DIMF, int DIMC);

int main () {
	
	int A[FIL][COL];
	int B[FIL][COL];
	
	srand(time(NULL));
	CargarMatriz(A,5,12);
	printf("\n");
	printf("ganancias de 5 anios \n");
	MostrarMatriz(A,5,12);
	printf("\n");
    printf("el promedio por anio es: \n");
    promedio(A,5,12);
	printf("\n");
    maxymin(A,5,12);

	getchar ();
	getchar ();
	
	return 0;
	
}

void CargarMatriz(int M[FIL][COL], int DIMF, int DIMC)
{	int i, j;
	for(i=0; i < DIMF; i++) { // i para filas
		for(j=0; j < DIMC; j++) { // j para columnas
			M[i][j] =10000+rand()%40000; 
			// rand() % (Max - min) + min
		}
	}
}

void MostrarMatriz(int M[FIL][COL], int DIMF, int DIMC)
{	int i, j;
	printf("\n");
	for(i=0; i < DIMF; i++) { // i para filas
		for(j=0; j < DIMC; j++) { // j para columnas
			printf("%d ",M[i][j]);
		}
		printf("\n");
	}
}

void promedio(int M[FIL][COL], int DIMF, int DIMC) {
    int i, j;
    float suma;
    suma=0;
	for(i=0; i < DIMF; i++) { // i para filas
		for(j=0; j < DIMC; j++) { // j para columnas
			suma+=M[i][j]; // suma el anio
		}
        suma=suma/12; // saca el promedio
        printf("el promedio de ganancia del anio %d es de= %.2f\n", i+1, suma); // muestra el promedio
        suma=0; // reinicializa la variable para calcular el promedio del siguiente anio
	}
}

void maxymin(int M[FIL][COL], int DIMF, int DIMC) {
    
    int i, j, max, min, maxanio, maxmes, minanio, minmes;
    max=0;
    min=50000;
	for(i=0; i < DIMF; i++) { // i para filas
		for(j=0; j < DIMC; j++) { // j para columnas
			if(M[i][j]>max) {
                max=M[i][j];
                maxanio=i+1;
                maxmes=j+1;
            }
            if(M[i][j]<min){
                min=M[i][j];
                minanio=i+1;
                minmes=j+1;
            }
		}
	}

    printf("la maxima ganancia fue de:%d, en el mes:%d del anio:%d\n", max, maxmes, maxanio);
    printf("la minima ganancia fue de:%d, en el mes:%d del anio:%d\n", min, minmes, minanio);
}
