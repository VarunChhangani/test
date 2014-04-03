/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_msgrcv.c                                                                                            
 ** Module Name  : MAC_HS_IN                                                                                                      
 ** Project Name : MAC-HS UE Side                                                                                                
 ** Description  : definition of nexg_msgrcv()                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   : 21-01-2013                                                                                                       
 ** End date     : 24-01-2013                                                                                                      
 */

#include "../mac_hs_include/header.h"

U32
nexg_msgrcv (U32 msqid, void *msg_ptr, size_t msg_sz, U64 msg_type, U32 msgflg) /* wrapper function nexg_msgrcv() starts */
{
  return msgrcv (msqid, msg_ptr, msg_sz, msg_type, msgflg);
}

/************************************************************************************************************************************
*                                              end of file nexg_msgrcv.c                                                             *
************************************************************************************************************************************/

