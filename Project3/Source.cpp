/* 
 * File:   main.cpp
 * Author: Dennis Klint
 *
 * Created on den 21 februari 2013, 08:15
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

/*
 * 
 */

int pengar();
int satsning(int &tsumma);
int spela(int &satsning, int &tsumma);
int Loop(int &tsumma, int &psatsning);


int main(int argc, char** argv) {

    int tsumma = pengar();
    int psatsning = satsning(tsumma);
    tsumma = spela(psatsning, tsumma);
	tsumma = Loop(tsumma, psatsning);
    /*Denna while loop l�ter anv�ndaren g�ra nya ins�ttningar, satsningar, och
     spela igen om de s� skulle vilja.*/
    
    return 0;
}
    


int pengar() {
    int summa = 0;
    int tsumma = 0;
    cout << "Var v�nlig och skriv in en summa pengar du vill s�tta in p� dit "
            "konto, vi f�resl�r att du skriver in en summa delbar med 50."
            << endl;

    cin >> summa;
    while (summa < 50) {
        cout << "Du har antingen skrivit in en f�r l�g summa eller en summa "
                "som inte �r delbar med 50. Skriv in en ny summa." << endl;
        cin >> summa;
    }
    tsumma = summa + tsumma;
    cout << "Du har nu laggt in " << tsumma << " kr p� kontot." << endl;
    return tsumma;
}

int satsning(int &tsumma) {
    int psatsning = 0;
    while (tsumma < 50) {
        cout << "Du har f�r lite pengar p� kontot." << endl;
        tsumma = pengar();
    }
    cout << "Skriv in en summa du vill satsa. Summan m�ste antingen vara 50,"
            " 100 eller 500 kronor." << endl;
    cin >> psatsning;

    while ((psatsning != 50 && psatsning != 100
            && psatsning != 500) || tsumma < psatsning) {
        cout << "Du har antingen skrivit in en oacceptabel summa eller s� har "
                "du f�r lite pengar p� kontot f�r just den satsningen." << endl;
        cin >> psatsning;
    }
    cout << endl << "Du har nu satsat " << psatsning << " kronor." << endl;

    return psatsning;
}

int spela(int &satsning, int &tsumma) {
    srand(time(0));
    int vinst = 0;
    int counter = 0;
    int rutor[3][3];
    /*H�r genereras slumptal f�r alla v�rden i variabeln rutor.*/
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            rutor[x][y] = rand() % 3 + 1;
        }
    }
    /*H�r skrivs v�rdena fr�n rutor i ett l�tt l�st s�tt f�r anv�ndaren*/
    cout << "[" << rutor[0][0] << "] [" << rutor[0][1] << "] [" << rutor[0][2]
            << "]" << endl << "[" << rutor[1][0] << "] [" << rutor[1][1]
            << "] [" << rutor[1][2] << "]" << endl << "[" << rutor[2][0]
            << "] [" << rutor[2][1] << "] [" << rutor[2][2] << "]";
    /*H�r �r massor med if satser kollar ifall anv�nderen f�tt n�gon rad med 
     samma v�rde.*/
    if (rutor[0][0] == rutor[0][1] && rutor[0][1] == rutor[0][2]) {
        counter++;
    }
    if (rutor[1][0] == rutor[1][1] && rutor[1][1] == rutor[1][2]) {
        counter++;
    }
    if (rutor[2][0] == rutor[2][1] && rutor[2][1] == rutor[2][2]) {
        counter++;
    }
    if (rutor[0][0] == rutor[1][0] && rutor[1][0] == rutor[2][0]) {
        counter++;
    }
    if (rutor[0][1] == rutor[1][1] && rutor[1][1] == rutor[2][1]) {
        counter++;
    }
    if (rutor[0][2] == rutor[1][2] && rutor[1][2] == rutor[2][2]) {
        counter++;
    }
    if (rutor[0][0] == rutor[1][1] && rutor[1][1] == rutor[2][2]) {
        counter++;
    }
    if (rutor[2][0] == rutor[1][1] && rutor[1][1] == rutor[0][2]) {
        counter++;
    }

    /*H�r f�r/f�rlorar anv�nderen pengar beroende p� hur m�nga rader de fick och
     vad de satsade f�r summa.*/
    if (counter == 1) {
        vinst = satsning;
    } else if (counter == 2) {
        vinst = satsning * 3;
    } else if (counter == 3) {
        vinst = satsning * 7;
    } else if (counter == 4) {
        vinst = satsning * 16;
    } else if (counter == 8) {
        vinst = satsning * 127;
    } else {
        vinst = satsning - (satsning * 2);
    }

    cout << endl << "Denna match gick du +/- " << vinst << " kr. Du fick totalt "
            << counter << " rad(er) med samma tecken." << endl;
    tsumma = vinst + tsumma;

    return tsumma;
}

int Loop(int &tsumma, int &psatsning){
	char loop;
    int cantstopthis = 1;

	while (cantstopthis = 1) {
        if (tsumma <= 0) {
            cout << "Du har inga pengar kvar!" << endl << "Om du vill spela igen s� "
                    "f�r du starta om programmet.";
            return 0;
        }
        cout << endl << "Du har nu " << tsumma << " kr p� kontot."
                << endl << "Om du vill g�ra en ny ins�tning av pengar, skriv in 1."
                << endl << "Om du vill g�ra en ny satsning, skriv in 2." << endl
                << "Om du vill spela igen, skriv in 3." << endl
                << "Om du vill avsluta spelet skriv in n�got annat �n 1-3"
                << endl;
        cin >> loop;

        if (loop == '1') {
            tsumma = pengar();
        } else if (loop == '2') {
            psatsning = satsning(tsumma);
        } else if (loop == '3') {
            tsumma = spela(psatsning, tsumma);
        } else {
            return 0;
		}
	}