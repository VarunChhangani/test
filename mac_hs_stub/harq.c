/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : Harq.c                                                                                          
 ** Module Name  : MAC-HS-IN                                                                                                           
 ** Project Name : MAC-HS UE Side                                                                                                 
 ** Description  : definition of harq() function which is called by send.c file and send the acknowledgment to lower layer nad received
data send to other entity                                                                                              
 ** Author       : MAC-HS-IN Project Team                                                                                            
 ** Start date   : 12-01-2013                                                                                                       
 ** End date     : 20-01-2013                                                                                                      
 */
#include"../mac_hs_include/header.h"
#include"../mac_hs_include/wrapper.h"
U32
harq ()
{
  FILE *harq;                                   /* Define File pointer which used to access the file*/
  FILE *harq_rq;                                /* Define File pointer which used to access the file*/
  struct mac_hs_msg pdu;
//  U8 buffer [HUNDRED];
  U8 arrayONE[THIRTYFIVE] = "POSITIVE";         /* Take another character type Array & the size of array is also HUNDRED */
  U8 arrayTWO[THIRTYFIVE] = "NEGATIVE";         /* Take another character type Array & the size of array is also HUNDRED */
  U32 len         = ZERO;                       /* Define the integer Variables which is use in code */
  U32 msgqid      = ZERO;                       /* Declare and initialize an integer type of message queue id and iterate */
  U32 msgqidONE   = ZERO;                       /* Declare and initialize an integer type of message queue id and iterate */
  U32 msgqidTHREE = ZERO;                       /* Declare and initialize an integer type of message queue id and iterate */
  U32 running     = ONE;                        /* Define the integer Variables which is use in code */
/*
 * Function: nexg_printf                                                                                                                
 * Purpose : Used for printing output                           
 * Inputs  : user dependent.                                                                                                
 * Return  : return the number of characters printed.
 */

  nexg_printf ("\t\t\t\tMESSAGES FROM LOWER LAYER AT MAC_HS SIDE:\n\n");

  harq = nexg_fopen ("../mac_hs_logfiles/harq.txt", "a");       /*File from which data will be write */
  nexg_fprintf (harq, "\t\nDATA CREATED ON:-%s\t\n\n", __TIMESTAMP__);  /*print date and time in file */
#ifdef DEBUG
      nexg_printf
        ("\t\t ==============================================================================================\n");
      nexg_printf
        ("\t\t||                                                                                             ||\n");
      nexg_printf
        ("\t\t||                                     MESSAGE AT HARQ.....                                    ||\n");
      nexg_printf
        ("\t\t||                                                                                             ||\n");
      nexg_printf
        ("\t\t ==============================================================================================\n\n");
#endif
  while (running <= EIGHT)
    {
      pdu.message_type = ZERO;  /* Giving the priority of message */
      nexg_fprintf (harq, "\n\t\t\t*****||||Waiting for the Data*****||||\n");
      nexg_fprintf (harq, "\n\t\t\t======>>>Data receiving started at time=%s<<<======\n", __TIME__);   /*predefined macros to print the file name */
      nexg_fprintf (harq, "\n\t\t\t======>>>Data receiving started on Date=%s<<<======\n", __DATE__);   /*predefined macros to print the file name */

/*
 * System Call: nexg_msgget.                                                                                                        
 * Purpose : To create message queue.                                                                                         
 * Inputs  : KEY and msgflg.                                                                                                        
 * Return  : returns a positive number, the queue identifier, on success otherwise negative number on failure.                         
*/
      msgqid = nexg_msgget ((key_t) ONE, IPC_CREAT | PERMISSION);       /* get a message queue identifier */
      if (msgqid < ZERO)        /* if start to check return value of msgget function used above */
        {

/*
 * Function: nexg_perror                                                                                                                
 * Purpose : Print a system error message.                      
 * Inputs  :                                                                                                
 * Return  :
                                                                                                                             39,1          21%
 nexg_perror ("\t\t\t\tERROR CREATING MESSAGE QUEUE\n");
        }

/*
  * System Call: nexg_msgrcv                                                                                                             
  * Purpose : To receive message from message queue.                                                        *                           
  * Inputs  : message queue identifier returned from a msgget function,pointer to the message to be sent,size of the message 
                pointed to by msg_ptr,long int message type msgflg.                         
  * Return  : On success, msgrcv returns zero,and returns negative number on error.                                             
*/

      else if (nexg_msgrcv (msgqid, &pdu, FOURHUNDRED, ZERO, ZERO) == -ONE)     /*to receive message from physical entity */
        {
          nexg_perror ("\t\t\t\tMESSAGE RECEIVE FAILED\n");

/*
 * Function: Return                                                                                                                     
 * Purpose : Cause normal process termination.                          
 * Inputs  :                                                                                                
 * Return  : Return function return ONE on Successful .
*/
          return (ZERO);
        }

      msgqidONE = nexg_msgget ((key_t) TWO, IPC_CREAT | PERMISSION);    /* get a message queue identifier */
      if (msgqidONE < ZERO)     /* if start to check return value of msgget function used above */
        {
          nexg_perror ("\t\t\t\tERROR CREATING MESSAGE QUEUE\n");
        }
      if ((pdu.qid >= ONE && pdu.qid <= EIGHT)
          && (pdu.tsn >= ONE && pdu.tsn <= SIXTYFOUR))
        {
          pdu.message_type = ONE;       /* Giving the priority of message */
#ifdef DEBUG
#else

          nexg_printf ("\t\t\t\tQID is: %d", pdu.qid);
          nexg_printf ("\tTSN is: %d\n\t\t\t\t", pdu.tsn);
                     for (running = ZERO; running < HUNDRED; running++)    /* Take the 100 times iteration in for loop */
            {
             /// buffer[running] = pdu.array[running];
                nexg_fprintf (harq,"%c",pdu.array[running]);
            }
#endif
           harq_rq = nexg_fopen ("../mac_hs_logfiles/harq_rq.txt", "a");        /*File from which data will be write */
          nexg_fprintf (harq_rq, "\t\nDATA CREATED ON:-%s\t\n\n", __TIMESTAMP__);       /*print date and time in file */
          nexg_fprintf (harq_rq,"\n\t\t\t*****||||Data send to RQ*****||||\n");
          nexg_fprintf (harq_rq, "\n\t\t\t======>>>Data sendinding started at time=%s<<<======\n", __TIME__);   /*predefined macros to print the file name */
          nexg_fprintf (harq_rq, "\n\t\t\t======>>>Data sendinging started on Date=%s<<<======\n", __DATE__);   /*predefined macros to print the file name */


/*
 * System Call: nexg_msgsnd                                                                                                             
 * Purpose : To send message into message queue.                                                                        
 * Inputs  : message queue identifier returned from a msgget function,pointer to the message to be sent,size of the message 
                pointed to by msg_ptr,msgflg.                                                                                       
 * Return  : On success, msgsnd returns zero,and returns negative number on error.
*/
          if (nexg_msgsnd (msgqidONE, &pdu, FOURHUNDRED, ZERO) == -ONE)
            {
              nexg_perror ("\t\t\t\tMESSAGE SEND FAILED\n");
            }
#ifdef DEBUG
#else
//               puts (buffer);
#endif
                 nexg_delay(ONE);
        }
      if ((pdu.qid >= ONE && pdu.qid <= EIGHT)
          && (pdu.tsn >= ONE && pdu.tsn <= SIXTYFOUR))
        {
          msgqidTHREE = nexg_msgget ((key_t) SIX, IPC_CREAT | PERMISSION);
          if (msgqidTHREE < ZERO)
            {
                                                                                                                                111,1-8       
{
              nexg_perror ("\t\t\t\tERROR CREATING MESSAGE QUEUE\n");
            }
          len = nexg_strlen (arrayONE);
          if (nexg_msgsnd (msgqidTHREE, &arrayONE, len, ZERO) == -ONE)
            {
              nexg_perror ("\t\t\t\tMESSAGE SEND FAILED\n");
              return (ZERO);
            }
        }
      else
        {
          msgqidTHREE = nexg_msgget ((key_t) SIX, IPC_CREAT | PERMISSION);      /* get a message queue identifier */
          if (msgqidTHREE < ZERO)
            {
            nexg_perror ("\t\t\t\tERROR CREATING MESSAGE QUEUE\n");
            }
           len = nexg_strlen (arrayTWO);
          if (nexg_msgsnd (msgqidTHREE, &arrayTWO, len, ZERO) == -ONE)
            {
              nexg_perror ("\t\t\t\tMESSAGE SEND FAILED\n");
              return (ZERO);
            }
          nexg_printf ("NEGETIVE ACKWNOWLEDGEMENT SENT TO LOWER LAYER\n");
        }
      running++;
    }

/*
  * System Call: nexg_msgctl                                                                                                     
  * Purpose : To delete message queue.                                                      *                           
  * Inputs  : Message qid, message queue delete command,and flag.                         
  * Return  : On success, nexg_msgctl returns zero,and returns negative number on error.                 
*/
 if(nexg_fclose(harq)==-ONE)            /*close the file */
  {
        nexg_perror("\t\t\t\t\tError close to file\n");
  }
if(nexg_fclose (harq_rq)==-ONE)
   {
        nexg_perror("\t\t\t\t\tError close to file\n");
   }
  nexg_msgctl (msgqid, IPC_RMID, ZERO); /* Function used to delete message queue */
#ifdef debug 
  nexg_printf ("\t Total no of lines in harq.c file %d\n", __LINE__);   /* predefined macros to print number of lines */
#else
#endif
return (ZERO);
}


/************************************************************************************************************************************
*                                              harq.c                                                                            *
**************************************************************************************************************************************/
                                                                                                                             200,1         Bot


