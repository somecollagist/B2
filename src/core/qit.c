// The use of NAND-based circuitry is a direct reflection of modern hardware

#include "core.h"

/// @brief Stands in for a switch case
/// @param _param The variable to test
/// @param _a The mapping for Qit A
/// @param _e The mapping for Qit E
/// @param _i The mapping for Qit I
/// @param _o The mapping for Qit O
/// @param _u The mapping for Qit U
/// @return The corresonding mapping for the variable
static inline Qit Switch(Qit _param, Qit _a, Qit _e, Qit _i, Qit _o, Qit _u){
	Qit ret = I;
	switch(_param){
		case A:
			ret = _a;
			break;
		case E:
			ret = _e;
			break;
		case I:
			ret = _i;
			break;
		case O:
			ret = _o;
			break;
		case U:
			ret = _u;
			break;
	}
	return ret;
}

/// @brief Qitwise logical NAND gate
/// @param _a First Qit to test
/// @param _b Second Qit to test
/// @return The logical NAND of the two Qits
Qit NAND(Qit _a, Qit _b){
	return Switch(
		_a,
		Switch(
			_b,
			U, U, U, U, U
		),
		Switch(
			_b,
			U, O, O, O, O
		),
		Switch(
			_b,
			U, O, I, I, I
		),
		Switch(
			_b,
			U, O, I, E, E
		),
		Switch(
			_b,
			U, O, I, E, A
		)
	);
}

/// @brief Qitwise logical NOT gate
/// @param _a First Qit to test
/// @param _b Second Qit to test
/// @return The logical NOT of the two Qits
Qit NOT(Qit _a){
	return NAND(_a, _a);
}

/// @brief Qitwise logical AND gate
/// @param _a First Qit to test
/// @param _b Second Qit to test
/// @return The logical AND of the two Qits
Qit AND(Qit _a, Qit _b){
	return NOT(NAND(_a, _b));
}

/// @brief Qitwise logical OR gate
/// @param _a First Qit to test
/// @param _b Second Qit to test
/// @return The logical OR of the two Qits
Qit OR(Qit _a, Qit _b){
	return NAND(NOT(_a), NOT(_b));
}

/// @brief Qitwise logical NOR gate
/// @param _a First Qit to test
/// @param _b Second Qit to test
/// @return The logical NOR of the two Qits
Qit NOR(Qit _a, Qit _b){
	return NOT(NAND(NOT(_a), NOT(_b)));
}

/// @brief Qitwise logical XOR gate
/// @param _a First Qit to test
/// @param _b Second Qit to test
/// @return The logical XOR of the two Qits
Qit XOR(Qit _a, Qit _b){
	Qit ANANDB = NAND(_a, _b);
	return NAND(NAND(_a, ANANDB), NAND(ANANDB, _b));
}