//---------------------------------------------------------------------------
// ------ Stanis�aw Stasiak = "sstsoft@2001-2015r"---------------------------
//---------------------------------------------------------------------------
#include "tsoft_kop32_controler.h"
#include "tsoft_kop32_class.h"
//---------------------------------------------------------------------------

 __stdcall ts::__kop32_class_progress_controler::__stat::__stat()
: readed(0), size(0)
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
	reset();
}
//---------------------------------------------------------------------------

__stdcall ts::__kop32_class_progress_controler::__stat::~__stat()
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif

}
//---------------------------------------------------------------------------

__int32 __stdcall ts::__kop32_class_progress_controler::__stat::percent(void)
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
		if (size!=0) return (__int32)((100* readed) / size);
		else return 0;
}
//---------------------------------------------------------------------------

void   __stdcall ts::__kop32_class_progress_controler::__stat::reset(void)
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
		readed = size = 0;
}
//---------------------------------------------------------------------------

__stdcall  ts::__kop32_class_progress_controler::__kop32_class_progress_controler(ts::__kop32_class *aowner)
:	f_owner(aowner),
	f_timer_freezed(true),
	f_t1(0),f_t2(0),
	f_t (0),
	cancel(false), pause(false)
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif

		src = new __stat_group();
		dst = new __stat_group();
		reset();
}
//---------------------------------------------------------------------------

__stdcall  ts::__kop32_class_progress_controler::~__kop32_class_progress_controler()
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
		delete src;
		delete dst;
}
//---------------------------------------------------------------------------

void  __stdcall ts::__kop32_class_progress_controler::reset()
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
		f_t1 = 0;
		f_t2 = 0;
		f_timer_freezed = true;
		cancel = false;
		src->reset(); dst->reset();
}
//---------------------------------------------------------------------------

__int32 __stdcall ts::__kop32_class_progress_controler::initialize_timer(void)
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
		f_timer_freezed = false;
		f_t1 = time(&f_t);
		f_t2 = f_t1;
		return f_t1;
}
//---------------------------------------------------------------------------

void	__stdcall ts::__kop32_class_progress_controler::freeze_timer(void)
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
		f_timer_freezed = true;
}
//---------------------------------------------------------------------------

void	__stdcall ts::__kop32_class_progress_controler::resume_timer(void)
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
		__int32 d = f_t2-f_t1;
		f_t2 = time(&f_t);
		f_t1 = f_t2-d;
		f_timer_freezed = false;
}
//---------------------------------------------------------------------------

__int32 __stdcall ts::__kop32_class_progress_controler::elapsed(void)
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
		if (f_timer_freezed==false) f_t2 = time(&f_t);
		return f_t2 - f_t1;
}
//---------------------------------------------------------------------------

__int32 __stdcall ts::__kop32_class_progress_controler::actual_time(void)
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
		f_timer_freezed = false;
		f_t2 = time(&f_t);
		return f_t2;
}
//---------------------------------------------------------------------------

void __stdcall ts::__kop32_class_progress_controler::set_owner(ts::__kop32_class *aowner)
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
		f_owner = aowner;
}
//---------------------------------------------------------------------------

ts::__kop32_class* __stdcall ts::__kop32_class_progress_controler::owner(void)
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
		return f_owner;
}
//---------------------------------------------------------------------------

const char* __stdcall ts::__kop32_class_progress_controler::do_event(const char *a_event, const char *a_code, const char *a_code_ex)
{
#ifdef __DEBUG_KOP32_PROGRESS_CONTROLER__
__DEBUG_FUNC_CALLED__
#endif
if (!callback_event_handler) return default_callback_event_handler(this->owner(), a_event,a_code, a_code_ex);
else return callback_event_handler(this->owner(), a_event,a_code,a_code_ex);
}
//---------------------------------------------------------------------------
const char* __stdcall ts::__kop32_class_progress_controler::default_callback_event_handler(ts::__kop32_class*, const char*, const char*, const char*) {
return "OK";
}
//---------------------------------------------------------------------------
