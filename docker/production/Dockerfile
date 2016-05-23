
#FROM busybox:glibc
FROM frolvlad/alpine-glibc
#FROM alpine

MAINTAINER fibservice

ARG bin_path=/usr/local/bin/
ARG lib_path=/lib/
ARG service_port=1984


COPY ./bin/fibservice ${bin_path}
COPY ./lib/librestbed.so ${lib_path}
COPY ./lib/libjsoncpp.so ${lib_path}
RUN cd ${lib_path} \
    && ln -s libjsoncpp.so libjsoncpp.so.1 \
    && ln -s libjsoncpp.so libjsoncpp.so.1.7.2
COPY ./lib/libboost_program_options.so ${lib_path}
RUN cd ${lib_path} \
    && ln -s libboost_program_options.so libboost_program_options.so.1.61.0 

COPY ./lib/libstdc++.so.6 ${lib_path}
COPY ./lib/libgccpp.so.1 ${lib_path}
COPY ./lib/libgcc_s.so.1 ${lib_path}
COPY ./lib/libpthread.so.0 ${lib_path}

RUN apk add --update
RUN apk --no-cache add ca-certificates

EXPOSE ${service_port}

CMD ["fibservice", "-h"]

