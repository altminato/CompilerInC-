/*
 * tokeniz1.cpp
 *
 *  Created on: Feb 21, 2016
 *      Author: antonio
 *  Description:
 */

#include "../error/error.h"
#include "../buffer/buffer.h"
#include "parser.h"
#include <iostream>
using namespace std;

//Main function

int main(int argc, char *argv[]) {

	cout << "Initiating the Tokeni1.cpp program..." << endl; // prints !!!Hello World!!!

	TParser parser(new TSourceBuffer("/home/antonio/workspace/Compiler/Debug/input2.pass"));
	parser.Parse();

	cout << "Exiting Tokeni1.cpp program..." << endl; // prints !!!Hello World!!!

	return 0;
}
