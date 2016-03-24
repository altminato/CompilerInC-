/*
 * buffer.cpp
 *
 *  Created on: Feb 13, 2016
 *      Author: antonio
 *  Classes: TTextInBUffer, TSourceBUffer, TTextOutBuffer, TListBuffer
 */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include "../common/common.h"
#include "buffer.h"

using namespace std;

char eofChar=0x7F;
int inputPosition;
int listFlag;

//TextInputBuffer
TTextInBuffer::TTextInBuffer(const char *pInputFileName, TAbortCode ac)
	:pFileName(new char[strlen(pInputFileName)+1])
{
	strcpy(pFileName, pInputFileName);
	//open the file, abort if failed.
	file.open(pFileName, ios::in);
	if(!file.good())
		AbortTranslation(ac);
}

//GetChar()
char TTextInBuffer::GetChar(void)
{
	const int tabSize=8;
	char ch;

	if(*pChar==eofChar)
		return eofChar;
	else if(*pChar=='\0')
		ch=GetLine();
	else
	{
		++pChar;
		++inputPosition;
		ch=*pChar;
	}

	//if tab char, increment inputPosition to the next
	//multiple of tabSize
	if(ch=='\t')
		inputPosition+=tabSize-inputPosition%tabSize;

	return ch;
}

char TTextInBuffer::PutBackChar(void)
{
	--pChar;
	--inputPosition;
	return *pChar;
}

//SourceBuffer
TSourceBuffer::TSourceBuffer(const char *pSourceFileName)
	:TTextInBuffer(pSourceFileName, abortSourceFileOpenFailed)
{
	//INitialize the list file
	if(listFlag)
		list.Initialize(pSourceFileName);
	GetLine();
}

char TSourceBuffer::GetLine(void)
{
	extern int lineNumber, currentNestingLevel;

	//if at the end of the source file, return end-of-file char.
	if(file.eof())
		pChar=&eofChar;
	else
	{
		file.getline(text, maxInputBufferSize);
		pChar=text;
		if(listFlag)
			list.PutLine(text, ++currentLineNumber, currentNestingLevel);
	}
	inputPosition=0;
	return *pChar;
}

//listBuffer
const int maxPrintLineLength=80;
const int maxLinesPerPage=50;

TListBuffer list;


//TListBuffer

void TListBuffer::PrintPageHeader(void)
{
	const char formFeedChar='\f';
	cout <<formFeedChar<< "Page "<< ++pageNumber
			<< "   "<<pSourceFileName<<"   "<<date
			<< endl;
	lineCount=0;
}

void TListBuffer::Initialize(const char *pFileName)
{
	text[0]='\0';
	pageNumber=0;

	//copy the inputfile name
	pSourceFileName=new char[strlen(pFileName)+1];
	strcpy(pSourceFileName, pFileName);

	//set the date
	time_t timer;
	time(&timer);
	strcpy(date, asctime(localtime(&timer)));
	date[strlen(date)-1];

	PrintPageHeader();
}

void TListBuffer::PutLine(void)
{
	//start new page if the current one is full
	if(listFlag && (lineCount == maxLinesPerPage))
		PrintPageHeader();

	//Truncate the line if its too long
	text[maxPrintLineLength]='\0';

	//print the next line and then blanck up the text
	cout <<text<<endl;

	text[0]='\0';

	++lineCount;
}


























