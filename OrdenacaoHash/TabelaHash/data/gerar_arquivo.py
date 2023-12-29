import pandas as pd
import random

def gerar_csv(numRegistros: int, numRepeticoes: int) -> None:
    dre_val = [random.randint(10**8, 10**9 - 1) for _ in range(numRegistros)]
    notas_val = [round(random.uniform(0, 10), 2) for _ in range(numRegistros)]

    df = pd.DataFrame({"DRE": dre_val, "nota": notas_val})
    duplicadas = random.sample(range(numRegistros), numRepeticoes)
    lin_duplicadas = df.iloc[duplicadas]

    df = pd.concat([df, lin_duplicadas], ignore_index=True)
    df.to_csv("DRE.csv", index=False)

if __name__ == "__main__":
    numRegistros = int(input("Insira número de registros: "))
    numRepeticoes = int(input("Insira número de repetições: "))
    
    gerar_csv(numRegistros, numRepeticoes)
    print(f"CSV com {numRegistros + numRepeticoes} linhas gerado")
