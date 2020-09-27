FROM gitlab-registry.cern.ch/alitrd/alitrd-containers:centos8

COPY . .

RUN dnf install -y motif-devel

RUN chmod +x bootstrap

RUN ./bootstrap
RUN ./configure
RUN make
RUN make rpm
