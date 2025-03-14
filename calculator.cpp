#include <iostream>
using namespace std;

struct s_tree
{
	char	op = 0;
	int		value = 0;
	s_tree	*left;
	s_tree	*right;
};

/*
s_tree	*set_equation_in_tree(char *equation)
{
	s_tree	*equation;


}
*/

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

	equation = new s_tree;
	equation->op = '+';
	equation->left = new s_tree;
	equation->left->op = '*';
	equation->left->left = new s_tree;
	equation->left->left->value = 5;
	equation->left->right = new s_tree;
	equation->left->right->value = 3;
	equation->right = new s_tree;
	equation->right->value = 2;
	// 2 + 5 * 3
	cout << binary_tree_calculator(equation) << endl;
	return (0);
}
