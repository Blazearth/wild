//#AbstractConfig:default
//#Object:runtime.c
//#CompArgs:-g -fmerge-constants -fPIC
//#ReferenceLinkers:

//#Config:only-keep-debug:default
//#LinkArgs:--only-keep-debug
//#RunEnabled:false
//#DiffEnabled:false
//#TestOnlyKeepDebug:true
//#ExpectSym:_start
//#ExpectSym:exit_syscall
//#ExpectSection:.symtab

//#Config:only-keep-debug-compressed:default
//#LinkArgs:--only-keep-debug --compress-debug-sections=zlib
//#RunEnabled:false
//#DiffEnabled:false
//#TestOnlyKeepDebug:true
//#ExpectSym:_start

//#Config:only-keep-debug-build-id:default
//#LinkArgs:--only-keep-debug --build-id=0x123456789abcdef0
//#RunEnabled:false
//#DiffEnabled:false
//#TestOnlyKeepDebug:true
//#ExpectSym:_start

//#Config:only-keep-debug-dynamic:default
//#Mode:dynamic
//#Shared:shared.c
//#LinkArgs:--only-keep-debug -z now
//#RunEnabled:false
//#DiffEnabled:false
//#TestOnlyKeepDebug:true
//#ExpectSym:_start

//#Config:only-keep-debug-shared:default
//#Mode:dynamic
//#LinkArgs:-shared --only-keep-debug
//#RunEnabled:false
//#DiffEnabled:false
//#TestOnlyKeepDebug:true
//#ExpectSym:_start

#include "../common/runtime.h"

int global_var = 42;

const char* msg1 = "non-debug merged string";
const char* msg2 = "non-debug merged string";

__attribute__((weak)) int shared_func(int x);

void _start(void) {
  runtime_init();
  int val = global_var;
  if (shared_func) {
    val = shared_func(val);
  }
  if (msg1[0] == msg2[0]) {
    val += 1;
  }
  exit_syscall(val);
}

