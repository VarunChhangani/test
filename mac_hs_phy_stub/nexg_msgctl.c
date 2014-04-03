/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_msgctl.h                                                                                                       
 ** Module Name  : MAC-HS-IN                                                                                                           
 ** Project Name : MAC-HS UE Side                                                                                                 
 ** Description  : definition of nexg_msgctl()                                                                            
 ** Author       : MAC-HS Project Team                                                                                            
 ** Start date   : 21-01-2013                                                                                                       
 ** End date     : 24-01-2013                                                                                                    
 */
#include "../mac_hs_include/header.h"

U32
nexg_msgctl (U32 msgqid, U32 cmd, struct msqid_ds *buf) /* wrapper function nexg_msgctl() starts */
{

  if (msgctl (msgqid, cmd, buf) < ZERO)
    {
      perror ("msgctl failed\n");
      return (ZERO);
    }
  else
    {
      printf ("\n\n\tmessage queue of qid %d have been deleted\n\n", msgqid);
    }

  return (ZERO);
}

/***********************************************************************************************************************************
*                                              end of file nexg_msgctl.c                                                            *
************************************************************************************************************************************/

