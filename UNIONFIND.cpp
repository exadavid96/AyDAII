#include "UNIONFIND.h"
#include <iostream>

using namespace std;

UNIONFIND::UNIONFIND(int tamanio) {

    this->p = new int[tamanio];
    this->tamanio = tamanio;
    for(int i = 0; i < tamanio ; i++)
        this->p[i] = this->DISCERNIBLE;

}

void UNIONFIND::unir(int i, int j) {
    this->p[i] = j;
}

int UNIONFIND::buscar(int i) const {

    while ( p[i]>= 0)
        i=this->p[i];
    return i;
}

void UNIONFIND::mostrar() {
    for( int i = 0; i < this->tamanio ; i++ )
        cout<<this->p[i]<<" ";
    cout<<endl;
}

UNIONFIND::~UNIONFIND() {
    delete [] p ;
}
