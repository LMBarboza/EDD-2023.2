from typing import Optional, Tuple
import pandas as pd

class HashTable:
    def __init__(self, size: int) -> None:
        self.size: int = size
        self.table: List[Optional[Tuple[int, Any]]] = [None] * self.size

    def _hash(self, key: int) -> int:
        return key % self.size

    def insert(self, key: int, data: any) -> None:
        index: int = self._hash(key)
        while self.table[index] is not None:
            index = (index + 1) % self.size
        self.table[index] = (key, data)

    def search(self, key: int) -> Optional[any]:
        index: int = self._hash(key)
        while self.table[index] is not None:
            if self.table[index][0] == key:
                return self.table[index][1]
            index = (index + 1) % self.size
        return None

    def remove(self, key: int) -> bool:
        index: int = self._hash(key)
        while self.table[index] is not None:
            if self.table[index][0] == key:
                self.table[index] = None
                return True
            index = (index - 1) % self.size
        return False

def remove_duplicates_from_csv(file_path):
    df = pd.read_csv(file_path)
    hash_table = HashTable(len(df)) 
    key_values = df["DRE"]
    data_val = df ["nota"]
    for key, data in zip(key_values, data_val):
        key = int(key)
        if hash_table.search(key) is None:
            hash_table.insert(key, data)

    return hash_table

if __name__ == "__main__":
    file_path = "../data/DRE.csv"
    result_hash_table = remove_duplicates_from_csv(file_path)
    print(result_hash_table.table)
