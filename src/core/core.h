#pragma once

typedef enum __attribute__((packed)) Qit {
	A = -2,
	E,
	I,
	O,
	U
} Qit ;

typedef Qit Qyte[3];

Qit NOT(Qit _a);
Qit AND(Qit _a, Qit _b);
Qit OR(Qit _a, Qit _b);
Qit NAND(Qit _a, Qit _b);
Qit NOR(Qit _a, Qit _b);
Qit XOR(Qit _a, Qit _b);

#define QYTE_MONO_FUNCTION(_function, _a)		\
{												\
	_function(_a[0]),							\
	_function(_a[1]),							\
	_function(_a[2])							\
}

#define QYTE_DUAL_FUNCTION(_function, _a, _b)	\
{												\
	_function(_a[0], _b[0]),					\
	_function(_a[1], _b[1]),					\
	_function(_a[2], _b[2]),					\
}

#define NOTQ(_a) QYTE_MONO_FUNCTION(NOT, _a)
#define ANDQ(_a) QYTE_DUAL_FUNCTION(AND, _a, _b)
#define ORQ(_a) QYTE_DUAL_FUNCTION(OR, _a, _b)
#define NANDQ(_a) QYTE_DUAL_FUNCTION(NAND, _a, _b)
#define NORQ(_a) QYTE_DUAL_FUNCTION(NOR, _a, _b)
#define XORQ(_a) QYTE_DUAL_FUNCTION(XOR, _a, _b)
