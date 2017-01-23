//
// Created by lahmer on 1/23/17.
//

#include <dirent.h>
#include <iostream>
#include <cstring>
#include "FileServer.h"

FileServer::FileServer(const std::string &path) : path(path) {
    DIR *dir;
    struct dirent *epdf;

    dir = opendir(path.c_str());
    if (dir != NULL){
        while (epdf = readdir(dir)){
            if(strcmp(epdf->d_name,".") == 0 )
                continue;

            if(strcmp(epdf->d_name,"..") == 0 )
                continue;

            std::string fileName = path;
            fileName+= "/";
            fileName.append(epdf->d_name);
            std::string name(epdf->d_name);
            fileList.push_back(File(fileName,name));

        }
}

}

File *FileServer::getFileByName(const std::string &name) {
    for (int i = 0; i < fileList.size(); ++i) {
        if(strcmp(fileList.at(i).getFileName().c_str(),name.c_str()) == 0 ){
            return &fileList.at(i);
        }
    }
    return nullptr;
}
