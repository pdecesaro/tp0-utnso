#include "client.h"
#include <readline/history.h>
int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;
	char* linea;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = log_create("tp0-log", "log",1,log_level_from_string("INFO"));
	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

	log_info(logger,"Hola! Soy un log");
	
	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = config_create("cliente.config");

	valor = config_get_string_value(config,"CLAVE");
	ip = config_get_string_value(config,"IP");
	puerto = config_get_string_value(config,"PUERTO");
	log_info(logger,valor);
	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config


	/* ---------------- LEER DE CONSOLA ---------------- */
	
	leer_consola(logger);
	while (1){
		linea = readline(">");
		if(linea){
			add_history(linea);
			log_info(logger,linea);
		}

		if(!strncmp(linea, "", 1)){
			free(linea);
			break;
		}
		
		printf("%s\n", linea);
		free(linea);
	}
	
	
	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
	config_destroy(config);
	log_destroy(logger);
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
