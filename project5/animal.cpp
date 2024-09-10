/*
	animal.cpp

	author: L. Henke and C. Painter-Wakefield
	date: 04 November 2019

	Animal/20 questions program for CSCI 262, starter code.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;

class node {
public:
    string data;
    node* left;
    node* right;
};

void play_game(node*);
node* read_game_tree();
void write_game_tree(node*);
void delete_game_tree(node*);

// TODO: Add helper method templates here, such as read_preorder().
node* read_preorder(ifstream &fin);

/**
 * Handles showing the main menu/basic UI
 */
int main() {
	node* root = read_game_tree();
	if (root == NULL) return -1;

	while (true) {
		string tmp;
		int choice;

		cout << "Welcome to 20 questions!" << endl;
		cout << "  1) Play the game" << endl;
		cout << "  2) Save the game file" << endl;
		cout << "  3) Quit" << endl;
		cout << "Please make your selection: ";
		getline(cin, tmp);
		choice = atoi(tmp.c_str());

		switch (choice) {
    		case 1:
    			play_game(root);
    			break;
    		case 2:
    			write_game_tree(root);
    			break;
    		case 3:
    			break;
    		default:
    			cout << "Sorry, I don't understand." << endl << endl;
		}
		if (choice == 3) break;
	}

	delete_game_tree(root);
	return 0;
}

/**
 * Sets up the recursive call to the read_preorder
 * @return root of the tree
 */
node* read_game_tree() {
    // TODO: Implement me. See implementation hints! Reading is more complex than it may seem.
    ifstream fin;
    fin.open("animal_game_tree.txt");
	return read_preorder(fin);
}

/**
 * Plays the game
 * @param root Root of the game tree
 */
void play_game(node* root) {
    // TODO: Implement me.
    static node* name = root;
    queue <char> answer; // use queue to record history of answers?
    string question;
    while (root->left != nullptr && root->right != nullptr) {
        // while the root doesn't reach the leaf nodes...
        // this is to remove the #Q and #A in the question and answers
        question = (root->data).substr(3);
        cout << question << " [y/n]: ";
        char input;
        cin >> input;
        if (input == 'y') {
            root = root->left;
            answer.push(input);
        }
        if (input == 'n') {
            root = root->right;
            answer.push(input);
        }
    }
    if (root->left == nullptr && root->right == nullptr) {
        // when it does reach the leaf nodes...
        // this is to remove the #Q and #A in the question and answers
        question = (root->data).substr(3);
        cout << question << " [y/n]: ";
        char input;
        cin >> input;
        if (input == 'y') {
            answer.push(input);
            cout << "YAY! I guessed your animal!" << endl;
        }
        if (input == 'n') {
            answer.push(input);
            cout << "BOO! I don't know!" << endl;
            cout << "Would you like to expand the game tree (y/n)?" << endl;
            cin >> input;
                if (input == 'y') {
                    cout << "I asked the following:" << endl;
                    while (name != nullptr) {
                        cout << (name->data).substr(3);
                        if (answer.front() == 'y') {
                            cout << " YES" << endl;
                            name = name->left;
                        }
                        else {
                            cout << " NO" << endl;
                            name = name->right;
                        }
                        answer.pop();
                    }
                }
                cin.ignore();
                cout << "Enter a new animal in the form of question (e.g. is it a platypus?):" << endl;
                string new_answer;
                getline(cin, new_answer);
                new_answer = "#A" + new_answer;
                string right_leaf = root->data;
                // last question that was asked is a right leaf...
                cout << "Now enter a question for which the answer is 'yes' for your new animal, and which does not contradict your previous answers:" << endl;
                string new_question;
                getline(cin, new_question);
                new_question = '#Q' + new_question;
                root->data = new_question;
                node* new_left = new node;
                node* new_right - new node;
                new_left->data = new_answer;
                root->left = new_left;
                new_right->data = right_leaf;
                // set the data for the new right data as the last question asked
                root->right = new_right;
        }
    }
}

/**
 * Writes the game tree, sets up a recursive call to write_preorder();
 * @param root The root of the tree
 */
void write_game_tree(node* root) {
	// TODO: Implement me.
    // Hmmmmm..... missing few steps in reading the file and assigning the string in
    // create_new_node????
    string new_question;
    // pre_order traversal
    // need to have base case;
    if (root == nullptr) {
        return;
    }
    // need to visit root;
    fout << root->data << endl;
    // INQUIRY: add ofstream pass by reference parameter to the function?
    // traverse to the left
    // traverse to the right
    write_game_tree(root->left, fout);
    write_game_tree(root->right, fout);
}

/**
 * Deletes the game tree
 * @param root Root of the game tree
 */
void delete_game_tree(node* root) {
    // Optional. Do a post-order deletion of the game tree.
    // This isn't strictly needed as the program exits after this is called,
    // which frees up all the memory anyway.
}

// implement the read_preorder function here...
node* read_preorder(ifstream &fin) {
    string line;
    getline(fin, line);
    node* tree = new node;
    tree->data = line;
    if (line[1] == 'Q') {
        tree->left = read_preorder(fin);
        tree->right = read_preorder(fin);
    }
    else {
        // base case of the recursion
        tree->left = nullptr;
        tree->right = nullptr;
        return tree;
    }
    return tree;
}