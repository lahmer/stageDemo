//
// Created by lahmer on 1/23/17.
//

#ifndef FILESERVER_FILE_H
#define FILESERVER_FILE_H


#include <string>
#include <vector>

class File {
public:
    File(const std::string& path, const std::string &name);
    std::string getFileName();
    std::string getChunk(int index);
    int getChunkListSize();

private:
    std::string fileContent;
    std::string name;
    std::string path;
    unsigned int chunkSize = 100;
    std::vector<std::string> chunks;
};


#endif //FILESERVER_FILE_H
