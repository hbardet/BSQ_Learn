#!/bin/python3

import csv

def read_csv(file_path):
    with open(file_path, 'r') as file:
        reader = csv.reader(file)
        rows = list(reader)
    return rows

def process_data(times, returns):
    header = times[0]
    processed_data = [header]
    
    for time_row, return_row in zip(times[1:], returns[1:]):
        processed_row = [time_row[0]]  # Start with the language
        for time, ret in zip(time_row[1:], return_row[1:]):
            if ret == '1':
                processed_row.append("CRASH")
            else:
                try:
                    processed_row.append(f"{float(time):.3f}")
                except ValueError:
                    processed_row.append(time)
        processed_data.append(processed_row)
    
    return processed_data

def csv_to_markdown(data):
    col_widths = [max(len(str(cell)) for cell in column) for column in zip(*data)]
    
    markdown_table = []
    header = data[0]
    markdown_table.append("| " + " | ".join(f"{cell:<{col_widths[i]}}" for i, cell in enumerate(header)) + " |")
    markdown_table.append("|" + "|".join("-" * (col_widths[i] + 2) for i in range(len(header))) + "|")
    
    for row in data[1:]:
        markdown_table.append("| " + " | ".join(f"{cell:<{col_widths[i]}}" for i, cell in enumerate(row)) + " |")
    
    return "\n".join(markdown_table)

# Example usage
times_file = "../data/time_value.csv" 
returns_file = "../data/return_value.csv"

times_data = read_csv(times_file)
returns_data = read_csv(returns_file)
processed_data = process_data(times_data, returns_data)
markdown_table = csv_to_markdown(processed_data)

# Print the markdown table to stdout
print(markdown_table)
