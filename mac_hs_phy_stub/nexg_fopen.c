
/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_fopen.c                                                                                            
 ** Module Name  : MAC_HS_IN                                                                                                      
 ** Project Name : MAC-HS UE Side                                                                                                
 ** Description  : definition of nexg_fopen()                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   : 21-01-2013                                                                                                      
 ** End date     : 24-01-2013                                                                                                     
 */







#include "../mac_hs_include/header.h"


void *
nexg_fopen (const U8 *name, const U8 *mode)     /* wrapper function nexg_fopen() starts */
{
  return fopen (name, mode);
}

/************************************************************************************************************************************
*                                              end of file nexg_fopen.c                                                             *
************************************************************************************************************************************/

