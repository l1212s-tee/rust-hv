SECTIONS
{
 . = 0xfffffffff0000000;
 .header : { *(.header) }
 . = ALIGN(16);
 .text : {
  __text_start = .;
  *(.text)
 }
 . = ALIGN(16);
 .rodata : { *(.rodata) }
 . = ALIGN(16);
 .data : { *(.data) }
 . = ALIGN(8);
 .init_array : {
  __init_array_start = .;
  *(SORT(.init_array.*)) *(.init_array)
  __init_array_end = .;
 }
 .units : {
  __unit_array_start = .;
  *(.units);
  __unit_array_end = .;
 }

 . = ALIGN((1 << 12));
 .console : { *(.console) }
 . = ALIGN((1 << 12));
 
 . = ALIGN(1 << 12);
 .data.rel.ro    : { *(.data.rel.ro) }
 . = ALIGN(1 << 12);
 .got        : { *(.got) }
 
 .bss : { *(.bss) }
 . = ALIGN((1 << 12));
 __page_pool = .;
 .eh_frame : { *(.eh_frame*) }
}
