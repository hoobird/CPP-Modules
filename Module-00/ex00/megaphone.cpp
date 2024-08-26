/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <hoobird@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:55:05 by hoobird           #+#    #+#             */
/*   Updated: 2024/08/25 15:55:06 by hoobird          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
            std::cout << (char)toupper(argv[i][j]);
    }
    std::cout << std::endl;
    return 0;
}