/*
 * Thermistor.h
 *
 *  Created on: Nov 5, 2015
 *      Author: sigmond
 */

#ifndef THERMISTOR_H_
#define THERMISTOR_H_
#include "Arduino.h"

class Thermistor {
	enum Temperature{CELCIUS, FAHRENHEIT};
public:

	Thermistor(unsigned int analog_pin, unsigned int scale_ohm=3000, unsigned int static_ohm=10000, float temp_nom_c = 25.0, unsigned int b_coeff = 3936);
	virtual ~Thermistor();

	virtual float readTemp(Temperature temp = CELCIUS);

private:
	unsigned int m_ScaleOhm;
	unsigned int m_StaticOhm;
	unsigned int m_Pin;
	float m_NomC;
	unsigned int m_BetaCoeff;

};

#endif /* THERMISTOR_H_ */
