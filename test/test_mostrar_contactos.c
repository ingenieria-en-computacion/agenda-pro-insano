#include "../src/agenda.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
    Agenda a;
    inicializar_agenda(&a);

    Contacto c1 = {"Ana", "Perez", 11, ENERO, "5555555555", CASA};
    Contacto c2 = {"Helena", "Rodriguez", 12, SEPTIEMBRE, "5555555556", MOVIL};

    agregar_contacto(&a, c1);
    agregar_contacto(&a, c2);

    imprimir_contactos(a);

    printf("✔ test_mostrar_contactos: OK\n");
    return 0;
}
