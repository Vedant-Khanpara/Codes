#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class FiniteAutomata {
private:
    // Representing the states and transitions as a map of maps
    unordered_map<int, unordered_map<char, int>> transitions;
    int startState;
    vector<int> acceptStates;

public:
    // Constructor to initialize start state and accept states
    FiniteAutomata(int start, vector<int> accepts) {
        startState = start;
        acceptStates = accepts;
    }

    // Method to add a transition
    void addTransition(int fromState, char input, int toState) {
        transitions[fromState][input] = toState;
    }

    // Method to check if the input string is valid
    bool validateString(const string& input) {
        int currentState = startState;

        for (char c : input) {
            // Check if there is a transition from current state with the input character
            if (transitions[currentState].find(c) == transitions[currentState].end()) {
                return false;  // Invalid transition, so the string is invalid
            }
            currentState = transitions[currentState][c];  // Move to the next state
        }

        // Check if the final state is one of the accept states
        for (int acceptState : acceptStates) {
            if (currentState == acceptState) {
                return true;  // String is valid
            }
        }

        return false;  // Final state is not an accept state
    }
};

int main() {
    // Example: Simple Finite Automaton for binary strings that end with "01"
    
    // Create a finite automaton with start state 0 and accept state 2
    FiniteAutomata fa(0, {2});

    // Add transitions
    fa.addTransition(0, '0', 0);
    fa.addTransition(0, '1', 1);
    fa.addTransition(1, '0', 2);
    fa.addTransition(1, '1', 0);
    fa.addTransition(2, '0', 0);
    fa.addTransition(2, '1', 1);

    // Get input string from the user
    string input;
    cout << "Enter a string to validate: ";
    cin >> input;

    // Validate the string and output the result
    if (fa.validateString(input)) {
        cout << "Valid String" << endl;
    } else {
        cout << "Invalid String" << endl;
    }

    return 0;
}