#include <bits/stdc++.h>
using namespace std;

// Function to generate all possible orientations of the dice
vector<vector<int>> generate_permutations(vector<int> dice) {
    vector<vector<int>> permutations;

    // Possible rotations when each face is on top
    vector<vector<int>> rotations = {
        {dice[0], dice[1], dice[2], dice[3], dice[4], dice[5]},  // Original orientation
        {dice[0], dice[1], dice[4], dice[5], dice[3], dice[2]},
        {dice[0], dice[1], dice[3], dice[2], dice[5], dice[4]},
        {dice[0], dice[1], dice[5], dice[4], dice[2], dice[3]},
        
        {dice[2], dice[3], dice[1], dice[0], dice[4], dice[5]},  // Rotate front to top
        {dice[2], dice[3], dice[4], dice[5], dice[0], dice[1]},
        {dice[2], dice[3], dice[0], dice[1], dice[5], dice[4]},
        {dice[2], dice[3], dice[5], dice[4], dice[1], dice[0]},

        {dice[4], dice[5], dice[2], dice[3], dice[1], dice[0]},  // Rotate left to top
        {dice[4], dice[5], dice[0], dice[1], dice[2], dice[3]},
        {dice[4], dice[5], dice[3], dice[2], dice[0], dice[1]},
        {dice[4], dice[5], dice[1], dice[0], dice[3], dice[2]},

        {dice[3], dice[2], dice[1], dice[0], dice[5], dice[4]},  // Rotate back to top
        {dice[3], dice[2], dice[5], dice[4], dice[0], dice[1]},
        {dice[3], dice[2], dice[0], dice[1], dice[4], dice[5]},
        {dice[3], dice[2], dice[4], dice[5], dice[1], dice[0]},

        {dice[5], dice[4], dice[2], dice[3], dice[0], dice[1]},  // Rotate right to top
        {dice[5], dice[4], dice[1], dice[0], dice[2], dice[3]},
        {dice[5], dice[4], dice[3], dice[2], dice[1], dice[0]},
        {dice[5], dice[4], dice[0], dice[1], dice[3], dice[2]},

        {dice[1], dice[0], dice[2], dice[3], dice[5], dice[4]},  // Rotate bottom to top
        {dice[1], dice[0], dice[5], dice[4], dice[3], dice[2]},
        {dice[1], dice[0], dice[3], dice[2], dice[4], dice[5]},
        {dice[1], dice[0], dice[4], dice[5], dice[2], dice[3]}
    };

    for (auto& perm : rotations) {
        permutations.push_back(perm);
    }

    return permutations;
}

// Function to find the lexicographically smallest permutation of a dice
vector<int> min_dice_permutation(vector<int> dice) {
    vector<vector<int>> all_permutations = generate_permutations(dice);
    return *min_element(all_permutations.begin(), all_permutations.end());
}

int main() {
    int n;
    while(cin >> n){
        vector<vector<int>> dice_data(n, vector<int>(6));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 6; ++j) {
                cin >> dice_data[i][j];
            }
            dice_data[i] = min_dice_permutation(dice_data[i]);
        }

        map<vector<int>, int> unique_dice;
        for (const auto& dice : dice_data) {
            unique_dice[dice]++;
        }

        int result = 0;
        for (const auto& entry : unique_dice) {
            result = max(result, entry.second);
        }
        cout << result << endl;
    }
}
