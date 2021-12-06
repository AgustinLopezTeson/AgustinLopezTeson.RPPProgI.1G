#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 9
typedef struct
{
    int id;
    char procesador[10];
    char marca[20];
    float precio;
}eNotebook;



int calcularIva(float precioBruto, float* resultado);
int ordenarNotebooks(eNotebook lista[], int tam);
void mostrarNotebook(eNotebook notebook);
int mostrarNotebooks(eNotebook* lista, int tam);
int subibaja(char str[]);

int main()
{

    eNotebook lista[TAM];

    int nextId=2000;
    float precio= 1000;
    float resultadoIva;
    char cadena[20];

    if(calcularIva(precio,&resultadoIva))
    {
       printf("%.2f",resultadoIva);

    }else
    {

        printf("No se pudo calcular el impuesto");
    }



    hardcodearNotebooks(lista,TAM,9,&nextId);
    ordenarNotebooks(lista,TAM);
    mostrarNotebooks(lista,TAM);








    return 0;
}


int calcularIva(float precioBruto, float* resultado)

{
    int todoOk= 0 ;

        if(precioBruto!=0)
        {

            *resultado=(precioBruto*1.21)-precioBruto;

            todoOk=1;
        }


    return todoOk;
}

int ordenarNotebooks(eNotebook lista[], int tam)
{
    int todoOk = 0;
    eNotebook auxNotebook;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(strcmp(lista[i].marca,lista[j].marca)>0 ||
                        (strcmp(lista[i].marca,lista[j].marca)==0 &&
                         (lista[i].precio<lista[j].precio)))
                {
                    auxNotebook = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxNotebook;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int hardcodearNotebooks(eNotebook lista[], int tam, int cant, int* pId)
{
	int contador = -1;

	char marcas[9][20] = {
		"Dell",
		"Asus",
		"AOC",
		"RedDrago",
		"Sentey",
		"Xiaomi",
		"LgLG",
		"Gamer",
		"Juanchito"
};

char procesador[9][20] = {
		"I9",
		"i3",
		"i5",
		"intel",
		"nvidia",
		"amd",
		"pentum",
		"trhireaper",
		"FX"

};



float precios[9] = {1500,
                    1000,
                    1700,
                    2000,
                    3500,
                    1100,
                    1950,
                    1620,
                    1547};


	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
	{
		contador = 0;
		for(int i = 0; i < cant; i++)
		{
			lista[i].id = *pId;
			(*pId)++;
			strcpy(lista[i].marca, marcas[i]);
			strcpy(lista[i].procesador, procesador[i]);
			lista[i].precio=precios[i];
			contador++;
		}
	}
	return contador;
}

void mostrarNotebook(eNotebook notebook)
{

    printf("  %d   %-20s      %-20s      %-6.2f\n",
           notebook.id,
           notebook.marca,
           notebook.procesador,
           notebook.precio);
}


int mostrarNotebooks(eNotebook* lista, int tam)
{
    int todoOk = 0;
    int flag = 1;
    if(lista != NULL && tam > 0)
    {
        printf("\n\n\n");
        printf("       *** Listado de Notebooks ***      \n");
        printf("-------------------------------------------------------------------\n");
        printf("   Id      Marca                       Procesador            Precio\n");
        printf("-------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {

                mostrarNotebook(lista[i]);
                flag = 0;
        }
        if(flag)
        {
            printf("   No hay notebooks para mostrar\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

/*int subibaja(char str[])
{
   int todoOk= 0;

    int tam;

    tam=strlen(str);



    for(int i=0;i<tam;i++)
    {


        if(str[i]==toupper(str[i])
           {
              str[i]= tolower(str[i]);

           }

        if(str[i]==tolower(str[i])
           {
              str[i]=toupper(str[i]);

           }
           todoOk=1;
    }

            return todoOk;
}
*/
