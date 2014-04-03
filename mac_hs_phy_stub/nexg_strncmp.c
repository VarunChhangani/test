/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : nexg_strncmp.c                                                                                            
 ** Module Name  : MAC-HS                                                                                                     
 ** Project Name : MAC-HS UE Side                                                                                                
 ** Description  : definition of nexg_fopen()                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   :                                                                                                        
 ** End date     :                                                                                                     
 */







#include "../mac_hs_include/header.h"


U32
nexg_strncmp (U8 *s1, U8 *s2, size_t n)
{
  return strncmp (s1, s2, n);
}

/************************************************************************************************************************************
*                                              end of file nexg_strncmp.c                                                             *
************************************************************************************************************************************/
