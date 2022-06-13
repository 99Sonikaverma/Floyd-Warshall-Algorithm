# Floyd Warshall Algorithm in python

# The number of vertices
no_of_Vertices = 4
INF = 999

# Algorithm implementation
def Floyd_Warshall_Algorithm(G):
    distance = list(map(lambda i: list(map(lambda j: j, i)), G))

    # Adding vertices individually
    for k in range(no_of_Vertices):
        for i in range(no_of_Vertices):
            for j in range(no_of_Vertices):
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])
    print_solution(distance)

# Printing the solution
def print_solution(distance):
    for i in range(no_of_Vertices):
        for j in range(no_of_Vertices):
            if(distance[i][j] == INF):
                print("INF", end=" ")
            else:
                print(distance[i][j], end="  ")
        print(" ")


G = [[0, 3, INF, 5],
         [2, 0, INF, 4],
         [INF, 1, 0, INF],
         [INF, INF, 2, 0]]
Floyd_Warshall_Algorithm(G)