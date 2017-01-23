#include <iostream>
#include "FileServer.h"
#include "Server.h"
#include <ndn-cxx/face.hpp>
#include <ndn-cxx/interest.hpp>
#include <ndn-cxx/data.hpp>
#include <ndn-cxx/security/key-chain.hpp>


int main() {
    FileServer *server = new FileServer("/home/lahmer/Desktop/pfe/itec-ndn/topologies");
    File* file = server->getFileByName("first-scenario.top");
    for (int i = 0; i < file->getChunkListSize(); ++i) {
        std::cout<<"chunk = "<<file->getChunk(i)<<std::endl;
    }

    ndn::Face face;
    Server server1(face);

    face.processEvents();
    return 0;
}