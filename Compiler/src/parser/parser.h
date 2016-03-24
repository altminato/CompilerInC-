/*
 * parser.h
 *
 *  Created on: Feb 21, 2016
 *      Author: antonio
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "../misc/misc.h"
#include "../buffer/buffer.h"
#include "../token/token.h"
#include "../scanner/scanner.h"

//TParser class
class TParser{
	TTextScanner *const pScanner;
	TToken				*pToken;
	TTokenCode			token;
	void GetToken(void){
		pToken=pScanner->Get();
		token=pToken->Code();
	}
public:
	TParser(TTextInBuffer *pBuffer)
		:pScanner(new TTextScanner(pBuffer)){}

	~TParser(void){delete pScanner; }

	void Parse(void);

};


















#endif /* PARSER_H_ */
