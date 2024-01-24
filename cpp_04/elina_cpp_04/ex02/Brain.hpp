/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esirnio <esirnio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:42:05 by esirnio           #+#    #+#             */
/*   Updated: 2023/12/07 16:23:20 by esirnio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string ideas[100];
		int			idea_idx;
	public:
		Brain();
		Brain(const Brain &cpy);
		Brain &operator=(const Brain &cpy);
		virtual ~Brain();
		void	setIdea(std::string idea);
		void	printIdeas();
};

#endif