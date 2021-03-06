/*
 * token.cpp
 *
 *  Created on: Feb 21, 2016
 *      Author: antonio
 */

#include <stdio.h>
#include <string.h>
#include "token.h"
#include "../misc/misc.h"

void stringtolower(char *string, int lenght){
	for(int i=0; i<lenght; i++){
		if(isupper(string[i])){
			string[i]=tolower(string[i]);
		}
	}
}

//Word Token
//Get
void TWordToken::Get(TTextInBuffer &buffer){
	char ch=buffer.Char();
	char *ps=string;

	//Extract the word
	do{
		*ps++=ch;
		ch=buffer.GetChar();

	}while( (charCodeMap[ch]==ccLetter)
			|| (charCodeMap[ch]== ccDigit));

	*ps='\0';
	stringtolower(string, maxInputBufferSize);
	code=tcWord;
}

//Print
void TWordToken::Print(void)const
{
	sprintf(list.text, "\t%-18s %-s", ">> word: ", string);
	list.PutLine();
}

//Get
void TNumberToken::Get(TTextInBuffer &buffer){
	const int maxDigitCount=4;

	char ch=buffer.Char();
	char *ps=string;
	int digitCount=0;
	int countErrorFlag=false;


	//Accumulate the value as long as the total allowable
	//number of digits has not been exceeded
	value.integer=0;
	do{
		*ps++=ch;
		//SHift left and add
		if(++digitCount <= maxDigitCount){
			value.integer=10*value.integer+(ch-'0');
		}else{
			countErrorFlag=true;
		}
		ch=buffer.GetChar();
	}while((charCodeMap[ch]==ccDigit));

	*ps='\0';
	code=countErrorFlag ? tcError: tcNumber;

}

//Print
void TNumberToken::Print(void)const{
	sprintf(list.text, "\t%-18s =%d", ">> number:", value.integer);
	list.PutLine();
}

//SpecialTokens

void TSpecialToken::Get(TTextInBuffer &buffer){
	char ch=buffer.Char();
	char *ps=string;

	*ps++=ch;
	*ps='\0';
	buffer.GetChar();
	code= (ch== '.')? tcPeriod: tcError;

}

//Print
void TSpecialToken::Print(void)const{
	sprintf(list.text,"\t%-18s %-s",">> special:", string);
	list.PutLine();
}


//TErrorToken
//Get
void TErrorToken::Get(TTextInBuffer &buffer){
	string[0]=buffer.Char();
	string[1]='\0';
	buffer.GetChar();
}




