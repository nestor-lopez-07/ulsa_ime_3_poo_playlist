// Interfaz de la clase Podcast.
// Relación: un Podcast ES UNA Pista (herencia).

#ifndef PODCAST_H
#define PODCAST_H

#include <string>
#include "Pista.h"

// TODO 3.2: declara la clase Podcast derivada de Pista con herencia pública.
class Podcast : public Pista {
private:
    std::string anfitrion;
    int numeroEpisodio;

public:
    // Constructor: recibe titulo, min, seg, anfitrion y numeroEpisodio
    Podcast(const std::string& titulo, int min, int seg,
            const std::string& anfitrion, int numeroEpisodio);

    // Accedentes const
    std::string getAnfitrion() const;
    int getNumeroEpisodio() const;

    // Método de despliegue
    void mostrar() const;
};

#endif
// Pregunta: ¿qué código te ahorraste gracias a la herencia?
//titulo y duracion
