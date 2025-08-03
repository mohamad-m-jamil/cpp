/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:00:04 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/20 16:48:24 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstddef>

class Serializer
{
    private:
        Serializer();
        Serializer& operator=(const Serializer&);
        Serializer( const Serializer&);
        ~Serializer();
    public:
        static size_t serialize(Data* ptr);
        static Data* deserialize(size_t raw);

};

#endif