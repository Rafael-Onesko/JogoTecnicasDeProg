#pragma once
#include "Obstaculo.h"
namespace Entidades {
	namespace Obstaculos {
		class Espinho : public Obstaculo
		{
		private:
			static int numEspinhos;
		public:
			Espinho();
			~Espinho();
			Espinho(float pX, float pY);
			static int getNumEspinhos();
		};
	}
}

