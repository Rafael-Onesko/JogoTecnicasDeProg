#pragma once
#include "Obstaculo.h"
namespace Entidades {
	namespace Obstaculos {
		class Muralha :
			public Obstaculo
		{
		private:
			static int numMuralhas;
		public:
			Muralha();
			~Muralha();
			Muralha(float pX, float pY);
			static int getNumMuralhas();
		};
	}
}

