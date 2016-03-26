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

//TTokenCode
enum TTokenCode{
	tcDummy, tcIdentifier, tcNumber, tcString, tcEndOfFile, tcError,

	tcUpArrow, tcStar, tcLParen, tcRParen, tcMinus, tcPlus,
	tcEqual, tcLBracket, tcRBracket, tcColon, tcSemicolon, tcLt,
	tcGt, tcComma, tcPeriod, tcSlash, tcColonEqual, tcLe, tcGe,
	tcNe, tcDotDot,

	tcAND, tcARRAY, tcBEGIN, tcCASE, tcCONST, tcDIV,
	tcDO, tcDOWNTO, tcELSE, tcEND, tcFILE, tcFOR, tcFUNCTION,
	tcGOTO, tcIF, tcIN, tcLABEL, tcMOD, tcNIL, tcNOT, tcOF, tcOR,
	tcPACKED, tcPROCEDURE, tcPROGRAM, tcRECORD, tcREPEAT, tcSET,
	tcTHEN, tcTO, tcTYPE, tcUNTIL, tcVAR, tcWHILE, tcWITH,
};


//TCharCode
enum TCharCode{
	ccLetter, ccDigit, ccSpecial, ccQuote, ccWhiteSpace, ccEndOfFile, ccError,
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
