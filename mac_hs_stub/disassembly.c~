/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : disassemblt.c                                                                                           
 ** Module Name  : MAC-HS-IN                                                                                                           
 ** Project Name : MAC-HS UE Side                                                                                                 
 ** Description  : definition of disassembly() function which is called by reorder.c file.            
 ** Author       : MAC-HS-IN Project Team                                                                                            
 ** Start date   : 12-01-2013                                                                                                       
 ** End date     : 20-01-2013                                                                                                      
 */
#include"../mac_hs_include/header.h"
#include"../mac_hs_include/wrapper.h"
U32
disassembly ()
{
  FILE *dis;                    /* Define File pointer which used to access the file*/
  FILE *dis_mac;                /* Define File pointer which used to access the file*/
  struct mac_hs_msg pdu;
  struct diss_msg dmsg;
  U8 buffer[HUNDRED];           /* Take character type Array & the size of array is also HUNDRED */
  U32 iterate   = ZERO;         /* Define the integer Variables which is use in code */
  U32 msgqidONE = ZERO;         /* Declare and initialize an integer type of message queue id and iterate */
  U32 msgqidTWO = ZERO;         /* Declare and initialize an integer type of message queue id and iterate */
  U32 running   = ONE;          /* Define the integer Variables which is use in code */
  /* 
   * Function: nexg_printf                                                                                                               
   * Purpose : Used for printing output                          
   * Inputs  : user dependent.                                                                                               
   * Return  : return the number of characters printed.
   */
  dis = nexg_fopen ("../mac_hs_logfiles/disassembly.txt", "a"); /*File from which data will be write */
#ifdef DEBUG

  nexg_fprintf (dis, "\t\nDATA CREATED ON:-%s\t\n\n", __TIMESTAMP__);   /*print date and time in file */
  nexg_fprintf (dis, "\n\t\t\t*****||||Waiting for the Data*****||||\n");
  nexg_fprintf (dis, "\n\t\t\t======>>>Data receiving started at time=%s<<<======\n", __TIME__);        /*predefined macros to print the file name */
  nexg_fprintf (dis, "\n\t\t\t======>>>Data receiving started on Date=%s<<<======\n", __DATE__);        /*predefined macros to print the file name */
#endif
   nexg_printf
    ("\t\t ==============================================================================================\n");
  nexg_printf
    ("\t\t||                                                                                             ||\n");
  nexg_printf
    ("\t\t||                                     MESSAGE AT DISASSEMBLY.....                             ||\n");
  nexg_printf
    ("\t\t||                                                                                             ||\n");
  nexg_printf
    ("\t\t ==============================================================================================||\n");
  while (running <= NINE)       /* Loop for getting data from reordering */
    {
      pdu.message_type = ZERO;  /* giving message priority */

/*
 * System Call: nexg_msgget.                                                                                                        
 * Purpose : To create message queue.                                                                                         
 * Inputs  : KEY and msgflg.                                                                                                        
 * Return  : returns a positive number, the queue identifier, on success otherwise negative number on failure.                         
 */

      msgqidONE = nexg_msgget ((key_t) FOUR, IPC_CREAT | PERMISSION);   /* to create message queue */
      if (msgqidONE < ZERO)

/*
 * Function: nexg_perror                                                                                                                
 * Purpose : Print a system error message.                      
 * Inputs  :                                                                                                
 * Return  :
 */

        nexg_perror ("\t\t\t\tERROR CREATING MESSAGE QUEUE\n");

/*
  * System Call: nexg_msgrcv                                                                                                             
  * Purpose : To receive message from message queue.                                                        *                           
  * Inputs  : message queue identifier returned from a msgget function,pointer to the message to be sent,size of the message 
                pointed to by msg_ptr,long int message type msgflg.                         
  * Return  : On success, msgrcv returns zero,and returns negative number on error.
      else if (nexg_msgrcv (msgqidONE, &pdu, FOURHUNDRED, ZERO, ZERO) == -ONE)  /* receive message from reordering */
        {
          nexg_perror ("\t\t\t\tMESSAGE RECEIVE FAILED\n");     /* if start to check return value of msgget function used above */
          return (ZERO);
        }

      for (iterate = ZERO; iterate < HUNDRED; iterate++)
        {
          buffer[iterate] = pdu.array[iterate]; /* Store the geeting value in another array */
          dmsg.a[iterate] = pdu.array[iterate];
        }
#ifdef DEBUG
#else
      nexg_printf ("\t\t\t\tQID: %d", pdu.qid);
      nexg_printf ("\tTSN: %d\n\t\t\t\t\n\n", pdu.tsn);

      for (iterate = ZERO; buffer[iterate] != '\0'; iterate++)
        {
          nexg_fprintf (dis,"%c", buffer[iterate]);     /* printing the receiving value */
        }
#endif
        running++;
      msgqidTWO = nexg_msgget ((key_t) FIVE, IPC_CREAT | PERMISSION);   /* create another message queue */
      if (msgqidTWO < ZERO)     /* if start to check return value of msgget function used above */
        {
          nexg_perror ("\t\t\t\tERROR CREATING MESSAGE QUEUE\n");
        }
      dmsg.message_type = ONE;
      dis_mac = nexg_fopen ("../mac_hs_logfiles/to_mac.txt", "a");      /*File from which data will be write */
      nexg_fprintf (dis_mac, "\t\nDATA CREATED ON:-%s\t\n\n", __TIMESTAMP__);   /*print date and time in file */
      nexg_fprintf (dis_mac,
                    "\n\t\t\t*****||||Data send to MAC-D*****||||\n");
      nexg_fprintf (dis_mac, "\n\t\t\t======>>>Data sendinding started at time=%s<<<======\n", __TIME__);       /*predefined macros to print the file name */
      nexg_fprintf (dis_mac, "\n\t\t\t======>>>Data sendinging started on Date=%s<<<======\n", __DATE__);       /*predefined macros to print the file name */

/*
 * System Call: nexg_msgsnd                                                                                                             
 * Purpose : To send message into message queue.   
 * Inputs  : message queue identifier returned from a msgget function,pointer to the message to be sent,size of the message 
                pointed to by msg_ptr,msgflg.                                                                                       
 * Return  : On success, msgsnd returns zero,and returns negative number on error.
 */

      if (nexg_msgsnd (msgqidTWO, &dmsg, FOURHUNDRED, ZERO) == -ONE)    /* if start to check return value of msgget function used above */
        {
          nexg_perror ("\t\t\t\tMESSAGE SEND FAILED\n");        /* Send message to next MAC entity */
          return (ZERO);
        }
   //  running++;
    }

 if( nexg_fclose (dis)==-ONE)           /* close the file */
  {
        nexg_perror("\t\t\t\t\tError close to file\n");
  }
 if(nexg_fclose (dis_mac)==-ONE)        /* close the file */
  {
        nexg_perror("\t\t\t\t\tError close to file\n");
  }
/*
  * System Call: nexg_msgctl                                                                                                     
  * Purpose : To delete message queue.                                                      *                           
  * Inputs  : Message qid, message queue delete command,and flag.                         
  * Return  : On success, nexg_msgctl returns zero,and returns negative number on error.                                        
*/

  nexg_msgctl (msgqidONE, IPC_RMID, ZERO);      /* Function used to delete message queue */
  nexg_msgctl (msgqidTWO, IPC_RMID, ZERO);
#ifdef DEBUG
#else
  nexg_printf ("\t Total no of lines in disassembly.c file %d\n", __LINE__);    /* predefined macros to print number of lines */
#endif
nexg_printf
    ("\n\n\n\n\t\t ==============================================================================================\n");
  nexg_printf
     ("\t\t||                                                                                             ||\n");
  nexg_printf
    ("\t\t||                                    ...... MESSAGE AT MAC-D.....                             ||\n");
     nexg_printf
    ("\t\t||                                                                                             ||\n");
  nexg_printf
    ("\t\t ==============================================================================================||\n");


  return (ZERO);                /* returning control to the main function in send.c file */
}

/************************************************************************************************************************************
*                                              end of file disassembly.c                                                              *
************************************************************************************************************************************/

