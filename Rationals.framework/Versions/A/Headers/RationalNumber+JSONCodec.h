//
//  RationalNumber+JSONCodec.h
//  Rationals
//
//  Created by Ryan Tsukamoto on 5/16/12.
//  Copyright (c) 2012 Miso Media. All rights reserved.
//

#import <Rationals/RationalNumber.h>

@interface RationalNumber (JSONCodec)

+(RationalNumber*)importRationalNumberFromJSON:(id)json;

-(id)exportToJSON;

@end
