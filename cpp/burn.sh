#! /bin/bash

openocd -f board/st_nucleo_g0.cfg -c "init;targets;halt;flash write_image erase build/firmware.elf;shutdown"
