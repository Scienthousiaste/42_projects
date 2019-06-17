/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:02:48 by tbehra            #+#    #+#             */
/*   Updated: 2019/06/17 16:22:47 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
# define ABSTRACTVM_HPP

# include "Factory.hpp"
# include "IterStack.hpp"
# include "Exceptions.hpp"

class AbstractVM {
	public:
		AbstractVM(void);
		~AbstractVM(void);
		
		IterStack< const IOperand* > & getStack(void);
		Factory & getFactory();

		void push(const IOperand *op);
		void pop(void) throw();
		void dump(void);
		void assert(const IOperand *op) throw();
		void add(void) throw();
		void sub(void) throw();
		void mul(void) throw();
		void div(void) throw();
		void mod(void) throw();
		void print(void) throw();

	private:
		Factory _factory;
		IterStack< const IOperand* > _stack;
		AbstractVM(AbstractVM const & avm);
		AbstractVM & operator=(AbstractVM const & avm); 
};

#endif
