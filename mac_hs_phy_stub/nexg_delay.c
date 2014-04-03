/*
All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_delay.c                                                                                            
 ** Module Name  : MAC_HS_IN                                                                                                      
 ** Project Name : MAC_HS UE Side                                                                                                
 ** Description  : definition of nexg_delay()                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   : 2-2-2013                                                                                                       
 ** End date     : 2-2-2013                                                                                                      
 */

#include "../mac_hs_include/header.h"

void nexg_delay (int timeout)    /* wrapper function nexg_delay() starts */
{
  time_t start_time;
  time_t current_time;

  start_time = time (NULL);
  current_time = time (NULL);

  while (current_time < start_time + timeout)
    current_time = time (NULL);

}

/************************************************************************************************************************************
*                                              end of file nexg_delay.c                                                             *
************************************************************************************************************************************/

