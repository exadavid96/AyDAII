#include <iostream>
#include "GrafoDirigido.h"
#include "GrafoNDirigido.h"
#include <list>
#include <queue>
#include "UNIONFIND.h"



using namespace std;

const int INFINITO = INT_MAX;

void cargarGrafoD(GrafoDirigido & grafoD);
void cargarGrafoN(GrafoNDirigido & grafoN);



//Primera versión sin considerar el tiempo con Grafo No Dirigido
void DFS_ND(GrafoNDirigido grafoN , int fuente , char visitados []);
void bosqueDFS_ND (GrafoNDirigido grafoN );

//Segunda versión considerando el tiempo y predecesor con Grafo Dirigido

struct infoDFS {
    char estado;
    int inicioVisita;
    int finVisita;
    int predecesor;
};


void DFS_D(GrafoDirigido grafoD , int fuente , int & tiempo , infoDFS arr[]);
void bosqueDFS_D(GrafoDirigido grafoD , infoDFS arr[]);

//Primer versión BFS
void BFS_f(GrafoDirigido grafoD , int fuente , char estado[]);
void bosqueBFS_f(GrafoDirigido grafoD);

//Excentricidad en un Grafo DFS
int DFS_excentricidadGrafo(GrafoNDirigido grafoN);


//Excentricidad en un Grafo BFS
int BFS_excentricidadGrafo(GrafoNDirigido grafoN);

//Clasificacion de arcos
void DFS_clasificacion (GrafoDirigido grafoD , int fuente, infoDFS arr[] , int & t);

//Clasificación de aristas
void DFS_aristas (GrafoNDirigido grafoN , int fuente , infoDFS arr[] , int & tiempo);
void bosqueDFS_aristas (GrafoNDirigido grafoN , infoDFS arr[]);

//Numeración Post-Orden
void DFS_postOrden (GrafoDirigido grafoD , int fuente, char estado[] , int postOrden[] , int & num);
void numeracionPostOrden (GrafoDirigido grafoD , int postOrden[]);

//Numeración Pre-Orden
void DFS_preOrdenGD (GrafoDirigido grafoD , int fuente, char estado[] , int preOrden[] , int & num);
void numeracionPreOrdenGD (GrafoDirigido grafoD , int preOrden[]);



//Test de Aciclicidad
bool esAciclico (GrafoDirigido grafoD);

//Sort Topológico
void sortTopologico(GrafoDirigido grafoD, int fuente , char estado[] , list<int> & l);
list<int> bosqueSortTopologico (GrafoDirigido grafoD);

//Puntos de Articulación
void DFS_preOrdenGND (GrafoNDirigido grafoN , int fuente, char estado[] , int * preOrden , int * masAlto, int & num);
void puntosArticulacion(GrafoNDirigido grafoN, int i);

//Componentes Fuertemente Conectadas
list< list<int> > componentesFC (GrafoDirigido grafoD);
void DFS_CFC ( GrafoDirigido grafoD , int fuente , char estado[] , list<int> & verticesPostOrden , GrafoDirigido & grafoDR);

//Componentes Conexas
list< list<int> > componentesConexas (GrafoNDirigido grafoN);
void DFS_CC ( GrafoNDirigido grafoN , int fuente , list<int> & componente , char estado[]);


