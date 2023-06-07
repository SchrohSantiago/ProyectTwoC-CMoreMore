#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int FILA = 3;      // Asigno de manera global Fila y Columna
const int COLUMNA = 3; 

// PROTOTIPOS, Son utilizados para no tener que colocar el int main debajo del todo
void Menu();
void cargarMatriz(int tMatriz[FILA][COLUMNA]);
void mostrarMatriz(int tMatriz[FILA][COLUMNA]);
bool buscarValor(int tMatriz[FILA][COLUMNA], int valor);
void encontrarMaxMin(int tMatriz[FILA][COLUMNA]);
void ordenarMatriz(int tMatriz[FILA][COLUMNA]);
int calcularDeterminante(int tMatriz[FILA][COLUMNA]);

int main()
{
    int tMatriz[FILA][COLUMNA] = {};    
    bool matrizCargada = false;
    int seleccionUsuario;


    while(seleccionUsuario != 7) { // Si la opcion elegida por el usuario es 10 finaliza sale del While y finaliza el programa
        Menu();
       
        
        cout << "Ingrese una opcion: " << endl;
        cin >> seleccionUsuario;

        switch (seleccionUsuario) {
            case 1:
                cargarMatriz(tMatriz);
                matrizCargada = true;
                break;
            case 2:
                if (matrizCargada) {        // Condicional para comprobar si esta cargada la matriz
                    mostrarMatriz(tMatriz);
                } else {
                    cout << "Primero cargue la Matriz" << endl;
                }
                break;
            case 3:
                if (matrizCargada) {
                    int valor;
                    cout << "Ingrese el valor a buscar: ";
                    cin >> valor;
                    if (buscarValor(tMatriz, valor)) {
                        cout << "El valor se encuentra en la matriz." << endl;
                    } else {
                        cout << "El valor no se encuentra en la matriz" << endl;
                    }
                } else {
                    cout << "Primero cargue la Matriz" << endl;
                }
                break;
            case 4:
                if (matrizCargada) {
                    encontrarMaxMin(tMatriz);
                } else {
                    cout << "Primero cargue la Matriz" << endl;
                }
                break;
            case 5:
                if (matrizCargada) {
                    ordenarMatriz(tMatriz);
                } else {
                    cout << "Primero cargue la Matriz" << endl;
                }
                break;
            case 6:
                if (matrizCargada) {
                    int determinante = calcularDeterminante(tMatriz);
                    cout << "El determinante de la matriz es: " << determinante << endl;
                } else {
                    cout << "Primero cargue la Matriz" << endl;
                }
                break;
            case 7:
                cout << "Finalizando programa..." << endl;
                break;
            default:
                cout << "Error!, presione una opcion valida" << endl;
                break;
        }

        cout << endl;

    }

    return 0;
}

void Menu()
{
    cout << "1 = Cargar la matriz" << endl;
    cout << "2 = Mostrar matriz" << endl;
    cout << "3 = Buscar un valor especifico en la matriz" << endl;
    cout << "4 = Ver valor MAXIMO o MINIMO de la Matriz" << endl;
    cout << "5 = Ordenar los valores de la matriz de forma ascendente o descendente" << endl;
    cout << "6 = Calcular el determinante" << endl;
    cout << "7 = Salir" << endl;
}



void cargarMatriz(int tMatriz[FILA][COLUMNA])
{
    int eleccionArmadoUsuario;
    cout << "Ingrese 1 si quiere cargar la Matriz Manualmente. Sino introduzca cualquier otro numero" << endl;
    cin >> eleccionArmadoUsuario;

    if(eleccionArmadoUsuario == 1){
    cout << "Ingrese 9 valores para rellenar la matriz:";
  
    for (int i = 0; i < FILA; i++) {
        for (int j = 0; j < COLUMNA; j++) {
            cin >> tMatriz[i][j];  //El usuario ira metiendo los valores 1 por 1
        }
    }

    cout << "Su matriz fue cargada manulamente de forma correcta" << endl;
    } else {

     srand(time(0)); // Genero la semilla para los numeros randoms.

     for (int i = 0; i < FILA; i++) {
        for (int j = 0; j < COLUMNA; j++) {
            tMatriz[i][j] = rand() % 100 + 1;  // Establecemos valores randoms del 1 al 100
        }
    }
    cout << "Su matriz fue cargada aleatoriamente de forma correcta" << endl;
    }
}

