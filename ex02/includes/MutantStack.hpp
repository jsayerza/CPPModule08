#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() : std::stack<T, Container>() {}
		MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
				std::stack<T, Container>::operator=(other);
			return (*this);
		};
		~MutantStack() {}

		//Iterators
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return (this->c.begin()); }
		const_iterator begin() const { return (this->c.begin()); }
		reverse_iterator rbegin() { return (this->c.rbegin()); }
		const_reverse_iterator rbegin() const { return (this->c.rbegin()); }

		iterator end() { return (this->c.end()); }
		const_iterator end() const { return (this->c.end()); }
		reverse_iterator rend() { return (this->c.rend()); }
		const_reverse_iterator rend() const { return (this->c.rend()); }
};

#endif

// std::stack es un contenedor que NO tiene iteradores.
// Crear MutantStack que herede de std::stack y añada iteradores.

// 1. template <typename T, typename Container = std::deque<T> >
// class MutantStack : public std::stack<T, Container>
// Hereda de std::stack<T, Container>
// Es una clase template que acepta dos parámetros de tipo:
// Acepta tipo T y opcionalmente un contenedor (default: deque<T>)
// T: El tipo de dato que almacenaré (int, string, etc.)
// std::stack tiene un miembro protected llamado c (container) --> en este caso, std::deque<T>
//		std::deque<T> porque std::stack en la librería estándar también usa deque por defecto
//		Como heredamos de stack, podemos acceder a c

// 2. Define typedef para tipos de iteradores
// typedef typename Container::iterator iterator;
//		Sin typename, el compilador no sabe si Container::iterator es un tipo o una variable.
//		typename es necesario porque Container es un template
// Container::iterator es el tipo de iterador del contenedor interno
// Ahora MutantStack<int>::iterator existe

// 3. Implementa begin() y end() usando this->c
// 4. Añade versiones const y reverse

// std::stack<T, Container>::operator=(other);
//		Llama al operador de asignación (operator=) de la clase base std::stack<T, Container> pasándole other como argumento
//		Cuando heredas de una clase y haces tu propio operator=, debes llamar explícitamente al operator= de la clase padre para copiar sus datos.