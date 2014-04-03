/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_fread.c                                                                                            
 ** Module Name  : MAC_HS_IN                                                                                                      
 ** Project Name : MAC-HS UE Side                                                                                                
 ** Description  : definition of nexg_fread()                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   : 21-01-2013                                                                                                    
 ** End date     : 24-01-2013                                                                                                     
 */

#include "../mac_hs_include/header.h"


U32
nexg_fread (void *buf, size_t size, size_t n, FILE * fp)        /* wrapper function nexg_fread() starts */
{
  return fread (buf, size, n, fp);
}

/************************************************************************************************************************************
*                                              end of file nexg_fread.c                                                             *
************************************************************************************************************************************/

