//#AbstractConfig:base
// Nix's linker wrapper otherwise removes --sysroot arguments.
//#Env:NIX_ENFORCE_PURITY=0
//#ReferenceLinkers:bfd,lld
//#Object:runtime.c
//#Archive:as(first/lib/libvalue.a),noadd:first.c
//#Archive:as(last/lib/libvalue.a),noadd:last.c
//#PostLinkArgs:-lvalue
//#ExpectSym:last_root
//#NoSym:first_root

//#Config:library-before-sysroots:base
//#LinkArgs:-L=/lib --sysroot=$OUT_DIR/first --sysroot=$OUT_DIR/last

//#Config:library-between-sysroots:base
// LLD 21 does not expand $SYSROOT in library search paths.
//#ReferenceLinkers:bfd
//#LinkArgs:--sysroot=$OUT_DIR/first -L$SYSROOT/lib --sysroot=$OUT_DIR/last

//#Config:library-after-sysroots:base
//#LinkArgs:--sysroot=$OUT_DIR/first --sysroot=$OUT_DIR/last -L=/lib

//#Config:save-library-before-sysroots:base
//#ReferenceLinkers:
//#DriverMode:save-dir-response
//#LinkArgs:-L=/lib --sysroot=$OUT_DIR/first --sysroot=$OUT_DIR/last

//#Config:save-library-between-sysroots:base
//#ReferenceLinkers:
//#DriverMode:save-dir-response
//#LinkArgs:--sysroot=$OUT_DIR/first -L$SYSROOT/lib --sysroot=$OUT_DIR/last

//#Config:library-without-sysroot:base
//#ReferenceLinkers:
//#LinkArgs:-L=$OUT_DIR/last/lib

//#Config:save-library-without-sysroot:base
//#ReferenceLinkers:
//#DriverMode:save-dir-response
//#LinkArgs:-L=$OUT_DIR/last/lib

//#AbstractConfig:script-base
//#Env:NIX_ENFORCE_PURITY=0
//#ReferenceLinkers:bfd
//#Object:runtime.c
//#Archive:as(first/lib/libvalue.a),noadd:first.c
//#Archive:as(last/lib/libvalue.a),noadd:last.c
//#ExpectSym:last_root
//#NoSym:first_root

//#Config:script-forced-equals:script-base
//#LinkArgs:--sysroot=$OUT_DIR/last
//#AugmentLinkerScript:script-equals.ld

//#Config:save-script-forced-equals:script-base
//#ReferenceLinkers:
//#DriverMode:save-dir-response
//#LinkArgs:--sysroot=$OUT_DIR/last
//#AugmentLinkerScript:script-equals.ld

//#Config:script-forced-sysroot-var:script-base
//#LinkArgs:--sysroot=$OUT_DIR/last
//#AugmentLinkerScript:script-sysroot-var.ld

//#Config:save-script-forced-sysroot-var:script-base
//#ReferenceLinkers:
//#DriverMode:save-dir-response
//#LinkArgs:--sysroot=$OUT_DIR/last
//#AugmentLinkerScript:script-sysroot-var.ld

//#Config:forced-file-equals:script-base
//#LinkArgs:--sysroot=$OUT_DIR/last
//#PostLinkArgs:=/lib/libvalue.a

//#Config:forced-file-sysroot-var:script-base
//#LinkArgs:--sysroot=$OUT_DIR/last
//#PostLinkArgs:$SYSROOT/lib/libvalue.a

//#Config:forced-file-equals-no-sysroot:script-base
//#ReferenceLinkers:
//#PostLinkArgs:=$OUT_DIR/last/lib/libvalue.a

//#Config:save-forced-file-sysroot-var-no-sysroot:script-base
//#ReferenceLinkers:
//#DriverMode:save-dir-response
//#PostLinkArgs:$SYSROOT$OUT_DIR/last/lib/libvalue.a

//#Config:save-forced-file-equals-no-sysroot:script-base
//#ReferenceLinkers:
//#DriverMode:save-dir-response
//#PostLinkArgs:=$OUT_DIR/last/lib/libvalue.a

//#Config:script-forced-equals-no-sysroot:script-base
//#ReferenceLinkers:
//#AugmentLinkerScript:script-equals-no-sysroot.ld

//#Config:save-script-forced-equals-no-sysroot:script-base
//#ReferenceLinkers:
//#DriverMode:save-dir-response
//#AugmentLinkerScript:script-equals-no-sysroot.ld

//#Config:script-forced-sysroot-var-no-sysroot:script-base
//#ReferenceLinkers:
//#AugmentLinkerScript:script-sysroot-var-no-sysroot.ld

//#Config:save-script-forced-sysroot-var-no-sysroot:script-base
//#ReferenceLinkers:
//#DriverMode:save-dir-response
//#AugmentLinkerScript:script-sysroot-var-no-sysroot.ld

#include "../common/runtime.h"

int value(void);

void _start(void) {
  runtime_init();
  exit_syscall(value());
}
