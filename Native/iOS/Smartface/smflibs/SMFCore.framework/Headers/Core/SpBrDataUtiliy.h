/*
 * SpBrDataUtility.h
 *
 *  Created on: Aug 26, 2013
 *      Author: ugurkilic
 */

#ifndef SPBRDATAUTILITY_H_
#define SPBRDATAUTILITY_H_

#include <string>
#include <vector>
#include <map>

#include "SpDefs.h"
#include "SpDefs.h"
#include "SpJsEngine/Core/SpJsEngine.h"

class SmfDataParameter;

class SpBrDataUtiliy {
public:
	SpBrDataUtiliy();
	virtual ~SpBrDataUtiliy();
    
public:
    static void SetInsideParameters(SpJsObject parameter, std::vector<std::string> *paramVec, std::map<std::string, std::string> *paramMap);
};

#endif /* SPBRDATAUTILITY_H_ */
