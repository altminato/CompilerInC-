/*
 * buffer.h
 *
 *  Created on: Feb 13, 2016
 *      Author: antonio
 *  Classes: TTextInBUffer, TSourceBUffer, TTextOutBuffer, TListBuffer
 */

#ifndef BUFFER_H_
#define BUFFER_H_

//includes
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "../misc/misc.h"
#include "../error/error.h"


extern char eofChar;
extern int inputPosition;
extern int listFlag;
extern int level;

const int maxInputBufferSize =256;

//TTextInBuffer
class TTextInBuffer
{
protected:
	fstream file;
	char *const pFileName;
	char text[maxInputBufferSize];
	char *pChar;

	virtual char GetLine(void)=0;
public:
	TTextInBuffer(const char *pInputFileName, TAbortCode ac);
	virtual ~TTextInBuffer(void){
		file.close();
		delete pFileName;
	}
	//public methods
	char Char(void)const {return *pChar;};
	char GetChar(void);
	char PutBackChar(void);

};


//TSourceBuffer
class TSourceBuffer:public TTextInBuffer
{
	virtual char GetLine(void);
public:
	TSourceBuffer(const char *pSourceFileName);
};

//TTextOutBuffer
class TTextOutBuffer
{
public:
	char text[maxInputBufferSize+16];
	virtual void PutLine(void)=0;
	void PutLine(const char *pText)
	{
		strcpy(text, pText);
		PutLine();
	}
};

//TListBuffer
class TListBuffer:public TTextOutBuffer
{
	char *pSourceFileName;
	char date[26];
	int pageNumber;
	int lineCount;

	void PrintPageHeader(void);
public:
	virtual ~TListBuffer(void){
		delete pSourceFileName;
	}

	void Initialize(const char *fileName);
	virtual void PutLine(void);

	void PutLine(const char *pText){
		TTextOutBuffer::PutLine(pText);
	}

	void PutLine(const char *pText, int lineNumber, int nestingLevel){
		sprintf(text, "%4d %d: %s", lineNumber, nestingLevel, pText);
	}
};

extern TListBuffer list;

#endif /* BUFFER_H_ */
