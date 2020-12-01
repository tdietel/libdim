dnl
dnl
dnl
dnl ------------------------------------------------------------------

AC_INIT([Distributed Information Management System], [20.07], 
        [Clara.Gaspar@cern.ch], dim)

AC_SUBST([RPM_RELEASE],[4])
AC_SUBST([IPKG_RELEASE],[3])

AC_PREREQ(2.50)
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([1.9 foreign])

# Please read the libtool manual before changing the version number! 
# http://www.gnu.org/software/libtool/manual.html#Versioning
AC_SUBST([LIB_VERSION],[1:0:0])


dnl    options for configuration
dnl    =========================

AC_DEFUN([AC_DEBUG],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_MSG_CHECKING(whether to make debug objects)
  AC_ARG_ENABLE(debug,
    [AC_HELP_STRING([--enable-debug],[Enable debugging symbols in objects])],
    [],[enable_debug=yes])
  if test "x$enable_debug" = "xno" ; then
    CFLAGS=`echo $CFLAGS | sed 's,-g,,'`
  else
    case $CFLAGS in
    *-g*) ;;
    *)    CFLAGS="$CFLAGS -g" ;;
    esac
  fi
  AC_MSG_RESULT($enable_debug 'CFLAGS=$CFLAGS')
])

dnl ------------------------------------------------------------------
AC_DEFUN([AC_OPTIMIZATION],
[
  AC_REQUIRE([AC_PROG_CC])
  AC_ARG_ENABLE(optimization,
    [AC_HELP_STRING([--enable-optimization],[Enable optimization of objects])],
    [],[enable_optimization=yes])
  AC_MSG_CHECKING(for optimiztion level)
  changequote(<<, >>)dnl
  if test "x$enable_optimization" = "xno" ; then
    CFLAGS=`echo   $CFLAGS   | sed 's,-O\([0-9][0-9]*\|\),,'`
  elif test "x$enable_optimization" = "xyes" ; then
    case $CFLAGS in
    *-O*) ;;
    *)    CFLAGS="$CXXFLAGS -O2" ;;
    esac
  else
    CFLAGS=`echo $CFLAGS | sed "s,-O\([0-9][0-9]*\|\),-O$enable_optimization,"`
  fi
  changequote([, ])dnl
  AC_MSG_RESULT($enable_optimization 'CFLAGS=$CFLAGS')
])

dnl __________________________________________________________________

dnl
dnl __________________________________________________________________
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL

dnl ------------------------------------------------------------------
AH_TEMPLATE(MIPSEB, [Big-endian machine])
AH_TEMPLATE(MIPSEL, [Little-endian machine])
AC_C_BIGENDIAN([AC_DEFINE([MIPSEB])],[AC_DEFINE([MIPSEL])])
AC_DEFINE([PROTOCOL],[1])
case $host_os:$host_cpu in
sun*)		AC_DEFINE([sunos])		;;
solaris*)       AC_DEFINE([solaris])	
		LIBS="$LIBS -lsocket -lnsl"	;;
hp-ux*)		AC_DEFINE([hpux])		;;
osf*)		AC_DEFINE([osf])		;;
aix*)		AC_DEFINE([aix])	
		AC_DEFINE([unix])
		AC_DEFINE([_BSD])		;;
lynxos*:rs6000)	AC_DEFINE([LYNXOS])	
		AC_DEFINE([RAID])
		AC_DEFINE([unix])		
		CPPFLAGS="$CPPFLAGS -I/usr/include/bsd -I/usr/include/posix"
		LDFLAGS="$LDFLAGS -L/usr/posix/usr/lib"
		LIBS="$LIBS -lbsd"		;;
lynxos*:*86*)	AC_DEFINE([LYNXOS])	
		AC_DEFINE([unix])		
		LIBS="$LIBS -lbsd -llynx"	;;
lynxos*)	AC_DEFINE([LYNXOS])	
		AC_DEFINE([unix])		
		LIBS="$LIBS -lbsd"		;;
linux*)		AC_DEFINE([linux])		
		AC_DEFINE([unix])		;;
