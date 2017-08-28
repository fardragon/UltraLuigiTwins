#ifndef PositionComponent_h__
#define PositionComponent_h__
#include "Component.h"

class PositionComponent: public Component
{
public:
	PositionComponent();
	unsigned int x() const;
	unsigned int y() const;
	void setPos(unsigned int x, unsigned int y);
	void setX(unsigned int x);
	void setY(unsigned int y);

	void update() override;


private:
	unsigned int posX;
	unsigned int posY;

};

#endif // PositionComponent_h__

