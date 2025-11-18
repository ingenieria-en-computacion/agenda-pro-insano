#include "../src/agenda.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

int main() {
    Agenda a;

    leer_agenda(&a, "../data/test_leer.txt");

    assert(a.num_contactos == 2);
    assert(strcmp(a.contactos[1].telefono, "2222") == 0);

    printf("✔ test_leer: OK\n");
    return 0;
}
