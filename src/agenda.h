#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};

typedef struct {
    char nombre[30];
    char apellido[30];
    int dia;
    int mes;
    char telefono[20];
    int tipo;
} Contacto;

typedef struct {
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos;
} Agenda;

// FUNCIONES PRINCIPALES
void iniciar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
void imprimir_agenda(Agenda agenda);
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);

// AUXILIARES
void mostrar_contacto(Contacto c);
void leer_contacto(Contacto *c);

// ARCHIVOS
void guardar_agenda(char *filename, Agenda agenda);
void leer_agenda(Agenda *agenda, char *filename);

#endif
