#include "shotsArray.h"

shotsArray::shotsArray()
{
	for (unsigned int i = 0; i < size; i++)
		Arr[i] = NULL;
	
	size = 0;
}

shotsArray::~shotsArray()
{
	for (unsigned int i = 0; i < size; i++)
	{
		delete Arr[i];
		Arr[i] = NULL;
	}
	size = 0;
}

void shotsArray::initArr(){
	for (unsigned int i = 0; i < size; i++)
	{
		Arr[i]->shotErase();
		delete Arr[i];
		Arr[i] = NULL;
	}
	size = 0;
}

void shotsArray::printShots() const{
	for (unsigned int i = 0; i < size; i++)
		Arr[i]->shotDraw();
}

unsigned int shotsArray::getSize()
{
	return size;
}

Shot* shotsArray::getShotInArr(int i)
{
	return Arr[i];
}

unsigned int  shotsArray::setSize(unsigned int newSize)
{
	size = newSize;
	return size;
}

void shotsArray::move()
{
	if (size != 0)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			Arr[i]->shotMove();
			delete Arr[i];
			Arr[i] = NULL;
			--size;
		}		
	}
}

int shotsArray::addShot(Point shotPosition, Direction::VALUE shotDirection)
{	
	Arr[size] = new Shot(shotPosition, shotDirection);
	size++;
	return size - 1;
}

void shotsArray::delShot(int i)
{
	Arr[i]->shotErase();
	swap(Arr[i], Arr[size - 1]);
	delete Arr[size - 1];
	Arr[size - 1] = NULL;
	
	--size;
}

void shotsArray::swap(Shot* &a, Shot* &b)
{
	Shot* tmp;
	tmp = a;
	a = b;
	b = tmp;
}