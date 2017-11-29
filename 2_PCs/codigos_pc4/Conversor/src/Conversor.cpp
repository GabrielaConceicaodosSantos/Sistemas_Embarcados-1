//============================================================================
// Name        : Conversor.cpp
// Author      : Josy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int conversor(char caractere) {

	if (caractere == 'a'){
		return 0x16;
	}
	else if (caractere == 'b'){
		return 0x26;
	}
	else if (caractere == 'c'){
		return 0x36;
	}
	else if (caractere == 'd'){
			return 0x46;
		}
	else if (caractere == 'e'){
			return 0x56;
		}
	else if (caractere == 'f'){
			return 0x66;
		}
	else if (caractere == 'g'){
			return 0x76;
		}
	else if (caractere == 'h'){
			return 0x86;
		}
	else if (caractere == 'i'){
			return 0x96;
		}
	else if (caractere == 'j'){
			return 0xA6;
		}
	else if (caractere == 'k'){
			return 0xB6;
		}
	else if (caractere == 'l'){
			return 0xC6;
		}
	else if (caractere == 'm'){
			return 0xD6;
		}
	else if (caractere == 'n'){
			return 0xE6;
		}
	else if (caractere == 'o'){
			return 0xF6;
		}
	else if (caractere == 'p'){
			return 0x07;
		}
	else if (caractere == 'q'){
			return 0x17;
		}
	else if (caractere == 'r'){
			return 0x27;
		}
	else if (caractere == 's'){
			return 0x37;
		}
	else if (caractere == 't'){
			return 0x47;
		}
	else if (caractere == 'u'){
			return 0x57;
		}
	else if (caractere == 'v'){
			return 0x67;
		}
	else if (caractere == 'w'){
			return 0x77;
		}
	else if (caractere == 'x'){
			return 0x87;
		}
	else if (caractere == 'y'){
			return 0x97;
		}
	else if (caractere == 'z'){
			return 0xA7;
		}
	else if (caractere == 'A'){
			return 0x14;
		}
	else if (caractere == 'B'){
			return 0x24;
		}
	else if (caractere == 'C'){
			return 0x34;
		}
	else if (caractere == 'D'){
			return 0x44;
		}
	else if (caractere == 'E'){
			return 0x54;
		}
	else if (caractere == 'F'){
			return 0x64;
		}
	else if (caractere == 'G'){
			return 0x74;
		}
	else if (caractere == 'H'){
			return 0x84;
		}
	else if (caractere == 'I'){
			return 0x94;
		}
	else if (caractere == 'J'){
			return 0xA4;
		}
	else if (caractere == 'K'){
			return 0xB4;
		}
	else if (caractere == 'L'){
			return 0xC4;
		}
	else if (caractere == 'M'){
			return 0xD4;
		}
	else if (caractere == 'N'){
			return 0xE4;
		}
	else if (caractere == 'O'){
			return 0xF4;
		}
	else if (caractere == 'P'){
			return 0x05;
		}
	else if (caractere == 'Q'){
			return 0x15;
		}
	else if (caractere == 'R'){
			return 0x25;
		}
	else if (caractere == 'S'){
			return 0x35;
		}
	else if (caractere == 'T'){
			return 0x45;
		}
	else if (caractere == 'U'){
			return 0x55;
		}
	else if (caractere == 'V'){
			return 0x65;
		}
	else if (caractere == 'W'){
			return 0x75;
		}
	else if (caractere == 'X'){
			return 0x85;
		}
	else if (caractere == 'Y'){
			return 0x95;
		}
	else if (caractere == 'Z'){
			return 0xA5;
		}
	else if (caractere == '0'){
			return 0x03;
		}
	else if (caractere == '1'){
			return 0x13;
		}
	else if (caractere == '2'){
			return 0x23;
		}
	else if (caractere == '3'){
			return 0x33;
		}
	else if (caractere == '4'){
			return 0x43;
		}
	else if (caractere == '5'){
			return 0x53;
		}
	else if (caractere == '6'){
			return 0x63;
		}
	else if (caractere == '7'){
			return 0x73;
		}
	else if (caractere == '8'){
			return 0x83;
		}
	else if (caractere == '9'){
			return 0x93;
		}
	else if (caractere == ':'){
			return 0xA3;
		}
	else if (caractere == ' '){
			return 0x02;
		}
	else if (caractere == '*'){
			return 0xA2;
		}
	else if (caractere == '#'){
			return 0x32;
		}
	else if (caractere == ','){
			return 0xC2;
		}
	else if (caractere == '.'){
			return 0xE2;
		}
	else if (caractere == '>'){
			return 0xE3;
		}
	else if (caractere == '<'){
			return 0xC3;
		}
	else if (caractere == '-'){
			return 0xD2;
		}
	else if (caractere == '!'){
			return 0x12;
		}
	else if (caractere == '?'){
			return 0xF3;
		}
	else {
		return 0xF3;
	}
}

int main() {
	char a;
	cout << "insira um caractere: " << flush;
	cin >> a;
	cout << hex << conversor (a) << endl;
	return 0;
}
