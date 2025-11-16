#ifndef __AGENDA_H__
#define __AGENDA_H__

#define MAX_CONTACTOS 100

/* Tipos de teléfono */
enum TipoTelefono {CASA, MOVIL, OFICINA, OTRO};

/* Meses (FEBRERO estaba mal escrito en tu versión) */
enum Mes {ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE};

/* Estructura del contacto */
struct Persona {
    char nombre[30];
    char apellido[30];
    int dia;
    int mes;         // usar enum Mes
    char telefono[20];
    int tipo;        // usar enum TipoTelefono
};

typedef struct Persona Contacto;

/* Estructura agenda */
typedef struct Agenda {
    Contacto contactos[MAX_CONTACTOS];
    int num_contactos;
} Agenda;

/* --- PROTOTIPOS EXIGIDOS POR LOS TESTS --- */

/* Inicialización */
void iniciar_agenda(Agenda *agenda);
void inicializar_agenda(Agenda *agenda);   // alias requerido por test

/* Operaciones básicas */
void agregar_contacto(Agenda *agenda, Contacto c);
void mostrar_contacto(Contacto c);

/* Impresiones */
void imprimir_agenda(Agenda agenda);
void imprimir_contactos(Agenda agenda);    // requerido por test

/* Búsquedas */
int buscar_contacto(Agenda *agenda, char *nombre);
int buscar_contacto_x_telefono(Agenda *agenda, char telefono[]);

/* Ordenamiento */
void ordenar_contactos(Agenda *agenda);
void ordenar_contactos_inv(Agenda *agenda);

/* Lectura de un contacto */
void leer_contacto(Contacto *c);

/* Guardado y carga */
void guardar_contactos(char *filename, Agenda agenda);
void cargar_contactos(char *filename, Agenda *agenda);
void leer_agenda(char *filename, Agenda *agenda);   // alias requerido por test

#endif // __AGENDA_H__

