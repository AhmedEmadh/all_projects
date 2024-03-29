/*
 ============================================================================
 File Name		: main.cpp
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 24/3/2023
 Description	: This file contains the program of the scanner that creates tokens from C code to be passed to parser in C compiler
 Notes			: The implementation of the program incapsulated in Lexer Class
 ============================================================================
*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Lexer.h"
using namespace std;

int main() {
	Lexer lexer("Testfile.txt");
	lexer.scan();
	vector<string> tokens = lexer.getTokens();
	for (auto token : tokens) {
		cout << "  " << token << endl;
	}
	return 0;
}