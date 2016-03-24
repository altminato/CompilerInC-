/*
 * misc.h
 *
 *  Created on: Feb 15, 2016
 *      Author: antonio
 */

#ifndef MISC_H_
#define MISC_H_

//const int ffalse = 0;
//const int ttrue = 1;

//TCharCode
enum TCharCode{
	ccLetter, ccDigit, ccSpecial, ccQuote, ccWhiteSpace, ccEndOfFile, ccError,
};


//TTokenCode
enum TTokenCode{
	tcDummy, tcWord, tcNumber, tcPeriod, tcEndOfFile, tcError,
};

//TDataType
enum TDataType{
	tyDummy, tyInteger, tyReal, tyCharacter, tyString,
};

//TDataValue
union TDataValue{
	int integer;
	float real;
	char character;
	char *pString;
};


#endif /* MISC_H_ */
