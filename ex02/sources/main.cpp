#include <list>
#include "../includes/MutantStack.hpp"

int main()
{
	{
		std::cout << "\n--- Test subject with MutantStack" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}

	{
		std::cout << "\n--- Test subject with std::list" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}

	{
		std::cout << "\n--- Test MutantStack iterator" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "--- Test MutantStack reverse iterator" << std::endl;
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	{
		std::cout << "\n--- Test MutantStack copy" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		MutantStack<int> copy_mstack(mstack);

		std::cout << "--- Test MutantStack copy reverse iterator" << std::endl;
		for (MutantStack<int>::iterator it = copy_mstack.begin(); it != copy_mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "--- Test MutantStack copy reverse iterator" << std::endl;
		for (MutantStack<int>::reverse_iterator it = copy_mstack.rbegin(); it != copy_mstack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	{
		std::cout << "\n--- Test MutantStack assign operator" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		MutantStack<int> copy_mstack = mstack;

		std::cout << "--- Test MutantStack assign operator reverse iterator" << std::endl;
		for (MutantStack<int>::iterator it = copy_mstack.begin(); it != copy_mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "--- Test MutantStack assign operator reverse iterator" << std::endl;
		for (MutantStack<int>::reverse_iterator it = copy_mstack.rbegin(); it != copy_mstack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	{
		std::cout << "\n--- Test string MutantStack iterator" << std::endl;
		MutantStack<std::string> mstack;
		mstack.push("This");
		mstack.push("is");
		mstack.push("a");
		mstack.push("pretty");
		mstack.push("test!");

		for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "--- Test string MutantStack reverse iterator" << std::endl;
		for (MutantStack<std::string>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	return (0);
}

