#include "circlesboxcontextmanager.h"

#include "circlesboxviewmanager.h"
#include "circleobject.h"
#include "box.h"
#include "bounceinner.h"

CirclesBoxContextManager::CirclesBoxContextManager(): _tempCircle(nullptr)
{

	_box.setDimensions(Vector2(300, 400));
	_box.setDrawMode(GL_LINE_LOOP);

	_eventManager.setContextManager(*this);

	_engines.addEngine("collision", new Collision);
	_engines.addEngine("physic", new Physics);
	_engines.addEngine("events", &_eventManager);

	{
		Collision* collision = (Collision*)(&_engines.getEngine("collision"));

		collision->addData(&_box, {"box"});

		collision->addTester(new SatTester, "box");
		collision->addTester(new SatTester, "circle");
	}

	CircleObject* first = new CircleObject;
	first->setRadius(75);
	first->setMass(75 * 2 * pi);
	first->setColor(sf::Color(255, 255, 255));
	addCicle(first);

	((Physics*)(&_engines.getEngine("physic")))->addData(first);

	_engines.setLoopPerSecond(0);
	_engines.setSpeed(0.75);
	_engines.running(true);
}

CirclesBoxContextManager::~CirclesBoxContextManager()
{
	_engines.running(false);
}

void CirclesBoxContextManager::addCicle(CircleObject* circle)
{
	_circles.push_back(circle);

	circle->setDrawMode(GL_POLYGON);
	circle->setRule("gravity", new Rule::Gravity(Vector2(0, 30)));
	circle->setRule("resistance", new Rule::Resistance(Vector2(1, 1)*circle->getRadius()));
	circle->setRule("spring", new Rule::Spring(Vector2(0, 0), 40, Vector2(400.00001, 300)));

	circle->addCollisionHandler(new BounceInner, "box");

	((Collision*)(&_engines.getEngine("collision")))->addData(circle, {"box", "circle"});
}

Box& CirclesBoxContextManager::getBox()
{
	return _box;
}

void CirclesBoxContextManager::removeCicle(CircleObject* cicle)
{
	((Physics*)(&_engines.getEngine("physic")))->removeData(*cicle);
	((Collision*)(&_engines.getEngine("collision")))->removeData(*cicle);
	((CirclesBoxViewManager*)(_viewManager))->removeCicle(*cicle);

	_circles.remove(cicle);
	delete cicle;
}

void CirclesBoxContextManager::execute(const float time)
{
	_box.setAngle(_box.getAngle() + (0.01 * time));
	//_box.setAngle(pi*1.5);
}

void CirclesBoxContextManager::setViewManager(ViewManager& viewManager)
{
	ContextManager::setViewManager(viewManager);
	((CirclesBoxViewManager*)(_viewManager))->setBox(_box);
for(auto circle : _circles)
	{
		((CirclesBoxViewManager*)(_viewManager))->addCicle(*circle);
	}
}

void CirclesBoxContextManager::applyTempCircle()
{
	if(_tempCircle != nullptr)
	{
		if(_tempCircle->getRadius() > 2)
		{
			addCicle(_tempCircle);
			((Physics*)(&_engines.getEngine("physic")))->addData(_tempCircle);
		}
		else
		{
			removeCicle(_tempCircle);
		}

		_tempCircle = nullptr;
	}
}

CircleObject* CirclesBoxContextManager::circleHitTest(const Vector2 point)
{
	PointTester tester;
	CollisionResult* result;
	Collisionnable::Point test_point(point);

for(auto circle : _circles)
	{
		result = tester.compareObject(*circle, test_point, 0);

		if(result != nullptr && result->isCollision)
		{
			return circle;
		}
	}
	return nullptr;
}

const CircleObject* CirclesBoxContextManager::circleHitTest(const Vector2 point) const
{
	PointTester tester;
	CollisionResult* result;
	Collisionnable::Point test_point(point);

for(auto circle : _circles)
	{
		result = tester.compareObject(*circle, test_point, 0);
		if(result != nullptr && result->isCollision)
		{
			return circle;
		}
	}
	return nullptr;
}

void CirclesBoxContextManager::createTempCircle(const Vector2 position)
{
	if(_tempCircle != nullptr)
	{
		applyTempCircle();
	}

	_tempCircle = new CircleObject;
	_tempCircle->setColor(sf::Color(255, 255, 255));
	_tempCircle->setPosition(position);
	_tempCircle->setDrawMode(GL_LINE_LOOP);

	((CirclesBoxViewManager*)(_viewManager))->addCicle(*_tempCircle);
}

void CirclesBoxContextManager::setSpring(CircleObject* circle, Vector2 position)
{
	((Rule::Spring*)(&circle->getRule("spring")))->setValue(Vector2(300, 300));
	((Rule::Spring*)(&circle->getRule("spring")))->setPosition(position);
	
	((CirclesBoxViewManager*)(_viewManager))->setSpring(*circle, *((Rule::Spring*)(&circle->getRule("spring"))) );
}

void CirclesBoxContextManager::setSpringPosition(CircleObject* circle, Vector2 position)
{
	((Rule::Spring*)(&circle->getRule("spring")))->setPosition(position);
}

void CirclesBoxContextManager::unsetSpring(CircleObject* circle)
{
	((Rule::Spring*)(&circle->getRule("spring")))->setValue(Vector2());
}

void CirclesBoxContextManager::setTempCircleRadiusByPoint(const Vector2 position)
{
	if(_tempCircle != nullptr)
	{
		double newSize = (_tempCircle->getPosition() - position).getLenght();
		if(newSize < 100)
		{
			_tempCircle->setRadius(newSize);
			_tempCircle->setMass(2 * newSize * pi);
		}
		else
		{
			_tempCircle->setRadius(100);
			_tempCircle->setMass(2 * 100 * pi);
		}
	}
}

