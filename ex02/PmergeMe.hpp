/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:58:34 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/20 14:07:20 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    - Secuencia de Jacobsthal: 1, 1, 3, 5, 11, 21...

    Estructura del proceso:
    1. Se parte de una lista de números desordenados.
    2. Se agrupan en pares y se comparan, intercambiando si es necesario para que el mayor de cada par esté a la derecha.
    3. Se separan en dos listas: una principal con los mayores y otra pendiente con los menores.
    4. La lista principal se ordena con `std::sort()`.
    5. Se insertan los elementos de la lista pendiente en la lista principal usando inserción binaria.
    6. Se sigue la secuencia de Jacobsthal para elegir los elementos a insertar en cada iteración.

    Notación en la pizarra:
    - Los números en la primera fila representan la lista original desordenada.
    - Las líneas y agrupaciones indican las comparaciones y ordenaciones realizadas.
    - Las líneas cruzadas marcan las posiciones eliminadas en el proceso.
    - Se sigue un orden de inserción basado en Jacobsthal, dividiendo y ordenando por grupos.

    Ejemplo visual en la pizarra:
    - Lista original: [11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7]
    - Agrupación en pares y comparación: [(2,11), (0,17), (8,16), ...]
    - Ordenación de la lista principal con `std::sort()`.
    - Inserción de los elementos pendientes en orden Jacobsthal: [0, 17, 6, 15, ...]
    - Proceso finaliza con la lista completamente ordenada.
*/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int> deq;
		double timeVec;
		double timeDeq;

		void mergeInsertionSortVector(std::vector<int> &arr);
		void mergeInsertionSortDeque(std::deque<int> &arr);
		void binaryInsert(std::vector<int> &arr, int value);
		void binaryInsert(std::deque<int> &arr, int value);
	public:
		PmergeMe();
		PmergeMe(std::vector<int> data);
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		void sortVector();
		void sortDeque();
		void printResults(std::vector<int>) const;
};

#endif
