//
// Created by lahmer on 1/23/17.
//

#ifndef FILESERVER_FILESERVER_H
#define FILESERVER_FILESERVER_H


#include <string>
#include <vector>
#include <map>
#include "File.h"

class FileServer {
public:
    FileServer(const std::string &path);
    File* getFileByName(const std::string& name );

private:
    std::string path;
    std::vector<File> fileList;
};


#endif //FILESERVER_FILESERVER_H
