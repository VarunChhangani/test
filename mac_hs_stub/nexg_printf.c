/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_printf.c                                                                                            
 ** Module Name  : MAC-HS_IN                                                                                                      
 ** Project Name : MAC-HS UE Side                                                                                                
 ** Description  : definition of nexg_printf()                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   : 21-01-2013                                                                                                      
 ** End date     : 24-01-2013                                                                                                      
 */

#include "../mac_hs_include/header.h"

void
nexg_printf (char *format, ...) /* wrapper function nexg_printf() starts */
{
  va_list ap;
  va_start (ap, format);
  vprintf (format, ap);
  va_end (ap);
}

/************************************************************************************************************************************
*                                              end of file nexg_printf.c                                                             *
************************************************************************************************************************************/

