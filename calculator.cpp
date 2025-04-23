#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct s_tree
{
	char	op = 0;
	int		value = 0;
	s_tree	*left;
	s_tree	*right;
};

struct s_halfs
{
	string left_half;
	string right_half;
};

vector <string>	spliter(string str, string delim)
{
	string	word;
	short	pos;
	vector <string> words;

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

s_halfs	divide_equation(string equation)
{
	s_halfs 		halfs;
	vector <string>	splited;
	int				idx = 0;

	splited = spliter(equation, " ");
	for (string &iter : splited)
	{
		if (iter == "+" || iter == "-")
		{

		}
		idx++;
	}
}

s_tree	*set_equation_in_tree(string equation)
{
	s_tree *tree;
	s_halfs halfs;

	tree = new s_tree;
	halfs = divide_equation(equation);
	tree->left = set_equation_in_tree(halfs.left_half);
	tree->right = set_equation_in_tree(halfs.right_half);
	return (tree);
}

int	binary_tree_calculator(s_tree *equation)
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

int	main(void)
{
	s_tree			*tree;
	string			equation;
	vector <string>	splited;

	cout << "Enter the equation:\n-> ";
	cin >> equation;
	// 2 + 5 * 3
	splited = spliter(equation, " ");
	tree = set_equation_in_tree(equation);
	cout << binary_tree_calculator(tree) << endl;
	return (0);
}
// to completed someday
