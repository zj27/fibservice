#ifndef SRC_FIBSERVICE_H_
#define SRC_FIBSERVICE_H_

const unsigned int default_port = 1984;
const unsigned int default_thread_num = 5;

/*
 *  Start the service with given port and thread num
 */
void start_fibservice(const unsigned int port = default_port,
                      const unsigned int thread_num = default_thread_num);

#endif  // SRC_FIBSERVICE_H_
