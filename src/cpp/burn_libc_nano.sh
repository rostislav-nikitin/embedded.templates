#! /bin/sh

openocd -f board/st_nucleo_g0.cfg -c "init;targets;halt;flash write_image erase build/firmware_libc_nano.elf;shutdown"
