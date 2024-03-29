#include "puntajes.h"

nodoPuntajes * inicListaPuntajes()
{
    return NULL;
}

nodoPuntajes * crearNodoPuntajes(char nombre[30],int puntaje)
{
    nodoPuntajes * nuevo=(nodoPuntajes*)malloc(sizeof(nodoPuntajes));
    strcpy(nuevo->puntajes.nombre,nombre);
    nuevo->puntajes.puntaje=puntaje;
    nuevo->siguiente=NULL;
    return nuevo;
}

nodoPuntajes*agregarPpio(nodoPuntajes*lista,nodoPuntajes*nuevo){
    if(lista==NULL){
        lista=nuevo;
    }else{
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}



///Acomoda el puntaje del mayor puntaje al menor
nodoPuntajes * acomodarPuntaje(nodoPuntajes * lista, nodoPuntajes * nuevo)
{

    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        if(nuevo->puntajes.puntaje > lista->puntajes.puntaje)
        {
            lista=agregarPpio(lista,nuevo);

        }
        else
        {
            nodoPuntajes * ante=lista;
            nodoPuntajes * seg=lista->siguiente;

            while(seg != NULL && nuevo->puntajes.puntaje < seg->puntajes.puntaje)
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente=seg;
            ante->siguiente=nuevo;

        }
    }
    return lista;
}

nodoPuntajes * abrirArchivoPuntajes()
{
    STpuntajes aux;
    nodoPuntajes * lista=inicListaPuntajes();

    FILE * archi=fopen("puntajes.dat","rb");
    if(archi!=NULL){
        printf("--- lee puntajes.dat ---\n");
        while(fread(&aux,sizeof(STpuntajes),1 ,archi) >0)
        {
            nodoPuntajes* nuevoNodo = crearNodoPuntajes(aux.nombre, aux.puntaje);
            lista = acomodarPuntaje(lista, nuevoNodo);

            ///strcpy(lista->puntajes.nombre,aux.nombre);
            ///lista->puntajes.puntaje=aux.puntaje;
            ///lista->siguiente=inicListaPuntajes();

        }
        fclose(archi);
    }

    return lista;
}

void guardarArchivoPuntajes(nodoPuntajes * lista)
{
    STpuntajes aux;
    FILE * archi = fopen("puntajes.dat","wb");

    nodoPuntajes*seg=lista;
    while(seg!=NULL){
        aux.puntaje=seg->puntajes.puntaje;
        strcpy(aux.nombre,seg->puntajes.nombre);

        fwrite(&aux,sizeof(STpuntajes),1,archi);

        seg=seg->siguiente;
    }
    fclose(archi);
}

void mostrarListaPuntajes(nodoPuntajes*lista){
    nodoPuntajes*seg=lista;
    printf("--- ListaPuntajes ----\n");
    while(seg!=NULL){
        printf("%s-%d\n",seg->puntajes.nombre,seg->puntajes.puntaje);
        seg=seg->siguiente;
    }
}

void mostrarPuntajes(STpuntajes puntaje,int posicion)
{
    printf("[ %d ]\t%s :\t%d\n",posicion,puntaje.nombre,puntaje.puntaje);
}

void recorreMostrarPuntajes()
{
    system("cls");
    STpuntajes aux;

    FILE * archi=fopen("puntajes.dat","rb");
    int posicion=1;
    while(fread(&aux,sizeof(STpuntajes),1,archi)>0)
    {
        mostrarPuntajes(aux,posicion);
        posicion++;
    }
    fclose(archi);
}

void cargarPuntajes(char nombre[],int puntaje)
{

    nodoPuntajes * nuevo=inicListaPuntajes();
    nuevo=crearNodoPuntajes(nombre,puntaje);
    nodoPuntajes * lista = abrirArchivoPuntajes();
    lista=acomodarPuntaje(lista,nuevo);
    guardarArchivoPuntajes(lista);
}
