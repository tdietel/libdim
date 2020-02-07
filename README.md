
DIM for the ALICE TRD
=====================

This repository contains [DIM] libraries and executables as they are used by the
ALICE TRD Detector on Linux computers and DCS boards. The code should be
identical to the upstream sources, but the build systems has been converted to
the autotools (autconf, automake, libtool) to facilitate the building of RPMs
for RedHat-based Linux systems and ipkg files for DCS boards.

The build system was based on previous work by [Christian Holm][NBI]. This
repository was hosted in [Heidelberg][HD] for many years, and has now been
migrated to Git.

Prerequisites
-------------

The prerequisites are the same as for the normal DIM packages. The most exotic dependency is probably Motif (or the open source version lesstif).

Build process
-------------

As the system uses the autotools, three commands should be sufficent to build the software:
```
./bootstrap
./configure
make
```

The configure script supports the usual autoconf options, use `./configure
--help` for more information.

Once compiled, you can optionally install the software in your local system:
```
make install
```

Building of RPM packages should be as simple as
```
make rpm
```

### DCS board packages

The package also includes support for building an ipkg. If the ipkg-utils and
fakeroot are installed, this can be done by executing `fakeroot
ipkg-buildpackage` after bootstrapping and configuring the package.

DIM Versions
------------

This directory will follow the upstream DIM versions very loosely, most upstream
releases will be skipped. To update to a new version of DIM, it should be
sufficient to copy the src/ and dim/ subdirectories from the .zip file to this
directory, change the version number in configure.ac and recompile.



[DIM]: https://dim.web.cern.ch
[NBI]: http://fmd.nbi.dk/fmd/fee/dim/
[HD]: https://alice.physi.uni-heidelberg.de/svn/trd/libdim/

### CI 

This repository is configured to run a CI build process on any commits to master branch. The building will be done on either a centos6 or centos7 Docker image depending on what is selected in the .gitlab-ci.yaml file. This will build Dim as well as the rpm packages which are automatically deployed to the http://alicetrd.web.cern.ch yum repository which is held on the CERN EOS drive.
