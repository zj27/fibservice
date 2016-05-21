#ifndef SRC_FIBSERVICE_H_
#define SRC_FIBSERVICE_H_

#include <memory>

#include <restbed>

using std::shared_ptr;

using restbed::Session;
using restbed::Service;

namespace fibservice {

class FibService {
    public:
        FibService(const unsigned int port, const unsigned int threads);

        FibService(const unsigned int port, const unsigned int threads,
                   const shared_ptr< Service >& service);

        void start();

        void stop();

        unsigned int get_port() { return m_port; };

        void set_port(const unsigned int port) { m_port = port; };

        unsigned int get_threads() { return m_threads; };

        void set_threads(const unsigned int threads) { m_threads = threads; };
          
    private:
        static void get_method_handler(const shared_ptr< Session > session);

        unsigned int m_port;
        unsigned int m_threads;

        shared_ptr< Service > m_service;

};

}

#endif  // SRC_FIBSERVICE_H_
