/*
 * Database.h
 *
 *  Created on: Nov 21, 2012
 *      Author: ugurkilic
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <list>
#include <map>
#include <string>
#include "sqlite3.h"
#include "Core/SpDefs.h"

class ResultSet;
class SpBrString;


static void smf_sql_function_decrypt(sqlite3_context *context, int argc, sqlite3_value **argv);

static void smf_sql_function_encrypt(sqlite3_context *context, int argc, sqlite3_value **argv);

static void smf_sql_function_main(CryptoMode mode, sqlite3_context *context, int argc, sqlite3_value **argv);

class Database {
public:
	Database(SpBrString* path);
	~Database();
    
	sqlite3* SQLiteHandle();
	bool Open(int* errorCode = 0);
	bool Close();
    
	void CloseOpenResultSets();
	bool HasOpenResultSets();
    
	bool Commit();
	bool BeginTransaction();
    bool Rollback();
	bool TableExists(const char* tableName);

	bool ExecuteUpdate(const char* sql, std::vector<char *> *paramList = NULL, std::vector<std::string> *paramVec = NULL, std::map<std::string, std::string> *paramMap = NULL);
	ResultSet* ExecuteQuery(const char* sql, std::vector<char *> *paramList = NULL, std::vector<std::string> *paramVec = NULL, std::map<std::string, std::string> *paramMap = NULL);

    bool CollectInformation(const char* sql
                            , std::vector<SpBrString*> &columnNames
                            , std::vector<SpBrString*> &columnTypes
                            , std::vector<SpBrString*> &columnDefaults
                            , std::vector<bool> &columnIsPrimary);
    
	void ResultSetDidClose(ResultSet* rs);
	ResultSet* GetSchema();
	ResultSet* GetTableSchema(SpBrString* tableName);
	bool ValidateSQL(SpBrString* sql);
    SpBrString* GetLastErrorMessage();
    
	void WarnInUse();
	bool IsInUse();
    void BindObject(const char* obj, int idx, sqlite3_stmt* pStmt);

private:
	sqlite3 *db;
	SpBrString *databasePath;
    SpBrString *lastErrorMessage;
    
	std::vector<ResultSet *> openedResultSets;
	bool isExecutingStatement;
};

#endif /* DATABASE_H */
