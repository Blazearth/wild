ENTRY(_start)

text_start = SEGMENT_START("text", 0x10);
rodata_start = SEGMENT_START("rodata", 0x11);
data_start = SEGMENT_START("data", 0x12);
bss_start = SEGMENT_START("bss", 0x13);

SECTIONS {
  . = 0x600000;
  .text : {
    *(.text .text.*)
  }
  .rodata : { *(.rodata .rodata.*) }
  .data : { *(.data .data.*) }
  .bss : { *(.bss .bss.*) }
}
