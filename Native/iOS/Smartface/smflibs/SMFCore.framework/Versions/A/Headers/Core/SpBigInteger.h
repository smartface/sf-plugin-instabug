
#ifndef __SPBIGINTEGER_H__
#define __SPBIGINTEGER_H__

#define KBigIntegerExceptionBase					0x1000
#define KBigIntegerExceptionPositiveOverflow		KBigIntegerExceptionBase+0x01
#define KBigIntegerExceptionNegativeOverflow		KBigIntegerExceptionBase+0x02
#define KBigIntegerExceptionInvalidString			KBigIntegerExceptionBase+0x03
#define KBigIntegerExceptionByteOverflow			KBigIntegerExceptionBase+0x04
#define KBigIntegerExceptionOperatorPlus			KBigIntegerExceptionBase+0x05
#define KBigIntegerExceptionOperatorPlusPlus		KBigIntegerExceptionBase+0x06
#define KBigIntegerExceptionOperatorMinus			KBigIntegerExceptionBase+0x07
#define KBigIntegerExceptionOperatorMinusMinus		KBigIntegerExceptionBase+0x08
#define KBigIntegerExceptionOperatorProduct			KBigIntegerExceptionBase+0x09
#define KBigIntegerExceptionOperatorNegative		KBigIntegerExceptionBase+0x0A
#define KBigIntegerExceptionToStringRadix			KBigIntegerExceptionBase+0x0B
#define KBigIntegerExceptionPowMod					KBigIntegerExceptionBase+0x0C


#define KMAXSIZE			512

#define KMAXUUNIT			0xFFFF
#define KUNITMINUSONE		0x8000
#define KMAXUUNITPLUSONE	0x10000
#define KUNITBITLEN			16

typedef short				TUnit;
typedef unsigned short		TUUnit;
typedef int					TDoubleUnit;
typedef unsigned int		TUDoubleUnit;
typedef unsigned char		TByte;

class SpBigInteger
{
public:
	SpBigInteger();
	SpBigInteger(TDoubleUnit value);
	SpBigInteger(TUDoubleUnit value);
	SpBigInteger(TUUnit buffer[KMAXSIZE],TUnit bufferLength);
	SpBigInteger(const SpBigInteger& bi);
	SpBigInteger(const char* value,TUnit radix);
	SpBigInteger(TByte* inData,TUnit inLen);

public:
	SpBigInteger operator+(const SpBigInteger& bi) const;
	SpBigInteger operator++() const;
	SpBigInteger operator-(const SpBigInteger& bi) const;
	SpBigInteger operator--() const;
	SpBigInteger operator*(const SpBigInteger& bi) const;
	SpBigInteger operator/(const SpBigInteger& bi) const;
	SpBigInteger operator%(const SpBigInteger& bi) const;

	SpBigInteger operator<<(TUnit shiftVal) const;
	SpBigInteger operator>>(TUnit shiftVal) const;

	SpBigInteger operator~() const;
	SpBigInteger operator-() const;

	bool operator==(const SpBigInteger& bi);
	bool operator!=(const SpBigInteger& bi);
	bool operator>(const SpBigInteger& bi);
	bool operator<(const SpBigInteger& bi);
	bool operator>=(const SpBigInteger& bi);
	bool operator<=(const SpBigInteger& bi);
	bool Equals(const SpBigInteger& bi) const;

	void ToString(char* result,TUnit radix);

	SpBigInteger modPow(const SpBigInteger& expo,const SpBigInteger& mod);

private:
	TUnit bitCount();
	SpBigInteger BarrettReduction(const SpBigInteger& x,const SpBigInteger& n,const SpBigInteger& constant);

private:
	static TUnit shiftLeft(TUUnit buffer[KMAXSIZE],const TUnit& bufferLength,const TUnit& shiftVal);
	static TUnit shiftRight(TUUnit buffer[KMAXSIZE],const TUnit& bufferLength,const TUnit& shiftVal);

	static void multiByteDivide(const SpBigInteger& bi1,const SpBigInteger& bi2,SpBigInteger& outQuotient,SpBigInteger& outRemainder);
	static void singleByteDivide(const SpBigInteger& cbi1,const SpBigInteger& cbi2,SpBigInteger& outQuotient,SpBigInteger& outRemainder);

	static void InsertCharAtZero(char ch,char* string);

private:
	TUUnit		data[KMAXSIZE];
	TUnit		dataLength;
};

#endif
