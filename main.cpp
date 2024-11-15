#include "include/alumno.hpp"
#include "include/listaAlumnos.hpp"
#include "include/funcionesAlumnos.hpp"

int main() 
    {
        ListaAlumnos lista;
        cargarDesdeArchivo(lista);
        mostrarMenu(lista);
        
        return 0;
    }