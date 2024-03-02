#!/bin/bash

gcc -o application_v_2 gestion_etudiant.c main.c

if [ $? -eq 0 ]; then
    echo "Compilation réussie !"
else
    echo "Échec de la compilation."
fi
