void dfs(int** rooms, int* roomsColSize, int* visited, int room) {
    visited[room] = 1;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(rooms, roomsColSize, visited, key);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int visited[roomsSize];

    for (int i = 0; i < roomsSize; i++)
        visited[i] = 0;

    dfs(rooms, roomsColSize, visited, 0);

    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i])
            return false;
    }

    return true;
}