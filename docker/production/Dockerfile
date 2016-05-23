
FROM busybox:glibc

MAINTAINER fibservice

ARG bin_path=/usr/local/bin/
ARG lib_path=/lib/
ARG service_port=1984

COPY ./bin/fibservice ${bin_path}
COPY ./lib/librestbed.so ${lib_path}
COPY ./lib/libjsoncpp.so* ${lib_path}
COPY ./lib/libboost_program_options.so* ${lib_path}

EXPOSE ${service_port}

CMD ["fibservice", "-h"]

