import numpy as np

values = np.array([[0]])

# values = np.array([[2,6], [7, 3]])

# values = np.array([[1, 10, 3], [9, 12, 35,], [45, 15, 9]])

determinant = np.linalg.det(values)

print(f"Детерминант матрицы: {determinant}")

def minor(matrix, i, j):
    submatrix = np.delete(np.delete(matrix, i, axis=0), j, axis=1)
    return np.linalg.det(submatrix)

def calc_complements(matrix):
    complements = np.zeros(matrix.shape)
    for i in range(matrix.shape[0]):
        for j in range(matrix.shape[1]):
            complements[i, j] = (-1) ** (i + j) * minor(matrix, i, j)
    return complements

complements_matrix = calc_complements(values)

print("Матрица дополнений:")
print(complements_matrix)

inverse_matrix = np.linalg.inv(values)
print("Матрица обратная:")
print(inverse_matrix)