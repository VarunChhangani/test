/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_free.c                                                                                            
 ** Module Name  : MAC-HS_IN                                                                                                      
 ** Project Name : MAC-HS UE Side                                                                                                
 ** Description  : definition of nexg_free()                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   : 21-01-2013                                                                                                     
 ** End date     : 24-01-2013                                                                                                   
 */

#include "../include/header.h"
void 
nexg_free(void *p)	/* wrapper function nexg_free() starts */
{
return free(p);
}

/************************************************************************************************************************************
*                                              end of file nexg_free.c                                                             *
************************************************************************************************************************************/

