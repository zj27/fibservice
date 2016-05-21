#include <unistd.h>
#include <cstdlib>
#include <iostream>

#include "fibservice.h"

using std::cerr;
using std::endl;

using fibservice::FibService;

const unsigned int max_port = 65535;
const unsigned int min_port = 1025;
const unsigned int max_threads = 100;

void usage(const char * program_name) {
    cerr
        << "\n"
        << "usage: " << program_name << " [options] \n"
        << "\n"
        << "options:\n"
        << "   -h               = print usage\n"
        << "   -p <port>        = specify the service port\n"
        << "   -t <thread_num>  = specify the thread number\n";
}

int main(int argc, char** argv) {
    unsigned int port = 1984;
    unsigned int thread_num = 5;
    int opt;
    extern char* optarg;
    while ((opt = getopt(argc, argv, "hp:t:")) > 0) {
        switch (opt) {
            case 'p':
                port = atoi(optarg);
                if (port < min_port || port > max_port) {
                    cerr << "Invalid port " << optarg << endl;
                    cerr << "The port should between " << min_port \
                              << " and " << max_port << endl;
                    return 1;
                }
                break;
            case 't':
                thread_num = atoi(optarg);
                if (thread_num == 0 || thread_num > max_threads) {
                    cerr << "Invalid thread number "
                              << optarg << endl;
                    cerr << "The thread number should between 1 and " \
                              << max_threads << endl;
                    return 1;
                }
                break;
            case 'h':
            default:
                usage(argv[0]);
                return 1;
        }
    }

    FibService fibservice(port, thread_num);
    fibservice.start(); 
    return 0;
}
