## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = espaceclient

espaceclient_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	users.c users.h \
	Hotels.c Hotels.h \
	vols.c vols.h \
	voiture.c voiture.h \
	sejours.c sejours.h \
	coordonnees.c coordonnees.h \
	cordvoiture.c cordvoiture.h \
	cordvol.c cordvol.h \
	cordsejours.c cordsejours.h \
	profile.c profile.h \
	rec.c rec.h \
	hist_hotels.c hist_hotels.h

espaceclient_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

