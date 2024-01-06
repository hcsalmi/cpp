/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbroms <lbroms@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:31:08 by lbroms            #+#    #+#             */
/*   Updated: 2023/10/10 16:49:30 by lbroms           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	mmain(int argc, char **argv)
{
	/*test constructors and copy assingment operator*/
	std::cout << "####test constructors and copy assingment operator####" << std::endl;
	Fixed a;
	std::cout << "a is " << a << std::endl;
	Fixed b(555);
	std::cout << "b is " << b << std::endl;
	Fixed c(5.05f);
	std::cout << "c is " << c << std::endl;
	Fixed d(b);
	std::cout << "d is " << d << std::endl;
	Fixed e;
	std::cout << "e is " << e << std::endl;
	e = c;
	std::cout << "e is " << e << std::endl;
	
	std::cout << std::endl;

	/*test multiply and division*/
	std::cout << "####test multiply and division####" << std::endl;
	Fixed f1(4);
	Fixed f2(42);
	Fixed f3(2.5f);
	Fixed f4(0.876f);
	
	std::cout << "f1 is " << f1 << std::endl;
	std::cout << "f2 is " << f2 << std::endl;
	std::cout << "f3 is " << f3 << std::endl;
	std::cout << "f4 is " << f4 << std::endl;

	std::cout << "f1 * f2 is " << f1 * f2 << std::endl;
	std::cout << "f1 / f2 is " << f1 / f2 << std::endl;
	std::cout << "f1 * f3 is " << f1 * f3 << std::endl;
	std::cout << "f1 / f3 is " << f1 / f3 << std::endl;
	std::cout << "f1 * f4 is " << f1 * f4 << std::endl;
	std::cout << "f1 / f4 is " << f1 / f4 << std::endl;
	std::cout << "f2 * f3 is " << f2 * f3 << std::endl;
	std::cout << "f2 / f3 is " << f2 / f3 << std::endl;
	std::cout << "f2 * f4 is " << f2 * f4 << std::endl;
	std::cout << "f2 / f4 is " << f2 / f4 << std::endl;
	std::cout << "f3 * f4 is " << f3 * f4 << std::endl;
	std::cout << "f3 / f4 is " << f3 / f4 << std::endl;
	
	std::cout << std::endl;


	/*test the -- ++ stuff*/
	std::cout << "####test the -- ++ stuff####" << std::endl;
	Fixed g1(4);
	Fixed g2(5.05f);
	
	std::cout << "g1 is " << g1 << std::endl;
	std::cout << "g2 is " << g2 << std::endl;

	std::cout << "g1++ is " << g1++ << std::endl;
	std::cout << "g1 is " << g1 << std::endl;
	std::cout << "++g1 is " << ++g1 << std::endl;
	std::cout << "g1 is " << g1 << std::endl;
	std::cout << "g2-- is " << g2-- << std::endl;
	std::cout << "g2 is " << g2 << std::endl;
	std::cout << "--g2 is " << --g2 << std::endl;
	std::cout << "g2 is " << g2 << std::endl;

	std::cout << std::endl;
	
	/*test the comparison operators*/
	std::cout << "####test the comparison operators####" << std::endl;
	Fixed h1(4);
	Fixed h2(5.05f);
	Fixed h3(5);
	Fixed h4(4.12f);

	std::cout << "h1 is " << h1 << std::endl;
	std::cout << "h2 is " << h2 << std::endl;
	std::cout << "h3 is " << h3 << std::endl;
	std::cout << "h4 is " << h4 << std::endl;

	std::cout << "h1 > h2 is " << (h1 > h2) << std::endl;
	std::cout << "h1 < h2 is " << (h1 < h2) << std::endl;
	std::cout << "h1 >= h2 is " << (h1 >= h2) << std::endl;
	std::cout << "h1 <= h2 is " << (h1 <= h2) << std::endl;
	std::cout << "h1 == h2 is " << (h1 == h2) << std::endl;
	std::cout << "h1 != h2 is " << (h1 != h2) << std::endl;
	std::cout << "h1 > h3 is " << (h1 > h3) << std::endl;
	std::cout << "h1 < h3 is " << (h1 < h3) << std::endl;
	std::cout << "h1 >= h3 is " << (h1 >= h3) << std::endl;
	std::cout << "h1 <= h3 is " << (h1 <= h3) << std::endl;
	std::cout << "h1 == h3 is " << (h1 == h3) << std::endl;
	std::cout << "h1 != h3 is " << (h1 != h3) << std::endl;
	std::cout << "h1 > h4 is " << (h2 > h4) << std::endl;
	std::cout << "h1 < h4 is " << (h2 < h4) << std::endl;
	std::cout << "h1 >= h4 is " << (h2 >= h4) << std::endl;
	std::cout << "h1 <= h4 is " << (h2 <= h4) << std::endl;
	std::cout << "h1 == h4 is " << (h2 == h4) << std::endl;
	std::cout << "h1 != h4 is " << (h2 != h4) << std::endl;

	std::cout << std::endl;
	
	/*test + and - */
	std::cout << "####test + and - ####" << std::endl;
	Fixed i1(4);
	Fixed i2(5.05f);
	Fixed i3(5);
	Fixed i4(4.12f);

	std::cout << "i1 is " << i1 << std::endl;
	std::cout << "i2 is " << i2 << std::endl;
	std::cout << "i3 is " << i3 << std::endl;
	std::cout << "i4 is " << i4 << std::endl;
	
	std::cout << "i1 + i2 is " << i1 + i2 << std::endl;
	std::cout << "i1 - i2 is " << i1 - i2 << std::endl;
	std::cout << "i1 + i3 is " << i1 + i3 << std::endl;
	std::cout << "i1 - i3 is " << i1 - i3 << std::endl;
	std::cout << "i1 + i4 is " << i1 + i4 << std::endl;
	std::cout << "i1 - i4 is " << i1 - i4 << std::endl;
	std::cout << "i2 + i3 is " << i2 + i3 << std::endl;
	std::cout << "i2 - i3 is " << i2 - i3 << std::endl;
	std::cout << "i2 + i4 is " << i2 + i4 << std::endl;
	std::cout << "i2 - i4 is " << i2 - i4 << std::endl;
	std::cout << "i3 + i4 is " << i3 + i4 << std::endl;
	std::cout << "i3 - i4 is " << i3 - i4 << std::endl;

	std::cout << std::endl;
	
	
	/*test min and max */
	std::cout << "####test min and max ####" << std::endl;
	Fixed j1(4);
	Fixed j2(5.05f);
	Fixed j3(5);
	Fixed j4(4.12f);

	std::cout << "j1 is " << j1 << std::endl;
	std::cout << "j2 is " << j2 << std::endl;
	std::cout << "j3 is " << j3 << std::endl;
	std::cout << "j4 is " << j4 << std::endl;
	
	std::cout << "min(j1, j2) is " << Fixed::min(j1, j2) << std::endl;
	std::cout << "max(j1, j2) is " << Fixed::max(j1, j2) << std::endl;
	std::cout << "min(j1, j3) is " << Fixed::min(j1, j3) << std::endl;
	std::cout << "max(j1, j3) is " << Fixed::max(j1, j3) << std::endl;
	std::cout << "min(j1, j4) is " << Fixed::min(j1, j4) << std::endl;
	std::cout << "max(j1, j4) is " << Fixed::max(j1, j4) << std::endl;
	std::cout << "min(j2, j3) is " << Fixed::min(j2, j3) << std::endl;
	std::cout << "max(j2, j3) is " << Fixed::max(j2, j3) << std::endl;
	std::cout << "min(j2, j4) is " << Fixed::min(j2, j4) << std::endl;
	std::cout << "max(j2, j4) is " << Fixed::max(j2, j4) << std::endl;
	
	std::cout << std::endl;
}

/*the test provided in the subject*/


int	main( void )
{
	Fixed 			a;
	Fixed const 	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}
