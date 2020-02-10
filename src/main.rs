#![no_std]
#![no_main]
#![feature(global_asm)]
#![feature(lang_items)]
#![feature(start)]

use core::panic::PanicInfo;

global_asm!(include_str!("entry.S"));

#[lang = "eh_personality"]
extern "C" fn eh_personality() {}

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop { }
}

//#[start]
//fn main(_argc: isize, _: argv *const *const u8) {

#[no_mangle] // don't mangle the name of this function
pub extern "C" fn entry() -> ! {
    loop { }
//    println!("Hello, world!");
}
