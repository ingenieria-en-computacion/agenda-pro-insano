
#include "agenda.h"

int main() {

    Agenda agenda;
    inicializar_agenda(&agenda);

    Contacto c1 = {"Ana", "Perez", 11, ENERO, "5551111111", CASA};
    Contacto c2 = {"Helena", "Luis", 5, FEBRERO, "5552222222", MOVIL};
    Contacto c3 = {"Carlos", "Lopez", 20, MARZO, "5553333333", OFICINA};

    agregar_contacto(&agenda, c1);
    agregar_contacto(&agenda, c2);
    agregar_contacto(&agenda, c3);

    printf("Contactos actuales:\n");
    imprimir_contactos(agenda);

    return 0;
}
