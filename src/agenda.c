#include "agenda.h"

// Inicializar agenda
void iniciar_agenda(Agenda *agenda) {
    agenda->num_contactos = 0;
}

void inicializar_agenda(Agenda *agenda) {
    iniciar_agenda(agenda);
}

// Agregar contacto
void agregar_contacto(Agenda *agenda, Contacto c) {
    agenda->contactos[agenda->num_contactos] = c;
    agenda->num_contactos++;
}

// Buscar por nombre
int buscar_contacto(Agenda *agenda, char *nombre) {
    for (int i = 0; i < agenda->num_contactos; i++) {
        if (strcmp(agenda->contactos[i].nombre, nombre) == 0)
            return i;
    }
    return -1;
}

// Buscar por teléfono
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]) {
    for (int i = 0; i < agenda->num_contactos; i++) {
        if (strcmp(agenda->contactos[i].telefono, telefono) == 0)
            return i;
    }
    return -1;
}

// Ordenar A → Z
void ordenar_contactos(Agenda *a) {
    Contacto temp;
    for (int i = 0; i < a->num_contactos - 1; i++) {
        for (int j = 0; j < a->num_contactos - 1 - i; j++) {
            if (strcmp(a->contactos[j].nombre,
                       a->contactos[j+1].nombre) > 0) {

                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

// Ordenar Z → A
void ordenar_contactos_inv(Agenda *a) {
    Contacto temp;
    for (int i = 0; i < a->num_contactos - 1; i++) {
        for (int j = 0; j < a->num_contactos - 1 - i; j++) {
            if (strcmp(a->contactos[j].nombre,
                       a->contactos[j+1].nombre) < 0) {

                temp = a->contactos[j];
                a->contactos[j] = a->contactos[j+1];
                a->contactos[j+1] = temp;
            }
        }
    }
}

void mostrar_contacto(Contacto c) {
    printf("%s %s %d %d %s %d\n",
           c.nombre, c.apellido, c.dia, c.mes, c.telefono, c.tipo);
}

void imprimir_agenda(Agenda agenda) {
    for (int i = 0; i < agenda.num_contactos; i++)
        mostrar_contacto(agenda.contactos[i]);
}

void imprimir_contactos(Agenda agenda) {
    imprimir_agenda(agenda);
}

// Leer archivo
void cargar_contactos(char *filename, Agenda *agenda) {
    FILE *f = fopen(filename, "r");
    if (!f) return;

    char nombre[30], telefono[30];
    agenda->num_contactos = 0;

    while (fscanf(f, "%s %s", nombre, telefono) == 2) {
        Contacto c;
        strcpy(c.nombre, nombre);
        strcpy(c.apellido, "");
        c.dia = 1;
        c.mes = ENERO;
        strcpy(c.telefono, telefono);
        c.tipo = CASA;

        agregar_contacto(agenda, c);
    }
    fclose(f);
}

void leer_agenda(Agenda *agenda, char *filename) {
    cargar_contactos(filename, agenda);
}

// Guardar archivo
void guardar_contactos(char *filename, Agenda agenda) {
    FILE *f = fopen(filename, "w");
    if (!f) return;

    for (int i = 0; i < agenda.num_contactos; i++) {
        Contacto c = agenda.contactos[i];

        fprintf(f, "%s %s %d %d %s %d\n",
                c.nombre, c.apellido, c.dia, c.mes,
                c.telefono, c.tipo);
    }
    fclose(f);
}

void guardar_agenda(char *filename, Agenda agenda) {
    guardar_contactos(filename, agenda);
}
