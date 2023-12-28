import csv
import random

def gerar_dre() -> int:
    return random.randint(10**8, 10**9 - 1)

def gerar_csv(path, num_registros) -> None:
    with open(path, "w", newline = "") as csvfile:
        colunas = ["DRE"]
        writer = csv.DictWriter(csvfile, fieldnames = colunas)

        writer.writeheader()
        for _ in range(num_registros):
            dre = gerar_dre()
            writer.writerow({"DRE": dre})

if __name__ == "__main__":
    output_file = "DRE.csv"
    num_registros = int(input("Insira o número de registros: "))

    gerar_csv(output_file, num_registros)
    print(f"{num_registros} registros salvos em  {output_file}.")
