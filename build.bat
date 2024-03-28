cl.exe -nologo  /fp:fast /O1 /GS- /Gs1000000000 main.c -link -nodefaultlib -subsystem:windows User32.lib Dwmapi.lib msvcrt.lib Kernel32.lib /stack:0x200000,200000 
