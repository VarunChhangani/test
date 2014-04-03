/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_msgsnd.c                                                                                            
 ** Module Name  : MAC-HS_IN                                                                                                      
 ** Project Name : MAC-HS UE Side                                                                                                
 ** Description  : definition of nexg_msgsnd()                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   : 21-01-2013                                                                                                     
 ** End date     : 24-01-2013                                                                                                      
 */



#include "../mac_hs_include/header.h"

U32
nexg_msgsnd (U32 msqid, const void *msg_ptr, size_t msg_sz,U32 msgflg)  /* wrapper function nexg_msgsnd() starts */
{
  return msgsnd (msqid, msg_ptr, msg_sz, msgflg);
}


/************************************************************************************************************************************
*                                              end of file nexg_msgsnd.c                                                             *
************************************************************************************************************************************/

