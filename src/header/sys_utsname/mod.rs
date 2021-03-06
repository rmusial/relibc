//! sys/utsname implementation for linux, following http://pubs.opengroup.org/onlinepubs/7908799/xsh/sysutsname.h.html

use platform::types::*;

pub const UTSLENGTH: usize = 65;

#[repr(C)]
pub struct utsname {
    pub sysname: [c_char; UTSLENGTH],
    pub nodename: [c_char; UTSLENGTH],
    pub release: [c_char; UTSLENGTH],
    pub version: [c_char; UTSLENGTH],
    pub machine: [c_char; UTSLENGTH],
    pub domainname: [c_char; UTSLENGTH],
}

#[cfg(target_os = "linux")]
mod inner {
    use super::*;
    use platform::{Pal, Sys};

    #[no_mangle]
    pub unsafe extern "C" fn uname(uts: *mut utsname) -> c_int {
        Sys::uname(uts)
    }
}
#[cfg(target_os = "linux")]
pub use self::inner::*;
