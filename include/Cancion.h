// Interfaz de la clase Cancion.
// Relación: una Cancion ES UNA Pista (herencia).

#ifndef CANCION_H
#define CANCION_H

#include <string>
#include "Pista.h"


// TODO 3.1: declara la clase Cancion derivada de Pista con herencia pública.
class Cancion : public Pista {
private:
    std::string artista;
    std::string genero;

public:
    // Constructor: recibe titulo, min, seg, artista y genero
    Cancion(const std::string& titulo, int min, int seg,
            const std::string& artista, const std::string& genero);

    // Accedentes const
    std::string getArtista() const;
    std::string getGenero() const;

    // Método de despliegue
    void mostrar() const;
};
// Pregunta: ¿puede Cancion leer directamente el atributo titulo de Pista?
// ¿Por qué sí o por qué no? no porque es derivada 

#endif