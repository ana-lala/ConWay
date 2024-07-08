#include "FuncionesAuxiliares.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::setw;

//*************************************************
int CapturarEntero(const char solicitud[])
{
    int x;
    cout << solicitud;
    cin >> x;
    while(cin.fail() || x != (int)x){
        cout << "Error: valor no v\240lido";
        if(cin.fail()){
            cout << ", se espera un n\243mero" << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(),'\n');
        }else{
            cout << ", se espera un n\243mero entero" << endl;
        }
        cout << solicitud;
        cin >> x;
    }
    return x;
}
//*************************************************
//**********************************************************************************
void Imprimir(tipo **arreglo, int m, int n)
{
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
                if(arreglo[i][j]){
                    cout << setw(4) << char(15);
                }
                else {
                        cout << setw(4) << " ";}
            }
            cout << endl;
        }
}
//********************************************************************************
void GeneracionNueva(tipo **&matrizVivos, tipo **&matrizVecinos, int m , int n)
{
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(matrizVivos[i][j] == 0){
                if(matrizVecinos[i][j] == 3){
                    matrizVivos[i][j] = 1;
                }
            } else{
                if(matrizVecinos[i][j] !=3 && matrizVecinos[i][j] !=2){
                    matrizVivos[i][j] = 0;
                }
            }
        }
    }

}

//**********************************************************************************
void PonerVecinos( tipo **&arreglo, tipo **&Vecinos, int m, int n)
{
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                Vecinos[i][j] = 0;
            }
        }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(arreglo[i - 1][j] == 1) Vecinos[i][j] +=1;
            if(arreglo[i + 1][j] == 1) Vecinos[i][j] +=1;
            if(arreglo[i][j - 1] == 1) Vecinos[i][j] +=1;
            if(arreglo[i][j + 1] == 1) Vecinos[i][j] +=1;

            if(arreglo[i - 1][j - 1] == 1) Vecinos[i][j] +=1;
            if(arreglo[i + 1][j + 1] == 1) Vecinos[i][j] +=1;
            if(arreglo[i - 1][j + 1] == 1) Vecinos[i][j] +=1;
            if(arreglo[i + 1][j - 1] == 1) Vecinos[i][j] +=1;
        }
    }

}
//**********************************************************************************
tipo **Crear(int m, int n)
{
    tipo **arreglo = new tipo *[m];
    arreglo[0] = new tipo[m * n];
    for (int i = 1; i < m; ++i)
        arreglo[i] = arreglo[0] + i * n;

    return arreglo;
}

//*************************************************
void Destruir(tipo **&arreglo)
{
    delete[] arreglo[0];
    delete[] arreglo;
    arreglo = NULL;
}
//*************************************************************************
void **BichosVivosMuertos(tipo **&matrizVivos, int m , int n)
{
    srand(time(NULL));
    for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                    matrizVivos[i][j] = rand() % 2;
                }
    }
}
