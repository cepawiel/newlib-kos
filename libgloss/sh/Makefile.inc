multilibtool_DATA += \
	%D%/kos-dreamcast.specs \
	%D%/crt0.o \
	%D%/kos-dreamcast.ld

multilibtool_LIBRARIES += %D%/libgloss.a
%C%_libgloss_a_CPPFLAGS = -I$(srcdir)/%D%
%C%_libgloss_a_SOURCES = \
	%D%/kos-syscalls.c \
	%D%/crt0.S
