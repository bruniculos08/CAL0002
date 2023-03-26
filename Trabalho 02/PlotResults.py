import matplotlib.pyplot as plt
import numpy as np
import math
# plt.style.use("seaborn-deep")

# (1) Caminho da pasta do trabalho:
# generalPath = "C:\\Users\\bruni\\OneDrive\\Documentos\\GitHub\\CAL0002\\Trabalho 02\\"
generalPath = "/home/bruno/CAL/Trabalho 02/"

# (2) Gráfico de teste do Quick Sort:

with open(generalPath + "QuickSort/PerformanceTestCase.txt", 'r') as f:
    lines = f.readlines()

vectorQuickSort = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        vectorQuickSort[j] += float(vector[j])

xpointsQuickSort = np.array([x for x in range(0, len(vectorQuickSort))])
ypointsQuickSort = np.array(vectorQuickSort)

plt.plot(xpointsQuickSort, ypointsQuickSort, label="QuickSort", linewidth=0.6)
plt.title("QuickSort")
plt.xlabel("Elementos")
plt.ylabel("Tempo (usec)")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics/QuickSort.png")
plt.close()
f.close()

# (2) Gráfico de testes do Insertion Sort:

with open(generalPath + "InsertionSort/PerformanceTestCase.txt", 'r') as f:
    lines = f.readlines()

vectorInsertionSort = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        vectorInsertionSort[j] += float(vector[j])/10

xpointsInsertionSort = np.array([x for x in range(0, len(vectorInsertionSort))])
ypointsInsertionSort = np.array(vectorInsertionSort)

plt.plot(xpointsInsertionSort, ypointsInsertionSort, label="InsertionSort", linewidth=0.6)
plt.title("InsertionSort")
plt.xlabel("Elementos")
plt.ylabel("Tempo (usec)")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics/InsertionSort.png")
plt.close()
f.close()

# (3) Gráfico de testes do BubbleSort:

with open(generalPath + "BubbleSort/PerformanceTestCase.txt", 'r') as f:
    lines = f.readlines()

vectorBubbleSort = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        vectorBubbleSort[j] = float(vector[j])

xpointsBubbleSort = np.array([x for x in range(0, len(vectorBubbleSort))])
ypointsBubbleSort = np.array(vectorBubbleSort)

plt.plot(xpointsBubbleSort, ypointsBubbleSort, label="BubbleSort", linewidth=0.6)
plt.title("BubbleSort")
plt.xlabel("Elementos")
plt.ylabel("Tempo (usec)")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics/BubbleSort.png")
plt.close()
f.close()

# (4) Gráfico de testes do MergeSort:

with open(generalPath + "MergeSort/PerformanceTestCase.txt", 'r') as f:
    lines = f.readlines()

vectorMergeSort = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        vectorMergeSort[j] = float(vector[j])

xpointsMergeSort = np.array([x for x in range(0, len(vectorMergeSort))])
ypointsMergeSort = np.array(vectorMergeSort)

plt.plot(xpointsMergeSort, ypointsMergeSort, label="MergeSort", linewidth=0.6)
plt.title("MergeSort")
plt.xlabel("Elementos")
plt.ylabel("Tempo (usec)")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics/MergeSort.png")
plt.close()
f.close()

# (4) Gráfico de testes do HeapSort:

with open(generalPath + "HeapSort/PerformanceTestCase.txt", 'r') as f:
    lines = f.readlines()

vectorHeapSort = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        vectorHeapSort[j] = float(vector[j])

xpointsHeapSort = np.array([x for x in range(0, len(vectorHeapSort))])
ypointsHeapSort = np.array(vectorHeapSort)

plt.plot(xpointsHeapSort, ypointsHeapSort, label="HeapSort", linewidth=0.6)
plt.title("HeapSort")
plt.xlabel("Elementos")
plt.ylabel("Tempo (usec)")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics/HeapSort.png")
plt.close()
f.close()

# (5) Gráfico de testes do BinarySearch:

with open(generalPath + "BinarySearch/PerformanceTestCase.txt", 'r') as f:
    lines = f.readlines()

vectorBinarySearch = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        vectorBinarySearch[j] = float(vector[j])

xpointsBinarySearch = np.array([x for x in range(0, len(vectorBinarySearch))])
ypointsBinarySearch = np.array(vectorBinarySearch)

plt.plot(xpointsBinarySearch, ypointsBinarySearch, label="BinarySearch", linewidth=0.6)
plt.title("BinarySearch")
plt.xlabel("Elementos")
plt.ylabel("Tempo (usec)")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics/BinarySearch.png")
plt.close()
f.close()

# (6) Gráfico de testes do LinearSearch:

with open(generalPath + "LinearSearch/PerformanceTestCase.txt", 'r') as f:
    lines = f.readlines()

vectorLinearSearch = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        vectorLinearSearch[j] = float(vector[j])

xpointsLinearSearch = np.array([x for x in range(0, len(vectorLinearSearch))])
ypointsLinearSearch = np.array(vectorLinearSearch)

plt.plot(xpointsLinearSearch, ypointsLinearSearch, label="LinearSearch", linewidth=0.6)
plt.title("LinearSearch")
plt.xlabel("Elementos")
plt.ylabel("Tempo (usec)")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics/LinearSearch.png")
plt.close()
f.close()

# (7) Gráficos de funções:

# xpoints = np.array([x for x in range(0, len(vectorHeapSort))])
# ypointsFunc1 = np.array([0] + [x*math.log(x) for x in xpoints[1:]])

# (8) Plotando todos os gráficos de algoritmos de ordenação em um só:

# plt.plot(xpoints, xpoints, label="n", linewidth=0.8)
# plt.plot(xpoints, ypointsFunc1, label="n.log(n)", linewidth=0.8)

plt.plot(xpointsQuickSort, ypointsQuickSort, label="QuickSort", linewidth=1)
plt.plot(xpointsInsertionSort, ypointsInsertionSort, label="InsertionSort", linewidth=1)
plt.plot(xpointsBubbleSort, ypointsBubbleSort, label="BubbleSort", linewidth=1)
plt.plot(xpointsMergeSort, ypointsMergeSort, label="MergeSort", linewidth=1)
plt.plot(xpointsHeapSort, ypointsHeapSort, label="HeapSort", linewidth=1)

plt.title("All Sorting Algorithms")
plt.xlabel("Elementos")
plt.ylabel("Tempo (usec)")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics/AllSorting.png")
plt.close()

# (9) Plotando todos os gráficos de algoritmos de busca em um só:

# plt.plot(xpoints, xpoints, label="n", linewidth=0.8)
# plt.plot(xpoints, ypointsFunc1, label="log(n)", linewidth=0.8)

plt.plot(xpointsLinearSearch, ypointsLinearSearch, label="LinearSearch", linewidth=1)
plt.plot(xpointsBinarySearch, ypointsBinarySearch, label="BinarySearch", linewidth=1)

plt.title("All Searching Algorithms")
plt.xlabel("Elementos")
plt.ylabel("Tempo (usec)")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics/AllSearching.png")
plt.close()