void mostrarMatriz(int tMatriz[FILA][COLUMNA])   //Mostramos la matriz creada
{
      cout << "Matriz Actual" << "\n";
    for (int i = 0; i < FILA; i++) {
        for (int j = 0; j < COLUMNA; j++) {
            cout << tMatriz[i][j] << " ";
        }
        cout << endl;
    }
}

bool buscarValor(int tMatriz[FILA][COLUMNA], int valor) // Funcion para buscar el valor que quiera el usuario
{
    for (int i = 0; i < FILA; i++) {
        for (int j = 0; j < COLUMNA; j++) {
            if (tMatriz[i][j] == valor) {
                return true;
            }
        }
    }
    return false;
}

void encontrarMaxMin(int tMatriz[FILA][COLUMNA])    // Encontar Maximo o Minimo segun el usuario quiera
{
    int valorMayoroMenorUser;

    cout << "Ingrese 1 si desea encontra el valor MAXIMO de la matriz. Si desea el valor MINIMO introduca cualquier otro numero" << endl;
    cin >> valorMayoroMenorUser;

if(valorMayoroMenorUser == 1){
    int maximo = tMatriz[0][0];
    for (int i = 0; i < FILA; i++) {
        for (int j = 0; j < COLUMNA; j++) {
            if (tMatriz[i][j] > maximo) {
                maximo = tMatriz[i][j];
            }
        }
    }
    cout << "El valor maximo es: " << maximo;
    } else {
        int minimo = tMatriz[0][0];
             for (int i = 0; i < FILA; i++) {
                 for (int j = 0; j < COLUMNA; j++) {
                     if (tMatriz[i][j] < minimo) {
                      minimo = tMatriz[i][j];
                   }
              }

          }
            cout << "El valor minimo es: " << minimo;
         } 
}
    


void ordenarMatriz(int tMatriz[FILA][COLUMNA])   //Ordenar la Matriz en orden descendente o ascendente
{
    int seleccionarOrden;
    int temp;

    cout << "Si desea ordenar la matriz de forma ascendente ingrese '1'. Si la quiere de forma descendente ingrese cualquier otro valor" << endl;
    cin >> seleccionarOrden;

    if(seleccionarOrden == 1) {
    for (int i = 0; i < FILA; i++) {
        for (int j = 0; j < COLUMNA; j++) {
            for (int k = 0; k < FILA; k++) {
                for (int l = 0; l < COLUMNA; l++) {
                    if (tMatriz[i][j] < tMatriz[k][l]) {
                        temp = tMatriz[i][j];
                        tMatriz[i][j] = tMatriz[k][l];
                        tMatriz[k][l] = temp;
                    }
                }
            }
        }
    }
      cout << "Su matriz fue ordenada de forma ascendente" << endl;
    } 
    else 
    {
     for (int i = 0; i < FILA; i++) {
        for (int j = 0; j < COLUMNA; j++) {
            for (int k = 0; k < FILA; k++) {
                for (int l = 0; l < COLUMNA; l++) {
                    if (tMatriz[i][j] > tMatriz[k][l]) {
                        temp = tMatriz[i][j];
                        tMatriz[i][j] = tMatriz[k][l];
                        tMatriz[k][l] = temp;
                    }
                }
            }
        }
     }
       cout << "Su matriz fue ordenada de forma descendente" << endl;
    }
}


int calcularDeterminante(int tMatriz[FILA][COLUMNA])   // Para sacar el determinanate de una matriz debemos multiplicar las diagonales desde la primera fila hasta la 3RA fila, sumar las 3 multiplicaciones de izquierda a derecha y despues hacerlo de manera inversa tambien con las diagonales. con los dos resultados separados que nos quedan los restamos y obtenemos el determinante de la matriz
{
    int determinante = 0;
    determinante = ((tMatriz[0][0] * tMatriz[1][1] * tMatriz[2][2]) + (tMatriz[1][0] * tMatriz[2][1] *tMatriz[0][2]) + (tMatriz[2][0] * tMatriz[0][1] * tMatriz[1][2])) /*Bien*/ - ((tMatriz[0][2]*tMatriz[1][1]*tMatriz[2][0]) +(tMatriz[1][2] * tMatriz[2][1] * tMatriz[0][0]) + (tMatriz[2][2]*tMatriz[0][1]*tMatriz[1][0])); //[0][0] seria la matriz A11, [1][1] seria la matriz A22 y [2][2] es la posicion de la matriz A33, La formula para calcular determinantes que usamos en matematicas la plasme en el codigo.
    return determinante;
}







