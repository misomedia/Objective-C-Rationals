//
//  Rational.h
//  Rational
//
//  Created by Ryan Hiroaki Tsukamoto on 3/2/12.
//  Copyright (c) 2012 Miso Media. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Rationals/RationalNumberC.h>

#pragma mark OBJ_C_BOX

//!	An Objective-C wrapper for the RATIONAL_NUMBER type.
@interface RationalNumber : NSObject	<NSCopying>
{
	RATIONAL_NUMBER underlying_number;	/*!<	The RATIONAL_NUMBER.	*/
}

//!	Convenience method for constructing a RationalNumber instance by copying a RationalNumber.
/*!	\param	n	the RationalNumber to be copied.	*/
+(RationalNumber*)numberWithRationalNumber:(RationalNumber*)n;

//!	Convenience method for constructing a RationalNumber instance from an unsigned integer.
/*!	\param	n	the unsigned integer whose value is to be used.	*/
+(RationalNumber*)numberWithUnsignedInt:(uint)n;

//!	Convenience method for constructing a RationalNumber instance from an integer.
/*!	\param	n	the integer whose value is to be used.	*/
+(RationalNumber*)numberWithInt:(int)n;

//!	Convenience method for constructing a RationalNumber instance from a floating point number.
/*!	\param	n	the floating point number whose value is to be used.	*/
+(RationalNumber*)numberWithFloat:(float)n;

//!	Convenience method for constructing a RationalNumber instance from a double precision floating point number.
/*!	\param	n	the double precision floating point number whose value is to be used.	*/
+(RationalNumber*)numberWithDouble:(double)n;

//!	Convenience method for constructing a RationalNumber instance from a fraction represented by an integer and an unsigned integer.
/*!
	\param	num	the integer whose value is to be used for the numerator.
	\param	den	the unsigned integer whose value is to be used for the denominator.  This cannot be zero, nor can it be one.
*/
+(RationalNumber*)fractionWithNumeratorInt:(int)num denominatorUnsignedInt:(uint)den;

//!	Convenience method for constructing a RationalNumber instance from the sum of an integer and a fraction strictly between zero and one represented by an integer and two unsigned integers.
/*!
	\param	integer	the integer whose value is to be used for the integer.
	\param	fracNum	the unsigned integer whose value is to be used for the numerator of the fraction.
	\param	fracDen	the unsigned integer whose value is to be used for the denominator of the fraction.  This cannot be zero, nor can it be one, nor can it be less than or equal to fracNum.
*/
+(RationalNumber*)fractionWithIntegerInt:(int)integer fractionNumeratorUnsignedInt:(uint)fracNum fractionDenominatorUnsignedInt:(uint)fracDen;

//!	Convenience method for constructing a RationalNumber instance from an existing RATIONAL_NUMBER.
/*!	
	It does not consume its argument (the result copies its argument).
	\param	n	the RATIONAL_NUMBER whose value will be copied and used to construct the result.
*/
+(RationalNumber*)numberWithUnderlyingNumber:(RATIONAL_NUMBER)n;

//!	Convenience method for constructing a RationalNumber instance from a string representation of a rational number.
+(RationalNumber*)numberWithString:(NSString*)string;

//!	Compares two RationalNumber instances.
/*!
	\param	LHS	the RationalNumber on the left.
	\param	RHS	the RationalNumber on the right.
	\return	the result of comparison as an NSComparisonResult
*/
+(NSComparisonResult)compareLHS:(RationalNumber*)LHS RHS:(RationalNumber*)RHS;

//!	Computes the sum of two RationalNumber instances.
/*!
	\param	LHS	the RationalNumber to the left of the addition sign.
	\param	RHS	the RationalNumber to the right of the addition sign.
	\return the sum of LHS and RHS.
*/
+(RationalNumber*)sumOfLHS:(RationalNumber*)LHS RHS:(RationalNumber*)RHS;

//!	Computes the difference between two RationalNumber instances.
/*!
	\param	LHS	the RationalNumber to the left of the subtraction sign.
	\param	RHS	the RationalNumber to the right of the subtraction sign.
	\return the difference between LHS and RHS.
*/
+(RationalNumber*)differenceBetweenLHS:(RationalNumber*)LHS RHS:(RationalNumber*)RHS;

//!	Computes the product of two RationalNumber instances.
/*!
	\param	LHS	the RationalNumber to the left of the multiplication sign.
	\param	RHS	the RationalNumber to the right of the multiplication sign.
	\return the product of LHS and RHS.
*/
+(RationalNumber*)productOfLHS:(RationalNumber*)LHS RHS:(RationalNumber*)RHS;

//!	Zero as a convenience method.
/*!
	\return	zero (as an unsigned int).
*/
+(RationalNumber*)zero;

//!	Computes the sum of a list of RationalNumber summands.
/*!
	\param	summands	an NSArray instance containing the RationalNumber instances to be summed.
	\return	the sum of the RationalNumber instances contained in summands.
*/
+(RationalNumber*)sum:(NSArray*)summands;

