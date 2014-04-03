#All rights reserved – Nex-G Exuberant Solutions Private Limited.
 #File Name   : makefile
 #Module Name : Makefile for UMI.
 #Project Name: MAC-HS for UE side.
 #Author      : MAC-HS-IN Project Team
 #Start date  : 20-01-2013
 #End date    : 02-02-2013


# ":" used for dependency;
# All is used to all programmes which belonging to project and make executable file.
all:    IN
# CC will replaced by `ec++'. make has a number of built-in variables and default values and Wall used for all warnings.
CC      = gcc -Wall
# All .obj files have dependencies of all .c files of the same name  and it's turn on optimization so that program  can runs faster and 
#options which relate to optimization or debugging.
CFLAGS  = -g
# Target that ends in `.o' always be dependent on `.c'.and in below target are specified as per '.o.' file respectively. 
OBJECT  = send.o
OBJECT1 = nexg_printf.o
OBJECT2 = nexg_fopen.o
OBJECT3 = nexg_fclose.o
OBJECT4 = nexg_fprintf.o
OBJECT5 = nexg_msgget.o
OBJECT6 = nexg_msgsnd.o
OBJECT7 = nexg_msgrcv.o
OBJECT8 = nexg_msgctl.o
OBJECT9 = nexg_fread.o
OBJECT10= nexg_perror.o
OBJECT11= nexg_strncmp.o
OBJECT12= nexg_delay.o
OBJECT13= nexg_strlen.o




MAIN    = send.c                # In .c file all the '.o' file has required source code which all the source code has been defined ac                                           cording to target Respectiviley.
PERROR  = nexg_perror.c
PRINTF  = nexg_printf.c
FOPEN   = nexg_fopen.c
FCLOSE  = nexg_fclose.c
FPRINTF = nexg_fprintf.c
MSGGET  = nexg_msgget.c
MSGSND  = nexg_msgsnd.c
MSGRCV  = nexg_msgrcv.c
MSGCTL  = nexg_msgctl.c
FREAD   = nexg_fread.c
STRNCMP = nexg_strncmp.c
DELAY   = nexg_delay.c
STRLEN  = nexg_strlen.c



#EXECUTABLE FILE(IN)
#make executable file according to the objects or target and their dependencies.

IN: $(OBJECT)  $(OBJECT1) $(OBJECT2) $(OBJECT3) $(OBJECT4) $(OBJECT5) $(OBJECT6) $(OBJECT7) $(OBJECT8) $(OBJECT9) $(OBJECT10) $(OBJECT11) $(OBJECT12) $(OBJECT13)
	$(CC) -o  ../mac_hs_release/IN $(MAIN) $(PRINTF) $(FOPEN) $(FCLOSE) $(FPRINTF) $(MSGGET) $(MSGSND) $(MSGRCV) $(MSGCTL) $(FREAD) $(PERROR) $(STRNCMP) $(DELAY) $(STRLEN)

#OBJECT FILES 
# It's include all object file according to target and dependency and make single executable file. 

harq.o: $(MAIN)  ../mac_hs_include/header.h ../mac_hs_include/wrapper.h
	$(CC) -c $(MAIN) $(CFLAGS)
# There are path header file and wrapper function has been given according to their file or function.
nexg_perror.o: $(PERROR) ../mac_hs_include/wrapper.h
	$(CC) -c $(PERROR) $(CFLAGS)
nexg_fread.o: $(FREAD) ../mac_hs_include/wrapper.h
	$(CC) -c $(FREAD) $(CFLAGS)
nexg_printf.o: $(PRINTF) ../mac_hs_include/wrapper.h
	$(CC) -c $(PRINTF) $(CFLAGS)
nexg_fopen.o: $(FOPEN) ../mac_hs_include/wrapper.h
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
nexg_strncmp.o: $(STRNCMP) ../mac_hs_include/wrapper.h
	$(CC) -c $(STRNCMP) $(CFLAGS)
nexg_delay.o: $(DELAY) ../mac_hs_include/wrapper.h
	$(CC) -c $(DELAY) $(CFLAGS)
nexg_strlen.o: $(STRLEN) ../mac_hs_include/wrapper.h
	$(CC) -c $(STRLEN) $(CFLAGS)



 #CLEAN THE OBJECT FILE
# Used to clean all the object files.

clean:
		rm -rf $(OBJECT) $(OBJECT1) $(OBJECT2) $(OBJECT3) $(OBJECT4) $(OBJECT5) $(OBJECT6) $(OBJECT7) $(OBJECT8) $(OBJECT9) $(OBJECT10) $(OBJECT11) $(OBJEACT12) $(OBJECT13)

#************************************************************************************************************************************
#                                 *                end of file MAKEFILE                        *
#*************************************************************************************************************************************


