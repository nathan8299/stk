//---------------------------------------------------------------------------
// ------ Stanislaw Stasiak = "sstsoft@2001-2015r"---------------------------
//---------------------------------------------------------------------------
#include "./../text/tsoft_cstr_utils.h"
#include "./../mem/tsoft_mem.h"
#include "./../io/tsoft_console.h"
//---------------------------------------------------------------------------
#include "tsoft_hash_ssc1.h"
//---------------------------------------------------------------------------
// NOT THREAD SAFE!
//---------------------------------------------------------------------------

static const uint32_t k[4*16] = {
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L,
                0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L
};
//---------------------------------------------------------------------------
static const uint8_t h_num[128] = {
                0x00L,0x00L,0x00L,0x00L,
                0x01L,0x01L,0x01L,0x01L,
                0x02L,0x02L,0x02L,0x02L,
                0x03L,0x03L,0x03L,0x03L,
                0x04L,0x04L,0x04L,0x04L,
                0x05L,0x05L,0x05L,0x05L,
                0x06L,0x06L,0x06L,0x06L,
                0x07L,0x07L,0x07L,0x07L,
                0x08L,0x08L,0x08L,0x08L,
                0x09L,0x09L,0x09L,0x09L,
                0x0AL,0x0AL,0x0AL,0x0AL,
                0x0BL,0x0BL,0x0BL,0x0BL,
                0x0CL,0x0CL,0x0CL,0x0CL,
                0x0DL,0x0DL,0x0DL,0x0DL,
                0x0EL,0x0EL,0x0EL,0x0EL,
                0x0FL,0x0FL,0x0FL,0x0FL,
                0x10L,0x10L,0x10L,0x10L,
                0x11L,0x11L,0x11L,0x11L,
                0x12L,0x12L,0x12L,0x12L,
                0x13L,0x13L,0x13L,0x13L,
                0x14L,0x14L,0x14L,0x14L,
                0x15L,0x15L,0x15L,0x15L,
                0x16L,0x16L,0x16L,0x16L,
                0x17L,0x17L,0x17L,0x17L,
                0x18L,0x18L,0x18L,0x18L,
                0x19L,0x19L,0x19L,0x19L,
                0x1AL,0x1AL,0x1AL,0x1AL,
                0x1BL,0x1BL,0x1BL,0x1BL,
                0x1CL,0x1CL,0x1CL,0x1CL,
                0x1DL,0x1DL,0x1DL,0x1DL,
                0x1EL,0x1EL,0x1EL,0x1EL,
                0x1FL,0x1FL,0x1FL,0x1FL
};
//---------------------------------------------------------------------------
static const uint8_t d_shift[256] = {
                0x00L, 0x01L, 0x01L, 0x02L, 0x01L, 0x02L, 0x02L, 0x03L,
                0x01L, 0x02L, 0x02L, 0x03L, 0x02L, 0x03L, 0x03L, 0x04L,
                0x01L, 0x02L, 0x02L, 0x03L, 0x02L, 0x03L, 0x03L, 0x04L,
                0x02L, 0x03L, 0x03L, 0x04L, 0x03L, 0x04L, 0x04L, 0x05L,
                0x01L, 0x02L, 0x02L, 0x03L, 0x02L, 0x03L, 0x03L, 0x04L,
                0x02L, 0x03L, 0x03L, 0x04L, 0x03L, 0x04L, 0x04L, 0x05L,
                0x02L, 0x03L, 0x03L, 0x04L, 0x03L, 0x04L, 0x04L, 0x05L,
                0x03L, 0x04L, 0x04L, 0x05L, 0x04L, 0x05L, 0x05L, 0x06L,
                0x01L, 0x02L, 0x02L, 0x03L, 0x02L, 0x03L, 0x03L, 0x04L,
                0x02L, 0x03L, 0x03L, 0x04L, 0x03L, 0x04L, 0x04L, 0x05L,
                0x02L, 0x03L, 0x03L, 0x04L, 0x03L, 0x04L, 0x04L, 0x05L,
                0x03L, 0x04L, 0x04L, 0x05L, 0x04L, 0x05L, 0x05L, 0x06L,
                0x02L, 0x03L, 0x03L, 0x04L, 0x03L, 0x04L, 0x04L, 0x05L,
                0x03L, 0x04L, 0x04L, 0x05L, 0x04L, 0x05L, 0x05L, 0x06L,
                0x03L, 0x04L, 0x04L, 0x05L, 0x04L, 0x05L, 0x05L, 0x06L,
                0x04L, 0x05L, 0x05L, 0x06L, 0x05L, 0x06L, 0x06L, 0x07L,
                0x01L, 0x02L, 0x02L, 0x03L, 0x02L, 0x03L, 0x03L, 0x04L,
                0x02L, 0x03L, 0x03L, 0x04L, 0x03L, 0x04L, 0x04L, 0x05L,
                0x02L, 0x03L, 0x03L, 0x04L, 0x03L, 0x04L, 0x04L, 0x05L,
                0x03L, 0x04L, 0x04L, 0x05L, 0x04L, 0x05L, 0x05L, 0x06L,
                0x02L, 0x03L, 0x03L, 0x04L, 0x03L, 0x04L, 0x04L, 0x05L,
                0x03L, 0x04L, 0x04L, 0x05L, 0x04L, 0x05L, 0x05L, 0x06L,
                0x03L, 0x04L, 0x04L, 0x05L, 0x04L, 0x05L, 0x05L, 0x06L,
                0x04L, 0x05L, 0x05L, 0x06L, 0x05L, 0x06L, 0x06L, 0x07L,
                0x02L, 0x03L, 0x03L, 0x04L, 0x03L, 0x04L, 0x04L, 0x05L,
                0x03L, 0x04L, 0x04L, 0x05L, 0x04L, 0x05L, 0x05L, 0x06L,
                0x03L, 0x04L, 0x04L, 0x05L, 0x04L, 0x05L, 0x05L, 0x06L,
                0x04L, 0x05L, 0x05L, 0x06L, 0x05L, 0x06L, 0x06L, 0x07L,
                0x03L, 0x04L, 0x04L, 0x05L, 0x04L, 0x05L, 0x05L, 0x06L,
                0x04L, 0x05L, 0x05L, 0x06L, 0x05L, 0x06L, 0x06L, 0x07L,
                0x04L, 0x05L, 0x05L, 0x06L, 0x05L, 0x06L, 0x06L, 0x07L,
                0x05L, 0x06L, 0x06L, 0x07L, 0x06L, 0x07L, 0x07L, 0x08L
};

