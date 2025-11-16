#include <stdio.h>
#include <string.h>
#include "agenda.h"

// --------------------------------------------------
// Alias requerido por test
// --------------------------------------------------
void inicializar_agenda(Agenda *agenda) {
    iniciar_agenda(agenda);
}

// --------------------------------------------------
// Inicializar agenda
// --------------------------------------------------
void iniciar_agenda(Agenda *agenda) {
    agenda->num_contactos = 0;
}

// --------------------------------------------------
// Lectura de un contacto (usado en test_leer_contacto.c)
// --------------------------------------------------
void leer_contacto(Contacto *c) {
    scanf("%s %s %d %d %s %d",
        c->nombre,
        c->apellido,
        &c->dia,
        (int *)&c->mes,
        c->telefono,
        (int *)&c->tipo
    );
}

// --------------------------------------------------
// Mostrar un contacto (test_mostrar_contactos.c)
// --------------------------------------------------
void mostrar_contacto(Contacto c) {
    printf("%s %s %d %d %s %d\n",
        c.nombre,
        c.apellido,
        c.dia,
        c.mes,
        c.telefono,
        c.tipo
    );
}

// --------------------------------------------------
// Agregar contacto (test_agregar.c)
// --------------------------------------------------
void agregar_contacto(Agenda *agenda, Contacto c) {
    if (agenda->num_contactos < MAX_CONTACTOS) {
        agenda->contactos[agenda->num_contactos] = c;
        agenda->num_contactos++;
    }
}

// --------------------------------------------------
// Buscar contacto por nombre (test_buscar.c)
// --------------------------------------------------
int buscar_contacto(Agenda *agenda, char *nombre) {
    for (int i = 0; i < agenda->num_contactos; i++) {
        if (strcmp(agenda->contactos[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

// --------------------------------------------------
// Buscar contacto por teléfono
// --------------------------------------------------
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]) {
    for (int i = 0; i < agenda->num_contactos; i++) {
        if (strcmp(agenda->contactos[i].telefono, telefono) == 0) {
            return i;
        }
    }
    return -1;
}

// --------------------------------------------------
// Ordenamiento ascendente (burbuja) — test_ordenar.c
// --------------------------------------------------
void ordenar_contactos(Agenda *agenda) {
    for (int i = 0; i < agenda->num_contactos - 1; i++) {
        for (int j = 0; j < agenda->num_contactos - i - 1; j++) {
            if (strcmp(agenda->contactos[j].nombre,
                       agenda->contactos[j+1].nombre) > 0) {
                Contacto temp = agenda->contactos[j];
                agenda->contactos[j] = agenda->contactos[j+1];
                agenda->contactos[j+1] = temp;
            }
        }
    }
}

// Orden descendente (extra)
void ordenar_contactos_inv(Agenda *agenda) {
    for (int i = 0; i < agenda->num_contactos - 1; i++) {
        for (int j = 0; j < agenda->num_contactos - i - 1; j++) {
            if (strcmp(agenda->contactos[j].nombre,
                       agenda->contactos[j+1].nombre) < 0) {
                Contacto temp = agenda->contactos[j];
                agenda->contactos[j] = agenda->contactos[j+1];
                agenda->contactos[j+1] = temp;
            }
        }
    }
}

// --------------------------------------------------
// Imprimir agenda completa
// --------------------------------------------------
void imprimir_contactos(Agenda agenda) {
    for (int i = 0; i < agenda.num_contactos; i++) {
        mostrar_contacto(agenda.contactos[i]);
    }
}

// --------------------------------------------------
// Guardar agenda (test_guardar.c)
// --------------------------------------------------
void guardar_agenda(char *filename, Agenda agenda) {
    FILE *f = fopen(filename, "w");

    if (!f) return;

    for (int i = 0; i < agenda.num_contactos; i++) {
        Contacto c = agenda.contactos[i];

        fprintf(f, "%s %s %d %d %s %d\n",
            c.nombre,
            c.apellido,
            c.dia,
            c.mes,
            c.telefono,
            c.tipo
        );
    }

    fclose(f);
}

// --------------------------------------------------
// Leer agenda (test_leer.c)
// --------------------------------------------------
void leer_agenda(Agenda *agenda, char *filename) {
    FILE *f = fopen(filename, "r");

    if (!f) {
        agenda->num_contactos = 0;
        return;
    }

    agenda->num_contactos = 0;

    while (!feof(f)) {
        Contacto c;
        if (fscanf(f, "%s %s %d %d %s %d",
                   c.nombre,
                   c.apellido,
                   &c.dia,
                  (int *)&c.mes,
                   c.telefono,
                  (int *)&c.tipo) == 6) {
            agenda->contactos[agenda->num_contactos++] = c;
        }
    }

    fclose(f);
}


