#include <iostream>
#include "MatrizBase.h"    
#include "MatrizEstatica.h" 
#include "MatrizDinamica.h"

int main() {
    std::cout << "--- Sistema generico de Algebra Lineal ---" << std::endl;
    std::cout << "\n>> Demostracion de Genericidad (Tipo FLOAT) <<" << std::endl;

    std::cout << "\n// 1. Creacion de Matriz Dinamica (a traves del puntero base)" << std::endl;
    
    MatrizBase<float>* A = new MatrizDinamica<float>(3, 2); 
    A->cargarValores(); 
    std::cout << "A =" << std::endl;
    A->imprimir();

    std::cout << "\n// 2. Creacion de Matriz Estatica (a traves del puntero base)" << std::endl;
    
    MatrizBase<float>* B = new MatrizEstatica<float, 3, 2>(); 
    B->setValor(0, 0, 0.5); B->setValor(0, 1, 1.0);
    B->setValor(1, 0, 2.0); B->setValor(1, 1, 3.0);
    B->setValor(2, 0, 1.0); B->setValor(2, 1, 1.0);
    std::cout << "B =" << std::endl;
    B->imprimir();

    std::cout << "\n// 3. Operacion Polimorfica (Suma)" << std::endl;
    std::cout << "SUMANDO: Matriz C = A + B..." << std::endl;
    std::cout << "(La suma es manejada por el metodo virtual de MatrizDinamica)" << std::endl;

    MatrizBase<float>* C = A->sumar(*B);
    
    std::cout << "Matriz Resultado C (3x2, Tipo FLOAT):" << std::endl;
    C->imprimir();

    std::cout << "\n>> Demostracion de Limpieza de Memoria <<" << std::endl;
    
    std::cout << "Llamando al destructor de C..." << std::endl;
    delete C;

    std::cout << "Llamando al destructor de A..." << std::endl;
    delete A; 

    std::cout << "Sistema cerrado." << std::endl;
    return 0;
}