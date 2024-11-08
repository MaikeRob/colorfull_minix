PROG=   colorfull
SRCS=   colorfull.c colors.c utils.c
 
FILES=${PROG}.conf
FILESNAME=${PROG}
FILESDIR= /etc/system.conf.d
 
DPADD+= ${LIBCHARDRIVER} ${LIBSYS}
LDADD+= -lchardriver -lsys
 
MAN=
 
.include <minix.service.mk>
