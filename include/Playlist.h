// Interfaz de la clase Playlist.
// Relación: una Playlist USA canciones y podcasts que ya existen (agregación).

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>

#include "Cancion.h"
#include "Duracion.h"
#include "Podcast.h"

// TODO 4.1: declara la clase Playlist.
class Playlist {
private:
    std::string nombre;
    std::vector<Cancion*> canciones;
    std::vector<Podcast*> podcasts;

public:
    // Constructor: recibe el nombre
    Playlist(const std::string& nombre);

    // TODO 4.2: declara  bool agregarCancion(Cancion* cancion);
    bool agregarCancion(Cancion* cancion);

    // TODO 4.3: declara  bool agregarPodcast(Podcast* podcast);
    bool agregarPodcast(Podcast* podcast);

    // TODO 4.4: declara  int cantidadPistas() const;
    int cantidadPistas() const;

    // TODO 4.5: declara  Duracion duracionTotal() const;
    Duracion duracionTotal() const;

    // TODO 4.6: declara  void mostrar() const;
    void mostrar() const;

    // Retos opcionales: ordenar y consultar pistas extremas.
    void ordenarPorDuracion();
    void mostrarPistaMasLarga() const;
    void mostrarPistaMasCorta() const;
    void mostrarMasLargaYMasCorta() const;
};

#endif

// Pregunta: la Playlist no tiene destructor que haga delete de las pistas.
// ¿Por qué eso es lo correcto en una agregación? porque la playlists solo almacena a la cancion o playlist