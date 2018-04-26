#include "Logic.h"
#include "Actors.h"
#include <vector>

using namespace std;


void ActorLogic()
{
	for (vector<Actors>::iterator BagIterator = ActorBag.begin(); BagIterator != ActorBag.end(); ++BagIterator)
	{
		if (BagIterator->Get_Logic() && BagIterator->Get_ID > 2)
		{
			//FOV()
			//AI()
			BagIterator->Set_Logic(false);
		}
	}
}

void PropLogic()
{
	for (vector<Props>::iterator BagIterator = PropBag.begin(); BagIterator != PropBag.end(); ++BagIterator)
	{

	}
}

void SetLogic()
{
	for (vector<Sets>::iterator BagIterator = SetBag.begin(); BagIterator != SetBag.end(); ++BagIterator)
	{

	}
}


//AI//



//FOV//



//MOVEMENT//