/*
 * error.h
 *
 *  Created on: Feb 15, 2016
 *      Author: antonio
 */

#ifndef ERROR_H_
#define ERROR_H_

extern int errorCount;

using namespace std;

//Abort codes
enum TAbortCode
{
	abortInvalidCommandLineArgs=-1,
	abortSourceFileOpenFailed=-2,
	abortIFormFileOpenFailed=-3,
	abortAssemblyFileOpenFailed=-4,
	abortTooManySyntaxErrors=-5,
	abortStackOverflow=-6,
	abortCodeSegmentOverflow=-7,
	abortNestingTooDeep=-8,
	abortRuntimeError=-9,
	abortUnimplementedFeature=-10,
};

void AbortTranslation(TAbortCode ac);


#endif /* ERROR_H_ */
