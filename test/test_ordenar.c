#include "../src/agenda.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
    Agenda a;
    inicializar_agenda(&a);

    Contacto c1 = {"Ana", "Perez", 11, ENERO, "5555555555", CASA};
    Contacto c2 = {"Helena", "Rodriguez", 12, SEPTIEMBRE, "5555555556", MOVIL};
    Contacto c3 = {"Carlos", "Rodriguez", 12, SEPTIEMBRE, "5555555556", MOVIL};

    agregar_contacto(&a, c1);
    agregar_contacto(&a, c2);
    agregar_contacto(&a, c3);

    ordenar_contactos_inv(&a);

    assert(strcmp(a.contactos[0].nombre, "Helena") == 0);
    assert(strcmp(a.contactos[1].nombre, "Carlos") == 0);
    assert(strcmp(a.contactos[2].nombre, "Ana") == 0);

    printf("✔ test_ordenar: OK\n");
    return 0;
}
