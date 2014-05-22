############################################################################3
# Makefile to create spectcl programs for experiments 03034 & 05028
# version 3.0-gcc3.x
# J.Pereira 8/29/2005
############################################################################3
#INSTDIR=/usr/opt/spectcl/3.0-gcc3.x
INSTDIR=/usr/opt/spectcl/current
include $(INSTDIR)/etc/SpecTcl_Makefile.include


#  If you have any switches that need to be added to the default c++ compilation
# rules, add them to the definition below:

USERCXXFLAGS=

#  If you have any switches you need to add to the default c compilation rules,
#  add them to the defintion below:

USERCCFLAGS=$(USERCXXFLAGS)

#  If you have any switches you need to add to the link add them below:

USERLDFLAGS= -ltk -ltcl -lSM -lICE

#
#   Append your objects to the definitions below:
#

OBJECTS=SpecTcl.o Unpacker.o \
#  Calibrator.o Threshold.o Correlator.o

#
#  Finally the makefile targets.
#


SpecTcl: $(OBJECTS)
	$(CXXLD)  -o  SpecTcl $(OBJECTS) $(USERLDFLAGS) \
	$(LDFLAGS) 


clean:
	rm -f $(OBJECTS) SpecTcl

depend:
	makedepend $(USERCXXFLAGS) *.cpp *.c

help:
	echo "make                 - Build customized SpecTcl"
	echo "make clean           - Remove objects from previous builds"
	echo "make depend          - Add dependencies to the Makefile. "
# DO NOT DELETE

Calibrator.o: /usr/include/math.h /usr/include/features.h
Calibrator.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
Calibrator.o: /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h
Calibrator.o: /usr/include/bits/mathcalls.h Parameters.h Variables.h
Calibrator.o: Calibrator.h /usr/include/unistd.h
Calibrator.o: /usr/include/bits/posix_opt.h /usr/include/bits/types.h
Calibrator.o: /usr/include/bits/wordsize.h /usr/include/bits/typesizes.h
Calibrator.o: /usr/include/bits/confname.h /usr/include/getopt.h
Calibrator.o: /usr/include/sys/types.h /usr/include/time.h
Calibrator.o: /usr/include/endian.h /usr/include/bits/endian.h
Calibrator.o: /usr/include/sys/select.h /usr/include/bits/select.h
Calibrator.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
Calibrator.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
Calibrator.o: /usr/include/bits/sched.h /usr/include/sys/stat.h
Calibrator.o: /usr/include/bits/stat.h /usr/include/fcntl.h
Calibrator.o: /usr/include/bits/fcntl.h
Correlator.o: /usr/include/math.h /usr/include/features.h
Correlator.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
Correlator.o: /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h
Correlator.o: /usr/include/bits/mathcalls.h Parameters.h Variables.h
Correlator.o: Correlator.h
SpecTcl.o: /usr/include/stdio.h /usr/include/features.h
SpecTcl.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
SpecTcl.o: /usr/include/bits/types.h /usr/include/bits/wordsize.h
SpecTcl.o: /usr/include/bits/typesizes.h /usr/include/libio.h
SpecTcl.o: /usr/include/_G_config.h /usr/include/wchar.h
SpecTcl.o: /usr/include/bits/wchar.h /usr/include/gconv.h
SpecTcl.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
SpecTcl.o: SpecTcl.h Unpacker.h Parameters.h Variables.h P.h V.h
Threshold.o: /usr/include/math.h /usr/include/features.h
Threshold.o: /usr/include/sys/cdefs.h /usr/include/gnu/stubs.h
Threshold.o: /usr/include/bits/huge_val.h /usr/include/bits/mathdef.h
Threshold.o: /usr/include/bits/mathcalls.h Parameters.h Variables.h
Threshold.o: Threshold.h
Unpacker.o: Parameters.h Unpacker.h
