/*
 * ResultSet.h
 *
 *  Created on: Nov 21, 2012
 *      Author: ugurkilic
 */

#ifndef RESULTSET_H
#define RESULTSET_H

#include <map>
#include <string>
#include "sqlite3.h"

class Statement;
class Database;
class SpBrString;

class ResultSet {
  public:
	ResultSet(Statement *_statement, Database *db);
    ~ResultSet();

	void Close(bool destructing = false);
	void SetStatement(Statement *_statement);
	void SetParentDB(Database *db);
	void SetupColumnNames();

	int ColumnCount();
	bool Next();
	bool HasAnotherRow();

	SpBrString* StringForColumnIndex(int ix);
	SpBrString* StringForColumnName(SpBrString **columnName);
	int IntegerForColumnIndex(int ix);

	int ColumnIndexForColumnName(SpBrString **columnName);
    SpBrString* ColumnNameAt(int ix);

  private:
	Database *parentDB;
	Statement *statement;
	std::map<std::string, int> columnNameToIndexMap;
	bool columnNamesSetup;
  };

  #endif /* RESULTSET_H */
