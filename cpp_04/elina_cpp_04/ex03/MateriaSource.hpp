/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:55:07 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/08 13:12:41 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materias[4];
		int			_idx;
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource &cpy);
		MateriaSource &operator=(MateriaSource &cpy);
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif