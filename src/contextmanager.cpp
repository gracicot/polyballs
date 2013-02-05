#include "contextmanager.h"

ContextManager::ContextManager() : _viewManager(nullptr)
{

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
