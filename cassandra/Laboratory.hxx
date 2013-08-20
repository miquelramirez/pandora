/*
 * Copyright (c) 2013
 * COMPUTER APPLICATIONS IN SCIENCE & ENGINEERING
 * BARCELONA SUPERCOMPUTING CENTRE - CENTRO NACIONAL DE SUPERCOMPUTACIÓN
 * http://www.bsc.es
 *
 * This file is part of Cassandra.
 * Cassandra is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Cassandra is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *  
 * You should have received a copy of the GNU General Public 
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef __Laboratory_hxx__
#define __Laboratory_hxx__

#include <QDialog>
#include <ui_Laboratory.h>
#include <tinyxml.h>

namespace GUI
{

enum ParamColumn
{
	eName = 0,
	eDefault = 1,
	eMin = 2,
	eMax = 3,
	eStep = 4
};

class Laboratory : public QDialog
{
	Q_OBJECT
	Ui::Laboratory _lab;

	std::string _simulationBinary;
	std::string _simulationConfig;
	std::string _outputDir;

	void parseLevel( TiXmlNode * parent, QTreeWidgetItem * parentItem);
	void parseAttributes( TiXmlElement * parent, QTreeWidgetItem * parentItem);

	void generateConfigs();
	void runSimulations();

public:
	Laboratory(QWidget * parent);
	virtual ~Laboratory();

private slots:
	void selectSimulation();
	void selectConfig();
	void selectOutput();
	void showConfig();
	void parseConfig();
	void paramChanged( QTreeWidgetItem * item, int column );
	void doubleClick(QTreeWidgetItem * item, int column);
	void buttonClicked( QAbstractButton * button );
};

}

#endif // __Laboratory_hxx__

