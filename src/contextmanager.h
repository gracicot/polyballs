#ifndef CONTEXTMANAGER_H
#define CONTEXTMANAGER_H

#include "viewmanager.h"

class ContextManager : public Engine
{
public:
	ContextManager();
	virtual ~ContextManager();
	
	virtual void setViewManager(ViewManager& viewManager);
	
	const ViewManager& getViewManager() const;
	ViewManager& getViewManager();
	
protected:
	MainEngine _engines;
	ViewManager* _viewManager;
};

#endif // CONTEXTMANAGER_H
