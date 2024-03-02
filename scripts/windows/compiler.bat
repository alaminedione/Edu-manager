@echo on

gcc -o EduManager gestion_etudiant.c main.c

@echo off

if %ERRORLEVEL% equ 0 (
    echo Compilation reussie !
) else (
    echo Echec de la compilation.
) quel est l'extension de ce fichier
