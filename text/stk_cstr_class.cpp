//---------------------------------------------------------------------------
// ------ Stanislaw Stasiak = "sstsoft@2001-2015r"---------------------------
//---------------------------------------------------------------------------
#include "stk_cstr_class.h"
#include "./../text/stk_cstr_utils.h"
#include "./../stk_MAIN.h"
//---------------------------------------------------------------------------

__stdcall stk::__cstr_class::__cstr_class()
:
  __vector<char>(0),
f_subs_size(0), f_subs(NULL), f_ptr_dup(NULL)
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif

__init(0,"\0");
}
//---------------------------------------------------------------------------

__stdcall stk::__cstr_class::__cstr_class(const uint32_t a_initial_size)
:
  __vector<char>(a_initial_size),
  f_subs_size(0), f_subs(NULL), f_ptr_dup(NULL)
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif

__init(a_initial_size,"\0");
}
//---------------------------------------------------------------------------

__stdcall stk::__cstr_class::__cstr_class(const char* __restrict__ a_text_to_clone)
:
  __vector<char>(0),
  f_subs_size(0), f_subs(NULL), f_ptr_dup(NULL)
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif
    __init(stk::cstr::len(a_text_to_clone)+1,a_text_to_clone);
}
//---------------------------------------------------------------------------

__stdcall stk::__cstr_class::__cstr_class(const uint32_t a_initial_size,const char* __restrict__ a_text_to_clone)
:
  __vector<char>(a_initial_size),
  f_subs_size(0), f_subs(NULL), f_ptr_dup(NULL)
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif
    __init(a_initial_size, a_text_to_clone);
}
//---------------------------------------------------------------------------

void __stdcall stk::__cstr_class::__init(const uint32_t a_initial_size, const char* __restrict__ a_text_to_clone)
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif
__vector<char>::resize(a_initial_size);
f_subs_size = 64-4;
f_subs = stk::cstr::alloc(f_subs_size);
}
//---------------------------------------------------------------------------

const char* __stdcall stk::__cstr_class::set(const char* __restrict__ a_text_to_clone)
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif
        if (a_text_to_clone==NULL) {
                        __vector<char>::at(0) = '\0';
                return &__vector<char>::at(0);
        }
        else
        {
                register uint32_t container_len = stk::cstr::len(a_text_to_clone);
                if (__vector<char>::mem_size() <=  container_len) {
                    __vector<char>::resize(container_len + 1);
                }
                return stk::cstr::mov(&__vector<char>::bottom(), a_text_to_clone);
        }
}
//---------------------------------------------------------------------------

const char *__stdcall stk::__cstr_class::add(const char* __restrict__ a_text_to_clone)
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif
        register uint32_t add_size, new_size;
        if (a_text_to_clone!=NULL) {
                add_size = stk::cstr::len(a_text_to_clone);
        }
        else {
                add_size = 0;
        }
                new_size = stk::cstr::len(&__vector<char>::bottom()) + add_size;
        if (new_size > __vector<char>::mem_size()) {
                __vector<char>::resize(new_size);
        }
        return stk::cstr::cat(&__vector<char>::bottom(),a_text_to_clone);
}
//---------------------------------------------------------------------------
const char	   *__stdcall	stk::__cstr_class::substr(uint32_t a_pos, uint32_t a_len) const
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif
if (f_subs_size < a_len + 1)
{
    f_subs_size = a_len + 1;
    f_subs = stk::cstr::realloc(f_subs,f_subs_size);
}
stk::cstr::substr(f_subs,&__vector<char>::bottom(),a_pos,a_len);
return f_subs;
}
//---------------------------------------------------------------------------

void __stdcall stk::__cstr_class::reserve(const uint32_t a_new_size)
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif
        __vector<char>::resize(a_new_size);
}
//---------------------------------------------------------------------------

void __stdcall stk::__cstr_class::resize(const uint32_t a_new_len)
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif
register uint32_t lp = stk::cstr::len(&__vector<char>::bottom()) +1;
if (a_new_len <= lp) __vector<char>::at(a_new_len) = '\0';
else stk::cstr::set_end(&__vector<char>::bottom(),'\0',lp,a_new_len);
}
//---------------------------------------------------------------------------

void __stdcall stk::__cstr_class::clear(void)
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif
if (__vector<char>::count()!=0) __vector<char>::bottom() = '\0';
}
//---------------------------------------------------------------------------

void __stdcall stk::__cstr_class::shrink_to_fit(void)
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif
if (__vector<char>::count()!=0) {
        __vector<char>::resize(stk::cstr::len(&__vector<char>::bottom())+1);
        }
}
//---------------------------------------------------------------------------

__stdcall stk::__cstr_class::~__cstr_class(void)
{
#ifdef __DEBUG_CSTR_CLASS__
__DEBUG_CALLED("")
#endif
        if (f_subs!=NULL) delete f_subs;
        f_ptr_dup = NULL;
}
//---------------------------------------------------------------------------
