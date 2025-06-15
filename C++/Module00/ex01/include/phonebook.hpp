/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:14:04 by hsarraj           #+#    #+#             */
/*   Updated: 2025/04/22 15:14:04 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <cstdlib>
#include "contact.hpp"

class PhoneBook{
	private:
		Contact	_contacts[8];
		int		_index;
		bool	_full;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	set_information(void);
		void	get_information(void)const;
		void	show_instruction(void);
};

#endif