int main() {

    GrafoDirigido grafoD;
    GrafoNDirigido grafoN;

    cargarGrafoN(grafoN);
    int numVerticesGND = grafoN.cantVertices();
    //cargarGrafoD(grafoD);
    int numVerticesGD = grafoD.cantVertices();

    /*    //////////////////////Testing Grafo Dirigido/////////////////////////////////////////////

    grafo.agregarArco(0,1,10);
    grafo.agregarArco(0,3,30);
    grafo.agregarArco(0,4,100);
    grafo.agregarArco(1,2,50);
    grafo.agregarArco(2,4,10);
    grafo.agregarArco(3,2,20);
    grafo.agregarArco(3,4,60);


    int vertAdy;
    cout << "Ingrese un vertice para determinar sus adyacentes"<<endl;
    cin>> vertAdy;
    list<GrafoDirigido::Nodo> ady = grafo.adyacentes(vertAdy);
    list<GrafoDirigido::Nodo>::const_iterator it;
    cout << "Los adyacentes de "<< vertAdy << " son: ";
    for ( it = ady.cbegin(); it!= ady.cend(); it++)
        cout << it->vertice << " ";
    cout<<endl;

    if(grafo.existeArco(3,1))
        cout <<"Existe arco";
    */

    /*//////////////////////////////////7Testing Grafo No Dirigido////////////////////////////////////

    int vertAdy;
    cout << "Ingrese un vertice para determinar sus adyacentes"<<endl;
    cin>> vertAdy;
    list<int> ady = grafoN.adyacentes(vertAdy);
    list<int>::const_iterator it;
    cout << "Los adyacentes de "<< vertAdy << " son: ";
    for ( it = ady.cbegin(); it!= ady.cend(); it++)
        cout << *it << " ";
    cout<<endl;

    if(grafoN.existeArista(3,1))
        cout <<"Existe arco";
    */

    /*    ///////////////////////////////////////////DFS Primera versión/////////////////////////////////////////////
    bosqueDFS_ND(grafoN);*/

    /* //////////////////////////// DFS segunda versión /////////////////////////////////////////////////////

    infoDFS arr[numVerticesGD];
    bosqueDFS_D(grafoD,arr);
    for(int i = 0 ; i < numVerticesGD ; i++){
        cout<< "Vertice "<< i << " :"<<endl;
        cout<< "    Inicio: "<<arr[i].inicioVisita<<endl;
        cout<< "    Fin: "<<arr[i].finVisita<<endl;
        cout<< "    Predecesor: ";
        if(arr[i].predecesor != -1)
          cout << " "<<arr[i].predecesor<<endl;
        else
            cout<< "No tiene predecesor"<<endl;
        cout<<"......................."<<endl;
    }
    */

    /*//////////////////////////////////// BFS Primera Version ///////////////////////////////////////////////////
    bosqueBFS_f(grafoD);
    */

    ////////////////////////////////// Excentricidad de un Grafo //////////////////////////////////////////////
    //cout << "El grado de excentricidad del Grafo es: "<< DFS_excentricidadGrafo(grafoN) << endl;
    //cout << "El grado de excentricidad del Grafo es: "<< BFS_excentricidadGrafo(grafoN) << endl;


    ////////////////////////////////////Clasificacion de arcos////////////////////////////////////////////////
    /*
    infoDFS arr[numVerticesGD];
    for(int i = 0 ; i < numVerticesGD; i++){
        arr[i].estado = 'N';
        arr[i].inicioVisita = INFINITO;
        arr[i].finVisita = INFINITO;
    }
    int tiempo = 1;
    DFS_clasificacion(grafoD,0,arr,tiempo);
    cout<<"........................................."<<endl;
    for(int i = 0 ; i < numVerticesGD ; i++){
        cout<< "Vertice "<< i << " :"<<endl;
        cout<< "    Inicio: "<<arr[i].inicioVisita<<endl;
        cout<< "    Fin: "<<arr[i].finVisita<<endl;

    }
    */

    ///////////////////////////////////Clasificacion de aristas////////////////////////////////////////////////

    /*infoDFS arr[numVerticesGND];
    for(int i = 0 ; i < numVerticesGND; i++){
        arr[i].estado = 'N';
        arr[i].inicioVisita = INFINITO;
        arr[i].finVisita = INFINITO;
        arr[i].predecesor = -1;
    }

    bosqueDFS_aristas(grafoN,arr);
    for(int i = 0 ; i < numVerticesGND ; i++){
        cout<< "Vertice "<< i << " :"<<endl;
        cout<< "    Inicio: "<<arr[i].inicioVisita<<endl;
        cout<< "    Fin: "<<arr[i].finVisita<<endl;

    }*/


     ///////////////////////////////////Numeración Post Orden/////////////////////////////
     /*int postOrden[grafoD.cantVertices()] ;
     numeracionPostOrden(grafoD,postOrden);
     for (int i = 0; i < grafoD.cantVertices() ; i++)
         cout<<"Vertice "<< i << " : " << postOrden[i] <<endl;
     cout<<endl;*/

    ///////////////////////////////////Numeración Pre Orden/////////////////////////////
    /*int preOrden[grafoD.cantVertices()] ;
    numeracionPreOrdenGD(grafoD,preOrden);
    for (int i = 0; i < grafoD.cantVertices() ; i++)
        cout<<"Vertice "<< i << " : " << preOrden[i] <<endl;
    cout<<endl;*/

    //////////////////////////////////Test de Aciclicidad/////////////////////////////////
    /*if ( esAciclico(grafoD))
        cout<<"El grafo no tiene ciclos"<<endl;
    else
        cout<<"El grafo tiene ciclos"<<endl;*/

    //////////////////////////////////Sort Topológico/////////////////////////////////

    /*list<int> ordTopologico = bosqueSortTopologico(grafoD);
    list<int>::const_iterator iterador;
    cout<<"El ordenamiento topologico es: "<<endl;
    for (iterador = ordTopologico.cbegin() ; iterador != ordTopologico.cend() ; iterador++)
        cout<< *iterador << "-" ;*/

    ///////////////////////////////Puntos de Articulación///////////////////////////////////

    //puntosArticulacion(grafoN, 4);

    ///////////////////////////////Componentes Fuertemente Conectadas///////////////////////////////////

    /*list< list<int> > lComponentes = componentesFC(grafoD);

    list< list<int> >::const_iterator itCompS ;
    for (itCompS = lComponentes.cbegin() ; itCompS != lComponentes.cend() ; itCompS++){
        list<int>::const_iterator itComp;
        for(itComp = (*itCompS).cbegin() ; itComp != (*itCompS).cend() ; itComp++)
            cout<< *itComp <<"-";
        cout<<"........................."<<endl;
    }
    */

    ///////////////////////////////Componentes Conexas - DFS ///////////////////////////////////

    /*list< list<int> > lcompConexas = componentesConexas(grafoN);
    list< list<int> >::const_iterator itCompS ;
    for (itCompS = lcompConexas.cbegin() ; itCompS != lcompConexas.cend() ; itCompS++){
        list<int>::const_iterator itComp;
        for(itComp = (*itCompS).cbegin() ; itComp != (*itCompS).cend() ; itComp++)
            cout<< *itComp <<"-";
        cout<<"........................."<<endl;
    }
     */





    return 0;
}



