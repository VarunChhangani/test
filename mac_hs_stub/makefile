#All rights reserved – Nex-G Exuberant Solutions Private Limited.
 #File Name   : makefile
 #Module Name : Makefile for MAC_HS.
 #Project Name: MAC_HS for UE side.
 #Author      : MAC_HS Project Team
 #Start date  : 25-01-2013
 #End date    : 25-01-2013

# ":" used for dependency;
# All is used to all programmes which belonging to project and make executable file.
all:     MAC_HS_OUT
# CC will replaced by `ec++'. make has a number of built-in variables and default values and Wall used for all warnings.
CC       = gcc -Wall
# All .obj files have dependencies of all .c files of the same name  and it's turn on optimization so that program  can runs faster and 
#options which relate to optimization or debugging.
CFLAGS   = -g
# Target that ends in `.o' always be dependent on `.c'.and in below target are specified as per '.o.' file respectively. 
OBJECT   = MAC_HS.o
OBJECT1  = harq.o
OBJECT2  = rq.o
OBJECT3  = reorder.o
OBJECT4  = disassembly.o
OBJECT5  = nexg_printf.o
OBJECT6  = nexg_fopen.o
OBJECT7  = nexg_fclose.o
OBJECT8  = nexg_fprintf.o
OBJECT9  = nexg_msgget.o
OBJECT10 = nexg_msgsnd.o
OBJECT11 = nexg_msgrcv.o
OBJECT12 = nexg_msgctl.o
OBJECT13 = nexg_fread.o
OBJECT14 = nexg_perror.o
OBJECT15 = nexg_delay.o
OBJECT16 = nexg_strlen.o



MAIN            = MAC_HS.c              # In .c file all the '.o' file has required source code which all the source code has been defined ac                                           cording to target Respectiviley.
MAC_HARQ        = harq.c
MAC_RQ          = rq.c
MAC_REORDER     = reorder.c
MAC_DISASSEMBLY = disassembly.c
PERROR          = nexg_perror.c
PRINTF          = nexg_printf.c
FOPEN           = nexg_fopen.c
FCLOSE          = nexg_fclose.c
FPRINTF         = nexg_fprintf.c
MSGGET          = nexg_msgget.c
MSGSND          = nexg_msgsnd.c
MSGRCV          = nexg_msgrcv.c
MSGCTL          = nexg_msgctl.c
FREAD           = nexg_fread.c
DELAY           = nexg_delay.c
STRLEN          = nexg_strlen.c



#EXECUTABLE FILE(MAC_HS_OUT)
#make executable file according to the objects or target and their dependencies.

MAC_HS_OUT: $(OBJECT) $(OBJECT1) $(OBJECT2) $(OBJECT3) $(OBJECT4) $(OBJECT5) $(OBJECT6) $(OBJECT7) $(OBJECT8) $(OBJECT9) $(OBJECT10) $(OBJECT11) $(OBJECT12) $(OBJECT13) $(OBJECT14) $(OBJECT15) $(OBJECT16)
	$(CC) -o ../mac_hs_release/MAC_HS_OUT $(MAIN) $(MAC_HARQ) $(MAC_RQ) $(MAC_REORDER) $(MAC_DISASSEMBLY) $(PRINTF) $(FOPEN) $(FCLOSE)  $(FPRINTF) $(MSGGET) $(MSGSND) $(MSGRCV) $(MSGCTL) $(FREAD)  $(PERROR) $(DELAY) $(STRLEN)

 #OBJECT FILES 
# It's include all object file according to target and dependency and make single executable file.
MAC_HS.o: $(MAIN)        ../mac_hs_include/header.h  ../mac_hs_include/wrapper.h
	$(CC) -c $(MAIN) $(CFLAGS)
# There are path header file and wrapper function has been given according to their file or function.
harq.o: $(MAC_HARQ)      ../mac_hs_include/header.h ../mac_hs_include/wrapper.h
rq.o: $(MAC_RQ)          ../mac_hs_include/header.h ../mac_hs_include/wrapper.h
	$(CC) -c $(MAC_RQ) $(CFLAGS)
reorder.o: $(MAC_REORDE) ../mac_hs_include/header.h ../mac_hs_include/wrapper.h
	$(CC) -c $(MAC_REORDER) $(CFLAGS)
disassembly.o: $(MAC_DISASSEMBLY) ../mac_hs_include/header.h ../mac_hs_include/wrapper.h
	$(CC) -c $(MAC_DISASSEMBLY) $(CFLAGS)
nexg_perror.o: $(PERROR) ../mac_hs_include/wrapper.h
	$(CC) -c $(PERROR) $(CFLAGS)
nexg_fread.o: $(FREAD)   ../mac_hs_include/wrapper.h
	$(CC) -c $(FREAD) $(CFLAGS)
nexg_printf.o: $(PRINTF) ../mac_hs_include/wrapper.h
	$(CC) -c $(PRINTF) $(CFLAGS)
nexg_fopen.o: $(FOPEN)   ../mac_hs_include/wrapper.h
	$(CC) -c $(FOPEN) $(CFLAGS)
nexg_fclose.o: $(FCLOSE) ../mac_hs_include/wrapper.h
	$(CC) -c $(FCLOSE) $(CFLAGS)
nexg_msgget.o: $(MSGGET) ../mac_hs_include/wrapper.h
	$(CC) -c $(MSGGET) $(CFLAGS)
nexg_msgsnd.o: $(MSGSND) ../mac_hs_include/wrapper.h
	$(CC) -c $(MSGSND) $(CFLAGS)
nexg_fprintf.o: $(FPRINTF) ../mac_hs_include/wrapper.h
	$(CC) -c $(FPRINTF) $(CFLAGS)
nexg_msgrcv.o: $(MSGRCV) ../mac_hs_include/wrapper.h
	$(CC) -c $(MSGRCV) $(CFLAGS) 
nexg_msgctl.o: $(MSGCTL) ../mac_hs_include/wrapper.h
	$(CC) -c $(MSGCTL) $(CFLAGS) 
nexg_delay.o: $(DELAY)   ../mac_hs_include/wrapper.h
	$(CC) -c $(DELAY) $(CFLAGS)
nexg_strlen.o: $(STRLEN)   ../mac_hs_include/wrapper.h
	$(CC) -c $(STRLEN) $(CFLAGS)



 #CLEAN THE OBJECT FILE

# Used to clean all the object files.
clean:
	rm -rf $(OBJECT) $(OBJECT1) $(OBJECT2) $(OBJECT3) $(OBJECT4) $(OBJECT5) $(OBJECT6) $(OBJECT7) $(OBJECT8) $(OBJECT9) $(OBJECT10) $(OBJECT11) $(OBJECT12) $(OBJECT14) $(OBJECT15) $(OBJECT16)



#/*************************************************************************************************************************************
#*                                               end of makefile                                                                      *
#************************************************************************************************************************************/
