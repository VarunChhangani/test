/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.
 ** File Name    : Readme.txt
 ** Module Name  : MAC-HS-STUB
 ** Project Name : MAC-HS UE Side
 ** Description  : description of Readme file in mac_hs_stub directory.
 ** Author       : MAC-HS-IN Project Team
 ** Start date   : 12-02-2013
 ** End date     : 12-02-2013
*/



                                -----------------------------------------------------------------
                                |       Relaese  3GPP TS 25.321 version 7.3.0 Release 7         |
                                |          3GPP TS 34.123-1 version 7.0.0 Release 7             |                                       |
                                -----------------------------------------------------------------

a) MAC -hs handles the HSDPA function.
b) To execute this project we used Message queue for receiving and sendind data.
c) In mac_hs_stub directory there are all the files like harq,rq,reorder,disassembly function,main file, wrapper function, make file placed.
d) In mac_hs_stub all these module run one by one means in specific order which we called function it will execute.

                                                --------------------
                                                \       STEP-1     \
                                                --------------------

e) In Harq.c function there are data has been received by send.c file which located at mac_hs_In directory,
f)   Accordiing to that Harq.c file  match the data with received data and generate the ACK,it may be POSITIVE or NEGATIVE.
g)   If received data is matched then POSITIVE ACK generated else NEGATIVE ACK and this to send.c mac_hs_IN directory.

                                                --------------------
                                                \       STEP-2     \
                                                --------------------

h) After that the data which received Harq.c file send to rq.c function which routes the MAC-hs PDUs to the correct reordering in buffer on
   QUEUE ID.
i) After that data has been send to reorder.c.

                                                --------------------
                                                \       STEP-3     \
                                                --------------------
j) Reorder.c function called after rq.c which received data from rq and it's reordering TSN in MAC-hs-PDU and reordered all the TSN.
k)  The data which received after POSITIVE ACK and Reordering Queue distribution then rearrange all the PDU TSN and QID.
l)  After that data send to Disassembly .If the MAC-hs PDU is not sent to Disassembly then lower TSN is missing.

                                                --------------------
                                                \       STEP-4     \
                                                --------------------

m) Final module is Disassembly.c in which MAC-hs header has been removed  and Padding bit has been also removed and sent to MAC-D layer.

                                                --------------------
                                                \       STEP-5     \
                                                --------------------

n) After that there are main file MAC_HS_OUT in which all function has been called.
o) All the wrapper function defination has been given in same directory and declaration at mac_hs_include directory.
p) After that we create make file via command "make".Compile the make file with make command Wall which also show hidden warnings.
q)  After compilation of make file new executable file ./MAC_HS_OUT has been created.

                                                -------------------
                                                \       STEP-6     \
                                                --------------------

r) At the execution of programme with ./MAC_HS_OUT data received from send file which located at mac_hs_release directory and send to further
   function which placed at same directory.
s) According the received data from Send.c function it's received ACk it may be POSITIVE or NEGATIVE.
t) When all the process has been completed the data with help of message queue send further to next module.
u) After that it's also checked with valgrind ./IN to check memory leakage.
v) But we did not find any leakage.
w) All the data which received or send in  mac_hs_OUT directory stored  in logfiles.
x) All the message queue has been also deleted after completion of all project.

/************************************************************************************************************************************
*                                              end of file readme.txt                                                                   *
************************************************************************************************************************************/
