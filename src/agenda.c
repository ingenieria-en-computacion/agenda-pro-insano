#include "agenda.h"
#include <stdio.h>
#include <string.h>

/* Inicializa la agenda */
void iniciar_agenda(Agenda *agenda){
    agenda->num_contactos = 0;
}

/* Agrega un contacto a la agenda */
void agregar_contacto(Agenda *agenda, Contacto c){
    if(agenda->num_contactos < MAX_CONTACTOS){
        agenda->contactos[agenda->num_contactos] = c;
        agenda->num_contactos++;
    }
}

/* Buscar por nombre */
int buscar_contacto(Agenda *agenda, char *nombre){
    for(int i = 0; i < agenda->num_contactos; i++){
        if(strcmp(agenda->contactos[i].nombre, nombre) == 0){
            return i;
        }
    }
    return -1;
}

/* Buscar por número telefónico */
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]){
    for(int i = 0; i < agenda->num_contactos; i++){
        if(strcmp(agenda->contactos[i].telefono, telefono) == 0){
            return i;
        }
    }
    return -1;
}

/* Ordenar A-Z */
void ordenar_contactos(Agenda *a){
    Contacto tmp;
    for(int i = 0; i < a->num_contactos - 1; i++){
        for(int j = 0; j < a->num_contactos - i - 1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre) > 0){
                tmp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = tmp;
            }
        }
    }
}

/* Ordenar Z-A */
void ordenar_contactos_inv(Agenda *a){
    Contacto tmp;
    for(int i = 0; i < a->num_contactos - 1; i++){
        for(int j = 0; j < a->num_contactos - i - 1; j++){
            if(strcmp(a->contactos[j].nombre, a->contactos[j+1].nombre) < 0){
                tmp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = tmp;
            }
        }
    }
}

/* Mostrar un contacto */
void mostrar_contacto(Contacto c){
    printf("%s %s %d %d %s %d\n",
        c.nombre, c.apellido, c.dia, c.mes, c.telefono, c.tipo);
}

/* Leer contacto desde teclado */
void leer_contacto(Contacto *c){
    scanf("%s %s %d %d %s %d",
        c->nombre, c->apellido, &c->dia, &c->mes, c->telefono, &c->tipo);
}

/* Guardar en archivo */
void guardar_contactos(char *filename, Agenda agenda){
    FILE *f = fopen(filename, "w");
    if(!f) return;

    for(int i = 0; i < agenda.num_contactos; i++){
        Contacto c = agenda.contactos[i];
        fprintf(f, "%s|%s|%d|%d|%s|%d\n",
            c.nombre, c.apellido, c.dia, c.mes, c.telefono, c.tipo);
    }

    fclose(f);
}

/* Cargar desde archivo */
void cargar_contactos(char *filename, Agenda *agenda){
    FILE *f = fopen(filename, "r");
    if(!f) return;

    Contacto c;
    while(fscanf(f, "%29[^|]|%29[^|]|%d|%d|%19[^|]|%d\n",
        c.nombre, c.apellido, &c.dia, &c.mes, c.telefono, &c.tipo) == 6){

        agregar_contacto(agenda, c);
    }

    fclose(f);
}

