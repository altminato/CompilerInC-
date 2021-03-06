/*
 * token.h
 *
 *  Created on: Feb 21, 2016
 *      Author: antonio
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include "../misc/misc.h"
#include "../error/error.h"
#include "../buffer/buffer.h"

//Token classes definitions

extern TCharCode charCodeMap[];

//TToken class

class TToken{
protected:
	TTokenCode 		code;
	TDataType 		type;
	TDataValue 		value;
	char			string[maxInputBufferSize];

public:
	TToken(void)
	{
		code=tcDummy;
		type=tyDummy;
		value.integer=0;
		string[0]='\0';

	}

	TTokenCode Code() const 	{ return code; }
	TDataType Type() const 		{ return type; }
	TDataValue Value()	const	{ return value; }
	char *String()				{ return string; }

	virtual void Get(TTextInBuffer &buffer)	=0;
	virtual int IsDelimiter(void) const =0;
	virtual void Print(void) const=0;
};

//TWordToken class

class TWordToken:public TToken{
	void CheckForReservedWord(void);
public:
	virtual void Get(TTextInBuffer &buffer);
	virtual int IsDelimiter(void) const { return false; }
	virtual void Print(void) const;
};


//TNumberToken
class TNumberToken:public TToken{
	char ch;
	char *ps;
	int digitCount;
	int countErrorFlag;

	int AccumulateValue(TTextInBuffer &buffer, float &value, TErrorCode ec);
public:
	TNumberToken(void){code = tcNumber; }

	virtual void Get(TTextInBuffer &buffer);
	virtual int IsDelimiter(void) const { return false; }
	virtual void Print(void) const;
};

//TStringToken
class TStringToken:public TToken{
public:
	TStringToken(){ code = tcString; }

	virtual void Get(TTextInBuffer &buffer){}
	virtual int IsDelimiter(void) const { return true; }
	virtual void Print(void) const{}
};

//TSpecialToken class

class TSpecialToken:public TToken{
public:
	virtual void Get(TTextInBuffer &buffer);
	virtual int IsDelimiter(void) const { return true; }
	virtual void Print(void) const;
};

//TEOFToken


class TEOFToken: public TToken{
public:
	TEOFToken(void){ code=tcEndOfFile; }
	virtual void Get(TTextInBuffer &buffer){}
	virtual int IsDelimiter(void) const { return false; }
	virtual void Print(void) const{}

};

//TErrorToken class
class TErrorToken:public TToken{
public:
	TErrorToken(void){ code= tcError; }
	virtual void Get(TTextInBuffer &buffer);
	virtual int IsDelimiter(void) const { return false; }
	virtual void Print(void) const{}

};













#endif /* TOKEN_H_ */
