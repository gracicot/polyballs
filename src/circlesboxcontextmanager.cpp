#include "circlesboxcontextmanager.h"

#include "circlesboxviewmanager.h"
#include "circleobject.h"
#include "box.h"
#include "bounceinner.h"

CirclesBoxContextManager::CirclesBoxContextManager(): _tempCircle(nullptr)
{

    _box.setDimensions(Vector2(300, 400));
    _box.setPosition(Vector2(400, 300));
    _box.setDrawMode(GL_LINE_LOOP);

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
    first->setColor(sf::Color(255, 255, 255));
    first->setPosition(Vector2(400, 300));
    addCicle(first);


    ((Physics*)(&_engines.getEngine("physic")))->addData(first);

    _engines.setSpeed(1);
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
    circle->setRule("gravity", new Rule::Gravity(Vector2(0, 5)));
    circle->setRule("resistance", new Rule::Resistance(Vector2(0.02, 0.02)));

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
    _box.setAngle(_box.getAngle() + (0.1*time));
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
		addCicle(_tempCircle);
        ((Physics*)(&_engines.getEngine("physic")))->addData(_tempCircle);
		
		_tempCircle = nullptr;
    }
}

void CirclesBoxContextManager::createTempCircle(Vector2 position)
{
    if(_tempCircle != nullptr)
    {
        applyTempCircle();
    }

    _tempCircle = new CircleObject;
    _tempCircle->setColor(sf::Color(255, 255, 255));
    _tempCircle->setPosition(position);
    _tempCircle->setDrawMode(GL_LINE_LOOP);

    if(_viewManager != nullptr)
    {
        ((CirclesBoxViewManager*)(_viewManager))->addCicle(*_tempCircle);
    }
}

void CirclesBoxContextManager::setTempCircleRadiusByPoint(Vector2 position)
{
    _tempCircle->setRadius((_tempCircle->getPosition() - position).getLenght());
}
