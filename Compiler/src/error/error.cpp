/*
 * error.cpp
 *
 *  Created on: Feb 15, 2016
 *      Author: antonio
 */

#include <stdlib.h>
#include <iostream>
#include "error.h"

int errorCount=0;

static const char* abortMsg[]= {
		NULL,
		"Invalid command line arguments",
		"Failed to open source file",
		"Failed to open intermediate form file",
		"Failed to open assembly file",
		"Too many syntax errors",
		"Stack overflow",
		"Code segment overflow",
		"Nesting too deep",
		"Runtime error",
		"Unimplemented feature"
};

//Abort Translation
void AbortTranslation(TAbortCode ac)
{
	cout << "*** Fatal transaltor error: " << abortMsg[ac] << endl;
	exit(ac);
}

