//---------------------------------------------------------------------------
#ifndef __stk_time_h
#define __stk_time_h
//---------------------------------------------------------------------------
#include "./../stk_main.h"
//---------------------------------------------------------------------------
namespace stk { namespace time {
//------------------------------------
extern uint64_t		    	__stdcall	time_us(void);
extern uint64_t			    __stdcall	time_ms(void);
extern void 		        __stdcall	wait_us(const uint64_t a_microseconds);
extern void 		        __stdcall	wait_ms(const uint64_t a_milliseconds);
extern void 		        __stdcall	wait_until(time_t a_time);
extern time_t               __stdcall   wait_idle(const time_t a_prev_time, const double a_percent_of_idle);
#ifdef __WIN32__
time_t __stdcall FILETIME_to_time_t(FILETIME const& ft);
FILETIME* __stdcall time_t_to_FILETIME(time_t t, LPFILETIME pft);
#endif
//------------------------------------
}}
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
