/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_fclose.c                                                                                            
 ** Module Name  : MAC-HS_IN                                                                                                      
 ** Project Name : MAC-HS UE Side                                                                                                
 ** Description  : definition of nexg_fclose()                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   : 21-01-2013                                                                                                    
 ** End date     : 24-01-2013                                                                                                     
 */

#include "../mac_hs_include/header.h"
#include "../mac_hs_include/wrapper.h"

int nexg_fclose(FILE *fptr)		/* wrapper function nexg_fclose() starts */
{
return fclose(fptr);
}

/************************************************************************************************************************************
*                                              end of file nexg_fclose.c                                                             *
************************************************************************************************************************************/
