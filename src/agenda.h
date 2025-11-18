#ifndef __AGENDA_H__
#define __AGENDA_H__

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTOS 100

enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};

enum Mes {
    ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO,
    JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE
};

typedef struct {
    char nombre[30];
    char apellido[30];
    int dia;
    enum Mes mes;
    char telefono[20];
    enum TipoTelefono tipo;
} Contacto;

typedef struct {
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos;
} Agenda;

void inicializar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);
void ordenar_contactos_inv(Agenda *agenda);
void ordenar_contactos(Agenda *agenda);

void imprimir_contactos(Agenda agenda);

void cargar_contactos(char *filename, Agenda *agenda);
void guardar_agenda(char *filename, Agenda agenda);

#endif

