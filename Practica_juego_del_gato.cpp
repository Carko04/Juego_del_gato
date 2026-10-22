
#include <iostream>
#include <limits>
using namespace std;

void iniciarTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void mostrarTablero(char tablero[3][3]) {
    cout << "\n    1   2   3\n";

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "   ";

        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j];

            if (j < 2) {
                cout << " | ";
            }
        }

        cout << endl;

        if (i < 2) {
            cout << "   ---+---+---\n";
        }
    }
    cout << endl;
}

void pedirJugada(char tablero[3][3], char jugador) {
    int fila, columna;
    bool valida = false;

    while (!valida) {
        cout << "Turno del jugador " << jugador << endl;
        cout << "Ingresa la fila (1-3): ";

        if (!(cin >> fila)) {
            cout << "Error: ingresa un numero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Ingresa la columna (1-3): ";

        if (!(cin >> columna)) {
            cout << "Error: ingresa un numero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        fila--;
        columna--;

        if (fila < 0 || fila >= 3 ||
            columna < 0 || columna >= 3) {
            cout << "Posicion fuera del tablero.\n";
        }
        else if (tablero[fila][columna] != ' ') {
            cout << "La casilla ya esta ocupada.\n";
        }
        else {
            tablero[fila][columna] = jugador;
            valida = true;
        }
    }
}

bool verificarGanador(char tablero[3][3], char jugador) {

    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador &&
            tablero[i][1] == jugador &&
            tablero[i][2] == jugador) {
            return true;
        }

        if (tablero[0][i] == jugador &&
            tablero[1][i] == jugador &&
            tablero[2][i] == jugador) {
            return true;
        }
    }

    if (tablero[0][0] == jugador &&
        tablero[1][1] == jugador &&
        tablero[2][2] == jugador) {
        return true;
    }

    if (tablero[0][2] == jugador &&
        tablero[1][1] == jugador &&
        tablero[2][0] == jugador) {
        return true;
    }

    return false;
}

bool verificarEmpate(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

int main() {
    char tablero[3][3];
    char jugador = 'X';
    bool jugando = true;

    iniciarTablero(tablero);

    cout << "=== JUEGO DEL GATO ===\n";
    cout << "Jugador 1: X\n";
    cout << "Jugador 2: O\n";

    while (jugando) {
        mostrarTablero(tablero);
        pedirJugada(tablero, jugador);

        if (verificarGanador(tablero, jugador)) {
            mostrarTablero(tablero);
            cout << "El jugador " << jugador
                 << " ha ganado!\n";
            jugando = false;
        }
        else if (verificarEmpate(tablero)) {
            mostrarTablero(tablero);
            cout << "La partida termino en empate.\n";
            jugando = false;
        }
        else {
            if (jugador == 'X') {
                jugador = 'O';
            }
            else {
                jugador = 'X';
            }
        }
    }

    cout << "Fin del juego.\n";

    return 0;
}