esac

dnl __________________________________________________________________
AC_ARG_ENABLE([threads],
              [AC_HELP_STRING([--enable-threads],
                              [Make the library thread-safe])],
			      [], [enable_threads=yes])
AC_MSG_CHECKING([whether make the library thread safe])
if test ! "x$enable_threads" = "xno" ; then
   enable_threads=yes
   case $host_os:$host_cpu in
   solaris*|sun*)	   CFLAGS="$CFLAGS -mt"
			   LIBS="$LIBS -lposix4"	;;
   hp-ux*|osf*|aix*)	   enable_threads=no		;;
   linux*)		   LIBS="$LIBS -pthread"	;;
   lynxos*:rs6000)	   CFLAGS="$CFLAGS -mthreads"	;;
   *)			   LIBS="$LIBS -lpthread"	;;
   esac
fi
if test "x$enable_threads" = "xno" ; then
   AC_DEFINE([NOTHREADS])
fi
AC_MSG_RESULT([$enable_threads])



AC_ARG_ENABLE([utils],
              [AC_HELP_STRING([--enable-utils],
                              [build utility programs])],
			      [], [enable_utils=yes])
AC_MSG_CHECKING([whether to build utility programs])
AC_MSG_RESULT([$enable_utils])

AM_CONDITIONAL(BUILD_UTILS, test "x$enable_utils" = "xyes")


dnl
dnl __________________________________________________________________
AC_DEBUG
AC_OPTIMIZATION



dnl __________________________________________________________________
AC_ARG_WITH([java],
            AS_HELP_STRING( [--with-readline],
			    [specify java version to use]),
            [with_java="$withval"],
            [with_java=check])



case x$with_java in

    xyes|xcheck)
	for jdkpath in /usr/java/default/ /usr/lib/jvm/java
	do 
            if test -f $jdkpath/include/jni.h ; then use_jdk=$jdkpath; break; fi
	done
	AS_IF([test x$use_jdk != x],
	      AC_MSG_NOTICE([using Java found in $use_jdk]),)
	;;
    
    xno)  ;;

    *)    use_jdk=$with_java ;;
esac

#AC_MSG_NOTICE([found JDK in $use_jdk])

AS_IF([test x$with_java = xyes -a  x$use_jdk = x],
      AC_MSG_ERROR([no JDK found to build Java interface]),)

AS_IF([test x$use_jdk != x],
      [CPPFLAGS="$CPPFLAGS -I$use_jdk/include -I$use_jdk/include/linux"
       AC_CHECK_HEADER(jni.h,,AC_MSG_ERROR([libjdim requires Java Native Interface]))], )

AM_CONDITIONAL(BUILD_LIBJDIM, test "x$use_jdk" != "x")


dnl __________________________________________________________________


if test "x$enable_utils" = "xyes" ; then
	AC_CHECK_HEADERS(Mrm/MrmAppl.h Xm/Xm.h,, AC_MSG_ERROR([utility program DID requires Motif]))
	AC_CHECK_LIB(Mrm, main, MOTIF_LIBS="-lMrm", AC_MSG_ERROR([utility program DID requires Motif]))
  AC_CHECK_LIB(Xm, main, MOTIF_LIBS="$MOTIF_LIBS -lXm", AC_MSG_ERROR([utility program DID requires Motif]))
 	AC_CHECK_LIB(Xt, main, MOTIF_LIBS="$MOTIF_LIBS -lXt", AC_MSG_ERROR([utility program DID requires Motif]))
	AC_CHECK_LIB(X11, main, MOTIF_LIBS="$MOTIF_LIBS -lX11", AC_MSG_ERROR([utility program DID requires Motif]))

	AC_SUBST(MOTIF_LIBS)
fi

dnl __________________________________________________________________
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([ipkg/control])
AC_CONFIG_FILES([extra/Makefile])
AC_CONFIG_FILES([extra/dim.spec])
AC_CONFIG_FILES([extra/dim-config])
AC_CONFIG_FILES([extra/dim-dns])

AC_OUTPUT
dnl
dnl EOF
dnl

