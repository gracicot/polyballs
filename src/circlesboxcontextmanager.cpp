#include "circlesboxcontextmanager.h"

#include "circlesboxviewmanager.h"
#include "circleobject.h"
#include "box.h"
#include "bounceinner.h"

CirclesBoxContextManager::CirclesBoxContextManager(): _tempCircle(nullptr), _boxSpeed(0.2)
{

	_box.setDimensions(Vector2(600, 750));
	_box.setDrawMode(GL_LINE_LOOP);

	_eventManager.setContextManager(*this);

	_engines.addEngine("collision", new Collision);
	_engines.addEngine("physic", new Physics);
	_engines.addEngine("events", &_eventManager);

	{
		Collision* collision = (Collision*)(&_engines.getEngine("collision"));

	for(auto & box : _box.collisionsSquares())
		{
			collision->addData(box, {"box"});
		}

		collision->addTester(new SatTester, "box");
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
	circle->setRule("gravity", new Rule::Gravity(Vector2(0, 80)));
	circle->setRule("resistance", new Rule::Resistance(Vector2(0.5, 0.5)*circle->getRadius()));
	circle->setRule("spring", new Rule::Spring(Vector2(0, 0), 100, Vector2(400.00001, 300)));

	circle->addCollisionHandler(new Bounce, "box");

	((Collision*)(&_engines.getEngine("collision")))->addData(circle, {"box"});
}

Box& CirclesBoxContextManager::getBox()
{
	return _box;
}

void CirclesBoxContextManager::removeCicle(CircleObject*& circle)
{
	((Physics*)(&_engines.getEngine("physic")))->removeData(*circle);
	((Collision*)(&_engines.getEngine("collision")))->removeData(*circle);
	((CirclesBoxViewManager*)(_viewManager))->removeCicle(*circle);

	if(((CirclesBoxViewManager*)(_viewManager)))
		((CirclesBoxViewManager*)(_viewManager))->unsetSpring(*circle);
	_circles.remove(circle);
	delete circle;
	circle = nullptr;
}

void CirclesBoxContextManager::execute(const float time)
{
	_box.setAngle(_box.getAngle() + (_boxSpeed * time));

	correctCircle();
}

void CirclesBoxContextManager::correctCircle()
{
	if(_tempCircle != nullptr)
	{

		SatTester tester;
		SatResult* result = nullptr;

	for(auto border : _box.collisionsSquares())
		{
			result = dynamic_cast<SatResult*>(tester.compareObject(*_tempCircle, *border, 0));


			if(result != nullptr)
			{
				_tempCircle->setRadius(_tempCircle->getRadius() - result->distance.getLenght());
			}
		}
	}
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
		if(_tempCircle->getRadius() > 5)
		{
			_tempCircle->setMass(2 * _tempCircle->getRadius() * pi);
			addCicle(_tempCircle);
			((Physics*)(&_engines.getEngine("physic")))->addData(_tempCircle);
			_tempCircle = nullptr;
		}
		else
		{
			removeCicle(_tempCircle);
		}

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

Box* CirclesBoxContextManager::boxHitTest(const Vector2 point)
{
	PointTester tester;
	CollisionResult* result;
	Collisionnable::Point test_point(point);

	result = tester.compareObject(_box, test_point, 0);
	if(result != nullptr && result->isCollision)
	{
		return &_box;
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
for(auto circles : _circles)
	{
		if(circle == circles)
		{
			((Rule::Spring*)(&circle->getRule("spring")))->setValue(Vector2(3, 3) * circle->getMass());
			((Rule::Spring*)(&circle->getRule("spring")))->setPosition(position);

			((CirclesBoxViewManager*)(_viewManager))->setSpring(*circle, *((Rule::Spring*)(&circle->getRule("spring"))));
		}
	}
}

void CirclesBoxContextManager::setSpringPosition(CircleObject* circle, Vector2 position)
{
for(auto circles : _circles)
	{
		if(circle == circles)
		{
			((Rule::Spring*)(&circle->getRule("spring")))->setPosition(position);
		}
	}
}

void CirclesBoxContextManager::unsetSpring(CircleObject* circle)
{
for(auto circles : _circles)
	{
		if(circle == circles)
		{
			((Rule::Spring*)(&circle->getRule("spring")))->setValue(Vector2());
		}
	}
}

void CirclesBoxContextManager::breakCircle(CircleObject* circle, double angle)
{
	angle += pi;
for(auto circles : _circles)
	{
		if(circle == circles)
		{
			if(circles->getRadius() / 2.0 > 4)
			{
				sf::Color color(circle->getColor());

				{
					sf::Color sub_color = color;
					int color_addition_total = color.r + color.g + color.b;

					sub_color.r = color.r - sf::Randomizer::Random(0, color_addition_total);
					sub_color.g = color.g - sf::Randomizer::Random(0, color_addition_total - (sub_color.r + color.r));
					sub_color.b = color.b - (sub_color.r + sub_color.g);

					color = sub_color;
				}

				{
					Vector2 position;
					Vector2 velocity;

					CircleObject* sub = new CircleObject;
					sub->setRadius(circle->getRadius() / 2);
					sub->setMass((circle->getRadius()) * pi);
					sub->setColor(color);


					position.setLenght((circles->getRadius() / 2));
					position.setAngle(angle - (pi));

					velocity = circle->getVelocity();
					velocity.setAngle(velocity.getAngle() - (pi / 2));


					sub->setPosition(circle->getPosition() + position);
					sub->setVelocity(velocity);


					addCicle(sub);

					((Physics*)(&_engines.getEngine("physic")))->addData(sub);
					((CirclesBoxViewManager*)(_viewManager))->addCicle(*sub);
				}

				sf::Color new_color;

				new_color.r = circle->getColor().r - color.r;
				new_color.g = circle->getColor().g - color.g;
				new_color.b = circle->getColor().b - color.b;

				{
					Vector2 position;
					Vector2 velocity;

					CircleObject* sub = new CircleObject;
					sub->setRadius(circle->getRadius() / 2);
					sub->setMass((circle->getRadius()) * pi);
					sub->setColor(new_color);

					position.setLenght(circles->getRadius() / 2);
					position.setAngle(angle + (pi));

					velocity = circle->getVelocity();
					velocity.setAngle(velocity.getAngle() + (pi / 2));

					sub->setPosition(circle->getPosition() - position);
					sub->setVelocity(velocity);

					addCicle(sub);

					((Physics*)(&_engines.getEngine("physic")))->addData(sub);
					((CirclesBoxViewManager*)(_viewManager))->addCicle(*sub);
				}
			}
			removeCicle(circle);
			break;
		}
	}
}

void CirclesBoxContextManager::setTempCircleRadiusByPoint(const Vector2 position)
{
	if(_tempCircle != nullptr)
	{
		double newSize = (_tempCircle->getPosition() - position).getLenght();
		if(newSize < 100)
		{
			_tempCircle->setRadius(newSize);
		}
		else
		{
			_tempCircle->setRadius(100);
		}
		correctCircle();
	}
}

double CirclesBoxContextManager::getBoxSpeed() const
{
	return _boxSpeed;
}

void CirclesBoxContextManager::setBoxSpeed(const double speed)
{
	_boxSpeed = speed;
}
