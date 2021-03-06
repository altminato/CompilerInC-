/*
 * parser.cpp
 *
 *  Created on: Feb 21, 2016
 *      Author: antonio
 */

#include <stdio.h>
#include "../common/common.h"
#include "../buffer/buffer.h"
#include "../error/error.h"
#include "parser.h"

//Parse method
void TParser::Parse(void){
	do{
		GetToken();
		if(token != tcError){
			pToken->Print();
		}else{
			sprintf(list.text,"\t%-18s %-s",">> *** ERROR ***",pToken->String());
			list.PutLine();
			++errorCount;
		}


	}while(token != tcEndOfFile);

	//Print the parser summary
	list.PutLine();
	sprintf(list.text,"%20d source lines.",currentLineNumber);
	list.PutLine();
	sprintf(list.text, "%20d syntax errors.", errorCount);
	list.PutLine();

}
