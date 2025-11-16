#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};
enum Mes {ENERO = 1, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE};

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

// FUNCIONES
void iniciar_agenda(Agenda *agenda);
void agregar_contacto(Agenda *agenda, Contacto c);
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);

void mostrar_contacto(Contacto c);
void leer_contacto(Contacto *c);

void cargar_contactos(char *filename, Agenda *agenda);
void guardar_contactos(char *filename, Agenda agenda);

#endif
