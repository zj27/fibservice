#include <cstdlib>
#include <iostream>

#include <boost/program_options.hpp>

#include "fibservice.h"

using std::cout;
using std::cerr;
using std::endl;

namespace po = boost::program_options;

using fibservice::FibService;

const unsigned int kMaxPort = 65535;
const unsigned int kMinPort = 1025;
const unsigned int kMaxThreads = 100;
const unsigned int kDefaultPort = 1984;
const unsigned int kDefaultThreads = 5;

int main(int argc, char** argv) {
    unsigned int port = kDefaultPort;
    unsigned int threads = kDefaultThreads;

    po::options_description desc("General options");
    desc.add_options()
        ("help,h", "produce help message")
        ("port,p", po::value<unsigned int>(), "set service port")
        ("threads,t", po::value<unsigned int>(), "set service thread number");

    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
    }
    catch (...) {
        // unknown_option, invalid_option_value, etc.
        cerr << desc << endl;
        return 1;
    }

    po::notify(vm);

    if (vm.count("help")) {
        cout << desc << endl;
        return 0;
    }

    if (vm.count("port")) {
        port = vm["port"].as<unsigned int>();
        // Port range check
        if (port < kMinPort || port > kMaxPort) {
            cerr << "Invalid port " << port << endl;
            cerr << "The port should between " << kMinPort \
                 << " and " << kMaxPort << endl;
            return 1;
        }
    }

    if (vm.count("threads")) {
        threads = vm["threads"].as<unsigned int>();
        // Thread number range check
        if (threads == 0 || threads > kMaxThreads) {
            cerr << "Invalid thread number "
                 << threads << endl;
            cerr << "The thread number should between 1 and " \
                 << kMaxThreads << endl;
            return 1;
        }
    }

    FibService fibservice(port, threads);
    fibservice.start();
    return 0;
}
