// Zadanie TEMPERATURY
// Filip Stankiewicz 170396 Bioinformatyka

#include <iostream>
#include <stdlib.h>
#include "headerFile.h"
using namespace std;

int dataCounter = 0;

void pytanie() {
	cout << "0 - pokaz historie" << endl;
	cout << "1 - przelicz Fahr -> Celsjusz" << endl;
	cout << "2 - przelicz Fahr -> Kelwin" << endl;
	cout << "3 - przelicz Celsjusz -> Fahr" << endl;
	cout << "4 - przelicz Celsjusz -> Kelwin" << endl;
	cout << "5 - przelicz Kelwin -> Celsjusz" << endl;
	cout << "6 - przelicz Kelwin -> Fahr" << endl;
	cout << "7 - zakoncz dzialanie programu" << endl << endl;
}

float pobierzF() {
	float f;
	cout << endl << "Podaj temperature w stopniach Fahrenheita: ";
	cin >> f;
	return f;
}
float pobierzC() {
	float c;
	cout << endl << "Podaj temperature w stopniach Celsjusza: ";
	cin >> c;
	return c;
}
float pobierzK() {
	float k;
	cout << endl << "Podaj temperature w stopniach Kelwina: ";
	cin >> k;
	return k;
}

float check(float temp0, char stopnie0) {
	if ((temp0 < 0 && stopnie0 == 'K') || (temp0 < -273.15 && stopnie0 == 'C') || (temp0 < -459.67 && stopnie0 == 'F')) {
		cout << "Nie ma takiej temperatury. ";
		return -999.0;
	}
	return temp0;
}



void historia(double mem[100], char sym [100]) {
	for (int i = 0; i < dataCounter/2; i++) {
		int indeks = i * 2;
		cout << endl << "<" << i+1 << "> " << mem[indeks] << sym[indeks] << " = " << mem[indeks+1] << sym[indeks+1];;
	}
}

float FtoC(float temp0) {
	float wynik;
	wynik = (temp0 - 32.0) * 5.0 / 9.0;
	return wynik;
}
float FtoK(float temp0) {
	float wynik;
	wynik = (temp0 + 459.67) * 5.0 / 9.0;
	return wynik;
}
float CtoF(float temp0) {
	float wynik;
	wynik = temp0 * 9.0 / 5.0 + 32.0;
	return wynik;
}
float CtoK(float temp0) {
	float wynik;
	wynik = temp0 + 273.15;
	return wynik;
}
float KtoC(float temp0) {
	float wynik;
	wynik = temp0 - 273.15;
	return wynik;
}
float KtoF(float temp0) {
	float wynik;
	wynik = temp0 * 9.0 / 5.0 - 459.67;
	return wynik;
}


int main(){
	int wybor;
	float temp0, temp;
	char stopnie0, stopnie;
	double mem[100] = {0};
	char sym[100] = {0};

	do {
		pytanie();
		cout << "Wybierz opcje: ";
		cin >> wybor;

		switch (wybor) {
			case 0:
				historia(mem, sym);
				cout << endl << endl << "Wcisnij Enter aby kontynuowac. ";
				cin.ignore();
				cin.get();
				system("cls");
				continue;
			case 1:
				stopnie0 = 'F';
				stopnie = 'C';
				temp0 = pobierzF();
				temp0 = check(temp0, stopnie0);
				if (temp0 != -999.0) {
					temp = FtoC(temp0);
					cout << endl << temp0 << " stopni Fahrenheita w przeliczeniu na stopnie Celsjusza to: " << temp;
				}
				break;
			case 2:
				stopnie0 = 'F';
				stopnie = 'K';
				temp0 = pobierzF();
				temp0 = check(temp0, stopnie0);
				if (temp0 != -999.0) {
					temp = FtoK(temp0);
					cout << endl << temp0 << " stopni Fahrenheita w przeliczeniu na stopnie Kelwina to: " << temp;
				}
				break;
			case 3:
				stopnie0 = 'C';
				stopnie = 'F';
				temp0 = pobierzC();
				temp0 = check(temp0, stopnie0);
				if (temp0 != -999.0) {
					temp = CtoF(temp0);
					cout << endl << temp0 << " stopni Celsjusza w przeliczeniu na stopnie Fahrenheita to: " << temp;
				}
				break;
			case 4:
				stopnie0 = 'C';
				stopnie = 'K';
				temp0 = pobierzC();
				temp0 = check(temp0, stopnie0);
				if (temp0 != -999.0) {
					temp = CtoK(temp0);
					cout << endl << temp0 << " stopni Celsjusza w przeliczeniu na stopnie Kelwina to: " << temp;
				}
				break;
			case 5:
				stopnie0 = 'K';
				stopnie = 'C';
				temp0 = pobierzK();
				temp0 = check(temp0, stopnie0);
				if (temp0 != -999.0) {
					temp = KtoC(temp0);
					cout << endl << temp0 << " stopni Kelwina w przeliczeniu na stopnie Celsjusza to: " << temp;
				}
				break;
			case 6:
				stopnie0 = 'K';
				stopnie = 'F';
				temp0 = pobierzK();
				temp0 = check(temp0, stopnie0);
				if (temp0 != -999.0) {
					temp = KtoF(temp0);
					cout << endl << temp0 << " stopni Kelwina w przeliczeniu na stopnie Fahrenheita to: " << temp;
				}
				break;
			case 7:
				cout << endl << "Koncze dzialanie programu." << endl;
				return 0;
			default:
				cout << endl << "Wybrano zla opcje. Koncze dzialanie programu." << endl;
				return 0;
		}
		if (temp0 != -999.0) {
			if (dataCounter + 1 < 100) {
				mem[dataCounter] = temp0;
				sym[dataCounter] = stopnie0;
				dataCounter++;
				mem[dataCounter] = temp;
				sym[dataCounter] = stopnie;
				dataCounter++;
			}
			else {
				cout << endl << "Pamiec pelna, nie mozna dodac wiecej danych.";
			}
		}
		cout << endl << endl << "Wcisnij Enter aby kontynuowac. ";
		cin.ignore(); 
		cin.get();
		system("cls");
	} while (wybor >= 0 && wybor <= 6);
}
