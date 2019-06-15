/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reader.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:40:43 by tbehra            #+#    #+#             */
/*   Updated: 2019/05/22 11:29:58 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <iostream>
# include <fstream>

class Reader {

public:
	Reader(void);
	~Reader(void);
	void cat_file(std::string s) const;
	void cat_console(void) const;
};

#endif