void cargarGrafoD(GrafoDirigido & grafoD){

    int cantidadVertices;
    cout <<"Ingrese el numero de vertices para tener en el grafo"<<endl;
    cin >> cantidadVertices;
    for(int i = 1 ; i <= cantidadVertices ; i++)
        grafoD.agregarVertice();
    char continuar;
    do{
        int origen,destino,costo;

        cout<<"Ingrese el arco  con su costo"<<endl;
        cin >> origen >> destino >> costo;
        grafoD.agregarArco(origen,destino,costo);
        cout<<"Continuar?"<<endl;
        cin >> continuar;
    } while ( continuar == 's');
}

void cargarGrafoN(GrafoNDirigido & grafoN) {

    int cantidadVertices;
    cout <<"Ingrese el numero de vertices para tener en el grafo"<<endl;
    cin >> cantidadVertices;
    for(int i = 1 ; i <= cantidadVertices ; i++)
        grafoN.agregarVertice();
    char continuar;
    do{
        int origen,destino,costo;

        cout<<"Ingrese la arista con su costo"<<endl;
        cin >> origen >> destino >> costo;
        grafoN.agregarArista(origen,destino,costo);
        cout<<"Continuar?"<<endl;
        cin >> continuar;
    } while ( continuar == 's');

}

void DFS_ND(GrafoNDirigido grafoN , int fuente , char visitados []){

    cout<< fuente << "-"; // Procesamiento, en este caso se imprime el vértice en el que se está recorriendo
    visitados[fuente] = 'v';
    list<int> ady = grafoN.adyacentes(fuente); // En ady estarán los adyacentes del fuente
    list<int>:: const_iterator itAdy; //El iterador que recorrera ady
    for ( itAdy = ady.cbegin() ; itAdy != ady.cend() ; itAdy++) //Se recorren todos los adyacentes del fuente
        if( visitados[*itAdy] != 'v') { //Se controla si el vértice adyacente en ese momento ya se visitó
            visitados[*itAdy] = 'v';
            DFS_ND(grafoN, *itAdy , visitados);
        }
}

void bosqueDFS_ND (GrafoNDirigido grafoN ){

    int N = grafoN.cantVertices();
    char visitados[N];
    for(int i = 0; i < N ; i++) //Se marca a todos los vertices como "No visitados"
        visitados[i] = 'n';
    for(int i = 0; i < N ; i++) //Se hace el control desde afuera del DFS para cada vértice si fue visitado.
        if(visitados[i] != 'v')
            DFS_ND(grafoN,i,visitados);
}