static const uint32_t b_sum[256] = {
                0x00000000L, 0x01000000L, 0x01000000L, 0x02000000L, 0x01000000L, 0x02000000L, 0x02000000L, 0x03000000L,
                0x01000000L, 0x02000000L, 0x02000000L, 0x03000000L, 0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L,
                0x01000000L, 0x02000000L, 0x02000000L, 0x03000000L, 0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L,
                0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L, 0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L,
                0x01000000L, 0x02000000L, 0x02000000L, 0x03000000L, 0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L,
                0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L, 0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L,
                0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L, 0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L,
                0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L, 0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L,
                0x01000000L, 0x02000000L, 0x02000000L, 0x03000000L, 0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L,
                0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L, 0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L,
                0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L, 0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L,
                0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L, 0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L,
                0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L, 0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L,
                0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L, 0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L,
                0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L, 0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L,
                0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L, 0x05000000L, 0x06000000L, 0x06000000L, 0x07000000L,
                0x01000000L, 0x02000000L, 0x02000000L, 0x03000000L, 0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L,
                0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L, 0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L,
                0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L, 0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L,
                0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L, 0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L,
                0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L, 0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L,
                0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L, 0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L,
                0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L, 0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L,
                0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L, 0x05000000L, 0x06000000L, 0x06000000L, 0x07000000L,
                0x02000000L, 0x03000000L, 0x03000000L, 0x04000000L, 0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L,
                0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L, 0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L,
                0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L, 0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L,
                0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L, 0x05000000L, 0x06000000L, 0x06000000L, 0x07000000L,
                0x03000000L, 0x04000000L, 0x04000000L, 0x05000000L, 0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L,
                0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L, 0x05000000L, 0x06000000L, 0x06000000L, 0x07000000L,
                0x04000000L, 0x05000000L, 0x05000000L, 0x06000000L, 0x05000000L, 0x06000000L, 0x06000000L, 0x07000000L,
                0x05000000L, 0x06000000L, 0x06000000L, 0x07000000L, 0x06000000L, 0x07000000L, 0x07000000L, 0x08000000L
};

