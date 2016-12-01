//---------------------------------------------------------------------------
#ifndef tsoft_database_alias_h
#define tsoft_database_alias_h
#pragma once
//---------------------------------------------------------------------------
#include "./../text/tsoft_cstr_class.h"
//---------------------------------------------------------------------------
// alias = database file name, override __cstr_class change text to save to file in future ;)
//
namespace ts {
//---------------------------------------------------------------------------
class __database;
class __database_alias : public ts::__cstr_class {
//-------------------------------
	public:
//-------------------------------
	__stdcall  __database_alias(void)
	: ts::__cstr_class()
	{}
	__stdcall  __database_alias(const char *atext)
	: ts::__cstr_class(atext)
	{ }
		__stdcall ~__database_alias()
	{}
//-------------------------------
	friend class __database;
//---------------------------------------------------------------------------
};
//---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
