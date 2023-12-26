#include "PES1UG20CS385_H.h"

int main()
{
    int vertices;
    int dfs_result = 0;
    int bfs_result = 0;
    int start_point, end_point;
    FILE *fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("\nInput file does not exist.");
        exit(0);
    }

    printf("\nReading from input file.\n");
    coord start, end;
    getcord(&start, fp);
    getcord(&end, fp);

    printf("\nStart: (%d, %d)\nEnd: (%d, %d)\n", start.x, start.y, end.x, end.y);

    vertices = num_v(fp);
    vertex_node *adj_list = (vertex_node *)malloc((vertices + 1) * sizeof(vertex_node));

    read_map(fp, adj_list);

    printf("\nDisplaying Adjacency List.\n");
    display_adj_list(adj_list, vertices);

    printf("\n\nFinding path:\n");
    int *d_path = (int *)calloc(vertices, sizeof(int));
    int *b_path = (int *)calloc(vertices, sizeof(int));

    // Storing the starting and the ending coordinates
    start_point = find_vertex(adj_list, &start, vertices);
    end_point = find_vertex(adj_list, &end, vertices);

    find_path(adj_list, start_point, end_point, vertices, &dfs_result, &bfs_result, d_path, b_path);
    store_path(adj_list, start_point, end_point, vertices, dfs_result, bfs_result, d_path, b_path);

    free(adj_list);
    return 0;
}