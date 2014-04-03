/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.
 ** File Name    : Readme.txt
 ** Module Name  : MAC-HS-IN
 ** Project Name : MAC-HS UE Side
 ** Description  : description of Readme file in mac_hs_IN directory.
 ** Author       : MAC-HS-IN Project Team
 ** Start date   : 12-02-2013
 ** End date     : 12-02-2013
*/


                                -----------------------------------------------------------------
                                |       Relaese  3GPP TS 25.321 version 7.3.0 Release 7         |
                                |          3GPP TS 34.123-1 version 7.0.0 Release 7             |                                       |
                                -----------------------------------------------------------------


a) MAC -hs handles the HSDPA function.
b) To execute this project we used Message queue for receiving and sending data.
                                                --------------------
                                                \       STEP-1     \
                                                --------------------
c) In mac_hs_IN directory there are all the files like send function, wrapper function, make file placed.
d) In MAC - hs there are Eight process has been used and TSN is used which range vary between ZERO - EIGHT and ONE - SIXTYFOUR respectively.
e) In mac_hs_IN there are data received file in send.c function.The main thing is that we didn 't use the scanf function entire programme.
f) For the input we divide the file in many parts and after that these dividing files and made a phy_pdu.txt file which all t data which we
   want to enter has been saved after that it's sent to send.c.

                                                --------------------
                                                \       STEP-2     \
                                                --------------------

g) send.c  read the data from fread function from phy_pdu.txt.
h) All the wrapper function defination has been given in same directory and declaration at mac_hs_include directory.
i)  send.c function received data send to Harq.c file which placed at mac_hs_stub directory.
j) After that we create make file via command "make" .Compile the make file with Wall which also show hidden warnings.
k) It's create executable file ./IN .

                                                --------------------
                                                \       STEP-3     \
                                                --------------------
                                                                                                                            1,1           Top
l) Execute  of programme with. / IN data picked from logfile and send to harq function which placed at mac_hs_stub directory.
m) According the received data by Harq function we received ACK it may be POSITIVE or NEGATIVE.When all the process has been completed the
    send function has been terminated.
n) After that it's also checked with valgrind ./IN to check memory leakage.
o) But we did not find any leakage.
p) All the data which received or send in send function stored in mac_hs_logfiles directory as name of harq.txt.
q)  All the message queue has been also deleted after completion of all project.
/************************************************************************************************************************************
*                                              end of file readme.txt                                                                   *
************************************************************************************************************************************/