void DFS_D(GrafoDirigido  grafoD , int fuente , int & tiempo , infoDFS arr []) {

    arr[fuente].estado = 'v'; //Se visita al vértice fuente
    cout<<fuente <<'-';
    arr[fuente].inicioVisita = tiempo; //Se marca el tiempo en que se comienza a visitar
    tiempo++;
    list<GrafoDirigido::Nodo> ady = grafoD.adyacentes(fuente);
    list<GrafoDirigido::Nodo>::const_iterator itAdy;
    for( itAdy = ady.cbegin(); itAdy != ady.cend() ; itAdy++)
        if(arr[itAdy->vertice].estado == 'n'){
            arr[itAdy->vertice].predecesor = fuente;
            arr[itAdy->vertice].estado = 'd';
            DFS_D(grafoD, itAdy->vertice , tiempo , arr);
        }
    arr[fuente].finVisita = tiempo;
    tiempo++;

}

void bosqueDFS_D(GrafoDirigido grafoD , infoDFS arr[]){

    int tiempo = 1;
    int numVerticesGD = grafoD.cantVertices();
    for(int i = 0; i < numVerticesGD ; i++){
        arr[i].estado = 'n';
        arr[i].inicioVisita = 0;
        arr[i].finVisita = 0;
        arr[i].predecesor = -1;
    }
    for(int i = 0; i < numVerticesGD ; i++)
        if(arr[i].estado == 'n')
            DFS_D(grafoD , i , tiempo, arr);

    cout<<endl;
}

void BFS_f(GrafoDirigido grafoD , int fuente , char estado[]) {
    queue<int> f;
    f.push(fuente); //Se inserta el elemento fuente en la fila
    estado[fuente] = 'V';
    cout<< fuente << "-"; //Procesamiento del vértice
    while (!f.empty()){ //Iteracion principal hasta que la fila no se vacíe.
        list<GrafoDirigido::Nodo> ady = grafoD.adyacentes(f.front());//Lista de adyacentes del primer elemento de la fila.
        list<GrafoDirigido::Nodo>::const_iterator itAdy;
        for( itAdy = ady.cbegin() ; itAdy!= ady.cend() ; itAdy++){ //Se recorre toda la lista de adyacencia
            int verticeActual = itAdy->vertice;
            if ( estado[verticeActual] != 'V') { //Control de si el vértice está visitado o no
                //Se visita verticeActual
                f.push( verticeActual);//Se ingresa a la fila.
                cout << verticeActual << "-"; //Se procesa.
                estado[verticeActual] = 'V';
            }
        }
        //Luego de recorrer los adyacentes del primero de la fila, se elimina
        f.pop();
    }
}

void bosqueBFS_f(GrafoDirigido grafoD){
    int N = grafoD.cantVertices();
    char estado[N];
    for(int i = 0; i < N ; i++)
        if(estado[i] != 'V')
            BFS_f(grafoD,i,estado);

}

void DFS_excentricidad(GrafoNDirigido grafoN , int fuente , char estado[] , int prof[] , int act) {
    act++;
    estado[fuente] = 'V';
    if ( act < prof[fuente] )
        prof[fuente] = act;
    /*cout<< "act: " << act <<endl;
    cout << "La profundidad del vertice " << fuente << " es: " << prof[fuente] <<endl;
    cout <<"........................................"<<endl;*/

    list<int> ady = grafoN.adyacentes(fuente);
    list<int>:: const_iterator itAdy ;
    for(itAdy=ady.cbegin() ; itAdy!=ady.cend(); itAdy++)
        if(estado[*itAdy] != 'V'){
            cout<<"Se llama a recursion desde: "<< fuente <<" a "<< *itAdy << endl;
            DFS_excentricidad(grafoN,*itAdy,estado,prof,act); //Cada llamado recursivo aumenta la profundidad

            estado[*itAdy] = 'N';
        }
}

void cargarDistancias (int prof[], int N){
    for (int i = 0; i < N ; i++)
        prof[i] = INT_MAX;
}

int mayorDistancia( int prof[] ,int N){

    int mayorActual = INT_MIN;
    for ( int i = 0; i < N; i++)
        if(prof[i] > mayorActual)
            mayorActual = prof[i];

    return mayorActual;

}

