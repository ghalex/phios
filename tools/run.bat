@ECHO OFF
ECHO Starting phiOS
CD qemu
qemu -L "." -fda a: -no-kqemu
CD .. 