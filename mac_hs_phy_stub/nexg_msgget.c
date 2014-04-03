/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_msgget.c                                                                                            
 ** Module Name  : MAC-HS_IN                                                                                                      
 ** Project Name : MAC-HS UE Side                                                                                                
 ** Description  : definition of nexg_msgget()                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   : 21-01-2013                                                                                                       
 ** End date     : 24-01-2013                                                                                                      
 */



#include "../mac_hs_include/header.h"

U32
nexg_msgget (key_t key,U32 msgflg)      /* wrapper function nexg_msgget() starts */
{
return msgget (key, msgflg);
}

/************************************************************************************************************************************
*                                              end of file nexg_msgget.c                                                             *
************************************************************************************************************************************/

