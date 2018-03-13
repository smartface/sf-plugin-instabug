/*
 * SpAPKRead.h
 *
 *  Created on: 25 Jul 2011
 *      Author: VAIO
 */
#ifndef SpAPKRead_H_
#define SpAPKRead_H_

#include <stdio.h>
#include <map>
#include <string>

using namespace std;

class stored_file_c{
public:
	 stored_file_c();
	 virtual ~stored_file_c();
	 int comp_method;
	 unsigned int CRC32;
	 unsigned int comp_size;
	 unsigned int uncomp_size;
	 unsigned int file_offset;
	 char* filename;
};

class SpAPKRead {
private:
	FILE* apkFile;
public:
	map<string,stored_file_c> storedFiles;
	map<string,string> storedEmulatorFiles;
	map<string,string> storedPlayerRAUFiles;
	SpAPKRead();
	virtual ~SpAPKRead();
	void Initialize(FILE* apkFile);
	bool ExistsInApk(const char *filename);
	unsigned int fileread(FILE* file, int num_bytes);
	char* readFile(const char* name, int& len, bool nullterminated);
};



#endif /* SpAPKRead_H_ */
