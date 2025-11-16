#include "agenda.h"
#include <stdio.h>
#include <string.h>

/**
 * Inicializa la agenda con 0 contactos
 */
void iniciar_agenda(Agenda *agenda){
    agenda->num_contactos = 0;
}

/**
 * Alias requerido por los tests (puede llamar a iniciar_agenda)
 */
void inicializar_agenda(Agenda *agenda){
    iniciar_agenda(agenda);
}

/**
 * Agrega un contacto a la agenda si hay espacio
 */
void agregar_contacto(Agenda *agenda, Contacto c){
    if (agenda->num_contactos < MAX_CONTACTOS){
        agenda->contactos[agenda->num_contactos] = c;
        agenda->num_contactos++;
    }
}

/**
 * Busca un contacto por nombre
 * Retorna índice o -1 si no existe
 */
int buscar_contacto(Agenda *agenda, char *nombre){
    for (int i = 0; i < agenda->num_contactos; i++){
        if (strcmp(agenda->contactos[i].nombre, nombre) == 0){
            return i;
        }
    }
    return -1;
}

/**
 * Busca un contacto por teléfono
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){
    for (int i = 0; i < agenda->num_contactos; i++){
        if (strcmp(agenda->contactos[i].telefono, telefono) == 0){
            return i;
        }
    }
    return -1;
}

/**
 * Muestra UN contacto
 */
void mostrar_contacto(Contacto c){
    printf("%s %s %d/%d Tel:%s Tipo:%d\n",
           c.nombre, c.apellido, c.dia, c.mes, c.telefono, c.tipo);
}

/**
 * Lee un contacto desde teclado
 */
void leer_contacto(Contacto *c){
    printf("Nombre: ");
    scanf("%s", c->nombre);
    printf("Apellido: ");
    scanf("%s", c->apellido);
    printf("Dia: ");
    scanf("%d", &c->dia);
    printf("Mes (numero 1–12): ");
    scanf("%d", &c->mes);
    printf("Telefono: ");
    scanf("%s", c->telefono);
    printf("Tipo (0=CASA,1=MOVIL,2=OFICINA,3=OTRO): ");
    scanf("%d", &c->tipo);
}

/**
 * Imprimir todos los contactos
 */
void imprimir_agenda(Agenda agenda){
    for (int i = 0; i < agenda.num_contactos; i++){
        mostrar_contacto(agenda.contactos[i]);
    }
}

/**
 * Ordena por nombre ascendente
 */
void ordenar_contactos(Agenda *a){
    Contacto temp;
    for(int i = 0; i < a->num_contactos; i++){
        for(int j = 0; j < a->num_contactos - i - 1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre) > 0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Ordena por nombre descendente
 */
void ordenar_contactos_inv(Agenda *a){
    Contacto temp;
    for(int i = 0; i < a->num_contactos; i++){
        for(int j = 0; j < a->num_contactos - i - 1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre) < 0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Cargar contactos desde archivo
 * Formato simple: un contacto por línea
 */
void cargar_contactos(char *filename, Agenda *agenda){
    FILE *f = fopen(filename, "r");
    if (!f) return;

    Contacto c;
    while (fscanf(f, "%s %s %d %d %s %d",
                  c.nombre, c.apellido, &c.dia, &c.mes,
                  c.telefono, &c.tipo) != EOF)
    {
        agregar_contacto(agenda, c);
    }
    fclose(f);
}

/**
 * Guardar contactos en archivo
 */
void guardar_contactos(char *filename, Agenda agenda){
    FILE *f = fopen(filename, "w");
    if (!f) return;

    for (int i = 0; i < agenda.num_contactos; i++){
        Contacto c = agenda.contactos[i];
        fprintf(f, "%s %s %d %d %s %d\n",
                c.nombre, c.apellido, c.dia, c.mes,
                c.telefono, c.tipo);
    }
    fclose(f);
}
