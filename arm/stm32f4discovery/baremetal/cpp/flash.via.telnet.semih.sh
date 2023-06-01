#!/usr/bin/expect
set timeout 20
spawn telnet localhost 4444

send "reset halt\n"
set timeout 5

send "flash write_image erase firmware_semih.elf\n"
set timeout 10

send "arm semihosting enable\n"
set timeout 10

send "reset\n"
set timeout 10

send "exit\n"
set timeout 10

interact
