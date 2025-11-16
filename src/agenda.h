#ifndef __AGENDA_H__
#define __AGENDA_H__

#include <stdio.h>
#include <string.h>

#define MAX_CONTACTOS 100

// Tipos de teléfono
enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};

// Meses del año
enum Mes {
    ENERO, FEBERO, MARZO, ABRIL, MAYO, JUNIO, JULIO,
    SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE
};

// Estructura del contacto
struct Persona {
    char nombre[30];
    char apellido[30];
    int dia;
    enum Mes mes;
    char telefono[20];
    enum TipoTelefono tipo;
};

typedef struct Persona Contacto;

// Estructura Agenda
typedef struct Agenda {
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos;
} Agenda;

// PROTOTIPOS DE FUNCIONES

void iniciar_agenda(Agenda *agenda);
void inicializar_agenda(Agenda *agenda);  // algunos tests usan este nombre también

void agregar_contacto(Agenda *agenda, Contacto c);

void imprimir_agenda(Agenda agenda);
void imprimir_contactos(Agenda agenda);   // requerido por test_mostrar_contactos

int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);

void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);

void mostrar_contacto(Contacto c);
void leer_contacto(Contacto *c);

void cargar_contactos(char *filename, Agenda *agenda);
void leer_agenda(Agenda *agenda, char *filename); // requerido por test_leer

void guardar_contactos(char *filename, Agenda agenda);
void guardar_agenda(char *filename, Agenda agenda); // requerido por test_guardar

#endif // __AGENDA_H__
