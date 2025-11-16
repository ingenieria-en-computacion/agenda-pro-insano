#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

// ENUMS CORRECTOS
enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};

enum Mes {
    ENERO,
    FEBRERO,
    MARZO,
    ABRIL,
    MAYO,
    JUNIO,
    JULIO,
    AGOSTO,
    SEPTIEMBRE,
    OCTUBRE,
    NOVIEMBRE,
    DICIEMBRE
};

// ESTRUCTURA CONTACTO
typedef struct {
    char nombre[30];
    char apellido[30];
    int dia;
    int mes;
    char telefono[20];
    int tipo;
} Contacto;

// ESTRUCTURA AGENDA
typedef struct {
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos;
} Agenda;

// PROTOTIPOS
void iniciar_agenda(Agenda *agenda);
void inicializar_agenda(Agenda *agenda);   // requerida por los tests

void agregar_contacto(Agenda *agenda, Contacto c);

int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);

void imprimir_agenda(Agenda agenda);
void mostrar_contacto(Contacto c);
void leer_contacto(Contacto *c);

void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);

void cargar_contactos(char *filename, Agenda *agenda);
void guardar_contactos(char *filename, Agenda agenda);

#endif
