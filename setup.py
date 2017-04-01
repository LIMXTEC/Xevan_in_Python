from distutils.core import setup, Extension

xevan_hash_module = Extension('xevan_hash',
                                 sources = ['xevanmodule.c',
                                            'xevanhash.c',
                                            'sha3/blake.c',
                                            'sha3/bmw.c',
                                            'sha3/groestl.c',
                                            'sha3/skein.c',
                                            'sha3/jh.c',
                                            'sha3/keccak.c',
                                            'sha3/luffa.c',
                                            'sha3/cubehash.c',
                                            'sha3/shavite.c',
                                            'sha3/simd.c',
                                            'sha3/echo.c',
                                            'sha3/hamsi.c',
                                            'sha3/fugue.c',
                                            'sha3/shabal.c',
                                            'sha3/whirlpool.c',
                                            'sha3/sph_sha2big.c',
                                            'sha3/haval.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'xevan_hash',
       version = '0.1-test',
       description = 'Binding for xevan proof of work hashing.',
       ext_modules = [xevan_hash_module])
