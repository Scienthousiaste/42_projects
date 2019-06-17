/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:16:49 by tbehra            #+#    #+#             */
/*   Updated: 2019/06/17 17:20:17 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

# include <regex>
# include <string>
# include <list>


class Parser {
	
	public:
		Parser(std::string str);
		~Parser(void);
		std::list< std::string > const & getInstructions(void) const;

	private:
		std::list< std::string > _instructions;
		Parser(void);
		Parser(Parser const & p);
		Parser & operator=(Parser const & p);
};

#endif
