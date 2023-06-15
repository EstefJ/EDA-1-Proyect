#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdll.h"

/**
 * @brief Crea una lista circular doblemente enlazada
 *
 * @return Una referencia a la nueva lista
 * @post Una lista existente en el heap
 */
CDLL* crearLista()
{
    CDLL* lista = (CDLL*)malloc(sizeof(CDLL));
    if (lista == NULL)
    {
        printf("Error: No se pudo asignar memoria para la lista.\n");
        return NULL;
    }

    lista->first = NULL;
    lista->last = NULL;
    lista->cursor = NULL;
    lista->len = 0;

    return lista;
}
/**
 * @brief Inserta un elemento en el fondo de la lista
 *
 * @param this una Una lista
 * @param se inserta el tipo abstracto Alumno
*/

void agregarNodo(CDLL* lista, Alumno alumno)
{
    Node* nuevoNodo = (Node*)malloc(sizeof(Node));
    if (nuevoNodo == NULL)
    {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        return;
    }

    nuevoNodo->alumno = alumno;
    nuevoNodo->next = NULL;
    nuevoNodo->prev = NULL;

    if (lista->first == NULL)
    {
        lista->first = nuevoNodo;
        lista->last = nuevoNodo;
    }
    else
    {
        nuevoNodo->prev = lista->last;
        lista->last->next = nuevoNodo;
        lista->last = nuevoNodo;
    }

    lista->len++;
}
/**
 * @brief calculu¿a el promedio del alumno recién ingresado a la lista
 *
 * @param Tipo abstracto Alumno
 * @return El promedio del alumno
*/

double calcularPromedio(Alumno alumno)
{
    // Aqu� ir�a el c�digo para calcular el promedio del alumno actual
    return 0.0;
}

/**
 * @brief Imprime el contenido de la lista de alumnos.
 *
 * @param this Una lista.
 */
void mostrarLista(CDLL* lista)
{
    printf( "\tNombre\t\t\tApellido\t\t\tNo. de cuenta\n");

    Node* actual = lista->first;
    int i = 1;

    while (actual != NULL)
    {
        printf("%d\t", i);
        printf("%s\t\t\t", actual->alumno.nombre);
        printf("%s\t\t\t", actual->alumno.apellido);
        printf("%d", actual->alumno.numeroCuenta);

        // Aqu� ir�a el c�digo para mostrar las calificaciones del alumno actual

        printf("\n");

        actual = actual->next;
        i++;
    }
}
/**
 * @brief Destruye la lista.
 *
 * @param this Una lista.
 */
void eliminarLista(CDLL* lista)
{
    Node* actual = lista->first;
    Node* siguiente;

    while (actual != NULL)
    {
        siguiente = actual->next;
        free(actual);
        actual = siguiente;
    }

    free(lista);
}
/**
 * @brief Ordena los promedios de los alumnos del mayor al menor
 *
 * @param this Una lista.
 */
void ordenarPromedios(CDLL* lista)
{
    // Aqu� ir�a el c�digo para ordenar los promedios de mayor a menor
}
/**
 * @brief Llena los datos al tipo Abstracto Alumno y lo agrega a la lista 
 *
 * @param this Una lista.
 */
void añadir_Alumno(CDLL* lista, char nombre[], char apellido[], int cuenta, double calificaciones[])
{
    Alumno alumno;
    strncpy(alumno.nombre, nombre, 50);
    strncpy(alumno.apellido, apellido, 50);
    alumno.numeroCuenta = cuenta;
    int i;
    for( i = 0; i < 3; i++)
    {
        alumno.calificaciones[i] = calificaciones[i];
    }  

    agregarNodo(lista, alumno);
    printf("Se ha agregado al alumno a la lista.\n");
}
