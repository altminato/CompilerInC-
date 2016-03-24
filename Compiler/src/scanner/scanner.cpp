/*
 * scanner.cpp
 *
 *  Created on: Feb 21, 2016
 *      Author: antonio
 */

#include "scanner.h"


//Maps a character to its code
TCharCode charCodeMap[128];


TTextScanner::TTextScanner(TTextInBuffer *pBuffer)
	:pTextInBuffer(pBuffer){

	int i;

	//Initialize the character code map.
	for (i=0; i<=127; ++i)charCodeMap[i]=ccError;
	for (i='a'; i<='z'; ++i)charCodeMap[i]=ccLetter;
	for (i='A'; i<='Z'; ++i)charCodeMap[i]=ccLetter;
	for (i='0'; i<='9'; ++i)charCodeMap[i]=ccDigit;

	charCodeMap['+']=charCodeMap['-']=ccSpecial;
	charCodeMap['*']=charCodeMap['/']=ccSpecial;
	charCodeMap['=']=charCodeMap['^']=ccSpecial;
	charCodeMap['.']=charCodeMap[',']=ccSpecial;
	charCodeMap['<']=charCodeMap['>']=ccSpecial;
	charCodeMap['(']=charCodeMap[')']=ccSpecial;
	charCodeMap['[']=charCodeMap[']']=ccSpecial;
	charCodeMap['{']=charCodeMap['}']=ccSpecial;
	charCodeMap[':']=charCodeMap[';']=ccSpecial;
	charCodeMap['\n']=charCodeMap['\0']=ccWhiteSpace;
	charCodeMap['\'']=ccQuote;
	charCodeMap[eofChar]=ccEndOfFile;

}

//SkipWhiteSpace
void TTextScanner::SkipWhiteSpace(void){
	char ch=pTextInBuffer->Char();
	while(charCodeMap[ch]== ccWhiteSpace){
		ch=pTextInBuffer->GetChar();
	}
}

//Get
TToken *TTextScanner::Get(void){
	TToken *pToken;
	SkipWhiteSpace();

	//Determine the token class based on the current character

	switch(charCodeMap[pTextInBuffer->Char()]){
		case ccLetter: 		pToken=&wordToken;		break;
		case ccDigit: 		pToken=&numberToken;	break;
		case ccQuote:		pToken=&stringToken;	break;
		case ccSpecial:		pToken=&specialToken;	break;
		case ccEndOfFile:	pToken=&eofToken;		break;
		default:			pToken=&errorToken;		break;
	}

	//Extract a token of that class, and return a pointer to it.
	pToken->Get(*pTextInBuffer);
	return pToken;
}

















