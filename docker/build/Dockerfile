# Dockerfile to build fibservice
# Example:
# docker build -t --rm fibservice-dev ./
# docker run -it -v /<path>/<for>/<output>:/dist fibservice-dev

FROM ubuntu:16.04
MAINTAINER fibwebservice

# install build tool
RUN apt-get update
RUN apt-get install -y git cmake g++-5 libboost-program-options-dev

ENV CXX /usr/bin/g++-5
ARG project_root=/root

# check out the source
RUN cd ${project_root} \ 
    && git clone --recursive https://github.com/zj27/fibservice.git

# build and install restbed
RUN cd ${project_root}/fibservice/deps/restbed \ 
    && mkdir build \
    && cd build \
    && cmake -DBUILD_SHARED=YES -DBUILD_SSL=NO -DCMAKE_INSTALL_PREFIX=${project_root}/restbed_dist .. \
    && make install \
    && cd ${project_root}/restbed_dist \
    && cp -r include/* /usr/local/include \
    && cp -r library/* /usr/local/lib

# build and install jsoncpp
RUN cd ${project_root}/fibservice/deps/jsoncpp \
    && mkdir build \
    && cd build \
    && cmake -DBUILD_STATIC_LIBS=OFF -DBUILD_SHARED_LIBS=ON .. \
    && make install

# refresh the ld
RUN ldconfig

# build and install fibservice 
RUN cd ${project_root}/fibservice \
    && mkdir build \
    && cd build \
    && cmake -DBUILD_TESTS=ON .. \
    && make install \
    && make test

# create installation script
# dockerfile COPY couldn't copy symlink
# to make the deployment dockerfile independent from lib version
# here we just distribute the .so
RUN echo "#!/bin/bash" >> /install.sh \
    && echo "mkdir -p /dist/bin; \
    mkdir -p /dist/lib; \
    cp /usr/local/bin/fibservice  /dist/bin/; \
    cp /usr/local/lib/librestbed.so /dist/lib/; \
    cp /usr/local/lib/libjsoncpp.so /dist/lib/; \
    cp /usr/lib/x86_64-linux-gnu/libboost_program_options.so /dist/lib/; \
    echo Done" \
    >> /install.sh \
    && chmod +x /install.sh 

CMD ["/install.sh"]
