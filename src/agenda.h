#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

// Tipos externos necesarios para los tests
enum TipoTelefono { CASA, MOVIL, OFICINA, OTRO };

// Meses corregidos (tu enum tenía errores)
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

// El contacto que usan los tests
typedef struct Persona {
    char nombre[30];
    char apellido[30];
    int dia;
    enum Mes mes;
    char telefono[20];
    enum TipoTelefono tipo;
} Contacto;

// Agenda completa
typedef struct Agenda {
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos;
} Agenda;


// --------- PROTOTIPOS QUE PIDEN LOS TESTS -----------

void iniciar_agenda(Agenda *agenda);
void inicializar_agenda(Agenda *agenda);   // alias requerido por test

void agregar_contacto(Agenda *agenda, Contacto c);

void imprimir_contactos(Agenda agenda);

int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);

void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);

void mostrar_contacto(Contacto c);
void leer_contacto(Contacto *c);

// OJO: Los tests esperan estos prototipos exactos:
void guardar_agenda(char *filename, Agenda agenda);
void leer_agenda(Agenda *agenda, char *filename);

#endif


