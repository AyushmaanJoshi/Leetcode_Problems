


class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree;  // Tracks missing ingredients count for recipes
        unordered_map<string, vector<string>> graph;  // Ingredient -> Recipes that depend on it
        unordered_set<string> available(supplies.begin(), supplies.end()); // Set of available ingredients

        queue<string> q;
        vector<string> result;

        // Initialize graph and in-degree count
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size(); // Recipe needs these many ingredients
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]); // "ing" is required by recipes[i]
            }
        }

        // Add all initially available supplies to the queue
        for (const string& item : supplies) {
            q.push(item);
        }

        // Process the queue
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // If "curr" is a recipe, add it to the result
            if (inDegree.count(curr)) {
                result.push_back(curr);
            }

            // Reduce in-degree for recipes that depend on "curr"
            for (const string& dependentRecipe : graph[curr]) {
                if (--inDegree[dependentRecipe] == 0) {  // All required ingredients are now available
                    q.push(dependentRecipe);
                    available.insert(dependentRecipe);
                }
            }
        }

        return result;
    }
};
