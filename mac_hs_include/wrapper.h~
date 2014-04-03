/*
 ** All rights reserved – Nex-G Exuberant Solutions Private Limited.                                                               
 ** File Name    : wrapper.h                                                                                            
 ** Module Name  : MAC_HS UE Side                                                                                                      
 ** Project Name : MAC-HS UE Side                                                                                                
 ** Description  : decleration of all wrapper functions                              
 ** Author       : MAC-HS Project Team                                                                                           
 ** Start date   : 12-01-2013                                                                                                       
 ** End date     : 12-01-2013                                                                                                     
 */


#ifndef _WRAPPER_H_
#define _WRAPPER_H_

void nexg_printf (char *format, ...);
void nexg_fprintf (FILE * fptr, char *format, ...);
void nexg_memcpy (void *dest, void *src, int bytes);
void nexg_perror (const char *s);
int nexg_strncmp (const char *s1, const char *s2, size_t n);
void nexg_memset (void *pointer, int c, int size);
void *nexg_fopen (const char *, const char *);
int nexg_fclose (FILE *);
void nexg_delay (int timeout);
int nexg_fread (void *, size_t, size_t, FILE *);
void *nexg_malloc (size_t n);
int nexg_msgget (key_t, int);
int nexg_msgsnd (int msqid, const void *msg_ptr, size_t msg_sz, int msgflg);
int nexg_msgrcv (int msqid, void *msg_ptr, size_t msg_sz, long int msg_type,int msgflg);
int nexg_msgctl (int msgqid, int cmd, struct msqid_ds *buf);
int nexg_strlen (char str[]);
size_t strlen(const char *s);
int harq ();
int rq ();
int reorder ();
int disassembly ();

#endif

/************************************************************************************************************************************
*                                              end of file wrapper.h                                                                *
************************************************************************************************************************************/
