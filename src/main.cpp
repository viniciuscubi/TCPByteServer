#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <pigpio.h>
#include <unistd.h>
#include "../include/server.hpp"
#include "../include/parser.hpp"
#include "../include/pinsys.hpp"

#define test_pin 14

int main() 
{  

    bool var = true;
	
	PinSys ps(test_pin);

    using namespace std::chrono_literals;

    Server sv("tcp://192.168.1.102:5555");
	

    while(1) 
    {
        std::string msg = sv.receive();

        //std::cout << "Received: " << msg << std::endl;

        if(msg.compare("1")){
            var = false;
        }else{
            var = true;
        }

		ps.updatePin(var);
		
        sv.sendBit(var);

    }

    return 0;
}