/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : rq.c                                                                                            
 ** Module Name  : MAC-HS                                                                                                          
 ** Project Name : MAC-HS UE Side                                                                                                 
 ** Description  : definition of rq() function which is called by Harq.c and receive data through it.
 ** Author       : MAC-HS Project Team                                                                                            
 ** Start date   : 12-01-2013                                                                                                       
 ** End date     : 20-01-2013                                                                                                      
 */

#include"../mac_hs_include/header.h"
#include"../mac_hs_include/wrapper.h"

U32
rq ()
{
  FILE *rq;                     /* Define File pointer which used to access the file*/
  FILE *rq_reorder;             /* Define File pointer which used to access the file*/
  struct mac_hs_msg pdu;
  struct mac_hs_msg pduONE[EIGHT];
  struct mac_hs_msg temp;
  U8 buffer[HUNDRED];           /* Take character type Array & the size of array is also HUNDRED */
  U32 iterate   = ONE;          /* Define the integer Variables which is use in code */
  U32 jiterate  = ZERO;         /* Define the integer Variables which is use in code */
  U32 running   = ONE;          /* Define the integer Variables which is use in code */
  U32 msgqidONE = ZERO;         /* Declare and initialize an integer type of message queue id and iterate */
  U32 msgqidTWO = ZERO;         /* Declare and initialize an integer type of message queue id and iterate */


  nexg_printf ("\n\t\t\tMESSAGES FROM HARQ AT RQ SIDE:\n\n");
  rq = nexg_fopen ("../mac_hs_logfiles/rq.txt", "a");                   /*File from which data will be write */
#ifdef DEBUG
  nexg_fprintf (rq, "\t\nDATA CREATED ON:-%s\t\n\n", __TIMESTAMP__);    /*print date and time in file */
  nexg_fprintf (rq, "\n\t\t\t*****||||Waiting for the Data*****||||\n");
  nexg_fprintf (rq, "\n\t\t\t======>>>Data receiving started at time=%s<<<======\n", __TIME__); /*predefined macros to print the file name */
  nexg_fprintf (rq, "\n\t\t\t======>>>Data receiving started on Date=%s<<<======\n", __DATE__); /*predefined macros to print the file name */
        
        nexg_printf
         ("\t\t  ==============================================================================================\n");
      nexg_printf
        ("\t\t||                                                                                             ||\n");
      nexg_printf
        ("\t\t||                                     MESSAGE AT RQ.....                                      ||\n");
      nexg_printf
        ("\t\t||                                                                                             ||\n");
      nexg_printf
        ("\t\t ==============================================================================================\n\n");

#endif
  while (running <= SEVEN)
    {
      pdu.message_type = ZERO;  /* Giving the priority of message */

/*
 * Function: nexg_printf                                                                                                                
 * Purpose : Used for printing output                           
 * Inputs  : user dependent.                                                                                                
 * Return  : return the number of characters printed.
 */


  /*
 * System Call: nexg_msgget.                                                                                                        
 * Purpose : To create message queue.                                                                                         
 * Inputs  : KEY and msgflg.                                                                                                        
 * Return  : returns a positive number, the queue identifier, on success otherwise negative number on failure.                         
 */


      msgqidONE = nexg_msgget ((key_t) TWO, IPC_CREAT | PERMISSION);
      if (msgqidONE < ZERO)     /* if start to check return value of msgget function used above */
        {

/*
 * Function: nexg_perror                                                                                                                
 * Purpose : Print a system error message.                      
 * Inputs  : 
 * Return  :
 */
          nexg_perror ("\t\t\t\tERROR CREATING MESSAGE QUEUE\n");
        }

/*
  * System Call: nexg_msgrcv                                                                                                             
  * Purpose : To receive message from message queue.                                                        *                           
  * Inputs  : message queue identifier returned from a msgget function,pointer to the message to be sent,size of the message 
                pointed to by msg_ptr,long int message type msgflg.                         
  * Return  : On success, msgrcv returns zero,and returns negative number on error.                             
*/

      else if (nexg_msgrcv (msgqidONE, &pdu, FOURHUNDRED, ZERO, ZERO) == -ONE)
        {                       /* if start to check return value of msgrcv function used above from harq function */
          nexg_perror ("\t\t\t\tMESSAGE RECEIVE FAILED\n");
          return (ZERO);
        }

      for (iterate = ZERO; iterate < HUNDRED; iterate++)        /* receive data from Harq */
        {
          buffer[iterate] = pdu.array[iterate]; /* Assigning value in to another array */
        }
#ifdef DEBUG
#else
      nexg_printf("\t\t\t\tMessage At RQ Side\n");
      nexg_printf ("\t\t\t\tQID :%d", pdu.qid);
      nexg_printf ("\tTSN :%d\n\t\t\t\t\n\n", pdu.tsn);

      for (jiterate = ZERO; buffer[jiterate] != '\0'; jiterate++)
        {
          nexg_fprintf (rq,"%c", buffer[jiterate]);
        }
      pduONE[running] = pdu;
#endif
      running++;
      nexg_delay (ONE);
    }
  for (iterate = ZERO; iterate < SEVEN; iterate++)
    {
      msgqidTWO = nexg_msgget ((key_t) THREE, IPC_CREAT | PERMISSION);
      if (msgqidTWO < ZERO)
        {
          nexg_perror ("\t\t\t\tERROR CREATING MESSAGE QUEUE\n");
        }
      pduONE[iterate].message_type = ONE;

      rq_reorder = nexg_fopen ("../mac_hs_logfiles/rq_reorder.txt", "a");       /*File from which data will be write */
      nexg_fprintf (rq_reorder, "\t\nDATA CREATED ON:-%s\t\n\n", __TIMESTAMP__);        /*print date and time in file */
      nexg_fprintf (rq_reorder, "\n\t\t\t*****||||Data send to REORDER*****||||\n");
      nexg_fprintf (rq_reorder, "\n\t\t\t======>>>Data sendinding started at time=%s<<<======\n", __TIME__);    /*predefined macros to print the file name */
      nexg_fprintf (rq_reorder, "\n\t\t\t======>>>Data sendinging started on Date=%s<<<======\n", __DATE__);    /*predefined macros to print the file name */

/*
 * System Call: nexg_msgsnd                                                                                                             
 * Purpose : To send message into message queue.                                                                        
 * Inputs  : message queue identifier returned from a msgget function,pointer to the message to be sent,size of the message 
                pointed to by msg_ptr,msgflg.                                                                                       
 * Return  : On success, msgsnd returns zero,and returns negative number on error.
*/

      if (nexg_msgsnd (msgqidTWO, &pduONE[iterate], FOURHUNDRED, ZERO) == -ONE)
        {
          nexg_perror ("\t\t\t\tMESSAGE SEND FAILED\n");
          return (ZERO);
        }
    }
/*
  * System Call: nexg_msgctl                                                                                                     
  * Purpose : To delete message queue.                                                      *                           
  * Inputs  : Message qid, message queue delete command,and flag.                         
  * Return  : On success, nexg_msgctl returns zero,and returns negative number on error.                                        
*/
     if (nexg_fclose (rq)==-ONE)                /*close the file */
      {
        nexg_perror("\t\t\t\t\tError close to file\n");
      }
 }
    if(nexg_fclose (rq_reorder)==-ONE)
     {
        nexg_perror("\t\t\t\t\tError close to file\n");
     }
  nexg_msgctl (msgqidONE, IPC_RMID, ZERO);      /* Function used to delete message queue */
#ifdef DEBUG
#else
  nexg_printf ("\t Total no of lines in rq.c file %d\n", __LINE__);     /* predefined macros to print number of lines */
#endif
  return (ZERO);
}

/************************************************************************************************************************************
*                                              end of file rq.c                                                              *
************************************************************************************************************************************/

