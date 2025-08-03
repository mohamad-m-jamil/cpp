/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:59:57 by mjamil            #+#    #+#             */
/*   Updated: 2025/07/20 16:46:14 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

size_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<size_t>(ptr);
}

Data* Serializer::deserialize(size_t raw) {
    return reinterpret_cast<Data*>(raw);
}
