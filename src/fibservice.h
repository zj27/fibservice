#ifndef FIB_SERVICE_H
#define FIB_SERVICE_H 

const unsigned int default_port = 1984;
const unsigned int default_thread_num = 5; 

void start_fibservice(const unsigned int port = default_port, 
                      const unsigned int thread_num = default_thread_num);

#endif
