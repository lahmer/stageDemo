//
// Created by lahmer on 1/23/17.
//

#ifndef FILESERVER_SERVER_H
#define FILESERVER_SERVER_H

#include <ndn-cxx/interest.hpp>
#include <ndn-cxx/data.hpp>
#include <ndn-cxx/security/key-chain.hpp>
#include <ndn-cxx/face.hpp>
#include "FileServer.h"

class Server
{
public:
  Server(ndn::Face& face)
    : m_face(face)
    , m_baseName("/fileServer")
    , m_counter(0)
  {
    m_face.setInterestFilter(m_baseName,std::bind(&Server::onInterest, this, _2),std::bind([] {
                                 std::cerr << "Prefix registered" << std::endl;
                               }),
                             [] (const ndn::Name& prefix, const std::string& reason) {
                               std::cerr << "Failed to register prefix: " << reason << std::endl;
                             });
      server = new FileServer("/home/lahmer/Desktop/pfe/itec-ndn/topologies");


  }

private:
  void
  onInterest(const ndn::Interest& interest)
  {
    std::cout << "<< interest for " << interest << std::endl;

    // create data packet with the same name as interest
    std::shared_ptr<ndn::Data> data = std::make_shared<ndn::Data>(interest.getName());

    // prepare and assign content of the data packet
    std::ostringstream os;


      ndn::Name name = interest.getName();
      std::string fileName = name.get(1).toUri();
      std::string chunkIndex = name.get(2).toUri();

      int index = atoi(chunkIndex.c_str());
      File *file = server->getFileByName(fileName);
      if(file == nullptr)
        os << "Error requesting unexisting file "<<fileName<<std::endl;

      std::string chunk = file->getChunk(index);

      os << chunk << std::endl;












    std::string content = os.str();
    data->setContent(reinterpret_cast<const uint8_t*>(content.c_str()), content.size());

    // set metainfo parameters
    data->setFreshnessPeriod(ndn::time::seconds(10));

    // sign data packet
    m_keyChain.sign(*data);

    // make data packet available for fetching
    m_face.put(*data);
  }

private:
  ndn::Face& m_face;
  ndn::KeyChain m_keyChain;
  ndn::Name m_baseName;
  uint64_t m_counter;

    FileServer *server;
};


#endif //FILESERVER_SERVER_H
