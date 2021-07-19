#include "GrafoNDirigido.h"
#include <climits>
#include <cassert>

GrafoNDirigido::GrafoNDirigido() {
    this->matriz = new int*[MAX_VERTICES];
    for(int i = 0 ; i < MAX_VERTICES; i++)
        this->matriz[i] = new int[MAX_VERTICES];

    for(int i = 0 ; i < MAX_VERTICES ; i++)
        for(int j = 0 ; j < MAX_VERTICES ; j++)
            this->matriz[i][j] = INT_MIN;

    this->numVertices = 0;
}

void GrafoNDirigido::agregarVertice() {
    this->numVertices++;
}

void GrafoNDirigido::agregarArista(int origen, int destino, int costo) {
    if((origen >= 0) && (origen < this->numVertices) && (destino >= 0) && (destino < this->numVertices)){
        this->matriz[origen] [destino] = costo;
        this->matriz[destino] [origen] = costo; }
}

int GrafoNDirigido::cantVertices() const {
    return this->numVertices;

}

bool GrafoNDirigido::existeArista(int origen, int destino) const {
    assert((origen >= 0) && (origen < this->numVertices) && (destino >= 0) && (destino < this->numVertices));
    return this->matriz[origen][destino] != INT_MIN;
}

list<int>  GrafoNDirigido::adyacentes(int vertice) const {
    list<int> lRetorno;
    for(int i = 0 ; i < this->numVertices; i++)
        if(this->matriz[vertice][i] != INT_MIN)
            lRetorno.push_back(i);

    return lRetorno;
}

GrafoNDirigido::~GrafoNDirigido() {

}
