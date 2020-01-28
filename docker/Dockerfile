FROM centos:6


RUN yum install https://dl.fedoraproject.org/pub/epel/epel-release-latest-6.noarch.rpm -y

RUN yum install libtool -y

RUN yum install lesstif-devel -y

RUN yum install gcc-c++ -y

#test libdim build#
# WORKDIR /usr/src/app

# COPY ./libdim-src.tar.gz .

# RUN tar -xf libdim-src.tar.gz

# WORKDIR /usr/src/app/libdim

# RUN ./bootstrap && ./configure

# RUN make

# RUN make install