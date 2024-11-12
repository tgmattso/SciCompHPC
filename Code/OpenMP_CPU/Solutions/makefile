#
#  USAGE:
#     make          ... to build the program
#     make test     ... to run the default test case
#

#  define compiler, linker, and optimization flags plus library refs
CC          = gcc-14
CLINKER     = $(CC)
LIBS        = -lm
CFLAGS      = -fopenmp
OPTFLAGS    = -std=c11 -fopenmp -O0 


EXES= hello_par pi_spmd_simple pi_spmd_final \
            pi_loop  jac_solv_par_for 

JAC_PAR_FOR_OBJS  = jac_solv_par_for.o mm_utils.o 

all: $(EXES)

jac_solv_par_for: $(JAC_PAR_FOR_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o jac_solv_par_for $(JAC_PAR_FOR_OBJS) $(LIBS)

hello_par: hello_par.o
	$(CLINKER) $(OPTFLAGS) -o hello_par hello_par.o $(LIBS)

pi_spmd_simple: pi_spmd_simple.o  
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_simple pi_spmd_simple.o $(LIBS)

pi_spmd_final: pi_spmd_final.o
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_final pi_spmd_final.o $(LIBS)

pi_loop: pi_loop.o
	$(CLINKER) $(OPTFLAGS) -o pi_loop pi_loop.o $(LIBS)


test: $(EXES)
	./hello_par
	./pi_spmd_simple
	./pi_spmd_final
	./pi_loop
	./jac_solv_par_for

clean:
	$(RM) $(EXES) *.o

.SUFFIXES:
.SUFFIXES: .c .cpp  .o

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CC) $(CFLAGS) -c $<

