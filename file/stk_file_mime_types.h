//---------------------------------------------------------------------------
#ifndef __stk_mime_types_h
#define __stk_mime_types_h
//---------------------------------------------------------------------------
#include "./../stk_main.h"
//---------------------------------------------------------------------------
#ifdef __cplusplus
namespace stk { namespace file { namespace mime {
#endif
//---------------------------------------------------------------------------
extern char  STK_IMPEXP *__stdcall decode(char* a_file_name);
#ifdef __WATCOMC__
extern void  atexit(void);
#else
extern void __cdecl atexit(void);
#endif
//---------------------------------------------------------------------------
#ifdef __cplusplus
}}}
#endif
//---------------------------------------------------------------------------
#endif
