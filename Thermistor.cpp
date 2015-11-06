/*
 * Thermistor.cpp
 *
 *  Created on: Nov 5, 2015
 *      Author: sigmond
 */

#include "Thermistor.h"

Thermistor::Thermistor(unsigned int analog_pin, unsigned int scale_ohm, unsigned int static_ohm, float temp_nom_c, unsigned int b_coeff) {
	m_Pin = analog_pin;
	m_ScaleOhm = scale_ohm;
	m_StaticOhm = static_ohm;
	m_NomC = temp_nom_c;
	m_BetaCoeff = b_coeff;
}

Thermistor::~Thermistor() {

}

float Thermistor::readTemp(Temperature temp) {
	float reading;

	reading = analogRead(m_Pin);

	reading = (1023 / reading)  - 1;
	reading = m_StaticOhm / reading;


	float steinhart;
	steinhart = reading / m_ScaleOhm;            // (R/Ro)
	steinhart = log(steinhart);                  // ln(R/Ro)
	steinhart /= m_BetaCoeff;                    // 1/B * ln(R/Ro)
	steinhart += 1.0 / (m_NomC + 273.15);        // + (1/To)
	steinhart = 1.0 / steinhart;                 // Invert
	steinhart -= 273.15;                         // convert to C

	if (temp == FAHRENHEIT) {
		steinhart = (steinhart*9/5)+32;
	}

	return steinhart;
}

