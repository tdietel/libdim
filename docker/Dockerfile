FROM centos:6


RUN yum install https://dl.fedoraproject.org/pub/epel/epel-release-latest-6.noarch.rpm -y

RUN yum install libtool -y

RUN yum install lesstif-devel -y

RUN yum install gcc-c++ -y

RUN yum install rpm-build -y

RUN yum install java-1.8.0-openjdk-devel -y

#test libdim build#
# WORKDIR /usr/src/app

# COPY ./libdim-src.tar.gz .

# RUN tar -xf libdim-src.tar.gz

# WORKDIR /usr/src/app/libdim

# RUN ./bootstrap && ./configure

# RUN make

# RUN make rpm

# RUN make install