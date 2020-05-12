#!/usr/bin/python3
import sys
import csv
import numpy

def print_usage():
    print("Usage: " + sys.argv[0] + " MATRIX_CSV_FILE_PATH conv_number [conv_number] [conv_number]...")

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

def print_matrix(x_len, y_len, conv_matrix, matrix):
    x = 0
    while x < x_len:
        for elem in numpy.convolve(matrix[x],conv_matrix,"valid"):
            print(elem,"\t", end = '')
        x += 1
        print("\n")

def main(argv):
    if(len(argv) < 1):
        print_usage()
        exit()

    matrix, x_len, y_len = generate_matrix(argv[0])

    convol_matrix = []*y_len
    for elem in argv[1:]:
        convol_matrix.append(int(elem))

    print_matrix(x_len, y_len, convol_matrix, matrix)

if __name__ == "__main__":
   main(sys.argv[1:])
