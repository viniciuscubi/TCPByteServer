#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <chrono>
#include <thread>
#include <zmq.hpp>

class Server{

    private:
            std::string ip;
            zmq::context_t context{1};
            zmq::socket_t socket{context, zmq::socket_type::rep};

    public:
            //Construtor
            Server(const std::string addr);
            ~Server();

            //Metodos
            int send(std::string message);
            std::string receive();
            int sendBit(bool message);
};

#endif