int DFS_excentricidadGrafo(GrafoNDirigido grafoN) {

    int N = grafoN.cantVertices();
    char estado[N];
    int mayorActual = 0;

    for(int i = 0; i < N ; i++){
        for (int j = 0; j < N ; j++)
            estado[j]='N';
        int prof[N];
        cargarDistancias(prof,N);
        DFS_excentricidad(grafoN,i,estado, prof , -1);
        int excVertice = mayorDistancia(prof,N);

        cout << "La excentricidad del vertice " << i << " es: " << excVertice<<endl;
        if(excVertice > mayorActual){
            mayorActual = excVertice;
            if ( excVertice == INT_MAX)
                return INT_MAX;
        }
    }
    return mayorActual;
}




int BFS_excentricidad(GrafoNDirigido grafoN , int fuente , char estado[]) {
    queue<int> f;
    int excVertice = 0;
    int visitados = 1; //Permite controlar al final si quedaron vertices sin visitar
    int verticesNivel = 0; // Marca después de cuántos vértices desencolados debo actualizar la excentricidad
    int verticesDesencolados = 0;
    int limite = 1; // Por defecto al arrancar en un vértice, después de la primer desencolada, ya el próximo hará dist 1
    f.push(fuente); //Se inserta el elemento fuente en la fila
    estado[fuente] = 'V';
    while (!f.empty()){ //Iteracion principal hasta que la fila no se vacíe.
        list<int> ady = grafoN.adyacentes(f.front());//Lista de adyacentes del primer elemento de la fila.
        list<int>::const_iterator itAdy;
        for( itAdy = ady.cbegin() ; itAdy!= ady.cend() ; itAdy++) { //Se recorre toda la lista de adyacencia

            int verticeActual = *itAdy;
            if (estado[verticeActual] != 'V') { //Control de si el vértice está visitado o no
                //Se visita verticeActual
                f.push(verticeActual);//Se ingresa a la fila.
                visitados++;
                verticesNivel++;
                estado[verticeActual] = 'V';
            }
        }
        f.pop();
        verticesDesencolados++;
        cout<<"Vertices Nivel: "<< verticesNivel <<", Vertices desencolados: "<<verticesDesencolados<<", Limite: "<< limite<<endl;

        if (verticesDesencolados == limite){
            excVertice++; //Actualizo la excentricidad
            limite = verticesNivel; //Ahora el límite son aquellos que entraron en la anterior.
            verticesDesencolados = 0; //Reseteo los vertices desencolados
            verticesNivel = 0;
        }

    }
    if ( (excVertice == 1) || (visitados < grafoN.cantVertices() ) ) //Esto
        return INT_MAX;
    else
        return excVertice - 1;
}



int BFS_excentricidadGrafo(GrafoNDirigido grafoN) {

    int N = grafoN.cantVertices();
    char estado[N];
    int mayorActual = 0;

    for(int i = 0; i < N ; i++){
        int excVertice = BFS_excentricidad(grafoN,i,estado);
        for (int j = 0; j < N ; j++)
            estado[j]='N';
        cout << "La excentricidad del vertice " << i << " es: " << excVertice<<endl;
        if(excVertice > mayorActual)
            mayorActual = excVertice;
    }
    return mayorActual;
}

void DFS_clasificacion (GrafoDirigido grafoD , int fuente, infoDFS arr[] , int & t){

    arr[fuente].estado = 'D'; //Se descubre el vértice al cuál se está visitando
    arr[fuente].inicioVisita = t++; //Se setea el tiempo de descubrimiento, actualizando el tiempo
    list<GrafoDirigido::Nodo> ady = grafoD.adyacentes(fuente);
    list<GrafoDirigido::Nodo>::const_iterator itAdy;
    for( itAdy = ady.cbegin() ; itAdy != ady.cend() ; itAdy++){
        cout<<"EL arco ( "<<fuente<<" , "<<itAdy->vertice<<" ) es ";
        if(arr[itAdy->vertice].estado != 'D'){ //Control si es un arco tree, que genera la recursión
            cout<<"tree"<<endl;
            DFS_clasificacion(grafoD,itAdy->vertice,arr,t);
        }
        else if( arr[fuente].inicioVisita < arr[itAdy->vertice].inicioVisita) //Control si es un arco forward
                 cout<<"forward"<<endl;
             else if(arr[itAdy->vertice].finVisita == INFINITO) //Control si es un arco back
                    cout<<"back"<<endl;
                  else
                      cout<<"cross"<<endl; //Si no se cumplen las tres condiciones anteriores es cross
    }
    arr[fuente].finVisita = t++; //Se setea el tiempo de finalización del vértice visitado. Aquí se vuelve al invocador.
}

