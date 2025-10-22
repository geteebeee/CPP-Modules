/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorg <gorg@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:45:38 by gorg              #+#    #+#             */
/*   Updated: 2025/07/22 14:45:38 by gorg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
class Dog : public Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog& src);
		Dog& operator=(const Dog& src);
		~Dog();

		void makeSound() const override;
		void setIdea(int n, const std::string& idea);
		std::string getIdea(int n) const;
};
