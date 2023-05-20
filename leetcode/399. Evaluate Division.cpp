//https://leetcode.com/problems/evaluate-division/submissions/953973333/




class Solution {
public:
    void dfs(string node, string& dest, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited, double& result, double temp) {
        if (visited.find(node) != visited.end())
            return;

        visited.insert(node);

        if (node == dest) {
            result = temp;
            return;
        }

        for (auto neighbor : graph[node]) {
            dfs(neighbor.first, dest, graph, visited, result, temp * neighbor.second);
        }
    }

    unordered_map<string, unordered_map<string, double>> buildGraph(const vector<vector<string>>& equations, const vector<double>& values) {
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double value = values[i];

            graph[dividend][divisor] = value;
            graph[divisor][dividend] = 1.0 / value;
        }

        return graph;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph = buildGraph(equations, values);
        vector<double> finalResults;

        for (auto query : queries) {
            string dividend = query[0];
            string divisor = query[1];

            if (graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end()) {
                finalResults.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                double result = -1.0, temp = 1.0;
                dfs(dividend, divisor, graph, visited, result, temp);
                finalResults.push_back(result);
            }
        }

        return finalResults;
    }
};