void DFS_aristas (GrafoNDirigido grafoN , int fuente , infoDFS arr[] , int & tiempo){

    arr[fuente].estado = 'V';
    arr[fuente].inicioVisita = tiempo++;
    list<int> ady = grafoN.adyacentes(fuente);
    list<int>::const_iterator itAdy;
    for(itAdy = ady.cbegin(); itAdy != ady.cend() ; itAdy++)
        if(arr[*itAdy].estado != 'V'){
            cout<<*itAdy<<endl;
            cout<<"La arista ( "<<fuente<<" , "<<*itAdy<<") es tree"<<endl;
            arr[*itAdy].predecesor = fuente;
            DFS_aristas(grafoN , *itAdy , arr , tiempo);
        }
        //Acá caen arcos (v,u) donde (u,v) ya se visito y los back. Acá se controlan los back
        else if( (arr[fuente].predecesor!= *itAdy) && (arr[fuente].inicioVisita > arr[*itAdy].inicioVisita) )
            cout<<"La arista ( "<<fuente<<" , "<<*itAdy<<") es back"<<endl;

    arr[fuente].finVisita = tiempo++;
}

void bosqueDFS_aristas (GrafoNDirigido grafoN , infoDFS arr[]){

    int tiempo = 1;
    for(int i = 0 ; i < grafoN.cantVertices() ; i++)
        if(arr[i].estado != 'V')
            DFS_aristas(grafoN,i,arr,tiempo);

}

void DFS_longitud (GrafoNDirigido grafoN , int fuente , int profundidad , char estado[] , int longitud[]){

    estado[fuente] = 'V';
    longitud[fuente] = profundidad++; //Se setea la longitud del vértice visitado al origen
    list<int> ady = grafoN.adyacentes(fuente);
    list<int>::const_iterator itAdy;
    for(itAdy = ady.cbegin(); itAdy != ady.cend() ; itAdy++)
        if(estado[*itAdy] != 'V')
            DFS_longitud(grafoN,*itAdy,profundidad,estado,longitud);
        else if(longitud[*itAdy] > profundidad) //Aca se pregunta por longitud+1 por si lo recorre
                longitud[*itAdy] = profundidad;
}

void DFS_postOrden (GrafoDirigido grafoD , int fuente, char estado[] , int * postOrden , int & num){

    estado[fuente] = 'V';
    list<GrafoDirigido::Nodo> ady = grafoD.adyacentes(fuente);
    list<GrafoDirigido::Nodo>::const_iterator itAdy;
    for (itAdy = ady.cbegin() ; itAdy != ady.cend() ; itAdy++)
        if ( estado[itAdy->vertice] != 'V')
            DFS_postOrden(grafoD , itAdy->vertice , estado, postOrden , num);
    postOrden[fuente] = num++;
}

void numeracionPostOrden (GrafoDirigido grafoD , int postOrden []){

    int N = grafoD.cantVertices();
    int num = 0;
    char estado[N];
    for(int i = 0; i < N ; i++) //Se marca a todos los vertices como "No visitados"
        estado[i] = 'n';
    for(int i = 0; i < N ; i++) //Se hace el control desde afuera del DFS para cada vértice si fue visitado.
        if(estado[i] != 'V')
            DFS_postOrden(grafoD,i,estado,postOrden,num);

}

void DFS_preOrdenGD (GrafoDirigido grafoD , int fuente, char estado[] , int * preOrden , int & num){

    estado[fuente] = 'V';
    preOrden[fuente] = num++;
    list<GrafoDirigido::Nodo> ady = grafoD.adyacentes(fuente);
    list<GrafoDirigido::Nodo>::const_iterator itAdy;
    for (itAdy = ady.cbegin() ; itAdy != ady.cend() ; itAdy++)
        if ( estado[itAdy->vertice] != 'V')
            DFS_preOrdenGD(grafoD , itAdy->vertice , estado, preOrden , num);

}

void numeracionPreOrdenGD (GrafoDirigido grafoD , int preOrden []){

    int N = grafoD.cantVertices();
    int num = 0;
    char estado[N];
    for(int i = 0; i < N ; i++) //Se marca a todos los vertices como "No visitados"
        estado[i] = 'n';
    for(int i = 0; i < N ; i++) //Se hace el control desde afuera del DFS para cada vértice si fue visitado.
        if(estado[i] != 'V')
            DFS_preOrdenGD(grafoD,i,estado,preOrden,num);
}


