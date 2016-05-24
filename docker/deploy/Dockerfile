# Dockerfile for fibservice
# Need execute the fibservice-build 
# docker image first, and build this 
# docker image under the build output folder

# Example:
# docker build --rm -t fibservice ./
# docker run fibservice -p 1984

FROM ubuntu:16.04

MAINTAINER fibservice

ARG bin_path=/usr/local/bin/
ARG lib_path=/usr/local/lib/

# copy the project binary and libraries
COPY ./bin/* ${bin_path}
COPY ./lib/* ${lib_path}

# refresh the ld
RUN ldconfig

ENTRYPOINT ["fibservice"]
