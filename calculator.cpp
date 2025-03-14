#include <iostream>
using namespace std;

struct s_tree
{
	char	op = 0;
	int		value = 0;
	s_tree	*left;
	s_tree	*right;
};

s_tree	*set_equation_in_tree(string *equation)
{
	s_tree	*equation;


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
	s_tree	*equation;
	string	line;

	cout << "Enter the equation:\n-> ";
	cin >> line;
	// 2 + 5 * 3
	equation = set_equation_in_tree(line.)
	cout << binary_tree_calculator(equation) << endl;
	return (0);
}
