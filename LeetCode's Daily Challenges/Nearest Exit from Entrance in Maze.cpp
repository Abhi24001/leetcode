class Solution2 {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        static const char visited = '-';
        maze[entrance[0]][entrance[1]] = visited;
        vector<pair<vector<int>, int>> q = {{entrance, 0}};
        while (!empty(q)) {
            vector<pair<vector<int>, int>> new_q;
            for (const auto& [curr, step] : q) {
                if (curr != entrance &&
                    (curr[0] == 0 || curr[0] == size(maze) - 1 ||
                     curr[1] == 0 || curr[1] == size(maze[0]) - 1)) {
                    return step;
                }
                for (const auto& [dr, dc] : directions) {
                    const auto nr = curr[0] + dr, nc = curr[1] + dc;
                    if (!(0 <= nr && nr < size(maze) &&
                          0 <= nc && nc < size(maze[0]) &&
                          maze[nr][nc] == '.')) {
                        continue;
                    }
                    maze[nr][nc] = visited;
                    new_q.emplace_back(vector<int>({nr, nc}), step + 1);
                }
            }
            q = move(new_q);
        }
        return -1;
    }
};
