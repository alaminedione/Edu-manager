#!/bin/bash

gcc -o EduManager gestion_etudiant.c main.c

if [ $? -eq 0 ]; then
    echo "Compilation réussie !"
else
    echo "Échec de la compilation."
fi
