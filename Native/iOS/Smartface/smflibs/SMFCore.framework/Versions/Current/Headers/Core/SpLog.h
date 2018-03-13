/**
 * logs for sprat
 *
 */
#ifndef SPLOG_H_
#define SPLOG_H_

#include "ESpLog.h"
#include "TinyXML/tinyxml.h"
#include <time.h>
#include <string>

class SpLogger;
class SpBrString;
/**
 * it show logs with time
 *
 */
void splog_t(int type,const char *className, const char *msg, ...);
std::string splog_tofile(int type,const char *className, const char *fileName, const char *msg);
const char* splog_str(SpBrString* str);
extern clock_t last_log_time;
const char* splog_objectname(int objectID);
const char* getEventName(int eventID);

#define SPLOG_DEBUG splog(SPDEB,"M","Function=%s Line=%d file=%s",__func__,__LINE__,__FILE__)
#define SPLOG_ERROR splog(SPERR,"M","Function=%s Line=%d file=%s",__func__,__LINE__,__FILE__)


/*
 * xml pring debug functions
 */
const unsigned int NUM_INDENTS_PER_SPACE=2;
const char * getIndent( unsigned int numIndents );
// same as getIndent but no "+" at the end
const char * getIndentAlt( unsigned int numIndents );
int dump_attribs_to_stdout(TiXmlElement* pElement, unsigned int indent);
void dump_to_stdout( TiXmlNode* pParent, unsigned int indent = 0 );

#include <string>

#define MAXLOGLENGTHINMEMORY    1024
#define LOGFILE                 "smf.log"
#define LOGSEPARATOR            "\n\t"

static SpLogger *logger = NULL;

class SpLogger {
public:
    SpLogger();
    ~SpLogger();

    static SpLogger* GetInstance();
    void Log(int priority, const char *description, const char *extra = NULL, ...);
    void Log(int priority, char *description, char *exceptionType, char *exceptionMethod, char *exceptionStackTrace);
    bool WriteLogToFile();
    bool SendLogs();

private:
    std::string logBuffer;
};

#endif
