
#pragma once

#include "ofMain.h"
#include "ftArea.h"

namespace flowTools {
	
	class ftAreaNormalized: public ftArea {
	public:
		ftAreaNormalized() { ; }
		virtual	~ftAreaNormalized() { ; }
		
		void	setup(int _width = 32, int _height = 32, string _name = "");
		void	update(ofTexture& _texture);
		
		float 	getMagnitude()	{ return normalizedMagnitude; }
		float	getVelocity(int _index) { if (_index < numChannels) { return normalizedVelocity[_index];  } else { return 0; } }
		
		float	getNormalization()				{ return pNormalization.get(); }
		float	getComponentBoost()				{ return pComponentBoost.get(); }
		
		float	setNormalization(float _value)	{ pNormalization.set(_value); }
		void	setComponentBoost(float _value)	{ pComponentBoost.set(_value); }
		
	protected:
		
		ofParameter<float>		pNormalization;
		ofParameter<float>		pComponentBoost;
		ofParameter<float>		pNormalizedMagnitude;
		
		float 			normalizedMagnitude;
		vector<float> 	normalizedVelocity;
		
		void pFloatListener(float& _value) { ftArea::pFloatListener(_value); }
		
	};
}