bool esAciclico (GrafoDirigido grafoD){
    int n = grafoD.cantVertices();
    int postOrden[n];
    numeracionPostOrden(grafoD,postOrden);
    for (int i = 0 ; i < n ; i++)
        for (int j = 0; j < n ; j++)
            if ( (grafoD.existeArco(i,j) ) && (postOrden[j] > postOrden[i]))
                return false;
    return true;
}

void sortTopologico(GrafoDirigido grafoD, int fuente , char estado[] , list<int> & l){
    estado[fuente] = 'V';
    list<GrafoDirigido::Nodo> ady = grafoD.adyacentes(fuente);
    list<GrafoDirigido::Nodo>::const_iterator itAdy;
    for (itAdy = ady.cbegin() ; itAdy != ady.cend() ; itAdy++)
        if (estado[itAdy->vertice] != 'V')
            sortTopologico(grafoD,itAdy->vertice , estado, l);
    l.push_front(fuente);
}

list<int> bosqueSortTopologico (GrafoDirigido grafoD) {

    list<int> l;
    int n = grafoD.cantVertices();
    char estado[n];

    for ( int i = 0 ; i < n ; i++)
        if(estado[i] != 'V')
            sortTopologico(grafoD,i,estado,l);
    return l;
}

int menorPreOrdenBack(GrafoNDirigido grafoN , int fuente ,  infoDFS estado [] ,  list<int> ady , int * preOrden){
    int menorActual = INT_MAX;
    list<int>::const_iterator itAdy;

    for (itAdy = ady.cbegin() ; itAdy != ady.cend() ; itAdy++){
        if(preOrden[*itAdy] < preOrden[fuente] &&
        (estado[fuente].predecesor!= *itAdy) &&
        (estado[fuente].inicioVisita > estado[*itAdy].inicioVisita)){

            if (preOrden[*itAdy] < menorActual)
                menorActual= preOrden[*itAdy];} }
    return menorActual;
}

int menorMasAltoTree(GrafoNDirigido grafoN , int fuente, list<int> ady , int * preOrden , int * masAlto) {
    int menorActual = INT_MAX;
    list<int>::const_iterator itAdy;
    for (itAdy = ady.cbegin() ; itAdy != ady.cend() ; itAdy++)
        if(preOrden[*itAdy] > preOrden[fuente])
            if (masAlto[*itAdy] < menorActual)
                menorActual= masAlto[*itAdy];
    return menorActual;
}

void DFS_preOrdenGND (GrafoNDirigido grafoN , int fuente, infoDFS estado [] , int * preOrden , int * masAlto, int & num , int & t){

    estado[fuente].estado = 'V';
    estado[fuente].inicioVisita = t++;
    preOrden[fuente] = num++;
    list<int> ady = grafoN.adyacentes(fuente);
    list<int>::const_iterator itAdy;
    for (itAdy = ady.cbegin() ; itAdy != ady.cend() ; itAdy++)
        if ( estado[*itAdy].estado != 'V'){
            estado[*itAdy].predecesor = fuente;
            DFS_preOrdenGND(grafoN , *itAdy, estado, preOrden , masAlto, num , t);

        }
    estado[fuente].finVisita = t++;
    cout<<"El padre del vertice "<< fuente <<" es: "<<estado[fuente].predecesor<<endl;
    int param1 = preOrden[fuente];
    int param2 = menorPreOrdenBack(grafoN, fuente ,estado, ady,preOrden); //Controla a los back
    int param3 = menorMasAltoTree(grafoN,fuente,ady,preOrden,masAlto);

    cout<<"Parametro 1: "<<param1<<" ; Parametro 2: "<<param2<<" ; Parametro 3: "<<param3<<endl;
    cout<<"........................................................"<<endl;
    masAlto[fuente] = min(param1, min (param2,param3) );

}

bool esPtoArticulacion (GrafoNDirigido grafoN , int masAlto[] , int preOrden[] , int vertice ){
    list<int> ady = grafoN.adyacentes( vertice);
    list<int>::const_iterator itAdy;
    for(itAdy = ady.cbegin() ; itAdy != ady.cend() ; itAdy++)
        if (masAlto[*itAdy] >= preOrden[vertice])
            return true;
    return false;
}

