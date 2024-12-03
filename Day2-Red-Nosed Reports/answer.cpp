#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool is_safe_sequence(const vector<int>& levels) {
    if (levels.size() <= 1) {
        return false;
    }
    
    bool is_increasing = true, is_decreasing = true;
    
    for (size_t i = 0; i < levels.size() - 1; i++) {
        int diff = abs(levels[i] - levels[i + 1]);
        if (diff < 1 || diff > 3) {
            return false;
        }
        
        if (levels[i] > levels[i + 1]) {
            is_increasing = false;
        }
        if (levels[i] < levels[i + 1]) {
            is_decreasing = false;
        }
        
        if(!is_increasing && !is_decreasing) return false;
    }
    
    return is_increasing || is_decreasing;
}

bool can_be_made_safe(const vector<int>& levels) {
  
    for (size_t i = 0; i < levels.size(); i++) {
        vector<int> modified = levels;
        modified.erase(modified.begin() + i);
        
        if (is_safe_sequence(modified)) {
            return true;
        }
    }
    
    return false;
}

vector<int> split_to_ints(const string& line) {
    vector<int> numbers;
    stringstream ss(line);
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

int main() {
    string line;
    int part1_safe_count = 0, part2_safe_count = 0;
    
    while (getline(cin, line)) {
        if (line.empty()) {
            continue;
        }
        
        vector<int> levels = split_to_ints(line);
        if (is_safe_sequence(levels)) {
          part1_safe_count++;
          part2_safe_count++;
        } else if (can_be_made_safe(levels)) {
          part2_safe_count++;
        }
    }
    
    cout << "safe sequences(part 1): " << part1_safe_count << endl;
    cout << "safe sequences(part 2): " << part2_safe_count << endl;
    return 0;
}