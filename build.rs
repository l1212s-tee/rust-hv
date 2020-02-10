extern crate cc;

fn main() {
    cc::Build::new()
        .file("src/header.c")
        .compile("libheader.a");
}
