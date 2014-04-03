
/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_fprintf.c                                                                                            
 ** Module Name  : MAC-HS_IN                                                                                                      
 ** Project Name : MAC-HS UE Side                                                                                                
 ** Description  : definition of nexg_fprintf()                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   : 21-01-2013                                                                                                    
 ** End date     : 24-01-2013                                                                                                      
 */

#include "../mac_hs_include/header.h"

void
nexg_fprintf (FILE * fptr, U8 *format, ...)     /* wrapper function nexg_fprintf() starts */
{
  va_list ap;
  va_start (ap, format);
  vfprintf (fptr, format, ap);
  va_end (ap);
}

/************************************************************************************************************************************
*                                              end of file nexg_delay.c                                                             *
************************************************************************************************************************************/

