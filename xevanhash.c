#include "xevanhash.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sha3/sph_blake.h"
#include "sha3/sph_bmw.h"
#include "sha3/sph_groestl.h"
#include "sha3/sph_jh.h"
#include "sha3/sph_keccak.h"
#include "sha3/sph_skein.h"
#include "sha3/sph_luffa.h"
#include "sha3/sph_cubehash.h"
#include "sha3/sph_shavite.h"
#include "sha3/sph_simd.h"
#include "sha3/sph_echo.h"
#include "sha3/sph_hamsi.h"
#include "sha3/sph_fugue.h"
#include "sha3/sph_shabal.h"
#include "sha3/sph_whirlpool.h"
#include "sha3/sph_sha2.h"
#include "sha3/sph_haval.h"


void xevan_hash(const char* input, char* output)
{
    sph_blake512_context     ctx_blake;
    sph_bmw512_context       ctx_bmw;
    sph_groestl512_context   ctx_groestl;
    sph_skein512_context     ctx_skein;
    sph_jh512_context        ctx_jh;
    sph_keccak512_context    ctx_keccak;

    sph_luffa512_context		ctx_luffa1;
    sph_cubehash512_context		ctx_cubehash1;
    sph_shavite512_context		ctx_shavite1;
    sph_simd512_context		ctx_simd1;
    sph_echo512_context		ctx_echo1;
	
	sph_hamsi512_context		ctx_hamsi;
    sph_fugue512_context		ctx_fugue;
    sph_shabal512_context		ctx_shabal;
    sph_whirlpool_context		ctx_whirlpool;
    sph_sha512_context		    ctx_sha2;
	
	sph_haval256_5_context		ctx_haval;
    

    
    uint32_t hashA[32], hashB[32];
	memset(hashA , 0, 128);
	memset(hashB , 0, 128);

    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, input, 80);
    sph_blake512_close (&ctx_blake, hashA);

    sph_bmw512_init(&ctx_bmw);
    sph_bmw512 (&ctx_bmw, hashA, 128);
    sph_bmw512_close(&ctx_bmw, hashB);

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512 (&ctx_groestl, hashB, 128);
    sph_groestl512_close(&ctx_groestl, hashA);

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, hashA, 128);
    sph_skein512_close (&ctx_skein, hashB);

    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, hashB, 128);
    sph_jh512_close(&ctx_jh, hashA);

    sph_keccak512_init(&ctx_keccak);
    sph_keccak512 (&ctx_keccak, hashA, 128);
    sph_keccak512_close(&ctx_keccak, hashB);

    sph_luffa512_init (&ctx_luffa1);
    sph_luffa512 (&ctx_luffa1, hashB, 128);
    sph_luffa512_close (&ctx_luffa1, hashA);

    sph_cubehash512_init (&ctx_cubehash1);
    sph_cubehash512 (&ctx_cubehash1, hashA, 128);
    sph_cubehash512_close(&ctx_cubehash1, hashB);

    sph_shavite512_init (&ctx_shavite1);
    sph_shavite512 (&ctx_shavite1, hashB, 128);
    sph_shavite512_close(&ctx_shavite1, hashA);

    sph_simd512_init (&ctx_simd1);
    sph_simd512 (&ctx_simd1, hashA, 128);
    sph_simd512_close(&ctx_simd1, hashB);

    sph_echo512_init (&ctx_echo1);
    sph_echo512 (&ctx_echo1, hashB, 128);
    sph_echo512_close(&ctx_echo1, hashA);
	
	
	sph_hamsi512_init(&ctx_hamsi);
    sph_hamsi512 (&ctx_hamsi, hashA, 128);
    sph_hamsi512_close(&ctx_hamsi, hashB);

    sph_fugue512_init(&ctx_fugue);
    sph_fugue512 (&ctx_fugue, hashB, 128);
    sph_fugue512_close(&ctx_fugue, hashA);

    sph_shabal512_init(&ctx_shabal);
    sph_shabal512 (&ctx_shabal, hashA, 128);
    sph_shabal512_close(&ctx_shabal, hashB);

    sph_whirlpool_init(&ctx_whirlpool);
    sph_whirlpool (&ctx_whirlpool, hashB, 128);
    sph_whirlpool_close(&ctx_whirlpool, hashA);

    sph_sha512_init(&ctx_sha2);
    sph_sha512 (&ctx_sha2, hashA, 128);
    sph_sha512_close(&ctx_sha2, hashB);

    sph_haval256_5_init(&ctx_haval);
    sph_haval256_5 (&ctx_haval, hashB, 128);
    sph_haval256_5_close(&ctx_haval, hashA);
	memset(&hashA[8], 0, 128 - 32);
	
	
    ///  Part2
    sph_blake512_init(&ctx_blake);
    sph_blake512 (&ctx_blake, hashA, 128);
    sph_blake512_close(&ctx_blake, hashB);
    
    sph_bmw512_init(&ctx_bmw);
    sph_bmw512 (&ctx_bmw, hashB, 128);
    sph_bmw512_close(&ctx_bmw, hashA);

    sph_groestl512_init(&ctx_groestl);
    sph_groestl512 (&ctx_groestl, hashA, 128);
    sph_groestl512_close(&ctx_groestl, hashB);

    sph_skein512_init(&ctx_skein);
    sph_skein512 (&ctx_skein, hashB, 128);
    sph_skein512_close(&ctx_skein, hashA);
    
    sph_jh512_init(&ctx_jh);
    sph_jh512 (&ctx_jh, hashA, 128);
    sph_jh512_close(&ctx_jh, hashB);
    
    sph_keccak512_init(&ctx_keccak);
    sph_keccak512 (&ctx_keccak, hashB, 128);
    sph_keccak512_close(&ctx_keccak, hashA);

    sph_luffa512_init(&ctx_luffa1);
    sph_luffa512 (&ctx_luffa1, hashA, 128);
    sph_luffa512_close(&ctx_luffa1, hashB);
    
    sph_cubehash512_init(&ctx_cubehash1);
    sph_cubehash512 (&ctx_cubehash1, hashB, 128);
    sph_cubehash512_close(&ctx_cubehash1, hashA);
    
    sph_shavite512_init(&ctx_shavite1);
    sph_shavite512(&ctx_shavite1, hashA, 128);
    sph_shavite512_close(&ctx_shavite1, hashB);
        
    sph_simd512_init(&ctx_simd1);
    sph_simd512 (&ctx_simd1, hashB, 128);
    sph_simd512_close(&ctx_simd1, hashA);

    sph_echo512_init(&ctx_echo1);
    sph_echo512 (&ctx_echo1, hashA, 128);
    sph_echo512_close(&ctx_echo1, hashB);

    sph_hamsi512_init(&ctx_hamsi);
    sph_hamsi512 (&ctx_hamsi, hashB, 128);
    sph_hamsi512_close(&ctx_hamsi, hashA);

    sph_fugue512_init(&ctx_fugue);
    sph_fugue512 (&ctx_fugue, hashA, 128);
    sph_fugue512_close(&ctx_fugue, hashB);

    sph_shabal512_init(&ctx_shabal);
    sph_shabal512 (&ctx_shabal, hashB, 128);
    sph_shabal512_close(&ctx_shabal, hashA);

    sph_whirlpool_init(&ctx_whirlpool);
    sph_whirlpool (&ctx_whirlpool, hashA, 128);
    sph_whirlpool_close(&ctx_whirlpool, hashB);

    sph_sha512_init(&ctx_sha2);
    sph_sha512 (&ctx_sha2, hashB, 128);
    sph_sha512_close(&ctx_sha2, hashA);

    sph_haval256_5_init(&ctx_haval);
    sph_haval256_5 (&ctx_haval, hashA, 128);
    sph_haval256_5_close(&ctx_haval, hashB);


    memcpy(output, hashB, 32);

}
/*{
   "hash": "0000000011ef47bda57dd19a0e71095180dff37b7724822448eb8cd46367576c",
   "confirmations": 4,
   "size": 239,
   "height": 290119,
   "version": 3,
   "merkleroot": "8dbadda0221ced1790e3ed0cc5568552938cf173c720d2a3fb1deca11bf2e481",
   "tx": [
      "8dbadda0221ced1790e3ed0cc5568552938cf173c720d2a3fb1deca11bf2e481"
   ],
   "time": 1491025717,
   "nonce": 52385877,
   "bits": "1c5b0f5a",
   "difficulty": 2.81129131,
   "chainwork": "000000000000000000000000000000000000000000000000005bc1dc7502241c",
   "previousblockhash": "00000000a0cbaccc11e43d5db4d8865efcb7907972d8ff7a6fa1db480608307f",
   "nextblockhash": "00000000138948e2401897a9a179a2226c7557869e1833633a0cdf9a74f109b2"
}*/

