#!/bin/python3

import csv
import subprocess
import time
import os
from datetime import datetime

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


def get_subdirectories():
    current_directory = "../"   # Obtient le répertoire de travail actuel
    directories = [d for d in os.listdir(current_directory) if os.path.isdir(os.path.join(current_directory, d))]
    return directories

def execute_and_measure_time(executable_path, map_path):
    with open("tmp", 'w') as f, \
        open("/dev/null", 'w') as null:
            print(f"{bcolors.HEADER}Exec {map_path}");
            start_time = time.time()
            result = subprocess.run(executable_path + " " + BSQ_MAP_DEFAULT + map_path, stdout=f ,stderr=null, shell=True)
            end_time = time.time()
            execution_time = end_time - start_time
            result = subprocess.run("diff tmp " + BSQ_MAP_RESOLVE + map_path, stdout=null, shell=True)
            result = result.returncode
            print(f"\ttime\t: {bcolors.WARNING}{execution_time:.5f}s{bcolors.HEADER}")
            if (not result):
                print(f"\tresult\t: {bcolors.OKGREEN}[OK]{bcolors.HEADER}")
            else :
                print(f"\tresult\t: {bcolors.FAIL}[KO]{bcolors.HEADER}")
            return execution_time, result

def makefile_is_present(directory):
    files = os.listdir(directory)
    for file in files:
        if (file == ".bsq"):
            return True
    return False

def exec_all_map(bin):
    files = os.listdir(BSQ_MAP_DEFAULT)
    data_time = {'Language': bin.split("/")[-1]}
    data_return = {'Language': bin.split("/")[-1]}

    for map_file in files:
        execution_time, return_code = execute_and_measure_time(bin + "/" + BIN_NAME, map_file)
        data_time[map_file] = execution_time
        data_return[map_file] = return_code
    time_output_file = datetime.now().strftime("../data/time_value_%d_%m_%Y.csv") 
    return_output_file = datetime.now().strftime("../data/return_value_%d_%m_%Y.csv")
    with open(time_output_file, 'a', newline='') as time_csvfile, \
         open(return_output_file, 'a', newline='') as return_csvfile:

        time_csvwriter = csv.DictWriter(time_csvfile, fieldnames=data_time.keys())
        if time_csvfile.tell() == 0:
            time_csvwriter.writeheader()
        time_csvwriter.writerow(data_time)

        return_csvwriter = csv.DictWriter(return_csvfile, fieldnames=data_return.keys())
        if return_csvfile.tell() == 0:
            return_csvwriter.writeheader()
        return_csvwriter.writerow(data_return)

def make_binary(path):
    if (not makefile_is_present(path)):
        return (False)
    subprocess.run("make --silent -C " + path, shell=True)
    return (True)

def test_bsq(path):
    if (not make_binary("../" + path)):
        return
    print(f"{bcolors.OKCYAN}{{==== START {path} BSQ ====}}{bcolors.HEADER}")
    exec_all_map("../" + path)
    print(f"{bcolors.OKCYAN}{{====  END {path} BSQ  ====}}")

def test_all_bsq():
    dirs = get_subdirectories() 
    for bsq in dirs:
        test_bsq(bsq)


def main():
    test_all_bsq()

if __name__ == "__main__":
    main()
