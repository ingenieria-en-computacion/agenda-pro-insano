#include "agenda.h"
#include <stdio.h>
#include <string.h>

/**
 * Inicializa la agenda
 */
void iniciar_agenda(Agenda *agenda){
    if (agenda == NULL) return;
    agenda->num_contactos = 0;
}

void inicializar_agenda(Agenda *agenda){
    iniciar_agenda(agenda);
}


/**
 * Agrega un contacto a la agenda
 */
void agregar_contacto(Agenda *agenda, Contacto c){
    if (agenda == NULL) return;
    if (agenda->num_contactos >= MAX_CONTACTOS){
        printf("Agenda llena.\n");
        return;
    }
    agenda->contactos[agenda->num_contactos] = c;
    agenda->num_contactos++;
}


/**
 * Buscar por nombre
 */
int buscar_contacto(Agenda *agenda, char *nombre){
    if (agenda == NULL) return -1;
    for(int i = 0; i < agenda->num_contactos; i++){
        if (strcmp(agenda->contactos[i].nombre, nombre) == 0){
            return i;
        }
    }
    return -1;
}


/**
 * Buscar por teléfono
 */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){
    if (agenda == NULL) return -1;
    for(int i = 0; i < agenda->num_contactos; i++){
        if (strcmp(agenda->contactos[i].telefono, telefono) == 0){
            return i;
        }
    }
    return -1;
}


/**
 * Ordenar A-Z por nombre
 */
void ordenar_contactos(Agenda *agenda){
    int i, j;
    Contacto temp;

    for(i = 0; i < agenda->num_contactos - 1; i++){
        for(j = 0; j < agenda->num_contactos - i - 1; j++){
            if(strcmp(agenda->contactos[j].nombre,
                      agenda->contactos[j+1].nombre) > 0){

                temp = agenda->contactos[j];
                agenda->contactos[j] = agenda->contactos[j+1];
                agenda->contactos[j+1] = temp;
            }
        }
    }
}


/**
 * Ordenar Z-A por nombre
 */
void ordenar_contactos_inv(Agenda *agenda){
    int i, j;
    Contacto temp;

    for(i = 0; i < agenda->num_contactos - 1; i++){
        for(j = 0; j < agenda->num_contactos - i - 1; j++){
            if(strcmp(agenda->contactos[j].nombre,
                      agenda->contactos[j+1].nombre) < 0){

                temp = agenda->contactos[j];
                agenda->contactos[j] = agenda->contactos[j+1];
                agenda->contactos[j+1] = temp;
            }
        }
    }
}


/**
 * Mostrar un contacto (formato completo)
 */
void mostrar_contacto(Contacto c){
    printf("Nombre: %s %s\n", c.nombre, c.apellido);
    printf("Nacimiento: %d/%d\n", c.dia, c.mes);
    printf("Telefono: %s\n", c.telefono);
    printf("Tipo: %d\n", c.tipo);
}


/**
 * Leer contacto desde teclado (para main si lo usas)
 */
void leer_contacto(Contacto *c){
    printf("Nombre: ");
    scanf("%29s", c->nombre);

    printf("Apellido: ");
    scanf("%29s", c->apellido);

    printf("Dia nacimiento: ");
    scanf("%d", &c->dia);

    printf("Mes nacimiento (0-11): ");
    scanf("%d", (int*)&c->mes);

    printf("Telefono: ");
    scanf("%19s", c->telefono);

    printf("Tipo telefono (0-3): ");
    scanf("%d", (int*)&c->tipo);
}


/**
 * Imprimir todos los contactos (formato completo)
 */
void imprimir_agenda(Agenda agenda){
    if (agenda.num_contactos == 0){
        printf("Agenda vacia.\n");
        return;
    }

    for(int i = 0; i < agenda.num_contactos; i++){
        printf("=== Contacto %d ===\n", i);
        mostrar_contacto(agenda.contactos[i]);
    }
}


/**
 * Función requerida por test_mostrar_contactos.c
 * Imprime SOLO una línea por contacto
 */
void imprimir_contactos(Agenda agenda){
    for(int i = 0; i < agenda.num_contactos; i++){
        printf("%s %s %s\n",
               agenda.contactos[i].nombre,
               agenda.contactos[i].apellido,
               agenda.contactos[i].telefono);
    }
}


/**
 * Guardar agenda (versión simple)
 * Usada por test_guardar.c
 */
void guardar_agenda(char *filename, Agenda agenda){
    FILE *f = fopen(filename, "w");
    if (!f) return;

    for(int i = 0; i < agenda.num_contactos; i++){
        fprintf(f, "%s %s\n",
                agenda.contactos[i].nombre,
                agenda.contactos[i].telefono);
    }

    fclose(f);
}


/**
 * Guardar versión completa (actividad)
 * Formato: nombre|apellido|dia|mes|telefono|tipo
 */
void guardar_contactos(char *filename, Agenda agenda){
    FILE *f = fopen(filename, "w");
    if (!f) return;

    for(int i = 0; i < agenda.num_contactos; i++){
        Contacto c = agenda.contactos[i];
        fprintf(f, "%s|%s|%d|%d|%s|%d\n",
                c.nombre, c.apellido,
                c.dia, c.mes,
                c.telefono, c.tipo);
    }

    fclose(f);
}


/**
 * Leer versión simple (test_leer.c)
 * Formato: nombre telefono
 */
void leer_agenda(Agenda *agenda, char *filename){
    FILE *f = fopen(filename, "r");
    if (!f) return;

    iniciar_agenda(agenda);

    Contacto c;
    strcpy(c.apellido, "");
    c.dia = 0;
    c.mes = ENERO;
    c.tipo = CASA;

    while(fscanf(f, "%29s %19s", c.nombre, c.telefono) == 2){
        agregar_contacto(agenda, c);
    }

    fclose(f);
}


/**
 * Versión completa para cargar contactos
 * Formato: nombre|apellido|dia|mes|telefono|tipo
 */
void cargar_contactos(char *filename, Agenda *agenda){
    FILE *f = fopen(filename, "r");
    if (!f) return;

    iniciar_agenda(agenda);

    Contacto c;
    while(fscanf(f, "%29[^|]|%29[^|]|%d|%d|%19[^|]|%d\n",
                 c.nombre, c.apellido,
                 &c.dia, (int*)&c.mes,
                 c.telefono, (int*)&c.tipo) == 6){

        agregar_contacto(agenda, c);
    }

    fclose(f);
}

