#include "contextmanager.h"

ContextManager::ContextManager() : _viewManager(nullptr)
{
	_engines.addEngine("context manager", this);
}

ContextManager::~ContextManager()
{

}

const ViewManager& ContextManager::getViewManager() const
{
	return *_viewManager;
}

ViewManager& ContextManager::getViewManager()
{
	return *_viewManager;
}

void ContextManager::setViewManager(ViewManager& viewManager)
{
	_viewManager = &viewManager;
}
