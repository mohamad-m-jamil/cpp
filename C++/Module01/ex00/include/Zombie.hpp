/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 08:43:37 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/24 08:43:37 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie();

    void announce() const;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
