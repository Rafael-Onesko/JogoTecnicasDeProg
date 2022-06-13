#pragma once
#include "Obstaculo.h"
namespace Entidades {
	namespace Obstaculos {
		class Agua : public Obstaculo
		{
		private:
			static int numAguas;
		public:
			Agua();
			Agua(float pX, float pY);
			~Agua();
			static int getNumAguas();
		};
	}
}

