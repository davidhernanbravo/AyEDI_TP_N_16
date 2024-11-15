#include "../include/funcionesAlumnos.hpp"

#include <iostream>
#include <fstream>

void cargarDesdeArchivo(ListaAlumnos &lista) 
    {
        ifstream archivo("Alumnos.txt");

        if (archivo.is_open()) 
            {
                Alumno alumno;

                while (archivo >> alumno.id) 
                    {
                        archivo.ignore();
                        getline(archivo, alumno.nombre);
                        getline(archivo, alumno.domicilio);
                        lista.insertarAlumno(alumno);
                    }
                archivo.close();
            }
    }

void guardarEnArchivo(const ListaAlumnos &lista) 
    {
        ofstream archivo("Alumnos.txt");

        for (int i = 0; i < lista.obtenerContador(); i++) 
            {
                Alumno alumno = lista.obtenerAlumno(i);
                archivo << alumno.id << endl;
                archivo << alumno.nombre << endl;
                archivo << alumno.domicilio << endl;
            }
            
        archivo.close();
    }

void mostrarMenu(ListaAlumnos &lista) 
    {
        int opcion;

        do 
            {
                cout << endl << "REGISTRO DE ALUMNOS:" << endl;
                cout << "-------------------" << endl << endl;
                cout << "1. Insertar Alumno" << endl;
                cout << "2. Eliminar Alumno" << endl;
                cout << "3. Buscar Alumno"<< endl;
                cout << "4. Mostrar un Alumno" << endl;
                cout << "5. Mostrar Listado de Alumnos" << endl;
                cout << "6. Ordenar Listado" << endl;
                cout << "0. Salir" << endl << endl;

                cout << "Seleccione una opcion: ";
                cin >> opcion;
                cin.ignore();
                cout << endl;

                Alumno alumno;
                int id, indice;
                string nombre;

                switch (opcion) 
                    {
                        case 1:
                            cout << "Ingrese ID: ";
                            cin >> alumno.id;
                            cin.ignore();

                            cout << "Ingrese Nombre: ";
                            getline(cin, alumno.nombre);

                            cout << "Ingrese Domicilio: ";
                            getline(cin, alumno.domicilio);

                            lista.insertarAlumno(alumno);
                            guardarEnArchivo(lista);

                            break;

                        case 2:
                            cout << "Ingrese ID del alumno a eliminar: ";
                            cin >> id;

                            lista.eliminarAlumno(id);
                            guardarEnArchivo(lista);

                            break;

                        case 3:
                            cout << "Ingrese Nombre a buscar: ";
                            getline(cin, nombre);

                            indice = lista.buscarAlumno(nombre);

                            if (indice != -1) 
                                {
                                    lista.mostrarAlumno(indice);

                                } else 
                                    {
                                        cout << "Alumno no encontrado." << endl;
                                    }

                            break;

                        case 4:
                            cout << "Ingrese Nombre a mostrar: ";
                            getline(cin, nombre);

                            indice = lista.buscarAlumno(nombre);

                            if (indice != -1) 
                                {
                                    lista.mostrarAlumno(indice);
                                } else 
                                    {
                                        cout << "Alumno no encontrado." << endl;
                                    }

                            break;

                        case 5:
                            lista.mostrarListaAlumnos();

                            break;

                        case 6:
                            bool ascendente;

                            cout << "Ordenar Ascendente (1) o Descendente (0): ";
                            cin >> ascendente;

                            lista.ordenarListaAlumnos(ascendente);
                            lista.mostrarListaAlumnos();

                            break;
                    }

            } while (opcion != 0);
    }