// Zadanie TEMPERATURY
// Filip Stankiewicz 170396 Bioinformatyka

#include <iostream>
#include <stdlib.h>
using namespace std;
void pytanie();
float FtoC(float temp0);
float FtoK(float temp0);
float CtoF(float temp0);
float CtoK(float temp0);
float KtoC(float temp0);
float KtoF(float temp0);
float pobierzF();
float pobierzC();
float pobierzK();
float check(float temp0, char stopnie);

void pytanie() {
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

float check(float temp0, char stopnie) {
	if ((temp0 < 0 && stopnie == 'K') || (temp0 < -273.15 && stopnie == 'C') || (temp0 < -459.67 && stopnie == 'F')) {
		cout << "Nie ma takiej temperatury. ";
		return -999.0;
	}
	return temp0;
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
	float temp0;
	char stopnie;

	do {
		pytanie();
		cout << "Wybierz opcje: ";
		cin >> wybor;

		switch (wybor) {
			case 1:
				stopnie = 'F';
				temp0 = pobierzF();
				temp0 = check(temp0, stopnie);
				if (temp0 != -999.0)
				cout << endl << temp0 << " stopni Fahrenheita w przeliczeniu na stopnie Celsjusza to: " << FtoC(temp0);
				break;
			case 2:
				stopnie = 'F';
				temp0 = pobierzF();
				temp0 = check(temp0, stopnie);
				if (temp0 != -999.0)
				cout << endl << temp0 << " stopni Fahrenheita w przeliczeniu na stopnie Kelwina to: " << FtoK(temp0);
				break;
			case 3:
				stopnie = 'C';
				temp0 = pobierzC();
				temp0 = check(temp0, stopnie);
				if (temp0 != -999.0)
				cout << endl << temp0 << " stopni Celsjusza w przeliczeniu na stopnie Fahrenheita to: " << CtoF(temp0);
				break;
			case 4:
				stopnie = 'C';
				temp0 = pobierzC();
				temp0 = check(temp0, stopnie);
				if (temp0 != -999.0)
				cout << endl << temp0 << " stopni Celsjusza w przeliczeniu na stopnie Kelwina to: " << CtoK(temp0);
				break;
			case 5:
				stopnie = 'K';
				temp0 = pobierzK();
				temp0 = check(temp0, stopnie);
				if (temp0 != -999.0)
				cout << endl << temp0 << " stopni Kelwina w przeliczeniu na stopnie Celsjusza to: " << KtoC(temp0);
				break;
			case 6:
				stopnie = 'K';
				temp0 = pobierzK();
				temp0 = check(temp0, stopnie);
				if (temp0 != -999.0)
				cout << endl << temp0 << " stopni Kelwina w przeliczeniu na stopnie Fahrenheita to: " << KtoF(temp0);
				break;
			case 7:
				cout << endl << "Koncze dzialanie programu." << endl;
				return 0;
			default:
				cout << endl << "Wybrano zla opcje. Koncze dzialanie programu." << endl;
				return 0;
		}
		cout << endl << endl << "Wcisnij Enter aby kontynuowac. ";
		cin.ignore(); 
		cin.get();
		system("cls");
	} while (wybor >= 1 && wybor <= 6);
}