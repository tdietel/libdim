
SUBDIRS = extra

#
#
#
#AUTOMAKE_OPTIONS        =  foreign
#ACLOCAL_AMFLAGS         =  -I .
AM_CPPFLAGS		= -I$(srcdir)/dim
# EXTRA_DIST		=  Release-Notes/license.gpl	\
# 			   Release-Notes/readme.txt	\
# 			   Release-Notes/README_v9.txt	\
# 			   Release-Notes/README_v10.txt	\
# 			   Release-Notes/README_v11.txt	\
# 			   Release-Notes/README_v12.txt	      

#dist_noinst_DATA =	dim.spec



if BUILD_LIBJDIM
lib_LTLIBRARIES	= 	libdim.la libjdim.la
else
lib_LTLIBRARIES	= 	libdim.la 
endif

if BUILD_UTILS
bin_PROGRAMS =		dim_get_service \
			dim_send_command \
			dim_check_dns \
			dim_check_servers \
			dim_bridge \
			dim_did

sbin_PROGRAMS =		dim_dns

endif

#bin_SCRIPTS = 		dim-config


pkginclude_HEADERS =	dim/dic.h \
			dim/dim.h \
			dim/dim_common.h \
			dim/dis.h \
			dim/dic.hxx \
			dim/dim.hxx \
			dim/dim_core.hxx \
			dim/dis.hxx \
			dim/dllist.hxx \
			dim/sllist.hxx \
			dim/tokenstring.hxx \
			dim/dim_jni.h

dist_noinst_HEADERS =	dim/dim_tcpip.h \
			dim/dim_core.hxx \
			src/did/did.h \
			src/did/dui_colors.h \
			src/did/dui_util.h

if BUILD_UTILS
dim_dns_SOURCES	=  src/dns.c
dim_dns_LDADD	=  libdim.la

dim_did_SOURCES	 =  src/did/did.c src/did/dui_util.c
dim_did_CPPFLAGS =  -I$(srcdir)/src/did -I$(srcdir)/dim -I/usr/X11R6/include
dim_did_LDADD	 =  libdim.la -L/usr/X11R6/lib/ -lMrm

dim_get_service_SOURCES         =  src/util/dim_get_service.c
dim_get_service_LDADD           =  libdim.la

dim_send_command_SOURCES        =  src/util/dim_send_command.c
dim_send_command_LDADD          =  libdim.la

dim_check_dns_SOURCES           =  src/util/check_dns.cxx
dim_check_dns_LDADD             =  libdim.la

dim_check_servers_SOURCES	=  src/util/check_dim_servers.cxx
dim_check_servers_LDADD		=  libdim.la

dim_bridge_SOURCES              =  src/util/dimbridge.cxx
dim_bridge_LDADD                =  libdim.la
endif

libdim_la_SOURCES =	src/dic.c \
                        src/dis.c \
			src/dna.c \
			src/sll.c \
			src/dll.c \
			src/hash.c \
			src/swap.c \
			src/copy_swap.c \
			src/open_dns.c \
			src/conn_handler.c \
			src/tcpip.c \
			src/dtq.c \
			src/dim_thr.c \
			src/utilities.c \
			src/diccpp.cxx \
			src/discpp.cxx \
			src/dimcpp.cxx \
			src/tokenstring.cxx

libdim_la_LDFLAGS = -version-info $(LIB_VERSION)

libjdim_la_SOURCES =	src/dic.c \
                        src/dis.c \
			src/dna.c \
			src/sll.c \
			src/dll.c \
			src/hash.c \
			src/swap.c \
			src/copy_swap.c \
			src/open_dns.c \
			src/conn_handler.c \
			src/tcpip.c \
			src/dtq.c \
			src/dim_thr.c \
			src/utilities.c \
			src/diccpp.cxx \
			src/discpp.cxx \
			src/dimcpp.cxx \
			src/tokenstring.cxx \
			src/dim_jni.c

libjdim_la_LDFLAGS = -version-info $(LIB_VERSION)


.PHONY: rpm
rpm:
	make dist
	rpmbuild -ta $(PACKAGE)-$(VERSION).tar.gz

#libdim_la_CPPFLAGS = -I$(srcdir)/dim
#
# EOF
#
