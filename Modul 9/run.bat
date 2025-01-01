@echo off
setlocal enabledelayedexpansion

REM Mendapatkan daftar file .c di direktori
set i=1
echo Pilih file yang ingin dijalankan:
for %%f in (*.c) do (
    echo !i!. %%f
    set /a i=!i!+1
)

REM Meminta input dari pengguna
set /p choice="Masukkan nomor file yang ingin dijalankan: "

REM Menghitung file yang dipilih dan menjalankannya
set i=1
for %%f in (*.c) do (
    if !i! == %choice% (
        echo Meng-compile dan menjalankan %%f...
        gcc -o %%~nf %%f && %%~nf
        goto end
    )
    set /a i=!i!+1
)

REM Jika input tidak valid
echo Pilihan tidak valid.

:end
