import os
import pandas as pd
import tempfile

class MergeSortExterno:
    def __init__(self, input_file: str, output_file: str, chunk_size: int) -> None:
        self.input_file = input_file
        self.output_file = output_file
        self.chunk_size = chunk_size
        self.run_files = []

    def sort_runs(self) -> None:
        chunks = pd.read_csv(self.input_file, header=None, names = ["DRE"], chunksize = self.chunk_size)

        for i, chunk in enumerate(chunks):
            if i == 0:
                continue
            chunk["DRE"] = chunk["DRE"].astype(int)
            chunk = chunk.sort_values(by = "DRE")

            temp_file = tempfile.NamedTemporaryFile(delete = False)
            self.run_files.append(temp_file.name)
            chunk.to_csv(temp_file.name, header = False, index = False)

    def merge_runs(self) -> None:
        while len(self.run_files) > 1:
            merge_run_files = []
            for i in range(0, len(self.run_files), 2):
                if i + 1 < len(self.run_files):
                    merged_run = self.merge_duas_runs(self.run_files[i], self.run_files[i + 1])
                    merge_run_files.append(merged_run)
                else:
                    merge_run_files.append(self.run_files[i])

            self.run_files = merge_run_files

    def merge_duas_runs(self, run1: str, run2: str) -> str:
        merged_run = tempfile.NamedTemporaryFile(delete = False)
        df1 = pd.read_csv(run1, header = None, names = ["DRE"])
        df2 = pd.read_csv(run2, header = None, names = ["DRE"])

        df1["DRE"] = df1["DRE"].astype(int)
        df2["DRE"] = df2["DRE"].astype(int)

        merged_df = pd.concat([df1, df2]).sort_values(by = "DRE")
        merged_df.to_csv(merged_run.name, header = False, index = False)

        return merged_run.name

    def output_run(self) -> None:
        os.rename(self.run_files[0], self.output_file)

def main():
    input_file = "../data/DRE.csv"
    output_file = "../data/DRE_ordenado.csv"
    num_chunks = int(input("Insira o tamanho das runs: "))    
    external_sort = MergeSortExterno(input_file, output_file, num_chunks)
    external_sort.sort_runs()
    external_sort.merge_runs()
    external_sort.output_run()

if __name__ == "__main__":
    main()
