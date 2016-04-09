//---------------------------------------------------------------------------
#ifndef __tsoft_cstr_manipulation_H__
#define __tsoft_cstr_manipulation_H__
//---------------------------------------------------------------------------
#include "./../tsoft_MAIN.h"
#include "./../mem/tsoft_mem32.h"
//---------------------------------------------------------------------------
namespace ts { namespace cstr {
//---------------------------------------------------------------------------
        extern char     *__stdcall alloc                (__int32 a_size);
        extern char     *__stdcall allocex              (__int32 a_size, const char *a_src_ptr);
//---------------------------------------------------------------------------
        extern char     *__stdcall realloc              (char *a_dst_ptr, __int32 a_size);
        extern char     *__stdcall reallocex            (char *a_dst_ptr, __int32 a_size, const char *a_src_ptr);
//---------------------------------------------------------------------------
        extern void      __stdcall free                 (char *a_dst_ptr);
//---------------------------------------------------------------------------
        extern char		*__stdcall dupex				(char *a_dst_ptr, const char *a_src_ptr);
        extern char		*__stdcall dup					(const char *a_src_ptr);
//---------------------------------------------------------------------------
        extern char		*__stdcall mov					(char *a_dst_ptr, const char *a_src_ptr);
        extern char		*__stdcall mov_max				(char *a_dst_ptr, const char *a_src_ptr, const __int32 a_end);
        extern char     *__stdcall movi                 (char* a_dst_ptr, const char* a_src_ptr, const char c);
        extern char*     __stdcall movi_dups            (char* a_dst_ptr, const char* a_src_ptr);
//---------------------------------------------------------------------------
        extern char		*__stdcall catex 				(char *a_dst_ptr, const char *a_src_ptr);
        extern char		*__stdcall cat					(char *a_dst_ptr, const char *a_src_ptr);
        extern char		*__stdcall insert				(char *a_dst_ptr, const __int32 a_start, const char *insert);
        extern char		*__stdcall cut					(char *a_dst_ptr, const __int32 a_start, const __int32 a_count);
        extern char		*__stdcall cut_end				(char *a_dst_ptr,const __int32 a_start, const __int32 a_end);
        extern char		*__stdcall substr	 			(char *a_dst_ptr, const char *a_src_ptr, const __int32 a_start, const __int32 a_count);
        extern char		*__stdcall substr_end			(char *a_dst_ptr, const char *a_src_ptr, const __int32 a_start, const __int32 a_end);
        extern __int32	 __stdcall pos					(const char *a_src_ptr, const __int32 a_start, const char *a_fnd_ptr);
        extern __int32	 __stdcall pos_end				(const char *a_src_ptr, const __int32 a_start, const char *a_fnd_ptr, const __int32 a_end);
        extern __int32	 __stdcall posr		 			(const char *a_src_ptr, const __int32 a_start, const char *a_fnd_ptr);
        extern __int32	 __stdcall compare				(const char *alp1, const char *alp2);
        extern __int32	 __stdcall compare_end			(const char *alp1, const char *alp2, const __int32 a_end);
        extern bool	 	 __stdcall test					(const char *alp1, const char *alp2);
        extern __int32   __stdcall between              (char* dst, const char* src, const char c);
        extern __int32   __stdcall between              (char* dst, const char* src, const char l, const char r);
        extern __int32   __stdcall between_words        (char* dst, const char* src, const char *l, const char *r);
        // bool account number-digits checksum is ok
        extern bool      __stdcall luhna_check          (char *digits);
//---------------------------------------------------------------------------
        extern char		*__stdcall replace				(char *a_dst_ptr, const char *a_fnd_ptr, const char *a_exch_ptr);
        extern char		*__stdcall replace_chr  		(char *a_dst_ptr, const char a_fnd_ptr, const char a_exch_ptr);
        extern char		*__stdcall upr					(char *a_dst_ptr);
        extern char		*__stdcall lwr					(char *a_dst_ptr);
        extern char		*__stdcall trim					(char *a_dst_ptr);
//---------------------------------------------------------------------------
        extern char		*__stdcall set					(char *a_dst_ptr, const char a_znak_B, const __int32 a_start, const __int32 a_count);
        extern char		*__stdcall set_end				(char *a_dst_ptr, const char a_znak_B, const __int32 a_start, const __int32 a_end);
        extern __int32	 __stdcall chr					(const char *a_src_ptr, const char a_chr);
        extern __int32	 __stdcall chr_end				(const char *a_src_ptr, const char a_chr, const __int32 a_end);
        extern __int32	 __stdcall chrr					(const char *a_src_ptr, const char a_chr);
        //extern __int32	 __stdcall chrr_end				(const char *a_src_ptr, const char a_chr);
        extern __int32   __stdcall chr_sum              (const char* a_str_ptr, const char a_chr);
        //---------------------------------------------------------------------------
        extern __int32	 __stdcall len					(const char *a_src_ptr);
        //---------------------------------------------------------------------------
        extern char     *__stdcall brks 				(const char *a_src_ptr, const __int32 a_start, const char *a_brk);
        inline char     *__stdcall brk                  (const char *a_src_ptr, const char *a_brk) {
        return brks(a_src_ptr,0,a_brk);
        }
        inline __int32   __stdcall spn                  (const char *s, const char *set) {
        register char *r = brks(s,0,set);
        if (r==NULL) return len(s);
        else return r - s;
        }
//---------------------------------------------------------------------------
        extern char		*__stdcall extract_file_root    (char *a_dst_ptr, const char *a_src_ptr);
        extern char		*__stdcall extract_file_path    (char *a_dst_ptr, const char *a_src_ptr);
        extern char		*__stdcall extract_file_name    (char *a_dst_ptr, const char *a_src_ptr);
        extern char		*__stdcall extract_file_name_ext(char *a_dst_ptr, const char *a_src_ptr);
        //---------------------------------------------------------------------------
        extern char		*__stdcall get_file_name		(const char *a_src_ptr);
        extern char		*__stdcall get_file_ext			(const char *a_src_ptr);
//---------------------------------------------------------------------------
        extern char		*__stdcall fix_file_path        (char *a_dst_ptr,const char *a_src_ptr);
//---------------------------------------------------------------------------
        extern __int32		 __stdcall atoi             (const char *a_src_ptr);
        extern const char	*__stdcall itoa             (const __int32 aint, char* a_dst_ptr, const __int8 abase);
        extern const char	*__stdcall itoa             (const __int32 aint, const __int8 abase);
        extern const char	*__stdcall itoa             (const __int32 aint);
//---------------------------------------------------------------------------
inline int isupper(char c){
    return (c >= 'A' && c <= 'Z');
}
inline int isalpha(char c){
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
inline int isspace(char c){
    return (c == ' ' || c == '\t' || c == '\n' || c == '\12');
}
inline int isdigit(char c){
    return (c >= '0' && c <= '9');
}
//---------------------------------------------------------------------------
}}
//---------------------------------------------------------------------------
#endif // TSOFT_TEXT_H