/* ^^ '1' a_bits count generator for this table

for (int s = 0, b = 0; s < 256; s++) {
b = 0;
for (int c = 0; c<8;c++) {
b += (s>>c) & 0x01L;
}
if (s % 8==0)fts::console::prints(stream,"\n");
fts::console::prints(stream,"%#04x000000, ",b);
}
_flushall();
fclose(stream);
return 1;
 */
//---------------------------------------------------------------------------
static uint32_t h[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//---------------------------------------------------------------------------

void __stdcall ts::hash::ssc1::reset_SSC1(void)
{
#ifdef __DEBUG_HASH_SSC1__
__DEBUG_FUNC_CALLED("")
#endif
for (register uint32_t i = 0; i < 32; i++) h[i] = 0;
}
//---------------------------------------------------------------------------

const uint32_t*  __stdcall ts::hash::ssc1::calc_SSC1(const void *a_data, const uint32_t a_len, const uint32_t a_bits)
{
#ifdef __DEBUG_HASH_SSC1__
__DEBUG_FUNC_CALLED("")
#endif
                // initialize ALL 32x hash variables - simple count in nibbles:
                int32_t n = (a_bits>>5) - 1;
                for (; n >= 0;  n--) h[n] = 0x00000000L;
                if (a_len==0) return (const uint32_t*)&h[n];
                //
                // Message last chunk (to prepare) & chunk pointer
                register int32_t B = (a_bits>>3); // count number hash BYTES -> chunk size
                uint8_t pB = ((int8_t*)a_data)[0], cB;
                char *data_chunk_ptr;
                register int32_t l, l_len = (a_len % B);
                static char last_data_chunk[32 * sizeof(int32_t)];
                // calculate chunk size, number of BYTES and hashes to calculate
                register uint32_t final_len = a_len + B - l_len;
                register uint32_t chunk_offset, H;
                register int32_t i;
                /* Pre-processing last message chunk*/
                for (l = l_len - 1, i = a_len - 1; l >= 0; l--) {
                                last_data_chunk[l] = ((int8_t*)a_data)[i--];
                }
                /* Fill rest of last chunk with chunk position indexes*/
                for (l = l_len; l < B; l++) {
                                last_data_chunk[l] = l;
                }
                /* Main Loop */
                for (chunk_offset = 0; chunk_offset < final_len; ) {
                                data_chunk_ptr = (char*)((uint8_t*)a_data + chunk_offset);
                                chunk_offset += B;
                                if (chunk_offset > a_len) data_chunk_ptr = (char*)&last_data_chunk;
                                //
                                for(i = 0;;) {
                                                for(H   = h[0]; i < B;) {
                                                                cB   = data_chunk_ptr[i];
                                                                H  += b_sum[cB];
                                                                H  += cB << d_shift[cB ^ pB];
                                                                pB   = cB;
                                                                if (((++i) % 0x10L == 0)) break;
                                                }
                                                // Add this chunk's hash to result so far
                                                h[0] = H;
                                                for(n = 0; n < h_num[B - 1]; n++) {
                                                                H  = h[n];
                                                                if ( H >= 0x10000000) h[n+1] += (H & 0xF0000000)>>0x04L;
                                                                if ((H  & 0x00FF0000)  >= 0x00010000) h[n+1] += (H & 0x00FF0000)>>0x10L;
                                                }
                                                if (i>=B) break;
                                }
                }
// cleanup & return hash value
                return &h[0];
}
//---------------------------------------------------------------------------

void  __stdcall ts::hash::ssc1::print_SSC1(void)
{
#ifdef __DEBUG_HASH_SSC1__
__DEBUG_FUNC_CALLED("")
#endif
                ts::con::prints("ssc1 HASH:\n");
                for (int32_t n = 0; n<32; n++) {
                                ts::con::prints("%#010x ", h[n]);
                                if ((n+1) % 4==0)
                                                ts::con::prints("\n");
                }
}
//---------------------------------------------------------------------------


