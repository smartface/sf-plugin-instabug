#ifndef __SMF_IO_FILESERVICE_H__
#define __SMF_IO_FILESERVICE_H__

#include <string>
using std::string;

namespace Smf {

class FileService {
public:
    static char* ReadFileInAsset(string filename, int &length);
    static char* ReadFileInResource(string filename, int &length);
};

}

#endif
