/*
 * scanner.h
 *
 *  Created on: Feb 21, 2016
 *      Author: antonio
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include "../misc/misc.h"
#include "../buffer/buffer.h"
#include "../token/token.h"


//Class TScanner

class TScanner{
protected:
	//Tokens extracted and returned by the scanner
	TWordToken wordToken;
	TNumberToken numberToken;
	TStringToken stringToken;
	TSpecialToken specialToken;
	TEOFToken eofToken;
	TErrorToken errorToken;

public:
	virtual ~TScanner(void){}

	virtual TToken *Get(void)=0;

};


//Class TTextScanner

class TTextScanner:public TScanner{
	TTextInBuffer *const pTextInBuffer;

	void SkipWhiteSpace(void);

public:
	TTextScanner (TTextInBuffer *pBuffer);
	virtual ~TTextScanner(void)
	{
		delete pTextInBuffer;
	}
	virtual TToken *Get(void);
};






#endif /* SCANNER_H_ */
