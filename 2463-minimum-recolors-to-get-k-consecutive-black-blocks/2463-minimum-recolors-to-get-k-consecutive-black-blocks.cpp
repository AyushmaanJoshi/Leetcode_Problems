class Solution {
public:
    int minimumRecolors(string blocks, int k) {
    int n = blocks.size();
    int min_operations = INT_MAX;
    int white_count = 0;
   
    for (int i = 0; i < k; i++) {
        if (blocks[i] == 'W') white_count++;
    }

    min_operations = white_count;

    for (int i = k; i < n; i++) {
        if (blocks[i] == 'W') white_count++;      

        if (blocks[i - k] == 'W') white_count--; 

        min_operations = min(min_operations, white_count);
    }

    return min_operations;
    }
};