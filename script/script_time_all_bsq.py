#!/bin/python3

import csv
import subprocess
import time
import os
from sys import argv
from enum import Enum
from concurrent.futures import ThreadPoolExecutor

BIN_NAME = "bsq_learn"
BSQ_MAP_DEFAULT = "../bsq_map/map_default/"
BSQ_MAP_RESOLVE = "../bsq_map/map_resolve/"

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    RESET = "\033[0;0m"

class MODE(Enum):
    DEFAULT = 0
    ONLY = 1
    EXCLUDE = 2

def update_csv(path, data):
    with open(path, 'r', newline='') as read_csvfile:
        reader = csv.DictReader(read_csvfile)
        rows = list(reader)

    updated = False

    for row in rows:
        if row['Language'] == data['Language']:
            for key in data.keys():
                row[key] = data[key]
            updated = True
            break
    if not updated:
        rows.append(data)

    with open(path, 'w', newline='') as write_csvfile:
        writer = csv.DictWriter(write_csvfile, fieldnames=data.keys())
        writer.writeheader()
        writer.writerows(rows)

def get_subdirectories():
    current_directory = "../"
    directories = [d for d in os.listdir(current_directory) if os.path.isdir(os.path.join(current_directory, d))]
    bsq_directories = [d for d in directories if os.path.isfile(os.path.join(current_directory, d, ".bsq"))]
    return bsq_directories

def execute_and_measure_time(language, executable_path, map_path):
    tmp_file = f"tmp_{language}_{map_path}"
    try:
        with open(tmp_file, 'w') as f, \
             open("/dev/null", 'w') as null:
            start_time = time.time()
            result = subprocess.run(f"{executable_path} {BSQ_MAP_DEFAULT}{map_path}", stdout=f, stderr=null, shell=True)
            end_time = time.time()
            execution_time = end_time - start_time
            result = subprocess.run(f"diff {tmp_file} {BSQ_MAP_RESOLVE}{map_path}", stdout=null, shell=True)
            return_code = result.returncode
            print(f"{bcolors.HEADER}Exec {map_path}{bcolors.RESET}")
            print(f"\ttime\t: {bcolors.WARNING}{execution_time:.5f}s{bcolors.RESET}")
            if return_code == 0:
                print(f"\tresult\t: {bcolors.OKGREEN}[OK]{bcolors.RESET}")
            else:
                print(f"\tresult\t: {bcolors.FAIL}[KO]{bcolors.RESET}")
            return execution_time, return_code
    finally:
        if os.path.exists(tmp_file):
            os.remove(tmp_file)

def makefile_is_present(directory):
    return os.path.isfile(os.path.join(directory, "Makefile"))

def is_bsq_directory(directory):
    return os.path.isfile(os.path.join(directory, ".bsq"))

def exec_all_map(bin):
    language = bin.split("/")[-1]
    files = os.listdir(BSQ_MAP_DEFAULT)
    data_time = {'Language': language}
    data_return = {'Language': language}

    def process_map(map_file):
        execution_time, return_code = execute_and_measure_time(language, bin + "/" + BIN_NAME, map_file)
        data_time[map_file] = execution_time
        data_return[map_file] = return_code

    with ThreadPoolExecutor() as executor:
        executor.map(process_map, files)

    update_csv("../data/time_value.csv", data_time)
    update_csv("../data/return_value.csv", data_return)

def make_binary(path):
    if not is_bsq_directory(path):
        return False
    if makefile_is_present(path):
        subprocess.run(f"make --silent -C {path}", shell=True)
    return True

def test_bsq(path):
    if not make_binary("../" + path):
        return
    print(f"{bcolors.OKCYAN}{{==== START {path} BSQ ====}}{bcolors.RESET}")
    exec_all_map("../" + path)
    print(f"{bcolors.OKCYAN}{{====  END {path} BSQ  ====}}{bcolors.RESET}")

def only_dirs(dirs):
    return [d for d in dirs if d in argv[2:]]

def exclude_dirs(dirs):
    return [d for d in dirs if d not in argv[2:]]

def test_all_bsq():
    dirs = get_subdirectories()
    if mode == MODE.ONLY:
        dirs = only_dirs(dirs)
    if mode == MODE.EXCLUDE:
        dirs = exclude_dirs(dirs)
    with ThreadPoolExecutor() as executor:
        executor.map(test_bsq, dirs)

def argv_handling():
    if len(argv) == 1:
        return MODE.DEFAULT
    if len(argv) == 2:
        print(f"{bcolors.FAIL}NOT ENOUGH ARGUMENT{bcolors.RESET}")
        exit(84)
    if argv[1] == "--only":
        return MODE.ONLY
    if argv[1] == "--exclude":
        return MODE.EXCLUDE

mode = argv_handling()

def main():
    test_all_bsq()

if __name__ == "__main__":
    main()

