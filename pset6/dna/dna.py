import csv
import sys

def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    database_file = sys.argv[1]
    sequence_file = sys.argv[2]

    # Ler as sequências STR do arquivo CSV
    with open(database_file, newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        headers = reader.fieldnames
        data = [row for row in reader]

    # Ler a sequência de DNA do arquivo de texto
    with open(sequence_file, 'r') as sequence_file:
        sequence = sequence_file.read()

    # Calcular as contagens de STR na sequência de DNA
    str_counts = {}
    for header in headers[1:]:
        str_counts[header] = max_str_repeat(sequence, header)

    # Comparar contagens de STR com o banco de dados
    match = find_match(data, str_counts)

    if match:
        print(match['name'])
    else:
        print("No match")

def max_str_repeat(sequence, str_pattern):
    max_repeats = 0
    current_repeats = 0
    str_len = len(str_pattern)

    i = 0
    while i < len(sequence):
        if sequence[i:i + str_len] == str_pattern:
            current_repeats += 1
            i += str_len
        else:
            current_repeats = 0
            i += 1

        max_repeats = max(max_repeats, current_repeats)

    return max_repeats

def find_match(data, str_counts):
    for row in data:
        match = True
        for key, value in str_counts.items():
            if int(row[key]) != value:
                match = False
                break
        if match:
            return row

    return None

if __name__ == "__main__":
    main()
