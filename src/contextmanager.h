#ifndef CONTEXTMANAGER_H
#define CONTEXTMANAGER_H

#include "viewmanager.h"

class ContextManager
{
public:
	ContextManager();
	virtual ~ContextManager();
	
	void setViewManager(ViewManager& viewManager);
	
	const ViewManager& getViewManager() const;
	ViewManager& getViewManager();
	
protected:
	MainEngine _engines;
	
private:
	ViewManager* _viewManager;
};

#endif // CONTEXTMANAGER_H
