//---------------------------------------------------------------------------
// ------ Stanislaw Stasiak = "sstsoft@2001-2015r"---------------------------
//---------------------------------------------------------------------------
#include "tsoft_cipher_pair.h"
//---------------------------------------------------------------------------
#include "./../mem/tsoft_mem.h"
#include "./../text/tsoft_cstr_utils.h"
//---------------------------------------------------------------------------

ts::cipher::__pair_cipher::__pair_cipher(void)
{
#ifdef __DEBUG_pair_CIPHER__
__DEBUG_FUNC_CALLED("")
#endif
	order = (uint8_t*)ts::mem32::alloc(256*sizeof(uint8_t));
	this->initialize();
}
//---------------------------------------------------------------------------

ts::cipher::__pair_cipher::~__pair_cipher(void)
{
#ifdef __DEBUG_pair_CIPHER__
__DEBUG_FUNC_CALLED("")
#endif
	ts::mem32::free(order);
}
//---------------------------------------------------------------------------

void __stdcall ts::cipher::__pair_cipher::initialize(void)
{
#ifdef __DEBUG_pair_CIPHER__
__DEBUG_FUNC_CALLED("")
#endif
	for (uint8_t i = 0;; i++) {
		order[i]=i;
		if (i==255) break;
	}
//------------------------------------------
}
//---------------------------------------------------------------------------

char __stdcall ts::cipher::__pair_cipher::encode(const char a_ch)
{
#ifdef __DEBUG_pair_CIPHER__
__DEBUG_FUNC_CALLED("")
#endif
	register uint8_t l_ch = (uint8_t)a_ch, r = ts::mem32::chr(order,l_ch,256);
	ts::mem32::ror(order,r);
	return r;
//------------------------------------------
}
//---------------------------------------------------------------------------

char __stdcall ts::cipher::__pair_cipher::decode(const char a_ch)
{
#ifdef __DEBUG_pair_CIPHER__
__DEBUG_FUNC_CALLED("")
#endif
	register uint8_t r = order[(uint8_t)a_ch];
	ts::mem32::ror(order,r);
	return r;
//------------------------------------------
}
//-------------------------------THE END-------------------------------------
