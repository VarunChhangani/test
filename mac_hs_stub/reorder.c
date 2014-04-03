*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : Reordering.c                                                                                            
 ** Module Name  : MAC-HS-IN                                                                                                           
 ** Project Name : MAC-HS UE Side                                                                                                 
 ** Description  : definition of reordering() function which is called by rq.c file,reorder the data and send to other entity.                                                                                                                   
 ** Author       : MAC-HS-IN Project Team                                                                                            
 ** Start date   : 12-01-2013                                                                                                       
 ** End date     : 20-01-2013                                                                                                      
 */


#include"../mac_hs_include/header.h"
#include"../mac_hs_include/wrapper.h"
U32
reorder ()
{
  FILE *reorder;                /* Define File pointer which used to access the file*/
  FILE *reorder_dis;            /* Define File pointer which used to access the file*/
  struct mac_hs_msg pdu;
  struct mac_hs_msg pduONE[EIGHT];
  struct mac_hs_msg temp;
  U8 buffer[HUNDRED];           /* Take character type Array & the size of array is also HUNDRED */
  U32 iterate   = ONE;          /* Define the integer Variables which is use in code */
  U32 jiterate  = ZERO;         /* Define the integer Variables which is use in code */
  U32 running   = ONE;          /* Define the integer Variables which is use in code */
  U32 msgqidONE = ZERO;         /* Declare and initialize an integer type of message queue id and iterate */
  U32 msgqidTWO = ZERO;         /* Declare and initialize an integer type of message queue id and iterate */

/*
 * Function: nexg_printf                                                                                                                
 * Purpose : Used for printing output                           
 * Inputs  : user dependent.                                                                                                
 * Return  : return the number of characters printed.
 */
  reorder = nexg_fopen ("../mac_hs_logfiles/reorder.txt", "a"); /*File from which data will be write */
#ifdef DEBUG
  nexg_fprintf (reorder, "\t\nDATA CREATED ON:-%s\t\n\n", __TIMESTAMP__);       /*print date and time in file */
  nexg_fprintf (reorder, "\n\t\t\t*****||||Waiting for the Data*****||||\n");
  nexg_fprintf (reorder, "\n\t\t\t======>>>Data receiving started at time=%s<<<======\n", __TIME__);    /*predefined macros to print the file name */
  nexg_fprintf (reorder, "\n\t\t\t======>>>Data receiving started on Date=%s<<<======\n", __DATE__);    /*predefined macros to print the file name */
  nexg_printf
    ("\t\t ==============================================================================================\n");
  nexg_printf
    ("\t\t||                                                                                             ||\n");
  nexg_printf
    ("\t\t||                                     MESSAGE AT REORDER.....                                 ||\n");
  nexg_printf
    ("\t\t||                                                                                             ||\n");
  nexg_printf
    ("\t\t ==============================================================================================||\n");
#endif
  while (running <= EIGHT)
    {
      pdu.message_type = ZERO;  /* Giving the priority of message */

/*
 * System Call: nexg_msgget.                                                                                                        
 * Purpose : To create message queue.                                                                                         
 * Inputs  : KEY and msgflg.                                                                                                        
 * Return  : returns a positive number, the queue identifier, on success otherwise negative number on failure.                         
 */

      msgqidONE = nexg_msgget ((key_t) THREE, IPC_CREAT | PERMISSION);
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
  * Purpose : To receive message from message queue.                                                                                    
  * Inputs  : message queue identifier returned from a msgget function,pointer to the message to be sent,size of the message 
                pointed to by msg_ptr,long int message type msgflg.                         
  * Return  : On success, msgrcv returns zero,and returns negative number on error.                                             
*/
      else if (nexg_msgrcv (msgqidONE, &pdu, FOURHUNDRED, ZERO, ZERO) == -ONE)
        {
          nexg_perror ("\t\t\t\tMESSAGE RECEIVE FAILED\n");
          return (ZERO);                /* if start to check return value of msgrcv function used above from rq function */
        }

      for (iterate = ZERO; iterate < HUNDRED; iterate++)
        {
          buffer[iterate] = pdu.array[iterate]; /* Assigning value in to another array */
        }
#ifdef DEBUG 
#else
      nexg_printf ("\t\t\t\tQID: %d", pdu.qid);
      nexg_printf ("\tTSN: %d\n\t\t\t\t\n\n", pdu.tsn); /* used to print receive value */

      for (jiterate = ZERO; buffer[jiterate] != '\0'; jiterate++)
        {
          nexg_fprintf (reorder,"%c",buffer[jiterate]);
        }
#endif
      pduONE[running] = pdu;
      running++;

      nexg_delay (ONE);
    }
                                                                                                                             109,1         51%
for (iterate = ZERO; iterate <=EIGHT; iterate++)
    {
      for (jiterate = ZERO; jiterate <= EIGHT - iterate; jiterate++)    /* Condition to check the reordering the data */
        {
          if (pduONE[jiterate].tsn > pduONE[jiterate + ONE].tsn)
            {
              temp = pduONE[jiterate];
              pduONE[jiterate] = pduONE[jiterate + ONE];
              pduONE[jiterate + ONE] = temp;
            }
        }
    }
  for (iterate = ZERO; iterate <=EIGHT; iterate++)
    {
      msgqidTWO = nexg_msgget ((key_t) FOUR, IPC_CREAT | PERMISSION);
      if (msgqidTWO < ZERO)     /* if start to check return value of msgget function used above */
        {
          nexg_perror ("\t\t\t\tERROR CREATING MESSAGE QUEUE\n");
        }
      pduONE[iterate].message_type = ONE;
      reorder_dis = nexg_fopen ("../mac_hs_logfiles/reorder_dis.txt", "a");             /*File from which data will be write */
      nexg_fprintf (reorder_dis, "\t\nDATA CREATED ON:-%s\t\n\n", __TIMESTAMP__);       /*print date and time in file */
      nexg_fprintf (reorder_dis,
                    "\n\t\t\t*****||||Data send to DISASSEMBLY*****||||\n");
      nexg_fprintf (reorder_dis, "\n\t\t\t======>>>Data sendinding started at time=%s<<<======\n", __TIME__);   /*predefined macros to print the file name */
      nexg_fprintf (reorder_dis, "\n\t\t\t======>>>Data sendinging started on Date=%s<<<======\n", __DATE__);   /*predefined macros to print the file name */


/*
 * System Call: nexg_msgsnd                                                                                                                
 * Purpose : To send message into message queue.                                                                        
 * Inputs  : message queue identifier returned from a msgget function, pointer to the message to be sent,size of the message pointed to by                   msg_ptr,msgflg.                                                                                        
 * Return  : On success, msgsnd returns zero,and returns negative number on error.
*/
                                                                                                                             143,1         76%
 if (nexg_msgsnd (msgqidTWO, &pduONE[iterate], FOURHUNDRED, ZERO) == -ONE) /* Send message to next Entity */
        {
          nexg_perror ("\t\t\t\tMESSAGE SEND FAILED\n");
          return (ZERO);
        }
    }

/*
  * System Call: nexg_msgctl                                                                                                     
  * Purpose : To delete message queue.                                                                                  
  * Inputs  : Message qid, message queue delete command,and flag.                         
  * Return  : On success, nexg_msgctl returns zero,and returns negative number on error.        
*/
        if(nexg_fclose (reorder)==-ONE)                                         /* close the file */
        {
                 nexg_perror("\t\t\t\t\tError close to file\n");
        }
        if(nexg_fclose (reorder_dis)==-ONE)
         {
                nexg_perror("\t\t\t\t\tError close to file\n");
          }
  nexg_msgctl (msgqidONE, IPC_RMID, ZERO);                                      /* Function used to delete message queue */
#ifdef debug
  nexg_printf ("\t Total no of lines in reorder.c file %d\n", __LINE__);        /* predefined macros to print number of lines */
#else
#endif
return (ZERO);                                                          /* returning control to the main function in send.c file */
}

/************************************************************************************************************************************
*                                              end of file reorder.c                                                              *
************************************************************************************************************************************/