//!	Computes the maximum of a list of RationalNumber instances.
/*!
	\param	numbers	an NSArray instance containing RationalNumber instances.
	\return	the greatest of the RationalNumber instances (if more than one number in the input is the maximum, one is chosen arbitrarily.  If input is empty, -\infty is returned).
*/
+(RationalNumber*)maximum:(NSArray*)numbers;

//!	Computes the minimum of a list of RationalNumber instances.
/*!
	\param	numbers	an NSArray instance containing RationalNumber instances.
	\return	the least of the RationalNumber instances (if more than one number in the input is the minimum, one is chosen arbitrarily.  If input is empty, \infty is returned).
*/
+(RationalNumber*)minimum:(NSArray*)numbers;

//!	One as a convenience method.
/*!
	\return one (as an unsigned int).
*/
+(RationalNumber*)one;

//! Positive infinity as a convenience method.
/*!
    \return pos_inf (as a signed infinity).
*/
+(RationalNumber*)positiveInfinity;

//! Negative infinity as a convenience method.
/*!
 \return neg_inf (as a signed infinity).
 */
+(RationalNumber*)negativeInfinity;

//!	Computes the product of a list of RationalNumber factors.
/*!
	\param	factors	an NSArray instance containing the RationalNumber instances to be produced.
	\return	the product of the RationalNumber instances contained in factors.
*/
+(RationalNumber*)product:(NSArray*)factors;

//!	A convenience method for creating a list of RationalNumber instances from an array of RATIONAL_NUMBER instances (copying them), yielding an NSArray instance containing the list of RationalNumber instances.
/*!
	The argument is not consumed.  Each RATIONAL_NUMBER instance in Ns is copied.
	\param	Ns	an array containing the RATIONAL_NUMBER instances to be copied.
	\param	length	an integer whose value is the length of Ns.
	\return an NSArray instance containing a list of RationalNumber instances.
	\sa	RationalNumber#unboxArray:
*/
+(NSArray*)boxArray:(RATIONAL_NUMBER*)Ns ofLength:(int)length;

//!	A convenience method for creating an array of RATIONAL_NUMBER instances from an array of RationalNumber instances (copying their underlying RATIONAL_NUMBER values).
/*!
	\param	Ns	an NSArray instance whose objects' underlying RATIONAL_NUMBER values are to be copied into the result.
	\return an RATIONAL_NUMBER array containing copies of the underlying RATIONAL_NUMBER values of objects of Ns.
	\sa RationalNumber#boxArray:ofLength
*/
+(RATIONAL_NUMBER*)unboxArray:(NSArray*)Ns;

//!	Initializes a new RationalNumber instance
/*!	\param	n	the RATIONAL_NUMBER whose value will be copied and used.	*/
-(id)initWithUnderlyingNumber:(RATIONAL_NUMBER)n;

//!	Initializes a new RationalNumber instance, copying the underlying value of an existing RationalNumber instance.
/*!	\param	n	the RationalNumber whose underlying value will be copied and used.	*/
-(id)initWithRationalNumber:(RationalNumber*)n;

//!	Creates and returns a copy of the underlying RATIONAL_NUMBER value.
-(RATIONAL_NUMBER)underlyingNumber;

//!	Returns the reciprocal (multiplicative inverse) of the value.
-(RationalNumber*)reciprocal;

//!	Returns the opposite (additive inverse) of the value.
-(RationalNumber*)opposite;

//!	Compares this (to the left) with another RationalNumber to the right of the comparison.
/*!	\param	n	The RationalNumber to the right of the comparison.	*/
-(NSComparisonResult)compare:(RationalNumber*)n;

//!	Adds this to another RationalNumber, returning the sum.
/*!	\param	n	The RationalNumber we add to this to get the result.	*/
-(RationalNumber*)plus:(RationalNumber*)n;

//!	Subtracts, from this, another RationalNumber, returning the difference.
/*!	\param	n	The RationalNumber we subtract from this to get the result.	*/
-(RationalNumber*)minus:(RationalNumber*)n;

//!	Multiplies this with another RationalNumber, returning the product.
/*!	\param	n	The RationalNumber we multiply with this to get the result.	*/
-(RationalNumber*)times:(RationalNumber*)n;

//!	Determines whether or not this is less than another RationalNumber.
/*!	\param	n	The RationalNumber we place on the right side of the is-less-than sign	*/
-(BOOL)isLessThan:(RationalNumber*)n;

//!	Determines whether or not this is equal to another RationalNumber.
/*!	\param	n	The RationalNumber we place on the right side of the is-equal-to sign	*/
-(BOOL)isEqualTo:(RationalNumber*)n;

//!	Return the value as a float.
-(float)floatValue;

//!	Formats the number as a string.
-(NSString*)stringValue;

@end

@interface RationalNumber (JSONCodec)

+(RationalNumber*)importFromJSON:(id)json;

+(RationalNumber*)importRationalNumberFromJSON:(id)json;

-(id)exportToJSON;

@end
