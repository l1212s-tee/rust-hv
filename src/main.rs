#![no_std]
#![no_main]
#![feature(global_asm)]
#![feature(lang_items)]
#![feature(start)]

use core::panic::PanicInfo;

global_asm!(include_str!("arch/x86/entry.S"));

#[lang = "eh_personality"]
extern "C" fn eh_personality() {}

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop { }
}

#[no_mangle]
pub extern "C" fn entry() -> ! {
    loop { }
}
