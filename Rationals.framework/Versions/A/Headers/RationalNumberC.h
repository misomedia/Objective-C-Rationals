//
//  RationalC.h
//  Rational
//
//  Created by Ryan Hiroaki Tsukamoto on 3/2/12.
//  Copyright (c) 2012 Miso Media. All rights reserved.
//

#ifndef Rational_RationalC_h
#define Rational_RationalC_h

#import <Foundation/Foundation.h>

#pragma mark TYPES

//!	A rational in terms of its representation as a fraction.
/*!	The fraction should be in lowest terms, please.	*/
struct _SINGLE_PRECISION_NUM_DEN_RATIONAL
{
	int numerator;		/*!<	The numerator.  The sign of the fraction is represented by the sign of the numerator	*/
	uint denominator;	/*!<	The denominator.  The denominator must be greater than one.	*/	
};

typedef struct _SINGLE_PRECISION_NUM_DEN_RATIONAL SINGLE_PRECISION_NUM_DEN_RATIONAL;	/*!<	An alias for the type struct _SINGLE_PRECISION_NUM_DEN_RATIONAL.	*/

//!	A rational in terms of its representation as the sum of an integer and a fraction strictly between zero and one.
/*!	The fraction should be in lowest terms, please.	*/
struct _SINGLE_PRECISION_INT_FRACNUM_FRACDEN_RATIONAL
{
	int integer_part;				/*!<	The integer part.  This should be the largest integer less than the rational number represented by the struct.	*/
	uint fraction_part_numerator;	/*!<	The numerator of the fraction part.  This must be positive and less than the denominator.	*/
	uint fraction_part_denominator;	/*!<	The denominator of the fraction part.  This must be positive and greater than the numerator.	*/
};

typedef struct _SINGLE_PRECISION_INT_FRACNUM_FRACDEN_RATIONAL SINGLE_PRECISION_INT_FRACNUM_FRACDEN_RATIONAL;	/*!<	An alias for the type struct _SINGLE_PRECISION_INT_FRACNUM_FRACDEN_RATIONAL.	*/

//!	An enumeration for the type tag of our number type
enum _RATIONAL_NUMBER_TYPE
{
	RATIONAL_NUMBER_TYPE_UINT,											/*!<	Tag for the unsigned int type (uint).	*/
	RATIONAL_NUMBER_TYPE_INT,											/*!<	Tag for the int type.	*/
	RATIONAL_NUMBER_TYPE_FLOAT,											/*!<	Tag for the float type.	*/
	RATIONAL_NUMBER_TYPE_DOUBLE,										/*!<	Tag for the double type.	*/
	RATIONAL_NUMBER_TYPE_SINGLE_PRECISION_NUM_DEN_RATIONAL,				/*!<	Tag for the SINGLE_PRECISION_NUM_DEN_RATIONAL type.	*/
	RATIONAL_NUMBER_TYPE_SINGLE_PRECISION_INT_FRACNUM_FRACDEN_RATIONAL,	/*!<	Tag for the SINGLE_PRECISION_INT_FRACNUM_FRACDEN_RATIONAL type.	*/
};

typedef enum _RATIONAL_NUMBER_TYPE RATIONAL_NUMBER_TYPE;	/*!<	An alias for the enumeration _RATIONAL_NUMBER_TYPE	*/

//!	A dynamically allocated type for rational numbers (floating point binary numbers are rationals too!  They're just crippled).
/*!	This is a tagged union using a void valued pointer.	*/
struct _RATIONAL_NUMBER
{
	void* RATIONAL_NUMBER_data;				/*!<	The "union."	*/
	RATIONAL_NUMBER_TYPE RATIONAL_NUMBER_type;	/*!<	The tag.	*/
};

typedef struct _RATIONAL_NUMBER RATIONAL_NUMBER;	/*!<	An alias for the type _RATIONAL_NUMBER.	*/

//!	Constructor for the RATIONAL_NUMBER type using an unsigned int.
/*!	\param	n	an unsigned integer argument.	*/
RATIONAL_NUMBER make_RATIONAL_NUMBER_from_UINT(uint n);

//!	Constructor for the RATIONAL_NUMBER type using an int.
/*!	\param	n	an integer argument.	*/
RATIONAL_NUMBER make_RATIONAL_NUMBER_from_INT(int n);

//!	Constructor for the RATIONAL_NUMBER type using a float.
/*!	\param	n	a floating point argument.	*/
RATIONAL_NUMBER make_RATIONAL_NUMBER_from_FLOAT(float n);

//!	Constructor for the RATIONAL_NUMBER type using a double.
/*!	\param	n	a double width argument.	*/
RATIONAL_NUMBER make_RATIONAL_NUMBER_from_DOUBLE(double n);

//!	Constructor for the RATIONAL_NUMBER type using an integer and an unsigned integer to uniquely represent a non-integral rational number as a fraction in lowest terms.
/*!
	\param	num	the integer whose value is to be used for the numerator.
	\param	den	the unsigned integer whose value is to be used for the denominator.  This cannot be zero, nor can it be one.
*/
RATIONAL_NUMBER make_RATIONAL_NUMBER_from_SINGLE_PRECISION_NUM_DEN_RATIONAL(int num, uint den);

