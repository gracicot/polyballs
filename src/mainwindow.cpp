#include "mainwindow.h"

MainWindow::MainWindow(): _viewManager(nullptr)
{
	
}

MainWindow::~MainWindow()
{
	
}

void MainWindow::render()
{
	_viewManager->render(*this);
}

void MainWindow::setViewManager(ViewManager& viewmanager)
{
	_viewManager = &viewmanager;
}
