# Dockerfile to build fibservice
# Example:
# docker build -t --rm fibservice-dev ./
# docker run -it fibservice-dev

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
    && cmake -DBUILD_TESTS .. \
    && make install \
    && make test

# create installation script
RUN echo "#!/bin/sh
    mkdir -p /dist/bin;
    mkdir -p /dist/lib; 
    cp /usr/local/bin/fibservice  /dist/bin/; 
    cp -P /usr/local/lib/librestbed.so* ${output_dir}/lib/; 
    cp -P /usr/local/lib/libjsoncpp.so* ${output_dir}/lib/; 
    cp -P /usr/local/lib/libboost_program_options.so* ${output_dir}/lib/ " \
    >> /install.sh &&

CMD ["/install.sh"]
