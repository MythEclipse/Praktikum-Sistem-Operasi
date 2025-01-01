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
        set filename=%%~nf
        gcc -o !filename! %%f > !filename!_compile_log.txt 2>&1
        if !errorlevel! == 0 (
            echo Kompilasi berhasil, menjalankan program...
            call !filename! > !filename!_run_log.txt 2>&1
        ) else (
            echo Kompilasi gagal, lihat !filename!_compile_log.txt untuk detail.
        )
        goto end
    )
    set /a i=!i!+1
)

REM Jika input tidak valid
echo Pilihan tidak valid.

:end
