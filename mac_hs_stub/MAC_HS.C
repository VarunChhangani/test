/*
 * * All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                              
 * * File Name    : MAC_HS.c                                                                                            
 * * Module Name  : MAC-HS                                                                                                   
 * * Project Name : MAC-HS UE Side                                                                                                
 * * Description  : main file for receive messages at harq entity and goes upto next process  by calling rq(),
                        reorder() and disassembly()functions.                                                            
 * * Author       : MAC-HS- Project Team                                                                                           
 * * Start date   : 16-01-2013                                                                                                      
 * * End date     : 24-01-2013                                                                                                     
 */
#include "../mac_hs_include/header.h"
#include "../mac_hs_include/wrapper.h"


U32
main ()                         /* definition of main function */
{                               /* start of main */

  nexg_printf ("\n");
  nexg_printf
    ("\t\t\t\t _______________________________________________________________\n");
  nexg_printf ("\t\t\t\t|The name of this file is:-%s\t\t\t|\n", __FILE__);     /*predefined macros to print the file name */
  nexg_printf ("\t\t\t\t|The Current Time is:-%s\t\t\t|\n", __TIMESTAMP__);     /*predefined macros to print the time */
  nexg_printf
    ("\t\t\t\t|_______________________________________________________________|\n");
  harq ();              /* harq function call */
  rq ();                /* rq function call */
  reorder ();           /* reorder function call*/
  disassembly ();                       /*  disasembly function call */
  nexg_printf ("\n\tThe current line is %d\n", __LINE__);       /* predefined macro to print number of lines */

  return (ZERO);                /* returning control to the operating system */
}                               /* end of main */

/************************************************************************************************************************************
*                                              end of file MAC_HS.c                                                      *
************************************************************************************************************************************/
