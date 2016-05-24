# Dockerfile for fibservice
# Need make the project and copy 
# all binary and libraries under ./bin and ./lib

# Example:
# docker build -t fibservice ./
# docker run fibservice -p 1984

# Base OS: alpine with glibc
# The glibc apk is built by andyshinn
# https://github.com/andyshinn/alpine-pkg-glibc
FROM frolvlad/alpine-glibc

MAINTAINER fibservice

ARG bin_path=/usr/local/bin/
ARG lib_path=/usr/local/lib/
ARG gnu_lib_path=/usr/glibc-compat/lib/

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

# the libstdc++ and libpthread is not compatible
# copy them from devkit as workaround
RUN rm -f /usr/glibc-compat/lib/libpthread*
COPY ./lib/libstdc++.so.6.0.21 ${gnu_lib_path}
COPY ./lib/libpthread-2.23.so ${gnu_lib_path}
RUN ln -s ${gnu_lib_path}/libpthread-2.23.so ${gnu_lib_path}/libpthread.so.0 \
    && ln -s ${gnu_lib_path}/libstdc++.so.6.0.21 ${gnu_lib_path}/libstdc++.so.6

# refresh the ld
RUN echo /usr/local/lib >> /usr/glibc-compat/etc/ld.so.conf \
    && /usr/glibc-compat/sbin/ldconfig

ENTRYPOINT ["fibservice"]
