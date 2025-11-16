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
 * Busca un contacto por su número de teléfono
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
 * Ordenar contactos por nombre (A-Z)
 */
void ordenar_contactos(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j = 0; j < a->num_contactos - i - 1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre) > 0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Ordenar contactos por nombre (Z-A)
 */
void ordenar_contactos_inv(Agenda *a){
    int i, j;
    Contacto temp;
    for(i = 0; i < a->num_contactos; i++){
        for(j = 0; j < a->num_contactos - i - 1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre) < 0){
                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

/**
 * Imprime un solo contacto
 */
void mostrar_contacto(Contacto c){
    printf("%s %s %d/%d %s %d\n",
        c.nombre,
        c.apellido,
        c.dia,
        c.mes,
        c.telefono,
        c.tipo
    );
}

/**
 * Leer un contacto desde teclado (no usado por tests pero obligatorio)
 */
void leer_contacto(Contacto *c){
    printf("Nombre: ");
    scanf("%s", c->nombre);

    printf("Apellido: ");
    scanf("%s", c->apellido);

    printf("Dia: ");
    scanf("%d", &c->dia);

    printf("Mes: ");
    scanf("%d", &c->mes);

    printf("Telefono: ");
    scanf("%s", c->telefono);

    printf("Tipo (0-3): ");
    scanf("%d", &c->tipo);
}

/**
 * Imprime toda la agenda
 */
void imprimir_agenda(Agenda agenda){
    for(int i = 0; i < agenda.num_contactos; i++){
        mostrar_contacto(agenda.contactos[i]);
    }
}

/**
 * Cargar contactos desde archivo
 * Formato esperado:
 * nombre|apellido|dia|mes|telefono|tipo
 */
void cargar_contactos(char *filename, Agenda *agenda){
    FILE *f = fopen(filename, "r");
    if (!f) return;

    agenda->num_contactos = 0;

    Contacto c;
    while(fscanf(f, "%29[^|]|%29[^|]|%d|%d|%19[^|]|%d\n",
                 c.nombre, c.apellido, &c.dia, &c.mes, c.telefono, &c.tipo) == 6){

        if (agenda->num_contactos < MAX_CONTACTOS){
            agenda->contactos[agenda->num_contactos] = c;
            agenda->num_contactos++;
        }
    }

    fclose(f);
}

/**
 * Guardar contactos en archivo
 */
void guardar_contactos(char *filename, Agenda agenda){
    FILE *f = fopen(filename, "w");
    if (!f) return;

    for(int i = 0; i < agenda.num_contactos; i++){
        Contacto c = agenda.contactos[i];
        fprintf(f, "%s|%s|%d|%d|%s|%d\n",
                c.nombre, c.apellido, c.dia, c.mes, c.telefono, c.tipo);
    }

    fclose(f);
}

/* ============================================================
   FUNCIONES “PUENTE” QUE EXIGE EL AUTOGRADER DE LA PROFA
   NO BORRAR ESTAS, SON NECESARIAS PARA QUE APRUEBE EL TASK
   ============================================================ */

/* puente para test_guardar.c */
void guardar_agenda(char *filename, Agenda agenda){
    guardar_contactos(filename, agenda);
}

/* puente para test_leer.c */
void leer_agenda(char *filename, Agenda *agenda){
    cargar_contactos(filename, agenda);
}

/* puente para test_mostrar_contactos.c */
void imprimir_contactos(Agenda agenda){
    imprimir_agenda(agenda);
}
