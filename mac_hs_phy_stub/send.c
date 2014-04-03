/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : send.c                                                                                          
 ** Module Name  : MAC-HS-IN                                                                                                           
 ** Project Name : MAC-HS UE Side                                                                                                 
 ** Description  : definition of send() function which is called by Harq.c file for send the data from Physical layer to                                           Harq entity.                                                                                               
 ** Author       : MAC-HS-IN Project Team                                                                                            
 ** Start date   : 12-01-2013                                                                                                       
 ** End date     : 20-01-2013                                                                                                      
 */


#include"../mac_hs_include/header.h"
#include"../mac_hs_include/wrapper.h"

U32
main ()
{

  FILE *fp_sdu;                 /* Define File pointer which used to access the file*/
  FILE *fp_mac_log;             /* Define File pointer which used to access the file*/
  struct mac_hs_msg pdu;
  U32 len        = ZERO;        /* Define the integer Variables which is use in code */
  U32 msgqid     = ZERO;        /* Declare and initialize an integer type of message queue id and iterate */
  U32 msgqidTHREE=  ZERO;       /* Declare and initialize an integer type of message queue id and iterate */
  U32 running    = ONE;         /* Define the integer Variables which is use in code */
  U8  arrayONE[THIRTYFIVE];     /* Take another character type Array & the size of array is also THIRTYFIVE */

/*
 * Function: nexg_printf                                                                                                                
 * Purpose : Used for printing output                           
 * Inputs  : user dependent.                                                                                                
 * Return  : return the number of characters printed.
*/

  nexg_printf ("\t\t\tMESSAGE FROM UTRAN \n\n");
  fp_mac_log = nexg_fopen ("../mac_hs_logfiles/mac.txt", "a");  /*File from which data will be write */
  nexg_fprintf (fp_mac_log, "\t\nDATA CREATED ON:-%s\t\n\n", __TIMESTAMP__);    /*print date and time in file */
  nexg_fprintf (fp_mac_log, "%s", "IE's COPIED ARE:-\n\n\n");
/*
 * Function: nexg_fopen                                                                                                                 
 * Purpose : Used to open the FILE which is decleared in standard library stdlib.h                      
 * Inputs  : user dependent File name.                                                                                              
 * Return  : Return the File pointer.
 */

  fp_sdu = nexg_fopen ("../mac_hs_logfiles/phy_pdu.txt", "rb"); /*creation of a file which will use in code */


/*
 * Function: nexg_perror                                                                                                                
 * Purpose : Print a system error message.                      
 * Inputs  :                                                                                                
 * Return  :
 */
  if (fp_sdu == NULL)
    {
      nexg_perror ("\t\t\tUnable to creat file\n");

      return (ZERO);
    }

/*
 * Function: Return                                                                                                                     
 * Purpose : Cause normal process termination.                          
 * Inputs  :                                                                                                
 * Return  : Return function return ONE on Successful .
 */

  while (running <= EIGHT)      /* start of While loop for process */
    {

/*
* Function: nexg_fread                                                                                                                 
 * Purpose : Read number of element,data.                       
 * Inputs  : File name given by pointer.                                                                                            
 * Return  : return the number of items successfully read or written.
 */

      while (nexg_fread (&pdu, sizeof (pdu), ONE, fp_sdu) == ONE)       /* Read data from file */
        {

          nexg_fprintf (fp_mac_log,"\n\t\t\t*****||||Waiting for the PHY layer*****||||\n");
          nexg_fprintf (fp_mac_log, "\n\t\t\t======>>>Data receiving started at time=%s<<<======\n", __TIME__); /*predefined macros to print the file name */
          nexg_fprintf (fp_mac_log, "\n\t\t\t======>>>Data receiving started on Date=%s<<<======\n", __DATE__); /*predefined macros to print the file name */


          pdu.message_type = ONE;       /* Giving the priority of message */

          len = sizeof (pdu.array);     /* Use to find size of object */

/*
 * System Call: nexg_msgget.                                                                                                        
 * Purpose : To create message queue.                                                                                         
 * Inputs  : KEY and msgflg.                                                                                                        
 * Return  : returns a positive number, the queue identifier, on success otherwise negative number on failure.                         
 */
          msgqid = nexg_msgget ((key_t) ONE, IPC_CREAT | PERMISSION);   /* get a message queue identifier */
          if (msgqid < ZERO)    /* if start to check return value of msgget function used above */
            {
nexg_perror ("\tERROR CREATING MESSAGE QUEUE\n");
            }
/*
 * System Call: nexg_msgsnd                                                                                                                     
 * Purpose : To send message into message queue.                                                                        
 * Inputs  : message queue identifier returned from a msgget function,pointer to the message to be sent,size of the message 
                pointed to by msg_ptr,msgflg.                                                                                       
 * Return  : On success, msgsnd returns zero,and returns negative number on error.
 */
          else if (nexg_msgsnd (msgqid, &pdu, len, ZERO) == -ONE)       /*to send message to a message queue with assigned message type */
            {
              nexg_perror ("\tMESSAGE SEND FAILED\n");
              return (ZERO);                                            /* end of msgsnd function if it's failed */
            }

          msgqidTHREE = nexg_msgget ((key_t) SIX, IPC_CREAT | PERMISSION);      /* get a message queue identifier */
          if (msgqidTHREE < ZERO)                                       /* if start to check return value of msgget function used above */
            {
              nexg_perror ("\tERROR CREATING MESSAGE QUEUE\n");
             }

/*
  * System Call: nexg_msgrcv                                                                                                             
  * Purpose : To receive message from message queue.                                                        *                           
  * Inputs  : message queue identifier returned from a msgget function,pointer to the message to be sent,size of the message 
                pointed to by msg_ptr,long int message type msgflg.                         
  * Return  : On success, msgrcv returns zero,and returns negative number on error.                                                     
*/
          else if (nexg_msgrcv (msgqidTHREE, &arrayONE, THIRTYFIVE, ZERO, ZERO) == -ONE)        /*to receive message from other entity */
            {
              nexg_perror ("\tMESSAGE RECEIVE FAILDE\n");
              return (ZERO);    /* end of msgrcv function if it's failed */
            }

          if (nexg_strncmp (arrayONE, "POSITIVE", THIRTYFIVE) == ZERO)
            {
              nexg_printf ("\t\t\t%s", arrayONE);
              nexg_printf (" ACKNOWLEDGEMENT RECEIVED\n");      /* print acknowledgement */
            }
          else
            {
              nexg_printf ("\t\t\t%s", arrayONE);
              nexg_printf (" ACKNOWLEDGEMENT RECEIVED\n\t\t\tREENTER MESSAGE\n");
            }

          running++;
        }
    }
/*
  * System Call: nexg_msgctl                                                                                                     
  * Purpose : To delete message queue.                                                      *                           
  * Inputs  : Message qid, message queue delete command,and flag.                         
  * Return  : On success, nexg_msgctl returns zero,and returns negative number on error.                                                
*/
     if(nexg_fclose (fp_sdu)==-ONE)     /*close the file*/
        {
                nexg_perror("\t\t\tError close to file\n");
        }
     if( nexg_fclose (fp_mac_log)==-ONE)        /*close the file*/
        {
                nexg_perror("\t\t\tError close to file\n");
        }

  nexg_msgctl (msgqidTHREE, IPC_RMID, ZERO);    /* Function used to delete message queue */

  nexg_printf ("\t Total no of lines in send.c file %d\n", __LINE__);   /* predefined macros to print number of lines */
  return (ZERO);                        /* returning control to the main function in send.c file */
}

/************************************************************************************************************************************
*                                              end of file send.c                                                                   *
************************************************************************************************************************************/
                                                                                     

