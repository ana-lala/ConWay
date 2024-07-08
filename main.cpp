#include <iostream>
#include "EstablecerConsola.hpp"
#include "FuncionesAuxiliares.hpp"


#define ENTER 13
#define ESCAPE 27

using namespace std;

int main()
{

    char tecla;
    int m, n;
    cout << "Capturando las dimensiones del tablero... \n\n";
    cout << "MAX (" << MAXREN << ") ";
    do {
        m = CapturarEntero("Filas: ");
        if (m > MAXREN) {
            cout << "El n\243mero NO puede ser mayor a " << MAXREN << ". ";
        }
    } while (m < 1 || m > MAXREN);
    cout << endl;
    cout << "MAX (" << MAXCOL << ") ";
    do {
        n = CapturarEntero("Columnas: ");
        if (n > MAXCOL) {
            cout << "El n\243mero NO puede ser mayor a " << MAXCOL << ". ";
        }
    } while (n < 1 || n > MAXCOL);
    CambiarCursor(APAGADO, NORMAL);

    system("cls");

    cout << "Pulsa ENTER para empezar: ";

    try {
        tipo **Actual = Crear(m+2, n+2);
        tipo **Siguiente = Crear(m+2, n+2);

        BichosVivosMuertos(Actual, m , n);

        while(true){
            if(kbhit()){
                tecla = getch();
                if(tecla == ESCAPE) break;
                if(tecla == ENTER){
                    MoverCursor(2,4);
                    cout << endl << endl;
                    Imprimir(Actual, m, n);

                    PonerVecinos(Actual, Siguiente, m, n);
                    //Ahora la Siguiente tiene el numero de vecinos
                    cout << endl << endl;
                    GeneracionNueva(Actual, Siguiente, m, n);
                    //Ahora la actual tiene el numero de bichos vivos

                }
            }
        }
        Destruir(Actual);
        Destruir(Siguiente);
    } catch (const bad_alloc &) {
        cout << "Error en la asignaci\242n de memoria" << endl;
    } catch (const char *msn) {
        cerr << "Error: " << msn << endl;
    } catch (...) {
        cout << "Ocurri\242 un error inesperado" << endl;
    }
    CambiarCursor(ENCENDIDO, NORMAL);

    system("pause");
    return 0;
}
