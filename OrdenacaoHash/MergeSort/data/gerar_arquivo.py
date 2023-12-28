import pandas as pd
import random

def gerar_csv(numRegistros: int) -> None:
    dre_val = [random.randint(10**8, 10**9 - 1) for _ in range(numRegistros)]

    df = pd.DataFrame({"DRE": dre_val})

    df.to_csv("DRE.csv", index=False)

if __name__ == "__main__":
    numRegistros = int(input("Insira número de registros: "))
    gerar_csv(numRegistros)
    print(f"CSV com {numRegistros} linhas gerado")
    
