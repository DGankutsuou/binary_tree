#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct s_tree
{
	char op = 0;
	int value = 0;
	s_tree *left;
	s_tree *right;
};

struct s_halfs
{
	string left_half = "";
	string right_half = "";
};

vector<string> spliter(string str, string delim)
{
	string word;
	short pos;
	vector<string> words;

	while ((pos = str.find(delim)) != string::npos)
	{
		word = str.substr(0, pos);
		if (word != "")
			words.push_back(word);
		str.erase(0, pos + delim.length());
	}
	if (str != "")
		words.push_back(str);
	return (words);
}

s_halfs divide_equation(string equation, s_tree *&tree, bool &found)
{
	s_halfs halfs;
	vector<string> splited;
	int idx = 0;
	int division = 0;
	int pcounter = 0;
	int counter = 0;
	bool paren = false;

	splited = spliter(equation, " ");
	// found = false;
	if (splited[0] == "(")
	{
		paren = true;
		splited.pop_back();
	}
	for (string &iter : splited)
	{
		if (idx == 0 && paren == true)
		{
			idx++;
			continue;
		}
		if (iter == "(")
			pcounter++;
		else if (iter == ")")
			pcounter--;
		if (pcounter == 0 && (iter == "+" || iter == "-"))
		{
			found = true;
			tree->op = iter.at(0);
			division = idx;
		}
		idx++;
	}
	if (!found)
	{
		idx = 0;
		division = 0;
		for (string &iter : splited)
		{
			if (idx == 0 && paren == true)
			{
				idx++;
				continue;
			}
			if (iter == "(")
				pcounter++;
			else if (iter == ")")
				pcounter--;
			if (pcounter == 0 && (iter == "*" || iter == "/"))
			{
				found = true;
				tree->op = iter.at(0);
				division = idx;
			}
			idx++;
		}
	}
	if (found)
	{
		for (string &iter : splited)
		{
			if (counter == 0 && paren == true)
			{
				counter++;
				continue;
			}
			if (counter < division)
			{
				halfs.left_half += iter + " ";
			}
			else if (counter > division)
				halfs.right_half += iter + " ";
			counter++;
		}
	}
	else
	{
		tree->value = stoi(splited[0]);
	}
	return (halfs);
}

s_tree *set_equation_in_tree(string equation)
{
	s_tree *tree;
	s_halfs halfs;
	bool found = false;

	tree = new s_tree;
	halfs = divide_equation(equation, tree, found);
	if (found == true)
	{
		tree->left = set_equation_in_tree(halfs.left_half);
		tree->right = set_equation_in_tree(halfs.right_half);
	}
	return (tree);
}

int binary_tree_calculator(s_tree *equation)
{
	if (equation->op == '+')
		return (binary_tree_calculator(equation->left) + binary_tree_calculator(equation->right));
	else if (equation->op == '-')
		return (binary_tree_calculator(equation->left) - binary_tree_calculator(equation->right));
	else if (equation->op == '*')
		return (binary_tree_calculator(equation->left) * binary_tree_calculator(equation->right));
	else if (equation->op == '/')
		return (binary_tree_calculator(equation->left) / binary_tree_calculator(equation->right));
	else
		return (equation->value);
}

int main(void)
{
	s_tree *tree;
	string equation;
	vector<string> splited;

	cout << "Enter the equation:\n-> ";
	getline(cin, equation);
	//  2 + 5 * 3
	splited = spliter(equation, " ");
	tree = set_equation_in_tree(equation);
	cout << "solution: " << binary_tree_calculator(tree) << endl;
	return (0);
}
// to completed someday
