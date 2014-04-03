/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : header.h                                                                                              
 ** Module Name  : MAC-HS                                                                                                       
 ** Project Name : MAC-HS UE Side                                                                                                 
 ** Description  : header file having all required library functions and user defined macros which will use in code
 ** Author       : MAC-HS Project Team                                                                                            
 ** Start date   : 12-01-2013                                                                                                       
 ** End date     : 12-01-2013                                                                                                      
 */
#ifndef _HEADER_H_
#define _HEADER_H_

#include<stdio.h>       /* All the header file has pre defined library function,and all of function which used in project has been mentioned 
                        in header files*/
#include<sys/types.h>
#include<sys/ipc.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<pthread.h>
#include<malloc.h>
#include<stdarg.h>
#include<semaphore.h>

#define DEBUG
#define ZERO            0                       /* defining Macros which are  used in programe  */
#define ONE             1
#define TWO             2
#define THREE           3
#define FOUR            4
#define FIVE            5
#define SIX             6
#define SEVEN           7
#define EIGHT           8
#define THIRTYFIVE      35
#define HUNDRED         100
#define FOURHUNDRED     400
#define SIXTYFOUR       64
#define PERMISSION      0666


typedef int U32;                /* Typedef datatypes */
typedef char U8;
typedef long int U64;

struct mac_hs_msg                /* Structure declaration */
{
  U64 message_type;
  U32 qid;
  U32 tsn;
  U32 array[HUNDRED];
};
struct diss_msg                 /* Structure declaration */
{
  U64 message_type;
  U32 a[HUNDRED];
};
#endif

/************************************************************************************************************************************
*                                              end of file header.h                                                     *
************************************************************************************************************************************/
