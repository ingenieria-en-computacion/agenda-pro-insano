#include "../src/agenda.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

int main() {
    Agenda a;
    inicializar_agenda(&a);

    Contacto c = {"Ana", "Perez", 11, ENERO, "5555555555", CASA};
    agregar_contacto(&a, c);

    assert(strcmp(a.contactos[0].nombre, "Ana") == 0);
    printf("✔ test_agregar: OK\n");
    return 0;
}
