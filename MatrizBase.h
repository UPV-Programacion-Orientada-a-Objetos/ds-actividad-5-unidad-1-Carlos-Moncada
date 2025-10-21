#ifndef MATRIZBASE_H
#define MATRIZBASE_H

#include <iostream>

template <typename T>
class MatrizBase {
protected:
    int filas;
    int columnas;

public:
    MatrizBase(int f, int c) : filas(f), columnas(c) {}

    virtual ~MatrizBase() {
        std::cout << "-> Llamando al destructor de MatrizBase..." << std::endl;
    }

    virtual void cargarValores() = 0;
    virtual void imprimir() const = 0;
    virtual MatrizBase<T>* sumar(const MatrizBase<T>& otra) const = 0;

    virtual T getValor(int f, int c) const = 0;
    virtual void setValor(int f, int c, T valor) = 0;

    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }
};

#endif // MATRIZBASE_H