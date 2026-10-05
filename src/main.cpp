// Práctica 1: Playlist de música
// Programación Orientada a Objetos - Ingeniería Mecatrónica, 3er semestre
//
// Compilar (desde la raíz del repositorio):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/*.cpp -o playlist
// Ejecutar:
//   ./playlist

#include <iostream>
#include "Playlist.h"

int main() {

    std::cout << "Practica 1: Playlist de musica" << std::endl;

    // TODO 5.1: crea la biblioteca: al menos tres canciones y un podcast.
    // Canciones de Ariel Camacho y Los Plebes del Rancho
    Cancion c1("Te Metiste", 3, 45, "Ariel Camacho", "Sierreño");
    Cancion c2("El Karma", 3, 30, "Ariel Camacho", "Corridos");
    Cancion c3("Hablemos", 3, 5, "Ariel Camacho", "Sierreño");
    Cancion c4("El Rey de Corazones", 2, 40, "Ariel Camacho", "Sierreño");
    Podcast p1("Historias de terror", 45, 20, "Podcast Musica", 5);
    // TODO 5.2: crea dos playlists y agrega pistas a cada una.
    //   Al menos una canción debe estar en las dos playlists.
    Playlist favs("Mis Favoritas");
    Playlist roadtrip("Viaje en Carretera");

    favs.agregarCancion(&c1);
    favs.agregarCancion(&c2);
    favs.agregarPodcast(&p1);

    roadtrip.agregarCancion(&c2); 
    roadtrip.agregarCancion(&c3);

    // TODO 5.3: muestra ambas playlists.
    std::cout << "MOSTRANDO PLAYLIST 1" << std::endl;
    favs.mostrar();
    std::cout << std::endl;

    std::cout << "MOSTRANDO PLAYLIST 2" << std::endl;
    roadtrip.mostrar();
    std::cout << std::endl;

    std::cout << "RETOS OPCIONALES" << std::endl;
    favs.ordenarPorDuracion();
    std::cout << std::endl;
    favs.mostrarMasLargaYMasCorta();
    std::cout << std::endl;

    // TODO 5.4: experimentos guiados de la Fase 3.
    std::cout << "EXPERIMENTOS GUIADOS (FASE 3) " << std::endl;
    std::cout << "Modificando el titulo de c3 con setTitulo()..." << std::endl;
    c3.setTitulo("Hablemos 1");
    std::cout << "Mostrando la playlist 'Viaje en Carretera' reflejando el cambio por punteros:" << std::endl;
    roadtrip.mostrar();
    std::cout << std::endl;

    // TODO 5.5: casos de prueba de la Fase 4.
    std::cout << "CASOS DE PRUEBA (FASE 4) ---" << std::endl;
    std::cout << "Prueba de Duracion negativa (-2 min, 75 seg): ";
    Duracion durInvalida(-2, 75);
    durInvalida.imprimir(); // Imprime 0:00 debido a la normalización
    std::cout << std::endl;

    std::cout << "Prueba de Duracion con desbordamiento (0 min, 85 seg): ";
    Duracion durDesborde(0, 85);
    durDesborde.imprimir(); // Imprime 1:25
    std::cout << std::endl;

    return 0;
}
