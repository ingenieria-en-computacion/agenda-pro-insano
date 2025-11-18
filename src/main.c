#include <stdio.h>
#include <string.h>
#include "agenda.h"

void menu() {
    printf("\n===== MENU DE AGENDA =====\n");
    printf("1. Agregar contacto\n");
    printf("2. Buscar por nombre\n");
    printf("3. Buscar por telefono\n");
    printf("4. Mostrar todos los contactos\n");
    printf("5. Ordenar A -> Z\n");
    printf("6. Ordenar Z -> A\n");
    printf("7. Guardar en archivo\n");
    printf("8. Cargar desde archivo\n");
    printf("9. Salir\n");
    printf("Seleccione una opcion: ");
}

int main() {
    Agenda agenda;
    iniciar_agenda(&agenda);

    int opcion;

    do {
        menu();
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        if (opcion == 1) {
            Contacto c;
            printf("Nombre: ");
            scanf("%s", c.nombre);

            printf("Apellido: ");
            scanf("%s", c.apellido);

            printf("Dia de nacimiento: ");
            scanf("%d", &c.dia);

            printf("Mes de nacimiento (0 = Enero, 11 = Diciembre): ");
            scanf("%d", (int *)&c.mes);

            printf("Telefono: ");
            scanf("%s", c.telefono);

            printf("Tipo (0 = Casa, 1 = Movil, 2 = Oficina, 3 = Otro): ");
            scanf("%d", (int *)&c.tipo);

            agregar_contacto(&agenda, c);
            printf("Contacto agregado correctamente.\n");

        } else if (opcion == 2) {
            char nombre[30];
            printf("Nombre a buscar: ");
            scanf("%s", nombre);

            int pos = buscar_contacto(&agenda, nombre);
            if (pos != -1)
                mostrar_contacto(agenda.contactos[pos]);
            else
                printf("No encontrado.\n");

        } else if (opcion == 3) {
            char tel[20];
            printf("Telefono a buscar: ");
            scanf("%s", tel);

            int pos = buscar_contacto_x_telefono(&agenda, tel);
            if (pos != -1)
                mostrar_contacto(agenda.contactos[pos]);
            else
                printf("No encontrado.\n");

        } else if (opcion == 4) {
            imprimir_contactos(agenda);

        } else if (opcion == 5) {
            ordenar_contactos(&agenda);
            printf("Contactos ordenados A -> Z.\n");

        } else if (opcion == 6) {
            ordenar_contactos_inv(&agenda);
            printf("Contactos ordenados Z -> A.\n");

        } else if (opcion == 7) {
            char archivo[50];
            printf("Nombre del archivo: ");
            scanf("%s", archivo);

            guardar_agenda(archivo, agenda);
            printf("Agenda guardada correctamente.\n");

        } else if (opcion == 8) {
            char archivo[50];
            printf("Nombre del archivo: ");
            scanf("%s", archivo);

            leer_agenda(&agenda, archivo);
            printf("Agenda cargada correctamente.\n");
        }

    } while (opcion != 9);

    printf("Saliendo del programa...\n");

    return 0;
}
