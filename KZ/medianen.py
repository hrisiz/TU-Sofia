#!/usr/bin/python3
import sys
import statistics
import csv

def print_usage():
    print("Usage: " + sys.argv[0] + " MATRIX_CSV_FILE_PATH [n]")

def generate_matrix(matrix_file):
    result = []
    with open(matrix_file) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        line_count = 0
        x = 0
        for row in csv_reader:
            y = 0
            result.append([])
            for elem in row:
                result[x].append(int(elem))
                y += 1
            x += 1
    return result, x, y



def print_matrix(x_len, y_len, n, matrix):
    x = 0
    while x < x_len:
        y = 0
        while y < y_len:
            ax = (x - n)
            median_list = []
            while ax <= (x + n):
                ay = (y - n)
                while ay <= (y + n):
                    try:
                        median_list.append(matrix[ax][ay])
                    except Exception as e:
                        median_list.append(0)
                    ay += 1
                ax += 1
            print(statistics.median(median_list),"\t", end = '')
            y += 1
        x += 1
        print("\n")

def main(argv):
    if(len(argv) < 1):
        print_usage()
        exit()

    matrix, x_len, y_len = generate_matrix(argv[0])
    n = 1
    if(len(argv) > 1):
        n = int(argv[1])

    print_matrix(x_len, y_len, n, matrix)

if __name__ == "__main__":
   main(sys.argv[1:])
