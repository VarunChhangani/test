/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_perror.c                                                                                            
 ** Module Name  : MAC-HS_IN                                                                                                      
 ** Project Name : MAC-HS UE Side                                                                                                
 ** Description  : definition of nexg_perror()                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   : 21-01-2013                                                                                                     
 ** End date     : 24-01-2013                                                                                                    
 */


#include "../mac_hs_include/header.h"
void
nexg_perror ()                  /* wrapper function nexg_perror() starts */
{
  printf ("error : %s\n", strerror (errno));

}

/************************************************************************************************************************************
*                                              end of file nexg_perror.c                                                             *
************************************************************************************************************************************/                                                                                                                                       
