# Dockerfile for fibservice
# Need execute the fibservice-build 
# docker image first, and build this 
# docker image under the build output folder

# Example:
# docker build -t fibservice ./
# docker run fibservice -p 1984

FROM ubuntu:16.04

MAINTAINER fibservice

ARG bin_path=/usr/local/bin/
ARG lib_path=/usr/local/lib/

# copy the project binary and libraries
COPY ./bin/fibservice ${bin_path}
COPY ./lib/librestbed.so ${lib_path}
COPY ./lib/libjsoncpp.so.1.7.2 ${lib_path}
RUN cd ${lib_path} \
    && ln -s libjsoncpp.so.1.7.2 libjsoncpp.so.1 \
    && ln -s libjsoncpp.so.1.7.2 libjsoncpp.so
COPY ./lib/libboost_program_options.so.1.61.0 ${lib_path}
RUN cd ${lib_path} \
    && ln -s libboost_program_options.so.1.61.0 libboost_program_options.so

# refresh the ld
RUN ldconfig

ENTRYPOINT ["fibservice"]
