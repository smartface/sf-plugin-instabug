/*
 * Statement.h
 *
 *  Created on: Nov 21, 2012
 *      Author: ugurkilic
 */

#ifndef STATEMENT_H
#define STATEMENT_H

#include "sqlite3.h"

class Statement {
public:
	Statement();
	~Statement();

	void Close();
	void Reset();

public:
	sqlite3_stmt *statement;
};

#endif /* STATEMENTWINRT_H */