void puntosArticulacion(GrafoNDirigido grafoN , int fuente){
    int n = grafoN.cantVertices();
    int preOrden[n];
    int masAlto[n];
    infoDFS estado[n];
    int tiempo = 0;
    int num = 0;
    for(int i = 0; i < n ; i++){ //Se marca a todos los vertices como "No visitados"
        estado[i].estado = 'n';
        estado[i].predecesor = -1;
    }
    DFS_preOrdenGND(grafoN,0,estado,preOrden,masAlto,num,tiempo);
    for (int i = 0 ; i < n; i++)
        if (esPtoArticulacion(grafoN,masAlto,preOrden,i))
            cout<<"El vertice "<< i << "es un punto de articulacion"<<endl;
}

void DFS_CFC ( GrafoDirigido grafoD , int fuente , char estado[] , list<int> & verticesPostOrden , GrafoDirigido & grafoDR){

    estado[fuente] = 'V';
    list<GrafoDirigido::Nodo> ady = grafoD.adyacentes(fuente);
    list<GrafoDirigido::Nodo>::const_iterator itAdy;
    for(itAdy = ady.cbegin(); itAdy != ady.cend(); itAdy++){
        grafoDR.agregarArco(itAdy->vertice,fuente,0);
        if(estado[itAdy->vertice] != 'V')
            DFS_CFC(grafoD,itAdy->vertice,estado,verticesPostOrden,grafoDR);
    }

    verticesPostOrden.push_front(fuente);


}

bool estaEnLista ( list<int> verticesPostOrden , int vertice ){

    list<int>::const_iterator it;
    for(it=verticesPostOrden.cbegin(); it!=verticesPostOrden.cend(); it++)
        if(*it == vertice)
            return true;
    return false;

}

void sacarVertice ( list<int> & verticesPostOrden , int vertice){
    bool continuar = true;
    list<int>::const_iterator it = verticesPostOrden.cbegin();
    while (continuar)
        if(*it == vertice){
            verticesPostOrden.erase(it);
            continuar = false;
        }
        else
            it++;
}

void DFS_GR (GrafoDirigido grafoDR , int fuente , list<int> & verticesPostOrden , list<int> & componente){

    componente.push_back( fuente);
    sacarVertice(verticesPostOrden,fuente);
    list<GrafoDirigido::Nodo> ady = grafoDR.adyacentes(fuente);
    list<GrafoDirigido::Nodo>::const_iterator itAdy;
    for(itAdy = ady.cbegin(); itAdy != ady.cend(); itAdy++)
        if(estaEnLista(verticesPostOrden,itAdy->vertice))
            DFS_GR(grafoDR,itAdy->vertice,verticesPostOrden,componente);

}


list< list<int> > componentesFC (GrafoDirigido grafoD){
    list< list<int> > componentes;
    int n = grafoD.cantVertices();
    GrafoDirigido grafoReverso;
    char estado[n];
    for(int i = 0 ; i < n; i++){
        grafoReverso.agregarVertice();
        estado[i] = 'N';
    }
    list<int> verticesPostOrden;
    for(int i = 0; i < n; i++)
        if (estado[i] != 'V')
            DFS_CFC(grafoD,i,estado,verticesPostOrden,grafoReverso);
    list<int>::const_iterator it = verticesPostOrden.cbegin();
    while (!verticesPostOrden.empty()){
        cout<<verticesPostOrden.size()<<endl;
        list<int>::const_iterator first = verticesPostOrden.cbegin();
        if(estaEnLista(verticesPostOrden,*first)){
            list<int> componente;
            DFS_GR(grafoReverso,*first,verticesPostOrden,componente);
            componentes.push_back(componente);
        }
    }
    return componentes;

}

void DFS_CC ( GrafoNDirigido grafoN , int fuente , list<int> & componente , char estado[]){

    estado[fuente] = 'V';
    componente.push_back(fuente);
    list<int> ady = grafoN.adyacentes(fuente);
    list<int>::const_iterator itAdy;
    for(itAdy = ady.cbegin() ; itAdy != ady.cend() ; itAdy++)
        if(estado[*itAdy] != 'V')
            DFS_CC(grafoN,*itAdy,componente,estado);
}

list< list<int> > componentesConexas (GrafoNDirigido grafoN){

    int n = grafoN.cantVertices();
    list< list <int> > componentes;
    char estado[n];
    for (int i = 0; i < n ; i++)
        estado[i] = 'N';

    for (int i = 0; i < n ; i++)
        if(estado[i] != 'V'){
            list<int> componente;
            DFS_CC(grafoN,i,componente,estado);
            componentes.push_back(componente);
        }

    return componentes;

}












