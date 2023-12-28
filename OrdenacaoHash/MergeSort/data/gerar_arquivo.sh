#!/bin/bash

output_file="DRE.csv"
echo "Insira o número de registros a serem gerados: "
read num_registros

# Function to generate a random 9-digit number
gerar_dre() {
    echo $((100000000 + RANDOM % 900000000))
}

echo "DRE" > "$output_file"  

for ((i = 0; i < num_registros; i++)); do
    dre=$(gerar_dre)
    echo "$dre" >> "$output_file"
done

echo "Arquivo CSV gerado: $output_file"
