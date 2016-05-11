#include <unistd.h>
#include <stdlib.h>
#include <iostream>

#include "fibservice.h"

const unsigned int max_port = 65535;
const unsigned int min_port = 1025;

void usage(const char * program_name)
{
   std::cerr
      << "\n"
      << "usage: " << program_name << " [options] \n"
      << "\n"
      << "options:\n"
      << "   -h               = print usage\n"
      << "   -p <port>        = specify the service port\n"
      << "   -t <thread_num>  = specify the thread number\n";
}

int main(int argc, char** argv)
{
    unsigned int port = 1984;
    unsigned int thread_num = 4;
    bool runAsDaemon = false;
    int opt;
    extern char* optarg;
    while((opt = getopt(argc, argv, "hdp:t:")) > 0)
    {
        switch(opt)
        {
            case 'd':
                runAsDaemon = true;
                break;
            case 'p':
                port = atoi(optarg);
                if(port < min_port || port > max_port)
                {
                    std::cerr << "Invalid port " << optarg << std::endl;
                    return 1;
                }
                break;
            case 't':
                thread_num = atoi(optarg);
                if(thread_num == 0)
                {
                    std::cerr << "Invalid thread number " << optarg << std::endl;
                    return 1;
                }
                break;
            case 'h':
            default:
                usage(argv[0]);
                return 1;
        }
    }
    start_fibservice(port, thread_num);
    return 0;
}