//!	Constructor for the RATIONAL_NUMBER type using an integer and two unsigned integers to uniquely represent a non-integral rational number as the sum of an integer and a fraction strictly between zero and one.
/*!
	\param	int_n	an integer argument for the integer.
	\param	frac_num	an unsigned integer argument for the numerator of the fraction.
	\param	frac_den	an unsigned integer argument for the denominator of the fraction.
*/
RATIONAL_NUMBER make_RATIONAL_NUMBER_from_SINGLE_PRECISION_INT_FRACNUM_FRACDEN_RATIONAL(int int_n, uint frac_num, uint frac_den);

//!	Copy constructor for the RATIONAL_NUMBER type.
/*!	\param	N	a RATIONAL_NUMBER argument.	*/
RATIONAL_NUMBER copy_RATIONAL_NUMBER(RATIONAL_NUMBER N);

//!	Destructor for the RATIONAL_NUMBER type.
/*!	\param	N	a RATIONAL_NUMBER argument.	*/
void		destroy_RATIONAL_NUMBER(RATIONAL_NUMBER N);

//!	Array copy constructor for the RATIONAL_NUMBER type.
/*!
	\param	Ns	an array of RATIONAL_NUMBER values.
	\param	len_N	an integer argument for the length of the array.
*/
RATIONAL_NUMBER*	array_copy_RATIONAL_NUMBER(RATIONAL_NUMBER* Ns, int len_N);

//!	Array destructor for the RATIONAL_NUMBER type.
/*!
	\param	Ns	an array of RATIONAL_NUMBER values.
	\param	len_N	an integer argument for the length of the array.
*/
void			array_destroy_RATIONAL_NUMBER(RATIONAL_NUMBER* Ns, int len_N);

//!	Negation operator for NSComparisonResult \f$\in 3^3\f$.
/*!	\param	r	the NSComparisonResult value to negate.	*/
NSComparisonResult negate_comparison_result(NSComparisonResult r);

//!	Comparison relation of RATIONAL_NUMBER values \f$\in 3^{\mathbf{Q}^2}\f$.
/*!
	\param	lhs	the RATIONAL_NUMBER value on the left side of the relation.
	\param	rhs	the RATIONAL_NUMBER value on the right side of the relation.
*/
NSComparisonResult RATIONAL_NUMBER_compare(RATIONAL_NUMBER lhs, RATIONAL_NUMBER rhs);

//!	Less-than relation of RATIONAL_NUMBER values \f$\in 2^{\mathbf{Q}^2}\f$.
/*!
	\param	lhs	the RATIONAL_NUMBER value on the left side of the relation.
	\param	rhs	the RATIONAL_NUMBER value on the right side of the relation.
*/
bool RATIONAL_NUMBER_is_less_than(RATIONAL_NUMBER lhs, RATIONAL_NUMBER rhs);

//!	Is-equal-to relation of RATIONAL_NUMBER values \f$\in 2^{\mathbf{Q}^2}\f$.
/*!
	\param	lhs	the RATIONAL_NUMBER value on the left side of the relation.
	\param	rhs	the	RATIONAL_NUMBER value on the right side of the relation.
*/
bool RATIONAL_NUMBER_is_equal_to(RATIONAL_NUMBER lhs, RATIONAL_NUMBER rhs);

#pragma mark ARITHMETIC

//!	Negation unary operator for the RATIONAL_NUMBER type.
/*!	\param	N	the RATIONAL_NUMBER value to be negated.	*/
RATIONAL_NUMBER RATIONAL_NUMBER_negate(RATIONAL_NUMBER N);

//!	Sum binary operator for the RATIONAL_NUMBER type.
/*!
	\param	LHS	the RATIONAL_NUMBER value on the left side of the addition sign.
	\param	RHS	the RATIONAL_NUMBER value on the right side of the addition sign.
*/
RATIONAL_NUMBER RATIONAL_NUMBER_sum(RATIONAL_NUMBER LHS, RATIONAL_NUMBER RHS);

//!	Difference binary operator for the RATIONAL_NUMBER type.
/*!
	\param	LHS	the RATIONAL_NUMBER value on the left side of the subtraction sign.
	\param	RHS	the RATIONAL_NUMBER value on the right side of the subtraction sign.
*/
RATIONAL_NUMBER RATIONAL_NUMBER_difference(RATIONAL_NUMBER LHS, RATIONAL_NUMBER RHS);

//!	Product binary operator for the RATIONAL_NUMBER type.
/*!
	\param	LHS	the RATIONAL_NUMBER value on the left side of the multiplication sign.
	\param	RHS	the RATIONAL_NUMBER value on the right side of the multiplication sign.
*/
RATIONAL_NUMBER RATIONAL_NUMBER_product(RATIONAL_NUMBER LHS, RATIONAL_NUMBER RHS);

//!	Reciprocation operator for the RATIONAL_NUMBER type.
/*!	\param	N	the RATIONAL_NUMBER value to be reciprocated.	*/
RATIONAL_NUMBER RATIONAL_NUMBER_reciprocate(RATIONAL_NUMBER N);

NSString* StringFor_RATIONAL_NUMBER(RATIONAL_NUMBER N);

#endif
